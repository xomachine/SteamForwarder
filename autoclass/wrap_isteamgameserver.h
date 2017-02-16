#ifndef WRAP_ISTEAMGAMESERVER_H
#define WRAP_ISTEAMGAMESERVER_H
#include "steam_api.h"
class ISteamGameServer_ 
{
  virtual bool InitGameServer( uint32 unIP, uint16 usGamePort, uint16 usQueryPort, uint32 unFlags, AppId_t nGameAppId, const char *pchVersionString ) __attribute__((thiscall));
  virtual void SetProduct( const char *pszProduct ) __attribute__((thiscall));
  virtual void SetGameDescription( const char *pszGameDescription ) __attribute__((thiscall));
  virtual void SetModDir( const char *pszModDir ) __attribute__((thiscall));
  virtual void SetDedicatedServer( bool bDedicated ) __attribute__((thiscall));
  virtual void LogOn( const char *pszToken ) __attribute__((thiscall));
  virtual void LogOnAnonymous() __attribute__((thiscall));
  virtual void LogOff() __attribute__((thiscall));
  virtual bool BLoggedOn() __attribute__((thiscall));
  virtual bool BSecure() __attribute__((thiscall));
  virtual CSteamID* GetSteamID(CSteamID* hidden) __attribute__((thiscall));
  virtual bool WasRestartRequested() __attribute__((thiscall));
  virtual void SetMaxPlayerCount( int cPlayersMax ) __attribute__((thiscall));
  virtual void SetBotPlayerCount( int cBotplayers ) __attribute__((thiscall));
  virtual void SetServerName( const char *pszServerName ) __attribute__((thiscall));
  virtual void SetMapName( const char *pszMapName ) __attribute__((thiscall));
  virtual void SetPasswordProtected( bool bPasswordProtected ) __attribute__((thiscall));
  virtual void SetSpectatorPort( uint16 unSpectatorPort ) __attribute__((thiscall));
  virtual void SetSpectatorServerName( const char *pszSpectatorServerName ) __attribute__((thiscall));
  virtual void ClearAllKeyValues() __attribute__((thiscall));
  virtual void SetKeyValue( const char *pKey, const char *pValue ) __attribute__((thiscall));
  virtual void SetGameTags( const char *pchGameTags ) __attribute__((thiscall));
  virtual void SetGameData( const char *pchGameData ) __attribute__((thiscall));
  virtual void SetRegion( const char *pszRegion ) __attribute__((thiscall));
  virtual bool SendUserConnectAndAuthenticate( uint32 unIPClient, const void *pvAuthBlob, uint32 cubAuthBlobSize, CSteamID *pSteamIDUser ) __attribute__((thiscall));
  virtual CSteamID* CreateUnauthenticatedUserConnection(CSteamID* hidden) __attribute__((thiscall));
  virtual void SendUserDisconnect( CSteamID steamIDUser ) __attribute__((thiscall));
  virtual bool BUpdateUserData( CSteamID steamIDUser, const char *pchPlayerName, uint32 uScore ) __attribute__((thiscall));
  virtual HAuthTicket GetAuthSessionTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket ) __attribute__((thiscall));
  virtual EBeginAuthSessionResult BeginAuthSession( const void *pAuthTicket, int cbAuthTicket, CSteamID steamID ) __attribute__((thiscall));
  virtual void EndAuthSession( CSteamID steamID ) __attribute__((thiscall));
  virtual void CancelAuthTicket( HAuthTicket hAuthTicket ) __attribute__((thiscall));
  virtual EUserHasLicenseForAppResult UserHasLicenseForApp( CSteamID steamID, AppId_t appID ) __attribute__((thiscall));
  virtual bool RequestUserGroupStatus( CSteamID steamIDUser, CSteamID steamIDGroup ) __attribute__((thiscall));
  virtual void GetGameplayStats( ) __attribute__((thiscall));
  virtual SteamAPICall_t GetServerReputation() __attribute__((thiscall));
  virtual uint32 GetPublicIP() __attribute__((thiscall));
  virtual bool HandleIncomingPacket( const void *pData, int cbData, uint32 srcIP, uint16 srcPort ) __attribute__((thiscall));
  virtual int GetNextOutgoingPacket( void *pOut, int cbMaxOut, uint32 *pNetAdr, uint16 *pPort ) __attribute__((thiscall));
  virtual void EnableHeartbeats( bool bActive ) __attribute__((thiscall));
  virtual void SetHeartbeatInterval( int iHeartbeatInterval ) __attribute__((thiscall));
  virtual void ForceHeartbeat() __attribute__((thiscall));
  virtual SteamAPICall_t AssociateWithClan( CSteamID steamIDClan ) __attribute__((thiscall));
  virtual SteamAPICall_t ComputeNewPlayerCompatibility( CSteamID steamIDNewPlayer ) __attribute__((thiscall));
  public:
    ISteamGameServer *internal;
};
#endif
