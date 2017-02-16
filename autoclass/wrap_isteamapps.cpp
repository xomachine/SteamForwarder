#ifndef WRAP_ISTEAMAPPS_CPP
#define WRAP_ISTEAMAPPS_CPP
#include "autoclass/steam_api_.h" 
#include "windef.h"
#include "wine/debug.h"
#include "config.h"
bool ISteamApps_::BIsSubscribed()
{
  TRACE("((this[ISteamApps])%p)\n", this);
  bool result = this->internal->BIsSubscribed();
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamApps_::BIsLowViolence()
{
  TRACE("((this[ISteamApps])%p)\n", this);
  bool result = this->internal->BIsLowViolence();
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamApps_::BIsCybercafe()
{
  TRACE("((this[ISteamApps])%p)\n", this);
  bool result = this->internal->BIsCybercafe();
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamApps_::BIsVACBanned()
{
  TRACE("((this[ISteamApps])%p)\n", this);
  bool result = this->internal->BIsVACBanned();
  TRACE(" = (bool)%d\n", result);
  return result;
}
const char * ISteamApps_::GetCurrentGameLanguage()
{
  TRACE("((this[ISteamApps])%p)\n", this);
  const char * result = this->internal->GetCurrentGameLanguage();
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
const char * ISteamApps_::GetAvailableGameLanguages()
{
  TRACE("((this[ISteamApps])%p)\n", this);
  const char * result = this->internal->GetAvailableGameLanguages();
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
bool ISteamApps_::BIsSubscribedApp( AppId_t appID )
{
  TRACE("((this[ISteamApps])%p, (AppId_t)%p)\n", this, appID);
  bool result = this->internal->BIsSubscribedApp(appID);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamApps_::BIsDlcInstalled( AppId_t appID )
{
  TRACE("((this[ISteamApps])%p, (AppId_t)%p)\n", this, appID);
  bool result = this->internal->BIsDlcInstalled(appID);
  TRACE(" = (bool)%d\n", result);
  return result;
}
uint32 ISteamApps_::GetEarliestPurchaseUnixTime( AppId_t nAppID )
{
  TRACE("((this[ISteamApps])%p, (AppId_t)%p)\n", this, nAppID);
  uint32 result = this->internal->GetEarliestPurchaseUnixTime(nAppID);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
bool ISteamApps_::BIsSubscribedFromFreeWeekend()
{
  TRACE("((this[ISteamApps])%p)\n", this);
  bool result = this->internal->BIsSubscribedFromFreeWeekend();
  TRACE(" = (bool)%d\n", result);
  return result;
}
int ISteamApps_::GetDLCCount()
{
  TRACE("((this[ISteamApps])%p)\n", this);
  int result = this->internal->GetDLCCount();
  TRACE(" = (int)%d\n", result);
  return result;
}
bool ISteamApps_::BGetDLCDataByIndex( int iDLC, AppId_t *pAppID, bool *pbAvailable, char *pchName, int cchNameBufferSize )
{
  TRACE("((this[ISteamApps])%p, (int)%d, (AppId_t *)%p, (bool *)%p, (char *)%p, (int)%d)\n", this, iDLC, pAppID, pbAvailable, pchName, cchNameBufferSize);
  bool result = this->internal->BGetDLCDataByIndex(iDLC, pAppID, pbAvailable, pchName, cchNameBufferSize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void ISteamApps_::InstallDLC( AppId_t nAppID )
{
  TRACE("((this[ISteamApps])%p, (AppId_t)%p)\n", this, nAppID);
  this->internal->InstallDLC(nAppID);
}
void ISteamApps_::UninstallDLC( AppId_t nAppID )
{
  TRACE("((this[ISteamApps])%p, (AppId_t)%p)\n", this, nAppID);
  this->internal->UninstallDLC(nAppID);
}
void ISteamApps_::RequestAppProofOfPurchaseKey( AppId_t nAppID )
{
  TRACE("((this[ISteamApps])%p, (AppId_t)%p)\n", this, nAppID);
  this->internal->RequestAppProofOfPurchaseKey(nAppID);
}
bool ISteamApps_::GetCurrentBetaName( char *pchName, int cchNameBufferSize )
{
  TRACE("((this[ISteamApps])%p, (char *)%p, (int)%d)\n", this, pchName, cchNameBufferSize);
  bool result = this->internal->GetCurrentBetaName(pchName, cchNameBufferSize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamApps_::MarkContentCorrupt( bool bMissingFilesOnly )
{
  TRACE("((this[ISteamApps])%p, (bool)%d)\n", this, bMissingFilesOnly);
  bool result = this->internal->MarkContentCorrupt(bMissingFilesOnly);
  TRACE(" = (bool)%d\n", result);
  return result;
}
uint32 ISteamApps_::GetInstalledDepots( AppId_t appID, DepotId_t *pvecDepots, uint32 cMaxDepots )
{
  TRACE("((this[ISteamApps])%p, (AppId_t)%p, (DepotId_t *)%p, (uint32)%d)\n", this, appID, pvecDepots, cMaxDepots);
  uint32 result = this->internal->GetInstalledDepots(appID, pvecDepots, cMaxDepots);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
uint32 ISteamApps_::GetAppInstallDir( AppId_t appID, char *pchFolder, uint32 cchFolderBufferSize )
{
  TRACE("((this[ISteamApps])%p, (AppId_t)%p, (char *)%p, (uint32)%d)\n", this, appID, pchFolder, cchFolderBufferSize);
  uint32 result = this->internal->GetAppInstallDir(appID, pchFolder, cchFolderBufferSize);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
bool ISteamApps_::BIsAppInstalled( AppId_t appID )
{
  TRACE("((this[ISteamApps])%p, (AppId_t)%p)\n", this, appID);
  bool result = this->internal->BIsAppInstalled(appID);
  TRACE(" = (bool)%d\n", result);
  return result;
}
CSteamID* ISteamApps_::GetAppOwner(CSteamID* hidden)
{
  TRACE("((this[ISteamApps])%p, (CSteamID*)%p)\n", this, hidden);
  *hidden = this->internal->GetAppOwner();
  return hidden;
}
const char * ISteamApps_::GetLaunchQueryParam( const char *pchKey )
{
  TRACE("((this[ISteamApps])%p, (const char *)\"%s\")\n", this, pchKey);
  const char * result = this->internal->GetLaunchQueryParam(pchKey);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
bool ISteamApps_::GetDlcDownloadProgress( AppId_t nAppID, uint64 *punBytesDownloaded, uint64 *punBytesTotal )
{
  TRACE("((this[ISteamApps])%p, (AppId_t)%p, (uint64 *)%p, (uint64 *)%p)\n", this, nAppID, punBytesDownloaded, punBytesTotal);
  bool result = this->internal->GetDlcDownloadProgress(nAppID, punBytesDownloaded, punBytesTotal);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int ISteamApps_::GetAppBuildId()
{
  TRACE("((this[ISteamApps])%p)\n", this);
  int result = this->internal->GetAppBuildId();
  TRACE(" = (int)%d\n", result);
  return result;
}
void ISteamApps_::RequestAllProofOfPurchaseKeys()
{
  TRACE("((this[ISteamApps])%p)\n", this);
  this->internal->RequestAllProofOfPurchaseKeys();
}
SteamAPICall_t ISteamApps_::GetFileDetails( const char* pszFileName )
{
  TRACE("((this[ISteamApps])%p, (const char*)\"%s\")\n", this, pszFileName);
  SteamAPICall_t result = this->internal->GetFileDetails(pszFileName);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
#endif
