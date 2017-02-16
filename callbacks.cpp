#include "callbacks.h"
#include <map>

std::map<WinCallback*, WrappedCallback*> callbackHolder;

WrappedCallback::WrappedCallback(WinCallback *wc)
{
  TRACE("((WrappedCallback*)%p = wrapped[(WinCallback)%p])\n", this, wc);
  internal = wc;
}

void WrappedCallback::Run(void *pvParams)
{
  TRACE("((WrappedCallback*)%p, (void*)%p)\n", this, pvParams);
  this->internal->Run(pvParams);
}
void WrappedCallback::Run(void *pvParams, bool onIOFailure, SteamAPICall_t hSteamAPICall)
{
  TRACE("((WrappedCallback*)%p, (void*)%p), (bool)%d, (SteamAPICall_t)%ld\n", this, pvParams, onIOFailure, hSteamAPICall);
  this->internal->Run(pvParams, onIOFailure, hSteamAPICall);
}
int WrappedCallback::GetCallbackSizeBytes()
{
  TRACE("((WrappedCallback)%p)\n", this);
  auto result = this->internal->GetCallbackSizeBytes();
  TRACE("() = %d\n", result);
  return result;
}
WrappedCallback *wrap(WinCallback *p)
{
  WrappedCallback *result= callbackHolder[p];
  if (result == NULL)
  {
    TRACE("Created new wrapper\n", p);
    result = new WrappedCallback(p);
    callbackHolder[p] = result;
  }
  TRACE("Wrapper for (WinCallback*)%p is (WrappedCallback*)%ld\n", p, result);
  return result;
}
#ifdef __cplusplus
extern "C" {
#endif
void SteamAPI_RegisterCallback_(class WinCallback * pCallback, int iCallback)
{
  TRACE("((class WinCallback *)%p, (int)%d)\n", pCallback, iCallback);
  WrappedCallback* cw = wrap(pCallback);
  SteamAPI_RegisterCallback(cw, iCallback);
}
void SteamAPI_UnregisterCallback_(class WinCallback * pCallback)
{
  TRACE("((class WinCallback *)%p)\n", pCallback);
  WrappedCallback* cw = wrap(pCallback);
  SteamAPI_UnregisterCallback(cw);
  callbackHolder.erase(pCallback);
  delete cw;
}
void SteamAPI_RegisterCallResult_(class WinCallback * pCallback, SteamAPICall_t hAPICall)
{
  TRACE("((class WinCallback *)%p, (SteamAPICall_t)%p)\n", pCallback, hAPICall);
  WrappedCallback* cw = wrap(pCallback);
  SteamAPI_RegisterCallResult(cw, hAPICall);
}
void SteamAPI_UnregisterCallResult_(class WinCallback * pCallback, SteamAPICall_t hAPICall)
{
  TRACE("((class WinCallback *)%p, (SteamAPICall_t)%p)\n", pCallback, hAPICall);
  WrappedCallback* cw = wrap(pCallback);
  SteamAPI_UnregisterCallResult(cw, hAPICall);
  callbackHolder.erase(pCallback);
  delete cw;
}
#ifdef __cplusplus
}
#endif
