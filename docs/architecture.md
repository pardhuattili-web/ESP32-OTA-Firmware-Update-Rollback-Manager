# Architecture

```
Metadata -> Policy -> Download/Verify -> Set Pending -> Reboot
                                      |
                                 Trial Boot
                                  /      \
                             Confirm   Rollback
```

The policy layer is independent of the transport. A production transport can use ESP-IDF OTA APIs, HTTPS, TLS certificate validation, and the ESP-IDF bootloader/OTA selection data.

The health layer confirms the new application only after critical initialization and a heartbeat. A watchdog/reset or fatal condition during the trial period should leave the image unconfirmed so the boot system can revert to the previous application.