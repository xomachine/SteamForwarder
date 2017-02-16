#ifndef WRAP_ISTEAMMUSICREMOTE_H
#define WRAP_ISTEAMMUSICREMOTE_H
#include "steam_api.h"
class ISteamMusicRemote_ 
{
  virtual bool RegisterSteamMusicRemote( const char *pchName ) __attribute__((thiscall));
  virtual bool DeregisterSteamMusicRemote() __attribute__((thiscall));
  virtual bool BIsCurrentMusicRemote() __attribute__((thiscall));
  virtual bool BActivationSuccess( bool bValue ) __attribute__((thiscall));
  virtual bool SetDisplayName( const char *pchDisplayName ) __attribute__((thiscall));
  virtual bool SetPNGIcon_64x64( void *pvBuffer, uint32 cbBufferLength ) __attribute__((thiscall));
  virtual bool EnablePlayPrevious(bool bValue) __attribute__((thiscall));
  virtual bool EnablePlayNext( bool bValue ) __attribute__((thiscall));
  virtual bool EnableShuffled( bool bValue ) __attribute__((thiscall));
  virtual bool EnableLooped( bool bValue ) __attribute__((thiscall));
  virtual bool EnableQueue( bool bValue ) __attribute__((thiscall));
  virtual bool EnablePlaylists( bool bValue ) __attribute__((thiscall));
  virtual bool UpdatePlaybackStatus( AudioPlayback_Status nStatus ) __attribute__((thiscall));
  virtual bool UpdateShuffled( bool bValue ) __attribute__((thiscall));
  virtual bool UpdateLooped( bool bValue ) __attribute__((thiscall));
  virtual bool UpdateVolume( float flValue ) __attribute__((thiscall));
  virtual bool CurrentEntryWillChange() __attribute__((thiscall));
  virtual bool CurrentEntryIsAvailable( bool bAvailable ) __attribute__((thiscall));
  virtual bool UpdateCurrentEntryText( const char *pchText ) __attribute__((thiscall));
  virtual bool UpdateCurrentEntryElapsedSeconds( int nValue ) __attribute__((thiscall));
  virtual bool UpdateCurrentEntryCoverArt( void *pvBuffer, uint32 cbBufferLength ) __attribute__((thiscall));
  virtual bool CurrentEntryDidChange() __attribute__((thiscall));
  virtual bool QueueWillChange() __attribute__((thiscall));
  virtual bool ResetQueueEntries() __attribute__((thiscall));
  virtual bool SetQueueEntry( int nID, int nPosition, const char *pchEntryText ) __attribute__((thiscall));
  virtual bool SetCurrentQueueEntry( int nID ) __attribute__((thiscall));
  virtual bool QueueDidChange() __attribute__((thiscall));
  virtual bool PlaylistWillChange() __attribute__((thiscall));
  virtual bool ResetPlaylistEntries() __attribute__((thiscall));
  virtual bool SetPlaylistEntry( int nID, int nPosition, const char *pchEntryText ) __attribute__((thiscall));
  virtual bool SetCurrentPlaylistEntry( int nID ) __attribute__((thiscall));
  virtual bool PlaylistDidChange() __attribute__((thiscall));
  public:
    ISteamMusicRemote *internal;
};
#endif
