#include <steam_api_.h>

HSteamPipe  ISteamClient_::CreateSteamPipe()
{
  TRACE("((ISteamClient *)%p)\n", this);
  auto result = this->internal->CreateSteamPipe();
  TRACE("() = (HSteamPipe )%p\n", result);

  return result;
}


bool  ISteamClient_::BReleaseSteamPipe(HSteamPipe  hSteamPipe)
{
  TRACE("((ISteamClient *)%p, (HSteamPipe )%p)\n", this, hSteamPipe);
  auto result = this->internal->BReleaseSteamPipe(hSteamPipe);
  TRACE("() = (bool )%d\n", result);

  return result;
}


HSteamUser  ISteamClient_::ConnectToGlobalUser(HSteamPipe  hSteamPipe)
{
  TRACE("((ISteamClient *)%p, (HSteamPipe )%p)\n", this, hSteamPipe);
  auto result = this->internal->ConnectToGlobalUser(hSteamPipe);
  TRACE("() = (HSteamUser )%p\n", result);

  return result;
}


HSteamUser  ISteamClient_::CreateLocalUser(HSteamPipe * phSteamPipe, EAccountType  eAccountType)
{
  TRACE("((ISteamClient *)%p, (HSteamPipe *)%p, (EAccountType )%p)\n", this, phSteamPipe, eAccountType);
  auto result = this->internal->CreateLocalUser(phSteamPipe, eAccountType);
  TRACE("() = (HSteamUser )%p\n", result);

  return result;
}


void  ISteamClient_::ReleaseUser(HSteamPipe  hSteamPipe, HSteamUser  hUser)
{
  TRACE("((ISteamClient *)%p, (HSteamPipe )%p, (HSteamUser )%p)\n", this, hSteamPipe, hUser);
  this->internal->ReleaseUser(hSteamPipe, hUser);
  
}


ISteamUser * ISteamClient_::GetISteamUser(HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamUser_(this->internal->GetISteamUser(hSteamUser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamUser *)%p\n", result);

  return (ISteamUser *)result;
}


ISteamGameServer * ISteamClient_::GetISteamGameServer(HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamGameServer_(this->internal->GetISteamGameServer(hSteamUser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamGameServer *)%p\n", result);

  return (ISteamGameServer *)result;
}


void  ISteamClient_::SetLocalIPBinding(uint32  unIP, uint16  usPort)
{
  TRACE("((ISteamClient *)%p, (uint32 )%d, (uint16 )%d)\n", this, unIP, usPort);
  this->internal->SetLocalIPBinding(unIP, usPort);
  
}


ISteamFriends * ISteamClient_::GetISteamFriends(HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamFriends_(this->internal->GetISteamFriends(hSteamUser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamFriends *)%p\n", result);

  return (ISteamFriends *)result;
}


ISteamUtils * ISteamClient_::GetISteamUtils(HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamPipe, pchVersion);
  auto result = new ISteamUtils_(this->internal->GetISteamUtils(hSteamPipe, pchVersion));
  TRACE("() = (ISteamUtils *)%p\n", result);

  return (ISteamUtils *)result;
}


ISteamMatchmaking * ISteamClient_::GetISteamMatchmaking(HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamMatchmaking_(this->internal->GetISteamMatchmaking(hSteamUser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamMatchmaking *)%p\n", result);

  return (ISteamMatchmaking *)result;
}


ISteamMatchmakingServers * ISteamClient_::GetISteamMatchmakingServers(HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamMatchmakingServers_(this->internal->GetISteamMatchmakingServers(hSteamUser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamMatchmakingServers *)%p\n", result);

  return (ISteamMatchmakingServers *)result;
}


void * ISteamClient_::GetISteamGenericInterface(HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = this->internal->GetISteamGenericInterface(hSteamUser, hSteamPipe, pchVersion);
  

  return result;
}


ISteamUserStats * ISteamClient_::GetISteamUserStats(HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamUserStats_(this->internal->GetISteamUserStats(hSteamUser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamUserStats *)%p\n", result);

  return (ISteamUserStats *)result;
}


ISteamGameServerStats * ISteamClient_::GetISteamGameServerStats(HSteamUser  hSteamuser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamGameServerStats_(this->internal->GetISteamGameServerStats(hSteamuser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamGameServerStats *)%p\n", result);

  return (ISteamGameServerStats *)result;
}


ISteamApps * ISteamClient_::GetISteamApps(HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamApps_(this->internal->GetISteamApps(hSteamUser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamApps *)%p\n", result);

  return (ISteamApps *)result;
}


ISteamNetworking * ISteamClient_::GetISteamNetworking(HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamNetworking_(this->internal->GetISteamNetworking(hSteamUser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamNetworking *)%p\n", result);

  return (ISteamNetworking *)result;
}


ISteamRemoteStorage * ISteamClient_::GetISteamRemoteStorage(HSteamUser  hSteamuser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamRemoteStorage_(this->internal->GetISteamRemoteStorage(hSteamuser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamRemoteStorage *)%p\n", result);

  return (ISteamRemoteStorage *)result;
}


ISteamScreenshots * ISteamClient_::GetISteamScreenshots(HSteamUser  hSteamuser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamScreenshots_(this->internal->GetISteamScreenshots(hSteamuser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamScreenshots *)%p\n", result);

  return (ISteamScreenshots *)result;
}


void  ISteamClient_::RunFrame()
{
  TRACE("((ISteamClient *)%p)\n", this);
  
  
}


uint32  ISteamClient_::GetIPCCallCount()
{
  TRACE("((ISteamClient *)%p)\n", this);
  auto result = this->internal->GetIPCCallCount();
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


void  ISteamClient_::SetWarningMessageHook(SteamAPIWarningMessageHook_t  pFunction)
{
  TRACE("((ISteamClient *)%p, (SteamAPIWarningMessageHook_t )%p)\n", this, pFunction);
  this->internal->SetWarningMessageHook(pFunction);
  
}


bool  ISteamClient_::BShutdownIfAllPipesClosed()
{
  TRACE("((ISteamClient *)%p)\n", this);
  auto result = this->internal->BShutdownIfAllPipesClosed();
  TRACE("() = (bool )%d\n", result);

  return result;
}


ISteamHTTP * ISteamClient_::GetISteamHTTP(HSteamUser  hSteamuser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamHTTP_(this->internal->GetISteamHTTP(hSteamuser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamHTTP *)%p\n", result);

  return (ISteamHTTP *)result;
}


ISteamUnifiedMessages * ISteamClient_::GetISteamUnifiedMessages(HSteamUser  hSteamuser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamUnifiedMessages_(this->internal->GetISteamUnifiedMessages(hSteamuser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamUnifiedMessages *)%p\n", result);

  return (ISteamUnifiedMessages *)result;
}


ISteamController * ISteamClient_::GetISteamController(HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamController_(this->internal->GetISteamController(hSteamUser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamController *)%p\n", result);

  return (ISteamController *)result;
}


ISteamUGC * ISteamClient_::GetISteamUGC(HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamUGC_(this->internal->GetISteamUGC(hSteamUser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamUGC *)%p\n", result);

  return (ISteamUGC *)result;
}


ISteamAppList * ISteamClient_::GetISteamAppList(HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamAppList_(this->internal->GetISteamAppList(hSteamUser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamAppList *)%p\n", result);

  return (ISteamAppList *)result;
}


ISteamMusic * ISteamClient_::GetISteamMusic(HSteamUser  hSteamuser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamMusic_(this->internal->GetISteamMusic(hSteamuser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamMusic *)%p\n", result);

  return (ISteamMusic *)result;
}


ISteamMusicRemote * ISteamClient_::GetISteamMusicRemote(HSteamUser  hSteamuser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamMusicRemote_(this->internal->GetISteamMusicRemote(hSteamuser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamMusicRemote *)%p\n", result);

  return (ISteamMusicRemote *)result;
}


ISteamHTMLSurface * ISteamClient_::GetISteamHTMLSurface(HSteamUser  hSteamuser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamHTMLSurface_(this->internal->GetISteamHTMLSurface(hSteamuser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamHTMLSurface *)%p\n", result);

  return (ISteamHTMLSurface *)result;
}


void  ISteamClient_::DEPRECATED_Set_SteamAPI_CPostAPIResultInProcess()
{
  TRACE("((ISteamClient *)%p)\n", this);
  
  
}


void  ISteamClient_::DEPRECATED_Remove_SteamAPI_CPostAPIResultInProcess()
{
  TRACE("((ISteamClient *)%p)\n", this);
  
  
}


void  ISteamClient_::Set_SteamAPI_CCheckCallbackRegisteredInProcess(SteamAPI_CheckCallbackRegistered_t  func)
{
  TRACE("((ISteamClient *)%p, (SteamAPI_CheckCallbackRegistered_t )%p)\n", this, func);
  
  
}


ISteamInventory * ISteamClient_::GetISteamInventory(HSteamUser  hSteamuser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamInventory_(this->internal->GetISteamInventory(hSteamuser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamInventory *)%p\n", result);

  return (ISteamInventory *)result;
}


ISteamVideo * ISteamClient_::GetISteamVideo(HSteamUser  hSteamuser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((ISteamClient *)%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", this, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamVideo_(this->internal->GetISteamVideo(hSteamuser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamVideo *)%p\n", result);

  return (ISteamVideo *)result;
}
ISteamClient_::ISteamClient_(ISteamClient * towrap)
{
  this->internal = towrap;
}

ISteamClient_::~ISteamClient_()
{
  delete this->internal;
}
