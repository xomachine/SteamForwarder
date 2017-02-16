#ifndef WRAP_ISTEAMAPPS_H
#define WRAP_ISTEAMAPPS_H
#include "steam_api.h"
class ISteamApps_ 
{
  virtual bool BIsSubscribed() __attribute__((thiscall));
  virtual bool BIsLowViolence() __attribute__((thiscall));
  virtual bool BIsCybercafe() __attribute__((thiscall));
  virtual bool BIsVACBanned() __attribute__((thiscall));
  virtual const char * GetCurrentGameLanguage() __attribute__((thiscall));
  virtual const char * GetAvailableGameLanguages() __attribute__((thiscall));
  virtual bool BIsSubscribedApp( AppId_t appID ) __attribute__((thiscall));
  virtual bool BIsDlcInstalled( AppId_t appID ) __attribute__((thiscall));
  virtual uint32 GetEarliestPurchaseUnixTime( AppId_t nAppID ) __attribute__((thiscall));
  virtual bool BIsSubscribedFromFreeWeekend() __attribute__((thiscall));
  virtual int GetDLCCount() __attribute__((thiscall));
  virtual bool BGetDLCDataByIndex( int iDLC, AppId_t *pAppID, bool *pbAvailable, char *pchName, int cchNameBufferSize ) __attribute__((thiscall));
  virtual void InstallDLC( AppId_t nAppID ) __attribute__((thiscall));
  virtual void UninstallDLC( AppId_t nAppID ) __attribute__((thiscall));
  virtual void RequestAppProofOfPurchaseKey( AppId_t nAppID ) __attribute__((thiscall));
  virtual bool GetCurrentBetaName( char *pchName, int cchNameBufferSize ) __attribute__((thiscall));
  virtual bool MarkContentCorrupt( bool bMissingFilesOnly ) __attribute__((thiscall));
  virtual uint32 GetInstalledDepots( AppId_t appID, DepotId_t *pvecDepots, uint32 cMaxDepots ) __attribute__((thiscall));
  virtual uint32 GetAppInstallDir( AppId_t appID, char *pchFolder, uint32 cchFolderBufferSize ) __attribute__((thiscall));
  virtual bool BIsAppInstalled( AppId_t appID ) __attribute__((thiscall));
  virtual CSteamID* GetAppOwner(CSteamID* hidden) __attribute__((thiscall));
  virtual const char * GetLaunchQueryParam( const char *pchKey ) __attribute__((thiscall));
  virtual bool GetDlcDownloadProgress( AppId_t nAppID, uint64 *punBytesDownloaded, uint64 *punBytesTotal ) __attribute__((thiscall));
  virtual int GetAppBuildId() __attribute__((thiscall));
  virtual void RequestAllProofOfPurchaseKeys() __attribute__((thiscall));
  virtual SteamAPICall_t GetFileDetails( const char* pszFileName ) __attribute__((thiscall));
  public:
    ISteamApps *internal;
};
#endif
