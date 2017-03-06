#include <steam_api_.h>

ScreenshotHandle  ISteamScreenshots_::WriteScreenshot(void * pubRGB, uint32  cubRGB, int  nWidth, int  nHeight)
{
  TRACE("((ISteamScreenshots *)%p, (void *)%p, (uint32 )%d, (int )%d, (int )%d)\n", this, pubRGB, cubRGB, nWidth, nHeight);
  auto result = this->internal->WriteScreenshot(pubRGB, cubRGB, nWidth, nHeight);
  TRACE("() = (ScreenshotHandle )%p\n", result);

  return result;
}


ScreenshotHandle  ISteamScreenshots_::AddScreenshotToLibrary(char * pchFilename, char * pchThumbnailFilename, int  nWidth, int  nHeight)
{
  TRACE("((ISteamScreenshots *)%p, (char *)\"%s\", (char *)\"%s\", (int )%d, (int )%d)\n", this, pchFilename, pchThumbnailFilename, nWidth, nHeight);
  auto result = this->internal->AddScreenshotToLibrary(pchFilename, pchThumbnailFilename, nWidth, nHeight);
  TRACE("() = (ScreenshotHandle )%p\n", result);

  return result;
}


void  ISteamScreenshots_::TriggerScreenshot()
{
  TRACE("((ISteamScreenshots *)%p)\n", this);
  this->internal->TriggerScreenshot();
  
}


void  ISteamScreenshots_::HookScreenshots(bool  bHook)
{
  TRACE("((ISteamScreenshots *)%p, (bool )%d)\n", this, bHook);
  this->internal->HookScreenshots(bHook);
  
}


bool  ISteamScreenshots_::SetLocation(ScreenshotHandle  hScreenshot, char * pchLocation)
{
  TRACE("((ISteamScreenshots *)%p, (ScreenshotHandle )%p, (char *)\"%s\")\n", this, hScreenshot, pchLocation);
  auto result = this->internal->SetLocation(hScreenshot, pchLocation);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamScreenshots_::TagUser(ScreenshotHandle  hScreenshot, CSteamID  steamID)
{
  TRACE("((ISteamScreenshots *)%p, (ScreenshotHandle )%p, (CSteamID )%p)\n", this, hScreenshot, steamID);
  auto result = this->internal->TagUser(hScreenshot, steamID);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamScreenshots_::TagPublishedFile(ScreenshotHandle  hScreenshot, PublishedFileId_t  unPublishedFileID)
{
  TRACE("((ISteamScreenshots *)%p, (ScreenshotHandle )%p, (PublishedFileId_t )%p)\n", this, hScreenshot, unPublishedFileID);
  auto result = this->internal->TagPublishedFile(hScreenshot, unPublishedFileID);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamScreenshots_::IsScreenshotsHooked()
{
  TRACE("((ISteamScreenshots *)%p)\n", this);
  auto result = this->internal->IsScreenshotsHooked();
  TRACE("() = (bool )%d\n", result);

  return result;
}


ScreenshotHandle  ISteamScreenshots_::AddVRScreenshotToLibrary(EVRScreenshotType  eType, char * pchFilename, char * pchVRFilename)
{
  TRACE("((ISteamScreenshots *)%p, (EVRScreenshotType )%p, (char *)\"%s\", (char *)\"%s\")\n", this, eType, pchFilename, pchVRFilename);
  auto result = this->internal->AddVRScreenshotToLibrary(eType, pchFilename, pchVRFilename);
  TRACE("() = (ScreenshotHandle )%p\n", result);

  return result;
}
ISteamScreenshots_::ISteamScreenshots_(ISteamScreenshots * towrap)
{
  this->internal = towrap;
}

ISteamScreenshots_::~ISteamScreenshots_()
{
  delete this->internal;
}
