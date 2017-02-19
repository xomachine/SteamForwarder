#include "config.h"
#include "steam_api_flat.h"
#include "steam_api.h"
#include "autoclass/steam_api_.h"
#include "stdint.h"
#ifdef __cplusplus
extern "C" {
#endif
bool SteamAPI_Init_()
{
  TRACE("()\n");
  bool result = SteamAPI_Init();
  TRACE(" = (bool)%d\n", result);
  return result;
}
void SteamAPI_Shutdown_()
{
  TRACE("()\n");
  SteamAPI_Shutdown();
}
bool SteamAPI_RestartAppIfNecessary_(uint32 unOwnAppID)
{
  TRACE("((uint32)%d)\n", unOwnAppID);
  bool result = SteamAPI_RestartAppIfNecessary(unOwnAppID);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void SteamAPI_WriteMiniDump_(uint32 uStructuredExceptionCode, void* pvExceptionInfo, uint32 uBuildID)
{
  TRACE("((uint32)%d, (void*)%p, (uint32)%d)\n", uStructuredExceptionCode, pvExceptionInfo, uBuildID);
  SteamAPI_WriteMiniDump(uStructuredExceptionCode, pvExceptionInfo, uBuildID);
}
void SteamAPI_SetMiniDumpComment_(const char * pchMsg)
{
  TRACE("((const char *)\"%s\")\n", pchMsg);
  SteamAPI_SetMiniDumpComment(pchMsg);
}
ISteamClient_* saved_SteamClient;
ISteamClient * SteamClient_()
{
  TRACE("()\n");
  auto tmp = SteamClient();
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  if (!saved_SteamClient)  saved_SteamClient = new ISteamClient_();
  saved_SteamClient->internal = tmp;
  TRACE(" = (ISteamClient_*)%p wrapped[(ISteamClient *)%p]\n", saved_SteamClient, tmp);
  return (ISteamClient *)saved_SteamClient;
}
ISteamUser_* saved_SteamUser;
ISteamUser * SteamUser_()
{
  TRACE("()\n");
  auto tmp = SteamUser();
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  if (!saved_SteamUser)  saved_SteamUser = new ISteamUser_();
  saved_SteamUser->internal = tmp;
  TRACE(" = (ISteamUser_*)%p wrapped[(ISteamUser *)%p]\n", saved_SteamUser, tmp);
  return (ISteamUser *)saved_SteamUser;
}
ISteamFriends_* saved_SteamFriends;
ISteamFriends * SteamFriends_()
{
  TRACE("()\n");
  auto tmp = SteamFriends();
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  if (!saved_SteamFriends)  saved_SteamFriends = new ISteamFriends_();
  saved_SteamFriends->internal = tmp;
  TRACE(" = (ISteamFriends_*)%p wrapped[(ISteamFriends *)%p]\n", saved_SteamFriends, tmp);
  return (ISteamFriends *)saved_SteamFriends;
}
ISteamUtils_* saved_SteamUtils;
ISteamUtils * SteamUtils_()
{
  TRACE("()\n");
  auto tmp = SteamUtils();
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  if (!saved_SteamUtils)  saved_SteamUtils = new ISteamUtils_();
  saved_SteamUtils->internal = tmp;
  TRACE(" = (ISteamUtils_*)%p wrapped[(ISteamUtils *)%p]\n", saved_SteamUtils, tmp);
  return (ISteamUtils *)saved_SteamUtils;
}
ISteamMatchmaking_* saved_SteamMatchmaking;
ISteamMatchmaking * SteamMatchmaking_()
{
  TRACE("()\n");
  auto tmp = SteamMatchmaking();
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  if (!saved_SteamMatchmaking)  saved_SteamMatchmaking = new ISteamMatchmaking_();
  saved_SteamMatchmaking->internal = tmp;
  TRACE(" = (ISteamMatchmaking_*)%p wrapped[(ISteamMatchmaking *)%p]\n", saved_SteamMatchmaking, tmp);
  return (ISteamMatchmaking *)saved_SteamMatchmaking;
}
ISteamUserStats_* saved_SteamUserStats;
ISteamUserStats * SteamUserStats_()
{
  TRACE("()\n");
  auto tmp = SteamUserStats();
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  if (!saved_SteamUserStats)  saved_SteamUserStats = new ISteamUserStats_();
  saved_SteamUserStats->internal = tmp;
  TRACE(" = (ISteamUserStats_*)%p wrapped[(ISteamUserStats *)%p]\n", saved_SteamUserStats, tmp);
  return (ISteamUserStats *)saved_SteamUserStats;
}
ISteamApps_* saved_SteamApps;
ISteamApps * SteamApps_()
{
  TRACE("()\n");
  auto tmp = SteamApps();
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  if (!saved_SteamApps)  saved_SteamApps = new ISteamApps_();
  saved_SteamApps->internal = tmp;
  TRACE(" = (ISteamApps_*)%p wrapped[(ISteamApps *)%p]\n", saved_SteamApps, tmp);
  return (ISteamApps *)saved_SteamApps;
}
ISteamNetworking_* saved_SteamNetworking;
ISteamNetworking * SteamNetworking_()
{
  TRACE("()\n");
  auto tmp = SteamNetworking();
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  if (!saved_SteamNetworking)  saved_SteamNetworking = new ISteamNetworking_();
  saved_SteamNetworking->internal = tmp;
  TRACE(" = (ISteamNetworking_*)%p wrapped[(ISteamNetworking *)%p]\n", saved_SteamNetworking, tmp);
  return (ISteamNetworking *)saved_SteamNetworking;
}
ISteamMatchmakingServers_* saved_SteamMatchmakingServers;
ISteamMatchmakingServers * SteamMatchmakingServers_()
{
  TRACE("()\n");
  auto tmp = SteamMatchmakingServers();
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  if (!saved_SteamMatchmakingServers)  saved_SteamMatchmakingServers = new ISteamMatchmakingServers_();
  saved_SteamMatchmakingServers->internal = tmp;
  TRACE(" = (ISteamMatchmakingServers_*)%p wrapped[(ISteamMatchmakingServers *)%p]\n", saved_SteamMatchmakingServers, tmp);
  return (ISteamMatchmakingServers *)saved_SteamMatchmakingServers;
}
ISteamRemoteStorage_* saved_SteamRemoteStorage;
ISteamRemoteStorage * SteamRemoteStorage_()
{
  TRACE("()\n");
  auto tmp = SteamRemoteStorage();
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  if (!saved_SteamRemoteStorage)  saved_SteamRemoteStorage = new ISteamRemoteStorage_();
  saved_SteamRemoteStorage->internal = tmp;
  TRACE(" = (ISteamRemoteStorage_*)%p wrapped[(ISteamRemoteStorage *)%p]\n", saved_SteamRemoteStorage, tmp);
  return (ISteamRemoteStorage *)saved_SteamRemoteStorage;
}
ISteamScreenshots_* saved_SteamScreenshots;
ISteamScreenshots * SteamScreenshots_()
{
  TRACE("()\n");
  auto tmp = SteamScreenshots();
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  if (!saved_SteamScreenshots)  saved_SteamScreenshots = new ISteamScreenshots_();
  saved_SteamScreenshots->internal = tmp;
  TRACE(" = (ISteamScreenshots_*)%p wrapped[(ISteamScreenshots *)%p]\n", saved_SteamScreenshots, tmp);
  return (ISteamScreenshots *)saved_SteamScreenshots;
}
ISteamHTTP_* saved_SteamHTTP;
ISteamHTTP * SteamHTTP_()
{
  TRACE("()\n");
  auto tmp = SteamHTTP();
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  if (!saved_SteamHTTP)  saved_SteamHTTP = new ISteamHTTP_();
  saved_SteamHTTP->internal = tmp;
  TRACE(" = (ISteamHTTP_*)%p wrapped[(ISteamHTTP *)%p]\n", saved_SteamHTTP, tmp);
  return (ISteamHTTP *)saved_SteamHTTP;
}
ISteamUnifiedMessages_* saved_SteamUnifiedMessages;
ISteamUnifiedMessages * SteamUnifiedMessages_()
{
  TRACE("()\n");
  auto tmp = SteamUnifiedMessages();
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  if (!saved_SteamUnifiedMessages)  saved_SteamUnifiedMessages = new ISteamUnifiedMessages_();
  saved_SteamUnifiedMessages->internal = tmp;
  TRACE(" = (ISteamUnifiedMessages_*)%p wrapped[(ISteamUnifiedMessages *)%p]\n", saved_SteamUnifiedMessages, tmp);
  return (ISteamUnifiedMessages *)saved_SteamUnifiedMessages;
}
ISteamController_* saved_SteamController;
ISteamController * SteamController_()
{
  TRACE("()\n");
  auto tmp = SteamController();
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  if (!saved_SteamController)  saved_SteamController = new ISteamController_();
  saved_SteamController->internal = tmp;
  TRACE(" = (ISteamController_*)%p wrapped[(ISteamController *)%p]\n", saved_SteamController, tmp);
  return (ISteamController *)saved_SteamController;
}
ISteamUGC_* saved_SteamUGC;
ISteamUGC * SteamUGC_()
{
  TRACE("()\n");
  auto tmp = SteamUGC();
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  if (!saved_SteamUGC)  saved_SteamUGC = new ISteamUGC_();
  saved_SteamUGC->internal = tmp;
  TRACE(" = (ISteamUGC_*)%p wrapped[(ISteamUGC *)%p]\n", saved_SteamUGC, tmp);
  return (ISteamUGC *)saved_SteamUGC;
}
ISteamAppList_* saved_SteamAppList;
ISteamAppList * SteamAppList_()
{
  TRACE("()\n");
  auto tmp = SteamAppList();
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  if (!saved_SteamAppList)  saved_SteamAppList = new ISteamAppList_();
  saved_SteamAppList->internal = tmp;
  TRACE(" = (ISteamAppList_*)%p wrapped[(ISteamAppList *)%p]\n", saved_SteamAppList, tmp);
  return (ISteamAppList *)saved_SteamAppList;
}
ISteamMusic_* saved_SteamMusic;
ISteamMusic * SteamMusic_()
{
  TRACE("()\n");
  auto tmp = SteamMusic();
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  if (!saved_SteamMusic)  saved_SteamMusic = new ISteamMusic_();
  saved_SteamMusic->internal = tmp;
  TRACE(" = (ISteamMusic_*)%p wrapped[(ISteamMusic *)%p]\n", saved_SteamMusic, tmp);
  return (ISteamMusic *)saved_SteamMusic;
}
ISteamMusicRemote_* saved_SteamMusicRemote;
ISteamMusicRemote * SteamMusicRemote_()
{
  TRACE("()\n");
  auto tmp = SteamMusicRemote();
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  if (!saved_SteamMusicRemote)  saved_SteamMusicRemote = new ISteamMusicRemote_();
  saved_SteamMusicRemote->internal = tmp;
  TRACE(" = (ISteamMusicRemote_*)%p wrapped[(ISteamMusicRemote *)%p]\n", saved_SteamMusicRemote, tmp);
  return (ISteamMusicRemote *)saved_SteamMusicRemote;
}
ISteamHTMLSurface_* saved_SteamHTMLSurface;
ISteamHTMLSurface * SteamHTMLSurface_()
{
  TRACE("()\n");
  auto tmp = SteamHTMLSurface();
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  if (!saved_SteamHTMLSurface)  saved_SteamHTMLSurface = new ISteamHTMLSurface_();
  saved_SteamHTMLSurface->internal = tmp;
  TRACE(" = (ISteamHTMLSurface_*)%p wrapped[(ISteamHTMLSurface *)%p]\n", saved_SteamHTMLSurface, tmp);
  return (ISteamHTMLSurface *)saved_SteamHTMLSurface;
}
ISteamInventory_* saved_SteamInventory;
ISteamInventory * SteamInventory_()
{
  TRACE("()\n");
  auto tmp = SteamInventory();
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  if (!saved_SteamInventory)  saved_SteamInventory = new ISteamInventory_();
  saved_SteamInventory->internal = tmp;
  TRACE(" = (ISteamInventory_*)%p wrapped[(ISteamInventory *)%p]\n", saved_SteamInventory, tmp);
  return (ISteamInventory *)saved_SteamInventory;
}
ISteamVideo_* saved_SteamVideo;
ISteamVideo * SteamVideo_()
{
  TRACE("()\n");
  auto tmp = SteamVideo();
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  if (!saved_SteamVideo)  saved_SteamVideo = new ISteamVideo_();
  saved_SteamVideo->internal = tmp;
  TRACE(" = (ISteamVideo_*)%p wrapped[(ISteamVideo *)%p]\n", saved_SteamVideo, tmp);
  return (ISteamVideo *)saved_SteamVideo;
}
void SteamAPI_RunCallbacks_()
{
  SteamAPI_RunCallbacks();
}
bool SteamAPI_IsSteamRunning_()
{
  TRACE("()\n");
  bool result = SteamAPI_IsSteamRunning();
  TRACE(" = (bool)%d\n", result);
  return result;
}
void Steam_RunCallbacks_(HSteamPipe hSteamPipe, bool bGameServerCallbacks)
{
  Steam_RunCallbacks(hSteamPipe, bGameServerCallbacks);
}
void Steam_RegisterInterfaceFuncs_(void * hModule)
{
  TRACE("((void *)%p)\n", hModule);
  Steam_RegisterInterfaceFuncs(hModule);
}
HSteamUser Steam_GetHSteamUserCurrent_()
{
  TRACE("()\n");
  HSteamUser result = Steam_GetHSteamUserCurrent();
  TRACE(" = (HSteamUser)%p\n", result);
  return result;
}
const char * SteamAPI_GetSteamInstallPath_()
{
  TRACE("()\n");
  const char * result = SteamAPI_GetSteamInstallPath();
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
HSteamPipe SteamAPI_GetHSteamPipe_()
{
  TRACE("()\n");
  HSteamPipe result = SteamAPI_GetHSteamPipe();
  TRACE(" = (HSteamPipe)%p\n", result);
  return result;
}
void SteamAPI_SetTryCatchCallbacks_(bool bTryCatchCallbacks)
{
  TRACE("((bool)%d)\n", bTryCatchCallbacks);
  SteamAPI_SetTryCatchCallbacks(bTryCatchCallbacks);
}
HSteamPipe GetHSteamPipe_()
{
  TRACE("()\n");
  HSteamPipe result = GetHSteamPipe();
  TRACE(" = (HSteamPipe)%p\n", result);
  return result;
}
HSteamUser GetHSteamUser_()
{
  TRACE("()\n");
  HSteamUser result = GetHSteamUser();
  TRACE(" = (HSteamUser)%p\n", result);
  return result;
}
bool SteamAPI_InitSafe_()
{
  TRACE("()\n");
  bool result = SteamAPI_InitSafe();
  TRACE(" = (bool)%d\n", result);
  return result;
}
HSteamPipe SteamAPI_ISteamClient_CreateSteamPipe_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  HSteamPipe result = SteamAPI_ISteamClient_CreateSteamPipe(instancePtr);
  TRACE(" = (HSteamPipe)%p\n", result);
  return result;
}
bool SteamAPI_ISteamClient_BReleaseSteamPipe_(intptr_t instancePtr, HSteamPipe hSteamPipe)
{
  TRACE("((intptr_t)%p, (HSteamPipe)%p)\n", instancePtr, hSteamPipe);
  bool result = SteamAPI_ISteamClient_BReleaseSteamPipe(instancePtr, hSteamPipe);
  TRACE(" = (bool)%d\n", result);
  return result;
}
HSteamUser SteamAPI_ISteamClient_ConnectToGlobalUser_(intptr_t instancePtr, HSteamPipe hSteamPipe)
{
  TRACE("((intptr_t)%p, (HSteamPipe)%p)\n", instancePtr, hSteamPipe);
  HSteamUser result = SteamAPI_ISteamClient_ConnectToGlobalUser(instancePtr, hSteamPipe);
  TRACE(" = (HSteamUser)%p\n", result);
  return result;
}
HSteamUser SteamAPI_ISteamClient_CreateLocalUser_(intptr_t instancePtr, HSteamPipe * phSteamPipe, EAccountType eAccountType)
{
  TRACE("((intptr_t)%p, (HSteamPipe *)%p, (EAccountType)%p)\n", instancePtr, phSteamPipe, eAccountType);
  HSteamUser result = SteamAPI_ISteamClient_CreateLocalUser(instancePtr, phSteamPipe, eAccountType);
  TRACE(" = (HSteamUser)%p\n", result);
  return result;
}
void SteamAPI_ISteamClient_ReleaseUser_(intptr_t instancePtr, HSteamPipe hSteamPipe, HSteamUser hUser)
{
  TRACE("((intptr_t)%p, (HSteamPipe)%p, (HSteamUser)%p)\n", instancePtr, hSteamPipe, hUser);
  SteamAPI_ISteamClient_ReleaseUser(instancePtr, hSteamPipe, hUser);
}
class ISteamUser * SteamAPI_ISteamClient_GetISteamUser_(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto tmp = SteamAPI_ISteamClient_GetISteamUser(instancePtr, hSteamUser, hSteamPipe, pchVersion);
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  auto result = new class ISteamUser_();
  result->internal = tmp;
  TRACE(" = (class ISteamUser_*)%p wrapped[(class ISteamUser *)%p]\n", result, tmp);
  return (class ISteamUser *)result;
}
class ISteamGameServer * SteamAPI_ISteamClient_GetISteamGameServer_(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto tmp = SteamAPI_ISteamClient_GetISteamGameServer(instancePtr, hSteamUser, hSteamPipe, pchVersion);
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  auto result = new class ISteamGameServer_();
  result->internal = tmp;
  TRACE(" = (class ISteamGameServer_*)%p wrapped[(class ISteamGameServer *)%p]\n", result, tmp);
  return (class ISteamGameServer *)result;
}
void SteamAPI_ISteamClient_SetLocalIPBinding_(intptr_t instancePtr, uint32 unIP, uint16 usPort)
{
  TRACE("((intptr_t)%p, (uint32)%d, (uint16)%d)\n", instancePtr, unIP, usPort);
  SteamAPI_ISteamClient_SetLocalIPBinding(instancePtr, unIP, usPort);
}
class ISteamFriends * SteamAPI_ISteamClient_GetISteamFriends_(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto tmp = SteamAPI_ISteamClient_GetISteamFriends(instancePtr, hSteamUser, hSteamPipe, pchVersion);
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  auto result = new class ISteamFriends_();
  result->internal = tmp;
  TRACE(" = (class ISteamFriends_*)%p wrapped[(class ISteamFriends *)%p]\n", result, tmp);
  return (class ISteamFriends *)result;
}
class ISteamUtils * SteamAPI_ISteamClient_GetISteamUtils_(intptr_t instancePtr, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamPipe, pchVersion);
  auto tmp = SteamAPI_ISteamClient_GetISteamUtils(instancePtr, hSteamPipe, pchVersion);
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  auto result = new class ISteamUtils_();
  result->internal = tmp;
  TRACE(" = (class ISteamUtils_*)%p wrapped[(class ISteamUtils *)%p]\n", result, tmp);
  return (class ISteamUtils *)result;
}
class ISteamMatchmaking * SteamAPI_ISteamClient_GetISteamMatchmaking_(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto tmp = SteamAPI_ISteamClient_GetISteamMatchmaking(instancePtr, hSteamUser, hSteamPipe, pchVersion);
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  auto result = new class ISteamMatchmaking_();
  result->internal = tmp;
  TRACE(" = (class ISteamMatchmaking_*)%p wrapped[(class ISteamMatchmaking *)%p]\n", result, tmp);
  return (class ISteamMatchmaking *)result;
}
class ISteamMatchmakingServers * SteamAPI_ISteamClient_GetISteamMatchmakingServers_(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto tmp = SteamAPI_ISteamClient_GetISteamMatchmakingServers(instancePtr, hSteamUser, hSteamPipe, pchVersion);
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  auto result = new class ISteamMatchmakingServers_();
  result->internal = tmp;
  TRACE(" = (class ISteamMatchmakingServers_*)%p wrapped[(class ISteamMatchmakingServers *)%p]\n", result, tmp);
  return (class ISteamMatchmakingServers *)result;
}
void * SteamAPI_ISteamClient_GetISteamGenericInterface_(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  void * result = SteamAPI_ISteamClient_GetISteamGenericInterface(instancePtr, hSteamUser, hSteamPipe, pchVersion);
  TRACE(" = (void *)%p\n", result);
  return result;
}
class ISteamUserStats * SteamAPI_ISteamClient_GetISteamUserStats_(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto tmp = SteamAPI_ISteamClient_GetISteamUserStats(instancePtr, hSteamUser, hSteamPipe, pchVersion);
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  auto result = new class ISteamUserStats_();
  result->internal = tmp;
  TRACE(" = (class ISteamUserStats_*)%p wrapped[(class ISteamUserStats *)%p]\n", result, tmp);
  return (class ISteamUserStats *)result;
}
class ISteamGameServerStats * SteamAPI_ISteamClient_GetISteamGameServerStats_(intptr_t instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamuser, hSteamPipe, pchVersion);
  auto tmp = SteamAPI_ISteamClient_GetISteamGameServerStats(instancePtr, hSteamuser, hSteamPipe, pchVersion);
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  auto result = new class ISteamGameServerStats_();
  result->internal = tmp;
  TRACE(" = (class ISteamGameServerStats_*)%p wrapped[(class ISteamGameServerStats *)%p]\n", result, tmp);
  return (class ISteamGameServerStats *)result;
}
class ISteamApps * SteamAPI_ISteamClient_GetISteamApps_(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto tmp = SteamAPI_ISteamClient_GetISteamApps(instancePtr, hSteamUser, hSteamPipe, pchVersion);
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  auto result = new class ISteamApps_();
  result->internal = tmp;
  TRACE(" = (class ISteamApps_*)%p wrapped[(class ISteamApps *)%p]\n", result, tmp);
  return (class ISteamApps *)result;
}
class ISteamNetworking * SteamAPI_ISteamClient_GetISteamNetworking_(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto tmp = SteamAPI_ISteamClient_GetISteamNetworking(instancePtr, hSteamUser, hSteamPipe, pchVersion);
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  auto result = new class ISteamNetworking_();
  result->internal = tmp;
  TRACE(" = (class ISteamNetworking_*)%p wrapped[(class ISteamNetworking *)%p]\n", result, tmp);
  return (class ISteamNetworking *)result;
}
class ISteamRemoteStorage * SteamAPI_ISteamClient_GetISteamRemoteStorage_(intptr_t instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamuser, hSteamPipe, pchVersion);
  auto tmp = SteamAPI_ISteamClient_GetISteamRemoteStorage(instancePtr, hSteamuser, hSteamPipe, pchVersion);
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  auto result = new class ISteamRemoteStorage_();
  result->internal = tmp;
  TRACE(" = (class ISteamRemoteStorage_*)%p wrapped[(class ISteamRemoteStorage *)%p]\n", result, tmp);
  return (class ISteamRemoteStorage *)result;
}
class ISteamScreenshots * SteamAPI_ISteamClient_GetISteamScreenshots_(intptr_t instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamuser, hSteamPipe, pchVersion);
  auto tmp = SteamAPI_ISteamClient_GetISteamScreenshots(instancePtr, hSteamuser, hSteamPipe, pchVersion);
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  auto result = new class ISteamScreenshots_();
  result->internal = tmp;
  TRACE(" = (class ISteamScreenshots_*)%p wrapped[(class ISteamScreenshots *)%p]\n", result, tmp);
  return (class ISteamScreenshots *)result;
}
uint32 SteamAPI_ISteamClient_GetIPCCallCount_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  uint32 result = SteamAPI_ISteamClient_GetIPCCallCount(instancePtr);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
void SteamAPI_ISteamClient_SetWarningMessageHook_(intptr_t instancePtr, SteamAPIWarningMessageHook_t pFunction)
{
  TRACE("((intptr_t)%p, (SteamAPIWarningMessageHook_t)%p)\n", instancePtr, pFunction);
  SteamAPI_ISteamClient_SetWarningMessageHook(instancePtr, pFunction);
}
bool SteamAPI_ISteamClient_BShutdownIfAllPipesClosed_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamClient_BShutdownIfAllPipesClosed(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
class ISteamHTTP * SteamAPI_ISteamClient_GetISteamHTTP_(intptr_t instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamuser, hSteamPipe, pchVersion);
  auto tmp = SteamAPI_ISteamClient_GetISteamHTTP(instancePtr, hSteamuser, hSteamPipe, pchVersion);
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  auto result = new class ISteamHTTP_();
  result->internal = tmp;
  TRACE(" = (class ISteamHTTP_*)%p wrapped[(class ISteamHTTP *)%p]\n", result, tmp);
  return (class ISteamHTTP *)result;
}
class ISteamUnifiedMessages * SteamAPI_ISteamClient_GetISteamUnifiedMessages_(intptr_t instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamuser, hSteamPipe, pchVersion);
  auto tmp = SteamAPI_ISteamClient_GetISteamUnifiedMessages(instancePtr, hSteamuser, hSteamPipe, pchVersion);
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  auto result = new class ISteamUnifiedMessages_();
  result->internal = tmp;
  TRACE(" = (class ISteamUnifiedMessages_*)%p wrapped[(class ISteamUnifiedMessages *)%p]\n", result, tmp);
  return (class ISteamUnifiedMessages *)result;
}
class ISteamController * SteamAPI_ISteamClient_GetISteamController_(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto tmp = SteamAPI_ISteamClient_GetISteamController(instancePtr, hSteamUser, hSteamPipe, pchVersion);
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  auto result = new class ISteamController_();
  result->internal = tmp;
  TRACE(" = (class ISteamController_*)%p wrapped[(class ISteamController *)%p]\n", result, tmp);
  return (class ISteamController *)result;
}
class ISteamUGC * SteamAPI_ISteamClient_GetISteamUGC_(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto tmp = SteamAPI_ISteamClient_GetISteamUGC(instancePtr, hSteamUser, hSteamPipe, pchVersion);
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  auto result = new class ISteamUGC_();
  result->internal = tmp;
  TRACE(" = (class ISteamUGC_*)%p wrapped[(class ISteamUGC *)%p]\n", result, tmp);
  return (class ISteamUGC *)result;
}
class ISteamAppList * SteamAPI_ISteamClient_GetISteamAppList_(intptr_t instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto tmp = SteamAPI_ISteamClient_GetISteamAppList(instancePtr, hSteamUser, hSteamPipe, pchVersion);
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  auto result = new class ISteamAppList_();
  result->internal = tmp;
  TRACE(" = (class ISteamAppList_*)%p wrapped[(class ISteamAppList *)%p]\n", result, tmp);
  return (class ISteamAppList *)result;
}
class ISteamMusic * SteamAPI_ISteamClient_GetISteamMusic_(intptr_t instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamuser, hSteamPipe, pchVersion);
  auto tmp = SteamAPI_ISteamClient_GetISteamMusic(instancePtr, hSteamuser, hSteamPipe, pchVersion);
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  auto result = new class ISteamMusic_();
  result->internal = tmp;
  TRACE(" = (class ISteamMusic_*)%p wrapped[(class ISteamMusic *)%p]\n", result, tmp);
  return (class ISteamMusic *)result;
}
class ISteamMusicRemote * SteamAPI_ISteamClient_GetISteamMusicRemote_(intptr_t instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamuser, hSteamPipe, pchVersion);
  auto tmp = SteamAPI_ISteamClient_GetISteamMusicRemote(instancePtr, hSteamuser, hSteamPipe, pchVersion);
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  auto result = new class ISteamMusicRemote_();
  result->internal = tmp;
  TRACE(" = (class ISteamMusicRemote_*)%p wrapped[(class ISteamMusicRemote *)%p]\n", result, tmp);
  return (class ISteamMusicRemote *)result;
}
class ISteamHTMLSurface * SteamAPI_ISteamClient_GetISteamHTMLSurface_(intptr_t instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamuser, hSteamPipe, pchVersion);
  auto tmp = SteamAPI_ISteamClient_GetISteamHTMLSurface(instancePtr, hSteamuser, hSteamPipe, pchVersion);
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  auto result = new class ISteamHTMLSurface_();
  result->internal = tmp;
  TRACE(" = (class ISteamHTMLSurface_*)%p wrapped[(class ISteamHTMLSurface *)%p]\n", result, tmp);
  return (class ISteamHTMLSurface *)result;
}
class ISteamInventory * SteamAPI_ISteamClient_GetISteamInventory_(intptr_t instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamuser, hSteamPipe, pchVersion);
  auto tmp = SteamAPI_ISteamClient_GetISteamInventory(instancePtr, hSteamuser, hSteamPipe, pchVersion);
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  auto result = new class ISteamInventory_();
  result->internal = tmp;
  TRACE(" = (class ISteamInventory_*)%p wrapped[(class ISteamInventory *)%p]\n", result, tmp);
  return (class ISteamInventory *)result;
}
class ISteamVideo * SteamAPI_ISteamClient_GetISteamVideo_(intptr_t instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char * pchVersion)
{
  TRACE("((intptr_t)%p, (HSteamUser)%p, (HSteamPipe)%p, (const char *)\"%s\")\n", instancePtr, hSteamuser, hSteamPipe, pchVersion);
  auto tmp = SteamAPI_ISteamClient_GetISteamVideo(instancePtr, hSteamuser, hSteamPipe, pchVersion);
  if (!tmp) {
    TRACE("() = nil");
    return NULL;
  }
  auto result = new class ISteamVideo_();
  result->internal = tmp;
  TRACE(" = (class ISteamVideo_*)%p wrapped[(class ISteamVideo *)%p]\n", result, tmp);
  return (class ISteamVideo *)result;
}
HSteamUser SteamAPI_ISteamUser_GetHSteamUser_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  HSteamUser result = SteamAPI_ISteamUser_GetHSteamUser(instancePtr);
  TRACE(" = (HSteamUser)%p\n", result);
  return result;
}
bool SteamAPI_ISteamUser_BLoggedOn_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamUser_BLoggedOn(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
uint64 SteamAPI_ISteamUser_GetSteamID_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  uint64 result = SteamAPI_ISteamUser_GetSteamID(instancePtr);
  TRACE(" = (uint64)%d\n", result);
  return result;
}
int SteamAPI_ISteamUser_InitiateGameConnection_(intptr_t instancePtr, void * pAuthBlob, int cbMaxAuthBlob, class CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer, bool bSecure)
{
  TRACE("((intptr_t)%p, (void *)%p, (int)%d, (class CSteamID)%p, (uint32)%d, (uint16)%d, (bool)%d)\n", instancePtr, pAuthBlob, cbMaxAuthBlob, steamIDGameServer, unIPServer, usPortServer, bSecure);
  int result = SteamAPI_ISteamUser_InitiateGameConnection(instancePtr, pAuthBlob, cbMaxAuthBlob, steamIDGameServer, unIPServer, usPortServer, bSecure);
  TRACE(" = (int)%d\n", result);
  return result;
}
void SteamAPI_ISteamUser_TerminateGameConnection_(intptr_t instancePtr, uint32 unIPServer, uint16 usPortServer)
{
  TRACE("((intptr_t)%p, (uint32)%d, (uint16)%d)\n", instancePtr, unIPServer, usPortServer);
  SteamAPI_ISteamUser_TerminateGameConnection(instancePtr, unIPServer, usPortServer);
}
void SteamAPI_ISteamUser_TrackAppUsageEvent_(intptr_t instancePtr, class CGameID gameID, int eAppUsageEvent, const char * pchExtraInfo)
{
  TRACE("((intptr_t)%p, (class CGameID)%p, (int)%d, (const char *)\"%s\")\n", instancePtr, gameID, eAppUsageEvent, pchExtraInfo);
  SteamAPI_ISteamUser_TrackAppUsageEvent(instancePtr, gameID, eAppUsageEvent, pchExtraInfo);
}
bool SteamAPI_ISteamUser_GetUserDataFolder_(intptr_t instancePtr, char * pchBuffer, int cubBuffer)
{
  TRACE("((intptr_t)%p, (char *)%p, (int)%d)\n", instancePtr, pchBuffer, cubBuffer);
  bool result = SteamAPI_ISteamUser_GetUserDataFolder(instancePtr, pchBuffer, cubBuffer);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void SteamAPI_ISteamUser_StartVoiceRecording_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPI_ISteamUser_StartVoiceRecording(instancePtr);
}
void SteamAPI_ISteamUser_StopVoiceRecording_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPI_ISteamUser_StopVoiceRecording(instancePtr);
}
EVoiceResult SteamAPI_ISteamUser_GetAvailableVoice_(intptr_t instancePtr, uint32 * pcbCompressed, uint32 * pcbUncompressed, uint32 nUncompressedVoiceDesiredSampleRate)
{
  TRACE("((intptr_t)%p, (uint32 *)%p, (uint32 *)%p, (uint32)%d)\n", instancePtr, pcbCompressed, pcbUncompressed, nUncompressedVoiceDesiredSampleRate);
  EVoiceResult result = SteamAPI_ISteamUser_GetAvailableVoice(instancePtr, pcbCompressed, pcbUncompressed, nUncompressedVoiceDesiredSampleRate);
  TRACE(" = (EVoiceResult)%p\n", result);
  return result;
}
EVoiceResult SteamAPI_ISteamUser_GetVoice_(intptr_t instancePtr, bool bWantCompressed, void * pDestBuffer, uint32 cbDestBufferSize, uint32 * nBytesWritten, bool bWantUncompressed, void * pUncompressedDestBuffer, uint32 cbUncompressedDestBufferSize, uint32 * nUncompressBytesWritten, uint32 nUncompressedVoiceDesiredSampleRate)
{
  TRACE("((intptr_t)%p, (bool)%d, (void *)%p, (uint32)%d, (uint32 *)%p, (bool)%d, (void *)%p, (uint32)%d, (uint32 *)%p, (uint32)%d)\n", instancePtr, bWantCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, bWantUncompressed, pUncompressedDestBuffer, cbUncompressedDestBufferSize, nUncompressBytesWritten, nUncompressedVoiceDesiredSampleRate);
  EVoiceResult result = SteamAPI_ISteamUser_GetVoice(instancePtr, bWantCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, bWantUncompressed, pUncompressedDestBuffer, cbUncompressedDestBufferSize, nUncompressBytesWritten, nUncompressedVoiceDesiredSampleRate);
  TRACE(" = (EVoiceResult)%p\n", result);
  return result;
}
EVoiceResult SteamAPI_ISteamUser_DecompressVoice_(intptr_t instancePtr, const void * pCompressed, uint32 cbCompressed, void * pDestBuffer, uint32 cbDestBufferSize, uint32 * nBytesWritten, uint32 nDesiredSampleRate)
{
  TRACE("((intptr_t)%p, (const void *)%p, (uint32)%d, (void *)%p, (uint32)%d, (uint32 *)%p, (uint32)%d)\n", instancePtr, pCompressed, cbCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, nDesiredSampleRate);
  EVoiceResult result = SteamAPI_ISteamUser_DecompressVoice(instancePtr, pCompressed, cbCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, nDesiredSampleRate);
  TRACE(" = (EVoiceResult)%p\n", result);
  return result;
}
uint32 SteamAPI_ISteamUser_GetVoiceOptimalSampleRate_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  uint32 result = SteamAPI_ISteamUser_GetVoiceOptimalSampleRate(instancePtr);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
HAuthTicket SteamAPI_ISteamUser_GetAuthSessionTicket_(intptr_t instancePtr, void * pTicket, int cbMaxTicket, uint32 * pcbTicket)
{
  TRACE("((intptr_t)%p, (void *)%p, (int)%d, (uint32 *)%p)\n", instancePtr, pTicket, cbMaxTicket, pcbTicket);
  HAuthTicket result = SteamAPI_ISteamUser_GetAuthSessionTicket(instancePtr, pTicket, cbMaxTicket, pcbTicket);
  TRACE(" = (HAuthTicket)%p\n", result);
  return result;
}
EBeginAuthSessionResult SteamAPI_ISteamUser_BeginAuthSession_(intptr_t instancePtr, const void * pAuthTicket, int cbAuthTicket, class CSteamID steamID)
{
  TRACE("((intptr_t)%p, (const void *)%p, (int)%d, (class CSteamID)%p)\n", instancePtr, pAuthTicket, cbAuthTicket, steamID);
  EBeginAuthSessionResult result = SteamAPI_ISteamUser_BeginAuthSession(instancePtr, pAuthTicket, cbAuthTicket, steamID);
  TRACE(" = (EBeginAuthSessionResult)%p\n", result);
  return result;
}
void SteamAPI_ISteamUser_EndAuthSession_(intptr_t instancePtr, class CSteamID steamID)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamID);
  SteamAPI_ISteamUser_EndAuthSession(instancePtr, steamID);
}
void SteamAPI_ISteamUser_CancelAuthTicket_(intptr_t instancePtr, HAuthTicket hAuthTicket)
{
  TRACE("((intptr_t)%p, (HAuthTicket)%p)\n", instancePtr, hAuthTicket);
  SteamAPI_ISteamUser_CancelAuthTicket(instancePtr, hAuthTicket);
}
EUserHasLicenseForAppResult SteamAPI_ISteamUser_UserHasLicenseForApp_(intptr_t instancePtr, class CSteamID steamID, AppId_t appID)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (AppId_t)%p)\n", instancePtr, steamID, appID);
  EUserHasLicenseForAppResult result = SteamAPI_ISteamUser_UserHasLicenseForApp(instancePtr, steamID, appID);
  TRACE(" = (EUserHasLicenseForAppResult)%p\n", result);
  return result;
}
bool SteamAPI_ISteamUser_BIsBehindNAT_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamUser_BIsBehindNAT(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void SteamAPI_ISteamUser_AdvertiseGame_(intptr_t instancePtr, class CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (uint32)%d, (uint16)%d)\n", instancePtr, steamIDGameServer, unIPServer, usPortServer);
  SteamAPI_ISteamUser_AdvertiseGame(instancePtr, steamIDGameServer, unIPServer, usPortServer);
}
SteamAPICall_t SteamAPI_ISteamUser_RequestEncryptedAppTicket_(intptr_t instancePtr, void * pDataToInclude, int cbDataToInclude)
{
  TRACE("((intptr_t)%p, (void *)%p, (int)%d)\n", instancePtr, pDataToInclude, cbDataToInclude);
  SteamAPICall_t result = SteamAPI_ISteamUser_RequestEncryptedAppTicket(instancePtr, pDataToInclude, cbDataToInclude);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
bool SteamAPI_ISteamUser_GetEncryptedAppTicket_(intptr_t instancePtr, void * pTicket, int cbMaxTicket, uint32 * pcbTicket)
{
  TRACE("((intptr_t)%p, (void *)%p, (int)%d, (uint32 *)%p)\n", instancePtr, pTicket, cbMaxTicket, pcbTicket);
  bool result = SteamAPI_ISteamUser_GetEncryptedAppTicket(instancePtr, pTicket, cbMaxTicket, pcbTicket);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int SteamAPI_ISteamUser_GetGameBadgeLevel_(intptr_t instancePtr, int nSeries, bool bFoil)
{
  TRACE("((intptr_t)%p, (int)%d, (bool)%d)\n", instancePtr, nSeries, bFoil);
  int result = SteamAPI_ISteamUser_GetGameBadgeLevel(instancePtr, nSeries, bFoil);
  TRACE(" = (int)%d\n", result);
  return result;
}
int SteamAPI_ISteamUser_GetPlayerSteamLevel_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  int result = SteamAPI_ISteamUser_GetPlayerSteamLevel(instancePtr);
  TRACE(" = (int)%d\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamUser_RequestStoreAuthURL_(intptr_t instancePtr, const char * pchRedirectURL)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchRedirectURL);
  SteamAPICall_t result = SteamAPI_ISteamUser_RequestStoreAuthURL(instancePtr, pchRedirectURL);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
const char * SteamAPI_ISteamFriends_GetPersonaName_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  const char * result = SteamAPI_ISteamFriends_GetPersonaName(instancePtr);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamFriends_SetPersonaName_(intptr_t instancePtr, const char * pchPersonaName)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchPersonaName);
  SteamAPICall_t result = SteamAPI_ISteamFriends_SetPersonaName(instancePtr, pchPersonaName);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
EPersonaState SteamAPI_ISteamFriends_GetPersonaState_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  EPersonaState result = SteamAPI_ISteamFriends_GetPersonaState(instancePtr);
  TRACE(" = (EPersonaState)%p\n", result);
  return result;
}
int SteamAPI_ISteamFriends_GetFriendCount_(intptr_t instancePtr, int iFriendFlags)
{
  TRACE("((intptr_t)%p, (int)%d)\n", instancePtr, iFriendFlags);
  int result = SteamAPI_ISteamFriends_GetFriendCount(instancePtr, iFriendFlags);
  TRACE(" = (int)%d\n", result);
  return result;
}
uint64 SteamAPI_ISteamFriends_GetFriendByIndex_(intptr_t instancePtr, int iFriend, int iFriendFlags)
{
  TRACE("((intptr_t)%p, (int)%d, (int)%d)\n", instancePtr, iFriend, iFriendFlags);
  uint64 result = SteamAPI_ISteamFriends_GetFriendByIndex(instancePtr, iFriend, iFriendFlags);
  TRACE(" = (uint64)%d\n", result);
  return result;
}
EFriendRelationship SteamAPI_ISteamFriends_GetFriendRelationship_(intptr_t instancePtr, class CSteamID steamIDFriend)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDFriend);
  EFriendRelationship result = SteamAPI_ISteamFriends_GetFriendRelationship(instancePtr, steamIDFriend);
  TRACE(" = (EFriendRelationship)%p\n", result);
  return result;
}
EPersonaState SteamAPI_ISteamFriends_GetFriendPersonaState_(intptr_t instancePtr, class CSteamID steamIDFriend)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDFriend);
  EPersonaState result = SteamAPI_ISteamFriends_GetFriendPersonaState(instancePtr, steamIDFriend);
  TRACE(" = (EPersonaState)%p\n", result);
  return result;
}
const char * SteamAPI_ISteamFriends_GetFriendPersonaName_(intptr_t instancePtr, class CSteamID steamIDFriend)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDFriend);
  const char * result = SteamAPI_ISteamFriends_GetFriendPersonaName(instancePtr, steamIDFriend);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
bool SteamAPI_ISteamFriends_GetFriendGamePlayed_(intptr_t instancePtr, class CSteamID steamIDFriend, struct FriendGameInfo_t * pFriendGameInfo)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (struct FriendGameInfo_t *)%p)\n", instancePtr, steamIDFriend, pFriendGameInfo);
  bool result = SteamAPI_ISteamFriends_GetFriendGamePlayed(instancePtr, steamIDFriend, pFriendGameInfo);
  TRACE(" = (bool)%d\n", result);
  return result;
}
const char * SteamAPI_ISteamFriends_GetFriendPersonaNameHistory_(intptr_t instancePtr, class CSteamID steamIDFriend, int iPersonaName)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (int)%d)\n", instancePtr, steamIDFriend, iPersonaName);
  const char * result = SteamAPI_ISteamFriends_GetFriendPersonaNameHistory(instancePtr, steamIDFriend, iPersonaName);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
int SteamAPI_ISteamFriends_GetFriendSteamLevel_(intptr_t instancePtr, class CSteamID steamIDFriend)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDFriend);
  int result = SteamAPI_ISteamFriends_GetFriendSteamLevel(instancePtr, steamIDFriend);
  TRACE(" = (int)%d\n", result);
  return result;
}
const char * SteamAPI_ISteamFriends_GetPlayerNickname_(intptr_t instancePtr, class CSteamID steamIDPlayer)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDPlayer);
  const char * result = SteamAPI_ISteamFriends_GetPlayerNickname(instancePtr, steamIDPlayer);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
int SteamAPI_ISteamFriends_GetFriendsGroupCount_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  int result = SteamAPI_ISteamFriends_GetFriendsGroupCount(instancePtr);
  TRACE(" = (int)%d\n", result);
  return result;
}
FriendsGroupID_t SteamAPI_ISteamFriends_GetFriendsGroupIDByIndex_(intptr_t instancePtr, int iFG)
{
  TRACE("((intptr_t)%p, (int)%d)\n", instancePtr, iFG);
  FriendsGroupID_t result = SteamAPI_ISteamFriends_GetFriendsGroupIDByIndex(instancePtr, iFG);
  TRACE(" = (FriendsGroupID_t)%p\n", result);
  return result;
}
const char * SteamAPI_ISteamFriends_GetFriendsGroupName_(intptr_t instancePtr, FriendsGroupID_t friendsGroupID)
{
  TRACE("((intptr_t)%p, (FriendsGroupID_t)%p)\n", instancePtr, friendsGroupID);
  const char * result = SteamAPI_ISteamFriends_GetFriendsGroupName(instancePtr, friendsGroupID);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
int SteamAPI_ISteamFriends_GetFriendsGroupMembersCount_(intptr_t instancePtr, FriendsGroupID_t friendsGroupID)
{
  TRACE("((intptr_t)%p, (FriendsGroupID_t)%p)\n", instancePtr, friendsGroupID);
  int result = SteamAPI_ISteamFriends_GetFriendsGroupMembersCount(instancePtr, friendsGroupID);
  TRACE(" = (int)%d\n", result);
  return result;
}
void SteamAPI_ISteamFriends_GetFriendsGroupMembersList_(intptr_t instancePtr, FriendsGroupID_t friendsGroupID, class CSteamID * pOutSteamIDMembers, int nMembersCount)
{
  TRACE("((intptr_t)%p, (FriendsGroupID_t)%p, (class CSteamID *)%p, (int)%d)\n", instancePtr, friendsGroupID, pOutSteamIDMembers, nMembersCount);
  SteamAPI_ISteamFriends_GetFriendsGroupMembersList(instancePtr, friendsGroupID, pOutSteamIDMembers, nMembersCount);
}
bool SteamAPI_ISteamFriends_HasFriend_(intptr_t instancePtr, class CSteamID steamIDFriend, int iFriendFlags)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (int)%d)\n", instancePtr, steamIDFriend, iFriendFlags);
  bool result = SteamAPI_ISteamFriends_HasFriend(instancePtr, steamIDFriend, iFriendFlags);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int SteamAPI_ISteamFriends_GetClanCount_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  int result = SteamAPI_ISteamFriends_GetClanCount(instancePtr);
  TRACE(" = (int)%d\n", result);
  return result;
}
uint64 SteamAPI_ISteamFriends_GetClanByIndex_(intptr_t instancePtr, int iClan)
{
  TRACE("((intptr_t)%p, (int)%d)\n", instancePtr, iClan);
  uint64 result = SteamAPI_ISteamFriends_GetClanByIndex(instancePtr, iClan);
  TRACE(" = (uint64)%d\n", result);
  return result;
}
const char * SteamAPI_ISteamFriends_GetClanName_(intptr_t instancePtr, class CSteamID steamIDClan)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDClan);
  const char * result = SteamAPI_ISteamFriends_GetClanName(instancePtr, steamIDClan);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
const char * SteamAPI_ISteamFriends_GetClanTag_(intptr_t instancePtr, class CSteamID steamIDClan)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDClan);
  const char * result = SteamAPI_ISteamFriends_GetClanTag(instancePtr, steamIDClan);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
bool SteamAPI_ISteamFriends_GetClanActivityCounts_(intptr_t instancePtr, class CSteamID steamIDClan, int * pnOnline, int * pnInGame, int * pnChatting)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (int *)%p, (int *)%p, (int *)%p)\n", instancePtr, steamIDClan, pnOnline, pnInGame, pnChatting);
  bool result = SteamAPI_ISteamFriends_GetClanActivityCounts(instancePtr, steamIDClan, pnOnline, pnInGame, pnChatting);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamFriends_DownloadClanActivityCounts_(intptr_t instancePtr, class CSteamID * psteamIDClans, int cClansToRequest)
{
  TRACE("((intptr_t)%p, (class CSteamID *)%p, (int)%d)\n", instancePtr, psteamIDClans, cClansToRequest);
  SteamAPICall_t result = SteamAPI_ISteamFriends_DownloadClanActivityCounts(instancePtr, psteamIDClans, cClansToRequest);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
int SteamAPI_ISteamFriends_GetFriendCountFromSource_(intptr_t instancePtr, class CSteamID steamIDSource)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDSource);
  int result = SteamAPI_ISteamFriends_GetFriendCountFromSource(instancePtr, steamIDSource);
  TRACE(" = (int)%d\n", result);
  return result;
}
uint64 SteamAPI_ISteamFriends_GetFriendFromSourceByIndex_(intptr_t instancePtr, class CSteamID steamIDSource, int iFriend)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (int)%d)\n", instancePtr, steamIDSource, iFriend);
  uint64 result = SteamAPI_ISteamFriends_GetFriendFromSourceByIndex(instancePtr, steamIDSource, iFriend);
  TRACE(" = (uint64)%d\n", result);
  return result;
}
bool SteamAPI_ISteamFriends_IsUserInSource_(intptr_t instancePtr, class CSteamID steamIDUser, class CSteamID steamIDSource)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (class CSteamID)%p)\n", instancePtr, steamIDUser, steamIDSource);
  bool result = SteamAPI_ISteamFriends_IsUserInSource(instancePtr, steamIDUser, steamIDSource);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void SteamAPI_ISteamFriends_SetInGameVoiceSpeaking_(intptr_t instancePtr, class CSteamID steamIDUser, bool bSpeaking)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (bool)%d)\n", instancePtr, steamIDUser, bSpeaking);
  SteamAPI_ISteamFriends_SetInGameVoiceSpeaking(instancePtr, steamIDUser, bSpeaking);
}
void SteamAPI_ISteamFriends_ActivateGameOverlay_(intptr_t instancePtr, const char * pchDialog)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchDialog);
  SteamAPI_ISteamFriends_ActivateGameOverlay(instancePtr, pchDialog);
}
void SteamAPI_ISteamFriends_ActivateGameOverlayToUser_(intptr_t instancePtr, const char * pchDialog, class CSteamID steamID)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (class CSteamID)%p)\n", instancePtr, pchDialog, steamID);
  SteamAPI_ISteamFriends_ActivateGameOverlayToUser(instancePtr, pchDialog, steamID);
}
void SteamAPI_ISteamFriends_ActivateGameOverlayToWebPage_(intptr_t instancePtr, const char * pchURL)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchURL);
  SteamAPI_ISteamFriends_ActivateGameOverlayToWebPage(instancePtr, pchURL);
}
void SteamAPI_ISteamFriends_ActivateGameOverlayToStore_(intptr_t instancePtr, AppId_t nAppID, EOverlayToStoreFlag eFlag)
{
  TRACE("((intptr_t)%p, (AppId_t)%p, (EOverlayToStoreFlag)%p)\n", instancePtr, nAppID, eFlag);
  SteamAPI_ISteamFriends_ActivateGameOverlayToStore(instancePtr, nAppID, eFlag);
}
void SteamAPI_ISteamFriends_SetPlayedWith_(intptr_t instancePtr, class CSteamID steamIDUserPlayedWith)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDUserPlayedWith);
  SteamAPI_ISteamFriends_SetPlayedWith(instancePtr, steamIDUserPlayedWith);
}
void SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialog_(intptr_t instancePtr, class CSteamID steamIDLobby)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDLobby);
  SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialog(instancePtr, steamIDLobby);
}
int SteamAPI_ISteamFriends_GetSmallFriendAvatar_(intptr_t instancePtr, class CSteamID steamIDFriend)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDFriend);
  int result = SteamAPI_ISteamFriends_GetSmallFriendAvatar(instancePtr, steamIDFriend);
  TRACE(" = (int)%d\n", result);
  return result;
}
int SteamAPI_ISteamFriends_GetMediumFriendAvatar_(intptr_t instancePtr, class CSteamID steamIDFriend)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDFriend);
  int result = SteamAPI_ISteamFriends_GetMediumFriendAvatar(instancePtr, steamIDFriend);
  TRACE(" = (int)%d\n", result);
  return result;
}
int SteamAPI_ISteamFriends_GetLargeFriendAvatar_(intptr_t instancePtr, class CSteamID steamIDFriend)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDFriend);
  int result = SteamAPI_ISteamFriends_GetLargeFriendAvatar(instancePtr, steamIDFriend);
  TRACE(" = (int)%d\n", result);
  return result;
}
bool SteamAPI_ISteamFriends_RequestUserInformation_(intptr_t instancePtr, class CSteamID steamIDUser, bool bRequireNameOnly)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (bool)%d)\n", instancePtr, steamIDUser, bRequireNameOnly);
  bool result = SteamAPI_ISteamFriends_RequestUserInformation(instancePtr, steamIDUser, bRequireNameOnly);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamFriends_RequestClanOfficerList_(intptr_t instancePtr, class CSteamID steamIDClan)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDClan);
  SteamAPICall_t result = SteamAPI_ISteamFriends_RequestClanOfficerList(instancePtr, steamIDClan);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
uint64 SteamAPI_ISteamFriends_GetClanOwner_(intptr_t instancePtr, class CSteamID steamIDClan)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDClan);
  uint64 result = SteamAPI_ISteamFriends_GetClanOwner(instancePtr, steamIDClan);
  TRACE(" = (uint64)%d\n", result);
  return result;
}
int SteamAPI_ISteamFriends_GetClanOfficerCount_(intptr_t instancePtr, class CSteamID steamIDClan)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDClan);
  int result = SteamAPI_ISteamFriends_GetClanOfficerCount(instancePtr, steamIDClan);
  TRACE(" = (int)%d\n", result);
  return result;
}
uint64 SteamAPI_ISteamFriends_GetClanOfficerByIndex_(intptr_t instancePtr, class CSteamID steamIDClan, int iOfficer)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (int)%d)\n", instancePtr, steamIDClan, iOfficer);
  uint64 result = SteamAPI_ISteamFriends_GetClanOfficerByIndex(instancePtr, steamIDClan, iOfficer);
  TRACE(" = (uint64)%d\n", result);
  return result;
}
uint32 SteamAPI_ISteamFriends_GetUserRestrictions_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  uint32 result = SteamAPI_ISteamFriends_GetUserRestrictions(instancePtr);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
bool SteamAPI_ISteamFriends_SetRichPresence_(intptr_t instancePtr, const char * pchKey, const char * pchValue)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (const char *)\"%s\")\n", instancePtr, pchKey, pchValue);
  bool result = SteamAPI_ISteamFriends_SetRichPresence(instancePtr, pchKey, pchValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void SteamAPI_ISteamFriends_ClearRichPresence_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPI_ISteamFriends_ClearRichPresence(instancePtr);
}
const char * SteamAPI_ISteamFriends_GetFriendRichPresence_(intptr_t instancePtr, class CSteamID steamIDFriend, const char * pchKey)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const char *)\"%s\")\n", instancePtr, steamIDFriend, pchKey);
  const char * result = SteamAPI_ISteamFriends_GetFriendRichPresence(instancePtr, steamIDFriend, pchKey);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
int SteamAPI_ISteamFriends_GetFriendRichPresenceKeyCount_(intptr_t instancePtr, class CSteamID steamIDFriend)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDFriend);
  int result = SteamAPI_ISteamFriends_GetFriendRichPresenceKeyCount(instancePtr, steamIDFriend);
  TRACE(" = (int)%d\n", result);
  return result;
}
const char * SteamAPI_ISteamFriends_GetFriendRichPresenceKeyByIndex_(intptr_t instancePtr, class CSteamID steamIDFriend, int iKey)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (int)%d)\n", instancePtr, steamIDFriend, iKey);
  const char * result = SteamAPI_ISteamFriends_GetFriendRichPresenceKeyByIndex(instancePtr, steamIDFriend, iKey);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
void SteamAPI_ISteamFriends_RequestFriendRichPresence_(intptr_t instancePtr, class CSteamID steamIDFriend)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDFriend);
  SteamAPI_ISteamFriends_RequestFriendRichPresence(instancePtr, steamIDFriend);
}
bool SteamAPI_ISteamFriends_InviteUserToGame_(intptr_t instancePtr, class CSteamID steamIDFriend, const char * pchConnectString)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const char *)\"%s\")\n", instancePtr, steamIDFriend, pchConnectString);
  bool result = SteamAPI_ISteamFriends_InviteUserToGame(instancePtr, steamIDFriend, pchConnectString);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int SteamAPI_ISteamFriends_GetCoplayFriendCount_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  int result = SteamAPI_ISteamFriends_GetCoplayFriendCount(instancePtr);
  TRACE(" = (int)%d\n", result);
  return result;
}
uint64 SteamAPI_ISteamFriends_GetCoplayFriend_(intptr_t instancePtr, int iCoplayFriend)
{
  TRACE("((intptr_t)%p, (int)%d)\n", instancePtr, iCoplayFriend);
  uint64 result = SteamAPI_ISteamFriends_GetCoplayFriend(instancePtr, iCoplayFriend);
  TRACE(" = (uint64)%d\n", result);
  return result;
}
int SteamAPI_ISteamFriends_GetFriendCoplayTime_(intptr_t instancePtr, class CSteamID steamIDFriend)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDFriend);
  int result = SteamAPI_ISteamFriends_GetFriendCoplayTime(instancePtr, steamIDFriend);
  TRACE(" = (int)%d\n", result);
  return result;
}
AppId_t SteamAPI_ISteamFriends_GetFriendCoplayGame_(intptr_t instancePtr, class CSteamID steamIDFriend)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDFriend);
  AppId_t result = SteamAPI_ISteamFriends_GetFriendCoplayGame(instancePtr, steamIDFriend);
  TRACE(" = (AppId_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamFriends_JoinClanChatRoom_(intptr_t instancePtr, class CSteamID steamIDClan)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDClan);
  SteamAPICall_t result = SteamAPI_ISteamFriends_JoinClanChatRoom(instancePtr, steamIDClan);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
bool SteamAPI_ISteamFriends_LeaveClanChatRoom_(intptr_t instancePtr, class CSteamID steamIDClan)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDClan);
  bool result = SteamAPI_ISteamFriends_LeaveClanChatRoom(instancePtr, steamIDClan);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int SteamAPI_ISteamFriends_GetClanChatMemberCount_(intptr_t instancePtr, class CSteamID steamIDClan)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDClan);
  int result = SteamAPI_ISteamFriends_GetClanChatMemberCount(instancePtr, steamIDClan);
  TRACE(" = (int)%d\n", result);
  return result;
}
uint64 SteamAPI_ISteamFriends_GetChatMemberByIndex_(intptr_t instancePtr, class CSteamID steamIDClan, int iUser)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (int)%d)\n", instancePtr, steamIDClan, iUser);
  uint64 result = SteamAPI_ISteamFriends_GetChatMemberByIndex(instancePtr, steamIDClan, iUser);
  TRACE(" = (uint64)%d\n", result);
  return result;
}
bool SteamAPI_ISteamFriends_SendClanChatMessage_(intptr_t instancePtr, class CSteamID steamIDClanChat, const char * pchText)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const char *)\"%s\")\n", instancePtr, steamIDClanChat, pchText);
  bool result = SteamAPI_ISteamFriends_SendClanChatMessage(instancePtr, steamIDClanChat, pchText);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int SteamAPI_ISteamFriends_GetClanChatMessage_(intptr_t instancePtr, class CSteamID steamIDClanChat, int iMessage, void * prgchText, int cchTextMax, EChatEntryType * peChatEntryType, class CSteamID * psteamidChatter)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (int)%d, (void *)%p, (int)%d, (EChatEntryType *)%p, (class CSteamID *)%p)\n", instancePtr, steamIDClanChat, iMessage, prgchText, cchTextMax, peChatEntryType, psteamidChatter);
  int result = SteamAPI_ISteamFriends_GetClanChatMessage(instancePtr, steamIDClanChat, iMessage, prgchText, cchTextMax, peChatEntryType, psteamidChatter);
  TRACE(" = (int)%d\n", result);
  return result;
}
bool SteamAPI_ISteamFriends_IsClanChatAdmin_(intptr_t instancePtr, class CSteamID steamIDClanChat, class CSteamID steamIDUser)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (class CSteamID)%p)\n", instancePtr, steamIDClanChat, steamIDUser);
  bool result = SteamAPI_ISteamFriends_IsClanChatAdmin(instancePtr, steamIDClanChat, steamIDUser);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamFriends_IsClanChatWindowOpenInSteam_(intptr_t instancePtr, class CSteamID steamIDClanChat)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDClanChat);
  bool result = SteamAPI_ISteamFriends_IsClanChatWindowOpenInSteam(instancePtr, steamIDClanChat);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamFriends_OpenClanChatWindowInSteam_(intptr_t instancePtr, class CSteamID steamIDClanChat)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDClanChat);
  bool result = SteamAPI_ISteamFriends_OpenClanChatWindowInSteam(instancePtr, steamIDClanChat);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamFriends_CloseClanChatWindowInSteam_(intptr_t instancePtr, class CSteamID steamIDClanChat)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDClanChat);
  bool result = SteamAPI_ISteamFriends_CloseClanChatWindowInSteam(instancePtr, steamIDClanChat);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamFriends_SetListenForFriendsMessages_(intptr_t instancePtr, bool bInterceptEnabled)
{
  TRACE("((intptr_t)%p, (bool)%d)\n", instancePtr, bInterceptEnabled);
  bool result = SteamAPI_ISteamFriends_SetListenForFriendsMessages(instancePtr, bInterceptEnabled);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamFriends_ReplyToFriendMessage_(intptr_t instancePtr, class CSteamID steamIDFriend, const char * pchMsgToSend)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const char *)\"%s\")\n", instancePtr, steamIDFriend, pchMsgToSend);
  bool result = SteamAPI_ISteamFriends_ReplyToFriendMessage(instancePtr, steamIDFriend, pchMsgToSend);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int SteamAPI_ISteamFriends_GetFriendMessage_(intptr_t instancePtr, class CSteamID steamIDFriend, int iMessageID, void * pvData, int cubData, EChatEntryType * peChatEntryType)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (int)%d, (void *)%p, (int)%d, (EChatEntryType *)%p)\n", instancePtr, steamIDFriend, iMessageID, pvData, cubData, peChatEntryType);
  int result = SteamAPI_ISteamFriends_GetFriendMessage(instancePtr, steamIDFriend, iMessageID, pvData, cubData, peChatEntryType);
  TRACE(" = (int)%d\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamFriends_GetFollowerCount_(intptr_t instancePtr, class CSteamID steamID)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamID);
  SteamAPICall_t result = SteamAPI_ISteamFriends_GetFollowerCount(instancePtr, steamID);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamFriends_IsFollowing_(intptr_t instancePtr, class CSteamID steamID)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamID);
  SteamAPICall_t result = SteamAPI_ISteamFriends_IsFollowing(instancePtr, steamID);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamFriends_EnumerateFollowingList_(intptr_t instancePtr, uint32 unStartIndex)
{
  TRACE("((intptr_t)%p, (uint32)%d)\n", instancePtr, unStartIndex);
  SteamAPICall_t result = SteamAPI_ISteamFriends_EnumerateFollowingList(instancePtr, unStartIndex);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
uint32 SteamAPI_ISteamUtils_GetSecondsSinceAppActive_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  uint32 result = SteamAPI_ISteamUtils_GetSecondsSinceAppActive(instancePtr);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
uint32 SteamAPI_ISteamUtils_GetSecondsSinceComputerActive_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  uint32 result = SteamAPI_ISteamUtils_GetSecondsSinceComputerActive(instancePtr);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
EUniverse SteamAPI_ISteamUtils_GetConnectedUniverse_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  EUniverse result = SteamAPI_ISteamUtils_GetConnectedUniverse(instancePtr);
  TRACE(" = (EUniverse)%p\n", result);
  return result;
}
uint32 SteamAPI_ISteamUtils_GetServerRealTime_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  uint32 result = SteamAPI_ISteamUtils_GetServerRealTime(instancePtr);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
const char * SteamAPI_ISteamUtils_GetIPCountry_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  const char * result = SteamAPI_ISteamUtils_GetIPCountry(instancePtr);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
bool SteamAPI_ISteamUtils_GetImageSize_(intptr_t instancePtr, int iImage, uint32 * pnWidth, uint32 * pnHeight)
{
  TRACE("((intptr_t)%p, (int)%d, (uint32 *)%p, (uint32 *)%p)\n", instancePtr, iImage, pnWidth, pnHeight);
  bool result = SteamAPI_ISteamUtils_GetImageSize(instancePtr, iImage, pnWidth, pnHeight);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUtils_GetImageRGBA_(intptr_t instancePtr, int iImage, uint8 * pubDest, int nDestBufferSize)
{
  TRACE("((intptr_t)%p, (int)%d, (uint8 *)%p, (int)%d)\n", instancePtr, iImage, pubDest, nDestBufferSize);
  bool result = SteamAPI_ISteamUtils_GetImageRGBA(instancePtr, iImage, pubDest, nDestBufferSize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUtils_GetCSERIPPort_(intptr_t instancePtr, uint32 * unIP, uint16 * usPort)
{
  TRACE("((intptr_t)%p, (uint32 *)%p, (uint16 *)%p)\n", instancePtr, unIP, usPort);
  bool result = SteamAPI_ISteamUtils_GetCSERIPPort(instancePtr, unIP, usPort);
  TRACE(" = (bool)%d\n", result);
  return result;
}
uint8 SteamAPI_ISteamUtils_GetCurrentBatteryPower_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  uint8 result = SteamAPI_ISteamUtils_GetCurrentBatteryPower(instancePtr);
  TRACE(" = (uint8)%p\n", result);
  return result;
}
uint32 SteamAPI_ISteamUtils_GetAppID_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  uint32 result = SteamAPI_ISteamUtils_GetAppID(instancePtr);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
void SteamAPI_ISteamUtils_SetOverlayNotificationPosition_(intptr_t instancePtr, ENotificationPosition eNotificationPosition)
{
  TRACE("((intptr_t)%p, (ENotificationPosition)%p)\n", instancePtr, eNotificationPosition);
  SteamAPI_ISteamUtils_SetOverlayNotificationPosition(instancePtr, eNotificationPosition);
}
bool SteamAPI_ISteamUtils_IsAPICallCompleted_(intptr_t instancePtr, SteamAPICall_t hSteamAPICall, bool * pbFailed)
{
  TRACE("((intptr_t)%p, (SteamAPICall_t)%p, (bool *)%p)\n", instancePtr, hSteamAPICall, pbFailed);
  bool result = SteamAPI_ISteamUtils_IsAPICallCompleted(instancePtr, hSteamAPICall, pbFailed);
  TRACE(" = (bool)%d\n", result);
  return result;
}
ESteamAPICallFailure SteamAPI_ISteamUtils_GetAPICallFailureReason_(intptr_t instancePtr, SteamAPICall_t hSteamAPICall)
{
  TRACE("((intptr_t)%p, (SteamAPICall_t)%p)\n", instancePtr, hSteamAPICall);
  ESteamAPICallFailure result = SteamAPI_ISteamUtils_GetAPICallFailureReason(instancePtr, hSteamAPICall);
  TRACE(" = (ESteamAPICallFailure)%p\n", result);
  return result;
}
bool SteamAPI_ISteamUtils_GetAPICallResult_(intptr_t instancePtr, SteamAPICall_t hSteamAPICall, void * pCallback, int cubCallback, int iCallbackExpected, bool * pbFailed)
{
  TRACE("((intptr_t)%p, (SteamAPICall_t)%p, (void *)%p, (int)%d, (int)%d, (bool *)%p)\n", instancePtr, hSteamAPICall, pCallback, cubCallback, iCallbackExpected, pbFailed);
  bool result = SteamAPI_ISteamUtils_GetAPICallResult(instancePtr, hSteamAPICall, pCallback, cubCallback, iCallbackExpected, pbFailed);
  TRACE(" = (bool)%d\n", result);
  return result;
}
uint32 SteamAPI_ISteamUtils_GetIPCCallCount_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  uint32 result = SteamAPI_ISteamUtils_GetIPCCallCount(instancePtr);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
void SteamAPI_ISteamUtils_SetWarningMessageHook_(intptr_t instancePtr, SteamAPIWarningMessageHook_t pFunction)
{
  TRACE("((intptr_t)%p, (SteamAPIWarningMessageHook_t)%p)\n", instancePtr, pFunction);
  SteamAPI_ISteamUtils_SetWarningMessageHook(instancePtr, pFunction);
}
bool SteamAPI_ISteamUtils_IsOverlayEnabled_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamUtils_IsOverlayEnabled(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUtils_BOverlayNeedsPresent_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamUtils_BOverlayNeedsPresent(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamUtils_CheckFileSignature_(intptr_t instancePtr, const char * szFileName)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, szFileName);
  SteamAPICall_t result = SteamAPI_ISteamUtils_CheckFileSignature(instancePtr, szFileName);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
bool SteamAPI_ISteamUtils_ShowGamepadTextInput_(intptr_t instancePtr, EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, const char * pchDescription, uint32 unCharMax, const char * pchExistingText)
{
  TRACE("((intptr_t)%p, (EGamepadTextInputMode)%p, (EGamepadTextInputLineMode)%p, (const char *)\"%s\", (uint32)%d, (const char *)\"%s\")\n", instancePtr, eInputMode, eLineInputMode, pchDescription, unCharMax, pchExistingText);
  bool result = SteamAPI_ISteamUtils_ShowGamepadTextInput(instancePtr, eInputMode, eLineInputMode, pchDescription, unCharMax, pchExistingText);
  TRACE(" = (bool)%d\n", result);
  return result;
}
uint32 SteamAPI_ISteamUtils_GetEnteredGamepadTextLength_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  uint32 result = SteamAPI_ISteamUtils_GetEnteredGamepadTextLength(instancePtr);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUtils_GetEnteredGamepadTextInput_(intptr_t instancePtr, char * pchText, uint32 cchText)
{
  TRACE("((intptr_t)%p, (char *)%p, (uint32)%d)\n", instancePtr, pchText, cchText);
  bool result = SteamAPI_ISteamUtils_GetEnteredGamepadTextInput(instancePtr, pchText, cchText);
  TRACE(" = (bool)%d\n", result);
  return result;
}
const char * SteamAPI_ISteamUtils_GetSteamUILanguage_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  const char * result = SteamAPI_ISteamUtils_GetSteamUILanguage(instancePtr);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
bool SteamAPI_ISteamUtils_IsSteamRunningInVR_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamUtils_IsSteamRunningInVR(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int SteamAPI_ISteamMatchmaking_GetFavoriteGameCount_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  int result = SteamAPI_ISteamMatchmaking_GetFavoriteGameCount(instancePtr);
  TRACE(" = (int)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMatchmaking_GetFavoriteGame_(intptr_t instancePtr, int iGame, AppId_t * pnAppID, uint32 * pnIP, uint16 * pnConnPort, uint16 * pnQueryPort, uint32 * punFlags, uint32 * pRTime32LastPlayedOnServer)
{
  TRACE("((intptr_t)%p, (int)%d, (AppId_t *)%p, (uint32 *)%p, (uint16 *)%p, (uint16 *)%p, (uint32 *)%p, (uint32 *)%p)\n", instancePtr, iGame, pnAppID, pnIP, pnConnPort, pnQueryPort, punFlags, pRTime32LastPlayedOnServer);
  bool result = SteamAPI_ISteamMatchmaking_GetFavoriteGame(instancePtr, iGame, pnAppID, pnIP, pnConnPort, pnQueryPort, punFlags, pRTime32LastPlayedOnServer);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int SteamAPI_ISteamMatchmaking_AddFavoriteGame_(intptr_t instancePtr, AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer)
{
  TRACE("((intptr_t)%p, (AppId_t)%p, (uint32)%d, (uint16)%d, (uint16)%d, (uint32)%d, (uint32)%d)\n", instancePtr, nAppID, nIP, nConnPort, nQueryPort, unFlags, rTime32LastPlayedOnServer);
  int result = SteamAPI_ISteamMatchmaking_AddFavoriteGame(instancePtr, nAppID, nIP, nConnPort, nQueryPort, unFlags, rTime32LastPlayedOnServer);
  TRACE(" = (int)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMatchmaking_RemoveFavoriteGame_(intptr_t instancePtr, AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags)
{
  TRACE("((intptr_t)%p, (AppId_t)%p, (uint32)%d, (uint16)%d, (uint16)%d, (uint32)%d)\n", instancePtr, nAppID, nIP, nConnPort, nQueryPort, unFlags);
  bool result = SteamAPI_ISteamMatchmaking_RemoveFavoriteGame(instancePtr, nAppID, nIP, nConnPort, nQueryPort, unFlags);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamMatchmaking_RequestLobbyList_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPICall_t result = SteamAPI_ISteamMatchmaking_RequestLobbyList(instancePtr);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
void SteamAPI_ISteamMatchmaking_AddRequestLobbyListStringFilter_(intptr_t instancePtr, const char * pchKeyToMatch, const char * pchValueToMatch, ELobbyComparison eComparisonType)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (const char *)\"%s\", (ELobbyComparison)%p)\n", instancePtr, pchKeyToMatch, pchValueToMatch, eComparisonType);
  SteamAPI_ISteamMatchmaking_AddRequestLobbyListStringFilter(instancePtr, pchKeyToMatch, pchValueToMatch, eComparisonType);
}
void SteamAPI_ISteamMatchmaking_AddRequestLobbyListNumericalFilter_(intptr_t instancePtr, const char * pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (int)%d, (ELobbyComparison)%p)\n", instancePtr, pchKeyToMatch, nValueToMatch, eComparisonType);
  SteamAPI_ISteamMatchmaking_AddRequestLobbyListNumericalFilter(instancePtr, pchKeyToMatch, nValueToMatch, eComparisonType);
}
void SteamAPI_ISteamMatchmaking_AddRequestLobbyListNearValueFilter_(intptr_t instancePtr, const char * pchKeyToMatch, int nValueToBeCloseTo)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (int)%d)\n", instancePtr, pchKeyToMatch, nValueToBeCloseTo);
  SteamAPI_ISteamMatchmaking_AddRequestLobbyListNearValueFilter(instancePtr, pchKeyToMatch, nValueToBeCloseTo);
}
void SteamAPI_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable_(intptr_t instancePtr, int nSlotsAvailable)
{
  TRACE("((intptr_t)%p, (int)%d)\n", instancePtr, nSlotsAvailable);
  SteamAPI_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable(instancePtr, nSlotsAvailable);
}
void SteamAPI_ISteamMatchmaking_AddRequestLobbyListDistanceFilter_(intptr_t instancePtr, ELobbyDistanceFilter eLobbyDistanceFilter)
{
  TRACE("((intptr_t)%p, (ELobbyDistanceFilter)%p)\n", instancePtr, eLobbyDistanceFilter);
  SteamAPI_ISteamMatchmaking_AddRequestLobbyListDistanceFilter(instancePtr, eLobbyDistanceFilter);
}
void SteamAPI_ISteamMatchmaking_AddRequestLobbyListResultCountFilter_(intptr_t instancePtr, int cMaxResults)
{
  TRACE("((intptr_t)%p, (int)%d)\n", instancePtr, cMaxResults);
  SteamAPI_ISteamMatchmaking_AddRequestLobbyListResultCountFilter(instancePtr, cMaxResults);
}
void SteamAPI_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter_(intptr_t instancePtr, class CSteamID steamIDLobby)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDLobby);
  SteamAPI_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter(instancePtr, steamIDLobby);
}
uint64 SteamAPI_ISteamMatchmaking_GetLobbyByIndex_(intptr_t instancePtr, int iLobby)
{
  TRACE("((intptr_t)%p, (int)%d)\n", instancePtr, iLobby);
  uint64 result = SteamAPI_ISteamMatchmaking_GetLobbyByIndex(instancePtr, iLobby);
  TRACE(" = (uint64)%d\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamMatchmaking_CreateLobby_(intptr_t instancePtr, ELobbyType eLobbyType, int cMaxMembers)
{
  TRACE("((intptr_t)%p, (ELobbyType)%p, (int)%d)\n", instancePtr, eLobbyType, cMaxMembers);
  SteamAPICall_t result = SteamAPI_ISteamMatchmaking_CreateLobby(instancePtr, eLobbyType, cMaxMembers);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamMatchmaking_JoinLobby_(intptr_t instancePtr, class CSteamID steamIDLobby)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDLobby);
  SteamAPICall_t result = SteamAPI_ISteamMatchmaking_JoinLobby(instancePtr, steamIDLobby);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
void SteamAPI_ISteamMatchmaking_LeaveLobby_(intptr_t instancePtr, class CSteamID steamIDLobby)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDLobby);
  SteamAPI_ISteamMatchmaking_LeaveLobby(instancePtr, steamIDLobby);
}
bool SteamAPI_ISteamMatchmaking_InviteUserToLobby_(intptr_t instancePtr, class CSteamID steamIDLobby, class CSteamID steamIDInvitee)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (class CSteamID)%p)\n", instancePtr, steamIDLobby, steamIDInvitee);
  bool result = SteamAPI_ISteamMatchmaking_InviteUserToLobby(instancePtr, steamIDLobby, steamIDInvitee);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int SteamAPI_ISteamMatchmaking_GetNumLobbyMembers_(intptr_t instancePtr, class CSteamID steamIDLobby)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDLobby);
  int result = SteamAPI_ISteamMatchmaking_GetNumLobbyMembers(instancePtr, steamIDLobby);
  TRACE(" = (int)%d\n", result);
  return result;
}
uint64 SteamAPI_ISteamMatchmaking_GetLobbyMemberByIndex_(intptr_t instancePtr, class CSteamID steamIDLobby, int iMember)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (int)%d)\n", instancePtr, steamIDLobby, iMember);
  uint64 result = SteamAPI_ISteamMatchmaking_GetLobbyMemberByIndex(instancePtr, steamIDLobby, iMember);
  TRACE(" = (uint64)%d\n", result);
  return result;
}
const char * SteamAPI_ISteamMatchmaking_GetLobbyData_(intptr_t instancePtr, class CSteamID steamIDLobby, const char * pchKey)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const char *)\"%s\")\n", instancePtr, steamIDLobby, pchKey);
  const char * result = SteamAPI_ISteamMatchmaking_GetLobbyData(instancePtr, steamIDLobby, pchKey);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
bool SteamAPI_ISteamMatchmaking_SetLobbyData_(intptr_t instancePtr, class CSteamID steamIDLobby, const char * pchKey, const char * pchValue)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const char *)\"%s\", (const char *)\"%s\")\n", instancePtr, steamIDLobby, pchKey, pchValue);
  bool result = SteamAPI_ISteamMatchmaking_SetLobbyData(instancePtr, steamIDLobby, pchKey, pchValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int SteamAPI_ISteamMatchmaking_GetLobbyDataCount_(intptr_t instancePtr, class CSteamID steamIDLobby)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDLobby);
  int result = SteamAPI_ISteamMatchmaking_GetLobbyDataCount(instancePtr, steamIDLobby);
  TRACE(" = (int)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMatchmaking_GetLobbyDataByIndex_(intptr_t instancePtr, class CSteamID steamIDLobby, int iLobbyData, char * pchKey, int cchKeyBufferSize, char * pchValue, int cchValueBufferSize)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (int)%d, (char *)%p, (int)%d, (char *)%p, (int)%d)\n", instancePtr, steamIDLobby, iLobbyData, pchKey, cchKeyBufferSize, pchValue, cchValueBufferSize);
  bool result = SteamAPI_ISteamMatchmaking_GetLobbyDataByIndex(instancePtr, steamIDLobby, iLobbyData, pchKey, cchKeyBufferSize, pchValue, cchValueBufferSize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMatchmaking_DeleteLobbyData_(intptr_t instancePtr, class CSteamID steamIDLobby, const char * pchKey)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const char *)\"%s\")\n", instancePtr, steamIDLobby, pchKey);
  bool result = SteamAPI_ISteamMatchmaking_DeleteLobbyData(instancePtr, steamIDLobby, pchKey);
  TRACE(" = (bool)%d\n", result);
  return result;
}
const char * SteamAPI_ISteamMatchmaking_GetLobbyMemberData_(intptr_t instancePtr, class CSteamID steamIDLobby, class CSteamID steamIDUser, const char * pchKey)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (class CSteamID)%p, (const char *)\"%s\")\n", instancePtr, steamIDLobby, steamIDUser, pchKey);
  const char * result = SteamAPI_ISteamMatchmaking_GetLobbyMemberData(instancePtr, steamIDLobby, steamIDUser, pchKey);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
void SteamAPI_ISteamMatchmaking_SetLobbyMemberData_(intptr_t instancePtr, class CSteamID steamIDLobby, const char * pchKey, const char * pchValue)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const char *)\"%s\", (const char *)\"%s\")\n", instancePtr, steamIDLobby, pchKey, pchValue);
  SteamAPI_ISteamMatchmaking_SetLobbyMemberData(instancePtr, steamIDLobby, pchKey, pchValue);
}
bool SteamAPI_ISteamMatchmaking_SendLobbyChatMsg_(intptr_t instancePtr, class CSteamID steamIDLobby, const void * pvMsgBody, int cubMsgBody)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const void *)%p, (int)%d)\n", instancePtr, steamIDLobby, pvMsgBody, cubMsgBody);
  bool result = SteamAPI_ISteamMatchmaking_SendLobbyChatMsg(instancePtr, steamIDLobby, pvMsgBody, cubMsgBody);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int SteamAPI_ISteamMatchmaking_GetLobbyChatEntry_(intptr_t instancePtr, class CSteamID steamIDLobby, int iChatID, class CSteamID * pSteamIDUser, void * pvData, int cubData, EChatEntryType * peChatEntryType)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (int)%d, (class CSteamID *)%p, (void *)%p, (int)%d, (EChatEntryType *)%p)\n", instancePtr, steamIDLobby, iChatID, pSteamIDUser, pvData, cubData, peChatEntryType);
  int result = SteamAPI_ISteamMatchmaking_GetLobbyChatEntry(instancePtr, steamIDLobby, iChatID, pSteamIDUser, pvData, cubData, peChatEntryType);
  TRACE(" = (int)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMatchmaking_RequestLobbyData_(intptr_t instancePtr, class CSteamID steamIDLobby)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDLobby);
  bool result = SteamAPI_ISteamMatchmaking_RequestLobbyData(instancePtr, steamIDLobby);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void SteamAPI_ISteamMatchmaking_SetLobbyGameServer_(intptr_t instancePtr, class CSteamID steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, class CSteamID steamIDGameServer)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (uint32)%d, (uint16)%d, (class CSteamID)%p)\n", instancePtr, steamIDLobby, unGameServerIP, unGameServerPort, steamIDGameServer);
  SteamAPI_ISteamMatchmaking_SetLobbyGameServer(instancePtr, steamIDLobby, unGameServerIP, unGameServerPort, steamIDGameServer);
}
bool SteamAPI_ISteamMatchmaking_GetLobbyGameServer_(intptr_t instancePtr, class CSteamID steamIDLobby, uint32 * punGameServerIP, uint16 * punGameServerPort, class CSteamID * psteamIDGameServer)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (uint32 *)%p, (uint16 *)%p, (class CSteamID *)%p)\n", instancePtr, steamIDLobby, punGameServerIP, punGameServerPort, psteamIDGameServer);
  bool result = SteamAPI_ISteamMatchmaking_GetLobbyGameServer(instancePtr, steamIDLobby, punGameServerIP, punGameServerPort, psteamIDGameServer);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMatchmaking_SetLobbyMemberLimit_(intptr_t instancePtr, class CSteamID steamIDLobby, int cMaxMembers)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (int)%d)\n", instancePtr, steamIDLobby, cMaxMembers);
  bool result = SteamAPI_ISteamMatchmaking_SetLobbyMemberLimit(instancePtr, steamIDLobby, cMaxMembers);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int SteamAPI_ISteamMatchmaking_GetLobbyMemberLimit_(intptr_t instancePtr, class CSteamID steamIDLobby)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDLobby);
  int result = SteamAPI_ISteamMatchmaking_GetLobbyMemberLimit(instancePtr, steamIDLobby);
  TRACE(" = (int)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMatchmaking_SetLobbyType_(intptr_t instancePtr, class CSteamID steamIDLobby, ELobbyType eLobbyType)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (ELobbyType)%p)\n", instancePtr, steamIDLobby, eLobbyType);
  bool result = SteamAPI_ISteamMatchmaking_SetLobbyType(instancePtr, steamIDLobby, eLobbyType);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMatchmaking_SetLobbyJoinable_(intptr_t instancePtr, class CSteamID steamIDLobby, bool bLobbyJoinable)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (bool)%d)\n", instancePtr, steamIDLobby, bLobbyJoinable);
  bool result = SteamAPI_ISteamMatchmaking_SetLobbyJoinable(instancePtr, steamIDLobby, bLobbyJoinable);
  TRACE(" = (bool)%d\n", result);
  return result;
}
uint64 SteamAPI_ISteamMatchmaking_GetLobbyOwner_(intptr_t instancePtr, class CSteamID steamIDLobby)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDLobby);
  uint64 result = SteamAPI_ISteamMatchmaking_GetLobbyOwner(instancePtr, steamIDLobby);
  TRACE(" = (uint64)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMatchmaking_SetLobbyOwner_(intptr_t instancePtr, class CSteamID steamIDLobby, class CSteamID steamIDNewOwner)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (class CSteamID)%p)\n", instancePtr, steamIDLobby, steamIDNewOwner);
  bool result = SteamAPI_ISteamMatchmaking_SetLobbyOwner(instancePtr, steamIDLobby, steamIDNewOwner);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMatchmaking_SetLinkedLobby_(intptr_t instancePtr, class CSteamID steamIDLobby, class CSteamID steamIDLobbyDependent)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (class CSteamID)%p)\n", instancePtr, steamIDLobby, steamIDLobbyDependent);
  bool result = SteamAPI_ISteamMatchmaking_SetLinkedLobby(instancePtr, steamIDLobby, steamIDLobbyDependent);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void SteamAPI_ISteamMatchmakingServerListResponse_ServerResponded_(intptr_t instancePtr, HServerListRequest hRequest, int iServer)
{
  TRACE("((intptr_t)%p, (HServerListRequest)%p, (int)%d)\n", instancePtr, hRequest, iServer);
  SteamAPI_ISteamMatchmakingServerListResponse_ServerResponded(instancePtr, hRequest, iServer);
}
void SteamAPI_ISteamMatchmakingServerListResponse_ServerFailedToRespond_(intptr_t instancePtr, HServerListRequest hRequest, int iServer)
{
  TRACE("((intptr_t)%p, (HServerListRequest)%p, (int)%d)\n", instancePtr, hRequest, iServer);
  SteamAPI_ISteamMatchmakingServerListResponse_ServerFailedToRespond(instancePtr, hRequest, iServer);
}
void SteamAPI_ISteamMatchmakingServerListResponse_RefreshComplete_(intptr_t instancePtr, HServerListRequest hRequest, EMatchMakingServerResponse response)
{
  TRACE("((intptr_t)%p, (HServerListRequest)%p, (EMatchMakingServerResponse)%p)\n", instancePtr, hRequest, response);
  SteamAPI_ISteamMatchmakingServerListResponse_RefreshComplete(instancePtr, hRequest, response);
}
void SteamAPI_ISteamMatchmakingPingResponse_ServerResponded_(intptr_t instancePtr, class gameserveritem_t & server)
{
  TRACE("((intptr_t)%p, (class gameserveritem_t &)%p)\n", instancePtr, server);
  SteamAPI_ISteamMatchmakingPingResponse_ServerResponded(instancePtr, server);
}
void SteamAPI_ISteamMatchmakingPingResponse_ServerFailedToRespond_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPI_ISteamMatchmakingPingResponse_ServerFailedToRespond(instancePtr);
}
void SteamAPI_ISteamMatchmakingPlayersResponse_AddPlayerToList_(intptr_t instancePtr, const char * pchName, int nScore, float flTimePlayed)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (int)%d, (float)%f)\n", instancePtr, pchName, nScore, flTimePlayed);
  SteamAPI_ISteamMatchmakingPlayersResponse_AddPlayerToList(instancePtr, pchName, nScore, flTimePlayed);
}
void SteamAPI_ISteamMatchmakingPlayersResponse_PlayersFailedToRespond_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPI_ISteamMatchmakingPlayersResponse_PlayersFailedToRespond(instancePtr);
}
void SteamAPI_ISteamMatchmakingPlayersResponse_PlayersRefreshComplete_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPI_ISteamMatchmakingPlayersResponse_PlayersRefreshComplete(instancePtr);
}
void SteamAPI_ISteamMatchmakingRulesResponse_RulesResponded_(intptr_t instancePtr, const char * pchRule, const char * pchValue)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (const char *)\"%s\")\n", instancePtr, pchRule, pchValue);
  SteamAPI_ISteamMatchmakingRulesResponse_RulesResponded(instancePtr, pchRule, pchValue);
}
void SteamAPI_ISteamMatchmakingRulesResponse_RulesFailedToRespond_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPI_ISteamMatchmakingRulesResponse_RulesFailedToRespond(instancePtr);
}
void SteamAPI_ISteamMatchmakingRulesResponse_RulesRefreshComplete_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPI_ISteamMatchmakingRulesResponse_RulesRefreshComplete(instancePtr);
}
HServerListRequest SteamAPI_ISteamMatchmakingServers_RequestInternetServerList_(intptr_t instancePtr, AppId_t iApp, struct MatchMakingKeyValuePair_t ** ppchFilters, uint32 nFilters, class ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
  TRACE("((intptr_t)%p, (AppId_t)%p, (struct MatchMakingKeyValuePair_t **)%p, (uint32)%d, (class ISteamMatchmakingServerListResponse *)%p)\n", instancePtr, iApp, ppchFilters, nFilters, pRequestServersResponse);
  HServerListRequest result = SteamAPI_ISteamMatchmakingServers_RequestInternetServerList(instancePtr, iApp, ppchFilters, nFilters, pRequestServersResponse);
  TRACE(" = (HServerListRequest)%p\n", result);
  return result;
}
HServerListRequest SteamAPI_ISteamMatchmakingServers_RequestLANServerList_(intptr_t instancePtr, AppId_t iApp, class ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
  TRACE("((intptr_t)%p, (AppId_t)%p, (class ISteamMatchmakingServerListResponse *)%p)\n", instancePtr, iApp, pRequestServersResponse);
  HServerListRequest result = SteamAPI_ISteamMatchmakingServers_RequestLANServerList(instancePtr, iApp, pRequestServersResponse);
  TRACE(" = (HServerListRequest)%p\n", result);
  return result;
}
HServerListRequest SteamAPI_ISteamMatchmakingServers_RequestFriendsServerList_(intptr_t instancePtr, AppId_t iApp, struct MatchMakingKeyValuePair_t ** ppchFilters, uint32 nFilters, class ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
  TRACE("((intptr_t)%p, (AppId_t)%p, (struct MatchMakingKeyValuePair_t **)%p, (uint32)%d, (class ISteamMatchmakingServerListResponse *)%p)\n", instancePtr, iApp, ppchFilters, nFilters, pRequestServersResponse);
  HServerListRequest result = SteamAPI_ISteamMatchmakingServers_RequestFriendsServerList(instancePtr, iApp, ppchFilters, nFilters, pRequestServersResponse);
  TRACE(" = (HServerListRequest)%p\n", result);
  return result;
}
HServerListRequest SteamAPI_ISteamMatchmakingServers_RequestFavoritesServerList_(intptr_t instancePtr, AppId_t iApp, struct MatchMakingKeyValuePair_t ** ppchFilters, uint32 nFilters, class ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
  TRACE("((intptr_t)%p, (AppId_t)%p, (struct MatchMakingKeyValuePair_t **)%p, (uint32)%d, (class ISteamMatchmakingServerListResponse *)%p)\n", instancePtr, iApp, ppchFilters, nFilters, pRequestServersResponse);
  HServerListRequest result = SteamAPI_ISteamMatchmakingServers_RequestFavoritesServerList(instancePtr, iApp, ppchFilters, nFilters, pRequestServersResponse);
  TRACE(" = (HServerListRequest)%p\n", result);
  return result;
}
HServerListRequest SteamAPI_ISteamMatchmakingServers_RequestHistoryServerList_(intptr_t instancePtr, AppId_t iApp, struct MatchMakingKeyValuePair_t ** ppchFilters, uint32 nFilters, class ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
  TRACE("((intptr_t)%p, (AppId_t)%p, (struct MatchMakingKeyValuePair_t **)%p, (uint32)%d, (class ISteamMatchmakingServerListResponse *)%p)\n", instancePtr, iApp, ppchFilters, nFilters, pRequestServersResponse);
  HServerListRequest result = SteamAPI_ISteamMatchmakingServers_RequestHistoryServerList(instancePtr, iApp, ppchFilters, nFilters, pRequestServersResponse);
  TRACE(" = (HServerListRequest)%p\n", result);
  return result;
}
HServerListRequest SteamAPI_ISteamMatchmakingServers_RequestSpectatorServerList_(intptr_t instancePtr, AppId_t iApp, struct MatchMakingKeyValuePair_t ** ppchFilters, uint32 nFilters, class ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
  TRACE("((intptr_t)%p, (AppId_t)%p, (struct MatchMakingKeyValuePair_t **)%p, (uint32)%d, (class ISteamMatchmakingServerListResponse *)%p)\n", instancePtr, iApp, ppchFilters, nFilters, pRequestServersResponse);
  HServerListRequest result = SteamAPI_ISteamMatchmakingServers_RequestSpectatorServerList(instancePtr, iApp, ppchFilters, nFilters, pRequestServersResponse);
  TRACE(" = (HServerListRequest)%p\n", result);
  return result;
}
void SteamAPI_ISteamMatchmakingServers_ReleaseRequest_(intptr_t instancePtr, HServerListRequest hServerListRequest)
{
  TRACE("((intptr_t)%p, (HServerListRequest)%p)\n", instancePtr, hServerListRequest);
  SteamAPI_ISteamMatchmakingServers_ReleaseRequest(instancePtr, hServerListRequest);
}
class gameserveritem_t * SteamAPI_ISteamMatchmakingServers_GetServerDetails_(intptr_t instancePtr, HServerListRequest hRequest, int iServer)
{
  TRACE("((intptr_t)%p, (HServerListRequest)%p, (int)%d)\n", instancePtr, hRequest, iServer);
  class gameserveritem_t * result = SteamAPI_ISteamMatchmakingServers_GetServerDetails(instancePtr, hRequest, iServer);
  TRACE(" = (class gameserveritem_t *)%p\n", result);
  return result;
}
void SteamAPI_ISteamMatchmakingServers_CancelQuery_(intptr_t instancePtr, HServerListRequest hRequest)
{
  TRACE("((intptr_t)%p, (HServerListRequest)%p)\n", instancePtr, hRequest);
  SteamAPI_ISteamMatchmakingServers_CancelQuery(instancePtr, hRequest);
}
void SteamAPI_ISteamMatchmakingServers_RefreshQuery_(intptr_t instancePtr, HServerListRequest hRequest)
{
  TRACE("((intptr_t)%p, (HServerListRequest)%p)\n", instancePtr, hRequest);
  SteamAPI_ISteamMatchmakingServers_RefreshQuery(instancePtr, hRequest);
}
bool SteamAPI_ISteamMatchmakingServers_IsRefreshing_(intptr_t instancePtr, HServerListRequest hRequest)
{
  TRACE("((intptr_t)%p, (HServerListRequest)%p)\n", instancePtr, hRequest);
  bool result = SteamAPI_ISteamMatchmakingServers_IsRefreshing(instancePtr, hRequest);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int SteamAPI_ISteamMatchmakingServers_GetServerCount_(intptr_t instancePtr, HServerListRequest hRequest)
{
  TRACE("((intptr_t)%p, (HServerListRequest)%p)\n", instancePtr, hRequest);
  int result = SteamAPI_ISteamMatchmakingServers_GetServerCount(instancePtr, hRequest);
  TRACE(" = (int)%d\n", result);
  return result;
}
void SteamAPI_ISteamMatchmakingServers_RefreshServer_(intptr_t instancePtr, HServerListRequest hRequest, int iServer)
{
  TRACE("((intptr_t)%p, (HServerListRequest)%p, (int)%d)\n", instancePtr, hRequest, iServer);
  SteamAPI_ISteamMatchmakingServers_RefreshServer(instancePtr, hRequest, iServer);
}
HServerQuery SteamAPI_ISteamMatchmakingServers_PingServer_(intptr_t instancePtr, uint32 unIP, uint16 usPort, class ISteamMatchmakingPingResponse * pRequestServersResponse)
{
  TRACE("((intptr_t)%p, (uint32)%d, (uint16)%d, (class ISteamMatchmakingPingResponse *)%p)\n", instancePtr, unIP, usPort, pRequestServersResponse);
  HServerQuery result = SteamAPI_ISteamMatchmakingServers_PingServer(instancePtr, unIP, usPort, pRequestServersResponse);
  TRACE(" = (HServerQuery)%p\n", result);
  return result;
}
HServerQuery SteamAPI_ISteamMatchmakingServers_PlayerDetails_(intptr_t instancePtr, uint32 unIP, uint16 usPort, class ISteamMatchmakingPlayersResponse * pRequestServersResponse)
{
  TRACE("((intptr_t)%p, (uint32)%d, (uint16)%d, (class ISteamMatchmakingPlayersResponse *)%p)\n", instancePtr, unIP, usPort, pRequestServersResponse);
  HServerQuery result = SteamAPI_ISteamMatchmakingServers_PlayerDetails(instancePtr, unIP, usPort, pRequestServersResponse);
  TRACE(" = (HServerQuery)%p\n", result);
  return result;
}
HServerQuery SteamAPI_ISteamMatchmakingServers_ServerRules_(intptr_t instancePtr, uint32 unIP, uint16 usPort, class ISteamMatchmakingRulesResponse * pRequestServersResponse)
{
  TRACE("((intptr_t)%p, (uint32)%d, (uint16)%d, (class ISteamMatchmakingRulesResponse *)%p)\n", instancePtr, unIP, usPort, pRequestServersResponse);
  HServerQuery result = SteamAPI_ISteamMatchmakingServers_ServerRules(instancePtr, unIP, usPort, pRequestServersResponse);
  TRACE(" = (HServerQuery)%p\n", result);
  return result;
}
void SteamAPI_ISteamMatchmakingServers_CancelServerQuery_(intptr_t instancePtr, HServerQuery hServerQuery)
{
  TRACE("((intptr_t)%p, (HServerQuery)%p)\n", instancePtr, hServerQuery);
  SteamAPI_ISteamMatchmakingServers_CancelServerQuery(instancePtr, hServerQuery);
}
bool SteamAPI_ISteamRemoteStorage_FileWrite_(intptr_t instancePtr, const char * pchFile, const void * pvData, int32 cubData)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (const void *)%p, (int32)%d)\n", instancePtr, pchFile, pvData, cubData);
  bool result = SteamAPI_ISteamRemoteStorage_FileWrite(instancePtr, pchFile, pvData, cubData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int32 SteamAPI_ISteamRemoteStorage_FileRead_(intptr_t instancePtr, const char * pchFile, void * pvData, int32 cubDataToRead)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (void *)%p, (int32)%d)\n", instancePtr, pchFile, pvData, cubDataToRead);
  int32 result = SteamAPI_ISteamRemoteStorage_FileRead(instancePtr, pchFile, pvData, cubDataToRead);
  TRACE(" = (int32)%d\n", result);
  return result;
}
bool SteamAPI_ISteamRemoteStorage_FileForget_(intptr_t instancePtr, const char * pchFile)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchFile);
  bool result = SteamAPI_ISteamRemoteStorage_FileForget(instancePtr, pchFile);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamRemoteStorage_FileDelete_(intptr_t instancePtr, const char * pchFile)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchFile);
  bool result = SteamAPI_ISteamRemoteStorage_FileDelete(instancePtr, pchFile);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamRemoteStorage_FileShare_(intptr_t instancePtr, const char * pchFile)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchFile);
  SteamAPICall_t result = SteamAPI_ISteamRemoteStorage_FileShare(instancePtr, pchFile);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
bool SteamAPI_ISteamRemoteStorage_SetSyncPlatforms_(intptr_t instancePtr, const char * pchFile, ERemoteStoragePlatform eRemoteStoragePlatform)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (ERemoteStoragePlatform)%p)\n", instancePtr, pchFile, eRemoteStoragePlatform);
  bool result = SteamAPI_ISteamRemoteStorage_SetSyncPlatforms(instancePtr, pchFile, eRemoteStoragePlatform);
  TRACE(" = (bool)%d\n", result);
  return result;
}
UGCFileWriteStreamHandle_t SteamAPI_ISteamRemoteStorage_FileWriteStreamOpen_(intptr_t instancePtr, const char * pchFile)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchFile);
  UGCFileWriteStreamHandle_t result = SteamAPI_ISteamRemoteStorage_FileWriteStreamOpen(instancePtr, pchFile);
  TRACE(" = (UGCFileWriteStreamHandle_t)%p\n", result);
  return result;
}
bool SteamAPI_ISteamRemoteStorage_FileWriteStreamWriteChunk_(intptr_t instancePtr, UGCFileWriteStreamHandle_t writeHandle, const void * pvData, int32 cubData)
{
  TRACE("((intptr_t)%p, (UGCFileWriteStreamHandle_t)%p, (const void *)%p, (int32)%d)\n", instancePtr, writeHandle, pvData, cubData);
  bool result = SteamAPI_ISteamRemoteStorage_FileWriteStreamWriteChunk(instancePtr, writeHandle, pvData, cubData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamRemoteStorage_FileWriteStreamClose_(intptr_t instancePtr, UGCFileWriteStreamHandle_t writeHandle)
{
  TRACE("((intptr_t)%p, (UGCFileWriteStreamHandle_t)%p)\n", instancePtr, writeHandle);
  bool result = SteamAPI_ISteamRemoteStorage_FileWriteStreamClose(instancePtr, writeHandle);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamRemoteStorage_FileWriteStreamCancel_(intptr_t instancePtr, UGCFileWriteStreamHandle_t writeHandle)
{
  TRACE("((intptr_t)%p, (UGCFileWriteStreamHandle_t)%p)\n", instancePtr, writeHandle);
  bool result = SteamAPI_ISteamRemoteStorage_FileWriteStreamCancel(instancePtr, writeHandle);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamRemoteStorage_FileExists_(intptr_t instancePtr, const char * pchFile)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchFile);
  bool result = SteamAPI_ISteamRemoteStorage_FileExists(instancePtr, pchFile);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamRemoteStorage_FilePersisted_(intptr_t instancePtr, const char * pchFile)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchFile);
  bool result = SteamAPI_ISteamRemoteStorage_FilePersisted(instancePtr, pchFile);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int32 SteamAPI_ISteamRemoteStorage_GetFileSize_(intptr_t instancePtr, const char * pchFile)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchFile);
  int32 result = SteamAPI_ISteamRemoteStorage_GetFileSize(instancePtr, pchFile);
  TRACE(" = (int32)%d\n", result);
  return result;
}
int64 SteamAPI_ISteamRemoteStorage_GetFileTimestamp_(intptr_t instancePtr, const char * pchFile)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchFile);
  int64 result = SteamAPI_ISteamRemoteStorage_GetFileTimestamp(instancePtr, pchFile);
  TRACE(" = (int64)%d\n", result);
  return result;
}
ERemoteStoragePlatform SteamAPI_ISteamRemoteStorage_GetSyncPlatforms_(intptr_t instancePtr, const char * pchFile)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchFile);
  ERemoteStoragePlatform result = SteamAPI_ISteamRemoteStorage_GetSyncPlatforms(instancePtr, pchFile);
  TRACE(" = (ERemoteStoragePlatform)%p\n", result);
  return result;
}
int32 SteamAPI_ISteamRemoteStorage_GetFileCount_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  int32 result = SteamAPI_ISteamRemoteStorage_GetFileCount(instancePtr);
  TRACE(" = (int32)%d\n", result);
  return result;
}
const char * SteamAPI_ISteamRemoteStorage_GetFileNameAndSize_(intptr_t instancePtr, int iFile, int32 * pnFileSizeInBytes)
{
  TRACE("((intptr_t)%p, (int)%d, (int32 *)%p)\n", instancePtr, iFile, pnFileSizeInBytes);
  const char * result = SteamAPI_ISteamRemoteStorage_GetFileNameAndSize(instancePtr, iFile, pnFileSizeInBytes);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
bool SteamAPI_ISteamRemoteStorage_GetQuota_(intptr_t instancePtr, uint64 * pnTotalBytes, uint64 * puAvailableBytes)
{
  TRACE("((intptr_t)%p, (uint64 *)%p, (uint64 *)%p)\n", instancePtr, pnTotalBytes, puAvailableBytes);
  bool result = SteamAPI_ISteamRemoteStorage_GetQuota(instancePtr, pnTotalBytes, puAvailableBytes);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamRemoteStorage_IsCloudEnabledForAccount_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamRemoteStorage_IsCloudEnabledForAccount(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamRemoteStorage_IsCloudEnabledForApp_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamRemoteStorage_IsCloudEnabledForApp(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void SteamAPI_ISteamRemoteStorage_SetCloudEnabledForApp_(intptr_t instancePtr, bool bEnabled)
{
  TRACE("((intptr_t)%p, (bool)%d)\n", instancePtr, bEnabled);
  SteamAPI_ISteamRemoteStorage_SetCloudEnabledForApp(instancePtr, bEnabled);
}
SteamAPICall_t SteamAPI_ISteamRemoteStorage_UGCDownload_(intptr_t instancePtr, UGCHandle_t hContent, uint32 unPriority)
{
  TRACE("((intptr_t)%p, (UGCHandle_t)%p, (uint32)%d)\n", instancePtr, hContent, unPriority);
  SteamAPICall_t result = SteamAPI_ISteamRemoteStorage_UGCDownload(instancePtr, hContent, unPriority);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
bool SteamAPI_ISteamRemoteStorage_GetUGCDownloadProgress_(intptr_t instancePtr, UGCHandle_t hContent, int32 * pnBytesDownloaded, int32 * pnBytesExpected)
{
  TRACE("((intptr_t)%p, (UGCHandle_t)%p, (int32 *)%p, (int32 *)%p)\n", instancePtr, hContent, pnBytesDownloaded, pnBytesExpected);
  bool result = SteamAPI_ISteamRemoteStorage_GetUGCDownloadProgress(instancePtr, hContent, pnBytesDownloaded, pnBytesExpected);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamRemoteStorage_GetUGCDetails_(intptr_t instancePtr, UGCHandle_t hContent, AppId_t * pnAppID, char ** ppchName, int32 * pnFileSizeInBytes, class CSteamID * pSteamIDOwner)
{
  TRACE("((intptr_t)%p, (UGCHandle_t)%p, (AppId_t *)%p, (char **)%p, (int32 *)%p, (class CSteamID *)%p)\n", instancePtr, hContent, pnAppID, ppchName, pnFileSizeInBytes, pSteamIDOwner);
  bool result = SteamAPI_ISteamRemoteStorage_GetUGCDetails(instancePtr, hContent, pnAppID, ppchName, pnFileSizeInBytes, pSteamIDOwner);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int32 SteamAPI_ISteamRemoteStorage_UGCRead_(intptr_t instancePtr, UGCHandle_t hContent, void * pvData, int32 cubDataToRead, uint32 cOffset, EUGCReadAction eAction)
{
  TRACE("((intptr_t)%p, (UGCHandle_t)%p, (void *)%p, (int32)%d, (uint32)%d, (EUGCReadAction)%p)\n", instancePtr, hContent, pvData, cubDataToRead, cOffset, eAction);
  int32 result = SteamAPI_ISteamRemoteStorage_UGCRead(instancePtr, hContent, pvData, cubDataToRead, cOffset, eAction);
  TRACE(" = (int32)%d\n", result);
  return result;
}
int32 SteamAPI_ISteamRemoteStorage_GetCachedUGCCount_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  int32 result = SteamAPI_ISteamRemoteStorage_GetCachedUGCCount(instancePtr);
  TRACE(" = (int32)%d\n", result);
  return result;
}
UGCHandle_t SteamAPI_ISteamRemoteStorage_GetCachedUGCHandle_(intptr_t instancePtr, int32 iCachedContent)
{
  TRACE("((intptr_t)%p, (int32)%d)\n", instancePtr, iCachedContent);
  UGCHandle_t result = SteamAPI_ISteamRemoteStorage_GetCachedUGCHandle(instancePtr, iCachedContent);
  TRACE(" = (UGCHandle_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamRemoteStorage_PublishWorkshopFile_(intptr_t instancePtr, const char * pchFile, const char * pchPreviewFile, AppId_t nConsumerAppId, const char * pchTitle, const char * pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, struct SteamParamStringArray_t * pTags, EWorkshopFileType eWorkshopFileType)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (const char *)\"%s\", (AppId_t)%p, (const char *)\"%s\", (const char *)\"%s\", (ERemoteStoragePublishedFileVisibility)%p, (struct SteamParamStringArray_t *)%p, (EWorkshopFileType)%p)\n", instancePtr, pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, pTags, eWorkshopFileType);
  SteamAPICall_t result = SteamAPI_ISteamRemoteStorage_PublishWorkshopFile(instancePtr, pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, pTags, eWorkshopFileType);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
PublishedFileUpdateHandle_t SteamAPI_ISteamRemoteStorage_CreatePublishedFileUpdateRequest_(intptr_t instancePtr, PublishedFileId_t unPublishedFileId)
{
  TRACE("((intptr_t)%p, (PublishedFileId_t)%p)\n", instancePtr, unPublishedFileId);
  PublishedFileUpdateHandle_t result = SteamAPI_ISteamRemoteStorage_CreatePublishedFileUpdateRequest(instancePtr, unPublishedFileId);
  TRACE(" = (PublishedFileUpdateHandle_t)%p\n", result);
  return result;
}
bool SteamAPI_ISteamRemoteStorage_UpdatePublishedFileFile_(intptr_t instancePtr, PublishedFileUpdateHandle_t updateHandle, const char * pchFile)
{
  TRACE("((intptr_t)%p, (PublishedFileUpdateHandle_t)%p, (const char *)\"%s\")\n", instancePtr, updateHandle, pchFile);
  bool result = SteamAPI_ISteamRemoteStorage_UpdatePublishedFileFile(instancePtr, updateHandle, pchFile);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamRemoteStorage_UpdatePublishedFilePreviewFile_(intptr_t instancePtr, PublishedFileUpdateHandle_t updateHandle, const char * pchPreviewFile)
{
  TRACE("((intptr_t)%p, (PublishedFileUpdateHandle_t)%p, (const char *)\"%s\")\n", instancePtr, updateHandle, pchPreviewFile);
  bool result = SteamAPI_ISteamRemoteStorage_UpdatePublishedFilePreviewFile(instancePtr, updateHandle, pchPreviewFile);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTitle_(intptr_t instancePtr, PublishedFileUpdateHandle_t updateHandle, const char * pchTitle)
{
  TRACE("((intptr_t)%p, (PublishedFileUpdateHandle_t)%p, (const char *)\"%s\")\n", instancePtr, updateHandle, pchTitle);
  bool result = SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTitle(instancePtr, updateHandle, pchTitle);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamRemoteStorage_UpdatePublishedFileDescription_(intptr_t instancePtr, PublishedFileUpdateHandle_t updateHandle, const char * pchDescription)
{
  TRACE("((intptr_t)%p, (PublishedFileUpdateHandle_t)%p, (const char *)\"%s\")\n", instancePtr, updateHandle, pchDescription);
  bool result = SteamAPI_ISteamRemoteStorage_UpdatePublishedFileDescription(instancePtr, updateHandle, pchDescription);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamRemoteStorage_UpdatePublishedFileVisibility_(intptr_t instancePtr, PublishedFileUpdateHandle_t updateHandle, ERemoteStoragePublishedFileVisibility eVisibility)
{
  TRACE("((intptr_t)%p, (PublishedFileUpdateHandle_t)%p, (ERemoteStoragePublishedFileVisibility)%p)\n", instancePtr, updateHandle, eVisibility);
  bool result = SteamAPI_ISteamRemoteStorage_UpdatePublishedFileVisibility(instancePtr, updateHandle, eVisibility);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTags_(intptr_t instancePtr, PublishedFileUpdateHandle_t updateHandle, struct SteamParamStringArray_t * pTags)
{
  TRACE("((intptr_t)%p, (PublishedFileUpdateHandle_t)%p, (struct SteamParamStringArray_t *)%p)\n", instancePtr, updateHandle, pTags);
  bool result = SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTags(instancePtr, updateHandle, pTags);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamRemoteStorage_CommitPublishedFileUpdate_(intptr_t instancePtr, PublishedFileUpdateHandle_t updateHandle)
{
  TRACE("((intptr_t)%p, (PublishedFileUpdateHandle_t)%p)\n", instancePtr, updateHandle);
  SteamAPICall_t result = SteamAPI_ISteamRemoteStorage_CommitPublishedFileUpdate(instancePtr, updateHandle);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamRemoteStorage_GetPublishedFileDetails_(intptr_t instancePtr, PublishedFileId_t unPublishedFileId, uint32 unMaxSecondsOld)
{
  TRACE("((intptr_t)%p, (PublishedFileId_t)%p, (uint32)%d)\n", instancePtr, unPublishedFileId, unMaxSecondsOld);
  SteamAPICall_t result = SteamAPI_ISteamRemoteStorage_GetPublishedFileDetails(instancePtr, unPublishedFileId, unMaxSecondsOld);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamRemoteStorage_DeletePublishedFile_(intptr_t instancePtr, PublishedFileId_t unPublishedFileId)
{
  TRACE("((intptr_t)%p, (PublishedFileId_t)%p)\n", instancePtr, unPublishedFileId);
  SteamAPICall_t result = SteamAPI_ISteamRemoteStorage_DeletePublishedFile(instancePtr, unPublishedFileId);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamRemoteStorage_EnumerateUserPublishedFiles_(intptr_t instancePtr, uint32 unStartIndex)
{
  TRACE("((intptr_t)%p, (uint32)%d)\n", instancePtr, unStartIndex);
  SteamAPICall_t result = SteamAPI_ISteamRemoteStorage_EnumerateUserPublishedFiles(instancePtr, unStartIndex);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamRemoteStorage_SubscribePublishedFile_(intptr_t instancePtr, PublishedFileId_t unPublishedFileId)
{
  TRACE("((intptr_t)%p, (PublishedFileId_t)%p)\n", instancePtr, unPublishedFileId);
  SteamAPICall_t result = SteamAPI_ISteamRemoteStorage_SubscribePublishedFile(instancePtr, unPublishedFileId);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamRemoteStorage_EnumerateUserSubscribedFiles_(intptr_t instancePtr, uint32 unStartIndex)
{
  TRACE("((intptr_t)%p, (uint32)%d)\n", instancePtr, unStartIndex);
  SteamAPICall_t result = SteamAPI_ISteamRemoteStorage_EnumerateUserSubscribedFiles(instancePtr, unStartIndex);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamRemoteStorage_UnsubscribePublishedFile_(intptr_t instancePtr, PublishedFileId_t unPublishedFileId)
{
  TRACE("((intptr_t)%p, (PublishedFileId_t)%p)\n", instancePtr, unPublishedFileId);
  SteamAPICall_t result = SteamAPI_ISteamRemoteStorage_UnsubscribePublishedFile(instancePtr, unPublishedFileId);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
bool SteamAPI_ISteamRemoteStorage_UpdatePublishedFileSetChangeDescription_(intptr_t instancePtr, PublishedFileUpdateHandle_t updateHandle, const char * pchChangeDescription)
{
  TRACE("((intptr_t)%p, (PublishedFileUpdateHandle_t)%p, (const char *)\"%s\")\n", instancePtr, updateHandle, pchChangeDescription);
  bool result = SteamAPI_ISteamRemoteStorage_UpdatePublishedFileSetChangeDescription(instancePtr, updateHandle, pchChangeDescription);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamRemoteStorage_GetPublishedItemVoteDetails_(intptr_t instancePtr, PublishedFileId_t unPublishedFileId)
{
  TRACE("((intptr_t)%p, (PublishedFileId_t)%p)\n", instancePtr, unPublishedFileId);
  SteamAPICall_t result = SteamAPI_ISteamRemoteStorage_GetPublishedItemVoteDetails(instancePtr, unPublishedFileId);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamRemoteStorage_UpdateUserPublishedItemVote_(intptr_t instancePtr, PublishedFileId_t unPublishedFileId, bool bVoteUp)
{
  TRACE("((intptr_t)%p, (PublishedFileId_t)%p, (bool)%d)\n", instancePtr, unPublishedFileId, bVoteUp);
  SteamAPICall_t result = SteamAPI_ISteamRemoteStorage_UpdateUserPublishedItemVote(instancePtr, unPublishedFileId, bVoteUp);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamRemoteStorage_GetUserPublishedItemVoteDetails_(intptr_t instancePtr, PublishedFileId_t unPublishedFileId)
{
  TRACE("((intptr_t)%p, (PublishedFileId_t)%p)\n", instancePtr, unPublishedFileId);
  SteamAPICall_t result = SteamAPI_ISteamRemoteStorage_GetUserPublishedItemVoteDetails(instancePtr, unPublishedFileId);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamRemoteStorage_EnumerateUserSharedWorkshopFiles_(intptr_t instancePtr, class CSteamID steamId, uint32 unStartIndex, struct SteamParamStringArray_t * pRequiredTags, struct SteamParamStringArray_t * pExcludedTags)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (uint32)%d, (struct SteamParamStringArray_t *)%p, (struct SteamParamStringArray_t *)%p)\n", instancePtr, steamId, unStartIndex, pRequiredTags, pExcludedTags);
  SteamAPICall_t result = SteamAPI_ISteamRemoteStorage_EnumerateUserSharedWorkshopFiles(instancePtr, steamId, unStartIndex, pRequiredTags, pExcludedTags);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamRemoteStorage_PublishVideo_(intptr_t instancePtr, EWorkshopVideoProvider eVideoProvider, const char * pchVideoAccount, const char * pchVideoIdentifier, const char * pchPreviewFile, AppId_t nConsumerAppId, const char * pchTitle, const char * pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, struct SteamParamStringArray_t * pTags)
{
  TRACE("((intptr_t)%p, (EWorkshopVideoProvider)%p, (const char *)\"%s\", (const char *)\"%s\", (const char *)\"%s\", (AppId_t)%p, (const char *)\"%s\", (const char *)\"%s\", (ERemoteStoragePublishedFileVisibility)%p, (struct SteamParamStringArray_t *)%p)\n", instancePtr, eVideoProvider, pchVideoAccount, pchVideoIdentifier, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, pTags);
  SteamAPICall_t result = SteamAPI_ISteamRemoteStorage_PublishVideo(instancePtr, eVideoProvider, pchVideoAccount, pchVideoIdentifier, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, pTags);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamRemoteStorage_SetUserPublishedFileAction_(intptr_t instancePtr, PublishedFileId_t unPublishedFileId, EWorkshopFileAction eAction)
{
  TRACE("((intptr_t)%p, (PublishedFileId_t)%p, (EWorkshopFileAction)%p)\n", instancePtr, unPublishedFileId, eAction);
  SteamAPICall_t result = SteamAPI_ISteamRemoteStorage_SetUserPublishedFileAction(instancePtr, unPublishedFileId, eAction);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamRemoteStorage_EnumeratePublishedFilesByUserAction_(intptr_t instancePtr, EWorkshopFileAction eAction, uint32 unStartIndex)
{
  TRACE("((intptr_t)%p, (EWorkshopFileAction)%p, (uint32)%d)\n", instancePtr, eAction, unStartIndex);
  SteamAPICall_t result = SteamAPI_ISteamRemoteStorage_EnumeratePublishedFilesByUserAction(instancePtr, eAction, unStartIndex);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamRemoteStorage_EnumeratePublishedWorkshopFiles_(intptr_t instancePtr, EWorkshopEnumerationType eEnumerationType, uint32 unStartIndex, uint32 unCount, uint32 unDays, struct SteamParamStringArray_t * pTags, struct SteamParamStringArray_t * pUserTags)
{
  TRACE("((intptr_t)%p, (EWorkshopEnumerationType)%p, (uint32)%d, (uint32)%d, (uint32)%d, (struct SteamParamStringArray_t *)%p, (struct SteamParamStringArray_t *)%p)\n", instancePtr, eEnumerationType, unStartIndex, unCount, unDays, pTags, pUserTags);
  SteamAPICall_t result = SteamAPI_ISteamRemoteStorage_EnumeratePublishedWorkshopFiles(instancePtr, eEnumerationType, unStartIndex, unCount, unDays, pTags, pUserTags);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamRemoteStorage_UGCDownloadToLocation_(intptr_t instancePtr, UGCHandle_t hContent, const char * pchLocation, uint32 unPriority)
{
  TRACE("((intptr_t)%p, (UGCHandle_t)%p, (const char *)\"%s\", (uint32)%d)\n", instancePtr, hContent, pchLocation, unPriority);
  SteamAPICall_t result = SteamAPI_ISteamRemoteStorage_UGCDownloadToLocation(instancePtr, hContent, pchLocation, unPriority);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
bool SteamAPI_ISteamUserStats_RequestCurrentStats_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamUserStats_RequestCurrentStats(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUserStats_GetStat_(intptr_t instancePtr, const char * pchName, int32 * pData)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (int32 *)%p)\n", instancePtr, pchName, pData);
  bool result = SteamAPI_ISteamUserStats_GetStat(instancePtr, pchName, pData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUserStats_GetStat0_(intptr_t instancePtr, const char * pchName, float * pData)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (float *)%f)\n", instancePtr, pchName, pData);
  bool result = SteamAPI_ISteamUserStats_GetStat0(instancePtr, pchName, pData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUserStats_SetStat_(intptr_t instancePtr, const char * pchName, int32 nData)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (int32)%d)\n", instancePtr, pchName, nData);
  bool result = SteamAPI_ISteamUserStats_SetStat(instancePtr, pchName, nData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUserStats_SetStat0_(intptr_t instancePtr, const char * pchName, float fData)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (float)%f)\n", instancePtr, pchName, fData);
  bool result = SteamAPI_ISteamUserStats_SetStat0(instancePtr, pchName, fData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUserStats_UpdateAvgRateStat_(intptr_t instancePtr, const char * pchName, float flCountThisSession, double dSessionLength)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (float)%f, (double)%p)\n", instancePtr, pchName, flCountThisSession, dSessionLength);
  bool result = SteamAPI_ISteamUserStats_UpdateAvgRateStat(instancePtr, pchName, flCountThisSession, dSessionLength);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUserStats_GetAchievement_(intptr_t instancePtr, const char * pchName, bool * pbAchieved)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (bool *)%p)\n", instancePtr, pchName, pbAchieved);
  bool result = SteamAPI_ISteamUserStats_GetAchievement(instancePtr, pchName, pbAchieved);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUserStats_SetAchievement_(intptr_t instancePtr, const char * pchName)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchName);
  bool result = SteamAPI_ISteamUserStats_SetAchievement(instancePtr, pchName);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUserStats_ClearAchievement_(intptr_t instancePtr, const char * pchName)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchName);
  bool result = SteamAPI_ISteamUserStats_ClearAchievement(instancePtr, pchName);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUserStats_GetAchievementAndUnlockTime_(intptr_t instancePtr, const char * pchName, bool * pbAchieved, uint32 * punUnlockTime)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (bool *)%p, (uint32 *)%p)\n", instancePtr, pchName, pbAchieved, punUnlockTime);
  bool result = SteamAPI_ISteamUserStats_GetAchievementAndUnlockTime(instancePtr, pchName, pbAchieved, punUnlockTime);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUserStats_StoreStats_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamUserStats_StoreStats(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int SteamAPI_ISteamUserStats_GetAchievementIcon_(intptr_t instancePtr, const char * pchName)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchName);
  int result = SteamAPI_ISteamUserStats_GetAchievementIcon(instancePtr, pchName);
  TRACE(" = (int)%d\n", result);
  return result;
}
const char * SteamAPI_ISteamUserStats_GetAchievementDisplayAttribute_(intptr_t instancePtr, const char * pchName, const char * pchKey)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (const char *)\"%s\")\n", instancePtr, pchName, pchKey);
  const char * result = SteamAPI_ISteamUserStats_GetAchievementDisplayAttribute(instancePtr, pchName, pchKey);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
bool SteamAPI_ISteamUserStats_IndicateAchievementProgress_(intptr_t instancePtr, const char * pchName, uint32 nCurProgress, uint32 nMaxProgress)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (uint32)%d, (uint32)%d)\n", instancePtr, pchName, nCurProgress, nMaxProgress);
  bool result = SteamAPI_ISteamUserStats_IndicateAchievementProgress(instancePtr, pchName, nCurProgress, nMaxProgress);
  TRACE(" = (bool)%d\n", result);
  return result;
}
uint32 SteamAPI_ISteamUserStats_GetNumAchievements_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  uint32 result = SteamAPI_ISteamUserStats_GetNumAchievements(instancePtr);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
const char * SteamAPI_ISteamUserStats_GetAchievementName_(intptr_t instancePtr, uint32 iAchievement)
{
  TRACE("((intptr_t)%p, (uint32)%d)\n", instancePtr, iAchievement);
  const char * result = SteamAPI_ISteamUserStats_GetAchievementName(instancePtr, iAchievement);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamUserStats_RequestUserStats_(intptr_t instancePtr, class CSteamID steamIDUser)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDUser);
  SteamAPICall_t result = SteamAPI_ISteamUserStats_RequestUserStats(instancePtr, steamIDUser);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
bool SteamAPI_ISteamUserStats_GetUserStat_(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, int32 * pData)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const char *)\"%s\", (int32 *)%p)\n", instancePtr, steamIDUser, pchName, pData);
  bool result = SteamAPI_ISteamUserStats_GetUserStat(instancePtr, steamIDUser, pchName, pData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUserStats_GetUserStat0_(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, float * pData)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const char *)\"%s\", (float *)%f)\n", instancePtr, steamIDUser, pchName, pData);
  bool result = SteamAPI_ISteamUserStats_GetUserStat0(instancePtr, steamIDUser, pchName, pData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUserStats_GetUserAchievement_(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, bool * pbAchieved)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const char *)\"%s\", (bool *)%p)\n", instancePtr, steamIDUser, pchName, pbAchieved);
  bool result = SteamAPI_ISteamUserStats_GetUserAchievement(instancePtr, steamIDUser, pchName, pbAchieved);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUserStats_GetUserAchievementAndUnlockTime_(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, bool * pbAchieved, uint32 * punUnlockTime)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const char *)\"%s\", (bool *)%p, (uint32 *)%p)\n", instancePtr, steamIDUser, pchName, pbAchieved, punUnlockTime);
  bool result = SteamAPI_ISteamUserStats_GetUserAchievementAndUnlockTime(instancePtr, steamIDUser, pchName, pbAchieved, punUnlockTime);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUserStats_ResetAllStats_(intptr_t instancePtr, bool bAchievementsToo)
{
  TRACE("((intptr_t)%p, (bool)%d)\n", instancePtr, bAchievementsToo);
  bool result = SteamAPI_ISteamUserStats_ResetAllStats(instancePtr, bAchievementsToo);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamUserStats_FindOrCreateLeaderboard_(intptr_t instancePtr, const char * pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (ELeaderboardSortMethod)%p, (ELeaderboardDisplayType)%p)\n", instancePtr, pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType);
  SteamAPICall_t result = SteamAPI_ISteamUserStats_FindOrCreateLeaderboard(instancePtr, pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamUserStats_FindLeaderboard_(intptr_t instancePtr, const char * pchLeaderboardName)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchLeaderboardName);
  SteamAPICall_t result = SteamAPI_ISteamUserStats_FindLeaderboard(instancePtr, pchLeaderboardName);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
const char * SteamAPI_ISteamUserStats_GetLeaderboardName_(intptr_t instancePtr, SteamLeaderboard_t hSteamLeaderboard)
{
  TRACE("((intptr_t)%p, (SteamLeaderboard_t)%p)\n", instancePtr, hSteamLeaderboard);
  const char * result = SteamAPI_ISteamUserStats_GetLeaderboardName(instancePtr, hSteamLeaderboard);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
int SteamAPI_ISteamUserStats_GetLeaderboardEntryCount_(intptr_t instancePtr, SteamLeaderboard_t hSteamLeaderboard)
{
  TRACE("((intptr_t)%p, (SteamLeaderboard_t)%p)\n", instancePtr, hSteamLeaderboard);
  int result = SteamAPI_ISteamUserStats_GetLeaderboardEntryCount(instancePtr, hSteamLeaderboard);
  TRACE(" = (int)%d\n", result);
  return result;
}
ELeaderboardSortMethod SteamAPI_ISteamUserStats_GetLeaderboardSortMethod_(intptr_t instancePtr, SteamLeaderboard_t hSteamLeaderboard)
{
  TRACE("((intptr_t)%p, (SteamLeaderboard_t)%p)\n", instancePtr, hSteamLeaderboard);
  ELeaderboardSortMethod result = SteamAPI_ISteamUserStats_GetLeaderboardSortMethod(instancePtr, hSteamLeaderboard);
  TRACE(" = (ELeaderboardSortMethod)%p\n", result);
  return result;
}
ELeaderboardDisplayType SteamAPI_ISteamUserStats_GetLeaderboardDisplayType_(intptr_t instancePtr, SteamLeaderboard_t hSteamLeaderboard)
{
  TRACE("((intptr_t)%p, (SteamLeaderboard_t)%p)\n", instancePtr, hSteamLeaderboard);
  ELeaderboardDisplayType result = SteamAPI_ISteamUserStats_GetLeaderboardDisplayType(instancePtr, hSteamLeaderboard);
  TRACE(" = (ELeaderboardDisplayType)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamUserStats_DownloadLeaderboardEntries_(intptr_t instancePtr, SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd)
{
  TRACE("((intptr_t)%p, (SteamLeaderboard_t)%p, (ELeaderboardDataRequest)%p, (int)%d, (int)%d)\n", instancePtr, hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd);
  SteamAPICall_t result = SteamAPI_ISteamUserStats_DownloadLeaderboardEntries(instancePtr, hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamUserStats_DownloadLeaderboardEntriesForUsers_(intptr_t instancePtr, SteamLeaderboard_t hSteamLeaderboard, class CSteamID * prgUsers, int cUsers)
{
  TRACE("((intptr_t)%p, (SteamLeaderboard_t)%p, (class CSteamID *)%p, (int)%d)\n", instancePtr, hSteamLeaderboard, prgUsers, cUsers);
  SteamAPICall_t result = SteamAPI_ISteamUserStats_DownloadLeaderboardEntriesForUsers(instancePtr, hSteamLeaderboard, prgUsers, cUsers);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
bool SteamAPI_ISteamUserStats_GetDownloadedLeaderboardEntry_(intptr_t instancePtr, SteamLeaderboardEntries_t hSteamLeaderboardEntries, int index, struct LeaderboardEntry_t * pLeaderboardEntry, int32 * pDetails, int cDetailsMax)
{
  TRACE("((intptr_t)%p, (SteamLeaderboardEntries_t)%p, (int)%d, (struct LeaderboardEntry_t *)%p, (int32 *)%p, (int)%d)\n", instancePtr, hSteamLeaderboardEntries, index, pLeaderboardEntry, pDetails, cDetailsMax);
  bool result = SteamAPI_ISteamUserStats_GetDownloadedLeaderboardEntry(instancePtr, hSteamLeaderboardEntries, index, pLeaderboardEntry, pDetails, cDetailsMax);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamUserStats_UploadLeaderboardScore_(intptr_t instancePtr, SteamLeaderboard_t hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int32 nScore, const int32 * pScoreDetails, int cScoreDetailsCount)
{
  TRACE("((intptr_t)%p, (SteamLeaderboard_t)%p, (ELeaderboardUploadScoreMethod)%p, (int32)%d, (const int32 *)%p, (int)%d)\n", instancePtr, hSteamLeaderboard, eLeaderboardUploadScoreMethod, nScore, pScoreDetails, cScoreDetailsCount);
  SteamAPICall_t result = SteamAPI_ISteamUserStats_UploadLeaderboardScore(instancePtr, hSteamLeaderboard, eLeaderboardUploadScoreMethod, nScore, pScoreDetails, cScoreDetailsCount);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamUserStats_AttachLeaderboardUGC_(intptr_t instancePtr, SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC)
{
  TRACE("((intptr_t)%p, (SteamLeaderboard_t)%p, (UGCHandle_t)%p)\n", instancePtr, hSteamLeaderboard, hUGC);
  SteamAPICall_t result = SteamAPI_ISteamUserStats_AttachLeaderboardUGC(instancePtr, hSteamLeaderboard, hUGC);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamUserStats_GetNumberOfCurrentPlayers_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPICall_t result = SteamAPI_ISteamUserStats_GetNumberOfCurrentPlayers(instancePtr);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamUserStats_RequestGlobalAchievementPercentages_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPICall_t result = SteamAPI_ISteamUserStats_RequestGlobalAchievementPercentages(instancePtr);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
int SteamAPI_ISteamUserStats_GetMostAchievedAchievementInfo_(intptr_t instancePtr, char * pchName, uint32 unNameBufLen, float * pflPercent, bool * pbAchieved)
{
  TRACE("((intptr_t)%p, (char *)%p, (uint32)%d, (float *)%f, (bool *)%p)\n", instancePtr, pchName, unNameBufLen, pflPercent, pbAchieved);
  int result = SteamAPI_ISteamUserStats_GetMostAchievedAchievementInfo(instancePtr, pchName, unNameBufLen, pflPercent, pbAchieved);
  TRACE(" = (int)%d\n", result);
  return result;
}
int SteamAPI_ISteamUserStats_GetNextMostAchievedAchievementInfo_(intptr_t instancePtr, int iIteratorPrevious, char * pchName, uint32 unNameBufLen, float * pflPercent, bool * pbAchieved)
{
  TRACE("((intptr_t)%p, (int)%d, (char *)%p, (uint32)%d, (float *)%f, (bool *)%p)\n", instancePtr, iIteratorPrevious, pchName, unNameBufLen, pflPercent, pbAchieved);
  int result = SteamAPI_ISteamUserStats_GetNextMostAchievedAchievementInfo(instancePtr, iIteratorPrevious, pchName, unNameBufLen, pflPercent, pbAchieved);
  TRACE(" = (int)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUserStats_GetAchievementAchievedPercent_(intptr_t instancePtr, const char * pchName, float * pflPercent)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (float *)%f)\n", instancePtr, pchName, pflPercent);
  bool result = SteamAPI_ISteamUserStats_GetAchievementAchievedPercent(instancePtr, pchName, pflPercent);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamUserStats_RequestGlobalStats_(intptr_t instancePtr, int nHistoryDays)
{
  TRACE("((intptr_t)%p, (int)%d)\n", instancePtr, nHistoryDays);
  SteamAPICall_t result = SteamAPI_ISteamUserStats_RequestGlobalStats(instancePtr, nHistoryDays);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
bool SteamAPI_ISteamUserStats_GetGlobalStat_(intptr_t instancePtr, const char * pchStatName, int64 * pData)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (int64 *)%p)\n", instancePtr, pchStatName, pData);
  bool result = SteamAPI_ISteamUserStats_GetGlobalStat(instancePtr, pchStatName, pData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUserStats_GetGlobalStat0_(intptr_t instancePtr, const char * pchStatName, double * pData)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (double *)%p)\n", instancePtr, pchStatName, pData);
  bool result = SteamAPI_ISteamUserStats_GetGlobalStat0(instancePtr, pchStatName, pData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int32 SteamAPI_ISteamUserStats_GetGlobalStatHistory_(intptr_t instancePtr, const char * pchStatName, int64 * pData, uint32 cubData)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (int64 *)%p, (uint32)%d)\n", instancePtr, pchStatName, pData, cubData);
  int32 result = SteamAPI_ISteamUserStats_GetGlobalStatHistory(instancePtr, pchStatName, pData, cubData);
  TRACE(" = (int32)%d\n", result);
  return result;
}
int32 SteamAPI_ISteamUserStats_GetGlobalStatHistory0_(intptr_t instancePtr, const char * pchStatName, double * pData, uint32 cubData)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (double *)%p, (uint32)%d)\n", instancePtr, pchStatName, pData, cubData);
  int32 result = SteamAPI_ISteamUserStats_GetGlobalStatHistory0(instancePtr, pchStatName, pData, cubData);
  TRACE(" = (int32)%d\n", result);
  return result;
}
bool SteamAPI_ISteamApps_BIsSubscribed_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamApps_BIsSubscribed(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamApps_BIsLowViolence_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamApps_BIsLowViolence(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamApps_BIsCybercafe_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamApps_BIsCybercafe(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamApps_BIsVACBanned_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamApps_BIsVACBanned(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
const char * SteamAPI_ISteamApps_GetCurrentGameLanguage_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  const char * result = SteamAPI_ISteamApps_GetCurrentGameLanguage(instancePtr);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
const char * SteamAPI_ISteamApps_GetAvailableGameLanguages_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  const char * result = SteamAPI_ISteamApps_GetAvailableGameLanguages(instancePtr);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
bool SteamAPI_ISteamApps_BIsSubscribedApp_(intptr_t instancePtr, AppId_t appID)
{
  TRACE("((intptr_t)%p, (AppId_t)%p)\n", instancePtr, appID);
  bool result = SteamAPI_ISteamApps_BIsSubscribedApp(instancePtr, appID);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamApps_BIsDlcInstalled_(intptr_t instancePtr, AppId_t appID)
{
  TRACE("((intptr_t)%p, (AppId_t)%p)\n", instancePtr, appID);
  bool result = SteamAPI_ISteamApps_BIsDlcInstalled(instancePtr, appID);
  TRACE(" = (bool)%d\n", result);
  return result;
}
uint32 SteamAPI_ISteamApps_GetEarliestPurchaseUnixTime_(intptr_t instancePtr, AppId_t nAppID)
{
  TRACE("((intptr_t)%p, (AppId_t)%p)\n", instancePtr, nAppID);
  uint32 result = SteamAPI_ISteamApps_GetEarliestPurchaseUnixTime(instancePtr, nAppID);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
bool SteamAPI_ISteamApps_BIsSubscribedFromFreeWeekend_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamApps_BIsSubscribedFromFreeWeekend(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int SteamAPI_ISteamApps_GetDLCCount_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  int result = SteamAPI_ISteamApps_GetDLCCount(instancePtr);
  TRACE(" = (int)%d\n", result);
  return result;
}
bool SteamAPI_ISteamApps_BGetDLCDataByIndex_(intptr_t instancePtr, int iDLC, AppId_t * pAppID, bool * pbAvailable, char * pchName, int cchNameBufferSize)
{
  TRACE("((intptr_t)%p, (int)%d, (AppId_t *)%p, (bool *)%p, (char *)%p, (int)%d)\n", instancePtr, iDLC, pAppID, pbAvailable, pchName, cchNameBufferSize);
  bool result = SteamAPI_ISteamApps_BGetDLCDataByIndex(instancePtr, iDLC, pAppID, pbAvailable, pchName, cchNameBufferSize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void SteamAPI_ISteamApps_InstallDLC_(intptr_t instancePtr, AppId_t nAppID)
{
  TRACE("((intptr_t)%p, (AppId_t)%p)\n", instancePtr, nAppID);
  SteamAPI_ISteamApps_InstallDLC(instancePtr, nAppID);
}
void SteamAPI_ISteamApps_UninstallDLC_(intptr_t instancePtr, AppId_t nAppID)
{
  TRACE("((intptr_t)%p, (AppId_t)%p)\n", instancePtr, nAppID);
  SteamAPI_ISteamApps_UninstallDLC(instancePtr, nAppID);
}
void SteamAPI_ISteamApps_RequestAppProofOfPurchaseKey_(intptr_t instancePtr, AppId_t nAppID)
{
  TRACE("((intptr_t)%p, (AppId_t)%p)\n", instancePtr, nAppID);
  SteamAPI_ISteamApps_RequestAppProofOfPurchaseKey(instancePtr, nAppID);
}
bool SteamAPI_ISteamApps_GetCurrentBetaName_(intptr_t instancePtr, char * pchName, int cchNameBufferSize)
{
  TRACE("((intptr_t)%p, (char *)%p, (int)%d)\n", instancePtr, pchName, cchNameBufferSize);
  bool result = SteamAPI_ISteamApps_GetCurrentBetaName(instancePtr, pchName, cchNameBufferSize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamApps_MarkContentCorrupt_(intptr_t instancePtr, bool bMissingFilesOnly)
{
  TRACE("((intptr_t)%p, (bool)%d)\n", instancePtr, bMissingFilesOnly);
  bool result = SteamAPI_ISteamApps_MarkContentCorrupt(instancePtr, bMissingFilesOnly);
  TRACE(" = (bool)%d\n", result);
  return result;
}
uint32 SteamAPI_ISteamApps_GetInstalledDepots_(intptr_t instancePtr, AppId_t appID, DepotId_t * pvecDepots, uint32 cMaxDepots)
{
  TRACE("((intptr_t)%p, (AppId_t)%p, (DepotId_t *)%p, (uint32)%d)\n", instancePtr, appID, pvecDepots, cMaxDepots);
  uint32 result = SteamAPI_ISteamApps_GetInstalledDepots(instancePtr, appID, pvecDepots, cMaxDepots);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
uint32 SteamAPI_ISteamApps_GetAppInstallDir_(intptr_t instancePtr, AppId_t appID, char * pchFolder, uint32 cchFolderBufferSize)
{
  TRACE("((intptr_t)%p, (AppId_t)%p, (char *)%p, (uint32)%d)\n", instancePtr, appID, pchFolder, cchFolderBufferSize);
  uint32 result = SteamAPI_ISteamApps_GetAppInstallDir(instancePtr, appID, pchFolder, cchFolderBufferSize);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
bool SteamAPI_ISteamApps_BIsAppInstalled_(intptr_t instancePtr, AppId_t appID)
{
  TRACE("((intptr_t)%p, (AppId_t)%p)\n", instancePtr, appID);
  bool result = SteamAPI_ISteamApps_BIsAppInstalled(instancePtr, appID);
  TRACE(" = (bool)%d\n", result);
  return result;
}
uint64 SteamAPI_ISteamApps_GetAppOwner_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  uint64 result = SteamAPI_ISteamApps_GetAppOwner(instancePtr);
  TRACE(" = (uint64)%d\n", result);
  return result;
}
const char * SteamAPI_ISteamApps_GetLaunchQueryParam_(intptr_t instancePtr, const char * pchKey)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchKey);
  const char * result = SteamAPI_ISteamApps_GetLaunchQueryParam(instancePtr, pchKey);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
bool SteamAPI_ISteamApps_GetDlcDownloadProgress_(intptr_t instancePtr, AppId_t nAppID, uint64 * punBytesDownloaded, uint64 * punBytesTotal)
{
  TRACE("((intptr_t)%p, (AppId_t)%p, (uint64 *)%p, (uint64 *)%p)\n", instancePtr, nAppID, punBytesDownloaded, punBytesTotal);
  bool result = SteamAPI_ISteamApps_GetDlcDownloadProgress(instancePtr, nAppID, punBytesDownloaded, punBytesTotal);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int SteamAPI_ISteamApps_GetAppBuildId_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  int result = SteamAPI_ISteamApps_GetAppBuildId(instancePtr);
  TRACE(" = (int)%d\n", result);
  return result;
}
bool SteamAPI_ISteamNetworking_SendP2PPacket_(intptr_t instancePtr, class CSteamID steamIDRemote, const void * pubData, uint32 cubData, EP2PSend eP2PSendType, int nChannel)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const void *)%p, (uint32)%d, (EP2PSend)%p, (int)%d)\n", instancePtr, steamIDRemote, pubData, cubData, eP2PSendType, nChannel);
  bool result = SteamAPI_ISteamNetworking_SendP2PPacket(instancePtr, steamIDRemote, pubData, cubData, eP2PSendType, nChannel);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamNetworking_IsP2PPacketAvailable_(intptr_t instancePtr, uint32 * pcubMsgSize, int nChannel)
{
  TRACE("((intptr_t)%p, (uint32 *)%p, (int)%d)\n", instancePtr, pcubMsgSize, nChannel);
  bool result = SteamAPI_ISteamNetworking_IsP2PPacketAvailable(instancePtr, pcubMsgSize, nChannel);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamNetworking_ReadP2PPacket_(intptr_t instancePtr, void * pubDest, uint32 cubDest, uint32 * pcubMsgSize, class CSteamID * psteamIDRemote, int nChannel)
{
  TRACE("((intptr_t)%p, (void *)%p, (uint32)%d, (uint32 *)%p, (class CSteamID *)%p, (int)%d)\n", instancePtr, pubDest, cubDest, pcubMsgSize, psteamIDRemote, nChannel);
  bool result = SteamAPI_ISteamNetworking_ReadP2PPacket(instancePtr, pubDest, cubDest, pcubMsgSize, psteamIDRemote, nChannel);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamNetworking_AcceptP2PSessionWithUser_(intptr_t instancePtr, class CSteamID steamIDRemote)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDRemote);
  bool result = SteamAPI_ISteamNetworking_AcceptP2PSessionWithUser(instancePtr, steamIDRemote);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamNetworking_CloseP2PSessionWithUser_(intptr_t instancePtr, class CSteamID steamIDRemote)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDRemote);
  bool result = SteamAPI_ISteamNetworking_CloseP2PSessionWithUser(instancePtr, steamIDRemote);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamNetworking_CloseP2PChannelWithUser_(intptr_t instancePtr, class CSteamID steamIDRemote, int nChannel)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (int)%d)\n", instancePtr, steamIDRemote, nChannel);
  bool result = SteamAPI_ISteamNetworking_CloseP2PChannelWithUser(instancePtr, steamIDRemote, nChannel);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamNetworking_GetP2PSessionState_(intptr_t instancePtr, class CSteamID steamIDRemote, struct P2PSessionState_t * pConnectionState)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (struct P2PSessionState_t *)%p)\n", instancePtr, steamIDRemote, pConnectionState);
  bool result = SteamAPI_ISteamNetworking_GetP2PSessionState(instancePtr, steamIDRemote, pConnectionState);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamNetworking_AllowP2PPacketRelay_(intptr_t instancePtr, bool bAllow)
{
  TRACE("((intptr_t)%p, (bool)%d)\n", instancePtr, bAllow);
  bool result = SteamAPI_ISteamNetworking_AllowP2PPacketRelay(instancePtr, bAllow);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SNetListenSocket_t SteamAPI_ISteamNetworking_CreateListenSocket_(intptr_t instancePtr, int nVirtualP2PPort, uint32 nIP, uint16 nPort, bool bAllowUseOfPacketRelay)
{
  TRACE("((intptr_t)%p, (int)%d, (uint32)%d, (uint16)%d, (bool)%d)\n", instancePtr, nVirtualP2PPort, nIP, nPort, bAllowUseOfPacketRelay);
  SNetListenSocket_t result = SteamAPI_ISteamNetworking_CreateListenSocket(instancePtr, nVirtualP2PPort, nIP, nPort, bAllowUseOfPacketRelay);
  TRACE(" = (SNetListenSocket_t)%p\n", result);
  return result;
}
SNetSocket_t SteamAPI_ISteamNetworking_CreateP2PConnectionSocket_(intptr_t instancePtr, class CSteamID steamIDTarget, int nVirtualPort, int nTimeoutSec, bool bAllowUseOfPacketRelay)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (int)%d, (int)%d, (bool)%d)\n", instancePtr, steamIDTarget, nVirtualPort, nTimeoutSec, bAllowUseOfPacketRelay);
  SNetSocket_t result = SteamAPI_ISteamNetworking_CreateP2PConnectionSocket(instancePtr, steamIDTarget, nVirtualPort, nTimeoutSec, bAllowUseOfPacketRelay);
  TRACE(" = (SNetSocket_t)%p\n", result);
  return result;
}
SNetSocket_t SteamAPI_ISteamNetworking_CreateConnectionSocket_(intptr_t instancePtr, uint32 nIP, uint16 nPort, int nTimeoutSec)
{
  TRACE("((intptr_t)%p, (uint32)%d, (uint16)%d, (int)%d)\n", instancePtr, nIP, nPort, nTimeoutSec);
  SNetSocket_t result = SteamAPI_ISteamNetworking_CreateConnectionSocket(instancePtr, nIP, nPort, nTimeoutSec);
  TRACE(" = (SNetSocket_t)%p\n", result);
  return result;
}
bool SteamAPI_ISteamNetworking_DestroySocket_(intptr_t instancePtr, SNetSocket_t hSocket, bool bNotifyRemoteEnd)
{
  TRACE("((intptr_t)%p, (SNetSocket_t)%p, (bool)%d)\n", instancePtr, hSocket, bNotifyRemoteEnd);
  bool result = SteamAPI_ISteamNetworking_DestroySocket(instancePtr, hSocket, bNotifyRemoteEnd);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamNetworking_DestroyListenSocket_(intptr_t instancePtr, SNetListenSocket_t hSocket, bool bNotifyRemoteEnd)
{
  TRACE("((intptr_t)%p, (SNetListenSocket_t)%p, (bool)%d)\n", instancePtr, hSocket, bNotifyRemoteEnd);
  bool result = SteamAPI_ISteamNetworking_DestroyListenSocket(instancePtr, hSocket, bNotifyRemoteEnd);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamNetworking_SendDataOnSocket_(intptr_t instancePtr, SNetSocket_t hSocket, void * pubData, uint32 cubData, bool bReliable)
{
  TRACE("((intptr_t)%p, (SNetSocket_t)%p, (void *)%p, (uint32)%d, (bool)%d)\n", instancePtr, hSocket, pubData, cubData, bReliable);
  bool result = SteamAPI_ISteamNetworking_SendDataOnSocket(instancePtr, hSocket, pubData, cubData, bReliable);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamNetworking_IsDataAvailableOnSocket_(intptr_t instancePtr, SNetSocket_t hSocket, uint32 * pcubMsgSize)
{
  TRACE("((intptr_t)%p, (SNetSocket_t)%p, (uint32 *)%p)\n", instancePtr, hSocket, pcubMsgSize);
  bool result = SteamAPI_ISteamNetworking_IsDataAvailableOnSocket(instancePtr, hSocket, pcubMsgSize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamNetworking_RetrieveDataFromSocket_(intptr_t instancePtr, SNetSocket_t hSocket, void * pubDest, uint32 cubDest, uint32 * pcubMsgSize)
{
  TRACE("((intptr_t)%p, (SNetSocket_t)%p, (void *)%p, (uint32)%d, (uint32 *)%p)\n", instancePtr, hSocket, pubDest, cubDest, pcubMsgSize);
  bool result = SteamAPI_ISteamNetworking_RetrieveDataFromSocket(instancePtr, hSocket, pubDest, cubDest, pcubMsgSize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamNetworking_IsDataAvailable_(intptr_t instancePtr, SNetListenSocket_t hListenSocket, uint32 * pcubMsgSize, SNetSocket_t * phSocket)
{
  TRACE("((intptr_t)%p, (SNetListenSocket_t)%p, (uint32 *)%p, (SNetSocket_t *)%p)\n", instancePtr, hListenSocket, pcubMsgSize, phSocket);
  bool result = SteamAPI_ISteamNetworking_IsDataAvailable(instancePtr, hListenSocket, pcubMsgSize, phSocket);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamNetworking_RetrieveData_(intptr_t instancePtr, SNetListenSocket_t hListenSocket, void * pubDest, uint32 cubDest, uint32 * pcubMsgSize, SNetSocket_t * phSocket)
{
  TRACE("((intptr_t)%p, (SNetListenSocket_t)%p, (void *)%p, (uint32)%d, (uint32 *)%p, (SNetSocket_t *)%p)\n", instancePtr, hListenSocket, pubDest, cubDest, pcubMsgSize, phSocket);
  bool result = SteamAPI_ISteamNetworking_RetrieveData(instancePtr, hListenSocket, pubDest, cubDest, pcubMsgSize, phSocket);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamNetworking_GetSocketInfo_(intptr_t instancePtr, SNetSocket_t hSocket, class CSteamID * pSteamIDRemote, int * peSocketStatus, uint32 * punIPRemote, uint16 * punPortRemote)
{
  TRACE("((intptr_t)%p, (SNetSocket_t)%p, (class CSteamID *)%p, (int *)%p, (uint32 *)%p, (uint16 *)%p)\n", instancePtr, hSocket, pSteamIDRemote, peSocketStatus, punIPRemote, punPortRemote);
  bool result = SteamAPI_ISteamNetworking_GetSocketInfo(instancePtr, hSocket, pSteamIDRemote, peSocketStatus, punIPRemote, punPortRemote);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamNetworking_GetListenSocketInfo_(intptr_t instancePtr, SNetListenSocket_t hListenSocket, uint32 * pnIP, uint16 * pnPort)
{
  TRACE("((intptr_t)%p, (SNetListenSocket_t)%p, (uint32 *)%p, (uint16 *)%p)\n", instancePtr, hListenSocket, pnIP, pnPort);
  bool result = SteamAPI_ISteamNetworking_GetListenSocketInfo(instancePtr, hListenSocket, pnIP, pnPort);
  TRACE(" = (bool)%d\n", result);
  return result;
}
ESNetSocketConnectionType SteamAPI_ISteamNetworking_GetSocketConnectionType_(intptr_t instancePtr, SNetSocket_t hSocket)
{
  TRACE("((intptr_t)%p, (SNetSocket_t)%p)\n", instancePtr, hSocket);
  ESNetSocketConnectionType result = SteamAPI_ISteamNetworking_GetSocketConnectionType(instancePtr, hSocket);
  TRACE(" = (ESNetSocketConnectionType)%p\n", result);
  return result;
}
int SteamAPI_ISteamNetworking_GetMaxPacketSize_(intptr_t instancePtr, SNetSocket_t hSocket)
{
  TRACE("((intptr_t)%p, (SNetSocket_t)%p)\n", instancePtr, hSocket);
  int result = SteamAPI_ISteamNetworking_GetMaxPacketSize(instancePtr, hSocket);
  TRACE(" = (int)%d\n", result);
  return result;
}
ScreenshotHandle SteamAPI_ISteamScreenshots_WriteScreenshot_(intptr_t instancePtr, void * pubRGB, uint32 cubRGB, int nWidth, int nHeight)
{
  TRACE("((intptr_t)%p, (void *)%p, (uint32)%d, (int)%d, (int)%d)\n", instancePtr, pubRGB, cubRGB, nWidth, nHeight);
  ScreenshotHandle result = SteamAPI_ISteamScreenshots_WriteScreenshot(instancePtr, pubRGB, cubRGB, nWidth, nHeight);
  TRACE(" = (ScreenshotHandle)%p\n", result);
  return result;
}
ScreenshotHandle SteamAPI_ISteamScreenshots_AddScreenshotToLibrary_(intptr_t instancePtr, const char * pchFilename, const char * pchThumbnailFilename, int nWidth, int nHeight)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (const char *)\"%s\", (int)%d, (int)%d)\n", instancePtr, pchFilename, pchThumbnailFilename, nWidth, nHeight);
  ScreenshotHandle result = SteamAPI_ISteamScreenshots_AddScreenshotToLibrary(instancePtr, pchFilename, pchThumbnailFilename, nWidth, nHeight);
  TRACE(" = (ScreenshotHandle)%p\n", result);
  return result;
}
void SteamAPI_ISteamScreenshots_TriggerScreenshot_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPI_ISteamScreenshots_TriggerScreenshot(instancePtr);
}
void SteamAPI_ISteamScreenshots_HookScreenshots_(intptr_t instancePtr, bool bHook)
{
  TRACE("((intptr_t)%p, (bool)%d)\n", instancePtr, bHook);
  SteamAPI_ISteamScreenshots_HookScreenshots(instancePtr, bHook);
}
bool SteamAPI_ISteamScreenshots_SetLocation_(intptr_t instancePtr, ScreenshotHandle hScreenshot, const char * pchLocation)
{
  TRACE("((intptr_t)%p, (ScreenshotHandle)%p, (const char *)\"%s\")\n", instancePtr, hScreenshot, pchLocation);
  bool result = SteamAPI_ISteamScreenshots_SetLocation(instancePtr, hScreenshot, pchLocation);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamScreenshots_TagUser_(intptr_t instancePtr, ScreenshotHandle hScreenshot, class CSteamID steamID)
{
  TRACE("((intptr_t)%p, (ScreenshotHandle)%p, (class CSteamID)%p)\n", instancePtr, hScreenshot, steamID);
  bool result = SteamAPI_ISteamScreenshots_TagUser(instancePtr, hScreenshot, steamID);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamScreenshots_TagPublishedFile_(intptr_t instancePtr, ScreenshotHandle hScreenshot, PublishedFileId_t unPublishedFileID)
{
  TRACE("((intptr_t)%p, (ScreenshotHandle)%p, (PublishedFileId_t)%p)\n", instancePtr, hScreenshot, unPublishedFileID);
  bool result = SteamAPI_ISteamScreenshots_TagPublishedFile(instancePtr, hScreenshot, unPublishedFileID);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusic_BIsEnabled_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamMusic_BIsEnabled(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusic_BIsPlaying_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamMusic_BIsPlaying(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
AudioPlayback_Status SteamAPI_ISteamMusic_GetPlaybackStatus_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  AudioPlayback_Status result = SteamAPI_ISteamMusic_GetPlaybackStatus(instancePtr);
  TRACE(" = (AudioPlayback_Status)%p\n", result);
  return result;
}
void SteamAPI_ISteamMusic_Play_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPI_ISteamMusic_Play(instancePtr);
}
void SteamAPI_ISteamMusic_Pause_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPI_ISteamMusic_Pause(instancePtr);
}
void SteamAPI_ISteamMusic_PlayPrevious_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPI_ISteamMusic_PlayPrevious(instancePtr);
}
void SteamAPI_ISteamMusic_PlayNext_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPI_ISteamMusic_PlayNext(instancePtr);
}
void SteamAPI_ISteamMusic_SetVolume_(intptr_t instancePtr, float flVolume)
{
  TRACE("((intptr_t)%p, (float)%f)\n", instancePtr, flVolume);
  SteamAPI_ISteamMusic_SetVolume(instancePtr, flVolume);
}
float SteamAPI_ISteamMusic_GetVolume_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  float result = SteamAPI_ISteamMusic_GetVolume(instancePtr);
  TRACE(" = (float)%f\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_RegisterSteamMusicRemote_(intptr_t instancePtr, const char * pchName)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchName);
  bool result = SteamAPI_ISteamMusicRemote_RegisterSteamMusicRemote(instancePtr, pchName);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_DeregisterSteamMusicRemote_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamMusicRemote_DeregisterSteamMusicRemote(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_BIsCurrentMusicRemote_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamMusicRemote_BIsCurrentMusicRemote(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_BActivationSuccess_(intptr_t instancePtr, bool bValue)
{
  TRACE("((intptr_t)%p, (bool)%d)\n", instancePtr, bValue);
  bool result = SteamAPI_ISteamMusicRemote_BActivationSuccess(instancePtr, bValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_SetDisplayName_(intptr_t instancePtr, const char * pchDisplayName)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchDisplayName);
  bool result = SteamAPI_ISteamMusicRemote_SetDisplayName(instancePtr, pchDisplayName);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_SetPNGIcon_64x64_(intptr_t instancePtr, void * pvBuffer, uint32 cbBufferLength)
{
  TRACE("((intptr_t)%p, (void *)%p, (uint32)%d)\n", instancePtr, pvBuffer, cbBufferLength);
  bool result = SteamAPI_ISteamMusicRemote_SetPNGIcon_64x64(instancePtr, pvBuffer, cbBufferLength);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_EnablePlayPrevious_(intptr_t instancePtr, bool bValue)
{
  TRACE("((intptr_t)%p, (bool)%d)\n", instancePtr, bValue);
  bool result = SteamAPI_ISteamMusicRemote_EnablePlayPrevious(instancePtr, bValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_EnablePlayNext_(intptr_t instancePtr, bool bValue)
{
  TRACE("((intptr_t)%p, (bool)%d)\n", instancePtr, bValue);
  bool result = SteamAPI_ISteamMusicRemote_EnablePlayNext(instancePtr, bValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_EnableShuffled_(intptr_t instancePtr, bool bValue)
{
  TRACE("((intptr_t)%p, (bool)%d)\n", instancePtr, bValue);
  bool result = SteamAPI_ISteamMusicRemote_EnableShuffled(instancePtr, bValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_EnableLooped_(intptr_t instancePtr, bool bValue)
{
  TRACE("((intptr_t)%p, (bool)%d)\n", instancePtr, bValue);
  bool result = SteamAPI_ISteamMusicRemote_EnableLooped(instancePtr, bValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_EnableQueue_(intptr_t instancePtr, bool bValue)
{
  TRACE("((intptr_t)%p, (bool)%d)\n", instancePtr, bValue);
  bool result = SteamAPI_ISteamMusicRemote_EnableQueue(instancePtr, bValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_EnablePlaylists_(intptr_t instancePtr, bool bValue)
{
  TRACE("((intptr_t)%p, (bool)%d)\n", instancePtr, bValue);
  bool result = SteamAPI_ISteamMusicRemote_EnablePlaylists(instancePtr, bValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_UpdatePlaybackStatus_(intptr_t instancePtr, AudioPlayback_Status nStatus)
{
  TRACE("((intptr_t)%p, (AudioPlayback_Status)%p)\n", instancePtr, nStatus);
  bool result = SteamAPI_ISteamMusicRemote_UpdatePlaybackStatus(instancePtr, nStatus);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_UpdateShuffled_(intptr_t instancePtr, bool bValue)
{
  TRACE("((intptr_t)%p, (bool)%d)\n", instancePtr, bValue);
  bool result = SteamAPI_ISteamMusicRemote_UpdateShuffled(instancePtr, bValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_UpdateLooped_(intptr_t instancePtr, bool bValue)
{
  TRACE("((intptr_t)%p, (bool)%d)\n", instancePtr, bValue);
  bool result = SteamAPI_ISteamMusicRemote_UpdateLooped(instancePtr, bValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_UpdateVolume_(intptr_t instancePtr, float flValue)
{
  TRACE("((intptr_t)%p, (float)%f)\n", instancePtr, flValue);
  bool result = SteamAPI_ISteamMusicRemote_UpdateVolume(instancePtr, flValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_CurrentEntryWillChange_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamMusicRemote_CurrentEntryWillChange(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_CurrentEntryIsAvailable_(intptr_t instancePtr, bool bAvailable)
{
  TRACE("((intptr_t)%p, (bool)%d)\n", instancePtr, bAvailable);
  bool result = SteamAPI_ISteamMusicRemote_CurrentEntryIsAvailable(instancePtr, bAvailable);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_UpdateCurrentEntryText_(intptr_t instancePtr, const char * pchText)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchText);
  bool result = SteamAPI_ISteamMusicRemote_UpdateCurrentEntryText(instancePtr, pchText);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_UpdateCurrentEntryElapsedSeconds_(intptr_t instancePtr, int nValue)
{
  TRACE("((intptr_t)%p, (int)%d)\n", instancePtr, nValue);
  bool result = SteamAPI_ISteamMusicRemote_UpdateCurrentEntryElapsedSeconds(instancePtr, nValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_UpdateCurrentEntryCoverArt_(intptr_t instancePtr, void * pvBuffer, uint32 cbBufferLength)
{
  TRACE("((intptr_t)%p, (void *)%p, (uint32)%d)\n", instancePtr, pvBuffer, cbBufferLength);
  bool result = SteamAPI_ISteamMusicRemote_UpdateCurrentEntryCoverArt(instancePtr, pvBuffer, cbBufferLength);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_CurrentEntryDidChange_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamMusicRemote_CurrentEntryDidChange(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_QueueWillChange_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamMusicRemote_QueueWillChange(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_ResetQueueEntries_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamMusicRemote_ResetQueueEntries(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_SetQueueEntry_(intptr_t instancePtr, int nID, int nPosition, const char * pchEntryText)
{
  TRACE("((intptr_t)%p, (int)%d, (int)%d, (const char *)\"%s\")\n", instancePtr, nID, nPosition, pchEntryText);
  bool result = SteamAPI_ISteamMusicRemote_SetQueueEntry(instancePtr, nID, nPosition, pchEntryText);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_SetCurrentQueueEntry_(intptr_t instancePtr, int nID)
{
  TRACE("((intptr_t)%p, (int)%d)\n", instancePtr, nID);
  bool result = SteamAPI_ISteamMusicRemote_SetCurrentQueueEntry(instancePtr, nID);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_QueueDidChange_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamMusicRemote_QueueDidChange(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_PlaylistWillChange_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamMusicRemote_PlaylistWillChange(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_ResetPlaylistEntries_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamMusicRemote_ResetPlaylistEntries(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_SetPlaylistEntry_(intptr_t instancePtr, int nID, int nPosition, const char * pchEntryText)
{
  TRACE("((intptr_t)%p, (int)%d, (int)%d, (const char *)\"%s\")\n", instancePtr, nID, nPosition, pchEntryText);
  bool result = SteamAPI_ISteamMusicRemote_SetPlaylistEntry(instancePtr, nID, nPosition, pchEntryText);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_SetCurrentPlaylistEntry_(intptr_t instancePtr, int nID)
{
  TRACE("((intptr_t)%p, (int)%d)\n", instancePtr, nID);
  bool result = SteamAPI_ISteamMusicRemote_SetCurrentPlaylistEntry(instancePtr, nID);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamMusicRemote_PlaylistDidChange_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamMusicRemote_PlaylistDidChange(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
HTTPRequestHandle SteamAPI_ISteamHTTP_CreateHTTPRequest_(intptr_t instancePtr, EHTTPMethod eHTTPRequestMethod, const char * pchAbsoluteURL)
{
  TRACE("((intptr_t)%p, (EHTTPMethod)%p, (const char *)\"%s\")\n", instancePtr, eHTTPRequestMethod, pchAbsoluteURL);
  HTTPRequestHandle result = SteamAPI_ISteamHTTP_CreateHTTPRequest(instancePtr, eHTTPRequestMethod, pchAbsoluteURL);
  TRACE(" = (HTTPRequestHandle)%p\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_SetHTTPRequestContextValue_(intptr_t instancePtr, HTTPRequestHandle hRequest, uint64 ulContextValue)
{
  TRACE("((intptr_t)%p, (HTTPRequestHandle)%p, (uint64)%d)\n", instancePtr, hRequest, ulContextValue);
  bool result = SteamAPI_ISteamHTTP_SetHTTPRequestContextValue(instancePtr, hRequest, ulContextValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_SetHTTPRequestNetworkActivityTimeout_(intptr_t instancePtr, HTTPRequestHandle hRequest, uint32 unTimeoutSeconds)
{
  TRACE("((intptr_t)%p, (HTTPRequestHandle)%p, (uint32)%d)\n", instancePtr, hRequest, unTimeoutSeconds);
  bool result = SteamAPI_ISteamHTTP_SetHTTPRequestNetworkActivityTimeout(instancePtr, hRequest, unTimeoutSeconds);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_SetHTTPRequestHeaderValue_(intptr_t instancePtr, HTTPRequestHandle hRequest, const char * pchHeaderName, const char * pchHeaderValue)
{
  TRACE("((intptr_t)%p, (HTTPRequestHandle)%p, (const char *)\"%s\", (const char *)\"%s\")\n", instancePtr, hRequest, pchHeaderName, pchHeaderValue);
  bool result = SteamAPI_ISteamHTTP_SetHTTPRequestHeaderValue(instancePtr, hRequest, pchHeaderName, pchHeaderValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_SetHTTPRequestGetOrPostParameter_(intptr_t instancePtr, HTTPRequestHandle hRequest, const char * pchParamName, const char * pchParamValue)
{
  TRACE("((intptr_t)%p, (HTTPRequestHandle)%p, (const char *)\"%s\", (const char *)\"%s\")\n", instancePtr, hRequest, pchParamName, pchParamValue);
  bool result = SteamAPI_ISteamHTTP_SetHTTPRequestGetOrPostParameter(instancePtr, hRequest, pchParamName, pchParamValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_SendHTTPRequest_(intptr_t instancePtr, HTTPRequestHandle hRequest, SteamAPICall_t * pCallHandle)
{
  TRACE("((intptr_t)%p, (HTTPRequestHandle)%p, (SteamAPICall_t *)%p)\n", instancePtr, hRequest, pCallHandle);
  bool result = SteamAPI_ISteamHTTP_SendHTTPRequest(instancePtr, hRequest, pCallHandle);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_SendHTTPRequestAndStreamResponse_(intptr_t instancePtr, HTTPRequestHandle hRequest, SteamAPICall_t * pCallHandle)
{
  TRACE("((intptr_t)%p, (HTTPRequestHandle)%p, (SteamAPICall_t *)%p)\n", instancePtr, hRequest, pCallHandle);
  bool result = SteamAPI_ISteamHTTP_SendHTTPRequestAndStreamResponse(instancePtr, hRequest, pCallHandle);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_DeferHTTPRequest_(intptr_t instancePtr, HTTPRequestHandle hRequest)
{
  TRACE("((intptr_t)%p, (HTTPRequestHandle)%p)\n", instancePtr, hRequest);
  bool result = SteamAPI_ISteamHTTP_DeferHTTPRequest(instancePtr, hRequest);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_PrioritizeHTTPRequest_(intptr_t instancePtr, HTTPRequestHandle hRequest)
{
  TRACE("((intptr_t)%p, (HTTPRequestHandle)%p)\n", instancePtr, hRequest);
  bool result = SteamAPI_ISteamHTTP_PrioritizeHTTPRequest(instancePtr, hRequest);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_GetHTTPResponseHeaderSize_(intptr_t instancePtr, HTTPRequestHandle hRequest, const char * pchHeaderName, uint32 * unResponseHeaderSize)
{
  TRACE("((intptr_t)%p, (HTTPRequestHandle)%p, (const char *)\"%s\", (uint32 *)%p)\n", instancePtr, hRequest, pchHeaderName, unResponseHeaderSize);
  bool result = SteamAPI_ISteamHTTP_GetHTTPResponseHeaderSize(instancePtr, hRequest, pchHeaderName, unResponseHeaderSize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_GetHTTPResponseHeaderValue_(intptr_t instancePtr, HTTPRequestHandle hRequest, const char * pchHeaderName, uint8 * pHeaderValueBuffer, uint32 unBufferSize)
{
  TRACE("((intptr_t)%p, (HTTPRequestHandle)%p, (const char *)\"%s\", (uint8 *)%p, (uint32)%d)\n", instancePtr, hRequest, pchHeaderName, pHeaderValueBuffer, unBufferSize);
  bool result = SteamAPI_ISteamHTTP_GetHTTPResponseHeaderValue(instancePtr, hRequest, pchHeaderName, pHeaderValueBuffer, unBufferSize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_GetHTTPResponseBodySize_(intptr_t instancePtr, HTTPRequestHandle hRequest, uint32 * unBodySize)
{
  TRACE("((intptr_t)%p, (HTTPRequestHandle)%p, (uint32 *)%p)\n", instancePtr, hRequest, unBodySize);
  bool result = SteamAPI_ISteamHTTP_GetHTTPResponseBodySize(instancePtr, hRequest, unBodySize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_GetHTTPResponseBodyData_(intptr_t instancePtr, HTTPRequestHandle hRequest, uint8 * pBodyDataBuffer, uint32 unBufferSize)
{
  TRACE("((intptr_t)%p, (HTTPRequestHandle)%p, (uint8 *)%p, (uint32)%d)\n", instancePtr, hRequest, pBodyDataBuffer, unBufferSize);
  bool result = SteamAPI_ISteamHTTP_GetHTTPResponseBodyData(instancePtr, hRequest, pBodyDataBuffer, unBufferSize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_GetHTTPStreamingResponseBodyData_(intptr_t instancePtr, HTTPRequestHandle hRequest, uint32 cOffset, uint8 * pBodyDataBuffer, uint32 unBufferSize)
{
  TRACE("((intptr_t)%p, (HTTPRequestHandle)%p, (uint32)%d, (uint8 *)%p, (uint32)%d)\n", instancePtr, hRequest, cOffset, pBodyDataBuffer, unBufferSize);
  bool result = SteamAPI_ISteamHTTP_GetHTTPStreamingResponseBodyData(instancePtr, hRequest, cOffset, pBodyDataBuffer, unBufferSize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_ReleaseHTTPRequest_(intptr_t instancePtr, HTTPRequestHandle hRequest)
{
  TRACE("((intptr_t)%p, (HTTPRequestHandle)%p)\n", instancePtr, hRequest);
  bool result = SteamAPI_ISteamHTTP_ReleaseHTTPRequest(instancePtr, hRequest);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_GetHTTPDownloadProgressPct_(intptr_t instancePtr, HTTPRequestHandle hRequest, float * pflPercentOut)
{
  TRACE("((intptr_t)%p, (HTTPRequestHandle)%p, (float *)%f)\n", instancePtr, hRequest, pflPercentOut);
  bool result = SteamAPI_ISteamHTTP_GetHTTPDownloadProgressPct(instancePtr, hRequest, pflPercentOut);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_SetHTTPRequestRawPostBody_(intptr_t instancePtr, HTTPRequestHandle hRequest, const char * pchContentType, uint8 * pubBody, uint32 unBodyLen)
{
  TRACE("((intptr_t)%p, (HTTPRequestHandle)%p, (const char *)\"%s\", (uint8 *)%p, (uint32)%d)\n", instancePtr, hRequest, pchContentType, pubBody, unBodyLen);
  bool result = SteamAPI_ISteamHTTP_SetHTTPRequestRawPostBody(instancePtr, hRequest, pchContentType, pubBody, unBodyLen);
  TRACE(" = (bool)%d\n", result);
  return result;
}
HTTPCookieContainerHandle SteamAPI_ISteamHTTP_CreateCookieContainer_(intptr_t instancePtr, bool bAllowResponsesToModify)
{
  TRACE("((intptr_t)%p, (bool)%d)\n", instancePtr, bAllowResponsesToModify);
  HTTPCookieContainerHandle result = SteamAPI_ISteamHTTP_CreateCookieContainer(instancePtr, bAllowResponsesToModify);
  TRACE(" = (HTTPCookieContainerHandle)%p\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_ReleaseCookieContainer_(intptr_t instancePtr, HTTPCookieContainerHandle hCookieContainer)
{
  TRACE("((intptr_t)%p, (HTTPCookieContainerHandle)%p)\n", instancePtr, hCookieContainer);
  bool result = SteamAPI_ISteamHTTP_ReleaseCookieContainer(instancePtr, hCookieContainer);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_SetCookie_(intptr_t instancePtr, HTTPCookieContainerHandle hCookieContainer, const char * pchHost, const char * pchUrl, const char * pchCookie)
{
  TRACE("((intptr_t)%p, (HTTPCookieContainerHandle)%p, (const char *)\"%s\", (const char *)\"%s\", (const char *)\"%s\")\n", instancePtr, hCookieContainer, pchHost, pchUrl, pchCookie);
  bool result = SteamAPI_ISteamHTTP_SetCookie(instancePtr, hCookieContainer, pchHost, pchUrl, pchCookie);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_SetHTTPRequestCookieContainer_(intptr_t instancePtr, HTTPRequestHandle hRequest, HTTPCookieContainerHandle hCookieContainer)
{
  TRACE("((intptr_t)%p, (HTTPRequestHandle)%p, (HTTPCookieContainerHandle)%p)\n", instancePtr, hRequest, hCookieContainer);
  bool result = SteamAPI_ISteamHTTP_SetHTTPRequestCookieContainer(instancePtr, hRequest, hCookieContainer);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_SetHTTPRequestUserAgentInfo_(intptr_t instancePtr, HTTPRequestHandle hRequest, const char * pchUserAgentInfo)
{
  TRACE("((intptr_t)%p, (HTTPRequestHandle)%p, (const char *)\"%s\")\n", instancePtr, hRequest, pchUserAgentInfo);
  bool result = SteamAPI_ISteamHTTP_SetHTTPRequestUserAgentInfo(instancePtr, hRequest, pchUserAgentInfo);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate_(intptr_t instancePtr, HTTPRequestHandle hRequest, bool bRequireVerifiedCertificate)
{
  TRACE("((intptr_t)%p, (HTTPRequestHandle)%p, (bool)%d)\n", instancePtr, hRequest, bRequireVerifiedCertificate);
  bool result = SteamAPI_ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate(instancePtr, hRequest, bRequireVerifiedCertificate);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS_(intptr_t instancePtr, HTTPRequestHandle hRequest, uint32 unMilliseconds)
{
  TRACE("((intptr_t)%p, (HTTPRequestHandle)%p, (uint32)%d)\n", instancePtr, hRequest, unMilliseconds);
  bool result = SteamAPI_ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS(instancePtr, hRequest, unMilliseconds);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamHTTP_GetHTTPRequestWasTimedOut_(intptr_t instancePtr, HTTPRequestHandle hRequest, bool * pbWasTimedOut)
{
  TRACE("((intptr_t)%p, (HTTPRequestHandle)%p, (bool *)%p)\n", instancePtr, hRequest, pbWasTimedOut);
  bool result = SteamAPI_ISteamHTTP_GetHTTPRequestWasTimedOut(instancePtr, hRequest, pbWasTimedOut);
  TRACE(" = (bool)%d\n", result);
  return result;
}
ClientUnifiedMessageHandle SteamAPI_ISteamUnifiedMessages_SendMethod_(intptr_t instancePtr, const char * pchServiceMethod, const void * pRequestBuffer, uint32 unRequestBufferSize, uint64 unContext)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (const void *)%p, (uint32)%d, (uint64)%d)\n", instancePtr, pchServiceMethod, pRequestBuffer, unRequestBufferSize, unContext);
  ClientUnifiedMessageHandle result = SteamAPI_ISteamUnifiedMessages_SendMethod(instancePtr, pchServiceMethod, pRequestBuffer, unRequestBufferSize, unContext);
  TRACE(" = (ClientUnifiedMessageHandle)%p\n", result);
  return result;
}
bool SteamAPI_ISteamUnifiedMessages_GetMethodResponseInfo_(intptr_t instancePtr, ClientUnifiedMessageHandle hHandle, uint32 * punResponseSize, EResult * peResult)
{
  TRACE("((intptr_t)%p, (ClientUnifiedMessageHandle)%p, (uint32 *)%p, (EResult *)%p)\n", instancePtr, hHandle, punResponseSize, peResult);
  bool result = SteamAPI_ISteamUnifiedMessages_GetMethodResponseInfo(instancePtr, hHandle, punResponseSize, peResult);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUnifiedMessages_GetMethodResponseData_(intptr_t instancePtr, ClientUnifiedMessageHandle hHandle, void * pResponseBuffer, uint32 unResponseBufferSize, bool bAutoRelease)
{
  TRACE("((intptr_t)%p, (ClientUnifiedMessageHandle)%p, (void *)%p, (uint32)%d, (bool)%d)\n", instancePtr, hHandle, pResponseBuffer, unResponseBufferSize, bAutoRelease);
  bool result = SteamAPI_ISteamUnifiedMessages_GetMethodResponseData(instancePtr, hHandle, pResponseBuffer, unResponseBufferSize, bAutoRelease);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUnifiedMessages_ReleaseMethod_(intptr_t instancePtr, ClientUnifiedMessageHandle hHandle)
{
  TRACE("((intptr_t)%p, (ClientUnifiedMessageHandle)%p)\n", instancePtr, hHandle);
  bool result = SteamAPI_ISteamUnifiedMessages_ReleaseMethod(instancePtr, hHandle);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUnifiedMessages_SendNotification_(intptr_t instancePtr, const char * pchServiceNotification, const void * pNotificationBuffer, uint32 unNotificationBufferSize)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (const void *)%p, (uint32)%d)\n", instancePtr, pchServiceNotification, pNotificationBuffer, unNotificationBufferSize);
  bool result = SteamAPI_ISteamUnifiedMessages_SendNotification(instancePtr, pchServiceNotification, pNotificationBuffer, unNotificationBufferSize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamController_Init_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamController_Init(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamController_Shutdown_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamController_Shutdown(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void SteamAPI_ISteamController_RunFrame_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPI_ISteamController_RunFrame(instancePtr);
}
void SteamAPI_ISteamController_TriggerHapticPulse_(intptr_t instancePtr, ControllerHandle_t controllerHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec)
{
  TRACE("((intptr_t)%p, (ControllerHandle_t)%p, (ESteamControllerPad)%p, (unsigned short)%p)\n", instancePtr, controllerHandle, eTargetPad, usDurationMicroSec);
  SteamAPI_ISteamController_TriggerHapticPulse(instancePtr, controllerHandle, eTargetPad, usDurationMicroSec);
}
UGCQueryHandle_t SteamAPI_ISteamUGC_CreateQueryUserUGCRequest_(intptr_t instancePtr, AccountID_t unAccountID, EUserUGCList eListType, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eSortOrder, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage)
{
  TRACE("((intptr_t)%p, (AccountID_t)%p, (EUserUGCList)%p, (EUGCMatchingUGCType)%p, (EUserUGCListSortOrder)%p, (AppId_t)%p, (AppId_t)%p, (uint32)%d)\n", instancePtr, unAccountID, eListType, eMatchingUGCType, eSortOrder, nCreatorAppID, nConsumerAppID, unPage);
  UGCQueryHandle_t result = SteamAPI_ISteamUGC_CreateQueryUserUGCRequest(instancePtr, unAccountID, eListType, eMatchingUGCType, eSortOrder, nCreatorAppID, nConsumerAppID, unPage);
  TRACE(" = (UGCQueryHandle_t)%p\n", result);
  return result;
}
UGCQueryHandle_t SteamAPI_ISteamUGC_CreateQueryAllUGCRequest_(intptr_t instancePtr, EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage)
{
  TRACE("((intptr_t)%p, (EUGCQuery)%p, (EUGCMatchingUGCType)%p, (AppId_t)%p, (AppId_t)%p, (uint32)%d)\n", instancePtr, eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, unPage);
  UGCQueryHandle_t result = SteamAPI_ISteamUGC_CreateQueryAllUGCRequest(instancePtr, eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, unPage);
  TRACE(" = (UGCQueryHandle_t)%p\n", result);
  return result;
}
UGCQueryHandle_t SteamAPI_ISteamUGC_CreateQueryUGCDetailsRequest_(intptr_t instancePtr, PublishedFileId_t * pvecPublishedFileID, uint32 unNumPublishedFileIDs)
{
  TRACE("((intptr_t)%p, (PublishedFileId_t *)%p, (uint32)%d)\n", instancePtr, pvecPublishedFileID, unNumPublishedFileIDs);
  UGCQueryHandle_t result = SteamAPI_ISteamUGC_CreateQueryUGCDetailsRequest(instancePtr, pvecPublishedFileID, unNumPublishedFileIDs);
  TRACE(" = (UGCQueryHandle_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamUGC_SendQueryUGCRequest_(intptr_t instancePtr, UGCQueryHandle_t handle)
{
  TRACE("((intptr_t)%p, (UGCQueryHandle_t)%p)\n", instancePtr, handle);
  SteamAPICall_t result = SteamAPI_ISteamUGC_SendQueryUGCRequest(instancePtr, handle);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_GetQueryUGCResult_(intptr_t instancePtr, UGCQueryHandle_t handle, uint32 index, struct SteamUGCDetails_t * pDetails)
{
  TRACE("((intptr_t)%p, (UGCQueryHandle_t)%p, (uint32)%d, (struct SteamUGCDetails_t *)%p)\n", instancePtr, handle, index, pDetails);
  bool result = SteamAPI_ISteamUGC_GetQueryUGCResult(instancePtr, handle, index, pDetails);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_GetQueryUGCPreviewURL_(intptr_t instancePtr, UGCQueryHandle_t handle, uint32 index, char * pchURL, uint32 cchURLSize)
{
  TRACE("((intptr_t)%p, (UGCQueryHandle_t)%p, (uint32)%d, (char *)%p, (uint32)%d)\n", instancePtr, handle, index, pchURL, cchURLSize);
  bool result = SteamAPI_ISteamUGC_GetQueryUGCPreviewURL(instancePtr, handle, index, pchURL, cchURLSize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_GetQueryUGCMetadata_(intptr_t instancePtr, UGCQueryHandle_t handle, uint32 index, char * pchMetadata, uint32 cchMetadatasize)
{
  TRACE("((intptr_t)%p, (UGCQueryHandle_t)%p, (uint32)%d, (char *)%p, (uint32)%d)\n", instancePtr, handle, index, pchMetadata, cchMetadatasize);
  bool result = SteamAPI_ISteamUGC_GetQueryUGCMetadata(instancePtr, handle, index, pchMetadata, cchMetadatasize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_GetQueryUGCChildren_(intptr_t instancePtr, UGCQueryHandle_t handle, uint32 index, PublishedFileId_t * pvecPublishedFileID, uint32 cMaxEntries)
{
  TRACE("((intptr_t)%p, (UGCQueryHandle_t)%p, (uint32)%d, (PublishedFileId_t *)%p, (uint32)%d)\n", instancePtr, handle, index, pvecPublishedFileID, cMaxEntries);
  bool result = SteamAPI_ISteamUGC_GetQueryUGCChildren(instancePtr, handle, index, pvecPublishedFileID, cMaxEntries);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_GetQueryUGCStatistic_(intptr_t instancePtr, UGCQueryHandle_t handle, uint32 index, EItemStatistic eStatType, uint64 * pStatValue)
{
  TRACE("((intptr_t)%p, (UGCQueryHandle_t)%p, (uint32)%d, (EItemStatistic)%p, (uint64 *)%p)\n", instancePtr, handle, index, eStatType, pStatValue);
  bool result = SteamAPI_ISteamUGC_GetQueryUGCStatistic(instancePtr, handle, index, eStatType, pStatValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
uint32 SteamAPI_ISteamUGC_GetQueryUGCNumAdditionalPreviews_(intptr_t instancePtr, UGCQueryHandle_t handle, uint32 index)
{
  TRACE("((intptr_t)%p, (UGCQueryHandle_t)%p, (uint32)%d)\n", instancePtr, handle, index);
  uint32 result = SteamAPI_ISteamUGC_GetQueryUGCNumAdditionalPreviews(instancePtr, handle, index);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_GetQueryUGCAdditionalPreview_(intptr_t instancePtr, UGCQueryHandle_t handle, uint32 index, uint32 previewIndex, char * pchURLOrVideoID, uint32 cchURLSize, char * pchOriginalFileName, uint32 cchOriginalFileNameSize, EItemPreviewType * pPreviewType)
{
  TRACE("((intptr_t)%p, (UGCQueryHandle_t)%p, (uint32)%d, (uint32)%d, (char *)%p, (uint32)%d, (char *)%p, (uint32)%d, (EItemPreviewType *)%p)\n", instancePtr, handle, index, previewIndex, pchURLOrVideoID, cchURLSize, pchOriginalFileName, cchOriginalFileNameSize, pPreviewType);
  bool result = SteamAPI_ISteamUGC_GetQueryUGCAdditionalPreview(instancePtr, handle, index, previewIndex, pchURLOrVideoID, cchURLSize, pchOriginalFileName, cchOriginalFileNameSize, pPreviewType);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_ReleaseQueryUGCRequest_(intptr_t instancePtr, UGCQueryHandle_t handle)
{
  TRACE("((intptr_t)%p, (UGCQueryHandle_t)%p)\n", instancePtr, handle);
  bool result = SteamAPI_ISteamUGC_ReleaseQueryUGCRequest(instancePtr, handle);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_AddRequiredTag_(intptr_t instancePtr, UGCQueryHandle_t handle, const char * pTagName)
{
  TRACE("((intptr_t)%p, (UGCQueryHandle_t)%p, (const char *)\"%s\")\n", instancePtr, handle, pTagName);
  bool result = SteamAPI_ISteamUGC_AddRequiredTag(instancePtr, handle, pTagName);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_AddExcludedTag_(intptr_t instancePtr, UGCQueryHandle_t handle, const char * pTagName)
{
  TRACE("((intptr_t)%p, (UGCQueryHandle_t)%p, (const char *)\"%s\")\n", instancePtr, handle, pTagName);
  bool result = SteamAPI_ISteamUGC_AddExcludedTag(instancePtr, handle, pTagName);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_SetReturnLongDescription_(intptr_t instancePtr, UGCQueryHandle_t handle, bool bReturnLongDescription)
{
  TRACE("((intptr_t)%p, (UGCQueryHandle_t)%p, (bool)%d)\n", instancePtr, handle, bReturnLongDescription);
  bool result = SteamAPI_ISteamUGC_SetReturnLongDescription(instancePtr, handle, bReturnLongDescription);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_SetReturnMetadata_(intptr_t instancePtr, UGCQueryHandle_t handle, bool bReturnMetadata)
{
  TRACE("((intptr_t)%p, (UGCQueryHandle_t)%p, (bool)%d)\n", instancePtr, handle, bReturnMetadata);
  bool result = SteamAPI_ISteamUGC_SetReturnMetadata(instancePtr, handle, bReturnMetadata);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_SetReturnChildren_(intptr_t instancePtr, UGCQueryHandle_t handle, bool bReturnChildren)
{
  TRACE("((intptr_t)%p, (UGCQueryHandle_t)%p, (bool)%d)\n", instancePtr, handle, bReturnChildren);
  bool result = SteamAPI_ISteamUGC_SetReturnChildren(instancePtr, handle, bReturnChildren);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_SetReturnAdditionalPreviews_(intptr_t instancePtr, UGCQueryHandle_t handle, bool bReturnAdditionalPreviews)
{
  TRACE("((intptr_t)%p, (UGCQueryHandle_t)%p, (bool)%d)\n", instancePtr, handle, bReturnAdditionalPreviews);
  bool result = SteamAPI_ISteamUGC_SetReturnAdditionalPreviews(instancePtr, handle, bReturnAdditionalPreviews);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_SetReturnTotalOnly_(intptr_t instancePtr, UGCQueryHandle_t handle, bool bReturnTotalOnly)
{
  TRACE("((intptr_t)%p, (UGCQueryHandle_t)%p, (bool)%d)\n", instancePtr, handle, bReturnTotalOnly);
  bool result = SteamAPI_ISteamUGC_SetReturnTotalOnly(instancePtr, handle, bReturnTotalOnly);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_SetAllowCachedResponse_(intptr_t instancePtr, UGCQueryHandle_t handle, uint32 unMaxAgeSeconds)
{
  TRACE("((intptr_t)%p, (UGCQueryHandle_t)%p, (uint32)%d)\n", instancePtr, handle, unMaxAgeSeconds);
  bool result = SteamAPI_ISteamUGC_SetAllowCachedResponse(instancePtr, handle, unMaxAgeSeconds);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_SetCloudFileNameFilter_(intptr_t instancePtr, UGCQueryHandle_t handle, const char * pMatchCloudFileName)
{
  TRACE("((intptr_t)%p, (UGCQueryHandle_t)%p, (const char *)\"%s\")\n", instancePtr, handle, pMatchCloudFileName);
  bool result = SteamAPI_ISteamUGC_SetCloudFileNameFilter(instancePtr, handle, pMatchCloudFileName);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_SetMatchAnyTag_(intptr_t instancePtr, UGCQueryHandle_t handle, bool bMatchAnyTag)
{
  TRACE("((intptr_t)%p, (UGCQueryHandle_t)%p, (bool)%d)\n", instancePtr, handle, bMatchAnyTag);
  bool result = SteamAPI_ISteamUGC_SetMatchAnyTag(instancePtr, handle, bMatchAnyTag);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_SetSearchText_(intptr_t instancePtr, UGCQueryHandle_t handle, const char * pSearchText)
{
  TRACE("((intptr_t)%p, (UGCQueryHandle_t)%p, (const char *)\"%s\")\n", instancePtr, handle, pSearchText);
  bool result = SteamAPI_ISteamUGC_SetSearchText(instancePtr, handle, pSearchText);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_SetRankedByTrendDays_(intptr_t instancePtr, UGCQueryHandle_t handle, uint32 unDays)
{
  TRACE("((intptr_t)%p, (UGCQueryHandle_t)%p, (uint32)%d)\n", instancePtr, handle, unDays);
  bool result = SteamAPI_ISteamUGC_SetRankedByTrendDays(instancePtr, handle, unDays);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamUGC_RequestUGCDetails_(intptr_t instancePtr, PublishedFileId_t nPublishedFileID, uint32 unMaxAgeSeconds)
{
  TRACE("((intptr_t)%p, (PublishedFileId_t)%p, (uint32)%d)\n", instancePtr, nPublishedFileID, unMaxAgeSeconds);
  SteamAPICall_t result = SteamAPI_ISteamUGC_RequestUGCDetails(instancePtr, nPublishedFileID, unMaxAgeSeconds);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamUGC_CreateItem_(intptr_t instancePtr, AppId_t nConsumerAppId, EWorkshopFileType eFileType)
{
  TRACE("((intptr_t)%p, (AppId_t)%p, (EWorkshopFileType)%p)\n", instancePtr, nConsumerAppId, eFileType);
  SteamAPICall_t result = SteamAPI_ISteamUGC_CreateItem(instancePtr, nConsumerAppId, eFileType);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
UGCUpdateHandle_t SteamAPI_ISteamUGC_StartItemUpdate_(intptr_t instancePtr, AppId_t nConsumerAppId, PublishedFileId_t nPublishedFileID)
{
  TRACE("((intptr_t)%p, (AppId_t)%p, (PublishedFileId_t)%p)\n", instancePtr, nConsumerAppId, nPublishedFileID);
  UGCUpdateHandle_t result = SteamAPI_ISteamUGC_StartItemUpdate(instancePtr, nConsumerAppId, nPublishedFileID);
  TRACE(" = (UGCUpdateHandle_t)%p\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_SetItemTitle_(intptr_t instancePtr, UGCUpdateHandle_t handle, const char * pchTitle)
{
  TRACE("((intptr_t)%p, (UGCUpdateHandle_t)%p, (const char *)\"%s\")\n", instancePtr, handle, pchTitle);
  bool result = SteamAPI_ISteamUGC_SetItemTitle(instancePtr, handle, pchTitle);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_SetItemDescription_(intptr_t instancePtr, UGCUpdateHandle_t handle, const char * pchDescription)
{
  TRACE("((intptr_t)%p, (UGCUpdateHandle_t)%p, (const char *)\"%s\")\n", instancePtr, handle, pchDescription);
  bool result = SteamAPI_ISteamUGC_SetItemDescription(instancePtr, handle, pchDescription);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_SetItemMetadata_(intptr_t instancePtr, UGCUpdateHandle_t handle, const char * pchMetaData)
{
  TRACE("((intptr_t)%p, (UGCUpdateHandle_t)%p, (const char *)\"%s\")\n", instancePtr, handle, pchMetaData);
  bool result = SteamAPI_ISteamUGC_SetItemMetadata(instancePtr, handle, pchMetaData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_SetItemVisibility_(intptr_t instancePtr, UGCUpdateHandle_t handle, ERemoteStoragePublishedFileVisibility eVisibility)
{
  TRACE("((intptr_t)%p, (UGCUpdateHandle_t)%p, (ERemoteStoragePublishedFileVisibility)%p)\n", instancePtr, handle, eVisibility);
  bool result = SteamAPI_ISteamUGC_SetItemVisibility(instancePtr, handle, eVisibility);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_SetItemTags_(intptr_t instancePtr, UGCUpdateHandle_t updateHandle, const struct SteamParamStringArray_t * pTags)
{
  TRACE("((intptr_t)%p, (UGCUpdateHandle_t)%p, (const struct SteamParamStringArray_t *)%p)\n", instancePtr, updateHandle, pTags);
  bool result = SteamAPI_ISteamUGC_SetItemTags(instancePtr, updateHandle, pTags);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_SetItemContent_(intptr_t instancePtr, UGCUpdateHandle_t handle, const char * pszContentFolder)
{
  TRACE("((intptr_t)%p, (UGCUpdateHandle_t)%p, (const char *)\"%s\")\n", instancePtr, handle, pszContentFolder);
  bool result = SteamAPI_ISteamUGC_SetItemContent(instancePtr, handle, pszContentFolder);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_SetItemPreview_(intptr_t instancePtr, UGCUpdateHandle_t handle, const char * pszPreviewFile)
{
  TRACE("((intptr_t)%p, (UGCUpdateHandle_t)%p, (const char *)\"%s\")\n", instancePtr, handle, pszPreviewFile);
  bool result = SteamAPI_ISteamUGC_SetItemPreview(instancePtr, handle, pszPreviewFile);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamUGC_SubmitItemUpdate_(intptr_t instancePtr, UGCUpdateHandle_t handle, const char * pchChangeNote)
{
  TRACE("((intptr_t)%p, (UGCUpdateHandle_t)%p, (const char *)\"%s\")\n", instancePtr, handle, pchChangeNote);
  SteamAPICall_t result = SteamAPI_ISteamUGC_SubmitItemUpdate(instancePtr, handle, pchChangeNote);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
EItemUpdateStatus SteamAPI_ISteamUGC_GetItemUpdateProgress_(intptr_t instancePtr, UGCUpdateHandle_t handle, uint64 * punBytesProcessed, uint64 * punBytesTotal)
{
  TRACE("((intptr_t)%p, (UGCUpdateHandle_t)%p, (uint64 *)%p, (uint64 *)%p)\n", instancePtr, handle, punBytesProcessed, punBytesTotal);
  EItemUpdateStatus result = SteamAPI_ISteamUGC_GetItemUpdateProgress(instancePtr, handle, punBytesProcessed, punBytesTotal);
  TRACE(" = (EItemUpdateStatus)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamUGC_AddItemToFavorites_(intptr_t instancePtr, AppId_t nAppId, PublishedFileId_t nPublishedFileID)
{
  TRACE("((intptr_t)%p, (AppId_t)%p, (PublishedFileId_t)%p)\n", instancePtr, nAppId, nPublishedFileID);
  SteamAPICall_t result = SteamAPI_ISteamUGC_AddItemToFavorites(instancePtr, nAppId, nPublishedFileID);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamUGC_RemoveItemFromFavorites_(intptr_t instancePtr, AppId_t nAppId, PublishedFileId_t nPublishedFileID)
{
  TRACE("((intptr_t)%p, (AppId_t)%p, (PublishedFileId_t)%p)\n", instancePtr, nAppId, nPublishedFileID);
  SteamAPICall_t result = SteamAPI_ISteamUGC_RemoveItemFromFavorites(instancePtr, nAppId, nPublishedFileID);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamUGC_SubscribeItem_(intptr_t instancePtr, PublishedFileId_t nPublishedFileID)
{
  TRACE("((intptr_t)%p, (PublishedFileId_t)%p)\n", instancePtr, nPublishedFileID);
  SteamAPICall_t result = SteamAPI_ISteamUGC_SubscribeItem(instancePtr, nPublishedFileID);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamUGC_UnsubscribeItem_(intptr_t instancePtr, PublishedFileId_t nPublishedFileID)
{
  TRACE("((intptr_t)%p, (PublishedFileId_t)%p)\n", instancePtr, nPublishedFileID);
  SteamAPICall_t result = SteamAPI_ISteamUGC_UnsubscribeItem(instancePtr, nPublishedFileID);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
uint32 SteamAPI_ISteamUGC_GetNumSubscribedItems_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  uint32 result = SteamAPI_ISteamUGC_GetNumSubscribedItems(instancePtr);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
uint32 SteamAPI_ISteamUGC_GetSubscribedItems_(intptr_t instancePtr, PublishedFileId_t * pvecPublishedFileID, uint32 cMaxEntries)
{
  TRACE("((intptr_t)%p, (PublishedFileId_t *)%p, (uint32)%d)\n", instancePtr, pvecPublishedFileID, cMaxEntries);
  uint32 result = SteamAPI_ISteamUGC_GetSubscribedItems(instancePtr, pvecPublishedFileID, cMaxEntries);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
uint32 SteamAPI_ISteamUGC_GetItemState_(intptr_t instancePtr, PublishedFileId_t nPublishedFileID)
{
  TRACE("((intptr_t)%p, (PublishedFileId_t)%p)\n", instancePtr, nPublishedFileID);
  uint32 result = SteamAPI_ISteamUGC_GetItemState(instancePtr, nPublishedFileID);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_GetItemInstallInfo_(intptr_t instancePtr, PublishedFileId_t nPublishedFileID, uint64 * punSizeOnDisk, char * pchFolder, uint32 cchFolderSize, uint32 * punTimeStamp)
{
  TRACE("((intptr_t)%p, (PublishedFileId_t)%p, (uint64 *)%p, (char *)%p, (uint32)%d, (uint32 *)%p)\n", instancePtr, nPublishedFileID, punSizeOnDisk, pchFolder, cchFolderSize, punTimeStamp);
  bool result = SteamAPI_ISteamUGC_GetItemInstallInfo(instancePtr, nPublishedFileID, punSizeOnDisk, pchFolder, cchFolderSize, punTimeStamp);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_GetItemDownloadInfo_(intptr_t instancePtr, PublishedFileId_t nPublishedFileID, uint64 * punBytesDownloaded, uint64 * punBytesTotal)
{
  TRACE("((intptr_t)%p, (PublishedFileId_t)%p, (uint64 *)%p, (uint64 *)%p)\n", instancePtr, nPublishedFileID, punBytesDownloaded, punBytesTotal);
  bool result = SteamAPI_ISteamUGC_GetItemDownloadInfo(instancePtr, nPublishedFileID, punBytesDownloaded, punBytesTotal);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamUGC_DownloadItem_(intptr_t instancePtr, PublishedFileId_t nPublishedFileID, bool bHighPriority)
{
  TRACE("((intptr_t)%p, (PublishedFileId_t)%p, (bool)%d)\n", instancePtr, nPublishedFileID, bHighPriority);
  bool result = SteamAPI_ISteamUGC_DownloadItem(instancePtr, nPublishedFileID, bHighPriority);
  TRACE(" = (bool)%d\n", result);
  return result;
}
uint32 SteamAPI_ISteamAppList_GetNumInstalledApps_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  uint32 result = SteamAPI_ISteamAppList_GetNumInstalledApps(instancePtr);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
uint32 SteamAPI_ISteamAppList_GetInstalledApps_(intptr_t instancePtr, AppId_t * pvecAppID, uint32 unMaxAppIDs)
{
  TRACE("((intptr_t)%p, (AppId_t *)%p, (uint32)%d)\n", instancePtr, pvecAppID, unMaxAppIDs);
  uint32 result = SteamAPI_ISteamAppList_GetInstalledApps(instancePtr, pvecAppID, unMaxAppIDs);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
int SteamAPI_ISteamAppList_GetAppName_(intptr_t instancePtr, AppId_t nAppID, char * pchName, int cchNameMax)
{
  TRACE("((intptr_t)%p, (AppId_t)%p, (char *)%p, (int)%d)\n", instancePtr, nAppID, pchName, cchNameMax);
  int result = SteamAPI_ISteamAppList_GetAppName(instancePtr, nAppID, pchName, cchNameMax);
  TRACE(" = (int)%d\n", result);
  return result;
}
int SteamAPI_ISteamAppList_GetAppInstallDir_(intptr_t instancePtr, AppId_t nAppID, char * pchDirectory, int cchNameMax)
{
  TRACE("((intptr_t)%p, (AppId_t)%p, (char *)%p, (int)%d)\n", instancePtr, nAppID, pchDirectory, cchNameMax);
  int result = SteamAPI_ISteamAppList_GetAppInstallDir(instancePtr, nAppID, pchDirectory, cchNameMax);
  TRACE(" = (int)%d\n", result);
  return result;
}
int SteamAPI_ISteamAppList_GetAppBuildId_(intptr_t instancePtr, AppId_t nAppID)
{
  TRACE("((intptr_t)%p, (AppId_t)%p)\n", instancePtr, nAppID);
  int result = SteamAPI_ISteamAppList_GetAppBuildId(instancePtr, nAppID);
  TRACE(" = (int)%d\n", result);
  return result;
}
void SteamAPI_ISteamHTMLSurface_DestructISteamHTMLSurface_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPI_ISteamHTMLSurface_DestructISteamHTMLSurface(instancePtr);
}
bool SteamAPI_ISteamHTMLSurface_Init_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamHTMLSurface_Init(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamHTMLSurface_Shutdown_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamHTMLSurface_Shutdown(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamHTMLSurface_CreateBrowser_(intptr_t instancePtr, const char * pchUserAgent, const char * pchUserCSS)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (const char *)\"%s\")\n", instancePtr, pchUserAgent, pchUserCSS);
  SteamAPICall_t result = SteamAPI_ISteamHTMLSurface_CreateBrowser(instancePtr, pchUserAgent, pchUserCSS);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
void SteamAPI_ISteamHTMLSurface_RemoveBrowser_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p)\n", instancePtr, unBrowserHandle);
  SteamAPI_ISteamHTMLSurface_RemoveBrowser(instancePtr, unBrowserHandle);
}
void SteamAPI_ISteamHTMLSurface_LoadURL_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, const char * pchURL, const char * pchPostData)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p, (const char *)\"%s\", (const char *)\"%s\")\n", instancePtr, unBrowserHandle, pchURL, pchPostData);
  SteamAPI_ISteamHTMLSurface_LoadURL(instancePtr, unBrowserHandle, pchURL, pchPostData);
}
void SteamAPI_ISteamHTMLSurface_SetSize_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, uint32 unWidth, uint32 unHeight)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p, (uint32)%d, (uint32)%d)\n", instancePtr, unBrowserHandle, unWidth, unHeight);
  SteamAPI_ISteamHTMLSurface_SetSize(instancePtr, unBrowserHandle, unWidth, unHeight);
}
void SteamAPI_ISteamHTMLSurface_StopLoad_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p)\n", instancePtr, unBrowserHandle);
  SteamAPI_ISteamHTMLSurface_StopLoad(instancePtr, unBrowserHandle);
}
void SteamAPI_ISteamHTMLSurface_Reload_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p)\n", instancePtr, unBrowserHandle);
  SteamAPI_ISteamHTMLSurface_Reload(instancePtr, unBrowserHandle);
}
void SteamAPI_ISteamHTMLSurface_GoBack_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p)\n", instancePtr, unBrowserHandle);
  SteamAPI_ISteamHTMLSurface_GoBack(instancePtr, unBrowserHandle);
}
void SteamAPI_ISteamHTMLSurface_GoForward_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p)\n", instancePtr, unBrowserHandle);
  SteamAPI_ISteamHTMLSurface_GoForward(instancePtr, unBrowserHandle);
}
void SteamAPI_ISteamHTMLSurface_AddHeader_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, const char * pchKey, const char * pchValue)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p, (const char *)\"%s\", (const char *)\"%s\")\n", instancePtr, unBrowserHandle, pchKey, pchValue);
  SteamAPI_ISteamHTMLSurface_AddHeader(instancePtr, unBrowserHandle, pchKey, pchValue);
}
void SteamAPI_ISteamHTMLSurface_ExecuteJavascript_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, const char * pchScript)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p, (const char *)\"%s\")\n", instancePtr, unBrowserHandle, pchScript);
  SteamAPI_ISteamHTMLSurface_ExecuteJavascript(instancePtr, unBrowserHandle, pchScript);
}
void SteamAPI_ISteamHTMLSurface_MouseUp_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton eMouseButton)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p, (ISteamHTMLSurface::EHTMLMouseButton)%p)\n", instancePtr, unBrowserHandle, eMouseButton);
  SteamAPI_ISteamHTMLSurface_MouseUp(instancePtr, unBrowserHandle, eMouseButton);
}
void SteamAPI_ISteamHTMLSurface_MouseDown_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton eMouseButton)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p, (ISteamHTMLSurface::EHTMLMouseButton)%p)\n", instancePtr, unBrowserHandle, eMouseButton);
  SteamAPI_ISteamHTMLSurface_MouseDown(instancePtr, unBrowserHandle, eMouseButton);
}
void SteamAPI_ISteamHTMLSurface_MouseDoubleClick_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton eMouseButton)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p, (ISteamHTMLSurface::EHTMLMouseButton)%p)\n", instancePtr, unBrowserHandle, eMouseButton);
  SteamAPI_ISteamHTMLSurface_MouseDoubleClick(instancePtr, unBrowserHandle, eMouseButton);
}
void SteamAPI_ISteamHTMLSurface_MouseMove_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, int x, int y)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p, (int)%d, (int)%d)\n", instancePtr, unBrowserHandle, x, y);
  SteamAPI_ISteamHTMLSurface_MouseMove(instancePtr, unBrowserHandle, x, y);
}
void SteamAPI_ISteamHTMLSurface_MouseWheel_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, int32 nDelta)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p, (int32)%d)\n", instancePtr, unBrowserHandle, nDelta);
  SteamAPI_ISteamHTMLSurface_MouseWheel(instancePtr, unBrowserHandle, nDelta);
}
void SteamAPI_ISteamHTMLSurface_KeyDown_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p, (uint32)%d, (ISteamHTMLSurface::EHTMLKeyModifiers)%p)\n", instancePtr, unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
  SteamAPI_ISteamHTMLSurface_KeyDown(instancePtr, unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
}
void SteamAPI_ISteamHTMLSurface_KeyUp_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p, (uint32)%d, (ISteamHTMLSurface::EHTMLKeyModifiers)%p)\n", instancePtr, unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
  SteamAPI_ISteamHTMLSurface_KeyUp(instancePtr, unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
}
void SteamAPI_ISteamHTMLSurface_KeyChar_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, uint32 cUnicodeChar, ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p, (uint32)%d, (ISteamHTMLSurface::EHTMLKeyModifiers)%p)\n", instancePtr, unBrowserHandle, cUnicodeChar, eHTMLKeyModifiers);
  SteamAPI_ISteamHTMLSurface_KeyChar(instancePtr, unBrowserHandle, cUnicodeChar, eHTMLKeyModifiers);
}
void SteamAPI_ISteamHTMLSurface_SetHorizontalScroll_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p, (uint32)%d)\n", instancePtr, unBrowserHandle, nAbsolutePixelScroll);
  SteamAPI_ISteamHTMLSurface_SetHorizontalScroll(instancePtr, unBrowserHandle, nAbsolutePixelScroll);
}
void SteamAPI_ISteamHTMLSurface_SetVerticalScroll_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p, (uint32)%d)\n", instancePtr, unBrowserHandle, nAbsolutePixelScroll);
  SteamAPI_ISteamHTMLSurface_SetVerticalScroll(instancePtr, unBrowserHandle, nAbsolutePixelScroll);
}
void SteamAPI_ISteamHTMLSurface_SetKeyFocus_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, bool bHasKeyFocus)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p, (bool)%d)\n", instancePtr, unBrowserHandle, bHasKeyFocus);
  SteamAPI_ISteamHTMLSurface_SetKeyFocus(instancePtr, unBrowserHandle, bHasKeyFocus);
}
void SteamAPI_ISteamHTMLSurface_ViewSource_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p)\n", instancePtr, unBrowserHandle);
  SteamAPI_ISteamHTMLSurface_ViewSource(instancePtr, unBrowserHandle);
}
void SteamAPI_ISteamHTMLSurface_CopyToClipboard_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p)\n", instancePtr, unBrowserHandle);
  SteamAPI_ISteamHTMLSurface_CopyToClipboard(instancePtr, unBrowserHandle);
}
void SteamAPI_ISteamHTMLSurface_PasteFromClipboard_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p)\n", instancePtr, unBrowserHandle);
  SteamAPI_ISteamHTMLSurface_PasteFromClipboard(instancePtr, unBrowserHandle);
}
void SteamAPI_ISteamHTMLSurface_Find_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, const char * pchSearchStr, bool bCurrentlyInFind, bool bReverse)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p, (const char *)\"%s\", (bool)%d, (bool)%d)\n", instancePtr, unBrowserHandle, pchSearchStr, bCurrentlyInFind, bReverse);
  SteamAPI_ISteamHTMLSurface_Find(instancePtr, unBrowserHandle, pchSearchStr, bCurrentlyInFind, bReverse);
}
void SteamAPI_ISteamHTMLSurface_StopFind_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p)\n", instancePtr, unBrowserHandle);
  SteamAPI_ISteamHTMLSurface_StopFind(instancePtr, unBrowserHandle);
}
void SteamAPI_ISteamHTMLSurface_GetLinkAtPosition_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, int x, int y)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p, (int)%d, (int)%d)\n", instancePtr, unBrowserHandle, x, y);
  SteamAPI_ISteamHTMLSurface_GetLinkAtPosition(instancePtr, unBrowserHandle, x, y);
}
void SteamAPI_ISteamHTMLSurface_SetCookie_(intptr_t instancePtr, const char * pchHostname, const char * pchKey, const char * pchValue, const char * pchPath, RTime32 nExpires, bool bSecure, bool bHTTPOnly)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (const char *)\"%s\", (const char *)\"%s\", (const char *)\"%s\", (RTime32)%p, (bool)%d, (bool)%d)\n", instancePtr, pchHostname, pchKey, pchValue, pchPath, nExpires, bSecure, bHTTPOnly);
  SteamAPI_ISteamHTMLSurface_SetCookie(instancePtr, pchHostname, pchKey, pchValue, pchPath, nExpires, bSecure, bHTTPOnly);
}
void SteamAPI_ISteamHTMLSurface_SetPageScaleFactor_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, float flZoom, int nPointX, int nPointY)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p, (float)%f, (int)%d, (int)%d)\n", instancePtr, unBrowserHandle, flZoom, nPointX, nPointY);
  SteamAPI_ISteamHTMLSurface_SetPageScaleFactor(instancePtr, unBrowserHandle, flZoom, nPointX, nPointY);
}
void SteamAPI_ISteamHTMLSurface_SetBackgroundMode_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, bool bBackgroundMode)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p, (bool)%d)\n", instancePtr, unBrowserHandle, bBackgroundMode);
  SteamAPI_ISteamHTMLSurface_SetBackgroundMode(instancePtr, unBrowserHandle, bBackgroundMode);
}
void SteamAPI_ISteamHTMLSurface_AllowStartRequest_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, bool bAllowed)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p, (bool)%d)\n", instancePtr, unBrowserHandle, bAllowed);
  SteamAPI_ISteamHTMLSurface_AllowStartRequest(instancePtr, unBrowserHandle, bAllowed);
}
void SteamAPI_ISteamHTMLSurface_JSDialogResponse_(intptr_t instancePtr, HHTMLBrowser unBrowserHandle, bool bResult)
{
  TRACE("((intptr_t)%p, (HHTMLBrowser)%p, (bool)%d)\n", instancePtr, unBrowserHandle, bResult);
  SteamAPI_ISteamHTMLSurface_JSDialogResponse(instancePtr, unBrowserHandle, bResult);
}
EResult SteamAPI_ISteamInventory_GetResultStatus_(intptr_t instancePtr, SteamInventoryResult_t resultHandle)
{
  TRACE("((intptr_t)%p, (SteamInventoryResult_t)%p)\n", instancePtr, resultHandle);
  EResult result = SteamAPI_ISteamInventory_GetResultStatus(instancePtr, resultHandle);
  TRACE(" = (EResult)%p\n", result);
  return result;
}
bool SteamAPI_ISteamInventory_GetResultItems_(intptr_t instancePtr, SteamInventoryResult_t resultHandle, struct SteamItemDetails_t * pOutItemsArray, uint32 * punOutItemsArraySize)
{
  TRACE("((intptr_t)%p, (SteamInventoryResult_t)%p, (struct SteamItemDetails_t *)%p, (uint32 *)%p)\n", instancePtr, resultHandle, pOutItemsArray, punOutItemsArraySize);
  bool result = SteamAPI_ISteamInventory_GetResultItems(instancePtr, resultHandle, pOutItemsArray, punOutItemsArraySize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
uint32 SteamAPI_ISteamInventory_GetResultTimestamp_(intptr_t instancePtr, SteamInventoryResult_t resultHandle)
{
  TRACE("((intptr_t)%p, (SteamInventoryResult_t)%p)\n", instancePtr, resultHandle);
  uint32 result = SteamAPI_ISteamInventory_GetResultTimestamp(instancePtr, resultHandle);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
bool SteamAPI_ISteamInventory_CheckResultSteamID_(intptr_t instancePtr, SteamInventoryResult_t resultHandle, class CSteamID steamIDExpected)
{
  TRACE("((intptr_t)%p, (SteamInventoryResult_t)%p, (class CSteamID)%p)\n", instancePtr, resultHandle, steamIDExpected);
  bool result = SteamAPI_ISteamInventory_CheckResultSteamID(instancePtr, resultHandle, steamIDExpected);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void SteamAPI_ISteamInventory_DestroyResult_(intptr_t instancePtr, SteamInventoryResult_t resultHandle)
{
  TRACE("((intptr_t)%p, (SteamInventoryResult_t)%p)\n", instancePtr, resultHandle);
  SteamAPI_ISteamInventory_DestroyResult(instancePtr, resultHandle);
}
bool SteamAPI_ISteamInventory_GetAllItems_(intptr_t instancePtr, SteamInventoryResult_t * pResultHandle)
{
  TRACE("((intptr_t)%p, (SteamInventoryResult_t *)%p)\n", instancePtr, pResultHandle);
  bool result = SteamAPI_ISteamInventory_GetAllItems(instancePtr, pResultHandle);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamInventory_GetItemsByID_(intptr_t instancePtr, SteamInventoryResult_t * pResultHandle, const SteamItemInstanceID_t * pInstanceIDs, uint32 unCountInstanceIDs)
{
  TRACE("((intptr_t)%p, (SteamInventoryResult_t *)%p, (const SteamItemInstanceID_t *)%p, (uint32)%d)\n", instancePtr, pResultHandle, pInstanceIDs, unCountInstanceIDs);
  bool result = SteamAPI_ISteamInventory_GetItemsByID(instancePtr, pResultHandle, pInstanceIDs, unCountInstanceIDs);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamInventory_SerializeResult_(intptr_t instancePtr, SteamInventoryResult_t resultHandle, void * pOutBuffer, uint32 * punOutBufferSize)
{
  TRACE("((intptr_t)%p, (SteamInventoryResult_t)%p, (void *)%p, (uint32 *)%p)\n", instancePtr, resultHandle, pOutBuffer, punOutBufferSize);
  bool result = SteamAPI_ISteamInventory_SerializeResult(instancePtr, resultHandle, pOutBuffer, punOutBufferSize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamInventory_DeserializeResult_(intptr_t instancePtr, SteamInventoryResult_t * pOutResultHandle, const void * pBuffer, uint32 unBufferSize, bool bRESERVED_MUST_BE_FALSE)
{
  TRACE("((intptr_t)%p, (SteamInventoryResult_t *)%p, (const void *)%p, (uint32)%d, (bool)%d)\n", instancePtr, pOutResultHandle, pBuffer, unBufferSize, bRESERVED_MUST_BE_FALSE);
  bool result = SteamAPI_ISteamInventory_DeserializeResult(instancePtr, pOutResultHandle, pBuffer, unBufferSize, bRESERVED_MUST_BE_FALSE);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamInventory_GenerateItems_(intptr_t instancePtr, SteamInventoryResult_t * pResultHandle, const SteamItemDef_t * pArrayItemDefs, const uint32 * punArrayQuantity, uint32 unArrayLength)
{
  TRACE("((intptr_t)%p, (SteamInventoryResult_t *)%p, (const SteamItemDef_t *)%p, (const uint32 *)%p, (uint32)%d)\n", instancePtr, pResultHandle, pArrayItemDefs, punArrayQuantity, unArrayLength);
  bool result = SteamAPI_ISteamInventory_GenerateItems(instancePtr, pResultHandle, pArrayItemDefs, punArrayQuantity, unArrayLength);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamInventory_GrantPromoItems_(intptr_t instancePtr, SteamInventoryResult_t * pResultHandle)
{
  TRACE("((intptr_t)%p, (SteamInventoryResult_t *)%p)\n", instancePtr, pResultHandle);
  bool result = SteamAPI_ISteamInventory_GrantPromoItems(instancePtr, pResultHandle);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamInventory_AddPromoItem_(intptr_t instancePtr, SteamInventoryResult_t * pResultHandle, SteamItemDef_t itemDef)
{
  TRACE("((intptr_t)%p, (SteamInventoryResult_t *)%p, (SteamItemDef_t)%p)\n", instancePtr, pResultHandle, itemDef);
  bool result = SteamAPI_ISteamInventory_AddPromoItem(instancePtr, pResultHandle, itemDef);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamInventory_AddPromoItems_(intptr_t instancePtr, SteamInventoryResult_t * pResultHandle, const SteamItemDef_t * pArrayItemDefs, uint32 unArrayLength)
{
  TRACE("((intptr_t)%p, (SteamInventoryResult_t *)%p, (const SteamItemDef_t *)%p, (uint32)%d)\n", instancePtr, pResultHandle, pArrayItemDefs, unArrayLength);
  bool result = SteamAPI_ISteamInventory_AddPromoItems(instancePtr, pResultHandle, pArrayItemDefs, unArrayLength);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamInventory_ConsumeItem_(intptr_t instancePtr, SteamInventoryResult_t * pResultHandle, SteamItemInstanceID_t itemConsume, uint32 unQuantity)
{
  TRACE("((intptr_t)%p, (SteamInventoryResult_t *)%p, (SteamItemInstanceID_t)%p, (uint32)%d)\n", instancePtr, pResultHandle, itemConsume, unQuantity);
  bool result = SteamAPI_ISteamInventory_ConsumeItem(instancePtr, pResultHandle, itemConsume, unQuantity);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamInventory_ExchangeItems_(intptr_t instancePtr, SteamInventoryResult_t * pResultHandle, const SteamItemDef_t * pArrayGenerate, const uint32 * punArrayGenerateQuantity, uint32 unArrayGenerateLength, const SteamItemInstanceID_t * pArrayDestroy, const uint32 * punArrayDestroyQuantity, uint32 unArrayDestroyLength)
{
  TRACE("((intptr_t)%p, (SteamInventoryResult_t *)%p, (const SteamItemDef_t *)%p, (const uint32 *)%p, (uint32)%d, (const SteamItemInstanceID_t *)%p, (const uint32 *)%p, (uint32)%d)\n", instancePtr, pResultHandle, pArrayGenerate, punArrayGenerateQuantity, unArrayGenerateLength, pArrayDestroy, punArrayDestroyQuantity, unArrayDestroyLength);
  bool result = SteamAPI_ISteamInventory_ExchangeItems(instancePtr, pResultHandle, pArrayGenerate, punArrayGenerateQuantity, unArrayGenerateLength, pArrayDestroy, punArrayDestroyQuantity, unArrayDestroyLength);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamInventory_TransferItemQuantity_(intptr_t instancePtr, SteamInventoryResult_t * pResultHandle, SteamItemInstanceID_t itemIdSource, uint32 unQuantity, SteamItemInstanceID_t itemIdDest)
{
  TRACE("((intptr_t)%p, (SteamInventoryResult_t *)%p, (SteamItemInstanceID_t)%p, (uint32)%d, (SteamItemInstanceID_t)%p)\n", instancePtr, pResultHandle, itemIdSource, unQuantity, itemIdDest);
  bool result = SteamAPI_ISteamInventory_TransferItemQuantity(instancePtr, pResultHandle, itemIdSource, unQuantity, itemIdDest);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void SteamAPI_ISteamInventory_SendItemDropHeartbeat_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPI_ISteamInventory_SendItemDropHeartbeat(instancePtr);
}
bool SteamAPI_ISteamInventory_TriggerItemDrop_(intptr_t instancePtr, SteamInventoryResult_t * pResultHandle, SteamItemDef_t dropListDefinition)
{
  TRACE("((intptr_t)%p, (SteamInventoryResult_t *)%p, (SteamItemDef_t)%p)\n", instancePtr, pResultHandle, dropListDefinition);
  bool result = SteamAPI_ISteamInventory_TriggerItemDrop(instancePtr, pResultHandle, dropListDefinition);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamInventory_TradeItems_(intptr_t instancePtr, SteamInventoryResult_t * pResultHandle, class CSteamID steamIDTradePartner, const SteamItemInstanceID_t * pArrayGive, const uint32 * pArrayGiveQuantity, uint32 nArrayGiveLength, const SteamItemInstanceID_t * pArrayGet, const uint32 * pArrayGetQuantity, uint32 nArrayGetLength)
{
  TRACE("((intptr_t)%p, (SteamInventoryResult_t *)%p, (class CSteamID)%p, (const SteamItemInstanceID_t *)%p, (const uint32 *)%p, (uint32)%d, (const SteamItemInstanceID_t *)%p, (const uint32 *)%p, (uint32)%d)\n", instancePtr, pResultHandle, steamIDTradePartner, pArrayGive, pArrayGiveQuantity, nArrayGiveLength, pArrayGet, pArrayGetQuantity, nArrayGetLength);
  bool result = SteamAPI_ISteamInventory_TradeItems(instancePtr, pResultHandle, steamIDTradePartner, pArrayGive, pArrayGiveQuantity, nArrayGiveLength, pArrayGet, pArrayGetQuantity, nArrayGetLength);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamInventory_LoadItemDefinitions_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamInventory_LoadItemDefinitions(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamInventory_GetItemDefinitionIDs_(intptr_t instancePtr, SteamItemDef_t * pItemDefIDs, uint32 * punItemDefIDsArraySize)
{
  TRACE("((intptr_t)%p, (SteamItemDef_t *)%p, (uint32 *)%p)\n", instancePtr, pItemDefIDs, punItemDefIDsArraySize);
  bool result = SteamAPI_ISteamInventory_GetItemDefinitionIDs(instancePtr, pItemDefIDs, punItemDefIDsArraySize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamInventory_GetItemDefinitionProperty_(intptr_t instancePtr, SteamItemDef_t iDefinition, const char * pchPropertyName, char * pchValueBuffer, uint32 * punValueBufferSizeOut)
{
  TRACE("((intptr_t)%p, (SteamItemDef_t)%p, (const char *)\"%s\", (char *)%p, (uint32 *)%p)\n", instancePtr, iDefinition, pchPropertyName, pchValueBuffer, punValueBufferSizeOut);
  bool result = SteamAPI_ISteamInventory_GetItemDefinitionProperty(instancePtr, iDefinition, pchPropertyName, pchValueBuffer, punValueBufferSizeOut);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void SteamAPI_ISteamVideo_GetVideoURL_(intptr_t instancePtr, AppId_t unVideoAppID)
{
  TRACE("((intptr_t)%p, (AppId_t)%p)\n", instancePtr, unVideoAppID);
  SteamAPI_ISteamVideo_GetVideoURL(instancePtr, unVideoAppID);
}
bool SteamAPI_ISteamVideo_IsBroadcasting_(intptr_t instancePtr, int * pnNumViewers)
{
  TRACE("((intptr_t)%p, (int *)%p)\n", instancePtr, pnNumViewers);
  bool result = SteamAPI_ISteamVideo_IsBroadcasting(instancePtr, pnNumViewers);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamGameServer_InitGameServer_(intptr_t instancePtr, uint32 unIP, uint16 usGamePort, uint16 usQueryPort, uint32 unFlags, AppId_t nGameAppId, const char * pchVersionString)
{
  TRACE("((intptr_t)%p, (uint32)%d, (uint16)%d, (uint16)%d, (uint32)%d, (AppId_t)%p, (const char *)\"%s\")\n", instancePtr, unIP, usGamePort, usQueryPort, unFlags, nGameAppId, pchVersionString);
  bool result = SteamAPI_ISteamGameServer_InitGameServer(instancePtr, unIP, usGamePort, usQueryPort, unFlags, nGameAppId, pchVersionString);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void SteamAPI_ISteamGameServer_SetProduct_(intptr_t instancePtr, const char * pszProduct)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pszProduct);
  SteamAPI_ISteamGameServer_SetProduct(instancePtr, pszProduct);
}
void SteamAPI_ISteamGameServer_SetGameDescription_(intptr_t instancePtr, const char * pszGameDescription)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pszGameDescription);
  SteamAPI_ISteamGameServer_SetGameDescription(instancePtr, pszGameDescription);
}
void SteamAPI_ISteamGameServer_SetModDir_(intptr_t instancePtr, const char * pszModDir)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pszModDir);
  SteamAPI_ISteamGameServer_SetModDir(instancePtr, pszModDir);
}
void SteamAPI_ISteamGameServer_SetDedicatedServer_(intptr_t instancePtr, bool bDedicated)
{
  TRACE("((intptr_t)%p, (bool)%d)\n", instancePtr, bDedicated);
  SteamAPI_ISteamGameServer_SetDedicatedServer(instancePtr, bDedicated);
}
void SteamAPI_ISteamGameServer_LogOn_(intptr_t instancePtr, const char * pszToken)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pszToken);
  SteamAPI_ISteamGameServer_LogOn(instancePtr, pszToken);
}
void SteamAPI_ISteamGameServer_LogOnAnonymous_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPI_ISteamGameServer_LogOnAnonymous(instancePtr);
}
void SteamAPI_ISteamGameServer_LogOff_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPI_ISteamGameServer_LogOff(instancePtr);
}
bool SteamAPI_ISteamGameServer_BLoggedOn_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamGameServer_BLoggedOn(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamGameServer_BSecure_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamGameServer_BSecure(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
uint64 SteamAPI_ISteamGameServer_GetSteamID_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  uint64 result = SteamAPI_ISteamGameServer_GetSteamID(instancePtr);
  TRACE(" = (uint64)%d\n", result);
  return result;
}
bool SteamAPI_ISteamGameServer_WasRestartRequested_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  bool result = SteamAPI_ISteamGameServer_WasRestartRequested(instancePtr);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void SteamAPI_ISteamGameServer_SetMaxPlayerCount_(intptr_t instancePtr, int cPlayersMax)
{
  TRACE("((intptr_t)%p, (int)%d)\n", instancePtr, cPlayersMax);
  SteamAPI_ISteamGameServer_SetMaxPlayerCount(instancePtr, cPlayersMax);
}
void SteamAPI_ISteamGameServer_SetBotPlayerCount_(intptr_t instancePtr, int cBotplayers)
{
  TRACE("((intptr_t)%p, (int)%d)\n", instancePtr, cBotplayers);
  SteamAPI_ISteamGameServer_SetBotPlayerCount(instancePtr, cBotplayers);
}
void SteamAPI_ISteamGameServer_SetServerName_(intptr_t instancePtr, const char * pszServerName)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pszServerName);
  SteamAPI_ISteamGameServer_SetServerName(instancePtr, pszServerName);
}
void SteamAPI_ISteamGameServer_SetMapName_(intptr_t instancePtr, const char * pszMapName)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pszMapName);
  SteamAPI_ISteamGameServer_SetMapName(instancePtr, pszMapName);
}
void SteamAPI_ISteamGameServer_SetPasswordProtected_(intptr_t instancePtr, bool bPasswordProtected)
{
  TRACE("((intptr_t)%p, (bool)%d)\n", instancePtr, bPasswordProtected);
  SteamAPI_ISteamGameServer_SetPasswordProtected(instancePtr, bPasswordProtected);
}
void SteamAPI_ISteamGameServer_SetSpectatorPort_(intptr_t instancePtr, uint16 unSpectatorPort)
{
  TRACE("((intptr_t)%p, (uint16)%d)\n", instancePtr, unSpectatorPort);
  SteamAPI_ISteamGameServer_SetSpectatorPort(instancePtr, unSpectatorPort);
}
void SteamAPI_ISteamGameServer_SetSpectatorServerName_(intptr_t instancePtr, const char * pszSpectatorServerName)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pszSpectatorServerName);
  SteamAPI_ISteamGameServer_SetSpectatorServerName(instancePtr, pszSpectatorServerName);
}
void SteamAPI_ISteamGameServer_ClearAllKeyValues_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPI_ISteamGameServer_ClearAllKeyValues(instancePtr);
}
void SteamAPI_ISteamGameServer_SetKeyValue_(intptr_t instancePtr, const char * pKey, const char * pValue)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\", (const char *)\"%s\")\n", instancePtr, pKey, pValue);
  SteamAPI_ISteamGameServer_SetKeyValue(instancePtr, pKey, pValue);
}
void SteamAPI_ISteamGameServer_SetGameTags_(intptr_t instancePtr, const char * pchGameTags)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchGameTags);
  SteamAPI_ISteamGameServer_SetGameTags(instancePtr, pchGameTags);
}
void SteamAPI_ISteamGameServer_SetGameData_(intptr_t instancePtr, const char * pchGameData)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pchGameData);
  SteamAPI_ISteamGameServer_SetGameData(instancePtr, pchGameData);
}
void SteamAPI_ISteamGameServer_SetRegion_(intptr_t instancePtr, const char * pszRegion)
{
  TRACE("((intptr_t)%p, (const char *)\"%s\")\n", instancePtr, pszRegion);
  SteamAPI_ISteamGameServer_SetRegion(instancePtr, pszRegion);
}
bool SteamAPI_ISteamGameServer_SendUserConnectAndAuthenticate_(intptr_t instancePtr, uint32 unIPClient, const void * pvAuthBlob, uint32 cubAuthBlobSize, class CSteamID * pSteamIDUser)
{
  TRACE("((intptr_t)%p, (uint32)%d, (const void *)%p, (uint32)%d, (class CSteamID *)%p)\n", instancePtr, unIPClient, pvAuthBlob, cubAuthBlobSize, pSteamIDUser);
  bool result = SteamAPI_ISteamGameServer_SendUserConnectAndAuthenticate(instancePtr, unIPClient, pvAuthBlob, cubAuthBlobSize, pSteamIDUser);
  TRACE(" = (bool)%d\n", result);
  return result;
}
uint64 SteamAPI_ISteamGameServer_CreateUnauthenticatedUserConnection_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  uint64 result = SteamAPI_ISteamGameServer_CreateUnauthenticatedUserConnection(instancePtr);
  TRACE(" = (uint64)%d\n", result);
  return result;
}
void SteamAPI_ISteamGameServer_SendUserDisconnect_(intptr_t instancePtr, class CSteamID steamIDUser)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDUser);
  SteamAPI_ISteamGameServer_SendUserDisconnect(instancePtr, steamIDUser);
}
bool SteamAPI_ISteamGameServer_BUpdateUserData_(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchPlayerName, uint32 uScore)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const char *)\"%s\", (uint32)%d)\n", instancePtr, steamIDUser, pchPlayerName, uScore);
  bool result = SteamAPI_ISteamGameServer_BUpdateUserData(instancePtr, steamIDUser, pchPlayerName, uScore);
  TRACE(" = (bool)%d\n", result);
  return result;
}
HAuthTicket SteamAPI_ISteamGameServer_GetAuthSessionTicket_(intptr_t instancePtr, void * pTicket, int cbMaxTicket, uint32 * pcbTicket)
{
  TRACE("((intptr_t)%p, (void *)%p, (int)%d, (uint32 *)%p)\n", instancePtr, pTicket, cbMaxTicket, pcbTicket);
  HAuthTicket result = SteamAPI_ISteamGameServer_GetAuthSessionTicket(instancePtr, pTicket, cbMaxTicket, pcbTicket);
  TRACE(" = (HAuthTicket)%p\n", result);
  return result;
}
EBeginAuthSessionResult SteamAPI_ISteamGameServer_BeginAuthSession_(intptr_t instancePtr, const void * pAuthTicket, int cbAuthTicket, class CSteamID steamID)
{
  TRACE("((intptr_t)%p, (const void *)%p, (int)%d, (class CSteamID)%p)\n", instancePtr, pAuthTicket, cbAuthTicket, steamID);
  EBeginAuthSessionResult result = SteamAPI_ISteamGameServer_BeginAuthSession(instancePtr, pAuthTicket, cbAuthTicket, steamID);
  TRACE(" = (EBeginAuthSessionResult)%p\n", result);
  return result;
}
void SteamAPI_ISteamGameServer_EndAuthSession_(intptr_t instancePtr, class CSteamID steamID)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamID);
  SteamAPI_ISteamGameServer_EndAuthSession(instancePtr, steamID);
}
void SteamAPI_ISteamGameServer_CancelAuthTicket_(intptr_t instancePtr, HAuthTicket hAuthTicket)
{
  TRACE("((intptr_t)%p, (HAuthTicket)%p)\n", instancePtr, hAuthTicket);
  SteamAPI_ISteamGameServer_CancelAuthTicket(instancePtr, hAuthTicket);
}
EUserHasLicenseForAppResult SteamAPI_ISteamGameServer_UserHasLicenseForApp_(intptr_t instancePtr, class CSteamID steamID, AppId_t appID)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (AppId_t)%p)\n", instancePtr, steamID, appID);
  EUserHasLicenseForAppResult result = SteamAPI_ISteamGameServer_UserHasLicenseForApp(instancePtr, steamID, appID);
  TRACE(" = (EUserHasLicenseForAppResult)%p\n", result);
  return result;
}
bool SteamAPI_ISteamGameServer_RequestUserGroupStatus_(intptr_t instancePtr, class CSteamID steamIDUser, class CSteamID steamIDGroup)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (class CSteamID)%p)\n", instancePtr, steamIDUser, steamIDGroup);
  bool result = SteamAPI_ISteamGameServer_RequestUserGroupStatus(instancePtr, steamIDUser, steamIDGroup);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void SteamAPI_ISteamGameServer_GetGameplayStats_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPI_ISteamGameServer_GetGameplayStats(instancePtr);
}
SteamAPICall_t SteamAPI_ISteamGameServer_GetServerReputation_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPICall_t result = SteamAPI_ISteamGameServer_GetServerReputation(instancePtr);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
uint32 SteamAPI_ISteamGameServer_GetPublicIP_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  uint32 result = SteamAPI_ISteamGameServer_GetPublicIP(instancePtr);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
bool SteamAPI_ISteamGameServer_HandleIncomingPacket_(intptr_t instancePtr, const void * pData, int cbData, uint32 srcIP, uint16 srcPort)
{
  TRACE("((intptr_t)%p, (const void *)%p, (int)%d, (uint32)%d, (uint16)%d)\n", instancePtr, pData, cbData, srcIP, srcPort);
  bool result = SteamAPI_ISteamGameServer_HandleIncomingPacket(instancePtr, pData, cbData, srcIP, srcPort);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int SteamAPI_ISteamGameServer_GetNextOutgoingPacket_(intptr_t instancePtr, void * pOut, int cbMaxOut, uint32 * pNetAdr, uint16 * pPort)
{
  TRACE("((intptr_t)%p, (void *)%p, (int)%d, (uint32 *)%p, (uint16 *)%p)\n", instancePtr, pOut, cbMaxOut, pNetAdr, pPort);
  int result = SteamAPI_ISteamGameServer_GetNextOutgoingPacket(instancePtr, pOut, cbMaxOut, pNetAdr, pPort);
  TRACE(" = (int)%d\n", result);
  return result;
}
void SteamAPI_ISteamGameServer_EnableHeartbeats_(intptr_t instancePtr, bool bActive)
{
  TRACE("((intptr_t)%p, (bool)%d)\n", instancePtr, bActive);
  SteamAPI_ISteamGameServer_EnableHeartbeats(instancePtr, bActive);
}
void SteamAPI_ISteamGameServer_SetHeartbeatInterval_(intptr_t instancePtr, int iHeartbeatInterval)
{
  TRACE("((intptr_t)%p, (int)%d)\n", instancePtr, iHeartbeatInterval);
  SteamAPI_ISteamGameServer_SetHeartbeatInterval(instancePtr, iHeartbeatInterval);
}
void SteamAPI_ISteamGameServer_ForceHeartbeat_(intptr_t instancePtr)
{
  TRACE("((intptr_t)%p)\n", instancePtr);
  SteamAPI_ISteamGameServer_ForceHeartbeat(instancePtr);
}
SteamAPICall_t SteamAPI_ISteamGameServer_AssociateWithClan_(intptr_t instancePtr, class CSteamID steamIDClan)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDClan);
  SteamAPICall_t result = SteamAPI_ISteamGameServer_AssociateWithClan(instancePtr, steamIDClan);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamGameServer_ComputeNewPlayerCompatibility_(intptr_t instancePtr, class CSteamID steamIDNewPlayer)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDNewPlayer);
  SteamAPICall_t result = SteamAPI_ISteamGameServer_ComputeNewPlayerCompatibility(instancePtr, steamIDNewPlayer);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamGameServerStats_RequestUserStats_(intptr_t instancePtr, class CSteamID steamIDUser)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDUser);
  SteamAPICall_t result = SteamAPI_ISteamGameServerStats_RequestUserStats(instancePtr, steamIDUser);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
bool SteamAPI_ISteamGameServerStats_GetUserStat_(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, int32 * pData)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const char *)\"%s\", (int32 *)%p)\n", instancePtr, steamIDUser, pchName, pData);
  bool result = SteamAPI_ISteamGameServerStats_GetUserStat(instancePtr, steamIDUser, pchName, pData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamGameServerStats_GetUserStat0_(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, float * pData)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const char *)\"%s\", (float *)%f)\n", instancePtr, steamIDUser, pchName, pData);
  bool result = SteamAPI_ISteamGameServerStats_GetUserStat0(instancePtr, steamIDUser, pchName, pData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamGameServerStats_GetUserAchievement_(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, bool * pbAchieved)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const char *)\"%s\", (bool *)%p)\n", instancePtr, steamIDUser, pchName, pbAchieved);
  bool result = SteamAPI_ISteamGameServerStats_GetUserAchievement(instancePtr, steamIDUser, pchName, pbAchieved);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamGameServerStats_SetUserStat_(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, int32 nData)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const char *)\"%s\", (int32)%d)\n", instancePtr, steamIDUser, pchName, nData);
  bool result = SteamAPI_ISteamGameServerStats_SetUserStat(instancePtr, steamIDUser, pchName, nData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamGameServerStats_SetUserStat0_(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, float fData)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const char *)\"%s\", (float)%f)\n", instancePtr, steamIDUser, pchName, fData);
  bool result = SteamAPI_ISteamGameServerStats_SetUserStat0(instancePtr, steamIDUser, pchName, fData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamGameServerStats_UpdateUserAvgRateStat_(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName, float flCountThisSession, double dSessionLength)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const char *)\"%s\", (float)%f, (double)%p)\n", instancePtr, steamIDUser, pchName, flCountThisSession, dSessionLength);
  bool result = SteamAPI_ISteamGameServerStats_UpdateUserAvgRateStat(instancePtr, steamIDUser, pchName, flCountThisSession, dSessionLength);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamGameServerStats_SetUserAchievement_(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const char *)\"%s\")\n", instancePtr, steamIDUser, pchName);
  bool result = SteamAPI_ISteamGameServerStats_SetUserAchievement(instancePtr, steamIDUser, pchName);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool SteamAPI_ISteamGameServerStats_ClearUserAchievement_(intptr_t instancePtr, class CSteamID steamIDUser, const char * pchName)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p, (const char *)\"%s\")\n", instancePtr, steamIDUser, pchName);
  bool result = SteamAPI_ISteamGameServerStats_ClearUserAchievement(instancePtr, steamIDUser, pchName);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t SteamAPI_ISteamGameServerStats_StoreUserStats_(intptr_t instancePtr, class CSteamID steamIDUser)
{
  TRACE("((intptr_t)%p, (class CSteamID)%p)\n", instancePtr, steamIDUser);
  SteamAPICall_t result = SteamAPI_ISteamGameServerStats_StoreUserStats(instancePtr, steamIDUser);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
HSteamUser SteamAPI_GetHSteamUser_()
{
  TRACE("()\n");
  HSteamUser result = SteamAPI_GetHSteamUser();
  TRACE(" = (HSteamUser)%p\n", result);
  return result;
}
void SteamAPI_UseBreakpadCrashHandler_(char const * pchVersion, char const * pchDate, char const * pchTime, bool bFullMemoryDumps, void * pvContext, PFNPreMinidumpCallback m_pfnPreMinidumpCallback)
{
  TRACE("((char const *)%p, (char const *)%p, (char const *)%p, (bool)%d, (void *)%p, (PFNPreMinidumpCallback)%p)\n", pchVersion, pchDate, pchTime, bFullMemoryDumps, pvContext, m_pfnPreMinidumpCallback);
  SteamAPI_UseBreakpadCrashHandler(pchVersion, pchDate, pchTime, bFullMemoryDumps, pvContext, m_pfnPreMinidumpCallback);
}
void SteamAPI_SetBreakpadAppID_(uint32 unAppID)
{
  TRACE("((uint32)%d)\n", unAppID);
  SteamAPI_SetBreakpadAppID(unAppID);
}
#ifdef __cplusplus
}
#endif
