#include <steam_api_.h>
#include <isteamapplist.h>
class ISteamAppList_
{
public:
  virtual uint32  GetNumInstalledApps() __attribute__((thiscall));
  virtual uint32  GetInstalledApps(AppId_t * pvecAppID, uint32  unMaxAppIDs) __attribute__((thiscall));
  virtual int  GetAppName(AppId_t  nAppID, char * pchName, int  cchNameMax) __attribute__((thiscall));
  virtual int  GetAppInstallDir(AppId_t  nAppID, char * pchDirectory, int  cchNameMax) __attribute__((thiscall));
  virtual int  GetAppBuildId(AppId_t  nAppID) __attribute__((thiscall));
  ISteamAppList_(ISteamAppList*to_wrap);
  ~ISteamAppList_();
private:
  ISteamAppList * internal;
};
