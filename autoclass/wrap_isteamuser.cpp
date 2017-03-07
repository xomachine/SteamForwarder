#include <steam_api_.h>

HSteamUser  ISteamUser_::GetHSteamUser()
{
  TRACE("((ISteamUser *)%p)\n", this);
  HSteamUser  result = this->internal->GetHSteamUser();
  TRACE("() = (HSteamUser )%p\n", result);

  return result;
}


bool  ISteamUser_::BLoggedOn()
{
  TRACE("((ISteamUser *)%p)\n", this);
  bool  result = this->internal->BLoggedOn();
  TRACE("() = (bool )%d\n", result);

  return result;
}


CSteamID * ISteamUser_::GetSteamID(CSteamID * hidden)
{
  TRACE("((ISteamUser *)%p)\n", this);
  *hidden = this->internal->GetSteamID();
  return hidden;
}


int  ISteamUser_::InitiateGameConnection(void * pAuthBlob, int  cbMaxAuthBlob, CSteamID  steamIDGameServer, uint32  unIPServer, uint16  usPortServer, bool  bSecure)
{
  TRACE("((ISteamUser *)%p, (void *)%p, (int )%d, (CSteamID )%p, (uint32 )%d, (uint16 )%d, (bool )%d)\n", this, pAuthBlob, cbMaxAuthBlob, steamIDGameServer, unIPServer, usPortServer, bSecure);
  int  result = this->internal->InitiateGameConnection(pAuthBlob, cbMaxAuthBlob, steamIDGameServer, unIPServer, usPortServer, bSecure);
  TRACE("() = (int )%d\n", result);

  return result;
}


void  ISteamUser_::TerminateGameConnection(uint32  unIPServer, uint16  usPortServer)
{
  TRACE("((ISteamUser *)%p, (uint32 )%d, (uint16 )%d)\n", this, unIPServer, usPortServer);
  this->internal->TerminateGameConnection(unIPServer, usPortServer);
  
}


void  ISteamUser_::TrackAppUsageEvent(CGameID  gameID, int  eAppUsageEvent, char * pchExtraInfo)
{
  TRACE("((ISteamUser *)%p, (CGameID )%p, (int )%d, (char *)\"%s\")\n", this, gameID, eAppUsageEvent, pchExtraInfo);
  this->internal->TrackAppUsageEvent(gameID, eAppUsageEvent, pchExtraInfo);
  
}


bool  ISteamUser_::GetUserDataFolder(char * pchBuffer, int  cubBuffer)
{
  TRACE("((ISteamUser *)%p, (char *)\"%s\", (int )%d)\n", this, pchBuffer, cubBuffer);
  bool  result = this->internal->GetUserDataFolder(pchBuffer, cubBuffer);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  ISteamUser_::StartVoiceRecording()
{
  TRACE("((ISteamUser *)%p)\n", this);
  this->internal->StartVoiceRecording();
  
}


void  ISteamUser_::StopVoiceRecording()
{
  TRACE("((ISteamUser *)%p)\n", this);
  this->internal->StopVoiceRecording();
  
}


EVoiceResult  ISteamUser_::GetAvailableVoice(uint32 * pcbCompressed, uint32 * pcbUncompressed, uint32  nUncompressedVoiceDesiredSampleRate)
{
  TRACE("((ISteamUser *)%p, (uint32 *)%d, (uint32 *)%d, (uint32 )%d)\n", this, pcbCompressed, pcbUncompressed, nUncompressedVoiceDesiredSampleRate);
  EVoiceResult  result = this->internal->GetAvailableVoice(pcbCompressed, pcbUncompressed, nUncompressedVoiceDesiredSampleRate);
  TRACE("() = (EVoiceResult )%p\n", result);

  return result;
}


EVoiceResult  ISteamUser_::GetVoice(bool  bWantCompressed, void * pDestBuffer, uint32  cbDestBufferSize, uint32 * nBytesWritten, bool  bWantUncompressed, void * pUncompressedDestBuffer, uint32  cbUncompressedDestBufferSize, uint32 * nUncompressBytesWritten, uint32  nUncompressedVoiceDesiredSampleRate)
{
  TRACE("((ISteamUser *)%p, (bool )%d, (void *)%p, (uint32 )%d, (uint32 *)%d, (bool )%d, (void *)%p, (uint32 )%d, (uint32 *)%d, (uint32 )%d)\n", this, bWantCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, bWantUncompressed, pUncompressedDestBuffer, cbUncompressedDestBufferSize, nUncompressBytesWritten, nUncompressedVoiceDesiredSampleRate);
  EVoiceResult  result = this->internal->GetVoice(bWantCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, bWantUncompressed, pUncompressedDestBuffer, cbUncompressedDestBufferSize, nUncompressBytesWritten, nUncompressedVoiceDesiredSampleRate);
  TRACE("() = (EVoiceResult )%p\n", result);

  return result;
}


EVoiceResult  ISteamUser_::DecompressVoice(void * pCompressed, uint32  cbCompressed, void * pDestBuffer, uint32  cbDestBufferSize, uint32 * nBytesWritten, uint32  nDesiredSampleRate)
{
  TRACE("((ISteamUser *)%p, (void *)%p, (uint32 )%d, (void *)%p, (uint32 )%d, (uint32 *)%d, (uint32 )%d)\n", this, pCompressed, cbCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, nDesiredSampleRate);
  EVoiceResult  result = this->internal->DecompressVoice(pCompressed, cbCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, nDesiredSampleRate);
  TRACE("() = (EVoiceResult )%p\n", result);

  return result;
}


uint32  ISteamUser_::GetVoiceOptimalSampleRate()
{
  TRACE("((ISteamUser *)%p)\n", this);
  uint32  result = this->internal->GetVoiceOptimalSampleRate();
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


HAuthTicket  ISteamUser_::GetAuthSessionTicket(void * pTicket, int  cbMaxTicket, uint32 * pcbTicket)
{
  TRACE("((ISteamUser *)%p, (void *)%p, (int )%d, (uint32 *)%d)\n", this, pTicket, cbMaxTicket, pcbTicket);
  HAuthTicket  result = this->internal->GetAuthSessionTicket(pTicket, cbMaxTicket, pcbTicket);
  TRACE("() = (HAuthTicket )%p\n", result);

  return result;
}


EBeginAuthSessionResult  ISteamUser_::BeginAuthSession(void * pAuthTicket, int  cbAuthTicket, CSteamID  steamID)
{
  TRACE("((ISteamUser *)%p, (void *)%p, (int )%d, (CSteamID )%p)\n", this, pAuthTicket, cbAuthTicket, steamID);
  EBeginAuthSessionResult  result = this->internal->BeginAuthSession(pAuthTicket, cbAuthTicket, steamID);
  TRACE("() = (EBeginAuthSessionResult )%p\n", result);

  return result;
}


void  ISteamUser_::EndAuthSession(CSteamID  steamID)
{
  TRACE("((ISteamUser *)%p, (CSteamID )%p)\n", this, steamID);
  this->internal->EndAuthSession(steamID);
  
}


void  ISteamUser_::CancelAuthTicket(HAuthTicket  hAuthTicket)
{
  TRACE("((ISteamUser *)%p, (HAuthTicket )%p)\n", this, hAuthTicket);
  this->internal->CancelAuthTicket(hAuthTicket);
  
}


EUserHasLicenseForAppResult  ISteamUser_::UserHasLicenseForApp(CSteamID  steamID, AppId_t  appID)
{
  TRACE("((ISteamUser *)%p, (CSteamID )%p, (AppId_t )%p)\n", this, steamID, appID);
  EUserHasLicenseForAppResult  result = this->internal->UserHasLicenseForApp(steamID, appID);
  TRACE("() = (EUserHasLicenseForAppResult )%p\n", result);

  return result;
}


bool  ISteamUser_::BIsBehindNAT()
{
  TRACE("((ISteamUser *)%p)\n", this);
  bool  result = this->internal->BIsBehindNAT();
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  ISteamUser_::AdvertiseGame(CSteamID  steamIDGameServer, uint32  unIPServer, uint16  usPortServer)
{
  TRACE("((ISteamUser *)%p, (CSteamID )%p, (uint32 )%d, (uint16 )%d)\n", this, steamIDGameServer, unIPServer, usPortServer);
  this->internal->AdvertiseGame(steamIDGameServer, unIPServer, usPortServer);
  
}


SteamAPICall_t  ISteamUser_::RequestEncryptedAppTicket(void * pDataToInclude, int  cbDataToInclude)
{
  TRACE("((ISteamUser *)%p, (void *)%p, (int )%d)\n", this, pDataToInclude, cbDataToInclude);
  SteamAPICall_t  result = this->internal->RequestEncryptedAppTicket(pDataToInclude, cbDataToInclude);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  ISteamUser_::GetEncryptedAppTicket(void * pTicket, int  cbMaxTicket, uint32 * pcbTicket)
{
  TRACE("((ISteamUser *)%p, (void *)%p, (int )%d, (uint32 *)%d)\n", this, pTicket, cbMaxTicket, pcbTicket);
  bool  result = this->internal->GetEncryptedAppTicket(pTicket, cbMaxTicket, pcbTicket);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  ISteamUser_::GetGameBadgeLevel(int  nSeries, bool  bFoil)
{
  TRACE("((ISteamUser *)%p, (int )%d, (bool )%d)\n", this, nSeries, bFoil);
  int  result = this->internal->GetGameBadgeLevel(nSeries, bFoil);
  TRACE("() = (int )%d\n", result);

  return result;
}


int  ISteamUser_::GetPlayerSteamLevel()
{
  TRACE("((ISteamUser *)%p)\n", this);
  int  result = this->internal->GetPlayerSteamLevel();
  TRACE("() = (int )%d\n", result);

  return result;
}


SteamAPICall_t  ISteamUser_::RequestStoreAuthURL(char * pchRedirectURL)
{
  TRACE("((ISteamUser *)%p, (char *)\"%s\")\n", this, pchRedirectURL);
  SteamAPICall_t  result = this->internal->RequestStoreAuthURL(pchRedirectURL);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  ISteamUser_::BIsPhoneVerified()
{
  TRACE("((ISteamUser *)%p)\n", this);
  bool  result = this->internal->BIsPhoneVerified();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUser_::BIsTwoFactorEnabled()
{
  TRACE("((ISteamUser *)%p)\n", this);
  bool  result = this->internal->BIsTwoFactorEnabled();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUser_::BIsPhoneIdentifying()
{
  TRACE("((ISteamUser *)%p)\n", this);
  bool  result = this->internal->BIsPhoneIdentifying();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUser_::BIsPhoneRequiringVerification()
{
  TRACE("((ISteamUser *)%p)\n", this);
  bool  result = this->internal->BIsPhoneRequiringVerification();
  TRACE("() = (bool )%d\n", result);

  return result;
}
ISteamUser_::ISteamUser_(ISteamUser * towrap)
{
  this->internal = towrap;
}

ISteamUser_::~ISteamUser_()
{
  delete this->internal;
}
