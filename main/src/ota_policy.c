#include "ota_policy.h"
int ota_version_compare(ota_version_t a,ota_version_t b){if(a.major!=b.major)return a.major>b.major?1:-1;if(a.minor!=b.minor)return a.minor>b.minor?1:-1;if(a.patch!=b.patch)return a.patch>b.patch?1:-1;return 0;}
int ota_policy_accepts(ota_version_t c,ota_version_t cur,ota_version_t min){return ota_version_compare(c,min)>=0&&ota_version_compare(c,cur)>0;}