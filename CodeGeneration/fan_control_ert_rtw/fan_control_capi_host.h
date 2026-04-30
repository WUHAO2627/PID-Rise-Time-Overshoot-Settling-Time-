#ifndef fan_control_cap_host_h__
#define fan_control_cap_host_h__
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"

typedef struct {
  rtwCAPI_ModelMappingInfo mmi;
} fan_control_host_DataMapInfo_T;

#ifdef __cplusplus

extern "C"
{

#endif

  void fan_control_host_InitializeDataMapInfo(fan_control_host_DataMapInfo_T
    *dataMap, const char *path);

#ifdef __cplusplus

}

#endif
#endif                                 /* HOST_CAPI_BUILD */
#endif                                 /* fan_control_cap_host_h__ */

/* EOF: fan_control_capi_host.h */
