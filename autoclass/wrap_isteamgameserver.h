#include <steam_api_.h>
#include <isteamgameserver.h>
class ISteamGameServer_
{
public:
  virtual bool  InitGameServer(uint32  unIP, uint16  usGamePort, uint16  usQueryPort, uint32  unFlags, AppId_t  nGameAppId, char * pchVersionString) __attribute__((thiscall));
  virtual void  SetProduct(char * pszProduct) __attribute__((thiscall));
  virtual void  SetGameDescription(char * pszGameDescription) __attribute__((thiscall));
  virtual void  SetModDir(char * pszModDir) __attribute__((thiscall));
  virtual void  SetDedicatedServer(bool  bDedicated) __attribute__((thiscall));
  virtual void  LogOn(char * pszToken) __attribute__((thiscall));
  virtual void  LogOnAnonymous() __attribute__((thiscall));
  virtual void  LogOff() __attribute__((thiscall));
  virtual bool  BLoggedOn() __attribute__((thiscall));
  virtual bool  BSecure() __attribute__((thiscall));
  virtual CSteamID * GetSteamID(CSteamID * hidden) __attribute__((thiscall));
  virtual bool  WasRestartRequested() __attribute__((thiscall));
  virtual void  SetMaxPlayerCount(int  cPlayersMax) __attribute__((thiscall));
  virtual void  SetBotPlayerCount(int  cBotplayers) __attribute__((thiscall));
  virtual void  SetServerName(char * pszServerName) __attribute__((thiscall));
  virtual void  SetMapName(char * pszMapName) __attribute__((thiscall));
  virtual void  SetPasswordProtected(bool  bPasswordProtected) __attribute__((thiscall));
  virtual void  SetSpectatorPort(uint16  unSpectatorPort) __attribute__((thiscall));
  virtual void  SetSpectatorServerName(char * pszSpectatorServerName) __attribute__((thiscall));
  virtual void  ClearAllKeyValues() __attribute__((thiscall));
  virtual void  SetKeyValue(char * pKey, char * pValue) __attribute__((thiscall));
  virtual void  SetGameTags(char * pchGameTags) __attribute__((thiscall));
  virtual void  SetGameData(char * pchGameData) __attribute__((thiscall));
  virtual void  SetRegion(char * pszRegion) __attribute__((thiscall));
  virtual bool  SendUserConnectAndAuthenticate(uint32  unIPClient, void * pvAuthBlob, uint32  cubAuthBlobSize, CSteamID * pSteamIDUser) __attribute__((thiscall));
  virtual CSteamID * CreateUnauthenticatedUserConnection(CSteamID * hidden) __attribute__((thiscall));
  virtual void  SendUserDisconnect(CSteamID  steamIDUser) __attribute__((thiscall));
  virtual bool  BUpdateUserData(CSteamID  steamIDUser, char * pchPlayerName, uint32  uScore) __attribute__((thiscall));
  virtual HAuthTicket  GetAuthSessionTicket(void * pTicket, int  cbMaxTicket, uint32 * pcbTicket) __attribute__((thiscall));
  virtual EBeginAuthSessionResult  BeginAuthSession(void * pAuthTicket, int  cbAuthTicket, CSteamID  steamID) __attribute__((thiscall));
  virtual void  EndAuthSession(CSteamID  steamID) __attribute__((thiscall));
  virtual void  CancelAuthTicket(HAuthTicket  hAuthTicket) __attribute__((thiscall));
  virtual EUserHasLicenseForAppResult  UserHasLicenseForApp(CSteamID  steamID, AppId_t  appID) __attribute__((thiscall));
  virtual bool  RequestUserGroupStatus(CSteamID  steamIDUser, CSteamID  steamIDGroup) __attribute__((thiscall));
  virtual void  GetGameplayStats() __attribute__((thiscall));
  virtual SteamAPICall_t  GetServerReputation() __attribute__((thiscall));
  virtual uint32  GetPublicIP() __attribute__((thiscall));
  virtual bool  HandleIncomingPacket(void * pData, int  cbData, uint32  srcIP, uint16  srcPort) __attribute__((thiscall));
  virtual int  GetNextOutgoingPacket(void * pOut, int  cbMaxOut, uint32 * pNetAdr, uint16 * pPort) __attribute__((thiscall));
  virtual void  EnableHeartbeats(bool  bActive) __attribute__((thiscall));
  virtual void  SetHeartbeatInterval(int  iHeartbeatInterval) __attribute__((thiscall));
  virtual void  ForceHeartbeat() __attribute__((thiscall));
  virtual SteamAPICall_t  AssociateWithClan(CSteamID  steamIDClan) __attribute__((thiscall));
  virtual SteamAPICall_t  ComputeNewPlayerCompatibility(CSteamID  steamIDNewPlayer) __attribute__((thiscall));
  ISteamGameServer_(ISteamGameServer*to_wrap);
  ~ISteamGameServer_();
private:
  ISteamGameServer * internal;
};
