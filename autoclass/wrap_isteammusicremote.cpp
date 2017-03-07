#include <steam_api_.h>

bool  ISteamMusicRemote_::RegisterSteamMusicRemote(char * pchName)
{
  TRACE("((ISteamMusicRemote *)%p, (char *)\"%s\")\n", this, pchName);
  bool  result = this->internal->RegisterSteamMusicRemote(pchName);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::DeregisterSteamMusicRemote()
{
  TRACE("((ISteamMusicRemote *)%p)\n", this);
  bool  result = this->internal->DeregisterSteamMusicRemote();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::BIsCurrentMusicRemote()
{
  TRACE("((ISteamMusicRemote *)%p)\n", this);
  bool  result = this->internal->BIsCurrentMusicRemote();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::BActivationSuccess(bool  bValue)
{
  TRACE("((ISteamMusicRemote *)%p, (bool )%d)\n", this, bValue);
  bool  result = this->internal->BActivationSuccess(bValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::SetDisplayName(char * pchDisplayName)
{
  TRACE("((ISteamMusicRemote *)%p, (char *)\"%s\")\n", this, pchDisplayName);
  bool  result = this->internal->SetDisplayName(pchDisplayName);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::SetPNGIcon_64x64(void * pvBuffer, uint32  cbBufferLength)
{
  TRACE("((ISteamMusicRemote *)%p, (void *)%p, (uint32 )%d)\n", this, pvBuffer, cbBufferLength);
  bool  result = this->internal->SetPNGIcon_64x64(pvBuffer, cbBufferLength);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::EnablePlayPrevious(bool  bValue)
{
  TRACE("((ISteamMusicRemote *)%p, (bool )%d)\n", this, bValue);
  bool  result = this->internal->EnablePlayPrevious(bValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::EnablePlayNext(bool  bValue)
{
  TRACE("((ISteamMusicRemote *)%p, (bool )%d)\n", this, bValue);
  bool  result = this->internal->EnablePlayNext(bValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::EnableShuffled(bool  bValue)
{
  TRACE("((ISteamMusicRemote *)%p, (bool )%d)\n", this, bValue);
  bool  result = this->internal->EnableShuffled(bValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::EnableLooped(bool  bValue)
{
  TRACE("((ISteamMusicRemote *)%p, (bool )%d)\n", this, bValue);
  bool  result = this->internal->EnableLooped(bValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::EnableQueue(bool  bValue)
{
  TRACE("((ISteamMusicRemote *)%p, (bool )%d)\n", this, bValue);
  bool  result = this->internal->EnableQueue(bValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::EnablePlaylists(bool  bValue)
{
  TRACE("((ISteamMusicRemote *)%p, (bool )%d)\n", this, bValue);
  bool  result = this->internal->EnablePlaylists(bValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::UpdatePlaybackStatus(AudioPlayback_Status  nStatus)
{
  TRACE("((ISteamMusicRemote *)%p, (AudioPlayback_Status )%p)\n", this, nStatus);
  bool  result = this->internal->UpdatePlaybackStatus(nStatus);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::UpdateShuffled(bool  bValue)
{
  TRACE("((ISteamMusicRemote *)%p, (bool )%d)\n", this, bValue);
  bool  result = this->internal->UpdateShuffled(bValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::UpdateLooped(bool  bValue)
{
  TRACE("((ISteamMusicRemote *)%p, (bool )%d)\n", this, bValue);
  bool  result = this->internal->UpdateLooped(bValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::UpdateVolume(float  flValue)
{
  TRACE("((ISteamMusicRemote *)%p, (float )%f)\n", this, flValue);
  bool  result = this->internal->UpdateVolume(flValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::CurrentEntryWillChange()
{
  TRACE("((ISteamMusicRemote *)%p)\n", this);
  bool  result = this->internal->CurrentEntryWillChange();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::CurrentEntryIsAvailable(bool  bAvailable)
{
  TRACE("((ISteamMusicRemote *)%p, (bool )%d)\n", this, bAvailable);
  bool  result = this->internal->CurrentEntryIsAvailable(bAvailable);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::UpdateCurrentEntryText(char * pchText)
{
  TRACE("((ISteamMusicRemote *)%p, (char *)\"%s\")\n", this, pchText);
  bool  result = this->internal->UpdateCurrentEntryText(pchText);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::UpdateCurrentEntryElapsedSeconds(int  nValue)
{
  TRACE("((ISteamMusicRemote *)%p, (int )%d)\n", this, nValue);
  bool  result = this->internal->UpdateCurrentEntryElapsedSeconds(nValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::UpdateCurrentEntryCoverArt(void * pvBuffer, uint32  cbBufferLength)
{
  TRACE("((ISteamMusicRemote *)%p, (void *)%p, (uint32 )%d)\n", this, pvBuffer, cbBufferLength);
  bool  result = this->internal->UpdateCurrentEntryCoverArt(pvBuffer, cbBufferLength);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::CurrentEntryDidChange()
{
  TRACE("((ISteamMusicRemote *)%p)\n", this);
  bool  result = this->internal->CurrentEntryDidChange();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::QueueWillChange()
{
  TRACE("((ISteamMusicRemote *)%p)\n", this);
  bool  result = this->internal->QueueWillChange();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::ResetQueueEntries()
{
  TRACE("((ISteamMusicRemote *)%p)\n", this);
  bool  result = this->internal->ResetQueueEntries();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::SetQueueEntry(int  nID, int  nPosition, char * pchEntryText)
{
  TRACE("((ISteamMusicRemote *)%p, (int )%d, (int )%d, (char *)\"%s\")\n", this, nID, nPosition, pchEntryText);
  bool  result = this->internal->SetQueueEntry(nID, nPosition, pchEntryText);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::SetCurrentQueueEntry(int  nID)
{
  TRACE("((ISteamMusicRemote *)%p, (int )%d)\n", this, nID);
  bool  result = this->internal->SetCurrentQueueEntry(nID);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::QueueDidChange()
{
  TRACE("((ISteamMusicRemote *)%p)\n", this);
  bool  result = this->internal->QueueDidChange();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::PlaylistWillChange()
{
  TRACE("((ISteamMusicRemote *)%p)\n", this);
  bool  result = this->internal->PlaylistWillChange();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::ResetPlaylistEntries()
{
  TRACE("((ISteamMusicRemote *)%p)\n", this);
  bool  result = this->internal->ResetPlaylistEntries();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::SetPlaylistEntry(int  nID, int  nPosition, char * pchEntryText)
{
  TRACE("((ISteamMusicRemote *)%p, (int )%d, (int )%d, (char *)\"%s\")\n", this, nID, nPosition, pchEntryText);
  bool  result = this->internal->SetPlaylistEntry(nID, nPosition, pchEntryText);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::SetCurrentPlaylistEntry(int  nID)
{
  TRACE("((ISteamMusicRemote *)%p, (int )%d)\n", this, nID);
  bool  result = this->internal->SetCurrentPlaylistEntry(nID);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMusicRemote_::PlaylistDidChange()
{
  TRACE("((ISteamMusicRemote *)%p)\n", this);
  bool  result = this->internal->PlaylistDidChange();
  TRACE("() = (bool )%d\n", result);

  return result;
}
ISteamMusicRemote_::ISteamMusicRemote_(ISteamMusicRemote * towrap)
{
  this->internal = towrap;
}

ISteamMusicRemote_::~ISteamMusicRemote_()
{
  delete this->internal;
}
