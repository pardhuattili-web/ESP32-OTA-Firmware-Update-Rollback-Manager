#pragma once
#include <stdint.h>
typedef struct { uint32_t state_code; uint32_t attempts; } ota_store_t;
void storage_init(void);
int storage_save(const ota_store_t *s);
int storage_load(ota_store_t *s);