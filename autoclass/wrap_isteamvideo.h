#include <steam_api_.h>
#include <isteamvideo.h>
class ISteamVideo_
{
public:
  virtual void  GetVideoURL(AppId_t  unVideoAppID) __attribute__((thiscall));
  virtual bool  IsBroadcasting(int * pnNumViewers) __attribute__((thiscall));
  ISteamVideo_(ISteamVideo*to_wrap);
  ~ISteamVideo_();
private:
  ISteamVideo * internal;
};
