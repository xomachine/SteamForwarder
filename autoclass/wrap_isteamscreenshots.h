#ifndef WRAP_ISTEAMSCREENSHOTS_H
#define WRAP_ISTEAMSCREENSHOTS_H
#include "steam_api.h"
class ISteamScreenshots_ 
{
  virtual ScreenshotHandle WriteScreenshot( void *pubRGB, uint32 cubRGB, int nWidth, int nHeight ) __attribute__((thiscall));
  virtual ScreenshotHandle AddScreenshotToLibrary( const char *pchFilename, const char *pchThumbnailFilename, int nWidth, int nHeight ) __attribute__((thiscall));
  virtual void TriggerScreenshot() __attribute__((thiscall));
  virtual void HookScreenshots( bool bHook ) __attribute__((thiscall));
  virtual bool SetLocation( ScreenshotHandle hScreenshot, const char *pchLocation ) __attribute__((thiscall));
  virtual bool TagUser( ScreenshotHandle hScreenshot, CSteamID steamID ) __attribute__((thiscall));
  virtual bool TagPublishedFile( ScreenshotHandle hScreenshot, PublishedFileId_t unPublishedFileID ) __attribute__((thiscall));
  virtual bool IsScreenshotsHooked() __attribute__((thiscall));
  virtual ScreenshotHandle AddVRScreenshotToLibrary( EVRScreenshotType eType, const char *pchFilename, const char *pchVRFilename ) __attribute__((thiscall));
  public:
    ISteamScreenshots *internal;
};
#endif
