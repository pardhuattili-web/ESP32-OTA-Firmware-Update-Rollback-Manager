#pragma once
#include <stdint.h>
typedef struct { uint8_t scheduler_ok; uint8_t init_ok; uint8_t heartbeat_ok; uint8_t fatal_error; uint32_t elapsed_s; } boot_health_t;
void boot_health_init(boot_health_t *h);
void boot_health_note_heartbeat(boot_health_t *h);
int boot_health_ready(const boot_health_t *h, uint32_t window_s);