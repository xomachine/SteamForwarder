#ifndef WRAP_ISTEAMMUSICREMOTE_CPP
#define WRAP_ISTEAMMUSICREMOTE_CPP
#include "autoclass/steam_api_.h" 
#include "windef.h"
#include "wine/debug.h"
#include "config.h"
bool ISteamMusicRemote_::RegisterSteamMusicRemote( const char *pchName )
{
  TRACE("((this[ISteamMusicRemote])%p, (const char *)\"%s\")\n", this, pchName);
  bool result = this->internal->RegisterSteamMusicRemote(pchName);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::DeregisterSteamMusicRemote()
{
  TRACE("((this[ISteamMusicRemote])%p)\n", this);
  bool result = this->internal->DeregisterSteamMusicRemote();
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::BIsCurrentMusicRemote()
{
  TRACE("((this[ISteamMusicRemote])%p)\n", this);
  bool result = this->internal->BIsCurrentMusicRemote();
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::BActivationSuccess( bool bValue )
{
  TRACE("((this[ISteamMusicRemote])%p, (bool)%d)\n", this, bValue);
  bool result = this->internal->BActivationSuccess(bValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::SetDisplayName( const char *pchDisplayName )
{
  TRACE("((this[ISteamMusicRemote])%p, (const char *)\"%s\")\n", this, pchDisplayName);
  bool result = this->internal->SetDisplayName(pchDisplayName);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::SetPNGIcon_64x64( void *pvBuffer, uint32 cbBufferLength )
{
  TRACE("((this[ISteamMusicRemote])%p, (void *)%p, (uint32)%d)\n", this, pvBuffer, cbBufferLength);
  bool result = this->internal->SetPNGIcon_64x64(pvBuffer, cbBufferLength);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::EnablePlayPrevious(bool bValue)
{
  TRACE("((this[ISteamMusicRemote])%p, (bool)%d)\n", this, bValue);
  bool result = this->internal->EnablePlayPrevious(bValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::EnablePlayNext( bool bValue )
{
  TRACE("((this[ISteamMusicRemote])%p, (bool)%d)\n", this, bValue);
  bool result = this->internal->EnablePlayNext(bValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::EnableShuffled( bool bValue )
{
  TRACE("((this[ISteamMusicRemote])%p, (bool)%d)\n", this, bValue);
  bool result = this->internal->EnableShuffled(bValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::EnableLooped( bool bValue )
{
  TRACE("((this[ISteamMusicRemote])%p, (bool)%d)\n", this, bValue);
  bool result = this->internal->EnableLooped(bValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::EnableQueue( bool bValue )
{
  TRACE("((this[ISteamMusicRemote])%p, (bool)%d)\n", this, bValue);
  bool result = this->internal->EnableQueue(bValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::EnablePlaylists( bool bValue )
{
  TRACE("((this[ISteamMusicRemote])%p, (bool)%d)\n", this, bValue);
  bool result = this->internal->EnablePlaylists(bValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::UpdatePlaybackStatus( AudioPlayback_Status nStatus )
{
  TRACE("((this[ISteamMusicRemote])%p, (AudioPlayback_Status)%p)\n", this, nStatus);
  bool result = this->internal->UpdatePlaybackStatus(nStatus);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::UpdateShuffled( bool bValue )
{
  TRACE("((this[ISteamMusicRemote])%p, (bool)%d)\n", this, bValue);
  bool result = this->internal->UpdateShuffled(bValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::UpdateLooped( bool bValue )
{
  TRACE("((this[ISteamMusicRemote])%p, (bool)%d)\n", this, bValue);
  bool result = this->internal->UpdateLooped(bValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::UpdateVolume( float flValue )
{
  TRACE("((this[ISteamMusicRemote])%p, (float)%f)\n", this, flValue);
  bool result = this->internal->UpdateVolume(flValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::CurrentEntryWillChange()
{
  TRACE("((this[ISteamMusicRemote])%p)\n", this);
  bool result = this->internal->CurrentEntryWillChange();
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::CurrentEntryIsAvailable( bool bAvailable )
{
  TRACE("((this[ISteamMusicRemote])%p, (bool)%d)\n", this, bAvailable);
  bool result = this->internal->CurrentEntryIsAvailable(bAvailable);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::UpdateCurrentEntryText( const char *pchText )
{
  TRACE("((this[ISteamMusicRemote])%p, (const char *)\"%s\")\n", this, pchText);
  bool result = this->internal->UpdateCurrentEntryText(pchText);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::UpdateCurrentEntryElapsedSeconds( int nValue )
{
  TRACE("((this[ISteamMusicRemote])%p, (int)%d)\n", this, nValue);
  bool result = this->internal->UpdateCurrentEntryElapsedSeconds(nValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::UpdateCurrentEntryCoverArt( void *pvBuffer, uint32 cbBufferLength )
{
  TRACE("((this[ISteamMusicRemote])%p, (void *)%p, (uint32)%d)\n", this, pvBuffer, cbBufferLength);
  bool result = this->internal->UpdateCurrentEntryCoverArt(pvBuffer, cbBufferLength);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::CurrentEntryDidChange()
{
  TRACE("((this[ISteamMusicRemote])%p)\n", this);
  bool result = this->internal->CurrentEntryDidChange();
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::QueueWillChange()
{
  TRACE("((this[ISteamMusicRemote])%p)\n", this);
  bool result = this->internal->QueueWillChange();
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::ResetQueueEntries()
{
  TRACE("((this[ISteamMusicRemote])%p)\n", this);
  bool result = this->internal->ResetQueueEntries();
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::SetQueueEntry( int nID, int nPosition, const char *pchEntryText )
{
  TRACE("((this[ISteamMusicRemote])%p, (int)%d, (int)%d, (const char *)\"%s\")\n", this, nID, nPosition, pchEntryText);
  bool result = this->internal->SetQueueEntry(nID, nPosition, pchEntryText);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::SetCurrentQueueEntry( int nID )
{
  TRACE("((this[ISteamMusicRemote])%p, (int)%d)\n", this, nID);
  bool result = this->internal->SetCurrentQueueEntry(nID);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::QueueDidChange()
{
  TRACE("((this[ISteamMusicRemote])%p)\n", this);
  bool result = this->internal->QueueDidChange();
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::PlaylistWillChange()
{
  TRACE("((this[ISteamMusicRemote])%p)\n", this);
  bool result = this->internal->PlaylistWillChange();
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::ResetPlaylistEntries()
{
  TRACE("((this[ISteamMusicRemote])%p)\n", this);
  bool result = this->internal->ResetPlaylistEntries();
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::SetPlaylistEntry( int nID, int nPosition, const char *pchEntryText )
{
  TRACE("((this[ISteamMusicRemote])%p, (int)%d, (int)%d, (const char *)\"%s\")\n", this, nID, nPosition, pchEntryText);
  bool result = this->internal->SetPlaylistEntry(nID, nPosition, pchEntryText);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::SetCurrentPlaylistEntry( int nID )
{
  TRACE("((this[ISteamMusicRemote])%p, (int)%d)\n", this, nID);
  bool result = this->internal->SetCurrentPlaylistEntry(nID);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMusicRemote_::PlaylistDidChange()
{
  TRACE("((this[ISteamMusicRemote])%p)\n", this);
  bool result = this->internal->PlaylistDidChange();
  TRACE(" = (bool)%d\n", result);
  return result;
}
#endif
