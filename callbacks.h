#include "config.h"

class WinCallback
{
public:
  virtual __attribute__((thiscall)) void Run(void *pvParam) = 0;
  virtual __attribute__((thiscall)) void Run(void *pvParam, bool bIOFailure, SteamAPICall_t hSteamAPICall) = 0;
  virtual __attribute__((thiscall)) int GetCallbackSizeBytes() = 0;
  uint8 m_nCallbackFlags;
  int m_iCallback;
};

class WrappedCallback: public CCallbackBase
{
public:
  WrappedCallback(WinCallback *internal);
  virtual void Run(void *pvParam);
  virtual void Run(void *pvParam, bool bIOFailure, SteamAPICall_t hSteamAPICall);
  virtual int GetCallbackSizeBytes();
private:
  WinCallback *internal;
};

