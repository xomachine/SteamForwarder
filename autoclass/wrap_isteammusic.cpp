#ifndef WRAP_ISTEAMMUSIC_CPP
#define WRAP_ISTEAMMUSIC_CPP
#include "autoclass/steam_api_.h" 
#include "windef.h"
#include "wine/debug.h"
#include "config.h"
bool ISteamMusic_::BIsEnabled()
{
  TRACE("((this[ISteamMusic])%p)\n", this);
  bool result = this->internal->BIsEnabled();
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusic_::BIsPlaying()
{
  TRACE("((this[ISteamMusic])%p)\n", this);
  bool result = this->internal->BIsPlaying();
  TRACE(" = (bool)%d\n", result);
  return result;
}
AudioPlayback_Status ISteamMusic_::GetPlaybackStatus()
{
  TRACE("((this[ISteamMusic])%p)\n", this);
  AudioPlayback_Status result = this->internal->GetPlaybackStatus();
  TRACE(" = (AudioPlayback_Status)%p\n", result);
  return result;
}
void ISteamMusic_::Play()
{
  TRACE("((this[ISteamMusic])%p)\n", this);
  this->internal->Play();
}
void ISteamMusic_::Pause()
{
  TRACE("((this[ISteamMusic])%p)\n", this);
  this->internal->Pause();
}
void ISteamMusic_::PlayPrevious()
{
  TRACE("((this[ISteamMusic])%p)\n", this);
  this->internal->PlayPrevious();
}
void ISteamMusic_::PlayNext()
{
  TRACE("((this[ISteamMusic])%p)\n", this);
  this->internal->PlayNext();
}
void ISteamMusic_::SetVolume( float flVolume )
{
  TRACE("((this[ISteamMusic])%p, (float)%f)\n", this, flVolume);
  this->internal->SetVolume(flVolume);
}
float ISteamMusic_::GetVolume()
{
  TRACE("((this[ISteamMusic])%p)\n", this);
  float result = this->internal->GetVolume();
  TRACE(" = (float)%f\n", result);
  return result;
}
#endif
