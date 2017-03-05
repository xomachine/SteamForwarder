#include <steam_api_.h>
#include <isteamhtmlsurface.h>
class ISteamHTMLSurface_
{
public:
  virtual bool  Init() __attribute__((thiscall));
  virtual bool  Shutdown() __attribute__((thiscall));
  virtual SteamAPICall_t  CreateBrowser(char * pchUserAgent, char * pchUserCSS) __attribute__((thiscall));
  virtual void  RemoveBrowser(HHTMLBrowser  unBrowserHandle) __attribute__((thiscall));
  virtual void  LoadURL(HHTMLBrowser  unBrowserHandle, char * pchURL, char * pchPostData) __attribute__((thiscall));
  virtual void  SetSize(HHTMLBrowser  unBrowserHandle, uint32  unWidth, uint32  unHeight) __attribute__((thiscall));
  virtual void  StopLoad(HHTMLBrowser  unBrowserHandle) __attribute__((thiscall));
  virtual void  Reload(HHTMLBrowser  unBrowserHandle) __attribute__((thiscall));
  virtual void  GoBack(HHTMLBrowser  unBrowserHandle) __attribute__((thiscall));
  virtual void  GoForward(HHTMLBrowser  unBrowserHandle) __attribute__((thiscall));
  virtual void  AddHeader(HHTMLBrowser  unBrowserHandle, char * pchKey, char * pchValue) __attribute__((thiscall));
  virtual void  ExecuteJavascript(HHTMLBrowser  unBrowserHandle, char * pchScript) __attribute__((thiscall));
  virtual void  MouseUp(HHTMLBrowser  unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton  eMouseButton) __attribute__((thiscall));
  virtual void  MouseDown(HHTMLBrowser  unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton  eMouseButton) __attribute__((thiscall));
  virtual void  MouseDoubleClick(HHTMLBrowser  unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton  eMouseButton) __attribute__((thiscall));
  virtual void  MouseMove(HHTMLBrowser  unBrowserHandle, int  x, int  y) __attribute__((thiscall));
  virtual void  MouseWheel(HHTMLBrowser  unBrowserHandle, int32  nDelta) __attribute__((thiscall));
  virtual void  KeyDown(HHTMLBrowser  unBrowserHandle, uint32  nNativeKeyCode, ISteamHTMLSurface::EHTMLKeyModifiers  eHTMLKeyModifiers) __attribute__((thiscall));
  virtual void  KeyUp(HHTMLBrowser  unBrowserHandle, uint32  nNativeKeyCode, ISteamHTMLSurface::EHTMLKeyModifiers  eHTMLKeyModifiers) __attribute__((thiscall));
  virtual void  KeyChar(HHTMLBrowser  unBrowserHandle, uint32  cUnicodeChar, ISteamHTMLSurface::EHTMLKeyModifiers  eHTMLKeyModifiers) __attribute__((thiscall));
  virtual void  SetHorizontalScroll(HHTMLBrowser  unBrowserHandle, uint32  nAbsolutePixelScroll) __attribute__((thiscall));
  virtual void  SetVerticalScroll(HHTMLBrowser  unBrowserHandle, uint32  nAbsolutePixelScroll) __attribute__((thiscall));
  virtual void  SetKeyFocus(HHTMLBrowser  unBrowserHandle, bool  bHasKeyFocus) __attribute__((thiscall));
  virtual void  ViewSource(HHTMLBrowser  unBrowserHandle) __attribute__((thiscall));
  virtual void  CopyToClipboard(HHTMLBrowser  unBrowserHandle) __attribute__((thiscall));
  virtual void  PasteFromClipboard(HHTMLBrowser  unBrowserHandle) __attribute__((thiscall));
  virtual void  Find(HHTMLBrowser  unBrowserHandle, char * pchSearchStr, bool  bCurrentlyInFind, bool  bReverse) __attribute__((thiscall));
  virtual void  StopFind(HHTMLBrowser  unBrowserHandle) __attribute__((thiscall));
  virtual void  GetLinkAtPosition(HHTMLBrowser  unBrowserHandle, int  x, int  y) __attribute__((thiscall));
  virtual void  SetCookie(char * pchHostname, char * pchKey, char * pchValue, char * pchPath) __attribute__((thiscall));
  virtual void  SetPageScaleFactor(HHTMLBrowser  unBrowserHandle, float  flZoom, int  nPointX, int  nPointY) __attribute__((thiscall));
  virtual void  SetBackgroundMode(HHTMLBrowser  unBrowserHandle, bool  bBackgroundMode) __attribute__((thiscall));
  virtual void  AllowStartRequest(HHTMLBrowser  unBrowserHandle, bool  bAllowed) __attribute__((thiscall));
  virtual void  JSDialogResponse(HHTMLBrowser  unBrowserHandle, bool  bResult) __attribute__((thiscall));
  virtual void  FileLoadDialogResponse(HHTMLBrowser  unBrowserHandle, char ** pchSelectedFiles) __attribute__((thiscall));
  ISteamHTMLSurface_(ISteamHTMLSurface*to_wrap);
  ~ISteamHTMLSurface_();
private:
  ISteamHTMLSurface * internal;
};
