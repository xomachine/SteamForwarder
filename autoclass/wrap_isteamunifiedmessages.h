#ifndef WRAP_ISTEAMUNIFIEDMESSAGES_H
#define WRAP_ISTEAMUNIFIEDMESSAGES_H
#include "steam_api.h"
class ISteamUnifiedMessages_ 
{
  virtual ClientUnifiedMessageHandle SendMethod( const char *pchServiceMethod, const void *pRequestBuffer, uint32 unRequestBufferSize, uint64 unContext ) __attribute__((thiscall));
  virtual bool GetMethodResponseInfo( ClientUnifiedMessageHandle hHandle, uint32 *punResponseSize, EResult *peResult ) __attribute__((thiscall));
  virtual bool GetMethodResponseData( ClientUnifiedMessageHandle hHandle, void *pResponseBuffer, uint32 unResponseBufferSize, bool bAutoRelease ) __attribute__((thiscall));
  virtual bool ReleaseMethod( ClientUnifiedMessageHandle hHandle ) __attribute__((thiscall));
  virtual bool SendNotification( const char *pchServiceNotification, const void *pNotificationBuffer, uint32 unNotificationBufferSize ) __attribute__((thiscall));
  public:
    ISteamUnifiedMessages *internal;
};
#endif
