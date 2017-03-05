#include <steam_api_.h>
#include <isteamutils.h>
class ISteamUtils_
{
public:
  virtual uint32  GetSecondsSinceAppActive() __attribute__((thiscall));
  virtual uint32  GetSecondsSinceComputerActive() __attribute__((thiscall));
  virtual EUniverse  GetConnectedUniverse() __attribute__((thiscall));
  virtual uint32  GetServerRealTime() __attribute__((thiscall));
  virtual char * GetIPCountry() __attribute__((thiscall));
  virtual bool  GetImageSize(int  iImage, uint32 * pnWidth, uint32 * pnHeight) __attribute__((thiscall));
  virtual bool  GetImageRGBA(int  iImage, uint8 * pubDest, int  nDestBufferSize) __attribute__((thiscall));
  virtual bool  GetCSERIPPort(uint32 * unIP, uint16 * usPort) __attribute__((thiscall));
  virtual uint8  GetCurrentBatteryPower() __attribute__((thiscall));
  virtual uint32  GetAppID() __attribute__((thiscall));
  virtual void  SetOverlayNotificationPosition(ENotificationPosition  eNotificationPosition) __attribute__((thiscall));
  virtual bool  IsAPICallCompleted(SteamAPICall_t  hSteamAPICall, bool * pbFailed) __attribute__((thiscall));
  virtual ESteamAPICallFailure  GetAPICallFailureReason(SteamAPICall_t  hSteamAPICall) __attribute__((thiscall));
  virtual bool  GetAPICallResult(SteamAPICall_t  hSteamAPICall, void * pCallback, int  cubCallback, int  iCallbackExpected, bool * pbFailed) __attribute__((thiscall));
  virtual void  RunFrame() __attribute__((thiscall));
  virtual uint32  GetIPCCallCount() __attribute__((thiscall));
  virtual void  SetWarningMessageHook(SteamAPIWarningMessageHook_t  pFunction) __attribute__((thiscall));
  virtual bool  IsOverlayEnabled() __attribute__((thiscall));
  virtual bool  BOverlayNeedsPresent() __attribute__((thiscall));
  virtual SteamAPICall_t  CheckFileSignature(char * szFileName) __attribute__((thiscall));
  virtual bool  ShowGamepadTextInput(EGamepadTextInputMode  eInputMode, EGamepadTextInputLineMode  eLineInputMode, char * pchDescription, uint32  unCharMax, char * pchExistingText) __attribute__((thiscall));
  virtual uint32  GetEnteredGamepadTextLength() __attribute__((thiscall));
  virtual bool  GetEnteredGamepadTextInput(char * pchText, uint32  cchText) __attribute__((thiscall));
  virtual char * GetSteamUILanguage() __attribute__((thiscall));
  virtual bool  IsSteamRunningInVR() __attribute__((thiscall));
  virtual void  SetOverlayNotificationInset(int  nHorizontalInset, int  nVerticalInset) __attribute__((thiscall));
  virtual bool  IsSteamInBigPictureMode() __attribute__((thiscall));
  virtual void  StartVRDashboard() __attribute__((thiscall));
  ISteamUtils_(ISteamUtils*to_wrap);
  ~ISteamUtils_();
private:
  ISteamUtils * internal;
};
