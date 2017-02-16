#ifndef WRAP_ISTEAMSCREENSHOTS_CPP
#define WRAP_ISTEAMSCREENSHOTS_CPP
#include "autoclass/steam_api_.h" 
#include "windef.h"
#include "wine/debug.h"
#include "config.h"
ScreenshotHandle ISteamScreenshots_::WriteScreenshot( void *pubRGB, uint32 cubRGB, int nWidth, int nHeight )
{
  TRACE("((this[ISteamScreenshots])%p, (void *)%p, (uint32)%d, (int)%d, (int)%d)\n", this, pubRGB, cubRGB, nWidth, nHeight);
  ScreenshotHandle result = this->internal->WriteScreenshot(pubRGB, cubRGB, nWidth, nHeight);
  TRACE(" = (ScreenshotHandle)%p\n", result);
  return result;
}
ScreenshotHandle ISteamScreenshots_::AddScreenshotToLibrary( const char *pchFilename, const char *pchThumbnailFilename, int nWidth, int nHeight )
{
  TRACE("((this[ISteamScreenshots])%p, (const char *)\"%s\", (const char *)\"%s\", (int)%d, (int)%d)\n", this, pchFilename, pchThumbnailFilename, nWidth, nHeight);
  ScreenshotHandle result = this->internal->AddScreenshotToLibrary(pchFilename, pchThumbnailFilename, nWidth, nHeight);
  TRACE(" = (ScreenshotHandle)%p\n", result);
  return result;
}
void ISteamScreenshots_::TriggerScreenshot()
{
  TRACE("((this[ISteamScreenshots])%p)\n", this);
  this->internal->TriggerScreenshot();
}
void ISteamScreenshots_::HookScreenshots( bool bHook )
{
  TRACE("((this[ISteamScreenshots])%p, (bool)%d)\n", this, bHook);
  this->internal->HookScreenshots(bHook);
}
bool ISteamScreenshots_::SetLocation( ScreenshotHandle hScreenshot, const char *pchLocation )
{
  TRACE("((this[ISteamScreenshots])%p, (ScreenshotHandle)%p, (const char *)\"%s\")\n", this, hScreenshot, pchLocation);
  bool result = this->internal->SetLocation(hScreenshot, pchLocation);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamScreenshots_::TagUser( ScreenshotHandle hScreenshot, CSteamID steamID )
{
  TRACE("((this[ISteamScreenshots])%p, (ScreenshotHandle)%p, (CSteamID)%p)\n", this, hScreenshot, steamID);
  bool result = this->internal->TagUser(hScreenshot, steamID);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamScreenshots_::TagPublishedFile( ScreenshotHandle hScreenshot, PublishedFileId_t unPublishedFileID )
{
  TRACE("((this[ISteamScreenshots])%p, (ScreenshotHandle)%p, (PublishedFileId_t)%p)\n", this, hScreenshot, unPublishedFileID);
  bool result = this->internal->TagPublishedFile(hScreenshot, unPublishedFileID);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamScreenshots_::IsScreenshotsHooked()
{
  TRACE("((this[ISteamScreenshots])%p)\n", this);
  bool result = this->internal->IsScreenshotsHooked();
  TRACE(" = (bool)%d\n", result);
  return result;
}
ScreenshotHandle ISteamScreenshots_::AddVRScreenshotToLibrary( EVRScreenshotType eType, const char *pchFilename, const char *pchVRFilename )
{
  TRACE("((this[ISteamScreenshots])%p, (EVRScreenshotType)%p, (const char *)\"%s\", (const char *)\"%s\")\n", this, eType, pchFilename, pchVRFilename);
  ScreenshotHandle result = this->internal->AddVRScreenshotToLibrary(eType, pchFilename, pchVRFilename);
  TRACE(" = (ScreenshotHandle)%p\n", result);
  return result;
}
#endif
