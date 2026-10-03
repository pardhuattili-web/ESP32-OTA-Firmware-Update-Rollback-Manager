#pragma once
#include <stdint.h>
typedef enum { OTA_IDLE, OTA_CHECK, OTA_DOWNLOAD, OTA_VERIFY, OTA_SET_PENDING, OTA_TRIAL_BOOT, OTA_CONFIRMED, OTA_REJECTED, OTA_ROLLBACK } ota_state_t;
typedef struct { uint32_t major, minor, patch; } ota_version_t;
int ota_version_compare(ota_version_t a, ota_version_t b);
int ota_policy_accepts(ota_version_t candidate, ota_version_t current, ota_version_t minimum);