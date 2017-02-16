#ifndef WRAP_ISTEAMAPPLIST_CPP
#define WRAP_ISTEAMAPPLIST_CPP
#include "autoclass/steam_api_.h" 
#include "windef.h"
#include "wine/debug.h"
#include "config.h"
uint32 ISteamAppList_::GetNumInstalledApps()
{
  TRACE("((this[ISteamAppList])%p)\n", this);
  uint32 result = this->internal->GetNumInstalledApps();
  TRACE(" = (uint32)%d\n", result);
  return result;
}
uint32 ISteamAppList_::GetInstalledApps( AppId_t *pvecAppID, uint32 unMaxAppIDs )
{
  TRACE("((this[ISteamAppList])%p, (AppId_t *)%p, (uint32)%d)\n", this, pvecAppID, unMaxAppIDs);
  uint32 result = this->internal->GetInstalledApps(pvecAppID, unMaxAppIDs);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
int ISteamAppList_::GetAppName( AppId_t nAppID, OUT_STRING() char *pchName, int cchNameMax )
{
  TRACE("((this[ISteamAppList])%p, (AppId_t)%p, (char *)%p, (int)%d)\n", this, nAppID, pchName, cchNameMax);
  int result = this->internal->GetAppName(nAppID, pchName, cchNameMax);
  TRACE(" = (int)%d\n", result);
  return result;
}
int ISteamAppList_::GetAppInstallDir( AppId_t nAppID, char *pchDirectory, int cchNameMax )
{
  TRACE("((this[ISteamAppList])%p, (AppId_t)%p, (char *)%p, (int)%d)\n", this, nAppID, pchDirectory, cchNameMax);
  int result = this->internal->GetAppInstallDir(nAppID, pchDirectory, cchNameMax);
  TRACE(" = (int)%d\n", result);
  return result;
}
int ISteamAppList_::GetAppBuildId( AppId_t nAppID )
{
  TRACE("((this[ISteamAppList])%p, (AppId_t)%p)\n", this, nAppID);
  int result = this->internal->GetAppBuildId(nAppID);
  TRACE(" = (int)%d\n", result);
  return result;
}
#endif
