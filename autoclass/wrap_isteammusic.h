#include <steam_api_.h>
#include <isteammusic.h>
class ISteamMusic_
{
public:
  virtual bool  BIsEnabled() __attribute__((thiscall));
  virtual bool  BIsPlaying() __attribute__((thiscall));
  virtual AudioPlayback_Status  GetPlaybackStatus() __attribute__((thiscall));
  virtual void  Play() __attribute__((thiscall));
  virtual void  Pause() __attribute__((thiscall));
  virtual void  PlayPrevious() __attribute__((thiscall));
  virtual void  PlayNext() __attribute__((thiscall));
  virtual void  SetVolume(float  flVolume) __attribute__((thiscall));
  virtual float  GetVolume() __attribute__((thiscall));
  ISteamMusic_(ISteamMusic*to_wrap);
  ~ISteamMusic_();
private:
  ISteamMusic * internal;
};
