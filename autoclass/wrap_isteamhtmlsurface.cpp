#ifndef WRAP_ISTEAMHTMLSURFACE_CPP
#define WRAP_ISTEAMHTMLSURFACE_CPP
#include "autoclass/steam_api_.h" 
#include "windef.h"
#include "wine/debug.h"
#include "config.h"
bool ISteamHTMLSurface_::Init()
{
  TRACE("((this[ISteamHTMLSurface])%p)\n", this);
  bool result = this->internal->Init();
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamHTMLSurface_::Shutdown()
{
  TRACE("((this[ISteamHTMLSurface])%p)\n", this);
  bool result = this->internal->Shutdown();
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t ISteamHTMLSurface_::CreateBrowser( const char *pchUserAgent, const char *pchUserCSS )
{
  TRACE("((this[ISteamHTMLSurface])%p, (const char *)\"%s\", (const char *)\"%s\")\n", this, pchUserAgent, pchUserCSS);
  SteamAPICall_t result = this->internal->CreateBrowser(pchUserAgent, pchUserCSS);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
void ISteamHTMLSurface_::RemoveBrowser( HHTMLBrowser unBrowserHandle )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p)\n", this, unBrowserHandle);
  this->internal->RemoveBrowser(unBrowserHandle);
}
void ISteamHTMLSurface_::LoadURL( HHTMLBrowser unBrowserHandle, const char *pchURL, const char *pchPostData )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p, (const char *)\"%s\", (const char *)\"%s\")\n", this, unBrowserHandle, pchURL, pchPostData);
  this->internal->LoadURL(unBrowserHandle, pchURL, pchPostData);
}
void ISteamHTMLSurface_::SetSize( HHTMLBrowser unBrowserHandle, uint32 unWidth, uint32 unHeight )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p, (uint32)%d, (uint32)%d)\n", this, unBrowserHandle, unWidth, unHeight);
  this->internal->SetSize(unBrowserHandle, unWidth, unHeight);
}
void ISteamHTMLSurface_::StopLoad( HHTMLBrowser unBrowserHandle )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p)\n", this, unBrowserHandle);
  this->internal->StopLoad(unBrowserHandle);
}
void ISteamHTMLSurface_::Reload( HHTMLBrowser unBrowserHandle )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p)\n", this, unBrowserHandle);
  this->internal->Reload(unBrowserHandle);
}
void ISteamHTMLSurface_::GoBack( HHTMLBrowser unBrowserHandle )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p)\n", this, unBrowserHandle);
  this->internal->GoBack(unBrowserHandle);
}
void ISteamHTMLSurface_::GoForward( HHTMLBrowser unBrowserHandle )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p)\n", this, unBrowserHandle);
  this->internal->GoForward(unBrowserHandle);
}
void ISteamHTMLSurface_::AddHeader( HHTMLBrowser unBrowserHandle, const char *pchKey, const char *pchValue )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p, (const char *)\"%s\", (const char *)\"%s\")\n", this, unBrowserHandle, pchKey, pchValue);
  this->internal->AddHeader(unBrowserHandle, pchKey, pchValue);
}
void ISteamHTMLSurface_::ExecuteJavascript( HHTMLBrowser unBrowserHandle, const char *pchScript )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p, (const char *)\"%s\")\n", this, unBrowserHandle, pchScript);
  this->internal->ExecuteJavascript(unBrowserHandle, pchScript);
}
void ISteamHTMLSurface_::MouseUp( HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p, (EHTMLMouseButton)%p)\n", this, unBrowserHandle, (ISteamHTMLSurface::EHTMLMouseButton)eMouseButton);
  this->internal->MouseUp(unBrowserHandle, (ISteamHTMLSurface::EHTMLMouseButton)eMouseButton);
}
void ISteamHTMLSurface_::MouseDown( HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p, (EHTMLMouseButton)%p)\n", this, unBrowserHandle, (ISteamHTMLSurface::EHTMLMouseButton)eMouseButton);
  this->internal->MouseDown(unBrowserHandle, (ISteamHTMLSurface::EHTMLMouseButton)eMouseButton);
}
void ISteamHTMLSurface_::MouseDoubleClick( HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p, (EHTMLMouseButton)%p)\n", this, unBrowserHandle, (ISteamHTMLSurface::EHTMLMouseButton)eMouseButton);
  this->internal->MouseDoubleClick(unBrowserHandle, (ISteamHTMLSurface::EHTMLMouseButton)eMouseButton);
}
void ISteamHTMLSurface_::MouseMove( HHTMLBrowser unBrowserHandle, int x, int y )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p, (int)%d, (int)%d)\n", this, unBrowserHandle, x, y);
  this->internal->MouseMove(unBrowserHandle, x, y);
}
void ISteamHTMLSurface_::MouseWheel( HHTMLBrowser unBrowserHandle, int32 nDelta )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p, (int32)%d)\n", this, unBrowserHandle, nDelta);
  this->internal->MouseWheel(unBrowserHandle, nDelta);
}
void ISteamHTMLSurface_::KeyDown( HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p, (uint32)%d, (EHTMLKeyModifiers)%p)\n", this, unBrowserHandle, nNativeKeyCode, (ISteamHTMLSurface::EHTMLKeyModifiers)eHTMLKeyModifiers);
  this->internal->KeyDown(unBrowserHandle, nNativeKeyCode, (ISteamHTMLSurface::EHTMLKeyModifiers)eHTMLKeyModifiers);
}
void ISteamHTMLSurface_::KeyUp( HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p, (uint32)%d, (EHTMLKeyModifiers)%p)\n", this, unBrowserHandle, nNativeKeyCode, (ISteamHTMLSurface::EHTMLKeyModifiers)eHTMLKeyModifiers);
  this->internal->KeyUp(unBrowserHandle, nNativeKeyCode, (ISteamHTMLSurface::EHTMLKeyModifiers)eHTMLKeyModifiers);
}
void ISteamHTMLSurface_::KeyChar( HHTMLBrowser unBrowserHandle, uint32 cUnicodeChar, EHTMLKeyModifiers eHTMLKeyModifiers )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p, (uint32)%d, (EHTMLKeyModifiers)%p)\n", this, unBrowserHandle, cUnicodeChar, (ISteamHTMLSurface::EHTMLKeyModifiers)eHTMLKeyModifiers);
  this->internal->KeyChar(unBrowserHandle, cUnicodeChar, (ISteamHTMLSurface::EHTMLKeyModifiers)eHTMLKeyModifiers);
}
void ISteamHTMLSurface_::SetHorizontalScroll( HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p, (uint32)%d)\n", this, unBrowserHandle, nAbsolutePixelScroll);
  this->internal->SetHorizontalScroll(unBrowserHandle, nAbsolutePixelScroll);
}
void ISteamHTMLSurface_::SetVerticalScroll( HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p, (uint32)%d)\n", this, unBrowserHandle, nAbsolutePixelScroll);
  this->internal->SetVerticalScroll(unBrowserHandle, nAbsolutePixelScroll);
}
void ISteamHTMLSurface_::SetKeyFocus( HHTMLBrowser unBrowserHandle, bool bHasKeyFocus )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p, (bool)%d)\n", this, unBrowserHandle, bHasKeyFocus);
  this->internal->SetKeyFocus(unBrowserHandle, bHasKeyFocus);
}
void ISteamHTMLSurface_::ViewSource( HHTMLBrowser unBrowserHandle )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p)\n", this, unBrowserHandle);
  this->internal->ViewSource(unBrowserHandle);
}
void ISteamHTMLSurface_::CopyToClipboard( HHTMLBrowser unBrowserHandle )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p)\n", this, unBrowserHandle);
  this->internal->CopyToClipboard(unBrowserHandle);
}
void ISteamHTMLSurface_::PasteFromClipboard( HHTMLBrowser unBrowserHandle )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p)\n", this, unBrowserHandle);
  this->internal->PasteFromClipboard(unBrowserHandle);
}
void ISteamHTMLSurface_::Find( HHTMLBrowser unBrowserHandle, const char *pchSearchStr, bool bCurrentlyInFind, bool bReverse )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p, (const char *)\"%s\", (bool)%d, (bool)%d)\n", this, unBrowserHandle, pchSearchStr, bCurrentlyInFind, bReverse);
  this->internal->Find(unBrowserHandle, pchSearchStr, bCurrentlyInFind, bReverse);
}
void ISteamHTMLSurface_::StopFind( HHTMLBrowser unBrowserHandle )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p)\n", this, unBrowserHandle);
  this->internal->StopFind(unBrowserHandle);
}
void ISteamHTMLSurface_::GetLinkAtPosition(  HHTMLBrowser unBrowserHandle, int x, int y )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p, (int)%d, (int)%d)\n", this, unBrowserHandle, x, y);
  this->internal->GetLinkAtPosition(unBrowserHandle, x, y);
}
void ISteamHTMLSurface_::SetCookie( const char *pchHostname, const char *pchKey, const char *pchValue, const char *pchPath = "/", RTime32 nExpires = 0, bool bSecure = false, bool bHTTPOnly = false )
{
  TRACE("((this[ISteamHTMLSurface])%p, (const char *)\"%s\", (const char *)\"%s\", (const char *)\"%s\", (const char *)\"%s\", (RTime32)%p, (bool)%d, (bool)%d)\n", this, pchHostname, pchKey, pchValue, pchPath, nExpires, bSecure, bHTTPOnly);
  this->internal->SetCookie(pchHostname, pchKey, pchValue, pchPath, nExpires, bSecure, bHTTPOnly);
}
void ISteamHTMLSurface_::SetPageScaleFactor( HHTMLBrowser unBrowserHandle, float flZoom, int nPointX, int nPointY )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p, (float)%f, (int)%d, (int)%d)\n", this, unBrowserHandle, flZoom, nPointX, nPointY);
  this->internal->SetPageScaleFactor(unBrowserHandle, flZoom, nPointX, nPointY);
}
void ISteamHTMLSurface_::SetBackgroundMode( HHTMLBrowser unBrowserHandle, bool bBackgroundMode )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p, (bool)%d)\n", this, unBrowserHandle, bBackgroundMode);
  this->internal->SetBackgroundMode(unBrowserHandle, bBackgroundMode);
}
void ISteamHTMLSurface_::AllowStartRequest( HHTMLBrowser unBrowserHandle, bool bAllowed )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p, (bool)%d)\n", this, unBrowserHandle, bAllowed);
  this->internal->AllowStartRequest(unBrowserHandle, bAllowed);
}
void ISteamHTMLSurface_::JSDialogResponse( HHTMLBrowser unBrowserHandle, bool bResult )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p, (bool)%d)\n", this, unBrowserHandle, bResult);
  this->internal->JSDialogResponse(unBrowserHandle, bResult);
}
void ISteamHTMLSurface_::FileLoadDialogResponse( HHTMLBrowser unBrowserHandle, const char **pchSelectedFiles )
{
  TRACE("((this[ISteamHTMLSurface])%p, (HHTMLBrowser)%p, (const char **)%p)\n", this, unBrowserHandle, pchSelectedFiles);
  this->internal->FileLoadDialogResponse(unBrowserHandle, pchSelectedFiles);
}
#endif
