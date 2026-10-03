#include <assert.h>
#include <stdio.h>
#include "../main/include/ota_policy.h"
#include "../main/include/boot_health.h"
int main(void){
 ota_version_t cur={1,2,0},newer={1,3,0},older={1,1,9};
 assert(ota_version_compare(newer,cur)>0);
 assert(ota_policy_accepts(newer,cur,(ota_version_t){1,0,0})==1);
 assert(ota_policy_accepts(older,cur,(ota_version_t){1,0,0})==0);
 boot_health_t h;boot_health_init(&h);boot_health_note_heartbeat(&h);assert(boot_health_ready(&h,30)==1);
 h.fatal_error=1;assert(boot_health_ready(&h,30)==0);
 puts("OTA policy tests: PASS");return 0;}