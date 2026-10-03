#include <stdio.h>
#include "ota_manager.h"
#include "boot_health.h"
#include "storage.h"
void app_main(void){
 ota_manager_t m; boot_health_t h; storage_init(); ota_manager_init(&m); boot_health_init(&h);
 printf("\n=== ESP32 OTA Firmware Update & Rollback Manager ===\n");
 printf("Running: %lu.%lu.%lu\n",(unsigned long)m.runtime.running.major,(unsigned long)m.runtime.running.minor,(unsigned long)m.runtime.running.patch);
 boot_health_note_heartbeat(&h);
 if(boot_health_ready(&h,m.runtime.confirm_deadline_s)){ota_manager_confirm(&m);printf("Boot health: CONFIRMED\n");}
 else {ota_manager_rollback(&m);printf("Boot health: ROLLBACK\n");}
}