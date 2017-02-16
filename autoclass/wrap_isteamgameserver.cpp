#ifndef WRAP_ISTEAMGAMESERVER_CPP
#define WRAP_ISTEAMGAMESERVER_CPP
#include "autoclass/steam_api_.h" 
#include "windef.h"
#include "wine/debug.h"
#include "config.h"
bool ISteamGameServer_::InitGameServer( uint32 unIP, uint16 usGamePort, uint16 usQueryPort, uint32 unFlags, AppId_t nGameAppId, const char *pchVersionString )
{
  TRACE("((this[ISteamGameServer])%p, (uint32)%d, (uint16)%d, (uint16)%d, (uint32)%d, (AppId_t)%p, (const char *)\"%s\")\n", this, unIP, usGamePort, usQueryPort, unFlags, nGameAppId, pchVersionString);
  bool result = this->internal->InitGameServer(unIP, usGamePort, usQueryPort, unFlags, nGameAppId, pchVersionString);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void ISteamGameServer_::SetProduct( const char *pszProduct )
{
  TRACE("((this[ISteamGameServer])%p, (const char *)\"%s\")\n", this, pszProduct);
  this->internal->SetProduct(pszProduct);
}
void ISteamGameServer_::SetGameDescription( const char *pszGameDescription )
{
  TRACE("((this[ISteamGameServer])%p, (const char *)\"%s\")\n", this, pszGameDescription);
  this->internal->SetGameDescription(pszGameDescription);
}
void ISteamGameServer_::SetModDir( const char *pszModDir )
{
  TRACE("((this[ISteamGameServer])%p, (const char *)\"%s\")\n", this, pszModDir);
  this->internal->SetModDir(pszModDir);
}
void ISteamGameServer_::SetDedicatedServer( bool bDedicated )
{
  TRACE("((this[ISteamGameServer])%p, (bool)%d)\n", this, bDedicated);
  this->internal->SetDedicatedServer(bDedicated);
}
void ISteamGameServer_::LogOn( const char *pszToken )
{
  TRACE("((this[ISteamGameServer])%p, (const char *)\"%s\")\n", this, pszToken);
  this->internal->LogOn(pszToken);
}
void ISteamGameServer_::LogOnAnonymous()
{
  TRACE("((this[ISteamGameServer])%p)\n", this);
  this->internal->LogOnAnonymous();
}
void ISteamGameServer_::LogOff()
{
  TRACE("((this[ISteamGameServer])%p)\n", this);
  this->internal->LogOff();
}
bool ISteamGameServer_::BLoggedOn()
{
  TRACE("((this[ISteamGameServer])%p)\n", this);
  bool result = this->internal->BLoggedOn();
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamGameServer_::BSecure()
{
  TRACE("((this[ISteamGameServer])%p)\n", this);
  bool result = this->internal->BSecure();
  TRACE(" = (bool)%d\n", result);
  return result;
}
CSteamID* ISteamGameServer_::GetSteamID(CSteamID* hidden)
{
  TRACE("((this[ISteamGameServer])%p, (CSteamID*)%p)\n", this, hidden);
  *hidden = this->internal->GetSteamID();
  return hidden;
}
bool ISteamGameServer_::WasRestartRequested()
{
  TRACE("((this[ISteamGameServer])%p)\n", this);
  bool result = this->internal->WasRestartRequested();
  TRACE(" = (bool)%d\n", result);
  return result;
}
void ISteamGameServer_::SetMaxPlayerCount( int cPlayersMax )
{
  TRACE("((this[ISteamGameServer])%p, (int)%d)\n", this, cPlayersMax);
  this->internal->SetMaxPlayerCount(cPlayersMax);
}
void ISteamGameServer_::SetBotPlayerCount( int cBotplayers )
{
  TRACE("((this[ISteamGameServer])%p, (int)%d)\n", this, cBotplayers);
  this->internal->SetBotPlayerCount(cBotplayers);
}
void ISteamGameServer_::SetServerName( const char *pszServerName )
{
  TRACE("((this[ISteamGameServer])%p, (const char *)\"%s\")\n", this, pszServerName);
  this->internal->SetServerName(pszServerName);
}
void ISteamGameServer_::SetMapName( const char *pszMapName )
{
  TRACE("((this[ISteamGameServer])%p, (const char *)\"%s\")\n", this, pszMapName);
  this->internal->SetMapName(pszMapName);
}
void ISteamGameServer_::SetPasswordProtected( bool bPasswordProtected )
{
  TRACE("((this[ISteamGameServer])%p, (bool)%d)\n", this, bPasswordProtected);
  this->internal->SetPasswordProtected(bPasswordProtected);
}
void ISteamGameServer_::SetSpectatorPort( uint16 unSpectatorPort )
{
  TRACE("((this[ISteamGameServer])%p, (uint16)%d)\n", this, unSpectatorPort);
  this->internal->SetSpectatorPort(unSpectatorPort);
}
void ISteamGameServer_::SetSpectatorServerName( const char *pszSpectatorServerName )
{
  TRACE("((this[ISteamGameServer])%p, (const char *)\"%s\")\n", this, pszSpectatorServerName);
  this->internal->SetSpectatorServerName(pszSpectatorServerName);
}
void ISteamGameServer_::ClearAllKeyValues()
{
  TRACE("((this[ISteamGameServer])%p)\n", this);
  this->internal->ClearAllKeyValues();
}
void ISteamGameServer_::SetKeyValue( const char *pKey, const char *pValue )
{
  TRACE("((this[ISteamGameServer])%p, (const char *)\"%s\", (const char *)\"%s\")\n", this, pKey, pValue);
  this->internal->SetKeyValue(pKey, pValue);
}
void ISteamGameServer_::SetGameTags( const char *pchGameTags )
{
  TRACE("((this[ISteamGameServer])%p, (const char *)\"%s\")\n", this, pchGameTags);
  this->internal->SetGameTags(pchGameTags);
}
void ISteamGameServer_::SetGameData( const char *pchGameData )
{
  TRACE("((this[ISteamGameServer])%p, (const char *)\"%s\")\n", this, pchGameData);
  this->internal->SetGameData(pchGameData);
}
void ISteamGameServer_::SetRegion( const char *pszRegion )
{
  TRACE("((this[ISteamGameServer])%p, (const char *)\"%s\")\n", this, pszRegion);
  this->internal->SetRegion(pszRegion);
}
bool ISteamGameServer_::SendUserConnectAndAuthenticate( uint32 unIPClient, const void *pvAuthBlob, uint32 cubAuthBlobSize, CSteamID *pSteamIDUser )
{
  TRACE("((this[ISteamGameServer])%p, (uint32)%d, (const void *)%p, (uint32)%d, (CSteamID *)%p)\n", this, unIPClient, pvAuthBlob, cubAuthBlobSize, pSteamIDUser);
  bool result = this->internal->SendUserConnectAndAuthenticate(unIPClient, pvAuthBlob, cubAuthBlobSize, pSteamIDUser);
  TRACE(" = (bool)%d\n", result);
  return result;
}
CSteamID* ISteamGameServer_::CreateUnauthenticatedUserConnection(CSteamID* hidden)
{
  TRACE("((this[ISteamGameServer])%p, (CSteamID*)%p)\n", this, hidden);
  *hidden = this->internal->CreateUnauthenticatedUserConnection();
  return hidden;
}
void ISteamGameServer_::SendUserDisconnect( CSteamID steamIDUser )
{
  TRACE("((this[ISteamGameServer])%p, (CSteamID)%p)\n", this, steamIDUser);
  this->internal->SendUserDisconnect(steamIDUser);
}
bool ISteamGameServer_::BUpdateUserData( CSteamID steamIDUser, const char *pchPlayerName, uint32 uScore )
{
  TRACE("((this[ISteamGameServer])%p, (CSteamID)%p, (const char *)\"%s\", (uint32)%d)\n", this, steamIDUser, pchPlayerName, uScore);
  bool result = this->internal->BUpdateUserData(steamIDUser, pchPlayerName, uScore);
  TRACE(" = (bool)%d\n", result);
  return result;
}
HAuthTicket ISteamGameServer_::GetAuthSessionTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket )
{
  TRACE("((this[ISteamGameServer])%p, (void *)%p, (int)%d, (uint32 *)%p)\n", this, pTicket, cbMaxTicket, pcbTicket);
  HAuthTicket result = this->internal->GetAuthSessionTicket(pTicket, cbMaxTicket, pcbTicket);
  TRACE(" = (HAuthTicket)%p\n", result);
  return result;
}
EBeginAuthSessionResult ISteamGameServer_::BeginAuthSession( const void *pAuthTicket, int cbAuthTicket, CSteamID steamID )
{
  TRACE("((this[ISteamGameServer])%p, (const void *)%p, (int)%d, (CSteamID)%p)\n", this, pAuthTicket, cbAuthTicket, steamID);
  EBeginAuthSessionResult result = this->internal->BeginAuthSession(pAuthTicket, cbAuthTicket, steamID);
  TRACE(" = (EBeginAuthSessionResult)%p\n", result);
  return result;
}
void ISteamGameServer_::EndAuthSession( CSteamID steamID )
{
  TRACE("((this[ISteamGameServer])%p, (CSteamID)%p)\n", this, steamID);
  this->internal->EndAuthSession(steamID);
}
void ISteamGameServer_::CancelAuthTicket( HAuthTicket hAuthTicket )
{
  TRACE("((this[ISteamGameServer])%p, (HAuthTicket)%p)\n", this, hAuthTicket);
  this->internal->CancelAuthTicket(hAuthTicket);
}
EUserHasLicenseForAppResult ISteamGameServer_::UserHasLicenseForApp( CSteamID steamID, AppId_t appID )
{
  TRACE("((this[ISteamGameServer])%p, (CSteamID)%p, (AppId_t)%p)\n", this, steamID, appID);
  EUserHasLicenseForAppResult result = this->internal->UserHasLicenseForApp(steamID, appID);
  TRACE(" = (EUserHasLicenseForAppResult)%p\n", result);
  return result;
}
bool ISteamGameServer_::RequestUserGroupStatus( CSteamID steamIDUser, CSteamID steamIDGroup )
{
  TRACE("((this[ISteamGameServer])%p, (CSteamID)%p, (CSteamID)%p)\n", this, steamIDUser, steamIDGroup);
  bool result = this->internal->RequestUserGroupStatus(steamIDUser, steamIDGroup);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void ISteamGameServer_::GetGameplayStats( )
{
  TRACE("((this[ISteamGameServer])%p)\n", this);
  this->internal->GetGameplayStats();
}
SteamAPICall_t ISteamGameServer_::GetServerReputation()
{
  TRACE("((this[ISteamGameServer])%p)\n", this);
  SteamAPICall_t result = this->internal->GetServerReputation();
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
uint32 ISteamGameServer_::GetPublicIP()
{
  TRACE("((this[ISteamGameServer])%p)\n", this);
  uint32 result = this->internal->GetPublicIP();
  TRACE(" = (uint32)%d\n", result);
  return result;
}
bool ISteamGameServer_::HandleIncomingPacket( const void *pData, int cbData, uint32 srcIP, uint16 srcPort )
{
  TRACE("((this[ISteamGameServer])%p, (const void *)%p, (int)%d, (uint32)%d, (uint16)%d)\n", this, pData, cbData, srcIP, srcPort);
  bool result = this->internal->HandleIncomingPacket(pData, cbData, srcIP, srcPort);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int ISteamGameServer_::GetNextOutgoingPacket( void *pOut, int cbMaxOut, uint32 *pNetAdr, uint16 *pPort )
{
  TRACE("((this[ISteamGameServer])%p, (void *)%p, (int)%d, (uint32 *)%p, (uint16 *)%p)\n", this, pOut, cbMaxOut, pNetAdr, pPort);
  int result = this->internal->GetNextOutgoingPacket(pOut, cbMaxOut, pNetAdr, pPort);
  TRACE(" = (int)%d\n", result);
  return result;
}
void ISteamGameServer_::EnableHeartbeats( bool bActive )
{
  TRACE("((this[ISteamGameServer])%p, (bool)%d)\n", this, bActive);
  this->internal->EnableHeartbeats(bActive);
}
void ISteamGameServer_::SetHeartbeatInterval( int iHeartbeatInterval )
{
  TRACE("((this[ISteamGameServer])%p, (int)%d)\n", this, iHeartbeatInterval);
  this->internal->SetHeartbeatInterval(iHeartbeatInterval);
}
void ISteamGameServer_::ForceHeartbeat()
{
  TRACE("((this[ISteamGameServer])%p)\n", this);
  this->internal->ForceHeartbeat();
}
SteamAPICall_t ISteamGameServer_::AssociateWithClan( CSteamID steamIDClan )
{
  TRACE("((this[ISteamGameServer])%p, (CSteamID)%p)\n", this, steamIDClan);
  SteamAPICall_t result = this->internal->AssociateWithClan(steamIDClan);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t ISteamGameServer_::ComputeNewPlayerCompatibility( CSteamID steamIDNewPlayer )
{
  TRACE("((this[ISteamGameServer])%p, (CSteamID)%p)\n", this, steamIDNewPlayer);
  SteamAPICall_t result = this->internal->ComputeNewPlayerCompatibility(steamIDNewPlayer);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
#endif
