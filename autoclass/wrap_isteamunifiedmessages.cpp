#include <steam_api_.h>

ClientUnifiedMessageHandle  ISteamUnifiedMessages_::SendMethod(char * pchServiceMethod, void * pRequestBuffer, uint32  unRequestBufferSize, uint64  unContext)
{
  TRACE("((ISteamUnifiedMessages *)%p, (char *)\"%s\", (void *)%p, (uint32 )%d, (uint64 )%d)\n", this, pchServiceMethod, pRequestBuffer, unRequestBufferSize, unContext);
  auto result = this->internal->SendMethod(pchServiceMethod, pRequestBuffer, unRequestBufferSize, unContext);
  TRACE("() = (ClientUnifiedMessageHandle )%p\n", result);

  return result;
}


bool  ISteamUnifiedMessages_::GetMethodResponseInfo(ClientUnifiedMessageHandle  hHandle, uint32 * punResponseSize, EResult * peResult)
{
  TRACE("((ISteamUnifiedMessages *)%p, (ClientUnifiedMessageHandle )%p, (uint32 *)%d, (EResult *)%p)\n", this, hHandle, punResponseSize, peResult);
  auto result = this->internal->GetMethodResponseInfo(hHandle, punResponseSize, peResult);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUnifiedMessages_::GetMethodResponseData(ClientUnifiedMessageHandle  hHandle, void * pResponseBuffer, uint32  unResponseBufferSize, bool  bAutoRelease)
{
  TRACE("((ISteamUnifiedMessages *)%p, (ClientUnifiedMessageHandle )%p, (void *)%p, (uint32 )%d, (bool )%d)\n", this, hHandle, pResponseBuffer, unResponseBufferSize, bAutoRelease);
  auto result = this->internal->GetMethodResponseData(hHandle, pResponseBuffer, unResponseBufferSize, bAutoRelease);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUnifiedMessages_::ReleaseMethod(ClientUnifiedMessageHandle  hHandle)
{
  TRACE("((ISteamUnifiedMessages *)%p, (ClientUnifiedMessageHandle )%p)\n", this, hHandle);
  auto result = this->internal->ReleaseMethod(hHandle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUnifiedMessages_::SendNotification(char * pchServiceNotification, void * pNotificationBuffer, uint32  unNotificationBufferSize)
{
  TRACE("((ISteamUnifiedMessages *)%p, (char *)\"%s\", (void *)%p, (uint32 )%d)\n", this, pchServiceNotification, pNotificationBuffer, unNotificationBufferSize);
  auto result = this->internal->SendNotification(pchServiceNotification, pNotificationBuffer, unNotificationBufferSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}
ISteamUnifiedMessages_::ISteamUnifiedMessages_(ISteamUnifiedMessages * towrap)
{
  this->internal = towrap;
}

ISteamUnifiedMessages_::~ISteamUnifiedMessages_()
{
  delete this->internal;
}
