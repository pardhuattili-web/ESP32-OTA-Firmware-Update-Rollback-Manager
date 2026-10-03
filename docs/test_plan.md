# Test Plan

## Software tests
- semantic version comparison
- minimum-version rejection
- boot-health confirmation
- fatal-error rejection
- candidate/rollback state transitions

## Hardware/integration tests
- HTTPS download success/failure
- interrupted transfer recovery
- SHA-256 mismatch rejection
- boot into ota_0 / ota_1
- watchdog reset during trial boot
- power loss during flash write
- automatic rollback
- confirmation persistence across reboot
- TLS certificate validation

No physical rollback or power-loss result is claimed until tested on the target ESP32.