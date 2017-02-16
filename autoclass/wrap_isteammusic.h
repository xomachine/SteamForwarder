#ifndef WRAP_ISTEAMMUSIC_H
#define WRAP_ISTEAMMUSIC_H
#include "steam_api.h"
class ISteamMusic_ 
{
  virtual bool BIsEnabled() __attribute__((thiscall));
  virtual bool BIsPlaying() __attribute__((thiscall));
  virtual AudioPlayback_Status GetPlaybackStatus() __attribute__((thiscall));
  virtual void Play() __attribute__((thiscall));
  virtual void Pause() __attribute__((thiscall));
  virtual void PlayPrevious() __attribute__((thiscall));
  virtual void PlayNext() __attribute__((thiscall));
  virtual void SetVolume( float flVolume ) __attribute__((thiscall));
  virtual float GetVolume() __attribute__((thiscall));
  public:
    ISteamMusic *internal;
};
#endif
