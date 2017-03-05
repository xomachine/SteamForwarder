#include <steam_api_.h>
#include <isteamunifiedmessages.h>
class ISteamUnifiedMessages_
{
public:
  virtual ClientUnifiedMessageHandle  SendMethod(char * pchServiceMethod, void * pRequestBuffer, uint32  unRequestBufferSize, uint64  unContext) __attribute__((thiscall));
  virtual bool  GetMethodResponseInfo(ClientUnifiedMessageHandle  hHandle, uint32 * punResponseSize, EResult * peResult) __attribute__((thiscall));
  virtual bool  GetMethodResponseData(ClientUnifiedMessageHandle  hHandle, void * pResponseBuffer, uint32  unResponseBufferSize, bool  bAutoRelease) __attribute__((thiscall));
  virtual bool  ReleaseMethod(ClientUnifiedMessageHandle  hHandle) __attribute__((thiscall));
  virtual bool  SendNotification(char * pchServiceNotification, void * pNotificationBuffer, uint32  unNotificationBufferSize) __attribute__((thiscall));
  ISteamUnifiedMessages_(ISteamUnifiedMessages*to_wrap);
  ~ISteamUnifiedMessages_();
private:
  ISteamUnifiedMessages * internal;
};
