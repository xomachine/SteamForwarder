#include <steam_api_.h>

bool  ISteamMusic_::BIsEnabled()
{
  TRACE("((ISteamMusic *)%p)\n", this);
  auto result = this->internal->BIsEnabled();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusic_::BIsPlaying()
{
  TRACE("((ISteamMusic *)%p)\n", this);
  auto result = this->internal->BIsPlaying();
  TRACE("() = (bool )%d\n", result);

  return result;
}


AudioPlayback_Status  ISteamMusic_::GetPlaybackStatus()
{
  TRACE("((ISteamMusic *)%p)\n", this);
  auto result = this->internal->GetPlaybackStatus();
  TRACE("() = (AudioPlayback_Status )%p\n", result);

  return result;
}


void  ISteamMusic_::Play()
{
  TRACE("((ISteamMusic *)%p)\n", this);
  this->internal->Play();
  
}


void  ISteamMusic_::Pause()
{
  TRACE("((ISteamMusic *)%p)\n", this);
  this->internal->Pause();
  
}


void  ISteamMusic_::PlayPrevious()
{
  TRACE("((ISteamMusic *)%p)\n", this);
  this->internal->PlayPrevious();
  
}


void  ISteamMusic_::PlayNext()
{
  TRACE("((ISteamMusic *)%p)\n", this);
  this->internal->PlayNext();
  
}


void  ISteamMusic_::SetVolume(float  flVolume)
{
  TRACE("((ISteamMusic *)%p, (float )%f)\n", this, flVolume);
  this->internal->SetVolume(flVolume);
  
}


float  ISteamMusic_::GetVolume()
{
  TRACE("((ISteamMusic *)%p)\n", this);
  auto result = this->internal->GetVolume();
  TRACE("() = (float )%f\n", result);

  return result;
}
ISteamMusic_::ISteamMusic_(ISteamMusic * towrap)
{
  this->internal = towrap;
}

ISteamMusic_::~ISteamMusic_()
{
  delete this->internal;
}
