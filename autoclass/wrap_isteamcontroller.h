#include <steam_api_.h>
#include <isteamcontroller.h>
class ISteamController_
{
public:
  virtual bool  Init() __attribute__((thiscall));
  virtual bool  Shutdown() __attribute__((thiscall));
  virtual void  RunFrame() __attribute__((thiscall));
  virtual int  GetConnectedControllers(ControllerHandle_t * handlesOut) __attribute__((thiscall));
  virtual bool  ShowBindingPanel(ControllerHandle_t  controllerHandle) __attribute__((thiscall));
  virtual ControllerActionSetHandle_t  GetActionSetHandle(char * pszActionSetName) __attribute__((thiscall));
  virtual void  ActivateActionSet(ControllerHandle_t  controllerHandle, ControllerActionSetHandle_t  actionSetHandle) __attribute__((thiscall));
  virtual ControllerActionSetHandle_t  GetCurrentActionSet(ControllerHandle_t  controllerHandle) __attribute__((thiscall));
  virtual ControllerDigitalActionHandle_t  GetDigitalActionHandle(char * pszActionName) __attribute__((thiscall));
  virtual ControllerDigitalActionData_t  GetDigitalActionData(ControllerHandle_t  controllerHandle, ControllerDigitalActionHandle_t  digitalActionHandle) __attribute__((thiscall));
  virtual int  GetDigitalActionOrigins(ControllerHandle_t  controllerHandle, ControllerActionSetHandle_t  actionSetHandle, ControllerDigitalActionHandle_t  digitalActionHandle, EControllerActionOrigin * originsOut) __attribute__((thiscall));
  virtual ControllerAnalogActionHandle_t  GetAnalogActionHandle(char * pszActionName) __attribute__((thiscall));
  virtual ControllerAnalogActionData_t  GetAnalogActionData(ControllerHandle_t  controllerHandle, ControllerAnalogActionHandle_t  analogActionHandle) __attribute__((thiscall));
  virtual int  GetAnalogActionOrigins(ControllerHandle_t  controllerHandle, ControllerActionSetHandle_t  actionSetHandle, ControllerAnalogActionHandle_t  analogActionHandle, EControllerActionOrigin * originsOut) __attribute__((thiscall));
  virtual void  StopAnalogActionMomentum(ControllerHandle_t  controllerHandle, ControllerAnalogActionHandle_t  eAction) __attribute__((thiscall));
  virtual void  TriggerHapticPulse(ControllerHandle_t  controllerHandle, ESteamControllerPad  eTargetPad, unsigned short  usDurationMicroSec) __attribute__((thiscall));
  virtual void  TriggerRepeatedHapticPulse(ControllerHandle_t  controllerHandle, ESteamControllerPad  eTargetPad, unsigned short  usDurationMicroSec, unsigned short  usOffMicroSec, unsigned short  unRepeat, int  nFlags) __attribute__((thiscall));
  virtual void  TriggerVibration(ControllerHandle_t  controllerHandle, unsigned short  usLeftSpeed, unsigned short  usRightSpeed) __attribute__((thiscall));
  virtual void  SetLEDColor(ControllerHandle_t  controllerHandle, uint8  nColorR, uint8  nColorG, uint8  nColorB, int  nFlags) __attribute__((thiscall));
  virtual int  GetGamepadIndexForController(ControllerHandle_t  ulControllerHandle) __attribute__((thiscall));
  virtual ControllerHandle_t  GetControllerForGamepadIndex(int  nIndex) __attribute__((thiscall));
  virtual ControllerMotionData_t  GetMotionData(ControllerHandle_t  controllerHandle) __attribute__((thiscall));
  virtual bool  ShowDigitalActionOrigins(ControllerHandle_t  controllerHandle, ControllerDigitalActionHandle_t  digitalActionHandle, float  flScale, float  flXPosition, float  flYPosition) __attribute__((thiscall));
  virtual bool  ShowAnalogActionOrigins(ControllerHandle_t  controllerHandle, ControllerAnalogActionHandle_t  analogActionHandle, float  flScale, float  flXPosition, float  flYPosition) __attribute__((thiscall));
  virtual char * GetStringForActionOrigin(EControllerActionOrigin  eOrigin) __attribute__((thiscall));
  virtual char * GetGlyphForActionOrigin(EControllerActionOrigin  eOrigin) __attribute__((thiscall));
  ISteamController_(ISteamController*to_wrap);
  ~ISteamController_();
private:
  ISteamController * internal;
};
