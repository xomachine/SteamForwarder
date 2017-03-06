#include <steam_api_.h>

bool  ISteamGameServer_::InitGameServer(uint32  unIP, uint16  usGamePort, uint16  usQueryPort, uint32  unFlags, AppId_t  nGameAppId, char * pchVersionString)
{
  TRACE("((ISteamGameServer *)%p, (uint32 )%d, (uint16 )%d, (uint16 )%d, (uint32 )%d, (AppId_t )%p, (char *)\"%s\")\n", this, unIP, usGamePort, usQueryPort, unFlags, nGameAppId, pchVersionString);
  auto result = this->internal->InitGameServer(unIP, usGamePort, usQueryPort, unFlags, nGameAppId, pchVersionString);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  ISteamGameServer_::SetProduct(char * pszProduct)
{
  TRACE("((ISteamGameServer *)%p, (char *)\"%s\")\n", this, pszProduct);
  this->internal->SetProduct(pszProduct);
  
}


void  ISteamGameServer_::SetGameDescription(char * pszGameDescription)
{
  TRACE("((ISteamGameServer *)%p, (char *)\"%s\")\n", this, pszGameDescription);
  this->internal->SetGameDescription(pszGameDescription);
  
}


void  ISteamGameServer_::SetModDir(char * pszModDir)
{
  TRACE("((ISteamGameServer *)%p, (char *)\"%s\")\n", this, pszModDir);
  this->internal->SetModDir(pszModDir);
  
}


void  ISteamGameServer_::SetDedicatedServer(bool  bDedicated)
{
  TRACE("((ISteamGameServer *)%p, (bool )%d)\n", this, bDedicated);
  this->internal->SetDedicatedServer(bDedicated);
  
}


void  ISteamGameServer_::LogOn(char * pszToken)
{
  TRACE("((ISteamGameServer *)%p, (char *)\"%s\")\n", this, pszToken);
  this->internal->LogOn(pszToken);
  
}


void  ISteamGameServer_::LogOnAnonymous()
{
  TRACE("((ISteamGameServer *)%p)\n", this);
  this->internal->LogOnAnonymous();
  
}


void  ISteamGameServer_::LogOff()
{
  TRACE("((ISteamGameServer *)%p)\n", this);
  this->internal->LogOff();
  
}


bool  ISteamGameServer_::BLoggedOn()
{
  TRACE("((ISteamGameServer *)%p)\n", this);
  auto result = this->internal->BLoggedOn();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamGameServer_::BSecure()
{
  TRACE("((ISteamGameServer *)%p)\n", this);
  auto result = this->internal->BSecure();
  TRACE("() = (bool )%d\n", result);

  return result;
}


CSteamID * ISteamGameServer_::GetSteamID(CSteamID * hidden)
{
  TRACE("((ISteamGameServer *)%p)\n", this);
  *hidden = this->internal->GetSteamID();
  return hidden;
}


bool  ISteamGameServer_::WasRestartRequested()
{
  TRACE("((ISteamGameServer *)%p)\n", this);
  auto result = this->internal->WasRestartRequested();
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  ISteamGameServer_::SetMaxPlayerCount(int  cPlayersMax)
{
  TRACE("((ISteamGameServer *)%p, (int )%d)\n", this, cPlayersMax);
  this->internal->SetMaxPlayerCount(cPlayersMax);
  
}


void  ISteamGameServer_::SetBotPlayerCount(int  cBotplayers)
{
  TRACE("((ISteamGameServer *)%p, (int )%d)\n", this, cBotplayers);
  this->internal->SetBotPlayerCount(cBotplayers);
  
}


void  ISteamGameServer_::SetServerName(char * pszServerName)
{
  TRACE("((ISteamGameServer *)%p, (char *)\"%s\")\n", this, pszServerName);
  this->internal->SetServerName(pszServerName);
  
}


void  ISteamGameServer_::SetMapName(char * pszMapName)
{
  TRACE("((ISteamGameServer *)%p, (char *)\"%s\")\n", this, pszMapName);
  this->internal->SetMapName(pszMapName);
  
}


void  ISteamGameServer_::SetPasswordProtected(bool  bPasswordProtected)
{
  TRACE("((ISteamGameServer *)%p, (bool )%d)\n", this, bPasswordProtected);
  this->internal->SetPasswordProtected(bPasswordProtected);
  
}


void  ISteamGameServer_::SetSpectatorPort(uint16  unSpectatorPort)
{
  TRACE("((ISteamGameServer *)%p, (uint16 )%d)\n", this, unSpectatorPort);
  this->internal->SetSpectatorPort(unSpectatorPort);
  
}


void  ISteamGameServer_::SetSpectatorServerName(char * pszSpectatorServerName)
{
  TRACE("((ISteamGameServer *)%p, (char *)\"%s\")\n", this, pszSpectatorServerName);
  this->internal->SetSpectatorServerName(pszSpectatorServerName);
  
}


void  ISteamGameServer_::ClearAllKeyValues()
{
  TRACE("((ISteamGameServer *)%p)\n", this);
  this->internal->ClearAllKeyValues();
  
}


void  ISteamGameServer_::SetKeyValue(char * pKey, char * pValue)
{
  TRACE("((ISteamGameServer *)%p, (char *)\"%s\", (char *)\"%s\")\n", this, pKey, pValue);
  this->internal->SetKeyValue(pKey, pValue);
  
}


void  ISteamGameServer_::SetGameTags(char * pchGameTags)
{
  TRACE("((ISteamGameServer *)%p, (char *)\"%s\")\n", this, pchGameTags);
  this->internal->SetGameTags(pchGameTags);
  
}


void  ISteamGameServer_::SetGameData(char * pchGameData)
{
  TRACE("((ISteamGameServer *)%p, (char *)\"%s\")\n", this, pchGameData);
  this->internal->SetGameData(pchGameData);
  
}


void  ISteamGameServer_::SetRegion(char * pszRegion)
{
  TRACE("((ISteamGameServer *)%p, (char *)\"%s\")\n", this, pszRegion);
  this->internal->SetRegion(pszRegion);
  
}


bool  ISteamGameServer_::SendUserConnectAndAuthenticate(uint32  unIPClient, void * pvAuthBlob, uint32  cubAuthBlobSize, CSteamID * pSteamIDUser)
{
  TRACE("((ISteamGameServer *)%p, (uint32 )%d, (void *)%p, (uint32 )%d, (CSteamID *)%p)\n", this, unIPClient, pvAuthBlob, cubAuthBlobSize, pSteamIDUser);
  auto result = this->internal->SendUserConnectAndAuthenticate(unIPClient, pvAuthBlob, cubAuthBlobSize, pSteamIDUser);
  TRACE("() = (bool )%d\n", result);

  return result;
}


CSteamID * ISteamGameServer_::CreateUnauthenticatedUserConnection(CSteamID * hidden)
{
  TRACE("((ISteamGameServer *)%p)\n", this);
  *hidden = this->internal->CreateUnauthenticatedUserConnection();
  return hidden;
}


void  ISteamGameServer_::SendUserDisconnect(CSteamID  steamIDUser)
{
  TRACE("((ISteamGameServer *)%p, (CSteamID )%p)\n", this, steamIDUser);
  this->internal->SendUserDisconnect(steamIDUser);
  
}


bool  ISteamGameServer_::BUpdateUserData(CSteamID  steamIDUser, char * pchPlayerName, uint32  uScore)
{
  TRACE("((ISteamGameServer *)%p, (CSteamID )%p, (char *)\"%s\", (uint32 )%d)\n", this, steamIDUser, pchPlayerName, uScore);
  auto result = this->internal->BUpdateUserData(steamIDUser, pchPlayerName, uScore);
  TRACE("() = (bool )%d\n", result);

  return result;
}


HAuthTicket  ISteamGameServer_::GetAuthSessionTicket(void * pTicket, int  cbMaxTicket, uint32 * pcbTicket)
{
  TRACE("((ISteamGameServer *)%p, (void *)%p, (int )%d, (uint32 *)%d)\n", this, pTicket, cbMaxTicket, pcbTicket);
  auto result = this->internal->GetAuthSessionTicket(pTicket, cbMaxTicket, pcbTicket);
  TRACE("() = (HAuthTicket )%p\n", result);

  return result;
}


EBeginAuthSessionResult  ISteamGameServer_::BeginAuthSession(void * pAuthTicket, int  cbAuthTicket, CSteamID  steamID)
{
  TRACE("((ISteamGameServer *)%p, (void *)%p, (int )%d, (CSteamID )%p)\n", this, pAuthTicket, cbAuthTicket, steamID);
  auto result = this->internal->BeginAuthSession(pAuthTicket, cbAuthTicket, steamID);
  TRACE("() = (EBeginAuthSessionResult )%p\n", result);

  return result;
}


void  ISteamGameServer_::EndAuthSession(CSteamID  steamID)
{
  TRACE("((ISteamGameServer *)%p, (CSteamID )%p)\n", this, steamID);
  this->internal->EndAuthSession(steamID);
  
}


void  ISteamGameServer_::CancelAuthTicket(HAuthTicket  hAuthTicket)
{
  TRACE("((ISteamGameServer *)%p, (HAuthTicket )%p)\n", this, hAuthTicket);
  this->internal->CancelAuthTicket(hAuthTicket);
  
}


EUserHasLicenseForAppResult  ISteamGameServer_::UserHasLicenseForApp(CSteamID  steamID, AppId_t  appID)
{
  TRACE("((ISteamGameServer *)%p, (CSteamID )%p, (AppId_t )%p)\n", this, steamID, appID);
  auto result = this->internal->UserHasLicenseForApp(steamID, appID);
  TRACE("() = (EUserHasLicenseForAppResult )%p\n", result);

  return result;
}


bool  ISteamGameServer_::RequestUserGroupStatus(CSteamID  steamIDUser, CSteamID  steamIDGroup)
{
  TRACE("((ISteamGameServer *)%p, (CSteamID )%p, (CSteamID )%p)\n", this, steamIDUser, steamIDGroup);
  auto result = this->internal->RequestUserGroupStatus(steamIDUser, steamIDGroup);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  ISteamGameServer_::GetGameplayStats()
{
  TRACE("((ISteamGameServer *)%p)\n", this);
  this->internal->GetGameplayStats();
  
}


SteamAPICall_t  ISteamGameServer_::GetServerReputation()
{
  TRACE("((ISteamGameServer *)%p)\n", this);
  auto result = this->internal->GetServerReputation();
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


uint32  ISteamGameServer_::GetPublicIP()
{
  TRACE("((ISteamGameServer *)%p)\n", this);
  auto result = this->internal->GetPublicIP();
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


bool  ISteamGameServer_::HandleIncomingPacket(void * pData, int  cbData, uint32  srcIP, uint16  srcPort)
{
  TRACE("((ISteamGameServer *)%p, (void *)%p, (int )%d, (uint32 )%d, (uint16 )%d)\n", this, pData, cbData, srcIP, srcPort);
  auto result = this->internal->HandleIncomingPacket(pData, cbData, srcIP, srcPort);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  ISteamGameServer_::GetNextOutgoingPacket(void * pOut, int  cbMaxOut, uint32 * pNetAdr, uint16 * pPort)
{
  TRACE("((ISteamGameServer *)%p, (void *)%p, (int )%d, (uint32 *)%d, (uint16 *)%d)\n", this, pOut, cbMaxOut, pNetAdr, pPort);
  auto result = this->internal->GetNextOutgoingPacket(pOut, cbMaxOut, pNetAdr, pPort);
  TRACE("() = (int )%d\n", result);

  return result;
}


void  ISteamGameServer_::EnableHeartbeats(bool  bActive)
{
  TRACE("((ISteamGameServer *)%p, (bool )%d)\n", this, bActive);
  this->internal->EnableHeartbeats(bActive);
  
}


void  ISteamGameServer_::SetHeartbeatInterval(int  iHeartbeatInterval)
{
  TRACE("((ISteamGameServer *)%p, (int )%d)\n", this, iHeartbeatInterval);
  this->internal->SetHeartbeatInterval(iHeartbeatInterval);
  
}


void  ISteamGameServer_::ForceHeartbeat()
{
  TRACE("((ISteamGameServer *)%p)\n", this);
  this->internal->ForceHeartbeat();
  
}


SteamAPICall_t  ISteamGameServer_::AssociateWithClan(CSteamID  steamIDClan)
{
  TRACE("((ISteamGameServer *)%p, (CSteamID )%p)\n", this, steamIDClan);
  auto result = this->internal->AssociateWithClan(steamIDClan);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamGameServer_::ComputeNewPlayerCompatibility(CSteamID  steamIDNewPlayer)
{
  TRACE("((ISteamGameServer *)%p, (CSteamID )%p)\n", this, steamIDNewPlayer);
  auto result = this->internal->ComputeNewPlayerCompatibility(steamIDNewPlayer);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}
ISteamGameServer_::ISteamGameServer_(ISteamGameServer * towrap)
{
  this->internal = towrap;
}

ISteamGameServer_::~ISteamGameServer_()
{
  delete this->internal;
}
