#include <steam_api_.h>

bool  ISteamApps_::BIsSubscribed()
{
  TRACE("((ISteamApps *)%p)\n", this);
  bool  result = this->internal->BIsSubscribed();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamApps_::BIsLowViolence()
{
  TRACE("((ISteamApps *)%p)\n", this);
  bool  result = this->internal->BIsLowViolence();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamApps_::BIsCybercafe()
{
  TRACE("((ISteamApps *)%p)\n", this);
  bool  result = this->internal->BIsCybercafe();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamApps_::BIsVACBanned()
{
  TRACE("((ISteamApps *)%p)\n", this);
  bool  result = this->internal->BIsVACBanned();
  TRACE("() = (bool )%d\n", result);

  return result;
}


char * ISteamApps_::GetCurrentGameLanguage()
{
  TRACE("((ISteamApps *)%p)\n", this);
  char * result = this->internal->GetCurrentGameLanguage();
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


char * ISteamApps_::GetAvailableGameLanguages()
{
  TRACE("((ISteamApps *)%p)\n", this);
  char * result = this->internal->GetAvailableGameLanguages();
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


bool  ISteamApps_::BIsSubscribedApp(AppId_t  appID)
{
  TRACE("((ISteamApps *)%p, (AppId_t )%p)\n", this, appID);
  bool  result = this->internal->BIsSubscribedApp(appID);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamApps_::BIsDlcInstalled(AppId_t  appID)
{
  TRACE("((ISteamApps *)%p, (AppId_t )%p)\n", this, appID);
  bool  result = this->internal->BIsDlcInstalled(appID);
  TRACE("() = (bool )%d\n", result);

  return result;
}


uint32  ISteamApps_::GetEarliestPurchaseUnixTime(AppId_t  nAppID)
{
  TRACE("((ISteamApps *)%p, (AppId_t )%p)\n", this, nAppID);
  uint32  result = this->internal->GetEarliestPurchaseUnixTime(nAppID);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


bool  ISteamApps_::BIsSubscribedFromFreeWeekend()
{
  TRACE("((ISteamApps *)%p)\n", this);
  bool  result = this->internal->BIsSubscribedFromFreeWeekend();
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  ISteamApps_::GetDLCCount()
{
  TRACE("((ISteamApps *)%p)\n", this);
  int  result = this->internal->GetDLCCount();
  TRACE("() = (int )%d\n", result);

  return result;
}


bool  ISteamApps_::BGetDLCDataByIndex(int  iDLC, AppId_t * pAppID, bool * pbAvailable, char * pchName, int  cchNameBufferSize)
{
  TRACE("((ISteamApps *)%p, (int )%d, (AppId_t *)%p, (bool *)%d, (char *)\"%s\", (int )%d)\n", this, iDLC, pAppID, pbAvailable, pchName, cchNameBufferSize);
  bool  result = this->internal->BGetDLCDataByIndex(iDLC, pAppID, pbAvailable, pchName, cchNameBufferSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  ISteamApps_::InstallDLC(AppId_t  nAppID)
{
  TRACE("((ISteamApps *)%p, (AppId_t )%p)\n", this, nAppID);
  this->internal->InstallDLC(nAppID);
  
}


void  ISteamApps_::UninstallDLC(AppId_t  nAppID)
{
  TRACE("((ISteamApps *)%p, (AppId_t )%p)\n", this, nAppID);
  this->internal->UninstallDLC(nAppID);
  
}


void  ISteamApps_::RequestAppProofOfPurchaseKey(AppId_t  nAppID)
{
  TRACE("((ISteamApps *)%p, (AppId_t )%p)\n", this, nAppID);
  this->internal->RequestAppProofOfPurchaseKey(nAppID);
  
}


bool  ISteamApps_::GetCurrentBetaName(char * pchName, int  cchNameBufferSize)
{
  TRACE("((ISteamApps *)%p, (char *)\"%s\", (int )%d)\n", this, pchName, cchNameBufferSize);
  bool  result = this->internal->GetCurrentBetaName(pchName, cchNameBufferSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamApps_::MarkContentCorrupt(bool  bMissingFilesOnly)
{
  TRACE("((ISteamApps *)%p, (bool )%d)\n", this, bMissingFilesOnly);
  bool  result = this->internal->MarkContentCorrupt(bMissingFilesOnly);
  TRACE("() = (bool )%d\n", result);

  return result;
}


uint32  ISteamApps_::GetInstalledDepots(AppId_t  appID, DepotId_t * pvecDepots, uint32  cMaxDepots)
{
  TRACE("((ISteamApps *)%p, (AppId_t )%p, (DepotId_t *)%p, (uint32 )%d)\n", this, appID, pvecDepots, cMaxDepots);
  uint32  result = this->internal->GetInstalledDepots(appID, pvecDepots, cMaxDepots);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


uint32  ISteamApps_::GetAppInstallDir(AppId_t  appID, char * pchFolder, uint32  cchFolderBufferSize)
{
  TRACE("((ISteamApps *)%p, (AppId_t )%p, (char *)\"%s\", (uint32 )%d)\n", this, appID, pchFolder, cchFolderBufferSize);
  uint32  result = this->internal->GetAppInstallDir(appID, pchFolder, cchFolderBufferSize);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


bool  ISteamApps_::BIsAppInstalled(AppId_t  appID)
{
  TRACE("((ISteamApps *)%p, (AppId_t )%p)\n", this, appID);
  bool  result = this->internal->BIsAppInstalled(appID);
  TRACE("() = (bool )%d\n", result);

  return result;
}


CSteamID * ISteamApps_::GetAppOwner(CSteamID * hidden)
{
  TRACE("((ISteamApps *)%p)\n", this);
  *hidden = this->internal->GetAppOwner();
  return hidden;
}


char * ISteamApps_::GetLaunchQueryParam(char * pchKey)
{
  TRACE("((ISteamApps *)%p, (char *)\"%s\")\n", this, pchKey);
  char * result = this->internal->GetLaunchQueryParam(pchKey);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


bool  ISteamApps_::GetDlcDownloadProgress(AppId_t  nAppID, uint64 * punBytesDownloaded, uint64 * punBytesTotal)
{
  TRACE("((ISteamApps *)%p, (AppId_t )%p, (uint64 *)%d, (uint64 *)%d)\n", this, nAppID, punBytesDownloaded, punBytesTotal);
  bool  result = this->internal->GetDlcDownloadProgress(nAppID, punBytesDownloaded, punBytesTotal);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  ISteamApps_::GetAppBuildId()
{
  TRACE("((ISteamApps *)%p)\n", this);
  int  result = this->internal->GetAppBuildId();
  TRACE("() = (int )%d\n", result);

  return result;
}


void  ISteamApps_::RequestAllProofOfPurchaseKeys()
{
  TRACE("((ISteamApps *)%p)\n", this);
  this->internal->RequestAllProofOfPurchaseKeys();
  
}


SteamAPICall_t  ISteamApps_::GetFileDetails(char * pszFileName)
{
  TRACE("((ISteamApps *)%p, (char *)\"%s\")\n", this, pszFileName);
  SteamAPICall_t  result = this->internal->GetFileDetails(pszFileName);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}
ISteamApps_::ISteamApps_(ISteamApps * towrap)
{
  this->internal = towrap;
}

ISteamApps_::~ISteamApps_()
{
  delete this->internal;
}
