# ESP32 OTA Firmware Update & Rollback Manager

A reference ESP32 firmware-lifecycle manager that models a production-style OTA flow: check firmware metadata, download a candidate image, verify it, switch the boot partition, confirm application health, and roll back automatically when the new image fails its boot validation window.

> **Status:** ESP-IDF reference implementation. The OTA policy/state model and test scaffolding are included; real HTTPS transfer, signed-image verification, and physical rollback behavior require an ESP32 build and test environment.

## Architecture

```
OTA Server -> HTTPS/API -> OTA Manager -> Verify -> A/B Flash
                                      |
                                   Reboot
                                      v
                               Boot Health Check
                                /             \
                           confirm          rollback
```

## Features

- ESP32 + ESP-IDF
- Dual OTA application slots
- Version and metadata policy
- SHA-256 digest handling
- Persistent OTA state in NVS
- Trial-boot confirmation window
- Watchdog-assisted rollback policy
- Invalid/downgrade rejection
- Update progress/status reporting
- Host-side image metadata utility
- Failure-injection test mode

## State machine

```text
IDLE -> CHECK_UPDATE -> DOWNLOAD -> VERIFY -> SET_PENDING -> REBOOT
                                      |                       |
                                   REJECTED               TRIAL_BOOT
                                                              |
                                          +-------------------+----------------+
                                          |                                    |
                                       HEALTHY                             TIMEOUT/FAULT
                                          |                                    |
                                      CONFIRMED                           ROLLBACK
```

## Partition model

| Name | Purpose |
|---|---|
| nvs | persistent configuration/state |
| otadata | ESP-IDF OTA selection metadata |
| phy_init | PHY calibration data |
| factory | recovery/reference image |
| ota_0 | application slot A |
| ota_1 | application slot B |

Tune the exact partition sizes for the selected ESP32 flash capacity.

## Update safety policy

1. Reject malformed metadata.
2. Reject firmware versions below the configured policy.
3. Verify the candidate image digest.
4. Mark the target slot pending.
5. Reboot into the candidate.
6. Require a healthy boot inside the confirmation window.
7. Confirm only after health criteria pass.
8. Roll back after a failed/timed-out trial boot.

## Health criteria

The reference health manager checks that critical initialization completed, the scheduler is running, an application heartbeat is observed, and no fatal error is active before confirmation.

## Project structure

```text
main/
  app_main.c
  include/
    ota_manager.h
    ota_policy.h
    boot_health.h
    ota_state.h
    storage.h
  src/
    ota_manager.c
    ota_policy.c
    boot_health.c
    ota_state.c
    storage.c
partition/
  partitions.csv
tools/
  ota_image_tool.py
docs/
  architecture.md
  ota_state_machine.md
  partition_layout.md
  test_plan.md
test/
  ota_policy_test.c
```

## Build

Requires ESP-IDF 5.x.

```bash
idf.py set-target esp32
idf.py build
idf.py flash monitor
```

## Host metadata tool

```bash
python tools/ota_image_tool.py firmware.bin 1.2.0
```

## Security note

SHA-256 is an integrity primitive, not a complete firmware-authentication system. A production product should add signed firmware, secure boot, protected key storage, anti-rollback, and properly validated TLS.

## Validation status

Software tests cover the OTA policy/state machine. Real HTTPS transfer, flash behavior, power-loss recovery, secure boot, and physical rollback behavior require hardware validation.

## License

MIT
