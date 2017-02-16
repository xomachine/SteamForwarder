#ifndef WRAP_ISTEAMCLIENT_H
#define WRAP_ISTEAMCLIENT_H
#include "steam_api.h"
class ISteamClient_ 
{
  virtual HSteamPipe CreateSteamPipe() __attribute__((thiscall));
  virtual bool BReleaseSteamPipe( HSteamPipe hSteamPipe ) __attribute__((thiscall));
  virtual HSteamUser ConnectToGlobalUser( HSteamPipe hSteamPipe ) __attribute__((thiscall));
  virtual HSteamUser CreateLocalUser( HSteamPipe *phSteamPipe, EAccountType eAccountType ) __attribute__((thiscall));
  virtual void ReleaseUser( HSteamPipe hSteamPipe, HSteamUser hUser ) __attribute__((thiscall));
  virtual ISteamUser * GetISteamUser( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) __attribute__((thiscall));
  virtual ISteamGameServer * GetISteamGameServer( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) __attribute__((thiscall));
  virtual void SetLocalIPBinding( uint32 unIP, uint16 usPort ) __attribute__((thiscall));
  virtual ISteamFriends * GetISteamFriends( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) __attribute__((thiscall));
  virtual ISteamUtils * GetISteamUtils( HSteamPipe hSteamPipe, const char *pchVersion ) __attribute__((thiscall));
  virtual ISteamMatchmaking * GetISteamMatchmaking( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) __attribute__((thiscall));
  virtual ISteamMatchmakingServers * GetISteamMatchmakingServers( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) __attribute__((thiscall));
  virtual void * GetISteamGenericInterface( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) __attribute__((thiscall));
  virtual ISteamUserStats * GetISteamUserStats( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) __attribute__((thiscall));
  virtual ISteamGameServerStats * GetISteamGameServerStats( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) __attribute__((thiscall));
  virtual ISteamApps * GetISteamApps( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) __attribute__((thiscall));
  virtual ISteamNetworking * GetISteamNetworking( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) __attribute__((thiscall));
  virtual ISteamRemoteStorage * GetISteamRemoteStorage( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) __attribute__((thiscall));
  virtual ISteamScreenshots * GetISteamScreenshots( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) __attribute__((thiscall));
  virtual void RunFrame() __attribute__((thiscall));
  virtual uint32 GetIPCCallCount() __attribute__((thiscall));
  virtual void SetWarningMessageHook( SteamAPIWarningMessageHook_t pFunction ) __attribute__((thiscall));
  virtual bool BShutdownIfAllPipesClosed() __attribute__((thiscall));
  virtual ISteamHTTP * GetISteamHTTP( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) __attribute__((thiscall));
  virtual ISteamUnifiedMessages * GetISteamUnifiedMessages( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) __attribute__((thiscall));
  virtual ISteamController * GetISteamController( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) __attribute__((thiscall));
  virtual ISteamUGC * GetISteamUGC( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) __attribute__((thiscall));
  virtual ISteamAppList * GetISteamAppList( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) __attribute__((thiscall));
  virtual ISteamMusic * GetISteamMusic( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) __attribute__((thiscall));
  virtual ISteamMusicRemote * GetISteamMusicRemote(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion) __attribute__((thiscall));
  virtual ISteamHTMLSurface * GetISteamHTMLSurface(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion) __attribute__((thiscall));
  virtual void DEPRECATED_Set_SteamAPI_CPostAPIResultInProcess( void (*)() ) __attribute__((thiscall));
  virtual void DEPRECATED_Remove_SteamAPI_CPostAPIResultInProcess( void (*)() ) __attribute__((thiscall));
  virtual void Set_SteamAPI_CCheckCallbackRegisteredInProcess( SteamAPI_CheckCallbackRegistered_t func ) __attribute__((thiscall));
  virtual ISteamInventory * GetISteamInventory( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) __attribute__((thiscall));
  virtual ISteamVideo * GetISteamVideo( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion ) __attribute__((thiscall));
  public:
    ISteamClient *internal;
};
#endif
