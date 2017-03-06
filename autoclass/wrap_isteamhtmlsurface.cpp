#include <steam_api_.h>

bool  ISteamHTMLSurface_::Init()
{
  TRACE("((ISteamHTMLSurface *)%p)\n", this);
  auto result = this->internal->Init();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamHTMLSurface_::Shutdown()
{
  TRACE("((ISteamHTMLSurface *)%p)\n", this);
  auto result = this->internal->Shutdown();
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  ISteamHTMLSurface_::CreateBrowser(char * pchUserAgent, char * pchUserCSS)
{
  TRACE("((ISteamHTMLSurface *)%p, (char *)\"%s\", (char *)\"%s\")\n", this, pchUserAgent, pchUserCSS);
  auto result = this->internal->CreateBrowser(pchUserAgent, pchUserCSS);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


void  ISteamHTMLSurface_::RemoveBrowser(HHTMLBrowser  unBrowserHandle)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p)\n", this, unBrowserHandle);
  this->internal->RemoveBrowser(unBrowserHandle);
  
}


void  ISteamHTMLSurface_::LoadURL(HHTMLBrowser  unBrowserHandle, char * pchURL, char * pchPostData)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p, (char *)\"%s\", (char *)\"%s\")\n", this, unBrowserHandle, pchURL, pchPostData);
  this->internal->LoadURL(unBrowserHandle, pchURL, pchPostData);
  
}


void  ISteamHTMLSurface_::SetSize(HHTMLBrowser  unBrowserHandle, uint32  unWidth, uint32  unHeight)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p, (uint32 )%d, (uint32 )%d)\n", this, unBrowserHandle, unWidth, unHeight);
  this->internal->SetSize(unBrowserHandle, unWidth, unHeight);
  
}


void  ISteamHTMLSurface_::StopLoad(HHTMLBrowser  unBrowserHandle)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p)\n", this, unBrowserHandle);
  this->internal->StopLoad(unBrowserHandle);
  
}


void  ISteamHTMLSurface_::Reload(HHTMLBrowser  unBrowserHandle)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p)\n", this, unBrowserHandle);
  this->internal->Reload(unBrowserHandle);
  
}


void  ISteamHTMLSurface_::GoBack(HHTMLBrowser  unBrowserHandle)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p)\n", this, unBrowserHandle);
  this->internal->GoBack(unBrowserHandle);
  
}


void  ISteamHTMLSurface_::GoForward(HHTMLBrowser  unBrowserHandle)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p)\n", this, unBrowserHandle);
  this->internal->GoForward(unBrowserHandle);
  
}


void  ISteamHTMLSurface_::AddHeader(HHTMLBrowser  unBrowserHandle, char * pchKey, char * pchValue)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p, (char *)\"%s\", (char *)\"%s\")\n", this, unBrowserHandle, pchKey, pchValue);
  this->internal->AddHeader(unBrowserHandle, pchKey, pchValue);
  
}


void  ISteamHTMLSurface_::ExecuteJavascript(HHTMLBrowser  unBrowserHandle, char * pchScript)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p, (char *)\"%s\")\n", this, unBrowserHandle, pchScript);
  this->internal->ExecuteJavascript(unBrowserHandle, pchScript);
  
}


void  ISteamHTMLSurface_::MouseUp(HHTMLBrowser  unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton  eMouseButton)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p, (ISteamHTMLSurface::EHTMLMouseButton )%p)\n", this, unBrowserHandle, eMouseButton);
  this->internal->MouseUp(unBrowserHandle, eMouseButton);
  
}


void  ISteamHTMLSurface_::MouseDown(HHTMLBrowser  unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton  eMouseButton)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p, (ISteamHTMLSurface::EHTMLMouseButton )%p)\n", this, unBrowserHandle, eMouseButton);
  this->internal->MouseDown(unBrowserHandle, eMouseButton);
  
}


void  ISteamHTMLSurface_::MouseDoubleClick(HHTMLBrowser  unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton  eMouseButton)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p, (ISteamHTMLSurface::EHTMLMouseButton )%p)\n", this, unBrowserHandle, eMouseButton);
  this->internal->MouseDoubleClick(unBrowserHandle, eMouseButton);
  
}


void  ISteamHTMLSurface_::MouseMove(HHTMLBrowser  unBrowserHandle, int  x, int  y)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p, (int )%d, (int )%d)\n", this, unBrowserHandle, x, y);
  this->internal->MouseMove(unBrowserHandle, x, y);
  
}


void  ISteamHTMLSurface_::MouseWheel(HHTMLBrowser  unBrowserHandle, int32  nDelta)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p, (int32 )%d)\n", this, unBrowserHandle, nDelta);
  this->internal->MouseWheel(unBrowserHandle, nDelta);
  
}


void  ISteamHTMLSurface_::KeyDown(HHTMLBrowser  unBrowserHandle, uint32  nNativeKeyCode, ISteamHTMLSurface::EHTMLKeyModifiers  eHTMLKeyModifiers)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p, (uint32 )%d, (ISteamHTMLSurface::EHTMLKeyModifiers )%p)\n", this, unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
  this->internal->KeyDown(unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
  
}


void  ISteamHTMLSurface_::KeyUp(HHTMLBrowser  unBrowserHandle, uint32  nNativeKeyCode, ISteamHTMLSurface::EHTMLKeyModifiers  eHTMLKeyModifiers)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p, (uint32 )%d, (ISteamHTMLSurface::EHTMLKeyModifiers )%p)\n", this, unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
  this->internal->KeyUp(unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
  
}


void  ISteamHTMLSurface_::KeyChar(HHTMLBrowser  unBrowserHandle, uint32  cUnicodeChar, ISteamHTMLSurface::EHTMLKeyModifiers  eHTMLKeyModifiers)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p, (uint32 )%d, (ISteamHTMLSurface::EHTMLKeyModifiers )%p)\n", this, unBrowserHandle, cUnicodeChar, eHTMLKeyModifiers);
  this->internal->KeyChar(unBrowserHandle, cUnicodeChar, eHTMLKeyModifiers);
  
}


void  ISteamHTMLSurface_::SetHorizontalScroll(HHTMLBrowser  unBrowserHandle, uint32  nAbsolutePixelScroll)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p, (uint32 )%d)\n", this, unBrowserHandle, nAbsolutePixelScroll);
  this->internal->SetHorizontalScroll(unBrowserHandle, nAbsolutePixelScroll);
  
}


void  ISteamHTMLSurface_::SetVerticalScroll(HHTMLBrowser  unBrowserHandle, uint32  nAbsolutePixelScroll)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p, (uint32 )%d)\n", this, unBrowserHandle, nAbsolutePixelScroll);
  this->internal->SetVerticalScroll(unBrowserHandle, nAbsolutePixelScroll);
  
}


void  ISteamHTMLSurface_::SetKeyFocus(HHTMLBrowser  unBrowserHandle, bool  bHasKeyFocus)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p, (bool )%d)\n", this, unBrowserHandle, bHasKeyFocus);
  this->internal->SetKeyFocus(unBrowserHandle, bHasKeyFocus);
  
}


void  ISteamHTMLSurface_::ViewSource(HHTMLBrowser  unBrowserHandle)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p)\n", this, unBrowserHandle);
  this->internal->ViewSource(unBrowserHandle);
  
}


void  ISteamHTMLSurface_::CopyToClipboard(HHTMLBrowser  unBrowserHandle)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p)\n", this, unBrowserHandle);
  this->internal->CopyToClipboard(unBrowserHandle);
  
}


void  ISteamHTMLSurface_::PasteFromClipboard(HHTMLBrowser  unBrowserHandle)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p)\n", this, unBrowserHandle);
  this->internal->PasteFromClipboard(unBrowserHandle);
  
}


void  ISteamHTMLSurface_::Find(HHTMLBrowser  unBrowserHandle, char * pchSearchStr, bool  bCurrentlyInFind, bool  bReverse)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p, (char *)\"%s\", (bool )%d, (bool )%d)\n", this, unBrowserHandle, pchSearchStr, bCurrentlyInFind, bReverse);
  this->internal->Find(unBrowserHandle, pchSearchStr, bCurrentlyInFind, bReverse);
  
}


void  ISteamHTMLSurface_::StopFind(HHTMLBrowser  unBrowserHandle)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p)\n", this, unBrowserHandle);
  this->internal->StopFind(unBrowserHandle);
  
}


void  ISteamHTMLSurface_::GetLinkAtPosition(HHTMLBrowser  unBrowserHandle, int  x, int  y)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p, (int )%d, (int )%d)\n", this, unBrowserHandle, x, y);
  this->internal->GetLinkAtPosition(unBrowserHandle, x, y);
  
}


void  ISteamHTMLSurface_::SetCookie(char * pchHostname, char * pchKey, char * pchValue, char * pchPath)
{
  TRACE("((ISteamHTMLSurface *)%p, (char *)\"%s\", (char *)\"%s\", (char *)\"%s\", (char *)\"%s\")\n", this, pchHostname, pchKey, pchValue, pchPath);
  this->internal->SetCookie(pchHostname, pchKey, pchValue, pchPath);
  
}


void  ISteamHTMLSurface_::SetPageScaleFactor(HHTMLBrowser  unBrowserHandle, float  flZoom, int  nPointX, int  nPointY)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p, (float )%f, (int )%d, (int )%d)\n", this, unBrowserHandle, flZoom, nPointX, nPointY);
  this->internal->SetPageScaleFactor(unBrowserHandle, flZoom, nPointX, nPointY);
  
}


void  ISteamHTMLSurface_::SetBackgroundMode(HHTMLBrowser  unBrowserHandle, bool  bBackgroundMode)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p, (bool )%d)\n", this, unBrowserHandle, bBackgroundMode);
  this->internal->SetBackgroundMode(unBrowserHandle, bBackgroundMode);
  
}


void  ISteamHTMLSurface_::AllowStartRequest(HHTMLBrowser  unBrowserHandle, bool  bAllowed)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p, (bool )%d)\n", this, unBrowserHandle, bAllowed);
  this->internal->AllowStartRequest(unBrowserHandle, bAllowed);
  
}


void  ISteamHTMLSurface_::JSDialogResponse(HHTMLBrowser  unBrowserHandle, bool  bResult)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p, (bool )%d)\n", this, unBrowserHandle, bResult);
  this->internal->JSDialogResponse(unBrowserHandle, bResult);
  
}


void  ISteamHTMLSurface_::FileLoadDialogResponse(HHTMLBrowser  unBrowserHandle, char ** pchSelectedFiles)
{
  TRACE("((ISteamHTMLSurface *)%p, (HHTMLBrowser )%p, (char **)\"%s\")\n", this, unBrowserHandle, pchSelectedFiles);
  this->internal->FileLoadDialogResponse(unBrowserHandle, pchSelectedFiles);
  
}
ISteamHTMLSurface_::ISteamHTMLSurface_(ISteamHTMLSurface * towrap)
{
  this->internal = towrap;
}

ISteamHTMLSurface_::~ISteamHTMLSurface_()
{
  delete this->internal;
}
