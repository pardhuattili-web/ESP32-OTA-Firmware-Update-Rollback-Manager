#pragma once
#include "ota_state.h"
typedef struct { ota_runtime_t runtime; } ota_manager_t;
void ota_manager_init(ota_manager_t *m);
int ota_manager_check_candidate(ota_manager_t *m, ota_version_t candidate, ota_version_t minimum);
void ota_manager_begin_trial(ota_manager_t *m);
void ota_manager_confirm(ota_manager_t *m);
void ota_manager_rollback(ota_manager_t *m);