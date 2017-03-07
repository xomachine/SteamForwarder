#include <steam_api_.h>

uint32  ISteamUtils_::GetSecondsSinceAppActive()
{
  TRACE("((ISteamUtils *)%p)\n", this);
  uint32  result = this->internal->GetSecondsSinceAppActive();
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


uint32  ISteamUtils_::GetSecondsSinceComputerActive()
{
  TRACE("((ISteamUtils *)%p)\n", this);
  uint32  result = this->internal->GetSecondsSinceComputerActive();
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


EUniverse  ISteamUtils_::GetConnectedUniverse()
{
  TRACE("((ISteamUtils *)%p)\n", this);
  EUniverse  result = this->internal->GetConnectedUniverse();
  TRACE("() = (EUniverse )%p\n", result);

  return result;
}


uint32  ISteamUtils_::GetServerRealTime()
{
  TRACE("((ISteamUtils *)%p)\n", this);
  uint32  result = this->internal->GetServerRealTime();
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


char * ISteamUtils_::GetIPCountry()
{
  TRACE("((ISteamUtils *)%p)\n", this);
  char * result = this->internal->GetIPCountry();
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


bool  ISteamUtils_::GetImageSize(int  iImage, uint32 * pnWidth, uint32 * pnHeight)
{
  TRACE("((ISteamUtils *)%p, (int )%d, (uint32 *)%d, (uint32 *)%d)\n", this, iImage, pnWidth, pnHeight);
  bool  result = this->internal->GetImageSize(iImage, pnWidth, pnHeight);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUtils_::GetImageRGBA(int  iImage, uint8 * pubDest, int  nDestBufferSize)
{
  TRACE("((ISteamUtils *)%p, (int )%d, (uint8 *)%p, (int )%d)\n", this, iImage, pubDest, nDestBufferSize);
  bool  result = this->internal->GetImageRGBA(iImage, pubDest, nDestBufferSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUtils_::GetCSERIPPort(uint32 * unIP, uint16 * usPort)
{
  TRACE("((ISteamUtils *)%p, (uint32 *)%d, (uint16 *)%d)\n", this, unIP, usPort);
  bool  result = this->internal->GetCSERIPPort(unIP, usPort);
  TRACE("() = (bool )%d\n", result);

  return result;
}


uint8  ISteamUtils_::GetCurrentBatteryPower()
{
  TRACE("((ISteamUtils *)%p)\n", this);
  uint8  result = this->internal->GetCurrentBatteryPower();
  TRACE("() = (uint8 )%p\n", result);

  return result;
}


uint32  ISteamUtils_::GetAppID()
{
  TRACE("((ISteamUtils *)%p)\n", this);
  uint32  result = this->internal->GetAppID();
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


void  ISteamUtils_::SetOverlayNotificationPosition(ENotificationPosition  eNotificationPosition)
{
  TRACE("((ISteamUtils *)%p, (ENotificationPosition )%p)\n", this, eNotificationPosition);
  this->internal->SetOverlayNotificationPosition(eNotificationPosition);
  
}


bool  ISteamUtils_::IsAPICallCompleted(SteamAPICall_t  hSteamAPICall, bool * pbFailed)
{
  TRACE("((ISteamUtils *)%p, (SteamAPICall_t )%p, (bool *)%d)\n", this, hSteamAPICall, pbFailed);
  bool  result = this->internal->IsAPICallCompleted(hSteamAPICall, pbFailed);
  TRACE("() = (bool )%d\n", result);

  return result;
}


ESteamAPICallFailure  ISteamUtils_::GetAPICallFailureReason(SteamAPICall_t  hSteamAPICall)
{
  TRACE("((ISteamUtils *)%p, (SteamAPICall_t )%p)\n", this, hSteamAPICall);
  ESteamAPICallFailure  result = this->internal->GetAPICallFailureReason(hSteamAPICall);
  TRACE("() = (ESteamAPICallFailure )%p\n", result);

  return result;
}


bool  ISteamUtils_::GetAPICallResult(SteamAPICall_t  hSteamAPICall, void * pCallback, int  cubCallback, int  iCallbackExpected, bool * pbFailed)
{
  TRACE("((ISteamUtils *)%p, (SteamAPICall_t )%p, (void *)%p, (int )%d, (int )%d, (bool *)%d)\n", this, hSteamAPICall, pCallback, cubCallback, iCallbackExpected, pbFailed);
  bool  result = this->internal->GetAPICallResult(hSteamAPICall, pCallback, cubCallback, iCallbackExpected, pbFailed);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  ISteamUtils_::RunFrame()
{
  TRACE("((ISteamUtils *)%p)\n", this);
  
  
}


uint32  ISteamUtils_::GetIPCCallCount()
{
  TRACE("((ISteamUtils *)%p)\n", this);
  uint32  result = this->internal->GetIPCCallCount();
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


void  ISteamUtils_::SetWarningMessageHook(SteamAPIWarningMessageHook_t  pFunction)
{
  TRACE("((ISteamUtils *)%p, (SteamAPIWarningMessageHook_t )%p)\n", this, pFunction);
  this->internal->SetWarningMessageHook(pFunction);
  
}


bool  ISteamUtils_::IsOverlayEnabled()
{
  TRACE("((ISteamUtils *)%p)\n", this);
  bool  result = this->internal->IsOverlayEnabled();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUtils_::BOverlayNeedsPresent()
{
  TRACE("((ISteamUtils *)%p)\n", this);
  bool  result = this->internal->BOverlayNeedsPresent();
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  ISteamUtils_::CheckFileSignature(char * szFileName)
{
  TRACE("((ISteamUtils *)%p, (char *)\"%s\")\n", this, szFileName);
  SteamAPICall_t  result = this->internal->CheckFileSignature(szFileName);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  ISteamUtils_::ShowGamepadTextInput(EGamepadTextInputMode  eInputMode, EGamepadTextInputLineMode  eLineInputMode, char * pchDescription, uint32  unCharMax, char * pchExistingText)
{
  TRACE("((ISteamUtils *)%p, (EGamepadTextInputMode )%p, (EGamepadTextInputLineMode )%p, (char *)\"%s\", (uint32 )%d, (char *)\"%s\")\n", this, eInputMode, eLineInputMode, pchDescription, unCharMax, pchExistingText);
  bool  result = this->internal->ShowGamepadTextInput(eInputMode, eLineInputMode, pchDescription, unCharMax, pchExistingText);
  TRACE("() = (bool )%d\n", result);

  return result;
}


uint32  ISteamUtils_::GetEnteredGamepadTextLength()
{
  TRACE("((ISteamUtils *)%p)\n", this);
  uint32  result = this->internal->GetEnteredGamepadTextLength();
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


bool  ISteamUtils_::GetEnteredGamepadTextInput(char * pchText, uint32  cchText)
{
  TRACE("((ISteamUtils *)%p, (char *)\"%s\", (uint32 )%d)\n", this, pchText, cchText);
  bool  result = this->internal->GetEnteredGamepadTextInput(pchText, cchText);
  TRACE("() = (bool )%d\n", result);

  return result;
}


char * ISteamUtils_::GetSteamUILanguage()
{
  TRACE("((ISteamUtils *)%p)\n", this);
  char * result = this->internal->GetSteamUILanguage();
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


bool  ISteamUtils_::IsSteamRunningInVR()
{
  TRACE("((ISteamUtils *)%p)\n", this);
  bool  result = this->internal->IsSteamRunningInVR();
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  ISteamUtils_::SetOverlayNotificationInset(int  nHorizontalInset, int  nVerticalInset)
{
  TRACE("((ISteamUtils *)%p, (int )%d, (int )%d)\n", this, nHorizontalInset, nVerticalInset);
  this->internal->SetOverlayNotificationInset(nHorizontalInset, nVerticalInset);
  
}


bool  ISteamUtils_::IsSteamInBigPictureMode()
{
  TRACE("((ISteamUtils *)%p)\n", this);
  bool  result = this->internal->IsSteamInBigPictureMode();
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  ISteamUtils_::StartVRDashboard()
{
  TRACE("((ISteamUtils *)%p)\n", this);
  this->internal->StartVRDashboard();
  
}
ISteamUtils_::ISteamUtils_(ISteamUtils * towrap)
{
  this->internal = towrap;
}

ISteamUtils_::~ISteamUtils_()
{
  delete this->internal;
}
