#ifndef WRAP_ISTEAMUNIFIEDMESSAGES_CPP
#define WRAP_ISTEAMUNIFIEDMESSAGES_CPP
#include "autoclass/steam_api_.h" 
#include "windef.h"
#include "wine/debug.h"
#include "config.h"
ClientUnifiedMessageHandle ISteamUnifiedMessages_::SendMethod( const char *pchServiceMethod, const void *pRequestBuffer, uint32 unRequestBufferSize, uint64 unContext )
{
  TRACE("((this[ISteamUnifiedMessages])%p, (const char *)\"%s\", (const void *)%p, (uint32)%d, (uint64)%d)\n", this, pchServiceMethod, pRequestBuffer, unRequestBufferSize, unContext);
  ClientUnifiedMessageHandle result = this->internal->SendMethod(pchServiceMethod, pRequestBuffer, unRequestBufferSize, unContext);
  TRACE(" = (ClientUnifiedMessageHandle)%p\n", result);
  return result;
}
bool ISteamUnifiedMessages_::GetMethodResponseInfo( ClientUnifiedMessageHandle hHandle, uint32 *punResponseSize, EResult *peResult )
{
  TRACE("((this[ISteamUnifiedMessages])%p, (ClientUnifiedMessageHandle)%p, (uint32 *)%p, (EResult *)%p)\n", this, hHandle, punResponseSize, peResult);
  bool result = this->internal->GetMethodResponseInfo(hHandle, punResponseSize, peResult);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUnifiedMessages_::GetMethodResponseData( ClientUnifiedMessageHandle hHandle, void *pResponseBuffer, uint32 unResponseBufferSize, bool bAutoRelease )
{
  TRACE("((this[ISteamUnifiedMessages])%p, (ClientUnifiedMessageHandle)%p, (void *)%p, (uint32)%d, (bool)%d)\n", this, hHandle, pResponseBuffer, unResponseBufferSize, bAutoRelease);
  bool result = this->internal->GetMethodResponseData(hHandle, pResponseBuffer, unResponseBufferSize, bAutoRelease);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUnifiedMessages_::ReleaseMethod( ClientUnifiedMessageHandle hHandle )
{
  TRACE("((this[ISteamUnifiedMessages])%p, (ClientUnifiedMessageHandle)%p)\n", this, hHandle);
  bool result = this->internal->ReleaseMethod(hHandle);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUnifiedMessages_::SendNotification( const char *pchServiceNotification, const void *pNotificationBuffer, uint32 unNotificationBufferSize )
{
  TRACE("((this[ISteamUnifiedMessages])%p, (const char *)\"%s\", (const void *)%p, (uint32)%d)\n", this, pchServiceNotification, pNotificationBuffer, unNotificationBufferSize);
  bool result = this->internal->SendNotification(pchServiceNotification, pNotificationBuffer, unNotificationBufferSize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
#endif
