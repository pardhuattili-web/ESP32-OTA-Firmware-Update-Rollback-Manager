# OTA State Machine

| State | Meaning | Transition |
|---|---|---|
| IDLE | no update active | update available |
| CHECK | evaluate metadata/version | accepted -> DOWNLOAD |
| DOWNLOAD | receive candidate | complete -> VERIFY |
| VERIFY | validate digest/policy | pass -> SET_PENDING |
| SET_PENDING | select target OTA slot | reboot |
| TRIAL_BOOT | candidate running | health pass -> CONFIRMED |
| CONFIRMED | candidate accepted | IDLE |
| REJECTED | candidate refused | IDLE |
| ROLLBACK | candidate failed | previous image -> IDLE |

The implementation keeps the state machine explicit so tests can exercise failure paths without requiring a real network.