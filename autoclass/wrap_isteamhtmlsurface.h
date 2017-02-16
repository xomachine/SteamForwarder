#ifndef WRAP_ISTEAMHTMLSURFACE_H
#define WRAP_ISTEAMHTMLSURFACE_H
#include "steam_api.h"
class ISteamHTMLSurface_ 
{
  virtual bool Init() __attribute__((thiscall));
  virtual bool Shutdown() __attribute__((thiscall));
  virtual SteamAPICall_t CreateBrowser( const char *pchUserAgent, const char *pchUserCSS ) __attribute__((thiscall));
  virtual void RemoveBrowser( HHTMLBrowser unBrowserHandle ) __attribute__((thiscall));
  virtual void LoadURL( HHTMLBrowser unBrowserHandle, const char *pchURL, const char *pchPostData ) __attribute__((thiscall));
  virtual void SetSize( HHTMLBrowser unBrowserHandle, uint32 unWidth, uint32 unHeight ) __attribute__((thiscall));
  virtual void StopLoad( HHTMLBrowser unBrowserHandle ) __attribute__((thiscall));
  virtual void Reload( HHTMLBrowser unBrowserHandle ) __attribute__((thiscall));
  virtual void GoBack( HHTMLBrowser unBrowserHandle ) __attribute__((thiscall));
  virtual void GoForward( HHTMLBrowser unBrowserHandle ) __attribute__((thiscall));
  virtual void AddHeader( HHTMLBrowser unBrowserHandle, const char *pchKey, const char *pchValue ) __attribute__((thiscall));
  virtual void ExecuteJavascript( HHTMLBrowser unBrowserHandle, const char *pchScript ) __attribute__((thiscall));
	enum EHTMLMouseButton
	{
		eHTMLMouseButton_Left = 0,
		eHTMLMouseButton_Right = 1,
		eHTMLMouseButton_Middle = 2,
	};
  virtual void MouseUp( HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton ) __attribute__((thiscall));
  virtual void MouseDown( HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton ) __attribute__((thiscall));
  virtual void MouseDoubleClick( HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton ) __attribute__((thiscall));
  virtual void MouseMove( HHTMLBrowser unBrowserHandle, int x, int y ) __attribute__((thiscall));
  virtual void MouseWheel( HHTMLBrowser unBrowserHandle, int32 nDelta ) __attribute__((thiscall));
	enum EMouseCursor
	{
		dc_user = 0,
		dc_none,
		dc_arrow,
		dc_ibeam,
		dc_hourglass,
		dc_waitarrow,
		dc_crosshair,
		dc_up,
		dc_sizenw,
		dc_sizese,
		dc_sizene,
		dc_sizesw,
		dc_sizew,
		dc_sizee,
		dc_sizen,
		dc_sizes,
		dc_sizewe,
		dc_sizens,
		dc_sizeall,
		dc_no,
		dc_hand,
		dc_blank, // don't show any custom cursor, just use your default
		dc_middle_pan,
		dc_north_pan,
		dc_north_east_pan,
		dc_east_pan,
		dc_south_east_pan,
		dc_south_pan,
		dc_south_west_pan,
		dc_west_pan,
		dc_north_west_pan,
		dc_alias,
		dc_cell,
		dc_colresize,
		dc_copycur,
		dc_verticaltext,
		dc_rowresize,
		dc_zoomin,
		dc_zoomout,
		dc_help,
		dc_custom,

		dc_last, // custom cursors start from this value and up
	};
	enum EHTMLKeyModifiers
	{
		k_eHTMLKeyModifier_None = 0,
		k_eHTMLKeyModifier_AltDown = 1 << 0,
		k_eHTMLKeyModifier_CtrlDown = 1 << 1,
		k_eHTMLKeyModifier_ShiftDown = 1 << 2,
	};
  virtual void KeyDown( HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers ) __attribute__((thiscall));
  virtual void KeyUp( HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers ) __attribute__((thiscall));
  virtual void KeyChar( HHTMLBrowser unBrowserHandle, uint32 cUnicodeChar, EHTMLKeyModifiers eHTMLKeyModifiers ) __attribute__((thiscall));
  virtual void SetHorizontalScroll( HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll ) __attribute__((thiscall));
  virtual void SetVerticalScroll( HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll ) __attribute__((thiscall));
  virtual void SetKeyFocus( HHTMLBrowser unBrowserHandle, bool bHasKeyFocus ) __attribute__((thiscall));
  virtual void ViewSource( HHTMLBrowser unBrowserHandle ) __attribute__((thiscall));
  virtual void CopyToClipboard( HHTMLBrowser unBrowserHandle ) __attribute__((thiscall));
  virtual void PasteFromClipboard( HHTMLBrowser unBrowserHandle ) __attribute__((thiscall));
  virtual void Find( HHTMLBrowser unBrowserHandle, const char *pchSearchStr, bool bCurrentlyInFind, bool bReverse ) __attribute__((thiscall));
  virtual void StopFind( HHTMLBrowser unBrowserHandle ) __attribute__((thiscall));
  virtual void GetLinkAtPosition(  HHTMLBrowser unBrowserHandle, int x, int y ) __attribute__((thiscall));
  virtual void SetCookie( const char *pchHostname, const char *pchKey, const char *pchValue, const char *pchPath = "/", RTime32 nExpires = 0, bool bSecure = false, bool bHTTPOnly = false ) __attribute__((thiscall));
  virtual void SetPageScaleFactor( HHTMLBrowser unBrowserHandle, float flZoom, int nPointX, int nPointY ) __attribute__((thiscall));
  virtual void SetBackgroundMode( HHTMLBrowser unBrowserHandle, bool bBackgroundMode ) __attribute__((thiscall));
  virtual void AllowStartRequest( HHTMLBrowser unBrowserHandle, bool bAllowed ) __attribute__((thiscall));
  virtual void JSDialogResponse( HHTMLBrowser unBrowserHandle, bool bResult ) __attribute__((thiscall));
  virtual void FileLoadDialogResponse( HHTMLBrowser unBrowserHandle, const char **pchSelectedFiles ) __attribute__((thiscall));
  public:
    ISteamHTMLSurface *internal;
};
#endif
