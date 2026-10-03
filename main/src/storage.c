#include "storage.h"
#include "nvs.h"
#include "nvs_flash.h"
static const char *NS="ota";
void storage_init(void){(void)nvs_flash_init();}
int storage_save(const ota_store_t*s){if(!s)return-1;nvs_handle_t h;esp_err_t e=nvs_open(NS,NVS_READWRITE,&h);if(e!=ESP_OK)return e;e=nvs_set_blob(h,"state",s,sizeof(*s));if(e==ESP_OK)e=nvs_commit(h);nvs_close(h);return e;}
int storage_load(ota_store_t*s){if(!s)return-1;nvs_handle_t h;esp_err_t e=nvs_open(NS,NVS_READONLY,&h);if(e!=ESP_OK)return e;size_t n=sizeof(*s);e=nvs_get_blob(h,"state",s,&n);nvs_close(h);return(e==ESP_OK&&n==sizeof(*s))?0:e;}