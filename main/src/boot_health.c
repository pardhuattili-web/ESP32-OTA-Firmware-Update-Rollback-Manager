#include "boot_health.h"
void boot_health_init(boot_health_t*h){if(!h)return;*h=(boot_health_t){.scheduler_ok=1,.init_ok=1};}
void boot_health_note_heartbeat(boot_health_t*h){if(h)h->heartbeat_ok=1;}
int boot_health_ready(const boot_health_t*h,uint32_t window){return h&&h->scheduler_ok&&h->init_ok&&h->heartbeat_ok&&!h->fatal_error&&h->elapsed_s<=window;}