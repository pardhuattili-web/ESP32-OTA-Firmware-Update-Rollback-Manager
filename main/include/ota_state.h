#pragma once
#include <stdint.h>
#include "ota_policy.h"
typedef struct { ota_state_t state; ota_version_t running; ota_version_t candidate; uint32_t boot_attempts; uint32_t confirm_deadline_s; uint8_t failure_injected; } ota_runtime_t;
void ota_state_defaults(ota_runtime_t *s);