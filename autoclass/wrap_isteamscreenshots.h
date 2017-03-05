#include <steam_api_.h>
#include <isteamscreenshots.h>
class ISteamScreenshots_
{
public:
  virtual ScreenshotHandle  WriteScreenshot(void * pubRGB, uint32  cubRGB, int  nWidth, int  nHeight) __attribute__((thiscall));
  virtual ScreenshotHandle  AddScreenshotToLibrary(char * pchFilename, char * pchThumbnailFilename, int  nWidth, int  nHeight) __attribute__((thiscall));
  virtual void  TriggerScreenshot() __attribute__((thiscall));
  virtual void  HookScreenshots(bool  bHook) __attribute__((thiscall));
  virtual bool  SetLocation(ScreenshotHandle  hScreenshot, char * pchLocation) __attribute__((thiscall));
  virtual bool  TagUser(ScreenshotHandle  hScreenshot, CSteamID  steamID) __attribute__((thiscall));
  virtual bool  TagPublishedFile(ScreenshotHandle  hScreenshot, PublishedFileId_t  unPublishedFileID) __attribute__((thiscall));
  virtual bool  IsScreenshotsHooked() __attribute__((thiscall));
  virtual ScreenshotHandle  AddVRScreenshotToLibrary(EVRScreenshotType  eType, char * pchFilename, char * pchVRFilename) __attribute__((thiscall));
  ISteamScreenshots_(ISteamScreenshots*to_wrap);
  ~ISteamScreenshots_();
private:
  ISteamScreenshots * internal;
};
