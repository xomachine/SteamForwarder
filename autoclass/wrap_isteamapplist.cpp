#include <steam_api_.h>

uint32  ISteamAppList_::GetNumInstalledApps()
{
  TRACE("((ISteamAppList *)%p)\n", this);
  uint32  result = this->internal->GetNumInstalledApps();
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


uint32  ISteamAppList_::GetInstalledApps(AppId_t * pvecAppID, uint32  unMaxAppIDs)
{
  TRACE("((ISteamAppList *)%p, (AppId_t *)%p, (uint32 )%d)\n", this, pvecAppID, unMaxAppIDs);
  uint32  result = this->internal->GetInstalledApps(pvecAppID, unMaxAppIDs);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


int  ISteamAppList_::GetAppName(AppId_t  nAppID, char * pchName, int  cchNameMax)
{
  TRACE("((ISteamAppList *)%p, (AppId_t )%p, (char *)\"%s\", (int )%d)\n", this, nAppID, pchName, cchNameMax);
  int  result = this->internal->GetAppName(nAppID, pchName, cchNameMax);
  TRACE("() = (int )%d\n", result);

  return result;
}


int  ISteamAppList_::GetAppInstallDir(AppId_t  nAppID, char * pchDirectory, int  cchNameMax)
{
  TRACE("((ISteamAppList *)%p, (AppId_t )%p, (char *)\"%s\", (int )%d)\n", this, nAppID, pchDirectory, cchNameMax);
  int  result = this->internal->GetAppInstallDir(nAppID, pchDirectory, cchNameMax);
  TRACE("() = (int )%d\n", result);

  return result;
}


int  ISteamAppList_::GetAppBuildId(AppId_t  nAppID)
{
  TRACE("((ISteamAppList *)%p, (AppId_t )%p)\n", this, nAppID);
  int  result = this->internal->GetAppBuildId(nAppID);
  TRACE("() = (int )%d\n", result);

  return result;
}
ISteamAppList_::ISteamAppList_(ISteamAppList * towrap)
{
  this->internal = towrap;
}

ISteamAppList_::~ISteamAppList_()
{
  delete this->internal;
}
