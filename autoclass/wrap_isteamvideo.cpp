#include <steam_api_.h>

void  ISteamVideo_::GetVideoURL(AppId_t  unVideoAppID)
{
  TRACE("((ISteamVideo *)%p, (AppId_t )%p)\n", this, unVideoAppID);
  this->internal->GetVideoURL(unVideoAppID);
  
}


bool  ISteamVideo_::IsBroadcasting(int * pnNumViewers)
{
  TRACE("((ISteamVideo *)%p, (int *)%d)\n", this, pnNumViewers);
  bool  result = this->internal->IsBroadcasting(pnNumViewers);
  TRACE("() = (bool )%d\n", result);

  return result;
}
ISteamVideo_::ISteamVideo_(ISteamVideo * towrap)
{
  this->internal = towrap;
}

ISteamVideo_::~ISteamVideo_()
{
  delete this->internal;
}
