#include "ota_manager.h"
void ota_manager_init(ota_manager_t*m){if(!m)return;ota_state_defaults(&m->runtime);}
int ota_manager_check_candidate(ota_manager_t*m,ota_version_t c,ota_version_t min){if(!m)return-1;if(!ota_policy_accepts(c,m->runtime.running,min)){m->runtime.state=OTA_REJECTED;return-2;}m->runtime.candidate=c;m->runtime.state=OTA_VERIFY;return 0;}
void ota_manager_begin_trial(ota_manager_t*m){if(!m)return;m->runtime.boot_attempts++;m->runtime.state=OTA_TRIAL_BOOT;}
void ota_manager_confirm(ota_manager_t*m){if(!m)return;m->runtime.running=m->runtime.candidate;m->runtime.state=OTA_CONFIRMED;m->runtime.boot_attempts=0;}
void ota_manager_rollback(ota_manager_t*m){if(!m)return;m->runtime.state=OTA_ROLLBACK;m->runtime.candidate=(ota_version_t){0,0,0};}