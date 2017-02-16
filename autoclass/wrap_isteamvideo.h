#ifndef WRAP_ISTEAMVIDEO_H
#define WRAP_ISTEAMVIDEO_H
#include "steam_api.h"
class ISteamVideo_ 
{
  virtual void GetVideoURL( AppId_t unVideoAppID ) __attribute__((thiscall));
  virtual bool IsBroadcasting( int *pnNumViewers ) __attribute__((thiscall));
  public:
    ISteamVideo *internal;
};
#endif
