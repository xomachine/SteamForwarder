#ifndef WRAP_ISTEAMVIDEO_CPP
#define WRAP_ISTEAMVIDEO_CPP
#include "autoclass/steam_api_.h" 
#include "windef.h"
#include "wine/debug.h"
#include "config.h"
void ISteamVideo_::GetVideoURL( AppId_t unVideoAppID )
{
  TRACE("((this[ISteamVideo])%p, (AppId_t)%p)\n", this, unVideoAppID);
  this->internal->GetVideoURL(unVideoAppID);
}
bool ISteamVideo_::IsBroadcasting( int *pnNumViewers )
{
  TRACE("((this[ISteamVideo])%p, (int *)%p)\n", this, pnNumViewers);
  bool result = this->internal->IsBroadcasting(pnNumViewers);
  TRACE(" = (bool)%d\n", result);
  return result;
}
#endif
