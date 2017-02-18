#ifndef WRAP_ISTEAMCLIENT_CPP
#define WRAP_ISTEAMCLIENT_CPP
#include "autoclass/steam_api_.h" 
#include "windef.h"
#include "wine/debug.h"
#include "config.h"
HSteamPipe ISteamClient_::CreateSteamPipe()
{
  TRACE("((this[ISteamClient])%p)\n", this);
  HSteamPipe result = this->internal->CreateSteamPipe();
  TRACE(" = (HSteamPipe)%p\n", result);
  return result;
}
bool ISteamClient_::BReleaseSteamPipe( HSteamPipe hSteamPipe )
{
  TRACE("((this[ISteamClient])%p, (HSteamPipe)%p)\n", this, hSteamPipe);
  bool result = this->internal->BReleaseSteamPipe(hSteamPipe);
  TRACE(" = (bool)%d\n", result);
  return result;
}
HSteamUser ISteamClient_::ConnectToGlobalUser( HSteamPipe hSteamPipe )
{
  TRACE("((this[ISteamClient])%p, (HSteamPipe)%p)\n", this, hSteamPipe);
  HSteamUser result = this->internal->ConnectToGlobalUser(hSteamPipe);
  TRACE(" = (HSteamUser)%p\n", result);
  return result;
}
HSteamUser ISteamClient_::CreateLocalUser( HSteamPipe *phSteamPipe, EAccountType eAccountType )
{
  TRACE("((this[ISteamClient])%p, (HSteamPipe *)%p, (EAccountType)%p)\n", this, phSteamPipe, eAccountType);
  HSteamUser result = this->internal->CreateLocalUser(phSteamPipe, eAccountType);
  TRACE(" = (HSteamUser)%p\n", result);
  return result;
}
void ISteamClient_::ReleaseUser( HSteamPipe hSteamPipe, HSteamUser hUser )
{
  TRACE("((this[ISteamClient])%p, (HSteamPipe)%p, (HSteamUser)%p)\n", this, hSteamPipe, hUser);
  this->internal->ReleaseUser(hSteamPipe, hUser);
}
ISteamUser * ISteamClient_::GetISteamUser( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
  TRACE("((this[ISteamClient])%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamUser_();
  result->internal = this->internal->GetISteamUser(hSteamUser, hSteamPipe, pchVersion);
  if (!result->internal) {
    delete result;
    TRACE("() = nil\n");
    return NULL;
  }
  TRACE(" = (ISteamUser_*)%p wrapped[(ISteamUser *)%p]\n", result, result->internal);
  return (ISteamUser *)result;
}
ISteamGameServer * ISteamClient_::GetISteamGameServer( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
  TRACE("((this[ISteamClient])%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamGameServer_();
  result->internal = this->internal->GetISteamGameServer(hSteamUser, hSteamPipe, pchVersion);
  if (!result->internal) {
    delete result;
    TRACE("() = nil\n");
    return NULL;
  }
  TRACE(" = (ISteamGameServer_*)%p wrapped[(ISteamGameServer *)%p]\n", result, result->internal);
  return (ISteamGameServer *)result;
}
void ISteamClient_::SetLocalIPBinding( uint32 unIP, uint16 usPort )
{
  TRACE("((this[ISteamClient])%p, (uint32)%d, (uint16)%d)\n", this, unIP, usPort);
  this->internal->SetLocalIPBinding(unIP, usPort);
}
ISteamFriends * ISteamClient_::GetISteamFriends( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
  TRACE("((this[ISteamClient])%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamFriends_();
  result->internal = this->internal->GetISteamFriends(hSteamUser, hSteamPipe, pchVersion);
  if (!result->internal) {
    delete result;
    TRACE("() = nil\n");
    return NULL;
  }
  TRACE(" = (ISteamFriends_*)%p wrapped[(ISteamFriends *)%p]\n", result, result->internal);
  return (ISteamFriends *)result;
}
ISteamUtils * ISteamClient_::GetISteamUtils( HSteamPipe hSteamPipe, const char *pchVersion )
{
  TRACE("((this[ISteamClient])%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamPipe, pchVersion);
  auto result = new ISteamUtils_();
  result->internal = this->internal->GetISteamUtils(hSteamPipe, pchVersion);
  if (!result->internal) {
    delete result;
    TRACE("() = nil\n");
    return NULL;
  }
  TRACE(" = (ISteamUtils_*)%p wrapped[(ISteamUtils *)%p]\n", result, result->internal);
  return (ISteamUtils *)result;
}
ISteamMatchmaking * ISteamClient_::GetISteamMatchmaking( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
  TRACE("((this[ISteamClient])%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamMatchmaking_();
  result->internal = this->internal->GetISteamMatchmaking(hSteamUser, hSteamPipe, pchVersion);
  if (!result->internal) {
    delete result;
    TRACE("() = nil\n");
    return NULL;
  }
  TRACE(" = (ISteamMatchmaking_*)%p wrapped[(ISteamMatchmaking *)%p]\n", result, result->internal);
  return (ISteamMatchmaking *)result;
}
ISteamMatchmakingServers * ISteamClient_::GetISteamMatchmakingServers( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
  TRACE("((this[ISteamClient])%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamMatchmakingServers_();
  result->internal = this->internal->GetISteamMatchmakingServers(hSteamUser, hSteamPipe, pchVersion);
  if (!result->internal) {
    delete result;
    TRACE("() = nil\n");
    return NULL;
  }
  TRACE(" = (ISteamMatchmakingServers_*)%p wrapped[(ISteamMatchmakingServers *)%p]\n", result, result->internal);
  return (ISteamMatchmakingServers *)result;
}
void * ISteamClient_::GetISteamGenericInterface( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
  TRACE("((this[ISteamClient])%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  void * result = this->internal->GetISteamGenericInterface(hSteamUser, hSteamPipe, pchVersion);
  TRACE(" = (void *)%p\n", result);
  return result;
}
ISteamUserStats * ISteamClient_::GetISteamUserStats( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
  TRACE("((this[ISteamClient])%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamUserStats_();
  result->internal = this->internal->GetISteamUserStats(hSteamUser, hSteamPipe, pchVersion);
  if (!result->internal) {
    delete result;
    TRACE("() = nil\n");
    return NULL;
  }
  TRACE(" = (ISteamUserStats_*)%p wrapped[(ISteamUserStats *)%p]\n", result, result->internal);
  return (ISteamUserStats *)result;
}
ISteamGameServerStats * ISteamClient_::GetISteamGameServerStats( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion )
{
  TRACE("((this[ISteamClient])%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamGameServerStats_();
  result->internal = this->internal->GetISteamGameServerStats(hSteamuser, hSteamPipe, pchVersion);
  if (!result->internal) {
    delete result;
    TRACE("() = nil\n");
    return NULL;
  }
  TRACE(" = (ISteamGameServerStats_*)%p wrapped[(ISteamGameServerStats *)%p]\n", result, result->internal);
  return (ISteamGameServerStats *)result;
}
ISteamApps * ISteamClient_::GetISteamApps( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
  TRACE("((this[ISteamClient])%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamApps_();
  result->internal = this->internal->GetISteamApps(hSteamUser, hSteamPipe, pchVersion);
  if (!result->internal) {
    delete result;
    TRACE("() = nil\n");
    return NULL;
  }
  TRACE(" = (ISteamApps_*)%p wrapped[(ISteamApps *)%p]\n", result, result->internal);
  return (ISteamApps *)result;
}
ISteamNetworking * ISteamClient_::GetISteamNetworking( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
  TRACE("((this[ISteamClient])%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamNetworking_();
  result->internal = this->internal->GetISteamNetworking(hSteamUser, hSteamPipe, pchVersion);
  if (!result->internal) {
    delete result;
    TRACE("() = nil\n");
    return NULL;
  }
  TRACE(" = (ISteamNetworking_*)%p wrapped[(ISteamNetworking *)%p]\n", result, result->internal);
  return (ISteamNetworking *)result;
}
ISteamRemoteStorage * ISteamClient_::GetISteamRemoteStorage( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion )
{
  TRACE("((this[ISteamClient])%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamRemoteStorage_();
  result->internal = this->internal->GetISteamRemoteStorage(hSteamuser, hSteamPipe, pchVersion);
  if (!result->internal) {
    delete result;
    TRACE("() = nil\n");
    return NULL;
  }
  TRACE(" = (ISteamRemoteStorage_*)%p wrapped[(ISteamRemoteStorage *)%p]\n", result, result->internal);
  return (ISteamRemoteStorage *)result;
}
ISteamScreenshots * ISteamClient_::GetISteamScreenshots( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion )
{
  TRACE("((this[ISteamClient])%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamScreenshots_();
  result->internal = this->internal->GetISteamScreenshots(hSteamuser, hSteamPipe, pchVersion);
  if (!result->internal) {
    delete result;
    TRACE("() = nil\n");
    return NULL;
  }
  TRACE(" = (ISteamScreenshots_*)%p wrapped[(ISteamScreenshots *)%p]\n", result, result->internal);
  return (ISteamScreenshots *)result;
}
void ISteamClient_::RunFrame()
{
  TRACE("(deprecated)\n");
}
uint32 ISteamClient_::GetIPCCallCount()
{
  TRACE("((this[ISteamClient])%p)\n", this);
  uint32 result = this->internal->GetIPCCallCount();
  TRACE(" = (uint32)%d\n", result);
  return result;
}
void ISteamClient_::SetWarningMessageHook( SteamAPIWarningMessageHook_t pFunction )
{
  TRACE("((this[ISteamClient])%p, (SteamAPIWarningMessageHook_t)%p)\n", this, pFunction);
  this->internal->SetWarningMessageHook(pFunction);
}
bool ISteamClient_::BShutdownIfAllPipesClosed()
{
  TRACE("((this[ISteamClient])%p)\n", this);
  bool result = this->internal->BShutdownIfAllPipesClosed();
  TRACE(" = (bool)%d\n", result);
  return result;
}
ISteamHTTP * ISteamClient_::GetISteamHTTP( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion )
{
  TRACE("((this[ISteamClient])%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamHTTP_();
  result->internal = this->internal->GetISteamHTTP(hSteamuser, hSteamPipe, pchVersion);
  if (!result->internal) {
    delete result;
    TRACE("() = nil\n");
    return NULL;
  }
  TRACE(" = (ISteamHTTP_*)%p wrapped[(ISteamHTTP *)%p]\n", result, result->internal);
  return (ISteamHTTP *)result;
}
ISteamUnifiedMessages * ISteamClient_::GetISteamUnifiedMessages( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion )
{
  TRACE("((this[ISteamClient])%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamUnifiedMessages_();
  result->internal = this->internal->GetISteamUnifiedMessages(hSteamuser, hSteamPipe, pchVersion);
  if (!result->internal) {
    delete result;
    TRACE("() = nil\n");
    return NULL;
  }
  TRACE(" = (ISteamUnifiedMessages_*)%p wrapped[(ISteamUnifiedMessages *)%p]\n", result, result->internal);
  return (ISteamUnifiedMessages *)result;
}
ISteamController * ISteamClient_::GetISteamController( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
  TRACE("((this[ISteamClient])%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamController_();
  result->internal = this->internal->GetISteamController(hSteamUser, hSteamPipe, pchVersion);
  if (!result->internal) {
    delete result;
    TRACE("() = nil\n");
    return NULL;
  }
  TRACE(" = (ISteamController_*)%p wrapped[(ISteamController *)%p]\n", result, result->internal);
  return (ISteamController *)result;
}
ISteamUGC * ISteamClient_::GetISteamUGC( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
  TRACE("((this[ISteamClient])%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamUGC_();
  result->internal = this->internal->GetISteamUGC(hSteamUser, hSteamPipe, pchVersion);
  if (!result->internal) {
    delete result;
    TRACE("() = nil\n");
    return NULL;
  }
  TRACE(" = (ISteamUGC_*)%p wrapped[(ISteamUGC *)%p]\n", result, result->internal);
  return (ISteamUGC *)result;
}
ISteamAppList * ISteamClient_::GetISteamAppList( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
{
  TRACE("((this[ISteamClient])%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamAppList_();
  result->internal = this->internal->GetISteamAppList(hSteamUser, hSteamPipe, pchVersion);
  if (!result->internal) {
    delete result;
    TRACE("() = nil\n");
    return NULL;
  }
  TRACE(" = (ISteamAppList_*)%p wrapped[(ISteamAppList *)%p]\n", result, result->internal);
  return (ISteamAppList *)result;
}
ISteamMusic * ISteamClient_::GetISteamMusic( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion )
{
  TRACE("((this[ISteamClient])%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamMusic_();
  result->internal = this->internal->GetISteamMusic(hSteamuser, hSteamPipe, pchVersion);
  if (!result->internal) {
    delete result;
    TRACE("() = nil\n");
    return NULL;
  }
  TRACE(" = (ISteamMusic_*)%p wrapped[(ISteamMusic *)%p]\n", result, result->internal);
  return (ISteamMusic *)result;
}
ISteamMusicRemote * ISteamClient_::GetISteamMusicRemote(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion)
{
  TRACE("((this[ISteamClient])%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamMusicRemote_();
  result->internal = this->internal->GetISteamMusicRemote(hSteamuser, hSteamPipe, pchVersion);
  if (!result->internal) {
    delete result;
    TRACE("() = nil\n");
    return NULL;
  }
  TRACE(" = (ISteamMusicRemote_*)%p wrapped[(ISteamMusicRemote *)%p]\n", result, result->internal);
  return (ISteamMusicRemote *)result;
}
ISteamHTMLSurface * ISteamClient_::GetISteamHTMLSurface(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion)
{
  TRACE("((this[ISteamClient])%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamHTMLSurface_();
  result->internal = this->internal->GetISteamHTMLSurface(hSteamuser, hSteamPipe, pchVersion);
  if (!result->internal) {
    delete result;
    TRACE("() = nil\n");
    return NULL;
  }
  TRACE(" = (ISteamHTMLSurface_*)%p wrapped[(ISteamHTMLSurface *)%p]\n", result, result->internal);
  return (ISteamHTMLSurface *)result;
}
void ISteamClient_::DEPRECATED_Set_SteamAPI_CPostAPIResultInProcess( void (*)() )
{
  TRACE("(deprecated)\n");
}
void ISteamClient_::DEPRECATED_Remove_SteamAPI_CPostAPIResultInProcess( void (*)() )
{
  TRACE("(deprecated)\n");
}
void ISteamClient_::Set_SteamAPI_CCheckCallbackRegisteredInProcess( SteamAPI_CheckCallbackRegistered_t func )
{
  TRACE("(deprecated)\n");
}
ISteamInventory * ISteamClient_::GetISteamInventory( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion )
{
  TRACE("((this[ISteamClient])%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamInventory_();
  result->internal = this->internal->GetISteamInventory(hSteamuser, hSteamPipe, pchVersion);
  if (!result->internal) {
    delete result;
    TRACE("() = nil\n");
    return NULL;
  }
  TRACE(" = (ISteamInventory_*)%p wrapped[(ISteamInventory *)%p]\n", result, result->internal);
  return (ISteamInventory *)result;
}
ISteamVideo * ISteamClient_::GetISteamVideo( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion )
{
  TRACE("((this[ISteamClient])%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", this, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamVideo_();
  result->internal = this->internal->GetISteamVideo(hSteamuser, hSteamPipe, pchVersion);
  if (!result->internal) {
    delete result;
    TRACE("() = nil\n");
    return NULL;
  }
  TRACE(" = (ISteamVideo_*)%p wrapped[(ISteamVideo *)%p]\n", result, result->internal);
  return (ISteamVideo *)result;
}
#endif
