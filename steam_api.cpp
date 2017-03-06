#include <steam_api_.h>
#include <steam_api_flat.h>
extern "C" {

bool  SteamAPI_Init_()
{
  TRACE("()\n");
  auto result = SteamAPI_Init();
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  SteamAPI_Shutdown_()
{
  TRACE("()\n");
  SteamAPI_Shutdown();
  
}


bool  SteamAPI_RestartAppIfNecessary_(uint32  unOwnAppID)
{
  TRACE("((uint32 )%d)\n", unOwnAppID);
  auto result = SteamAPI_RestartAppIfNecessary(unOwnAppID);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  SteamAPI_WriteMiniDump_(uint32  uStructuredExceptionCode, void * pvExceptionInfo, uint32  uBuildID)
{
  TRACE("((uint32 )%d, (void *)%p, (uint32 )%d)\n", uStructuredExceptionCode, pvExceptionInfo, uBuildID);
  SteamAPI_WriteMiniDump(uStructuredExceptionCode, pvExceptionInfo, uBuildID);
  
}


void  SteamAPI_SetMiniDumpComment_(char * pchMsg)
{
  TRACE("((char *)\"%s\")\n", pchMsg);
  SteamAPI_SetMiniDumpComment(pchMsg);
  
}

ISteamClient * saved_ISteamClient = NULL;
ISteamClient * SteamClient_()
{
  TRACE("()\n");
  if (saved_ISteamClient == NULL) {
    auto internal = SteamClient();
    if (internal == NULL) {
      TRACE("() = NULL!\n");
      return saved_ISteamClient;
    }
    saved_ISteamClient = (ISteamClient *) new ISteamClient_(internal);
    TRACE("(): (ISteamClient *)%p wrapped as (ISteamClient_ *)%p\n", internal, saved_ISteamClient);
  }
  TRACE("() = (ISteamClient_ *)%p\n", saved_ISteamClient);

  return saved_ISteamClient;
}

ISteamUser * saved_ISteamUser = NULL;
ISteamUser * SteamUser_()
{
  TRACE("()\n");
  if (saved_ISteamUser == NULL) {
    auto internal = SteamUser();
    if (internal == NULL) {
      TRACE("() = NULL!\n");
      return saved_ISteamUser;
    }
    saved_ISteamUser = (ISteamUser *) new ISteamUser_(internal);
    TRACE("(): (ISteamUser *)%p wrapped as (ISteamUser_ *)%p\n", internal, saved_ISteamUser);
  }
  TRACE("() = (ISteamUser_ *)%p\n", saved_ISteamUser);

  return saved_ISteamUser;
}

ISteamFriends * saved_ISteamFriends = NULL;
ISteamFriends * SteamFriends_()
{
  TRACE("()\n");
  if (saved_ISteamFriends == NULL) {
    auto internal = SteamFriends();
    if (internal == NULL) {
      TRACE("() = NULL!\n");
      return saved_ISteamFriends;
    }
    saved_ISteamFriends = (ISteamFriends *) new ISteamFriends_(internal);
    TRACE("(): (ISteamFriends *)%p wrapped as (ISteamFriends_ *)%p\n", internal, saved_ISteamFriends);
  }
  TRACE("() = (ISteamFriends_ *)%p\n", saved_ISteamFriends);

  return saved_ISteamFriends;
}

ISteamUtils * saved_ISteamUtils = NULL;
ISteamUtils * SteamUtils_()
{
  TRACE("()\n");
  if (saved_ISteamUtils == NULL) {
    auto internal = SteamUtils();
    if (internal == NULL) {
      TRACE("() = NULL!\n");
      return saved_ISteamUtils;
    }
    saved_ISteamUtils = (ISteamUtils *) new ISteamUtils_(internal);
    TRACE("(): (ISteamUtils *)%p wrapped as (ISteamUtils_ *)%p\n", internal, saved_ISteamUtils);
  }
  TRACE("() = (ISteamUtils_ *)%p\n", saved_ISteamUtils);

  return saved_ISteamUtils;
}

ISteamMatchmaking * saved_ISteamMatchmaking = NULL;
ISteamMatchmaking * SteamMatchmaking_()
{
  TRACE("()\n");
  if (saved_ISteamMatchmaking == NULL) {
    auto internal = SteamMatchmaking();
    if (internal == NULL) {
      TRACE("() = NULL!\n");
      return saved_ISteamMatchmaking;
    }
    saved_ISteamMatchmaking = (ISteamMatchmaking *) new ISteamMatchmaking_(internal);
    TRACE("(): (ISteamMatchmaking *)%p wrapped as (ISteamMatchmaking_ *)%p\n", internal, saved_ISteamMatchmaking);
  }
  TRACE("() = (ISteamMatchmaking_ *)%p\n", saved_ISteamMatchmaking);

  return saved_ISteamMatchmaking;
}

ISteamUserStats * saved_ISteamUserStats = NULL;
ISteamUserStats * SteamUserStats_()
{
  TRACE("()\n");
  if (saved_ISteamUserStats == NULL) {
    auto internal = SteamUserStats();
    if (internal == NULL) {
      TRACE("() = NULL!\n");
      return saved_ISteamUserStats;
    }
    saved_ISteamUserStats = (ISteamUserStats *) new ISteamUserStats_(internal);
    TRACE("(): (ISteamUserStats *)%p wrapped as (ISteamUserStats_ *)%p\n", internal, saved_ISteamUserStats);
  }
  TRACE("() = (ISteamUserStats_ *)%p\n", saved_ISteamUserStats);

  return saved_ISteamUserStats;
}

ISteamApps * saved_ISteamApps = NULL;
ISteamApps * SteamApps_()
{
  TRACE("()\n");
  if (saved_ISteamApps == NULL) {
    auto internal = SteamApps();
    if (internal == NULL) {
      TRACE("() = NULL!\n");
      return saved_ISteamApps;
    }
    saved_ISteamApps = (ISteamApps *) new ISteamApps_(internal);
    TRACE("(): (ISteamApps *)%p wrapped as (ISteamApps_ *)%p\n", internal, saved_ISteamApps);
  }
  TRACE("() = (ISteamApps_ *)%p\n", saved_ISteamApps);

  return saved_ISteamApps;
}

ISteamNetworking * saved_ISteamNetworking = NULL;
ISteamNetworking * SteamNetworking_()
{
  TRACE("()\n");
  if (saved_ISteamNetworking == NULL) {
    auto internal = SteamNetworking();
    if (internal == NULL) {
      TRACE("() = NULL!\n");
      return saved_ISteamNetworking;
    }
    saved_ISteamNetworking = (ISteamNetworking *) new ISteamNetworking_(internal);
    TRACE("(): (ISteamNetworking *)%p wrapped as (ISteamNetworking_ *)%p\n", internal, saved_ISteamNetworking);
  }
  TRACE("() = (ISteamNetworking_ *)%p\n", saved_ISteamNetworking);

  return saved_ISteamNetworking;
}

ISteamMatchmakingServers * saved_ISteamMatchmakingServers = NULL;
ISteamMatchmakingServers * SteamMatchmakingServers_()
{
  TRACE("()\n");
  if (saved_ISteamMatchmakingServers == NULL) {
    auto internal = SteamMatchmakingServers();
    if (internal == NULL) {
      TRACE("() = NULL!\n");
      return saved_ISteamMatchmakingServers;
    }
    saved_ISteamMatchmakingServers = (ISteamMatchmakingServers *) new ISteamMatchmakingServers_(internal);
    TRACE("(): (ISteamMatchmakingServers *)%p wrapped as (ISteamMatchmakingServers_ *)%p\n", internal, saved_ISteamMatchmakingServers);
  }
  TRACE("() = (ISteamMatchmakingServers_ *)%p\n", saved_ISteamMatchmakingServers);

  return saved_ISteamMatchmakingServers;
}

ISteamRemoteStorage * saved_ISteamRemoteStorage = NULL;
ISteamRemoteStorage * SteamRemoteStorage_()
{
  TRACE("()\n");
  if (saved_ISteamRemoteStorage == NULL) {
    auto internal = SteamRemoteStorage();
    if (internal == NULL) {
      TRACE("() = NULL!\n");
      return saved_ISteamRemoteStorage;
    }
    saved_ISteamRemoteStorage = (ISteamRemoteStorage *) new ISteamRemoteStorage_(internal);
    TRACE("(): (ISteamRemoteStorage *)%p wrapped as (ISteamRemoteStorage_ *)%p\n", internal, saved_ISteamRemoteStorage);
  }
  TRACE("() = (ISteamRemoteStorage_ *)%p\n", saved_ISteamRemoteStorage);

  return saved_ISteamRemoteStorage;
}

ISteamScreenshots * saved_ISteamScreenshots = NULL;
ISteamScreenshots * SteamScreenshots_()
{
  TRACE("()\n");
  if (saved_ISteamScreenshots == NULL) {
    auto internal = SteamScreenshots();
    if (internal == NULL) {
      TRACE("() = NULL!\n");
      return saved_ISteamScreenshots;
    }
    saved_ISteamScreenshots = (ISteamScreenshots *) new ISteamScreenshots_(internal);
    TRACE("(): (ISteamScreenshots *)%p wrapped as (ISteamScreenshots_ *)%p\n", internal, saved_ISteamScreenshots);
  }
  TRACE("() = (ISteamScreenshots_ *)%p\n", saved_ISteamScreenshots);

  return saved_ISteamScreenshots;
}

ISteamHTTP * saved_ISteamHTTP = NULL;
ISteamHTTP * SteamHTTP_()
{
  TRACE("()\n");
  if (saved_ISteamHTTP == NULL) {
    auto internal = SteamHTTP();
    if (internal == NULL) {
      TRACE("() = NULL!\n");
      return saved_ISteamHTTP;
    }
    saved_ISteamHTTP = (ISteamHTTP *) new ISteamHTTP_(internal);
    TRACE("(): (ISteamHTTP *)%p wrapped as (ISteamHTTP_ *)%p\n", internal, saved_ISteamHTTP);
  }
  TRACE("() = (ISteamHTTP_ *)%p\n", saved_ISteamHTTP);

  return saved_ISteamHTTP;
}

ISteamUnifiedMessages * saved_ISteamUnifiedMessages = NULL;
ISteamUnifiedMessages * SteamUnifiedMessages_()
{
  TRACE("()\n");
  if (saved_ISteamUnifiedMessages == NULL) {
    auto internal = SteamUnifiedMessages();
    if (internal == NULL) {
      TRACE("() = NULL!\n");
      return saved_ISteamUnifiedMessages;
    }
    saved_ISteamUnifiedMessages = (ISteamUnifiedMessages *) new ISteamUnifiedMessages_(internal);
    TRACE("(): (ISteamUnifiedMessages *)%p wrapped as (ISteamUnifiedMessages_ *)%p\n", internal, saved_ISteamUnifiedMessages);
  }
  TRACE("() = (ISteamUnifiedMessages_ *)%p\n", saved_ISteamUnifiedMessages);

  return saved_ISteamUnifiedMessages;
}

ISteamController * saved_ISteamController = NULL;
ISteamController * SteamController_()
{
  TRACE("()\n");
  if (saved_ISteamController == NULL) {
    auto internal = SteamController();
    if (internal == NULL) {
      TRACE("() = NULL!\n");
      return saved_ISteamController;
    }
    saved_ISteamController = (ISteamController *) new ISteamController_(internal);
    TRACE("(): (ISteamController *)%p wrapped as (ISteamController_ *)%p\n", internal, saved_ISteamController);
  }
  TRACE("() = (ISteamController_ *)%p\n", saved_ISteamController);

  return saved_ISteamController;
}

ISteamUGC * saved_ISteamUGC = NULL;
ISteamUGC * SteamUGC_()
{
  TRACE("()\n");
  if (saved_ISteamUGC == NULL) {
    auto internal = SteamUGC();
    if (internal == NULL) {
      TRACE("() = NULL!\n");
      return saved_ISteamUGC;
    }
    saved_ISteamUGC = (ISteamUGC *) new ISteamUGC_(internal);
    TRACE("(): (ISteamUGC *)%p wrapped as (ISteamUGC_ *)%p\n", internal, saved_ISteamUGC);
  }
  TRACE("() = (ISteamUGC_ *)%p\n", saved_ISteamUGC);

  return saved_ISteamUGC;
}

ISteamAppList * saved_ISteamAppList = NULL;
ISteamAppList * SteamAppList_()
{
  TRACE("()\n");
  if (saved_ISteamAppList == NULL) {
    auto internal = SteamAppList();
    if (internal == NULL) {
      TRACE("() = NULL!\n");
      return saved_ISteamAppList;
    }
    saved_ISteamAppList = (ISteamAppList *) new ISteamAppList_(internal);
    TRACE("(): (ISteamAppList *)%p wrapped as (ISteamAppList_ *)%p\n", internal, saved_ISteamAppList);
  }
  TRACE("() = (ISteamAppList_ *)%p\n", saved_ISteamAppList);

  return saved_ISteamAppList;
}

ISteamMusic * saved_ISteamMusic = NULL;
ISteamMusic * SteamMusic_()
{
  TRACE("()\n");
  if (saved_ISteamMusic == NULL) {
    auto internal = SteamMusic();
    if (internal == NULL) {
      TRACE("() = NULL!\n");
      return saved_ISteamMusic;
    }
    saved_ISteamMusic = (ISteamMusic *) new ISteamMusic_(internal);
    TRACE("(): (ISteamMusic *)%p wrapped as (ISteamMusic_ *)%p\n", internal, saved_ISteamMusic);
  }
  TRACE("() = (ISteamMusic_ *)%p\n", saved_ISteamMusic);

  return saved_ISteamMusic;
}

ISteamMusicRemote * saved_ISteamMusicRemote = NULL;
ISteamMusicRemote * SteamMusicRemote_()
{
  TRACE("()\n");
  if (saved_ISteamMusicRemote == NULL) {
    auto internal = SteamMusicRemote();
    if (internal == NULL) {
      TRACE("() = NULL!\n");
      return saved_ISteamMusicRemote;
    }
    saved_ISteamMusicRemote = (ISteamMusicRemote *) new ISteamMusicRemote_(internal);
    TRACE("(): (ISteamMusicRemote *)%p wrapped as (ISteamMusicRemote_ *)%p\n", internal, saved_ISteamMusicRemote);
  }
  TRACE("() = (ISteamMusicRemote_ *)%p\n", saved_ISteamMusicRemote);

  return saved_ISteamMusicRemote;
}

ISteamHTMLSurface * saved_ISteamHTMLSurface = NULL;
ISteamHTMLSurface * SteamHTMLSurface_()
{
  TRACE("()\n");
  if (saved_ISteamHTMLSurface == NULL) {
    auto internal = SteamHTMLSurface();
    if (internal == NULL) {
      TRACE("() = NULL!\n");
      return saved_ISteamHTMLSurface;
    }
    saved_ISteamHTMLSurface = (ISteamHTMLSurface *) new ISteamHTMLSurface_(internal);
    TRACE("(): (ISteamHTMLSurface *)%p wrapped as (ISteamHTMLSurface_ *)%p\n", internal, saved_ISteamHTMLSurface);
  }
  TRACE("() = (ISteamHTMLSurface_ *)%p\n", saved_ISteamHTMLSurface);

  return saved_ISteamHTMLSurface;
}

ISteamInventory * saved_ISteamInventory = NULL;
ISteamInventory * SteamInventory_()
{
  TRACE("()\n");
  if (saved_ISteamInventory == NULL) {
    auto internal = SteamInventory();
    if (internal == NULL) {
      TRACE("() = NULL!\n");
      return saved_ISteamInventory;
    }
    saved_ISteamInventory = (ISteamInventory *) new ISteamInventory_(internal);
    TRACE("(): (ISteamInventory *)%p wrapped as (ISteamInventory_ *)%p\n", internal, saved_ISteamInventory);
  }
  TRACE("() = (ISteamInventory_ *)%p\n", saved_ISteamInventory);

  return saved_ISteamInventory;
}

ISteamVideo * saved_ISteamVideo = NULL;
ISteamVideo * SteamVideo_()
{
  TRACE("()\n");
  if (saved_ISteamVideo == NULL) {
    auto internal = SteamVideo();
    if (internal == NULL) {
      TRACE("() = NULL!\n");
      return saved_ISteamVideo;
    }
    saved_ISteamVideo = (ISteamVideo *) new ISteamVideo_(internal);
    TRACE("(): (ISteamVideo *)%p wrapped as (ISteamVideo_ *)%p\n", internal, saved_ISteamVideo);
  }
  TRACE("() = (ISteamVideo_ *)%p\n", saved_ISteamVideo);

  return saved_ISteamVideo;
}


void  SteamAPI_RunCallbacks_()
{
  
  SteamAPI_RunCallbacks();
  
}






bool  SteamAPI_IsSteamRunning_()
{
  TRACE("()\n");
  auto result = SteamAPI_IsSteamRunning();
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  Steam_RunCallbacks_(HSteamPipe  hSteamPipe, bool  bGameServerCallbacks)
{
  TRACE("((HSteamPipe )%p, (bool )%d)\n", hSteamPipe, bGameServerCallbacks);
  Steam_RunCallbacks(hSteamPipe, bGameServerCallbacks);
  
}


void  Steam_RegisterInterfaceFuncs_(void * hModule)
{
  TRACE("((void *)%p)\n", hModule);
  Steam_RegisterInterfaceFuncs(hModule);
  
}


HSteamUser  Steam_GetHSteamUserCurrent_()
{
  TRACE("()\n");
  auto result = Steam_GetHSteamUserCurrent();
  TRACE("() = (HSteamUser )%p\n", result);

  return result;
}


char * SteamAPI_GetSteamInstallPath_()
{
  TRACE("()\n");
  auto result = SteamAPI_GetSteamInstallPath();
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


HSteamPipe  SteamAPI_GetHSteamPipe_()
{
  TRACE("()\n");
  auto result = SteamAPI_GetHSteamPipe();
  TRACE("() = (HSteamPipe )%p\n", result);

  return result;
}


void  SteamAPI_SetTryCatchCallbacks_(bool  bTryCatchCallbacks)
{
  TRACE("((bool )%d)\n", bTryCatchCallbacks);
  SteamAPI_SetTryCatchCallbacks(bTryCatchCallbacks);
  
}


HSteamPipe  GetHSteamPipe_()
{
  TRACE("()\n");
  auto result = GetHSteamPipe();
  TRACE("() = (HSteamPipe )%p\n", result);

  return result;
}


HSteamUser  GetHSteamUser_()
{
  TRACE("()\n");
  auto result = GetHSteamUser();
  TRACE("() = (HSteamUser )%p\n", result);

  return result;
}


bool  SteamAPI_InitSafe_()
{
  TRACE("()\n");
  auto result = SteamAPI_InitSafe();
  TRACE("() = (bool )%d\n", result);

  return result;
}


HSteamUser  SteamAPI_GetHSteamUser_()
{
  TRACE("()\n");
  auto result = SteamAPI_GetHSteamUser();
  TRACE("() = (HSteamUser )%p\n", result);

  return result;
}


void  SteamAPI_UseBreakpadCrashHandler_(char const * pchVersion, char const * pchDate, char const * pchTime, bool  bFullMemoryDumps, void * pvContext, PFNPreMinidumpCallback  m_pfnPreMinidumpCallback)
{
  TRACE("((char const *)%p, (char const *)%p, (char const *)%p, (bool )%d, (void *)%p, (PFNPreMinidumpCallback )%p)\n", pchVersion, pchDate, pchTime, bFullMemoryDumps, pvContext, m_pfnPreMinidumpCallback);
  SteamAPI_UseBreakpadCrashHandler(pchVersion, pchDate, pchTime, bFullMemoryDumps, pvContext, m_pfnPreMinidumpCallback);
  
}


void  SteamAPI_SetBreakpadAppID_(uint32  unAppID)
{
  TRACE("((uint32 )%d)\n", unAppID);
  SteamAPI_SetBreakpadAppID(unAppID);
  
}


HSteamPipe  SteamAPI_ISteamClient_CreateSteamPipe_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamClient_CreateSteamPipe(instancePtr);
  TRACE("() = (HSteamPipe )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamClient_BReleaseSteamPipe_(intptr_t  instancePtr, HSteamPipe  hSteamPipe)
{
  TRACE("((intptr_t )%p, (HSteamPipe )%p)\n", instancePtr, hSteamPipe);
  auto result = SteamAPI_ISteamClient_BReleaseSteamPipe(instancePtr, hSteamPipe);
  TRACE("() = (bool )%d\n", result);

  return result;
}


HSteamUser  SteamAPI_ISteamClient_ConnectToGlobalUser_(intptr_t  instancePtr, HSteamPipe  hSteamPipe)
{
  TRACE("((intptr_t )%p, (HSteamPipe )%p)\n", instancePtr, hSteamPipe);
  auto result = SteamAPI_ISteamClient_ConnectToGlobalUser(instancePtr, hSteamPipe);
  TRACE("() = (HSteamUser )%p\n", result);

  return result;
}


HSteamUser  SteamAPI_ISteamClient_CreateLocalUser_(intptr_t  instancePtr, HSteamPipe * phSteamPipe, EAccountType  eAccountType)
{
  TRACE("((intptr_t )%p, (HSteamPipe *)%p, (EAccountType )%p)\n", instancePtr, phSteamPipe, eAccountType);
  auto result = SteamAPI_ISteamClient_CreateLocalUser(instancePtr, phSteamPipe, eAccountType);
  TRACE("() = (HSteamUser )%p\n", result);

  return result;
}


void  SteamAPI_ISteamClient_ReleaseUser_(intptr_t  instancePtr, HSteamPipe  hSteamPipe, HSteamUser  hUser)
{
  TRACE("((intptr_t )%p, (HSteamPipe )%p, (HSteamUser )%p)\n", instancePtr, hSteamPipe, hUser);
  SteamAPI_ISteamClient_ReleaseUser(instancePtr, hSteamPipe, hUser);
  
}


ISteamUser * SteamAPI_ISteamClient_GetISteamUser_(intptr_t  instancePtr, HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamUser_(SteamAPI_ISteamClient_GetISteamUser(instancePtr, hSteamUser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamUser *)%p\n", result);

  return (ISteamUser *)result;
}


ISteamGameServer * SteamAPI_ISteamClient_GetISteamGameServer_(intptr_t  instancePtr, HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamGameServer_(SteamAPI_ISteamClient_GetISteamGameServer(instancePtr, hSteamUser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamGameServer *)%p\n", result);

  return (ISteamGameServer *)result;
}


void  SteamAPI_ISteamClient_SetLocalIPBinding_(intptr_t  instancePtr, uint32  unIP, uint16  usPort)
{
  TRACE("((intptr_t )%p, (uint32 )%d, (uint16 )%d)\n", instancePtr, unIP, usPort);
  SteamAPI_ISteamClient_SetLocalIPBinding(instancePtr, unIP, usPort);
  
}


ISteamFriends * SteamAPI_ISteamClient_GetISteamFriends_(intptr_t  instancePtr, HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamFriends_(SteamAPI_ISteamClient_GetISteamFriends(instancePtr, hSteamUser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamFriends *)%p\n", result);

  return (ISteamFriends *)result;
}


ISteamUtils * SteamAPI_ISteamClient_GetISteamUtils_(intptr_t  instancePtr, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamPipe, pchVersion);
  auto result = new ISteamUtils_(SteamAPI_ISteamClient_GetISteamUtils(instancePtr, hSteamPipe, pchVersion));
  TRACE("() = (ISteamUtils *)%p\n", result);

  return (ISteamUtils *)result;
}


ISteamMatchmaking * SteamAPI_ISteamClient_GetISteamMatchmaking_(intptr_t  instancePtr, HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamMatchmaking_(SteamAPI_ISteamClient_GetISteamMatchmaking(instancePtr, hSteamUser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamMatchmaking *)%p\n", result);

  return (ISteamMatchmaking *)result;
}


ISteamMatchmakingServers * SteamAPI_ISteamClient_GetISteamMatchmakingServers_(intptr_t  instancePtr, HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamMatchmakingServers_(SteamAPI_ISteamClient_GetISteamMatchmakingServers(instancePtr, hSteamUser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamMatchmakingServers *)%p\n", result);

  return (ISteamMatchmakingServers *)result;
}


void * SteamAPI_ISteamClient_GetISteamGenericInterface_(intptr_t  instancePtr, HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto result = SteamAPI_ISteamClient_GetISteamGenericInterface(instancePtr, hSteamUser, hSteamPipe, pchVersion);
  

  return result;
}


ISteamUserStats * SteamAPI_ISteamClient_GetISteamUserStats_(intptr_t  instancePtr, HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamUserStats_(SteamAPI_ISteamClient_GetISteamUserStats(instancePtr, hSteamUser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamUserStats *)%p\n", result);

  return (ISteamUserStats *)result;
}


ISteamGameServerStats * SteamAPI_ISteamClient_GetISteamGameServerStats_(intptr_t  instancePtr, HSteamUser  hSteamuser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamGameServerStats_(SteamAPI_ISteamClient_GetISteamGameServerStats(instancePtr, hSteamuser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamGameServerStats *)%p\n", result);

  return (ISteamGameServerStats *)result;
}


ISteamApps * SteamAPI_ISteamClient_GetISteamApps_(intptr_t  instancePtr, HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamApps_(SteamAPI_ISteamClient_GetISteamApps(instancePtr, hSteamUser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamApps *)%p\n", result);

  return (ISteamApps *)result;
}


ISteamNetworking * SteamAPI_ISteamClient_GetISteamNetworking_(intptr_t  instancePtr, HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamNetworking_(SteamAPI_ISteamClient_GetISteamNetworking(instancePtr, hSteamUser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamNetworking *)%p\n", result);

  return (ISteamNetworking *)result;
}


ISteamRemoteStorage * SteamAPI_ISteamClient_GetISteamRemoteStorage_(intptr_t  instancePtr, HSteamUser  hSteamuser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamRemoteStorage_(SteamAPI_ISteamClient_GetISteamRemoteStorage(instancePtr, hSteamuser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamRemoteStorage *)%p\n", result);

  return (ISteamRemoteStorage *)result;
}


ISteamScreenshots * SteamAPI_ISteamClient_GetISteamScreenshots_(intptr_t  instancePtr, HSteamUser  hSteamuser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamScreenshots_(SteamAPI_ISteamClient_GetISteamScreenshots(instancePtr, hSteamuser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamScreenshots *)%p\n", result);

  return (ISteamScreenshots *)result;
}


uint32  SteamAPI_ISteamClient_GetIPCCallCount_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamClient_GetIPCCallCount(instancePtr);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


void  SteamAPI_ISteamClient_SetWarningMessageHook_(intptr_t  instancePtr, SteamAPIWarningMessageHook_t  pFunction)
{
  TRACE("((intptr_t )%p, (SteamAPIWarningMessageHook_t )%p)\n", instancePtr, pFunction);
  SteamAPI_ISteamClient_SetWarningMessageHook(instancePtr, pFunction);
  
}


bool  SteamAPI_ISteamClient_BShutdownIfAllPipesClosed_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamClient_BShutdownIfAllPipesClosed(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


ISteamHTTP * SteamAPI_ISteamClient_GetISteamHTTP_(intptr_t  instancePtr, HSteamUser  hSteamuser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamHTTP_(SteamAPI_ISteamClient_GetISteamHTTP(instancePtr, hSteamuser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamHTTP *)%p\n", result);

  return (ISteamHTTP *)result;
}


ISteamUnifiedMessages * SteamAPI_ISteamClient_GetISteamUnifiedMessages_(intptr_t  instancePtr, HSteamUser  hSteamuser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamUnifiedMessages_(SteamAPI_ISteamClient_GetISteamUnifiedMessages(instancePtr, hSteamuser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamUnifiedMessages *)%p\n", result);

  return (ISteamUnifiedMessages *)result;
}


ISteamController * SteamAPI_ISteamClient_GetISteamController_(intptr_t  instancePtr, HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamController_(SteamAPI_ISteamClient_GetISteamController(instancePtr, hSteamUser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamController *)%p\n", result);

  return (ISteamController *)result;
}


ISteamUGC * SteamAPI_ISteamClient_GetISteamUGC_(intptr_t  instancePtr, HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamUGC_(SteamAPI_ISteamClient_GetISteamUGC(instancePtr, hSteamUser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamUGC *)%p\n", result);

  return (ISteamUGC *)result;
}


ISteamAppList * SteamAPI_ISteamClient_GetISteamAppList_(intptr_t  instancePtr, HSteamUser  hSteamUser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamUser, hSteamPipe, pchVersion);
  auto result = new ISteamAppList_(SteamAPI_ISteamClient_GetISteamAppList(instancePtr, hSteamUser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamAppList *)%p\n", result);

  return (ISteamAppList *)result;
}


ISteamMusic * SteamAPI_ISteamClient_GetISteamMusic_(intptr_t  instancePtr, HSteamUser  hSteamuser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamMusic_(SteamAPI_ISteamClient_GetISteamMusic(instancePtr, hSteamuser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamMusic *)%p\n", result);

  return (ISteamMusic *)result;
}


ISteamMusicRemote * SteamAPI_ISteamClient_GetISteamMusicRemote_(intptr_t  instancePtr, HSteamUser  hSteamuser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamMusicRemote_(SteamAPI_ISteamClient_GetISteamMusicRemote(instancePtr, hSteamuser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamMusicRemote *)%p\n", result);

  return (ISteamMusicRemote *)result;
}


ISteamHTMLSurface * SteamAPI_ISteamClient_GetISteamHTMLSurface_(intptr_t  instancePtr, HSteamUser  hSteamuser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamHTMLSurface_(SteamAPI_ISteamClient_GetISteamHTMLSurface(instancePtr, hSteamuser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamHTMLSurface *)%p\n", result);

  return (ISteamHTMLSurface *)result;
}


ISteamInventory * SteamAPI_ISteamClient_GetISteamInventory_(intptr_t  instancePtr, HSteamUser  hSteamuser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamInventory_(SteamAPI_ISteamClient_GetISteamInventory(instancePtr, hSteamuser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamInventory *)%p\n", result);

  return (ISteamInventory *)result;
}


ISteamVideo * SteamAPI_ISteamClient_GetISteamVideo_(intptr_t  instancePtr, HSteamUser  hSteamuser, HSteamPipe  hSteamPipe, char * pchVersion)
{
  TRACE("((intptr_t )%p, (HSteamUser )%p, (HSteamPipe )%p, (char *)\"%s\")\n", instancePtr, hSteamuser, hSteamPipe, pchVersion);
  auto result = new ISteamVideo_(SteamAPI_ISteamClient_GetISteamVideo(instancePtr, hSteamuser, hSteamPipe, pchVersion));
  TRACE("() = (ISteamVideo *)%p\n", result);

  return (ISteamVideo *)result;
}


HSteamUser  SteamAPI_ISteamUser_GetHSteamUser_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUser_GetHSteamUser(instancePtr);
  TRACE("() = (HSteamUser )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamUser_BLoggedOn_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUser_BLoggedOn(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


uint64  SteamAPI_ISteamUser_GetSteamID_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUser_GetSteamID(instancePtr);
  TRACE("() = (uint64 )%d\n", result);

  return result;
}


int  SteamAPI_ISteamUser_InitiateGameConnection_(intptr_t  instancePtr, void * pAuthBlob, int  cbMaxAuthBlob, CSteamID  steamIDGameServer, uint32  unIPServer, uint16  usPortServer, bool  bSecure)
{
  TRACE("((intptr_t )%p, (void *)%p, (int )%d, (CSteamID )%p, (uint32 )%d, (uint16 )%d, (bool )%d)\n", instancePtr, pAuthBlob, cbMaxAuthBlob, steamIDGameServer, unIPServer, usPortServer, bSecure);
  auto result = SteamAPI_ISteamUser_InitiateGameConnection(instancePtr, pAuthBlob, cbMaxAuthBlob, steamIDGameServer, unIPServer, usPortServer, bSecure);
  TRACE("() = (int )%d\n", result);

  return result;
}


void  SteamAPI_ISteamUser_TerminateGameConnection_(intptr_t  instancePtr, uint32  unIPServer, uint16  usPortServer)
{
  TRACE("((intptr_t )%p, (uint32 )%d, (uint16 )%d)\n", instancePtr, unIPServer, usPortServer);
  SteamAPI_ISteamUser_TerminateGameConnection(instancePtr, unIPServer, usPortServer);
  
}


void  SteamAPI_ISteamUser_TrackAppUsageEvent_(intptr_t  instancePtr, CGameID  gameID, int  eAppUsageEvent, char * pchExtraInfo)
{
  TRACE("((intptr_t )%p, (CGameID )%p, (int )%d, (char *)\"%s\")\n", instancePtr, gameID, eAppUsageEvent, pchExtraInfo);
  SteamAPI_ISteamUser_TrackAppUsageEvent(instancePtr, gameID, eAppUsageEvent, pchExtraInfo);
  
}


bool  SteamAPI_ISteamUser_GetUserDataFolder_(intptr_t  instancePtr, char * pchBuffer, int  cubBuffer)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (int )%d)\n", instancePtr, pchBuffer, cubBuffer);
  auto result = SteamAPI_ISteamUser_GetUserDataFolder(instancePtr, pchBuffer, cubBuffer);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  SteamAPI_ISteamUser_StartVoiceRecording_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  SteamAPI_ISteamUser_StartVoiceRecording(instancePtr);
  
}


void  SteamAPI_ISteamUser_StopVoiceRecording_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  SteamAPI_ISteamUser_StopVoiceRecording(instancePtr);
  
}


EVoiceResult  SteamAPI_ISteamUser_GetAvailableVoice_(intptr_t  instancePtr, uint32 * pcbCompressed, uint32 * pcbUncompressed, uint32  nUncompressedVoiceDesiredSampleRate)
{
  TRACE("((intptr_t )%p, (uint32 *)%d, (uint32 *)%d, (uint32 )%d)\n", instancePtr, pcbCompressed, pcbUncompressed, nUncompressedVoiceDesiredSampleRate);
  auto result = SteamAPI_ISteamUser_GetAvailableVoice(instancePtr, pcbCompressed, pcbUncompressed, nUncompressedVoiceDesiredSampleRate);
  TRACE("() = (EVoiceResult )%p\n", result);

  return result;
}


EVoiceResult  SteamAPI_ISteamUser_GetVoice_(intptr_t  instancePtr, bool  bWantCompressed, void * pDestBuffer, uint32  cbDestBufferSize, uint32 * nBytesWritten, bool  bWantUncompressed, void * pUncompressedDestBuffer, uint32  cbUncompressedDestBufferSize, uint32 * nUncompressBytesWritten, uint32  nUncompressedVoiceDesiredSampleRate)
{
  TRACE("((intptr_t )%p, (bool )%d, (void *)%p, (uint32 )%d, (uint32 *)%d, (bool )%d, (void *)%p, (uint32 )%d, (uint32 *)%d, (uint32 )%d)\n", instancePtr, bWantCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, bWantUncompressed, pUncompressedDestBuffer, cbUncompressedDestBufferSize, nUncompressBytesWritten, nUncompressedVoiceDesiredSampleRate);
  auto result = SteamAPI_ISteamUser_GetVoice(instancePtr, bWantCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, bWantUncompressed, pUncompressedDestBuffer, cbUncompressedDestBufferSize, nUncompressBytesWritten, nUncompressedVoiceDesiredSampleRate);
  TRACE("() = (EVoiceResult )%p\n", result);

  return result;
}


EVoiceResult  SteamAPI_ISteamUser_DecompressVoice_(intptr_t  instancePtr, void * pCompressed, uint32  cbCompressed, void * pDestBuffer, uint32  cbDestBufferSize, uint32 * nBytesWritten, uint32  nDesiredSampleRate)
{
  TRACE("((intptr_t )%p, (void *)%p, (uint32 )%d, (void *)%p, (uint32 )%d, (uint32 *)%d, (uint32 )%d)\n", instancePtr, pCompressed, cbCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, nDesiredSampleRate);
  auto result = SteamAPI_ISteamUser_DecompressVoice(instancePtr, pCompressed, cbCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, nDesiredSampleRate);
  TRACE("() = (EVoiceResult )%p\n", result);

  return result;
}


uint32  SteamAPI_ISteamUser_GetVoiceOptimalSampleRate_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUser_GetVoiceOptimalSampleRate(instancePtr);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


HAuthTicket  SteamAPI_ISteamUser_GetAuthSessionTicket_(intptr_t  instancePtr, void * pTicket, int  cbMaxTicket, uint32 * pcbTicket)
{
  TRACE("((intptr_t )%p, (void *)%p, (int )%d, (uint32 *)%d)\n", instancePtr, pTicket, cbMaxTicket, pcbTicket);
  auto result = SteamAPI_ISteamUser_GetAuthSessionTicket(instancePtr, pTicket, cbMaxTicket, pcbTicket);
  TRACE("() = (HAuthTicket )%p\n", result);

  return result;
}


EBeginAuthSessionResult  SteamAPI_ISteamUser_BeginAuthSession_(intptr_t  instancePtr, void * pAuthTicket, int  cbAuthTicket, CSteamID  steamID)
{
  TRACE("((intptr_t )%p, (void *)%p, (int )%d, (CSteamID )%p)\n", instancePtr, pAuthTicket, cbAuthTicket, steamID);
  auto result = SteamAPI_ISteamUser_BeginAuthSession(instancePtr, pAuthTicket, cbAuthTicket, steamID);
  TRACE("() = (EBeginAuthSessionResult )%p\n", result);

  return result;
}


void  SteamAPI_ISteamUser_EndAuthSession_(intptr_t  instancePtr, CSteamID  steamID)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamID);
  SteamAPI_ISteamUser_EndAuthSession(instancePtr, steamID);
  
}


void  SteamAPI_ISteamUser_CancelAuthTicket_(intptr_t  instancePtr, HAuthTicket  hAuthTicket)
{
  TRACE("((intptr_t )%p, (HAuthTicket )%p)\n", instancePtr, hAuthTicket);
  SteamAPI_ISteamUser_CancelAuthTicket(instancePtr, hAuthTicket);
  
}


EUserHasLicenseForAppResult  SteamAPI_ISteamUser_UserHasLicenseForApp_(intptr_t  instancePtr, CSteamID  steamID, AppId_t  appID)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (AppId_t )%p)\n", instancePtr, steamID, appID);
  auto result = SteamAPI_ISteamUser_UserHasLicenseForApp(instancePtr, steamID, appID);
  TRACE("() = (EUserHasLicenseForAppResult )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamUser_BIsBehindNAT_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUser_BIsBehindNAT(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  SteamAPI_ISteamUser_AdvertiseGame_(intptr_t  instancePtr, CSteamID  steamIDGameServer, uint32  unIPServer, uint16  usPortServer)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (uint32 )%d, (uint16 )%d)\n", instancePtr, steamIDGameServer, unIPServer, usPortServer);
  SteamAPI_ISteamUser_AdvertiseGame(instancePtr, steamIDGameServer, unIPServer, usPortServer);
  
}


SteamAPICall_t  SteamAPI_ISteamUser_RequestEncryptedAppTicket_(intptr_t  instancePtr, void * pDataToInclude, int  cbDataToInclude)
{
  TRACE("((intptr_t )%p, (void *)%p, (int )%d)\n", instancePtr, pDataToInclude, cbDataToInclude);
  auto result = SteamAPI_ISteamUser_RequestEncryptedAppTicket(instancePtr, pDataToInclude, cbDataToInclude);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamUser_GetEncryptedAppTicket_(intptr_t  instancePtr, void * pTicket, int  cbMaxTicket, uint32 * pcbTicket)
{
  TRACE("((intptr_t )%p, (void *)%p, (int )%d, (uint32 *)%d)\n", instancePtr, pTicket, cbMaxTicket, pcbTicket);
  auto result = SteamAPI_ISteamUser_GetEncryptedAppTicket(instancePtr, pTicket, cbMaxTicket, pcbTicket);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  SteamAPI_ISteamUser_GetGameBadgeLevel_(intptr_t  instancePtr, int  nSeries, bool  bFoil)
{
  TRACE("((intptr_t )%p, (int )%d, (bool )%d)\n", instancePtr, nSeries, bFoil);
  auto result = SteamAPI_ISteamUser_GetGameBadgeLevel(instancePtr, nSeries, bFoil);
  TRACE("() = (int )%d\n", result);

  return result;
}


int  SteamAPI_ISteamUser_GetPlayerSteamLevel_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUser_GetPlayerSteamLevel(instancePtr);
  TRACE("() = (int )%d\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamUser_RequestStoreAuthURL_(intptr_t  instancePtr, char * pchRedirectURL)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchRedirectURL);
  auto result = SteamAPI_ISteamUser_RequestStoreAuthURL(instancePtr, pchRedirectURL);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


char * SteamAPI_ISteamFriends_GetPersonaName_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamFriends_GetPersonaName(instancePtr);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamFriends_SetPersonaName_(intptr_t  instancePtr, char * pchPersonaName)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchPersonaName);
  auto result = SteamAPI_ISteamFriends_SetPersonaName(instancePtr, pchPersonaName);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


EPersonaState  SteamAPI_ISteamFriends_GetPersonaState_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamFriends_GetPersonaState(instancePtr);
  TRACE("() = (EPersonaState )%p\n", result);

  return result;
}


int  SteamAPI_ISteamFriends_GetFriendCount_(intptr_t  instancePtr, int  iFriendFlags)
{
  TRACE("((intptr_t )%p, (int )%d)\n", instancePtr, iFriendFlags);
  auto result = SteamAPI_ISteamFriends_GetFriendCount(instancePtr, iFriendFlags);
  TRACE("() = (int )%d\n", result);

  return result;
}


uint64  SteamAPI_ISteamFriends_GetFriendByIndex_(intptr_t  instancePtr, int  iFriend, int  iFriendFlags)
{
  TRACE("((intptr_t )%p, (int )%d, (int )%d)\n", instancePtr, iFriend, iFriendFlags);
  auto result = SteamAPI_ISteamFriends_GetFriendByIndex(instancePtr, iFriend, iFriendFlags);
  TRACE("() = (uint64 )%d\n", result);

  return result;
}


EFriendRelationship  SteamAPI_ISteamFriends_GetFriendRelationship_(intptr_t  instancePtr, CSteamID  steamIDFriend)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDFriend);
  auto result = SteamAPI_ISteamFriends_GetFriendRelationship(instancePtr, steamIDFriend);
  TRACE("() = (EFriendRelationship )%p\n", result);

  return result;
}


EPersonaState  SteamAPI_ISteamFriends_GetFriendPersonaState_(intptr_t  instancePtr, CSteamID  steamIDFriend)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDFriend);
  auto result = SteamAPI_ISteamFriends_GetFriendPersonaState(instancePtr, steamIDFriend);
  TRACE("() = (EPersonaState )%p\n", result);

  return result;
}


char * SteamAPI_ISteamFriends_GetFriendPersonaName_(intptr_t  instancePtr, CSteamID  steamIDFriend)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDFriend);
  auto result = SteamAPI_ISteamFriends_GetFriendPersonaName(instancePtr, steamIDFriend);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


bool  SteamAPI_ISteamFriends_GetFriendGamePlayed_(intptr_t  instancePtr, CSteamID  steamIDFriend, FriendGameInfo_t * pFriendGameInfo)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (FriendGameInfo_t *)%p)\n", instancePtr, steamIDFriend, pFriendGameInfo);
  auto result = SteamAPI_ISteamFriends_GetFriendGamePlayed(instancePtr, steamIDFriend, pFriendGameInfo);
  TRACE("() = (bool )%d\n", result);

  return result;
}


char * SteamAPI_ISteamFriends_GetFriendPersonaNameHistory_(intptr_t  instancePtr, CSteamID  steamIDFriend, int  iPersonaName)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (int )%d)\n", instancePtr, steamIDFriend, iPersonaName);
  auto result = SteamAPI_ISteamFriends_GetFriendPersonaNameHistory(instancePtr, steamIDFriend, iPersonaName);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


int  SteamAPI_ISteamFriends_GetFriendSteamLevel_(intptr_t  instancePtr, CSteamID  steamIDFriend)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDFriend);
  auto result = SteamAPI_ISteamFriends_GetFriendSteamLevel(instancePtr, steamIDFriend);
  TRACE("() = (int )%d\n", result);

  return result;
}


char * SteamAPI_ISteamFriends_GetPlayerNickname_(intptr_t  instancePtr, CSteamID  steamIDPlayer)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDPlayer);
  auto result = SteamAPI_ISteamFriends_GetPlayerNickname(instancePtr, steamIDPlayer);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


int  SteamAPI_ISteamFriends_GetFriendsGroupCount_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamFriends_GetFriendsGroupCount(instancePtr);
  TRACE("() = (int )%d\n", result);

  return result;
}


FriendsGroupID_t  SteamAPI_ISteamFriends_GetFriendsGroupIDByIndex_(intptr_t  instancePtr, int  iFG)
{
  TRACE("((intptr_t )%p, (int )%d)\n", instancePtr, iFG);
  auto result = SteamAPI_ISteamFriends_GetFriendsGroupIDByIndex(instancePtr, iFG);
  TRACE("() = (FriendsGroupID_t )%p\n", result);

  return result;
}


char * SteamAPI_ISteamFriends_GetFriendsGroupName_(intptr_t  instancePtr, FriendsGroupID_t  friendsGroupID)
{
  TRACE("((intptr_t )%p, (FriendsGroupID_t )%p)\n", instancePtr, friendsGroupID);
  auto result = SteamAPI_ISteamFriends_GetFriendsGroupName(instancePtr, friendsGroupID);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


int  SteamAPI_ISteamFriends_GetFriendsGroupMembersCount_(intptr_t  instancePtr, FriendsGroupID_t  friendsGroupID)
{
  TRACE("((intptr_t )%p, (FriendsGroupID_t )%p)\n", instancePtr, friendsGroupID);
  auto result = SteamAPI_ISteamFriends_GetFriendsGroupMembersCount(instancePtr, friendsGroupID);
  TRACE("() = (int )%d\n", result);

  return result;
}


void  SteamAPI_ISteamFriends_GetFriendsGroupMembersList_(intptr_t  instancePtr, FriendsGroupID_t  friendsGroupID, CSteamID * pOutSteamIDMembers, int  nMembersCount)
{
  TRACE("((intptr_t )%p, (FriendsGroupID_t )%p, (CSteamID *)%p, (int )%d)\n", instancePtr, friendsGroupID, pOutSteamIDMembers, nMembersCount);
  SteamAPI_ISteamFriends_GetFriendsGroupMembersList(instancePtr, friendsGroupID, pOutSteamIDMembers, nMembersCount);
  
}


bool  SteamAPI_ISteamFriends_HasFriend_(intptr_t  instancePtr, CSteamID  steamIDFriend, int  iFriendFlags)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (int )%d)\n", instancePtr, steamIDFriend, iFriendFlags);
  auto result = SteamAPI_ISteamFriends_HasFriend(instancePtr, steamIDFriend, iFriendFlags);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  SteamAPI_ISteamFriends_GetClanCount_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamFriends_GetClanCount(instancePtr);
  TRACE("() = (int )%d\n", result);

  return result;
}


uint64  SteamAPI_ISteamFriends_GetClanByIndex_(intptr_t  instancePtr, int  iClan)
{
  TRACE("((intptr_t )%p, (int )%d)\n", instancePtr, iClan);
  auto result = SteamAPI_ISteamFriends_GetClanByIndex(instancePtr, iClan);
  TRACE("() = (uint64 )%d\n", result);

  return result;
}


char * SteamAPI_ISteamFriends_GetClanName_(intptr_t  instancePtr, CSteamID  steamIDClan)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDClan);
  auto result = SteamAPI_ISteamFriends_GetClanName(instancePtr, steamIDClan);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


char * SteamAPI_ISteamFriends_GetClanTag_(intptr_t  instancePtr, CSteamID  steamIDClan)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDClan);
  auto result = SteamAPI_ISteamFriends_GetClanTag(instancePtr, steamIDClan);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


bool  SteamAPI_ISteamFriends_GetClanActivityCounts_(intptr_t  instancePtr, CSteamID  steamIDClan, int * pnOnline, int * pnInGame, int * pnChatting)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (int *)%d, (int *)%d, (int *)%d)\n", instancePtr, steamIDClan, pnOnline, pnInGame, pnChatting);
  auto result = SteamAPI_ISteamFriends_GetClanActivityCounts(instancePtr, steamIDClan, pnOnline, pnInGame, pnChatting);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamFriends_DownloadClanActivityCounts_(intptr_t  instancePtr, CSteamID * psteamIDClans, int  cClansToRequest)
{
  TRACE("((intptr_t )%p, (CSteamID *)%p, (int )%d)\n", instancePtr, psteamIDClans, cClansToRequest);
  auto result = SteamAPI_ISteamFriends_DownloadClanActivityCounts(instancePtr, psteamIDClans, cClansToRequest);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


int  SteamAPI_ISteamFriends_GetFriendCountFromSource_(intptr_t  instancePtr, CSteamID  steamIDSource)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDSource);
  auto result = SteamAPI_ISteamFriends_GetFriendCountFromSource(instancePtr, steamIDSource);
  TRACE("() = (int )%d\n", result);

  return result;
}


uint64  SteamAPI_ISteamFriends_GetFriendFromSourceByIndex_(intptr_t  instancePtr, CSteamID  steamIDSource, int  iFriend)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (int )%d)\n", instancePtr, steamIDSource, iFriend);
  auto result = SteamAPI_ISteamFriends_GetFriendFromSourceByIndex(instancePtr, steamIDSource, iFriend);
  TRACE("() = (uint64 )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamFriends_IsUserInSource_(intptr_t  instancePtr, CSteamID  steamIDUser, CSteamID  steamIDSource)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (CSteamID )%p)\n", instancePtr, steamIDUser, steamIDSource);
  auto result = SteamAPI_ISteamFriends_IsUserInSource(instancePtr, steamIDUser, steamIDSource);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  SteamAPI_ISteamFriends_SetInGameVoiceSpeaking_(intptr_t  instancePtr, CSteamID  steamIDUser, bool  bSpeaking)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (bool )%d)\n", instancePtr, steamIDUser, bSpeaking);
  SteamAPI_ISteamFriends_SetInGameVoiceSpeaking(instancePtr, steamIDUser, bSpeaking);
  
}


void  SteamAPI_ISteamFriends_ActivateGameOverlay_(intptr_t  instancePtr, char * pchDialog)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchDialog);
  SteamAPI_ISteamFriends_ActivateGameOverlay(instancePtr, pchDialog);
  
}


void  SteamAPI_ISteamFriends_ActivateGameOverlayToUser_(intptr_t  instancePtr, char * pchDialog, CSteamID  steamID)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (CSteamID )%p)\n", instancePtr, pchDialog, steamID);
  SteamAPI_ISteamFriends_ActivateGameOverlayToUser(instancePtr, pchDialog, steamID);
  
}


void  SteamAPI_ISteamFriends_ActivateGameOverlayToWebPage_(intptr_t  instancePtr, char * pchURL)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchURL);
  SteamAPI_ISteamFriends_ActivateGameOverlayToWebPage(instancePtr, pchURL);
  
}


void  SteamAPI_ISteamFriends_ActivateGameOverlayToStore_(intptr_t  instancePtr, AppId_t  nAppID, EOverlayToStoreFlag  eFlag)
{
  TRACE("((intptr_t )%p, (AppId_t )%p, (EOverlayToStoreFlag )%p)\n", instancePtr, nAppID, eFlag);
  SteamAPI_ISteamFriends_ActivateGameOverlayToStore(instancePtr, nAppID, eFlag);
  
}


void  SteamAPI_ISteamFriends_SetPlayedWith_(intptr_t  instancePtr, CSteamID  steamIDUserPlayedWith)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDUserPlayedWith);
  SteamAPI_ISteamFriends_SetPlayedWith(instancePtr, steamIDUserPlayedWith);
  
}


void  SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialog_(intptr_t  instancePtr, CSteamID  steamIDLobby)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDLobby);
  SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialog(instancePtr, steamIDLobby);
  
}


int  SteamAPI_ISteamFriends_GetSmallFriendAvatar_(intptr_t  instancePtr, CSteamID  steamIDFriend)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDFriend);
  auto result = SteamAPI_ISteamFriends_GetSmallFriendAvatar(instancePtr, steamIDFriend);
  TRACE("() = (int )%d\n", result);

  return result;
}


int  SteamAPI_ISteamFriends_GetMediumFriendAvatar_(intptr_t  instancePtr, CSteamID  steamIDFriend)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDFriend);
  auto result = SteamAPI_ISteamFriends_GetMediumFriendAvatar(instancePtr, steamIDFriend);
  TRACE("() = (int )%d\n", result);

  return result;
}


int  SteamAPI_ISteamFriends_GetLargeFriendAvatar_(intptr_t  instancePtr, CSteamID  steamIDFriend)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDFriend);
  auto result = SteamAPI_ISteamFriends_GetLargeFriendAvatar(instancePtr, steamIDFriend);
  TRACE("() = (int )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamFriends_RequestUserInformation_(intptr_t  instancePtr, CSteamID  steamIDUser, bool  bRequireNameOnly)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (bool )%d)\n", instancePtr, steamIDUser, bRequireNameOnly);
  auto result = SteamAPI_ISteamFriends_RequestUserInformation(instancePtr, steamIDUser, bRequireNameOnly);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamFriends_RequestClanOfficerList_(intptr_t  instancePtr, CSteamID  steamIDClan)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDClan);
  auto result = SteamAPI_ISteamFriends_RequestClanOfficerList(instancePtr, steamIDClan);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


uint64  SteamAPI_ISteamFriends_GetClanOwner_(intptr_t  instancePtr, CSteamID  steamIDClan)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDClan);
  auto result = SteamAPI_ISteamFriends_GetClanOwner(instancePtr, steamIDClan);
  TRACE("() = (uint64 )%d\n", result);

  return result;
}


int  SteamAPI_ISteamFriends_GetClanOfficerCount_(intptr_t  instancePtr, CSteamID  steamIDClan)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDClan);
  auto result = SteamAPI_ISteamFriends_GetClanOfficerCount(instancePtr, steamIDClan);
  TRACE("() = (int )%d\n", result);

  return result;
}


uint64  SteamAPI_ISteamFriends_GetClanOfficerByIndex_(intptr_t  instancePtr, CSteamID  steamIDClan, int  iOfficer)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (int )%d)\n", instancePtr, steamIDClan, iOfficer);
  auto result = SteamAPI_ISteamFriends_GetClanOfficerByIndex(instancePtr, steamIDClan, iOfficer);
  TRACE("() = (uint64 )%d\n", result);

  return result;
}


uint32  SteamAPI_ISteamFriends_GetUserRestrictions_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamFriends_GetUserRestrictions(instancePtr);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamFriends_SetRichPresence_(intptr_t  instancePtr, char * pchKey, char * pchValue)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (char *)\"%s\")\n", instancePtr, pchKey, pchValue);
  auto result = SteamAPI_ISteamFriends_SetRichPresence(instancePtr, pchKey, pchValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  SteamAPI_ISteamFriends_ClearRichPresence_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  SteamAPI_ISteamFriends_ClearRichPresence(instancePtr);
  
}


char * SteamAPI_ISteamFriends_GetFriendRichPresence_(intptr_t  instancePtr, CSteamID  steamIDFriend, char * pchKey)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (char *)\"%s\")\n", instancePtr, steamIDFriend, pchKey);
  auto result = SteamAPI_ISteamFriends_GetFriendRichPresence(instancePtr, steamIDFriend, pchKey);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


int  SteamAPI_ISteamFriends_GetFriendRichPresenceKeyCount_(intptr_t  instancePtr, CSteamID  steamIDFriend)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDFriend);
  auto result = SteamAPI_ISteamFriends_GetFriendRichPresenceKeyCount(instancePtr, steamIDFriend);
  TRACE("() = (int )%d\n", result);

  return result;
}


char * SteamAPI_ISteamFriends_GetFriendRichPresenceKeyByIndex_(intptr_t  instancePtr, CSteamID  steamIDFriend, int  iKey)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (int )%d)\n", instancePtr, steamIDFriend, iKey);
  auto result = SteamAPI_ISteamFriends_GetFriendRichPresenceKeyByIndex(instancePtr, steamIDFriend, iKey);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


void  SteamAPI_ISteamFriends_RequestFriendRichPresence_(intptr_t  instancePtr, CSteamID  steamIDFriend)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDFriend);
  SteamAPI_ISteamFriends_RequestFriendRichPresence(instancePtr, steamIDFriend);
  
}


bool  SteamAPI_ISteamFriends_InviteUserToGame_(intptr_t  instancePtr, CSteamID  steamIDFriend, char * pchConnectString)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (char *)\"%s\")\n", instancePtr, steamIDFriend, pchConnectString);
  auto result = SteamAPI_ISteamFriends_InviteUserToGame(instancePtr, steamIDFriend, pchConnectString);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  SteamAPI_ISteamFriends_GetCoplayFriendCount_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamFriends_GetCoplayFriendCount(instancePtr);
  TRACE("() = (int )%d\n", result);

  return result;
}


uint64  SteamAPI_ISteamFriends_GetCoplayFriend_(intptr_t  instancePtr, int  iCoplayFriend)
{
  TRACE("((intptr_t )%p, (int )%d)\n", instancePtr, iCoplayFriend);
  auto result = SteamAPI_ISteamFriends_GetCoplayFriend(instancePtr, iCoplayFriend);
  TRACE("() = (uint64 )%d\n", result);

  return result;
}


int  SteamAPI_ISteamFriends_GetFriendCoplayTime_(intptr_t  instancePtr, CSteamID  steamIDFriend)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDFriend);
  auto result = SteamAPI_ISteamFriends_GetFriendCoplayTime(instancePtr, steamIDFriend);
  TRACE("() = (int )%d\n", result);

  return result;
}


AppId_t  SteamAPI_ISteamFriends_GetFriendCoplayGame_(intptr_t  instancePtr, CSteamID  steamIDFriend)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDFriend);
  auto result = SteamAPI_ISteamFriends_GetFriendCoplayGame(instancePtr, steamIDFriend);
  TRACE("() = (AppId_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamFriends_JoinClanChatRoom_(intptr_t  instancePtr, CSteamID  steamIDClan)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDClan);
  auto result = SteamAPI_ISteamFriends_JoinClanChatRoom(instancePtr, steamIDClan);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamFriends_LeaveClanChatRoom_(intptr_t  instancePtr, CSteamID  steamIDClan)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDClan);
  auto result = SteamAPI_ISteamFriends_LeaveClanChatRoom(instancePtr, steamIDClan);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  SteamAPI_ISteamFriends_GetClanChatMemberCount_(intptr_t  instancePtr, CSteamID  steamIDClan)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDClan);
  auto result = SteamAPI_ISteamFriends_GetClanChatMemberCount(instancePtr, steamIDClan);
  TRACE("() = (int )%d\n", result);

  return result;
}


uint64  SteamAPI_ISteamFriends_GetChatMemberByIndex_(intptr_t  instancePtr, CSteamID  steamIDClan, int  iUser)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (int )%d)\n", instancePtr, steamIDClan, iUser);
  auto result = SteamAPI_ISteamFriends_GetChatMemberByIndex(instancePtr, steamIDClan, iUser);
  TRACE("() = (uint64 )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamFriends_SendClanChatMessage_(intptr_t  instancePtr, CSteamID  steamIDClanChat, char * pchText)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (char *)\"%s\")\n", instancePtr, steamIDClanChat, pchText);
  auto result = SteamAPI_ISteamFriends_SendClanChatMessage(instancePtr, steamIDClanChat, pchText);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  SteamAPI_ISteamFriends_GetClanChatMessage_(intptr_t  instancePtr, CSteamID  steamIDClanChat, int  iMessage, void * prgchText, int  cchTextMax, EChatEntryType * peChatEntryType, CSteamID * psteamidChatter)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (int )%d, (void *)%p, (int )%d, (EChatEntryType *)%p, (CSteamID *)%p)\n", instancePtr, steamIDClanChat, iMessage, prgchText, cchTextMax, peChatEntryType, psteamidChatter);
  auto result = SteamAPI_ISteamFriends_GetClanChatMessage(instancePtr, steamIDClanChat, iMessage, prgchText, cchTextMax, peChatEntryType, psteamidChatter);
  TRACE("() = (int )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamFriends_IsClanChatAdmin_(intptr_t  instancePtr, CSteamID  steamIDClanChat, CSteamID  steamIDUser)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (CSteamID )%p)\n", instancePtr, steamIDClanChat, steamIDUser);
  auto result = SteamAPI_ISteamFriends_IsClanChatAdmin(instancePtr, steamIDClanChat, steamIDUser);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamFriends_IsClanChatWindowOpenInSteam_(intptr_t  instancePtr, CSteamID  steamIDClanChat)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDClanChat);
  auto result = SteamAPI_ISteamFriends_IsClanChatWindowOpenInSteam(instancePtr, steamIDClanChat);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamFriends_OpenClanChatWindowInSteam_(intptr_t  instancePtr, CSteamID  steamIDClanChat)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDClanChat);
  auto result = SteamAPI_ISteamFriends_OpenClanChatWindowInSteam(instancePtr, steamIDClanChat);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamFriends_CloseClanChatWindowInSteam_(intptr_t  instancePtr, CSteamID  steamIDClanChat)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDClanChat);
  auto result = SteamAPI_ISteamFriends_CloseClanChatWindowInSteam(instancePtr, steamIDClanChat);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamFriends_SetListenForFriendsMessages_(intptr_t  instancePtr, bool  bInterceptEnabled)
{
  TRACE("((intptr_t )%p, (bool )%d)\n", instancePtr, bInterceptEnabled);
  auto result = SteamAPI_ISteamFriends_SetListenForFriendsMessages(instancePtr, bInterceptEnabled);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamFriends_ReplyToFriendMessage_(intptr_t  instancePtr, CSteamID  steamIDFriend, char * pchMsgToSend)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (char *)\"%s\")\n", instancePtr, steamIDFriend, pchMsgToSend);
  auto result = SteamAPI_ISteamFriends_ReplyToFriendMessage(instancePtr, steamIDFriend, pchMsgToSend);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  SteamAPI_ISteamFriends_GetFriendMessage_(intptr_t  instancePtr, CSteamID  steamIDFriend, int  iMessageID, void * pvData, int  cubData, EChatEntryType * peChatEntryType)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (int )%d, (void *)%p, (int )%d, (EChatEntryType *)%p)\n", instancePtr, steamIDFriend, iMessageID, pvData, cubData, peChatEntryType);
  auto result = SteamAPI_ISteamFriends_GetFriendMessage(instancePtr, steamIDFriend, iMessageID, pvData, cubData, peChatEntryType);
  TRACE("() = (int )%d\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamFriends_GetFollowerCount_(intptr_t  instancePtr, CSteamID  steamID)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamID);
  auto result = SteamAPI_ISteamFriends_GetFollowerCount(instancePtr, steamID);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamFriends_IsFollowing_(intptr_t  instancePtr, CSteamID  steamID)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamID);
  auto result = SteamAPI_ISteamFriends_IsFollowing(instancePtr, steamID);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamFriends_EnumerateFollowingList_(intptr_t  instancePtr, uint32  unStartIndex)
{
  TRACE("((intptr_t )%p, (uint32 )%d)\n", instancePtr, unStartIndex);
  auto result = SteamAPI_ISteamFriends_EnumerateFollowingList(instancePtr, unStartIndex);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


uint32  SteamAPI_ISteamUtils_GetSecondsSinceAppActive_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUtils_GetSecondsSinceAppActive(instancePtr);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


uint32  SteamAPI_ISteamUtils_GetSecondsSinceComputerActive_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUtils_GetSecondsSinceComputerActive(instancePtr);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


EUniverse  SteamAPI_ISteamUtils_GetConnectedUniverse_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUtils_GetConnectedUniverse(instancePtr);
  TRACE("() = (EUniverse )%p\n", result);

  return result;
}


uint32  SteamAPI_ISteamUtils_GetServerRealTime_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUtils_GetServerRealTime(instancePtr);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


char * SteamAPI_ISteamUtils_GetIPCountry_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUtils_GetIPCountry(instancePtr);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


bool  SteamAPI_ISteamUtils_GetImageSize_(intptr_t  instancePtr, int  iImage, uint32 * pnWidth, uint32 * pnHeight)
{
  TRACE("((intptr_t )%p, (int )%d, (uint32 *)%d, (uint32 *)%d)\n", instancePtr, iImage, pnWidth, pnHeight);
  auto result = SteamAPI_ISteamUtils_GetImageSize(instancePtr, iImage, pnWidth, pnHeight);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUtils_GetImageRGBA_(intptr_t  instancePtr, int  iImage, uint8 * pubDest, int  nDestBufferSize)
{
  TRACE("((intptr_t )%p, (int )%d, (uint8 *)%p, (int )%d)\n", instancePtr, iImage, pubDest, nDestBufferSize);
  auto result = SteamAPI_ISteamUtils_GetImageRGBA(instancePtr, iImage, pubDest, nDestBufferSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUtils_GetCSERIPPort_(intptr_t  instancePtr, uint32 * unIP, uint16 * usPort)
{
  TRACE("((intptr_t )%p, (uint32 *)%d, (uint16 *)%d)\n", instancePtr, unIP, usPort);
  auto result = SteamAPI_ISteamUtils_GetCSERIPPort(instancePtr, unIP, usPort);
  TRACE("() = (bool )%d\n", result);

  return result;
}


uint8  SteamAPI_ISteamUtils_GetCurrentBatteryPower_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUtils_GetCurrentBatteryPower(instancePtr);
  TRACE("() = (uint8 )%p\n", result);

  return result;
}


uint32  SteamAPI_ISteamUtils_GetAppID_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUtils_GetAppID(instancePtr);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


void  SteamAPI_ISteamUtils_SetOverlayNotificationPosition_(intptr_t  instancePtr, ENotificationPosition  eNotificationPosition)
{
  TRACE("((intptr_t )%p, (ENotificationPosition )%p)\n", instancePtr, eNotificationPosition);
  SteamAPI_ISteamUtils_SetOverlayNotificationPosition(instancePtr, eNotificationPosition);
  
}


bool  SteamAPI_ISteamUtils_IsAPICallCompleted_(intptr_t  instancePtr, SteamAPICall_t  hSteamAPICall, bool * pbFailed)
{
  TRACE("((intptr_t )%p, (SteamAPICall_t )%p, (bool *)%d)\n", instancePtr, hSteamAPICall, pbFailed);
  auto result = SteamAPI_ISteamUtils_IsAPICallCompleted(instancePtr, hSteamAPICall, pbFailed);
  TRACE("() = (bool )%d\n", result);

  return result;
}


ESteamAPICallFailure  SteamAPI_ISteamUtils_GetAPICallFailureReason_(intptr_t  instancePtr, SteamAPICall_t  hSteamAPICall)
{
  TRACE("((intptr_t )%p, (SteamAPICall_t )%p)\n", instancePtr, hSteamAPICall);
  auto result = SteamAPI_ISteamUtils_GetAPICallFailureReason(instancePtr, hSteamAPICall);
  TRACE("() = (ESteamAPICallFailure )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamUtils_GetAPICallResult_(intptr_t  instancePtr, SteamAPICall_t  hSteamAPICall, void * pCallback, int  cubCallback, int  iCallbackExpected, bool * pbFailed)
{
  TRACE("((intptr_t )%p, (SteamAPICall_t )%p, (void *)%p, (int )%d, (int )%d, (bool *)%d)\n", instancePtr, hSteamAPICall, pCallback, cubCallback, iCallbackExpected, pbFailed);
  auto result = SteamAPI_ISteamUtils_GetAPICallResult(instancePtr, hSteamAPICall, pCallback, cubCallback, iCallbackExpected, pbFailed);
  TRACE("() = (bool )%d\n", result);

  return result;
}


uint32  SteamAPI_ISteamUtils_GetIPCCallCount_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUtils_GetIPCCallCount(instancePtr);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


void  SteamAPI_ISteamUtils_SetWarningMessageHook_(intptr_t  instancePtr, SteamAPIWarningMessageHook_t  pFunction)
{
  TRACE("((intptr_t )%p, (SteamAPIWarningMessageHook_t )%p)\n", instancePtr, pFunction);
  SteamAPI_ISteamUtils_SetWarningMessageHook(instancePtr, pFunction);
  
}


bool  SteamAPI_ISteamUtils_IsOverlayEnabled_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUtils_IsOverlayEnabled(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUtils_BOverlayNeedsPresent_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUtils_BOverlayNeedsPresent(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamUtils_CheckFileSignature_(intptr_t  instancePtr, char * szFileName)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, szFileName);
  auto result = SteamAPI_ISteamUtils_CheckFileSignature(instancePtr, szFileName);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamUtils_ShowGamepadTextInput_(intptr_t  instancePtr, EGamepadTextInputMode  eInputMode, EGamepadTextInputLineMode  eLineInputMode, char * pchDescription, uint32  unCharMax, char * pchExistingText)
{
  TRACE("((intptr_t )%p, (EGamepadTextInputMode )%p, (EGamepadTextInputLineMode )%p, (char *)\"%s\", (uint32 )%d, (char *)\"%s\")\n", instancePtr, eInputMode, eLineInputMode, pchDescription, unCharMax, pchExistingText);
  auto result = SteamAPI_ISteamUtils_ShowGamepadTextInput(instancePtr, eInputMode, eLineInputMode, pchDescription, unCharMax, pchExistingText);
  TRACE("() = (bool )%d\n", result);

  return result;
}


uint32  SteamAPI_ISteamUtils_GetEnteredGamepadTextLength_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUtils_GetEnteredGamepadTextLength(instancePtr);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUtils_GetEnteredGamepadTextInput_(intptr_t  instancePtr, char * pchText, uint32  cchText)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (uint32 )%d)\n", instancePtr, pchText, cchText);
  auto result = SteamAPI_ISteamUtils_GetEnteredGamepadTextInput(instancePtr, pchText, cchText);
  TRACE("() = (bool )%d\n", result);

  return result;
}


char * SteamAPI_ISteamUtils_GetSteamUILanguage_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUtils_GetSteamUILanguage(instancePtr);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


bool  SteamAPI_ISteamUtils_IsSteamRunningInVR_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUtils_IsSteamRunningInVR(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  SteamAPI_ISteamMatchmaking_GetFavoriteGameCount_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamMatchmaking_GetFavoriteGameCount(instancePtr);
  TRACE("() = (int )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMatchmaking_GetFavoriteGame_(intptr_t  instancePtr, int  iGame, AppId_t * pnAppID, uint32 * pnIP, uint16 * pnConnPort, uint16 * pnQueryPort, uint32 * punFlags, uint32 * pRTime32LastPlayedOnServer)
{
  TRACE("((intptr_t )%p, (int )%d, (AppId_t *)%p, (uint32 *)%d, (uint16 *)%d, (uint16 *)%d, (uint32 *)%d, (uint32 *)%d)\n", instancePtr, iGame, pnAppID, pnIP, pnConnPort, pnQueryPort, punFlags, pRTime32LastPlayedOnServer);
  auto result = SteamAPI_ISteamMatchmaking_GetFavoriteGame(instancePtr, iGame, pnAppID, pnIP, pnConnPort, pnQueryPort, punFlags, pRTime32LastPlayedOnServer);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  SteamAPI_ISteamMatchmaking_AddFavoriteGame_(intptr_t  instancePtr, AppId_t  nAppID, uint32  nIP, uint16  nConnPort, uint16  nQueryPort, uint32  unFlags, uint32  rTime32LastPlayedOnServer)
{
  TRACE("((intptr_t )%p, (AppId_t )%p, (uint32 )%d, (uint16 )%d, (uint16 )%d, (uint32 )%d, (uint32 )%d)\n", instancePtr, nAppID, nIP, nConnPort, nQueryPort, unFlags, rTime32LastPlayedOnServer);
  auto result = SteamAPI_ISteamMatchmaking_AddFavoriteGame(instancePtr, nAppID, nIP, nConnPort, nQueryPort, unFlags, rTime32LastPlayedOnServer);
  TRACE("() = (int )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMatchmaking_RemoveFavoriteGame_(intptr_t  instancePtr, AppId_t  nAppID, uint32  nIP, uint16  nConnPort, uint16  nQueryPort, uint32  unFlags)
{
  TRACE("((intptr_t )%p, (AppId_t )%p, (uint32 )%d, (uint16 )%d, (uint16 )%d, (uint32 )%d)\n", instancePtr, nAppID, nIP, nConnPort, nQueryPort, unFlags);
  auto result = SteamAPI_ISteamMatchmaking_RemoveFavoriteGame(instancePtr, nAppID, nIP, nConnPort, nQueryPort, unFlags);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamMatchmaking_RequestLobbyList_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamMatchmaking_RequestLobbyList(instancePtr);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


void  SteamAPI_ISteamMatchmaking_AddRequestLobbyListStringFilter_(intptr_t  instancePtr, char * pchKeyToMatch, char * pchValueToMatch, ELobbyComparison  eComparisonType)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (char *)\"%s\", (ELobbyComparison )%p)\n", instancePtr, pchKeyToMatch, pchValueToMatch, eComparisonType);
  SteamAPI_ISteamMatchmaking_AddRequestLobbyListStringFilter(instancePtr, pchKeyToMatch, pchValueToMatch, eComparisonType);
  
}


void  SteamAPI_ISteamMatchmaking_AddRequestLobbyListNumericalFilter_(intptr_t  instancePtr, char * pchKeyToMatch, int  nValueToMatch, ELobbyComparison  eComparisonType)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (int )%d, (ELobbyComparison )%p)\n", instancePtr, pchKeyToMatch, nValueToMatch, eComparisonType);
  SteamAPI_ISteamMatchmaking_AddRequestLobbyListNumericalFilter(instancePtr, pchKeyToMatch, nValueToMatch, eComparisonType);
  
}


void  SteamAPI_ISteamMatchmaking_AddRequestLobbyListNearValueFilter_(intptr_t  instancePtr, char * pchKeyToMatch, int  nValueToBeCloseTo)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (int )%d)\n", instancePtr, pchKeyToMatch, nValueToBeCloseTo);
  SteamAPI_ISteamMatchmaking_AddRequestLobbyListNearValueFilter(instancePtr, pchKeyToMatch, nValueToBeCloseTo);
  
}


void  SteamAPI_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable_(intptr_t  instancePtr, int  nSlotsAvailable)
{
  TRACE("((intptr_t )%p, (int )%d)\n", instancePtr, nSlotsAvailable);
  SteamAPI_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable(instancePtr, nSlotsAvailable);
  
}


void  SteamAPI_ISteamMatchmaking_AddRequestLobbyListDistanceFilter_(intptr_t  instancePtr, ELobbyDistanceFilter  eLobbyDistanceFilter)
{
  TRACE("((intptr_t )%p, (ELobbyDistanceFilter )%p)\n", instancePtr, eLobbyDistanceFilter);
  SteamAPI_ISteamMatchmaking_AddRequestLobbyListDistanceFilter(instancePtr, eLobbyDistanceFilter);
  
}


void  SteamAPI_ISteamMatchmaking_AddRequestLobbyListResultCountFilter_(intptr_t  instancePtr, int  cMaxResults)
{
  TRACE("((intptr_t )%p, (int )%d)\n", instancePtr, cMaxResults);
  SteamAPI_ISteamMatchmaking_AddRequestLobbyListResultCountFilter(instancePtr, cMaxResults);
  
}


void  SteamAPI_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter_(intptr_t  instancePtr, CSteamID  steamIDLobby)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDLobby);
  SteamAPI_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter(instancePtr, steamIDLobby);
  
}


uint64  SteamAPI_ISteamMatchmaking_GetLobbyByIndex_(intptr_t  instancePtr, int  iLobby)
{
  TRACE("((intptr_t )%p, (int )%d)\n", instancePtr, iLobby);
  auto result = SteamAPI_ISteamMatchmaking_GetLobbyByIndex(instancePtr, iLobby);
  TRACE("() = (uint64 )%d\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamMatchmaking_CreateLobby_(intptr_t  instancePtr, ELobbyType  eLobbyType, int  cMaxMembers)
{
  TRACE("((intptr_t )%p, (ELobbyType )%p, (int )%d)\n", instancePtr, eLobbyType, cMaxMembers);
  auto result = SteamAPI_ISteamMatchmaking_CreateLobby(instancePtr, eLobbyType, cMaxMembers);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamMatchmaking_JoinLobby_(intptr_t  instancePtr, CSteamID  steamIDLobby)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDLobby);
  auto result = SteamAPI_ISteamMatchmaking_JoinLobby(instancePtr, steamIDLobby);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


void  SteamAPI_ISteamMatchmaking_LeaveLobby_(intptr_t  instancePtr, CSteamID  steamIDLobby)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDLobby);
  SteamAPI_ISteamMatchmaking_LeaveLobby(instancePtr, steamIDLobby);
  
}


bool  SteamAPI_ISteamMatchmaking_InviteUserToLobby_(intptr_t  instancePtr, CSteamID  steamIDLobby, CSteamID  steamIDInvitee)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (CSteamID )%p)\n", instancePtr, steamIDLobby, steamIDInvitee);
  auto result = SteamAPI_ISteamMatchmaking_InviteUserToLobby(instancePtr, steamIDLobby, steamIDInvitee);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  SteamAPI_ISteamMatchmaking_GetNumLobbyMembers_(intptr_t  instancePtr, CSteamID  steamIDLobby)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDLobby);
  auto result = SteamAPI_ISteamMatchmaking_GetNumLobbyMembers(instancePtr, steamIDLobby);
  TRACE("() = (int )%d\n", result);

  return result;
}


uint64  SteamAPI_ISteamMatchmaking_GetLobbyMemberByIndex_(intptr_t  instancePtr, CSteamID  steamIDLobby, int  iMember)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (int )%d)\n", instancePtr, steamIDLobby, iMember);
  auto result = SteamAPI_ISteamMatchmaking_GetLobbyMemberByIndex(instancePtr, steamIDLobby, iMember);
  TRACE("() = (uint64 )%d\n", result);

  return result;
}


char * SteamAPI_ISteamMatchmaking_GetLobbyData_(intptr_t  instancePtr, CSteamID  steamIDLobby, char * pchKey)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (char *)\"%s\")\n", instancePtr, steamIDLobby, pchKey);
  auto result = SteamAPI_ISteamMatchmaking_GetLobbyData(instancePtr, steamIDLobby, pchKey);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


bool  SteamAPI_ISteamMatchmaking_SetLobbyData_(intptr_t  instancePtr, CSteamID  steamIDLobby, char * pchKey, char * pchValue)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (char *)\"%s\", (char *)\"%s\")\n", instancePtr, steamIDLobby, pchKey, pchValue);
  auto result = SteamAPI_ISteamMatchmaking_SetLobbyData(instancePtr, steamIDLobby, pchKey, pchValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  SteamAPI_ISteamMatchmaking_GetLobbyDataCount_(intptr_t  instancePtr, CSteamID  steamIDLobby)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDLobby);
  auto result = SteamAPI_ISteamMatchmaking_GetLobbyDataCount(instancePtr, steamIDLobby);
  TRACE("() = (int )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMatchmaking_GetLobbyDataByIndex_(intptr_t  instancePtr, CSteamID  steamIDLobby, int  iLobbyData, char * pchKey, int  cchKeyBufferSize, char * pchValue, int  cchValueBufferSize)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (int )%d, (char *)\"%s\", (int )%d, (char *)\"%s\", (int )%d)\n", instancePtr, steamIDLobby, iLobbyData, pchKey, cchKeyBufferSize, pchValue, cchValueBufferSize);
  auto result = SteamAPI_ISteamMatchmaking_GetLobbyDataByIndex(instancePtr, steamIDLobby, iLobbyData, pchKey, cchKeyBufferSize, pchValue, cchValueBufferSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMatchmaking_DeleteLobbyData_(intptr_t  instancePtr, CSteamID  steamIDLobby, char * pchKey)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (char *)\"%s\")\n", instancePtr, steamIDLobby, pchKey);
  auto result = SteamAPI_ISteamMatchmaking_DeleteLobbyData(instancePtr, steamIDLobby, pchKey);
  TRACE("() = (bool )%d\n", result);

  return result;
}


char * SteamAPI_ISteamMatchmaking_GetLobbyMemberData_(intptr_t  instancePtr, CSteamID  steamIDLobby, CSteamID  steamIDUser, char * pchKey)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (CSteamID )%p, (char *)\"%s\")\n", instancePtr, steamIDLobby, steamIDUser, pchKey);
  auto result = SteamAPI_ISteamMatchmaking_GetLobbyMemberData(instancePtr, steamIDLobby, steamIDUser, pchKey);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


void  SteamAPI_ISteamMatchmaking_SetLobbyMemberData_(intptr_t  instancePtr, CSteamID  steamIDLobby, char * pchKey, char * pchValue)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (char *)\"%s\", (char *)\"%s\")\n", instancePtr, steamIDLobby, pchKey, pchValue);
  SteamAPI_ISteamMatchmaking_SetLobbyMemberData(instancePtr, steamIDLobby, pchKey, pchValue);
  
}


bool  SteamAPI_ISteamMatchmaking_SendLobbyChatMsg_(intptr_t  instancePtr, CSteamID  steamIDLobby, void * pvMsgBody, int  cubMsgBody)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (void *)%p, (int )%d)\n", instancePtr, steamIDLobby, pvMsgBody, cubMsgBody);
  auto result = SteamAPI_ISteamMatchmaking_SendLobbyChatMsg(instancePtr, steamIDLobby, pvMsgBody, cubMsgBody);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  SteamAPI_ISteamMatchmaking_GetLobbyChatEntry_(intptr_t  instancePtr, CSteamID  steamIDLobby, int  iChatID, CSteamID * pSteamIDUser, void * pvData, int  cubData, EChatEntryType * peChatEntryType)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (int )%d, (CSteamID *)%p, (void *)%p, (int )%d, (EChatEntryType *)%p)\n", instancePtr, steamIDLobby, iChatID, pSteamIDUser, pvData, cubData, peChatEntryType);
  auto result = SteamAPI_ISteamMatchmaking_GetLobbyChatEntry(instancePtr, steamIDLobby, iChatID, pSteamIDUser, pvData, cubData, peChatEntryType);
  TRACE("() = (int )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMatchmaking_RequestLobbyData_(intptr_t  instancePtr, CSteamID  steamIDLobby)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDLobby);
  auto result = SteamAPI_ISteamMatchmaking_RequestLobbyData(instancePtr, steamIDLobby);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  SteamAPI_ISteamMatchmaking_SetLobbyGameServer_(intptr_t  instancePtr, CSteamID  steamIDLobby, uint32  unGameServerIP, uint16  unGameServerPort, CSteamID  steamIDGameServer)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (uint32 )%d, (uint16 )%d, (CSteamID )%p)\n", instancePtr, steamIDLobby, unGameServerIP, unGameServerPort, steamIDGameServer);
  SteamAPI_ISteamMatchmaking_SetLobbyGameServer(instancePtr, steamIDLobby, unGameServerIP, unGameServerPort, steamIDGameServer);
  
}


bool  SteamAPI_ISteamMatchmaking_GetLobbyGameServer_(intptr_t  instancePtr, CSteamID  steamIDLobby, uint32 * punGameServerIP, uint16 * punGameServerPort, CSteamID * psteamIDGameServer)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (uint32 *)%d, (uint16 *)%d, (CSteamID *)%p)\n", instancePtr, steamIDLobby, punGameServerIP, punGameServerPort, psteamIDGameServer);
  auto result = SteamAPI_ISteamMatchmaking_GetLobbyGameServer(instancePtr, steamIDLobby, punGameServerIP, punGameServerPort, psteamIDGameServer);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMatchmaking_SetLobbyMemberLimit_(intptr_t  instancePtr, CSteamID  steamIDLobby, int  cMaxMembers)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (int )%d)\n", instancePtr, steamIDLobby, cMaxMembers);
  auto result = SteamAPI_ISteamMatchmaking_SetLobbyMemberLimit(instancePtr, steamIDLobby, cMaxMembers);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  SteamAPI_ISteamMatchmaking_GetLobbyMemberLimit_(intptr_t  instancePtr, CSteamID  steamIDLobby)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDLobby);
  auto result = SteamAPI_ISteamMatchmaking_GetLobbyMemberLimit(instancePtr, steamIDLobby);
  TRACE("() = (int )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMatchmaking_SetLobbyType_(intptr_t  instancePtr, CSteamID  steamIDLobby, ELobbyType  eLobbyType)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (ELobbyType )%p)\n", instancePtr, steamIDLobby, eLobbyType);
  auto result = SteamAPI_ISteamMatchmaking_SetLobbyType(instancePtr, steamIDLobby, eLobbyType);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMatchmaking_SetLobbyJoinable_(intptr_t  instancePtr, CSteamID  steamIDLobby, bool  bLobbyJoinable)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (bool )%d)\n", instancePtr, steamIDLobby, bLobbyJoinable);
  auto result = SteamAPI_ISteamMatchmaking_SetLobbyJoinable(instancePtr, steamIDLobby, bLobbyJoinable);
  TRACE("() = (bool )%d\n", result);

  return result;
}


uint64  SteamAPI_ISteamMatchmaking_GetLobbyOwner_(intptr_t  instancePtr, CSteamID  steamIDLobby)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDLobby);
  auto result = SteamAPI_ISteamMatchmaking_GetLobbyOwner(instancePtr, steamIDLobby);
  TRACE("() = (uint64 )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMatchmaking_SetLobbyOwner_(intptr_t  instancePtr, CSteamID  steamIDLobby, CSteamID  steamIDNewOwner)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (CSteamID )%p)\n", instancePtr, steamIDLobby, steamIDNewOwner);
  auto result = SteamAPI_ISteamMatchmaking_SetLobbyOwner(instancePtr, steamIDLobby, steamIDNewOwner);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMatchmaking_SetLinkedLobby_(intptr_t  instancePtr, CSteamID  steamIDLobby, CSteamID  steamIDLobbyDependent)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (CSteamID )%p)\n", instancePtr, steamIDLobby, steamIDLobbyDependent);
  auto result = SteamAPI_ISteamMatchmaking_SetLinkedLobby(instancePtr, steamIDLobby, steamIDLobbyDependent);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  SteamAPI_ISteamMatchmakingServerListResponse_ServerResponded_(intptr_t  instancePtr, HServerListRequest  hRequest, int  iServer)
{
  TRACE("((intptr_t )%p, (HServerListRequest )%p, (int )%d)\n", instancePtr, hRequest, iServer);
  SteamAPI_ISteamMatchmakingServerListResponse_ServerResponded(instancePtr, hRequest, iServer);
  
}


void  SteamAPI_ISteamMatchmakingServerListResponse_ServerFailedToRespond_(intptr_t  instancePtr, HServerListRequest  hRequest, int  iServer)
{
  TRACE("((intptr_t )%p, (HServerListRequest )%p, (int )%d)\n", instancePtr, hRequest, iServer);
  SteamAPI_ISteamMatchmakingServerListResponse_ServerFailedToRespond(instancePtr, hRequest, iServer);
  
}


void  SteamAPI_ISteamMatchmakingServerListResponse_RefreshComplete_(intptr_t  instancePtr, HServerListRequest  hRequest, EMatchMakingServerResponse  response)
{
  TRACE("((intptr_t )%p, (HServerListRequest )%p, (EMatchMakingServerResponse )%p)\n", instancePtr, hRequest, response);
  SteamAPI_ISteamMatchmakingServerListResponse_RefreshComplete(instancePtr, hRequest, response);
  
}


void  SteamAPI_ISteamMatchmakingPingResponse_ServerResponded_(intptr_t  instancePtr, gameserveritem_t & server)
{
  TRACE("((intptr_t )%p, (gameserveritem_t &)%p)\n", instancePtr, server);
  SteamAPI_ISteamMatchmakingPingResponse_ServerResponded(instancePtr, server);
  
}


void  SteamAPI_ISteamMatchmakingPingResponse_ServerFailedToRespond_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  SteamAPI_ISteamMatchmakingPingResponse_ServerFailedToRespond(instancePtr);
  
}


void  SteamAPI_ISteamMatchmakingPlayersResponse_AddPlayerToList_(intptr_t  instancePtr, char * pchName, int  nScore, float  flTimePlayed)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (int )%d, (float )%f)\n", instancePtr, pchName, nScore, flTimePlayed);
  SteamAPI_ISteamMatchmakingPlayersResponse_AddPlayerToList(instancePtr, pchName, nScore, flTimePlayed);
  
}


void  SteamAPI_ISteamMatchmakingPlayersResponse_PlayersFailedToRespond_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  SteamAPI_ISteamMatchmakingPlayersResponse_PlayersFailedToRespond(instancePtr);
  
}


void  SteamAPI_ISteamMatchmakingPlayersResponse_PlayersRefreshComplete_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  SteamAPI_ISteamMatchmakingPlayersResponse_PlayersRefreshComplete(instancePtr);
  
}


void  SteamAPI_ISteamMatchmakingRulesResponse_RulesResponded_(intptr_t  instancePtr, char * pchRule, char * pchValue)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (char *)\"%s\")\n", instancePtr, pchRule, pchValue);
  SteamAPI_ISteamMatchmakingRulesResponse_RulesResponded(instancePtr, pchRule, pchValue);
  
}


void  SteamAPI_ISteamMatchmakingRulesResponse_RulesFailedToRespond_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  SteamAPI_ISteamMatchmakingRulesResponse_RulesFailedToRespond(instancePtr);
  
}


void  SteamAPI_ISteamMatchmakingRulesResponse_RulesRefreshComplete_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  SteamAPI_ISteamMatchmakingRulesResponse_RulesRefreshComplete(instancePtr);
  
}


HServerListRequest  SteamAPI_ISteamMatchmakingServers_RequestInternetServerList_(intptr_t  instancePtr, AppId_t  iApp, MatchMakingKeyValuePair_t ** ppchFilters, uint32  nFilters, ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
  TRACE("((intptr_t )%p, (AppId_t )%p, (MatchMakingKeyValuePair_t **)%p, (uint32 )%d, (ISteamMatchmakingServerListResponse *)%p)\n", instancePtr, iApp, ppchFilters, nFilters, pRequestServersResponse);
  auto result = SteamAPI_ISteamMatchmakingServers_RequestInternetServerList(instancePtr, iApp, ppchFilters, nFilters, pRequestServersResponse);
  TRACE("() = (HServerListRequest )%p\n", result);

  return result;
}


HServerListRequest  SteamAPI_ISteamMatchmakingServers_RequestLANServerList_(intptr_t  instancePtr, AppId_t  iApp, ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
  TRACE("((intptr_t )%p, (AppId_t )%p, (ISteamMatchmakingServerListResponse *)%p)\n", instancePtr, iApp, pRequestServersResponse);
  auto result = SteamAPI_ISteamMatchmakingServers_RequestLANServerList(instancePtr, iApp, pRequestServersResponse);
  TRACE("() = (HServerListRequest )%p\n", result);

  return result;
}


HServerListRequest  SteamAPI_ISteamMatchmakingServers_RequestFriendsServerList_(intptr_t  instancePtr, AppId_t  iApp, MatchMakingKeyValuePair_t ** ppchFilters, uint32  nFilters, ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
  TRACE("((intptr_t )%p, (AppId_t )%p, (MatchMakingKeyValuePair_t **)%p, (uint32 )%d, (ISteamMatchmakingServerListResponse *)%p)\n", instancePtr, iApp, ppchFilters, nFilters, pRequestServersResponse);
  auto result = SteamAPI_ISteamMatchmakingServers_RequestFriendsServerList(instancePtr, iApp, ppchFilters, nFilters, pRequestServersResponse);
  TRACE("() = (HServerListRequest )%p\n", result);

  return result;
}


HServerListRequest  SteamAPI_ISteamMatchmakingServers_RequestFavoritesServerList_(intptr_t  instancePtr, AppId_t  iApp, MatchMakingKeyValuePair_t ** ppchFilters, uint32  nFilters, ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
  TRACE("((intptr_t )%p, (AppId_t )%p, (MatchMakingKeyValuePair_t **)%p, (uint32 )%d, (ISteamMatchmakingServerListResponse *)%p)\n", instancePtr, iApp, ppchFilters, nFilters, pRequestServersResponse);
  auto result = SteamAPI_ISteamMatchmakingServers_RequestFavoritesServerList(instancePtr, iApp, ppchFilters, nFilters, pRequestServersResponse);
  TRACE("() = (HServerListRequest )%p\n", result);

  return result;
}


HServerListRequest  SteamAPI_ISteamMatchmakingServers_RequestHistoryServerList_(intptr_t  instancePtr, AppId_t  iApp, MatchMakingKeyValuePair_t ** ppchFilters, uint32  nFilters, ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
  TRACE("((intptr_t )%p, (AppId_t )%p, (MatchMakingKeyValuePair_t **)%p, (uint32 )%d, (ISteamMatchmakingServerListResponse *)%p)\n", instancePtr, iApp, ppchFilters, nFilters, pRequestServersResponse);
  auto result = SteamAPI_ISteamMatchmakingServers_RequestHistoryServerList(instancePtr, iApp, ppchFilters, nFilters, pRequestServersResponse);
  TRACE("() = (HServerListRequest )%p\n", result);

  return result;
}


HServerListRequest  SteamAPI_ISteamMatchmakingServers_RequestSpectatorServerList_(intptr_t  instancePtr, AppId_t  iApp, MatchMakingKeyValuePair_t ** ppchFilters, uint32  nFilters, ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
  TRACE("((intptr_t )%p, (AppId_t )%p, (MatchMakingKeyValuePair_t **)%p, (uint32 )%d, (ISteamMatchmakingServerListResponse *)%p)\n", instancePtr, iApp, ppchFilters, nFilters, pRequestServersResponse);
  auto result = SteamAPI_ISteamMatchmakingServers_RequestSpectatorServerList(instancePtr, iApp, ppchFilters, nFilters, pRequestServersResponse);
  TRACE("() = (HServerListRequest )%p\n", result);

  return result;
}


void  SteamAPI_ISteamMatchmakingServers_ReleaseRequest_(intptr_t  instancePtr, HServerListRequest  hServerListRequest)
{
  TRACE("((intptr_t )%p, (HServerListRequest )%p)\n", instancePtr, hServerListRequest);
  SteamAPI_ISteamMatchmakingServers_ReleaseRequest(instancePtr, hServerListRequest);
  
}


gameserveritem_t * SteamAPI_ISteamMatchmakingServers_GetServerDetails_(intptr_t  instancePtr, HServerListRequest  hRequest, int  iServer)
{
  TRACE("((intptr_t )%p, (HServerListRequest )%p, (int )%d)\n", instancePtr, hRequest, iServer);
  auto result = SteamAPI_ISteamMatchmakingServers_GetServerDetails(instancePtr, hRequest, iServer);
  TRACE("() = (gameserveritem_t *)%p\n", result);

  return result;
}


void  SteamAPI_ISteamMatchmakingServers_CancelQuery_(intptr_t  instancePtr, HServerListRequest  hRequest)
{
  TRACE("((intptr_t )%p, (HServerListRequest )%p)\n", instancePtr, hRequest);
  SteamAPI_ISteamMatchmakingServers_CancelQuery(instancePtr, hRequest);
  
}


void  SteamAPI_ISteamMatchmakingServers_RefreshQuery_(intptr_t  instancePtr, HServerListRequest  hRequest)
{
  TRACE("((intptr_t )%p, (HServerListRequest )%p)\n", instancePtr, hRequest);
  SteamAPI_ISteamMatchmakingServers_RefreshQuery(instancePtr, hRequest);
  
}


bool  SteamAPI_ISteamMatchmakingServers_IsRefreshing_(intptr_t  instancePtr, HServerListRequest  hRequest)
{
  TRACE("((intptr_t )%p, (HServerListRequest )%p)\n", instancePtr, hRequest);
  auto result = SteamAPI_ISteamMatchmakingServers_IsRefreshing(instancePtr, hRequest);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  SteamAPI_ISteamMatchmakingServers_GetServerCount_(intptr_t  instancePtr, HServerListRequest  hRequest)
{
  TRACE("((intptr_t )%p, (HServerListRequest )%p)\n", instancePtr, hRequest);
  auto result = SteamAPI_ISteamMatchmakingServers_GetServerCount(instancePtr, hRequest);
  TRACE("() = (int )%d\n", result);

  return result;
}


void  SteamAPI_ISteamMatchmakingServers_RefreshServer_(intptr_t  instancePtr, HServerListRequest  hRequest, int  iServer)
{
  TRACE("((intptr_t )%p, (HServerListRequest )%p, (int )%d)\n", instancePtr, hRequest, iServer);
  SteamAPI_ISteamMatchmakingServers_RefreshServer(instancePtr, hRequest, iServer);
  
}


HServerQuery  SteamAPI_ISteamMatchmakingServers_PingServer_(intptr_t  instancePtr, uint32  unIP, uint16  usPort, ISteamMatchmakingPingResponse * pRequestServersResponse)
{
  TRACE("((intptr_t )%p, (uint32 )%d, (uint16 )%d, (ISteamMatchmakingPingResponse *)%p)\n", instancePtr, unIP, usPort, pRequestServersResponse);
  auto result = SteamAPI_ISteamMatchmakingServers_PingServer(instancePtr, unIP, usPort, pRequestServersResponse);
  TRACE("() = (HServerQuery )%p\n", result);

  return result;
}


HServerQuery  SteamAPI_ISteamMatchmakingServers_PlayerDetails_(intptr_t  instancePtr, uint32  unIP, uint16  usPort, ISteamMatchmakingPlayersResponse * pRequestServersResponse)
{
  TRACE("((intptr_t )%p, (uint32 )%d, (uint16 )%d, (ISteamMatchmakingPlayersResponse *)%p)\n", instancePtr, unIP, usPort, pRequestServersResponse);
  auto result = SteamAPI_ISteamMatchmakingServers_PlayerDetails(instancePtr, unIP, usPort, pRequestServersResponse);
  TRACE("() = (HServerQuery )%p\n", result);

  return result;
}


HServerQuery  SteamAPI_ISteamMatchmakingServers_ServerRules_(intptr_t  instancePtr, uint32  unIP, uint16  usPort, ISteamMatchmakingRulesResponse * pRequestServersResponse)
{
  TRACE("((intptr_t )%p, (uint32 )%d, (uint16 )%d, (ISteamMatchmakingRulesResponse *)%p)\n", instancePtr, unIP, usPort, pRequestServersResponse);
  auto result = SteamAPI_ISteamMatchmakingServers_ServerRules(instancePtr, unIP, usPort, pRequestServersResponse);
  TRACE("() = (HServerQuery )%p\n", result);

  return result;
}


void  SteamAPI_ISteamMatchmakingServers_CancelServerQuery_(intptr_t  instancePtr, HServerQuery  hServerQuery)
{
  TRACE("((intptr_t )%p, (HServerQuery )%p)\n", instancePtr, hServerQuery);
  SteamAPI_ISteamMatchmakingServers_CancelServerQuery(instancePtr, hServerQuery);
  
}


bool  SteamAPI_ISteamRemoteStorage_FileWrite_(intptr_t  instancePtr, char * pchFile, void * pvData, int32  cubData)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (void *)%p, (int32 )%d)\n", instancePtr, pchFile, pvData, cubData);
  auto result = SteamAPI_ISteamRemoteStorage_FileWrite(instancePtr, pchFile, pvData, cubData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int32  SteamAPI_ISteamRemoteStorage_FileRead_(intptr_t  instancePtr, char * pchFile, void * pvData, int32  cubDataToRead)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (void *)%p, (int32 )%d)\n", instancePtr, pchFile, pvData, cubDataToRead);
  auto result = SteamAPI_ISteamRemoteStorage_FileRead(instancePtr, pchFile, pvData, cubDataToRead);
  TRACE("() = (int32 )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamRemoteStorage_FileForget_(intptr_t  instancePtr, char * pchFile)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchFile);
  auto result = SteamAPI_ISteamRemoteStorage_FileForget(instancePtr, pchFile);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamRemoteStorage_FileDelete_(intptr_t  instancePtr, char * pchFile)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchFile);
  auto result = SteamAPI_ISteamRemoteStorage_FileDelete(instancePtr, pchFile);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamRemoteStorage_FileShare_(intptr_t  instancePtr, char * pchFile)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchFile);
  auto result = SteamAPI_ISteamRemoteStorage_FileShare(instancePtr, pchFile);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamRemoteStorage_SetSyncPlatforms_(intptr_t  instancePtr, char * pchFile, ERemoteStoragePlatform  eRemoteStoragePlatform)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (ERemoteStoragePlatform )%p)\n", instancePtr, pchFile, eRemoteStoragePlatform);
  auto result = SteamAPI_ISteamRemoteStorage_SetSyncPlatforms(instancePtr, pchFile, eRemoteStoragePlatform);
  TRACE("() = (bool )%d\n", result);

  return result;
}


UGCFileWriteStreamHandle_t  SteamAPI_ISteamRemoteStorage_FileWriteStreamOpen_(intptr_t  instancePtr, char * pchFile)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchFile);
  auto result = SteamAPI_ISteamRemoteStorage_FileWriteStreamOpen(instancePtr, pchFile);
  TRACE("() = (UGCFileWriteStreamHandle_t )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamRemoteStorage_FileWriteStreamWriteChunk_(intptr_t  instancePtr, UGCFileWriteStreamHandle_t  writeHandle, void * pvData, int32  cubData)
{
  TRACE("((intptr_t )%p, (UGCFileWriteStreamHandle_t )%p, (void *)%p, (int32 )%d)\n", instancePtr, writeHandle, pvData, cubData);
  auto result = SteamAPI_ISteamRemoteStorage_FileWriteStreamWriteChunk(instancePtr, writeHandle, pvData, cubData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamRemoteStorage_FileWriteStreamClose_(intptr_t  instancePtr, UGCFileWriteStreamHandle_t  writeHandle)
{
  TRACE("((intptr_t )%p, (UGCFileWriteStreamHandle_t )%p)\n", instancePtr, writeHandle);
  auto result = SteamAPI_ISteamRemoteStorage_FileWriteStreamClose(instancePtr, writeHandle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamRemoteStorage_FileWriteStreamCancel_(intptr_t  instancePtr, UGCFileWriteStreamHandle_t  writeHandle)
{
  TRACE("((intptr_t )%p, (UGCFileWriteStreamHandle_t )%p)\n", instancePtr, writeHandle);
  auto result = SteamAPI_ISteamRemoteStorage_FileWriteStreamCancel(instancePtr, writeHandle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamRemoteStorage_FileExists_(intptr_t  instancePtr, char * pchFile)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchFile);
  auto result = SteamAPI_ISteamRemoteStorage_FileExists(instancePtr, pchFile);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamRemoteStorage_FilePersisted_(intptr_t  instancePtr, char * pchFile)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchFile);
  auto result = SteamAPI_ISteamRemoteStorage_FilePersisted(instancePtr, pchFile);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int32  SteamAPI_ISteamRemoteStorage_GetFileSize_(intptr_t  instancePtr, char * pchFile)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchFile);
  auto result = SteamAPI_ISteamRemoteStorage_GetFileSize(instancePtr, pchFile);
  TRACE("() = (int32 )%d\n", result);

  return result;
}


int64  SteamAPI_ISteamRemoteStorage_GetFileTimestamp_(intptr_t  instancePtr, char * pchFile)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchFile);
  auto result = SteamAPI_ISteamRemoteStorage_GetFileTimestamp(instancePtr, pchFile);
  TRACE("() = (int64 )%d\n", result);

  return result;
}


ERemoteStoragePlatform  SteamAPI_ISteamRemoteStorage_GetSyncPlatforms_(intptr_t  instancePtr, char * pchFile)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchFile);
  auto result = SteamAPI_ISteamRemoteStorage_GetSyncPlatforms(instancePtr, pchFile);
  TRACE("() = (ERemoteStoragePlatform )%p\n", result);

  return result;
}


int32  SteamAPI_ISteamRemoteStorage_GetFileCount_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamRemoteStorage_GetFileCount(instancePtr);
  TRACE("() = (int32 )%d\n", result);

  return result;
}


char * SteamAPI_ISteamRemoteStorage_GetFileNameAndSize_(intptr_t  instancePtr, int  iFile, int32 * pnFileSizeInBytes)
{
  TRACE("((intptr_t )%p, (int )%d, (int32 *)%d)\n", instancePtr, iFile, pnFileSizeInBytes);
  auto result = SteamAPI_ISteamRemoteStorage_GetFileNameAndSize(instancePtr, iFile, pnFileSizeInBytes);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


bool  SteamAPI_ISteamRemoteStorage_GetQuota_(intptr_t  instancePtr, uint64 * pnTotalBytes, uint64 * puAvailableBytes)
{
  TRACE("((intptr_t )%p, (uint64 *)%d, (uint64 *)%d)\n", instancePtr, pnTotalBytes, puAvailableBytes);
  auto result = SteamAPI_ISteamRemoteStorage_GetQuota(instancePtr, pnTotalBytes, puAvailableBytes);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamRemoteStorage_IsCloudEnabledForAccount_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamRemoteStorage_IsCloudEnabledForAccount(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamRemoteStorage_IsCloudEnabledForApp_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamRemoteStorage_IsCloudEnabledForApp(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  SteamAPI_ISteamRemoteStorage_SetCloudEnabledForApp_(intptr_t  instancePtr, bool  bEnabled)
{
  TRACE("((intptr_t )%p, (bool )%d)\n", instancePtr, bEnabled);
  SteamAPI_ISteamRemoteStorage_SetCloudEnabledForApp(instancePtr, bEnabled);
  
}


SteamAPICall_t  SteamAPI_ISteamRemoteStorage_UGCDownload_(intptr_t  instancePtr, UGCHandle_t  hContent, uint32  unPriority)
{
  TRACE("((intptr_t )%p, (UGCHandle_t )%p, (uint32 )%d)\n", instancePtr, hContent, unPriority);
  auto result = SteamAPI_ISteamRemoteStorage_UGCDownload(instancePtr, hContent, unPriority);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamRemoteStorage_GetUGCDownloadProgress_(intptr_t  instancePtr, UGCHandle_t  hContent, int32 * pnBytesDownloaded, int32 * pnBytesExpected)
{
  TRACE("((intptr_t )%p, (UGCHandle_t )%p, (int32 *)%d, (int32 *)%d)\n", instancePtr, hContent, pnBytesDownloaded, pnBytesExpected);
  auto result = SteamAPI_ISteamRemoteStorage_GetUGCDownloadProgress(instancePtr, hContent, pnBytesDownloaded, pnBytesExpected);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamRemoteStorage_GetUGCDetails_(intptr_t  instancePtr, UGCHandle_t  hContent, AppId_t * pnAppID, char ** ppchName, int32 * pnFileSizeInBytes, CSteamID * pSteamIDOwner)
{
  TRACE("((intptr_t )%p, (UGCHandle_t )%p, (AppId_t *)%p, (char **)\"%s\", (int32 *)%d, (CSteamID *)%p)\n", instancePtr, hContent, pnAppID, ppchName, pnFileSizeInBytes, pSteamIDOwner);
  auto result = SteamAPI_ISteamRemoteStorage_GetUGCDetails(instancePtr, hContent, pnAppID, ppchName, pnFileSizeInBytes, pSteamIDOwner);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int32  SteamAPI_ISteamRemoteStorage_UGCRead_(intptr_t  instancePtr, UGCHandle_t  hContent, void * pvData, int32  cubDataToRead, uint32  cOffset, EUGCReadAction  eAction)
{
  TRACE("((intptr_t )%p, (UGCHandle_t )%p, (void *)%p, (int32 )%d, (uint32 )%d, (EUGCReadAction )%p)\n", instancePtr, hContent, pvData, cubDataToRead, cOffset, eAction);
  auto result = SteamAPI_ISteamRemoteStorage_UGCRead(instancePtr, hContent, pvData, cubDataToRead, cOffset, eAction);
  TRACE("() = (int32 )%d\n", result);

  return result;
}


int32  SteamAPI_ISteamRemoteStorage_GetCachedUGCCount_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamRemoteStorage_GetCachedUGCCount(instancePtr);
  TRACE("() = (int32 )%d\n", result);

  return result;
}


UGCHandle_t  SteamAPI_ISteamRemoteStorage_GetCachedUGCHandle_(intptr_t  instancePtr, int32  iCachedContent)
{
  TRACE("((intptr_t )%p, (int32 )%d)\n", instancePtr, iCachedContent);
  auto result = SteamAPI_ISteamRemoteStorage_GetCachedUGCHandle(instancePtr, iCachedContent);
  TRACE("() = (UGCHandle_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamRemoteStorage_PublishWorkshopFile_(intptr_t  instancePtr, char * pchFile, char * pchPreviewFile, AppId_t  nConsumerAppId, char * pchTitle, char * pchDescription, ERemoteStoragePublishedFileVisibility  eVisibility, SteamParamStringArray_t * pTags, EWorkshopFileType  eWorkshopFileType)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (char *)\"%s\", (AppId_t )%p, (char *)\"%s\", (char *)\"%s\", (ERemoteStoragePublishedFileVisibility )%p, (SteamParamStringArray_t *)%p, (EWorkshopFileType )%p)\n", instancePtr, pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, pTags, eWorkshopFileType);
  auto result = SteamAPI_ISteamRemoteStorage_PublishWorkshopFile(instancePtr, pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, pTags, eWorkshopFileType);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


PublishedFileUpdateHandle_t  SteamAPI_ISteamRemoteStorage_CreatePublishedFileUpdateRequest_(intptr_t  instancePtr, PublishedFileId_t  unPublishedFileId)
{
  TRACE("((intptr_t )%p, (PublishedFileId_t )%p)\n", instancePtr, unPublishedFileId);
  auto result = SteamAPI_ISteamRemoteStorage_CreatePublishedFileUpdateRequest(instancePtr, unPublishedFileId);
  TRACE("() = (PublishedFileUpdateHandle_t )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamRemoteStorage_UpdatePublishedFileFile_(intptr_t  instancePtr, PublishedFileUpdateHandle_t  updateHandle, char * pchFile)
{
  TRACE("((intptr_t )%p, (PublishedFileUpdateHandle_t )%p, (char *)\"%s\")\n", instancePtr, updateHandle, pchFile);
  auto result = SteamAPI_ISteamRemoteStorage_UpdatePublishedFileFile(instancePtr, updateHandle, pchFile);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamRemoteStorage_UpdatePublishedFilePreviewFile_(intptr_t  instancePtr, PublishedFileUpdateHandle_t  updateHandle, char * pchPreviewFile)
{
  TRACE("((intptr_t )%p, (PublishedFileUpdateHandle_t )%p, (char *)\"%s\")\n", instancePtr, updateHandle, pchPreviewFile);
  auto result = SteamAPI_ISteamRemoteStorage_UpdatePublishedFilePreviewFile(instancePtr, updateHandle, pchPreviewFile);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTitle_(intptr_t  instancePtr, PublishedFileUpdateHandle_t  updateHandle, char * pchTitle)
{
  TRACE("((intptr_t )%p, (PublishedFileUpdateHandle_t )%p, (char *)\"%s\")\n", instancePtr, updateHandle, pchTitle);
  auto result = SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTitle(instancePtr, updateHandle, pchTitle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamRemoteStorage_UpdatePublishedFileDescription_(intptr_t  instancePtr, PublishedFileUpdateHandle_t  updateHandle, char * pchDescription)
{
  TRACE("((intptr_t )%p, (PublishedFileUpdateHandle_t )%p, (char *)\"%s\")\n", instancePtr, updateHandle, pchDescription);
  auto result = SteamAPI_ISteamRemoteStorage_UpdatePublishedFileDescription(instancePtr, updateHandle, pchDescription);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamRemoteStorage_UpdatePublishedFileVisibility_(intptr_t  instancePtr, PublishedFileUpdateHandle_t  updateHandle, ERemoteStoragePublishedFileVisibility  eVisibility)
{
  TRACE("((intptr_t )%p, (PublishedFileUpdateHandle_t )%p, (ERemoteStoragePublishedFileVisibility )%p)\n", instancePtr, updateHandle, eVisibility);
  auto result = SteamAPI_ISteamRemoteStorage_UpdatePublishedFileVisibility(instancePtr, updateHandle, eVisibility);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTags_(intptr_t  instancePtr, PublishedFileUpdateHandle_t  updateHandle, SteamParamStringArray_t * pTags)
{
  TRACE("((intptr_t )%p, (PublishedFileUpdateHandle_t )%p, (SteamParamStringArray_t *)%p)\n", instancePtr, updateHandle, pTags);
  auto result = SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTags(instancePtr, updateHandle, pTags);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamRemoteStorage_CommitPublishedFileUpdate_(intptr_t  instancePtr, PublishedFileUpdateHandle_t  updateHandle)
{
  TRACE("((intptr_t )%p, (PublishedFileUpdateHandle_t )%p)\n", instancePtr, updateHandle);
  auto result = SteamAPI_ISteamRemoteStorage_CommitPublishedFileUpdate(instancePtr, updateHandle);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamRemoteStorage_GetPublishedFileDetails_(intptr_t  instancePtr, PublishedFileId_t  unPublishedFileId, uint32  unMaxSecondsOld)
{
  TRACE("((intptr_t )%p, (PublishedFileId_t )%p, (uint32 )%d)\n", instancePtr, unPublishedFileId, unMaxSecondsOld);
  auto result = SteamAPI_ISteamRemoteStorage_GetPublishedFileDetails(instancePtr, unPublishedFileId, unMaxSecondsOld);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamRemoteStorage_DeletePublishedFile_(intptr_t  instancePtr, PublishedFileId_t  unPublishedFileId)
{
  TRACE("((intptr_t )%p, (PublishedFileId_t )%p)\n", instancePtr, unPublishedFileId);
  auto result = SteamAPI_ISteamRemoteStorage_DeletePublishedFile(instancePtr, unPublishedFileId);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamRemoteStorage_EnumerateUserPublishedFiles_(intptr_t  instancePtr, uint32  unStartIndex)
{
  TRACE("((intptr_t )%p, (uint32 )%d)\n", instancePtr, unStartIndex);
  auto result = SteamAPI_ISteamRemoteStorage_EnumerateUserPublishedFiles(instancePtr, unStartIndex);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamRemoteStorage_SubscribePublishedFile_(intptr_t  instancePtr, PublishedFileId_t  unPublishedFileId)
{
  TRACE("((intptr_t )%p, (PublishedFileId_t )%p)\n", instancePtr, unPublishedFileId);
  auto result = SteamAPI_ISteamRemoteStorage_SubscribePublishedFile(instancePtr, unPublishedFileId);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamRemoteStorage_EnumerateUserSubscribedFiles_(intptr_t  instancePtr, uint32  unStartIndex)
{
  TRACE("((intptr_t )%p, (uint32 )%d)\n", instancePtr, unStartIndex);
  auto result = SteamAPI_ISteamRemoteStorage_EnumerateUserSubscribedFiles(instancePtr, unStartIndex);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamRemoteStorage_UnsubscribePublishedFile_(intptr_t  instancePtr, PublishedFileId_t  unPublishedFileId)
{
  TRACE("((intptr_t )%p, (PublishedFileId_t )%p)\n", instancePtr, unPublishedFileId);
  auto result = SteamAPI_ISteamRemoteStorage_UnsubscribePublishedFile(instancePtr, unPublishedFileId);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamRemoteStorage_UpdatePublishedFileSetChangeDescription_(intptr_t  instancePtr, PublishedFileUpdateHandle_t  updateHandle, char * pchChangeDescription)
{
  TRACE("((intptr_t )%p, (PublishedFileUpdateHandle_t )%p, (char *)\"%s\")\n", instancePtr, updateHandle, pchChangeDescription);
  auto result = SteamAPI_ISteamRemoteStorage_UpdatePublishedFileSetChangeDescription(instancePtr, updateHandle, pchChangeDescription);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamRemoteStorage_GetPublishedItemVoteDetails_(intptr_t  instancePtr, PublishedFileId_t  unPublishedFileId)
{
  TRACE("((intptr_t )%p, (PublishedFileId_t )%p)\n", instancePtr, unPublishedFileId);
  auto result = SteamAPI_ISteamRemoteStorage_GetPublishedItemVoteDetails(instancePtr, unPublishedFileId);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamRemoteStorage_UpdateUserPublishedItemVote_(intptr_t  instancePtr, PublishedFileId_t  unPublishedFileId, bool  bVoteUp)
{
  TRACE("((intptr_t )%p, (PublishedFileId_t )%p, (bool )%d)\n", instancePtr, unPublishedFileId, bVoteUp);
  auto result = SteamAPI_ISteamRemoteStorage_UpdateUserPublishedItemVote(instancePtr, unPublishedFileId, bVoteUp);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamRemoteStorage_GetUserPublishedItemVoteDetails_(intptr_t  instancePtr, PublishedFileId_t  unPublishedFileId)
{
  TRACE("((intptr_t )%p, (PublishedFileId_t )%p)\n", instancePtr, unPublishedFileId);
  auto result = SteamAPI_ISteamRemoteStorage_GetUserPublishedItemVoteDetails(instancePtr, unPublishedFileId);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamRemoteStorage_EnumerateUserSharedWorkshopFiles_(intptr_t  instancePtr, CSteamID  steamId, uint32  unStartIndex, SteamParamStringArray_t * pRequiredTags, SteamParamStringArray_t * pExcludedTags)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (uint32 )%d, (SteamParamStringArray_t *)%p, (SteamParamStringArray_t *)%p)\n", instancePtr, steamId, unStartIndex, pRequiredTags, pExcludedTags);
  auto result = SteamAPI_ISteamRemoteStorage_EnumerateUserSharedWorkshopFiles(instancePtr, steamId, unStartIndex, pRequiredTags, pExcludedTags);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamRemoteStorage_PublishVideo_(intptr_t  instancePtr, EWorkshopVideoProvider  eVideoProvider, char * pchVideoAccount, char * pchVideoIdentifier, char * pchPreviewFile, AppId_t  nConsumerAppId, char * pchTitle, char * pchDescription, ERemoteStoragePublishedFileVisibility  eVisibility, SteamParamStringArray_t * pTags)
{
  TRACE("((intptr_t )%p, (EWorkshopVideoProvider )%p, (char *)\"%s\", (char *)\"%s\", (char *)\"%s\", (AppId_t )%p, (char *)\"%s\", (char *)\"%s\", (ERemoteStoragePublishedFileVisibility )%p, (SteamParamStringArray_t *)%p)\n", instancePtr, eVideoProvider, pchVideoAccount, pchVideoIdentifier, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, pTags);
  auto result = SteamAPI_ISteamRemoteStorage_PublishVideo(instancePtr, eVideoProvider, pchVideoAccount, pchVideoIdentifier, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, pTags);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamRemoteStorage_SetUserPublishedFileAction_(intptr_t  instancePtr, PublishedFileId_t  unPublishedFileId, EWorkshopFileAction  eAction)
{
  TRACE("((intptr_t )%p, (PublishedFileId_t )%p, (EWorkshopFileAction )%p)\n", instancePtr, unPublishedFileId, eAction);
  auto result = SteamAPI_ISteamRemoteStorage_SetUserPublishedFileAction(instancePtr, unPublishedFileId, eAction);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamRemoteStorage_EnumeratePublishedFilesByUserAction_(intptr_t  instancePtr, EWorkshopFileAction  eAction, uint32  unStartIndex)
{
  TRACE("((intptr_t )%p, (EWorkshopFileAction )%p, (uint32 )%d)\n", instancePtr, eAction, unStartIndex);
  auto result = SteamAPI_ISteamRemoteStorage_EnumeratePublishedFilesByUserAction(instancePtr, eAction, unStartIndex);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamRemoteStorage_EnumeratePublishedWorkshopFiles_(intptr_t  instancePtr, EWorkshopEnumerationType  eEnumerationType, uint32  unStartIndex, uint32  unCount, uint32  unDays, SteamParamStringArray_t * pTags, SteamParamStringArray_t * pUserTags)
{
  TRACE("((intptr_t )%p, (EWorkshopEnumerationType )%p, (uint32 )%d, (uint32 )%d, (uint32 )%d, (SteamParamStringArray_t *)%p, (SteamParamStringArray_t *)%p)\n", instancePtr, eEnumerationType, unStartIndex, unCount, unDays, pTags, pUserTags);
  auto result = SteamAPI_ISteamRemoteStorage_EnumeratePublishedWorkshopFiles(instancePtr, eEnumerationType, unStartIndex, unCount, unDays, pTags, pUserTags);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamRemoteStorage_UGCDownloadToLocation_(intptr_t  instancePtr, UGCHandle_t  hContent, char * pchLocation, uint32  unPriority)
{
  TRACE("((intptr_t )%p, (UGCHandle_t )%p, (char *)\"%s\", (uint32 )%d)\n", instancePtr, hContent, pchLocation, unPriority);
  auto result = SteamAPI_ISteamRemoteStorage_UGCDownloadToLocation(instancePtr, hContent, pchLocation, unPriority);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamUserStats_RequestCurrentStats_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUserStats_RequestCurrentStats(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUserStats_GetStat_(intptr_t  instancePtr, char * pchName, int32 * pData)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (int32 *)%d)\n", instancePtr, pchName, pData);
  auto result = SteamAPI_ISteamUserStats_GetStat(instancePtr, pchName, pData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUserStats_GetStat0_(intptr_t  instancePtr, char * pchName, float * pData)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (float *)%f)\n", instancePtr, pchName, pData);
  auto result = SteamAPI_ISteamUserStats_GetStat0(instancePtr, pchName, pData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUserStats_SetStat_(intptr_t  instancePtr, char * pchName, int32  nData)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (int32 )%d)\n", instancePtr, pchName, nData);
  auto result = SteamAPI_ISteamUserStats_SetStat(instancePtr, pchName, nData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUserStats_SetStat0_(intptr_t  instancePtr, char * pchName, float  fData)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (float )%f)\n", instancePtr, pchName, fData);
  auto result = SteamAPI_ISteamUserStats_SetStat0(instancePtr, pchName, fData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUserStats_UpdateAvgRateStat_(intptr_t  instancePtr, char * pchName, float  flCountThisSession, double  dSessionLength)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (float )%f, (double )%f)\n", instancePtr, pchName, flCountThisSession, dSessionLength);
  auto result = SteamAPI_ISteamUserStats_UpdateAvgRateStat(instancePtr, pchName, flCountThisSession, dSessionLength);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUserStats_GetAchievement_(intptr_t  instancePtr, char * pchName, bool * pbAchieved)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (bool *)%d)\n", instancePtr, pchName, pbAchieved);
  auto result = SteamAPI_ISteamUserStats_GetAchievement(instancePtr, pchName, pbAchieved);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUserStats_SetAchievement_(intptr_t  instancePtr, char * pchName)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchName);
  auto result = SteamAPI_ISteamUserStats_SetAchievement(instancePtr, pchName);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUserStats_ClearAchievement_(intptr_t  instancePtr, char * pchName)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchName);
  auto result = SteamAPI_ISteamUserStats_ClearAchievement(instancePtr, pchName);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUserStats_GetAchievementAndUnlockTime_(intptr_t  instancePtr, char * pchName, bool * pbAchieved, uint32 * punUnlockTime)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (bool *)%d, (uint32 *)%d)\n", instancePtr, pchName, pbAchieved, punUnlockTime);
  auto result = SteamAPI_ISteamUserStats_GetAchievementAndUnlockTime(instancePtr, pchName, pbAchieved, punUnlockTime);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUserStats_StoreStats_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUserStats_StoreStats(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  SteamAPI_ISteamUserStats_GetAchievementIcon_(intptr_t  instancePtr, char * pchName)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchName);
  auto result = SteamAPI_ISteamUserStats_GetAchievementIcon(instancePtr, pchName);
  TRACE("() = (int )%d\n", result);

  return result;
}


char * SteamAPI_ISteamUserStats_GetAchievementDisplayAttribute_(intptr_t  instancePtr, char * pchName, char * pchKey)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (char *)\"%s\")\n", instancePtr, pchName, pchKey);
  auto result = SteamAPI_ISteamUserStats_GetAchievementDisplayAttribute(instancePtr, pchName, pchKey);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


bool  SteamAPI_ISteamUserStats_IndicateAchievementProgress_(intptr_t  instancePtr, char * pchName, uint32  nCurProgress, uint32  nMaxProgress)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (uint32 )%d, (uint32 )%d)\n", instancePtr, pchName, nCurProgress, nMaxProgress);
  auto result = SteamAPI_ISteamUserStats_IndicateAchievementProgress(instancePtr, pchName, nCurProgress, nMaxProgress);
  TRACE("() = (bool )%d\n", result);

  return result;
}


uint32  SteamAPI_ISteamUserStats_GetNumAchievements_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUserStats_GetNumAchievements(instancePtr);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


char * SteamAPI_ISteamUserStats_GetAchievementName_(intptr_t  instancePtr, uint32  iAchievement)
{
  TRACE("((intptr_t )%p, (uint32 )%d)\n", instancePtr, iAchievement);
  auto result = SteamAPI_ISteamUserStats_GetAchievementName(instancePtr, iAchievement);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamUserStats_RequestUserStats_(intptr_t  instancePtr, CSteamID  steamIDUser)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDUser);
  auto result = SteamAPI_ISteamUserStats_RequestUserStats(instancePtr, steamIDUser);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamUserStats_GetUserStat_(intptr_t  instancePtr, CSteamID  steamIDUser, char * pchName, int32 * pData)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (char *)\"%s\", (int32 *)%d)\n", instancePtr, steamIDUser, pchName, pData);
  auto result = SteamAPI_ISteamUserStats_GetUserStat(instancePtr, steamIDUser, pchName, pData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUserStats_GetUserStat0_(intptr_t  instancePtr, CSteamID  steamIDUser, char * pchName, float * pData)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (char *)\"%s\", (float *)%f)\n", instancePtr, steamIDUser, pchName, pData);
  auto result = SteamAPI_ISteamUserStats_GetUserStat0(instancePtr, steamIDUser, pchName, pData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUserStats_GetUserAchievement_(intptr_t  instancePtr, CSteamID  steamIDUser, char * pchName, bool * pbAchieved)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (char *)\"%s\", (bool *)%d)\n", instancePtr, steamIDUser, pchName, pbAchieved);
  auto result = SteamAPI_ISteamUserStats_GetUserAchievement(instancePtr, steamIDUser, pchName, pbAchieved);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUserStats_GetUserAchievementAndUnlockTime_(intptr_t  instancePtr, CSteamID  steamIDUser, char * pchName, bool * pbAchieved, uint32 * punUnlockTime)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (char *)\"%s\", (bool *)%d, (uint32 *)%d)\n", instancePtr, steamIDUser, pchName, pbAchieved, punUnlockTime);
  auto result = SteamAPI_ISteamUserStats_GetUserAchievementAndUnlockTime(instancePtr, steamIDUser, pchName, pbAchieved, punUnlockTime);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUserStats_ResetAllStats_(intptr_t  instancePtr, bool  bAchievementsToo)
{
  TRACE("((intptr_t )%p, (bool )%d)\n", instancePtr, bAchievementsToo);
  auto result = SteamAPI_ISteamUserStats_ResetAllStats(instancePtr, bAchievementsToo);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamUserStats_FindOrCreateLeaderboard_(intptr_t  instancePtr, char * pchLeaderboardName, ELeaderboardSortMethod  eLeaderboardSortMethod, ELeaderboardDisplayType  eLeaderboardDisplayType)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (ELeaderboardSortMethod )%p, (ELeaderboardDisplayType )%p)\n", instancePtr, pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType);
  auto result = SteamAPI_ISteamUserStats_FindOrCreateLeaderboard(instancePtr, pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamUserStats_FindLeaderboard_(intptr_t  instancePtr, char * pchLeaderboardName)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchLeaderboardName);
  auto result = SteamAPI_ISteamUserStats_FindLeaderboard(instancePtr, pchLeaderboardName);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


char * SteamAPI_ISteamUserStats_GetLeaderboardName_(intptr_t  instancePtr, SteamLeaderboard_t  hSteamLeaderboard)
{
  TRACE("((intptr_t )%p, (SteamLeaderboard_t )%p)\n", instancePtr, hSteamLeaderboard);
  auto result = SteamAPI_ISteamUserStats_GetLeaderboardName(instancePtr, hSteamLeaderboard);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


int  SteamAPI_ISteamUserStats_GetLeaderboardEntryCount_(intptr_t  instancePtr, SteamLeaderboard_t  hSteamLeaderboard)
{
  TRACE("((intptr_t )%p, (SteamLeaderboard_t )%p)\n", instancePtr, hSteamLeaderboard);
  auto result = SteamAPI_ISteamUserStats_GetLeaderboardEntryCount(instancePtr, hSteamLeaderboard);
  TRACE("() = (int )%d\n", result);

  return result;
}


ELeaderboardSortMethod  SteamAPI_ISteamUserStats_GetLeaderboardSortMethod_(intptr_t  instancePtr, SteamLeaderboard_t  hSteamLeaderboard)
{
  TRACE("((intptr_t )%p, (SteamLeaderboard_t )%p)\n", instancePtr, hSteamLeaderboard);
  auto result = SteamAPI_ISteamUserStats_GetLeaderboardSortMethod(instancePtr, hSteamLeaderboard);
  TRACE("() = (ELeaderboardSortMethod )%p\n", result);

  return result;
}


ELeaderboardDisplayType  SteamAPI_ISteamUserStats_GetLeaderboardDisplayType_(intptr_t  instancePtr, SteamLeaderboard_t  hSteamLeaderboard)
{
  TRACE("((intptr_t )%p, (SteamLeaderboard_t )%p)\n", instancePtr, hSteamLeaderboard);
  auto result = SteamAPI_ISteamUserStats_GetLeaderboardDisplayType(instancePtr, hSteamLeaderboard);
  TRACE("() = (ELeaderboardDisplayType )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamUserStats_DownloadLeaderboardEntries_(intptr_t  instancePtr, SteamLeaderboard_t  hSteamLeaderboard, ELeaderboardDataRequest  eLeaderboardDataRequest, int  nRangeStart, int  nRangeEnd)
{
  TRACE("((intptr_t )%p, (SteamLeaderboard_t )%p, (ELeaderboardDataRequest )%p, (int )%d, (int )%d)\n", instancePtr, hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd);
  auto result = SteamAPI_ISteamUserStats_DownloadLeaderboardEntries(instancePtr, hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamUserStats_DownloadLeaderboardEntriesForUsers_(intptr_t  instancePtr, SteamLeaderboard_t  hSteamLeaderboard, CSteamID * prgUsers, int  cUsers)
{
  TRACE("((intptr_t )%p, (SteamLeaderboard_t )%p, (CSteamID *)%p, (int )%d)\n", instancePtr, hSteamLeaderboard, prgUsers, cUsers);
  auto result = SteamAPI_ISteamUserStats_DownloadLeaderboardEntriesForUsers(instancePtr, hSteamLeaderboard, prgUsers, cUsers);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamUserStats_GetDownloadedLeaderboardEntry_(intptr_t  instancePtr, SteamLeaderboardEntries_t  hSteamLeaderboardEntries, int  index, LeaderboardEntry_t * pLeaderboardEntry, int32 * pDetails, int  cDetailsMax)
{
  TRACE("((intptr_t )%p, (SteamLeaderboardEntries_t )%p, (int )%d, (LeaderboardEntry_t *)%p, (int32 *)%d, (int )%d)\n", instancePtr, hSteamLeaderboardEntries, index, pLeaderboardEntry, pDetails, cDetailsMax);
  auto result = SteamAPI_ISteamUserStats_GetDownloadedLeaderboardEntry(instancePtr, hSteamLeaderboardEntries, index, pLeaderboardEntry, pDetails, cDetailsMax);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamUserStats_UploadLeaderboardScore_(intptr_t  instancePtr, SteamLeaderboard_t  hSteamLeaderboard, ELeaderboardUploadScoreMethod  eLeaderboardUploadScoreMethod, int32  nScore, int32 * pScoreDetails, int  cScoreDetailsCount)
{
  TRACE("((intptr_t )%p, (SteamLeaderboard_t )%p, (ELeaderboardUploadScoreMethod )%p, (int32 )%d, (int32 *)%d, (int )%d)\n", instancePtr, hSteamLeaderboard, eLeaderboardUploadScoreMethod, nScore, pScoreDetails, cScoreDetailsCount);
  auto result = SteamAPI_ISteamUserStats_UploadLeaderboardScore(instancePtr, hSteamLeaderboard, eLeaderboardUploadScoreMethod, nScore, pScoreDetails, cScoreDetailsCount);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamUserStats_AttachLeaderboardUGC_(intptr_t  instancePtr, SteamLeaderboard_t  hSteamLeaderboard, UGCHandle_t  hUGC)
{
  TRACE("((intptr_t )%p, (SteamLeaderboard_t )%p, (UGCHandle_t )%p)\n", instancePtr, hSteamLeaderboard, hUGC);
  auto result = SteamAPI_ISteamUserStats_AttachLeaderboardUGC(instancePtr, hSteamLeaderboard, hUGC);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamUserStats_GetNumberOfCurrentPlayers_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUserStats_GetNumberOfCurrentPlayers(instancePtr);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamUserStats_RequestGlobalAchievementPercentages_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUserStats_RequestGlobalAchievementPercentages(instancePtr);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


int  SteamAPI_ISteamUserStats_GetMostAchievedAchievementInfo_(intptr_t  instancePtr, char * pchName, uint32  unNameBufLen, float * pflPercent, bool * pbAchieved)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (uint32 )%d, (float *)%f, (bool *)%d)\n", instancePtr, pchName, unNameBufLen, pflPercent, pbAchieved);
  auto result = SteamAPI_ISteamUserStats_GetMostAchievedAchievementInfo(instancePtr, pchName, unNameBufLen, pflPercent, pbAchieved);
  TRACE("() = (int )%d\n", result);

  return result;
}


int  SteamAPI_ISteamUserStats_GetNextMostAchievedAchievementInfo_(intptr_t  instancePtr, int  iIteratorPrevious, char * pchName, uint32  unNameBufLen, float * pflPercent, bool * pbAchieved)
{
  TRACE("((intptr_t )%p, (int )%d, (char *)\"%s\", (uint32 )%d, (float *)%f, (bool *)%d)\n", instancePtr, iIteratorPrevious, pchName, unNameBufLen, pflPercent, pbAchieved);
  auto result = SteamAPI_ISteamUserStats_GetNextMostAchievedAchievementInfo(instancePtr, iIteratorPrevious, pchName, unNameBufLen, pflPercent, pbAchieved);
  TRACE("() = (int )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUserStats_GetAchievementAchievedPercent_(intptr_t  instancePtr, char * pchName, float * pflPercent)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (float *)%f)\n", instancePtr, pchName, pflPercent);
  auto result = SteamAPI_ISteamUserStats_GetAchievementAchievedPercent(instancePtr, pchName, pflPercent);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamUserStats_RequestGlobalStats_(intptr_t  instancePtr, int  nHistoryDays)
{
  TRACE("((intptr_t )%p, (int )%d)\n", instancePtr, nHistoryDays);
  auto result = SteamAPI_ISteamUserStats_RequestGlobalStats(instancePtr, nHistoryDays);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamUserStats_GetGlobalStat_(intptr_t  instancePtr, char * pchStatName, int64 * pData)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (int64 *)%d)\n", instancePtr, pchStatName, pData);
  auto result = SteamAPI_ISteamUserStats_GetGlobalStat(instancePtr, pchStatName, pData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUserStats_GetGlobalStat0_(intptr_t  instancePtr, char * pchStatName, double * pData)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (double *)%f)\n", instancePtr, pchStatName, pData);
  auto result = SteamAPI_ISteamUserStats_GetGlobalStat0(instancePtr, pchStatName, pData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int32  SteamAPI_ISteamUserStats_GetGlobalStatHistory_(intptr_t  instancePtr, char * pchStatName, int64 * pData, uint32  cubData)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (int64 *)%d, (uint32 )%d)\n", instancePtr, pchStatName, pData, cubData);
  auto result = SteamAPI_ISteamUserStats_GetGlobalStatHistory(instancePtr, pchStatName, pData, cubData);
  TRACE("() = (int32 )%d\n", result);

  return result;
}


int32  SteamAPI_ISteamUserStats_GetGlobalStatHistory0_(intptr_t  instancePtr, char * pchStatName, double * pData, uint32  cubData)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (double *)%f, (uint32 )%d)\n", instancePtr, pchStatName, pData, cubData);
  auto result = SteamAPI_ISteamUserStats_GetGlobalStatHistory0(instancePtr, pchStatName, pData, cubData);
  TRACE("() = (int32 )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamApps_BIsSubscribed_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamApps_BIsSubscribed(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamApps_BIsLowViolence_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamApps_BIsLowViolence(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamApps_BIsCybercafe_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamApps_BIsCybercafe(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamApps_BIsVACBanned_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamApps_BIsVACBanned(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


char * SteamAPI_ISteamApps_GetCurrentGameLanguage_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamApps_GetCurrentGameLanguage(instancePtr);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


char * SteamAPI_ISteamApps_GetAvailableGameLanguages_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamApps_GetAvailableGameLanguages(instancePtr);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


bool  SteamAPI_ISteamApps_BIsSubscribedApp_(intptr_t  instancePtr, AppId_t  appID)
{
  TRACE("((intptr_t )%p, (AppId_t )%p)\n", instancePtr, appID);
  auto result = SteamAPI_ISteamApps_BIsSubscribedApp(instancePtr, appID);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamApps_BIsDlcInstalled_(intptr_t  instancePtr, AppId_t  appID)
{
  TRACE("((intptr_t )%p, (AppId_t )%p)\n", instancePtr, appID);
  auto result = SteamAPI_ISteamApps_BIsDlcInstalled(instancePtr, appID);
  TRACE("() = (bool )%d\n", result);

  return result;
}


uint32  SteamAPI_ISteamApps_GetEarliestPurchaseUnixTime_(intptr_t  instancePtr, AppId_t  nAppID)
{
  TRACE("((intptr_t )%p, (AppId_t )%p)\n", instancePtr, nAppID);
  auto result = SteamAPI_ISteamApps_GetEarliestPurchaseUnixTime(instancePtr, nAppID);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamApps_BIsSubscribedFromFreeWeekend_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamApps_BIsSubscribedFromFreeWeekend(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  SteamAPI_ISteamApps_GetDLCCount_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamApps_GetDLCCount(instancePtr);
  TRACE("() = (int )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamApps_BGetDLCDataByIndex_(intptr_t  instancePtr, int  iDLC, AppId_t * pAppID, bool * pbAvailable, char * pchName, int  cchNameBufferSize)
{
  TRACE("((intptr_t )%p, (int )%d, (AppId_t *)%p, (bool *)%d, (char *)\"%s\", (int )%d)\n", instancePtr, iDLC, pAppID, pbAvailable, pchName, cchNameBufferSize);
  auto result = SteamAPI_ISteamApps_BGetDLCDataByIndex(instancePtr, iDLC, pAppID, pbAvailable, pchName, cchNameBufferSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  SteamAPI_ISteamApps_InstallDLC_(intptr_t  instancePtr, AppId_t  nAppID)
{
  TRACE("((intptr_t )%p, (AppId_t )%p)\n", instancePtr, nAppID);
  SteamAPI_ISteamApps_InstallDLC(instancePtr, nAppID);
  
}


void  SteamAPI_ISteamApps_UninstallDLC_(intptr_t  instancePtr, AppId_t  nAppID)
{
  TRACE("((intptr_t )%p, (AppId_t )%p)\n", instancePtr, nAppID);
  SteamAPI_ISteamApps_UninstallDLC(instancePtr, nAppID);
  
}


void  SteamAPI_ISteamApps_RequestAppProofOfPurchaseKey_(intptr_t  instancePtr, AppId_t  nAppID)
{
  TRACE("((intptr_t )%p, (AppId_t )%p)\n", instancePtr, nAppID);
  SteamAPI_ISteamApps_RequestAppProofOfPurchaseKey(instancePtr, nAppID);
  
}


bool  SteamAPI_ISteamApps_GetCurrentBetaName_(intptr_t  instancePtr, char * pchName, int  cchNameBufferSize)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (int )%d)\n", instancePtr, pchName, cchNameBufferSize);
  auto result = SteamAPI_ISteamApps_GetCurrentBetaName(instancePtr, pchName, cchNameBufferSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamApps_MarkContentCorrupt_(intptr_t  instancePtr, bool  bMissingFilesOnly)
{
  TRACE("((intptr_t )%p, (bool )%d)\n", instancePtr, bMissingFilesOnly);
  auto result = SteamAPI_ISteamApps_MarkContentCorrupt(instancePtr, bMissingFilesOnly);
  TRACE("() = (bool )%d\n", result);

  return result;
}


uint32  SteamAPI_ISteamApps_GetInstalledDepots_(intptr_t  instancePtr, AppId_t  appID, DepotId_t * pvecDepots, uint32  cMaxDepots)
{
  TRACE("((intptr_t )%p, (AppId_t )%p, (DepotId_t *)%p, (uint32 )%d)\n", instancePtr, appID, pvecDepots, cMaxDepots);
  auto result = SteamAPI_ISteamApps_GetInstalledDepots(instancePtr, appID, pvecDepots, cMaxDepots);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


uint32  SteamAPI_ISteamApps_GetAppInstallDir_(intptr_t  instancePtr, AppId_t  appID, char * pchFolder, uint32  cchFolderBufferSize)
{
  TRACE("((intptr_t )%p, (AppId_t )%p, (char *)\"%s\", (uint32 )%d)\n", instancePtr, appID, pchFolder, cchFolderBufferSize);
  auto result = SteamAPI_ISteamApps_GetAppInstallDir(instancePtr, appID, pchFolder, cchFolderBufferSize);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamApps_BIsAppInstalled_(intptr_t  instancePtr, AppId_t  appID)
{
  TRACE("((intptr_t )%p, (AppId_t )%p)\n", instancePtr, appID);
  auto result = SteamAPI_ISteamApps_BIsAppInstalled(instancePtr, appID);
  TRACE("() = (bool )%d\n", result);

  return result;
}


uint64  SteamAPI_ISteamApps_GetAppOwner_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamApps_GetAppOwner(instancePtr);
  TRACE("() = (uint64 )%d\n", result);

  return result;
}


char * SteamAPI_ISteamApps_GetLaunchQueryParam_(intptr_t  instancePtr, char * pchKey)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchKey);
  auto result = SteamAPI_ISteamApps_GetLaunchQueryParam(instancePtr, pchKey);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


bool  SteamAPI_ISteamApps_GetDlcDownloadProgress_(intptr_t  instancePtr, AppId_t  nAppID, uint64 * punBytesDownloaded, uint64 * punBytesTotal)
{
  TRACE("((intptr_t )%p, (AppId_t )%p, (uint64 *)%d, (uint64 *)%d)\n", instancePtr, nAppID, punBytesDownloaded, punBytesTotal);
  auto result = SteamAPI_ISteamApps_GetDlcDownloadProgress(instancePtr, nAppID, punBytesDownloaded, punBytesTotal);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  SteamAPI_ISteamApps_GetAppBuildId_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamApps_GetAppBuildId(instancePtr);
  TRACE("() = (int )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamNetworking_SendP2PPacket_(intptr_t  instancePtr, CSteamID  steamIDRemote, void * pubData, uint32  cubData, EP2PSend  eP2PSendType, int  nChannel)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (void *)%p, (uint32 )%d, (EP2PSend )%p, (int )%d)\n", instancePtr, steamIDRemote, pubData, cubData, eP2PSendType, nChannel);
  auto result = SteamAPI_ISteamNetworking_SendP2PPacket(instancePtr, steamIDRemote, pubData, cubData, eP2PSendType, nChannel);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamNetworking_IsP2PPacketAvailable_(intptr_t  instancePtr, uint32 * pcubMsgSize, int  nChannel)
{
  TRACE("((intptr_t )%p, (uint32 *)%d, (int )%d)\n", instancePtr, pcubMsgSize, nChannel);
  auto result = SteamAPI_ISteamNetworking_IsP2PPacketAvailable(instancePtr, pcubMsgSize, nChannel);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamNetworking_ReadP2PPacket_(intptr_t  instancePtr, void * pubDest, uint32  cubDest, uint32 * pcubMsgSize, CSteamID * psteamIDRemote, int  nChannel)
{
  TRACE("((intptr_t )%p, (void *)%p, (uint32 )%d, (uint32 *)%d, (CSteamID *)%p, (int )%d)\n", instancePtr, pubDest, cubDest, pcubMsgSize, psteamIDRemote, nChannel);
  auto result = SteamAPI_ISteamNetworking_ReadP2PPacket(instancePtr, pubDest, cubDest, pcubMsgSize, psteamIDRemote, nChannel);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamNetworking_AcceptP2PSessionWithUser_(intptr_t  instancePtr, CSteamID  steamIDRemote)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDRemote);
  auto result = SteamAPI_ISteamNetworking_AcceptP2PSessionWithUser(instancePtr, steamIDRemote);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamNetworking_CloseP2PSessionWithUser_(intptr_t  instancePtr, CSteamID  steamIDRemote)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDRemote);
  auto result = SteamAPI_ISteamNetworking_CloseP2PSessionWithUser(instancePtr, steamIDRemote);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamNetworking_CloseP2PChannelWithUser_(intptr_t  instancePtr, CSteamID  steamIDRemote, int  nChannel)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (int )%d)\n", instancePtr, steamIDRemote, nChannel);
  auto result = SteamAPI_ISteamNetworking_CloseP2PChannelWithUser(instancePtr, steamIDRemote, nChannel);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamNetworking_GetP2PSessionState_(intptr_t  instancePtr, CSteamID  steamIDRemote, P2PSessionState_t * pConnectionState)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (P2PSessionState_t *)%p)\n", instancePtr, steamIDRemote, pConnectionState);
  auto result = SteamAPI_ISteamNetworking_GetP2PSessionState(instancePtr, steamIDRemote, pConnectionState);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamNetworking_AllowP2PPacketRelay_(intptr_t  instancePtr, bool  bAllow)
{
  TRACE("((intptr_t )%p, (bool )%d)\n", instancePtr, bAllow);
  auto result = SteamAPI_ISteamNetworking_AllowP2PPacketRelay(instancePtr, bAllow);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SNetListenSocket_t  SteamAPI_ISteamNetworking_CreateListenSocket_(intptr_t  instancePtr, int  nVirtualP2PPort, uint32  nIP, uint16  nPort, bool  bAllowUseOfPacketRelay)
{
  TRACE("((intptr_t )%p, (int )%d, (uint32 )%d, (uint16 )%d, (bool )%d)\n", instancePtr, nVirtualP2PPort, nIP, nPort, bAllowUseOfPacketRelay);
  auto result = SteamAPI_ISteamNetworking_CreateListenSocket(instancePtr, nVirtualP2PPort, nIP, nPort, bAllowUseOfPacketRelay);
  TRACE("() = (SNetListenSocket_t )%p\n", result);

  return result;
}


SNetSocket_t  SteamAPI_ISteamNetworking_CreateP2PConnectionSocket_(intptr_t  instancePtr, CSteamID  steamIDTarget, int  nVirtualPort, int  nTimeoutSec, bool  bAllowUseOfPacketRelay)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (int )%d, (int )%d, (bool )%d)\n", instancePtr, steamIDTarget, nVirtualPort, nTimeoutSec, bAllowUseOfPacketRelay);
  auto result = SteamAPI_ISteamNetworking_CreateP2PConnectionSocket(instancePtr, steamIDTarget, nVirtualPort, nTimeoutSec, bAllowUseOfPacketRelay);
  TRACE("() = (SNetSocket_t )%p\n", result);

  return result;
}


SNetSocket_t  SteamAPI_ISteamNetworking_CreateConnectionSocket_(intptr_t  instancePtr, uint32  nIP, uint16  nPort, int  nTimeoutSec)
{
  TRACE("((intptr_t )%p, (uint32 )%d, (uint16 )%d, (int )%d)\n", instancePtr, nIP, nPort, nTimeoutSec);
  auto result = SteamAPI_ISteamNetworking_CreateConnectionSocket(instancePtr, nIP, nPort, nTimeoutSec);
  TRACE("() = (SNetSocket_t )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamNetworking_DestroySocket_(intptr_t  instancePtr, SNetSocket_t  hSocket, bool  bNotifyRemoteEnd)
{
  TRACE("((intptr_t )%p, (SNetSocket_t )%p, (bool )%d)\n", instancePtr, hSocket, bNotifyRemoteEnd);
  auto result = SteamAPI_ISteamNetworking_DestroySocket(instancePtr, hSocket, bNotifyRemoteEnd);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamNetworking_DestroyListenSocket_(intptr_t  instancePtr, SNetListenSocket_t  hSocket, bool  bNotifyRemoteEnd)
{
  TRACE("((intptr_t )%p, (SNetListenSocket_t )%p, (bool )%d)\n", instancePtr, hSocket, bNotifyRemoteEnd);
  auto result = SteamAPI_ISteamNetworking_DestroyListenSocket(instancePtr, hSocket, bNotifyRemoteEnd);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamNetworking_SendDataOnSocket_(intptr_t  instancePtr, SNetSocket_t  hSocket, void * pubData, uint32  cubData, bool  bReliable)
{
  TRACE("((intptr_t )%p, (SNetSocket_t )%p, (void *)%p, (uint32 )%d, (bool )%d)\n", instancePtr, hSocket, pubData, cubData, bReliable);
  auto result = SteamAPI_ISteamNetworking_SendDataOnSocket(instancePtr, hSocket, pubData, cubData, bReliable);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamNetworking_IsDataAvailableOnSocket_(intptr_t  instancePtr, SNetSocket_t  hSocket, uint32 * pcubMsgSize)
{
  TRACE("((intptr_t )%p, (SNetSocket_t )%p, (uint32 *)%d)\n", instancePtr, hSocket, pcubMsgSize);
  auto result = SteamAPI_ISteamNetworking_IsDataAvailableOnSocket(instancePtr, hSocket, pcubMsgSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamNetworking_RetrieveDataFromSocket_(intptr_t  instancePtr, SNetSocket_t  hSocket, void * pubDest, uint32  cubDest, uint32 * pcubMsgSize)
{
  TRACE("((intptr_t )%p, (SNetSocket_t )%p, (void *)%p, (uint32 )%d, (uint32 *)%d)\n", instancePtr, hSocket, pubDest, cubDest, pcubMsgSize);
  auto result = SteamAPI_ISteamNetworking_RetrieveDataFromSocket(instancePtr, hSocket, pubDest, cubDest, pcubMsgSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamNetworking_IsDataAvailable_(intptr_t  instancePtr, SNetListenSocket_t  hListenSocket, uint32 * pcubMsgSize, SNetSocket_t * phSocket)
{
  TRACE("((intptr_t )%p, (SNetListenSocket_t )%p, (uint32 *)%d, (SNetSocket_t *)%p)\n", instancePtr, hListenSocket, pcubMsgSize, phSocket);
  auto result = SteamAPI_ISteamNetworking_IsDataAvailable(instancePtr, hListenSocket, pcubMsgSize, phSocket);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamNetworking_RetrieveData_(intptr_t  instancePtr, SNetListenSocket_t  hListenSocket, void * pubDest, uint32  cubDest, uint32 * pcubMsgSize, SNetSocket_t * phSocket)
{
  TRACE("((intptr_t )%p, (SNetListenSocket_t )%p, (void *)%p, (uint32 )%d, (uint32 *)%d, (SNetSocket_t *)%p)\n", instancePtr, hListenSocket, pubDest, cubDest, pcubMsgSize, phSocket);
  auto result = SteamAPI_ISteamNetworking_RetrieveData(instancePtr, hListenSocket, pubDest, cubDest, pcubMsgSize, phSocket);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamNetworking_GetSocketInfo_(intptr_t  instancePtr, SNetSocket_t  hSocket, CSteamID * pSteamIDRemote, int * peSocketStatus, uint32 * punIPRemote, uint16 * punPortRemote)
{
  TRACE("((intptr_t )%p, (SNetSocket_t )%p, (CSteamID *)%p, (int *)%d, (uint32 *)%d, (uint16 *)%d)\n", instancePtr, hSocket, pSteamIDRemote, peSocketStatus, punIPRemote, punPortRemote);
  auto result = SteamAPI_ISteamNetworking_GetSocketInfo(instancePtr, hSocket, pSteamIDRemote, peSocketStatus, punIPRemote, punPortRemote);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamNetworking_GetListenSocketInfo_(intptr_t  instancePtr, SNetListenSocket_t  hListenSocket, uint32 * pnIP, uint16 * pnPort)
{
  TRACE("((intptr_t )%p, (SNetListenSocket_t )%p, (uint32 *)%d, (uint16 *)%d)\n", instancePtr, hListenSocket, pnIP, pnPort);
  auto result = SteamAPI_ISteamNetworking_GetListenSocketInfo(instancePtr, hListenSocket, pnIP, pnPort);
  TRACE("() = (bool )%d\n", result);

  return result;
}


ESNetSocketConnectionType  SteamAPI_ISteamNetworking_GetSocketConnectionType_(intptr_t  instancePtr, SNetSocket_t  hSocket)
{
  TRACE("((intptr_t )%p, (SNetSocket_t )%p)\n", instancePtr, hSocket);
  auto result = SteamAPI_ISteamNetworking_GetSocketConnectionType(instancePtr, hSocket);
  TRACE("() = (ESNetSocketConnectionType )%p\n", result);

  return result;
}


int  SteamAPI_ISteamNetworking_GetMaxPacketSize_(intptr_t  instancePtr, SNetSocket_t  hSocket)
{
  TRACE("((intptr_t )%p, (SNetSocket_t )%p)\n", instancePtr, hSocket);
  auto result = SteamAPI_ISteamNetworking_GetMaxPacketSize(instancePtr, hSocket);
  TRACE("() = (int )%d\n", result);

  return result;
}


ScreenshotHandle  SteamAPI_ISteamScreenshots_WriteScreenshot_(intptr_t  instancePtr, void * pubRGB, uint32  cubRGB, int  nWidth, int  nHeight)
{
  TRACE("((intptr_t )%p, (void *)%p, (uint32 )%d, (int )%d, (int )%d)\n", instancePtr, pubRGB, cubRGB, nWidth, nHeight);
  auto result = SteamAPI_ISteamScreenshots_WriteScreenshot(instancePtr, pubRGB, cubRGB, nWidth, nHeight);
  TRACE("() = (ScreenshotHandle )%p\n", result);

  return result;
}


ScreenshotHandle  SteamAPI_ISteamScreenshots_AddScreenshotToLibrary_(intptr_t  instancePtr, char * pchFilename, char * pchThumbnailFilename, int  nWidth, int  nHeight)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (char *)\"%s\", (int )%d, (int )%d)\n", instancePtr, pchFilename, pchThumbnailFilename, nWidth, nHeight);
  auto result = SteamAPI_ISteamScreenshots_AddScreenshotToLibrary(instancePtr, pchFilename, pchThumbnailFilename, nWidth, nHeight);
  TRACE("() = (ScreenshotHandle )%p\n", result);

  return result;
}


void  SteamAPI_ISteamScreenshots_TriggerScreenshot_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  SteamAPI_ISteamScreenshots_TriggerScreenshot(instancePtr);
  
}


void  SteamAPI_ISteamScreenshots_HookScreenshots_(intptr_t  instancePtr, bool  bHook)
{
  TRACE("((intptr_t )%p, (bool )%d)\n", instancePtr, bHook);
  SteamAPI_ISteamScreenshots_HookScreenshots(instancePtr, bHook);
  
}


bool  SteamAPI_ISteamScreenshots_SetLocation_(intptr_t  instancePtr, ScreenshotHandle  hScreenshot, char * pchLocation)
{
  TRACE("((intptr_t )%p, (ScreenshotHandle )%p, (char *)\"%s\")\n", instancePtr, hScreenshot, pchLocation);
  auto result = SteamAPI_ISteamScreenshots_SetLocation(instancePtr, hScreenshot, pchLocation);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamScreenshots_TagUser_(intptr_t  instancePtr, ScreenshotHandle  hScreenshot, CSteamID  steamID)
{
  TRACE("((intptr_t )%p, (ScreenshotHandle )%p, (CSteamID )%p)\n", instancePtr, hScreenshot, steamID);
  auto result = SteamAPI_ISteamScreenshots_TagUser(instancePtr, hScreenshot, steamID);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamScreenshots_TagPublishedFile_(intptr_t  instancePtr, ScreenshotHandle  hScreenshot, PublishedFileId_t  unPublishedFileID)
{
  TRACE("((intptr_t )%p, (ScreenshotHandle )%p, (PublishedFileId_t )%p)\n", instancePtr, hScreenshot, unPublishedFileID);
  auto result = SteamAPI_ISteamScreenshots_TagPublishedFile(instancePtr, hScreenshot, unPublishedFileID);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusic_BIsEnabled_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamMusic_BIsEnabled(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusic_BIsPlaying_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamMusic_BIsPlaying(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


AudioPlayback_Status  SteamAPI_ISteamMusic_GetPlaybackStatus_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamMusic_GetPlaybackStatus(instancePtr);
  TRACE("() = (AudioPlayback_Status )%p\n", result);

  return result;
}


void  SteamAPI_ISteamMusic_Play_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  SteamAPI_ISteamMusic_Play(instancePtr);
  
}


void  SteamAPI_ISteamMusic_Pause_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  SteamAPI_ISteamMusic_Pause(instancePtr);
  
}


void  SteamAPI_ISteamMusic_PlayPrevious_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  SteamAPI_ISteamMusic_PlayPrevious(instancePtr);
  
}


void  SteamAPI_ISteamMusic_PlayNext_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  SteamAPI_ISteamMusic_PlayNext(instancePtr);
  
}


void  SteamAPI_ISteamMusic_SetVolume_(intptr_t  instancePtr, float  flVolume)
{
  TRACE("((intptr_t )%p, (float )%f)\n", instancePtr, flVolume);
  SteamAPI_ISteamMusic_SetVolume(instancePtr, flVolume);
  
}


float  SteamAPI_ISteamMusic_GetVolume_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamMusic_GetVolume(instancePtr);
  TRACE("() = (float )%f\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_RegisterSteamMusicRemote_(intptr_t  instancePtr, char * pchName)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchName);
  auto result = SteamAPI_ISteamMusicRemote_RegisterSteamMusicRemote(instancePtr, pchName);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_DeregisterSteamMusicRemote_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamMusicRemote_DeregisterSteamMusicRemote(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_BIsCurrentMusicRemote_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamMusicRemote_BIsCurrentMusicRemote(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_BActivationSuccess_(intptr_t  instancePtr, bool  bValue)
{
  TRACE("((intptr_t )%p, (bool )%d)\n", instancePtr, bValue);
  auto result = SteamAPI_ISteamMusicRemote_BActivationSuccess(instancePtr, bValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_SetDisplayName_(intptr_t  instancePtr, char * pchDisplayName)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchDisplayName);
  auto result = SteamAPI_ISteamMusicRemote_SetDisplayName(instancePtr, pchDisplayName);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_SetPNGIcon_64x64_(intptr_t  instancePtr, void * pvBuffer, uint32  cbBufferLength)
{
  TRACE("((intptr_t )%p, (void *)%p, (uint32 )%d)\n", instancePtr, pvBuffer, cbBufferLength);
  auto result = SteamAPI_ISteamMusicRemote_SetPNGIcon_64x64(instancePtr, pvBuffer, cbBufferLength);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_EnablePlayPrevious_(intptr_t  instancePtr, bool  bValue)
{
  TRACE("((intptr_t )%p, (bool )%d)\n", instancePtr, bValue);
  auto result = SteamAPI_ISteamMusicRemote_EnablePlayPrevious(instancePtr, bValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_EnablePlayNext_(intptr_t  instancePtr, bool  bValue)
{
  TRACE("((intptr_t )%p, (bool )%d)\n", instancePtr, bValue);
  auto result = SteamAPI_ISteamMusicRemote_EnablePlayNext(instancePtr, bValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_EnableShuffled_(intptr_t  instancePtr, bool  bValue)
{
  TRACE("((intptr_t )%p, (bool )%d)\n", instancePtr, bValue);
  auto result = SteamAPI_ISteamMusicRemote_EnableShuffled(instancePtr, bValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_EnableLooped_(intptr_t  instancePtr, bool  bValue)
{
  TRACE("((intptr_t )%p, (bool )%d)\n", instancePtr, bValue);
  auto result = SteamAPI_ISteamMusicRemote_EnableLooped(instancePtr, bValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_EnableQueue_(intptr_t  instancePtr, bool  bValue)
{
  TRACE("((intptr_t )%p, (bool )%d)\n", instancePtr, bValue);
  auto result = SteamAPI_ISteamMusicRemote_EnableQueue(instancePtr, bValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_EnablePlaylists_(intptr_t  instancePtr, bool  bValue)
{
  TRACE("((intptr_t )%p, (bool )%d)\n", instancePtr, bValue);
  auto result = SteamAPI_ISteamMusicRemote_EnablePlaylists(instancePtr, bValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_UpdatePlaybackStatus_(intptr_t  instancePtr, AudioPlayback_Status  nStatus)
{
  TRACE("((intptr_t )%p, (AudioPlayback_Status )%p)\n", instancePtr, nStatus);
  auto result = SteamAPI_ISteamMusicRemote_UpdatePlaybackStatus(instancePtr, nStatus);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_UpdateShuffled_(intptr_t  instancePtr, bool  bValue)
{
  TRACE("((intptr_t )%p, (bool )%d)\n", instancePtr, bValue);
  auto result = SteamAPI_ISteamMusicRemote_UpdateShuffled(instancePtr, bValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_UpdateLooped_(intptr_t  instancePtr, bool  bValue)
{
  TRACE("((intptr_t )%p, (bool )%d)\n", instancePtr, bValue);
  auto result = SteamAPI_ISteamMusicRemote_UpdateLooped(instancePtr, bValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_UpdateVolume_(intptr_t  instancePtr, float  flValue)
{
  TRACE("((intptr_t )%p, (float )%f)\n", instancePtr, flValue);
  auto result = SteamAPI_ISteamMusicRemote_UpdateVolume(instancePtr, flValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_CurrentEntryWillChange_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamMusicRemote_CurrentEntryWillChange(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_CurrentEntryIsAvailable_(intptr_t  instancePtr, bool  bAvailable)
{
  TRACE("((intptr_t )%p, (bool )%d)\n", instancePtr, bAvailable);
  auto result = SteamAPI_ISteamMusicRemote_CurrentEntryIsAvailable(instancePtr, bAvailable);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_UpdateCurrentEntryText_(intptr_t  instancePtr, char * pchText)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchText);
  auto result = SteamAPI_ISteamMusicRemote_UpdateCurrentEntryText(instancePtr, pchText);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_UpdateCurrentEntryElapsedSeconds_(intptr_t  instancePtr, int  nValue)
{
  TRACE("((intptr_t )%p, (int )%d)\n", instancePtr, nValue);
  auto result = SteamAPI_ISteamMusicRemote_UpdateCurrentEntryElapsedSeconds(instancePtr, nValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_UpdateCurrentEntryCoverArt_(intptr_t  instancePtr, void * pvBuffer, uint32  cbBufferLength)
{
  TRACE("((intptr_t )%p, (void *)%p, (uint32 )%d)\n", instancePtr, pvBuffer, cbBufferLength);
  auto result = SteamAPI_ISteamMusicRemote_UpdateCurrentEntryCoverArt(instancePtr, pvBuffer, cbBufferLength);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_CurrentEntryDidChange_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamMusicRemote_CurrentEntryDidChange(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_QueueWillChange_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamMusicRemote_QueueWillChange(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_ResetQueueEntries_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamMusicRemote_ResetQueueEntries(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_SetQueueEntry_(intptr_t  instancePtr, int  nID, int  nPosition, char * pchEntryText)
{
  TRACE("((intptr_t )%p, (int )%d, (int )%d, (char *)\"%s\")\n", instancePtr, nID, nPosition, pchEntryText);
  auto result = SteamAPI_ISteamMusicRemote_SetQueueEntry(instancePtr, nID, nPosition, pchEntryText);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_SetCurrentQueueEntry_(intptr_t  instancePtr, int  nID)
{
  TRACE("((intptr_t )%p, (int )%d)\n", instancePtr, nID);
  auto result = SteamAPI_ISteamMusicRemote_SetCurrentQueueEntry(instancePtr, nID);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_QueueDidChange_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamMusicRemote_QueueDidChange(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_PlaylistWillChange_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamMusicRemote_PlaylistWillChange(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_ResetPlaylistEntries_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamMusicRemote_ResetPlaylistEntries(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_SetPlaylistEntry_(intptr_t  instancePtr, int  nID, int  nPosition, char * pchEntryText)
{
  TRACE("((intptr_t )%p, (int )%d, (int )%d, (char *)\"%s\")\n", instancePtr, nID, nPosition, pchEntryText);
  auto result = SteamAPI_ISteamMusicRemote_SetPlaylistEntry(instancePtr, nID, nPosition, pchEntryText);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_SetCurrentPlaylistEntry_(intptr_t  instancePtr, int  nID)
{
  TRACE("((intptr_t )%p, (int )%d)\n", instancePtr, nID);
  auto result = SteamAPI_ISteamMusicRemote_SetCurrentPlaylistEntry(instancePtr, nID);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamMusicRemote_PlaylistDidChange_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamMusicRemote_PlaylistDidChange(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


HTTPRequestHandle  SteamAPI_ISteamHTTP_CreateHTTPRequest_(intptr_t  instancePtr, EHTTPMethod  eHTTPRequestMethod, char * pchAbsoluteURL)
{
  TRACE("((intptr_t )%p, (EHTTPMethod )%p, (char *)\"%s\")\n", instancePtr, eHTTPRequestMethod, pchAbsoluteURL);
  auto result = SteamAPI_ISteamHTTP_CreateHTTPRequest(instancePtr, eHTTPRequestMethod, pchAbsoluteURL);
  TRACE("() = (HTTPRequestHandle )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_SetHTTPRequestContextValue_(intptr_t  instancePtr, HTTPRequestHandle  hRequest, uint64  ulContextValue)
{
  TRACE("((intptr_t )%p, (HTTPRequestHandle )%p, (uint64 )%d)\n", instancePtr, hRequest, ulContextValue);
  auto result = SteamAPI_ISteamHTTP_SetHTTPRequestContextValue(instancePtr, hRequest, ulContextValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_SetHTTPRequestNetworkActivityTimeout_(intptr_t  instancePtr, HTTPRequestHandle  hRequest, uint32  unTimeoutSeconds)
{
  TRACE("((intptr_t )%p, (HTTPRequestHandle )%p, (uint32 )%d)\n", instancePtr, hRequest, unTimeoutSeconds);
  auto result = SteamAPI_ISteamHTTP_SetHTTPRequestNetworkActivityTimeout(instancePtr, hRequest, unTimeoutSeconds);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_SetHTTPRequestHeaderValue_(intptr_t  instancePtr, HTTPRequestHandle  hRequest, char * pchHeaderName, char * pchHeaderValue)
{
  TRACE("((intptr_t )%p, (HTTPRequestHandle )%p, (char *)\"%s\", (char *)\"%s\")\n", instancePtr, hRequest, pchHeaderName, pchHeaderValue);
  auto result = SteamAPI_ISteamHTTP_SetHTTPRequestHeaderValue(instancePtr, hRequest, pchHeaderName, pchHeaderValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_SetHTTPRequestGetOrPostParameter_(intptr_t  instancePtr, HTTPRequestHandle  hRequest, char * pchParamName, char * pchParamValue)
{
  TRACE("((intptr_t )%p, (HTTPRequestHandle )%p, (char *)\"%s\", (char *)\"%s\")\n", instancePtr, hRequest, pchParamName, pchParamValue);
  auto result = SteamAPI_ISteamHTTP_SetHTTPRequestGetOrPostParameter(instancePtr, hRequest, pchParamName, pchParamValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_SendHTTPRequest_(intptr_t  instancePtr, HTTPRequestHandle  hRequest, SteamAPICall_t * pCallHandle)
{
  TRACE("((intptr_t )%p, (HTTPRequestHandle )%p, (SteamAPICall_t *)%p)\n", instancePtr, hRequest, pCallHandle);
  auto result = SteamAPI_ISteamHTTP_SendHTTPRequest(instancePtr, hRequest, pCallHandle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_SendHTTPRequestAndStreamResponse_(intptr_t  instancePtr, HTTPRequestHandle  hRequest, SteamAPICall_t * pCallHandle)
{
  TRACE("((intptr_t )%p, (HTTPRequestHandle )%p, (SteamAPICall_t *)%p)\n", instancePtr, hRequest, pCallHandle);
  auto result = SteamAPI_ISteamHTTP_SendHTTPRequestAndStreamResponse(instancePtr, hRequest, pCallHandle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_DeferHTTPRequest_(intptr_t  instancePtr, HTTPRequestHandle  hRequest)
{
  TRACE("((intptr_t )%p, (HTTPRequestHandle )%p)\n", instancePtr, hRequest);
  auto result = SteamAPI_ISteamHTTP_DeferHTTPRequest(instancePtr, hRequest);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_PrioritizeHTTPRequest_(intptr_t  instancePtr, HTTPRequestHandle  hRequest)
{
  TRACE("((intptr_t )%p, (HTTPRequestHandle )%p)\n", instancePtr, hRequest);
  auto result = SteamAPI_ISteamHTTP_PrioritizeHTTPRequest(instancePtr, hRequest);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_GetHTTPResponseHeaderSize_(intptr_t  instancePtr, HTTPRequestHandle  hRequest, char * pchHeaderName, uint32 * unResponseHeaderSize)
{
  TRACE("((intptr_t )%p, (HTTPRequestHandle )%p, (char *)\"%s\", (uint32 *)%d)\n", instancePtr, hRequest, pchHeaderName, unResponseHeaderSize);
  auto result = SteamAPI_ISteamHTTP_GetHTTPResponseHeaderSize(instancePtr, hRequest, pchHeaderName, unResponseHeaderSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_GetHTTPResponseHeaderValue_(intptr_t  instancePtr, HTTPRequestHandle  hRequest, char * pchHeaderName, uint8 * pHeaderValueBuffer, uint32  unBufferSize)
{
  TRACE("((intptr_t )%p, (HTTPRequestHandle )%p, (char *)\"%s\", (uint8 *)%p, (uint32 )%d)\n", instancePtr, hRequest, pchHeaderName, pHeaderValueBuffer, unBufferSize);
  auto result = SteamAPI_ISteamHTTP_GetHTTPResponseHeaderValue(instancePtr, hRequest, pchHeaderName, pHeaderValueBuffer, unBufferSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_GetHTTPResponseBodySize_(intptr_t  instancePtr, HTTPRequestHandle  hRequest, uint32 * unBodySize)
{
  TRACE("((intptr_t )%p, (HTTPRequestHandle )%p, (uint32 *)%d)\n", instancePtr, hRequest, unBodySize);
  auto result = SteamAPI_ISteamHTTP_GetHTTPResponseBodySize(instancePtr, hRequest, unBodySize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_GetHTTPResponseBodyData_(intptr_t  instancePtr, HTTPRequestHandle  hRequest, uint8 * pBodyDataBuffer, uint32  unBufferSize)
{
  TRACE("((intptr_t )%p, (HTTPRequestHandle )%p, (uint8 *)%p, (uint32 )%d)\n", instancePtr, hRequest, pBodyDataBuffer, unBufferSize);
  auto result = SteamAPI_ISteamHTTP_GetHTTPResponseBodyData(instancePtr, hRequest, pBodyDataBuffer, unBufferSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_GetHTTPStreamingResponseBodyData_(intptr_t  instancePtr, HTTPRequestHandle  hRequest, uint32  cOffset, uint8 * pBodyDataBuffer, uint32  unBufferSize)
{
  TRACE("((intptr_t )%p, (HTTPRequestHandle )%p, (uint32 )%d, (uint8 *)%p, (uint32 )%d)\n", instancePtr, hRequest, cOffset, pBodyDataBuffer, unBufferSize);
  auto result = SteamAPI_ISteamHTTP_GetHTTPStreamingResponseBodyData(instancePtr, hRequest, cOffset, pBodyDataBuffer, unBufferSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_ReleaseHTTPRequest_(intptr_t  instancePtr, HTTPRequestHandle  hRequest)
{
  TRACE("((intptr_t )%p, (HTTPRequestHandle )%p)\n", instancePtr, hRequest);
  auto result = SteamAPI_ISteamHTTP_ReleaseHTTPRequest(instancePtr, hRequest);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_GetHTTPDownloadProgressPct_(intptr_t  instancePtr, HTTPRequestHandle  hRequest, float * pflPercentOut)
{
  TRACE("((intptr_t )%p, (HTTPRequestHandle )%p, (float *)%f)\n", instancePtr, hRequest, pflPercentOut);
  auto result = SteamAPI_ISteamHTTP_GetHTTPDownloadProgressPct(instancePtr, hRequest, pflPercentOut);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_SetHTTPRequestRawPostBody_(intptr_t  instancePtr, HTTPRequestHandle  hRequest, char * pchContentType, uint8 * pubBody, uint32  unBodyLen)
{
  TRACE("((intptr_t )%p, (HTTPRequestHandle )%p, (char *)\"%s\", (uint8 *)%p, (uint32 )%d)\n", instancePtr, hRequest, pchContentType, pubBody, unBodyLen);
  auto result = SteamAPI_ISteamHTTP_SetHTTPRequestRawPostBody(instancePtr, hRequest, pchContentType, pubBody, unBodyLen);
  TRACE("() = (bool )%d\n", result);

  return result;
}


HTTPCookieContainerHandle  SteamAPI_ISteamHTTP_CreateCookieContainer_(intptr_t  instancePtr, bool  bAllowResponsesToModify)
{
  TRACE("((intptr_t )%p, (bool )%d)\n", instancePtr, bAllowResponsesToModify);
  auto result = SteamAPI_ISteamHTTP_CreateCookieContainer(instancePtr, bAllowResponsesToModify);
  TRACE("() = (HTTPCookieContainerHandle )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_ReleaseCookieContainer_(intptr_t  instancePtr, HTTPCookieContainerHandle  hCookieContainer)
{
  TRACE("((intptr_t )%p, (HTTPCookieContainerHandle )%p)\n", instancePtr, hCookieContainer);
  auto result = SteamAPI_ISteamHTTP_ReleaseCookieContainer(instancePtr, hCookieContainer);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_SetCookie_(intptr_t  instancePtr, HTTPCookieContainerHandle  hCookieContainer, char * pchHost, char * pchUrl, char * pchCookie)
{
  TRACE("((intptr_t )%p, (HTTPCookieContainerHandle )%p, (char *)\"%s\", (char *)\"%s\", (char *)\"%s\")\n", instancePtr, hCookieContainer, pchHost, pchUrl, pchCookie);
  auto result = SteamAPI_ISteamHTTP_SetCookie(instancePtr, hCookieContainer, pchHost, pchUrl, pchCookie);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_SetHTTPRequestCookieContainer_(intptr_t  instancePtr, HTTPRequestHandle  hRequest, HTTPCookieContainerHandle  hCookieContainer)
{
  TRACE("((intptr_t )%p, (HTTPRequestHandle )%p, (HTTPCookieContainerHandle )%p)\n", instancePtr, hRequest, hCookieContainer);
  auto result = SteamAPI_ISteamHTTP_SetHTTPRequestCookieContainer(instancePtr, hRequest, hCookieContainer);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_SetHTTPRequestUserAgentInfo_(intptr_t  instancePtr, HTTPRequestHandle  hRequest, char * pchUserAgentInfo)
{
  TRACE("((intptr_t )%p, (HTTPRequestHandle )%p, (char *)\"%s\")\n", instancePtr, hRequest, pchUserAgentInfo);
  auto result = SteamAPI_ISteamHTTP_SetHTTPRequestUserAgentInfo(instancePtr, hRequest, pchUserAgentInfo);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate_(intptr_t  instancePtr, HTTPRequestHandle  hRequest, bool  bRequireVerifiedCertificate)
{
  TRACE("((intptr_t )%p, (HTTPRequestHandle )%p, (bool )%d)\n", instancePtr, hRequest, bRequireVerifiedCertificate);
  auto result = SteamAPI_ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate(instancePtr, hRequest, bRequireVerifiedCertificate);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS_(intptr_t  instancePtr, HTTPRequestHandle  hRequest, uint32  unMilliseconds)
{
  TRACE("((intptr_t )%p, (HTTPRequestHandle )%p, (uint32 )%d)\n", instancePtr, hRequest, unMilliseconds);
  auto result = SteamAPI_ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS(instancePtr, hRequest, unMilliseconds);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamHTTP_GetHTTPRequestWasTimedOut_(intptr_t  instancePtr, HTTPRequestHandle  hRequest, bool * pbWasTimedOut)
{
  TRACE("((intptr_t )%p, (HTTPRequestHandle )%p, (bool *)%d)\n", instancePtr, hRequest, pbWasTimedOut);
  auto result = SteamAPI_ISteamHTTP_GetHTTPRequestWasTimedOut(instancePtr, hRequest, pbWasTimedOut);
  TRACE("() = (bool )%d\n", result);

  return result;
}


ClientUnifiedMessageHandle  SteamAPI_ISteamUnifiedMessages_SendMethod_(intptr_t  instancePtr, char * pchServiceMethod, void * pRequestBuffer, uint32  unRequestBufferSize, uint64  unContext)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (void *)%p, (uint32 )%d, (uint64 )%d)\n", instancePtr, pchServiceMethod, pRequestBuffer, unRequestBufferSize, unContext);
  auto result = SteamAPI_ISteamUnifiedMessages_SendMethod(instancePtr, pchServiceMethod, pRequestBuffer, unRequestBufferSize, unContext);
  TRACE("() = (ClientUnifiedMessageHandle )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamUnifiedMessages_GetMethodResponseInfo_(intptr_t  instancePtr, ClientUnifiedMessageHandle  hHandle, uint32 * punResponseSize, EResult * peResult)
{
  TRACE("((intptr_t )%p, (ClientUnifiedMessageHandle )%p, (uint32 *)%d, (EResult *)%p)\n", instancePtr, hHandle, punResponseSize, peResult);
  auto result = SteamAPI_ISteamUnifiedMessages_GetMethodResponseInfo(instancePtr, hHandle, punResponseSize, peResult);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUnifiedMessages_GetMethodResponseData_(intptr_t  instancePtr, ClientUnifiedMessageHandle  hHandle, void * pResponseBuffer, uint32  unResponseBufferSize, bool  bAutoRelease)
{
  TRACE("((intptr_t )%p, (ClientUnifiedMessageHandle )%p, (void *)%p, (uint32 )%d, (bool )%d)\n", instancePtr, hHandle, pResponseBuffer, unResponseBufferSize, bAutoRelease);
  auto result = SteamAPI_ISteamUnifiedMessages_GetMethodResponseData(instancePtr, hHandle, pResponseBuffer, unResponseBufferSize, bAutoRelease);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUnifiedMessages_ReleaseMethod_(intptr_t  instancePtr, ClientUnifiedMessageHandle  hHandle)
{
  TRACE("((intptr_t )%p, (ClientUnifiedMessageHandle )%p)\n", instancePtr, hHandle);
  auto result = SteamAPI_ISteamUnifiedMessages_ReleaseMethod(instancePtr, hHandle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUnifiedMessages_SendNotification_(intptr_t  instancePtr, char * pchServiceNotification, void * pNotificationBuffer, uint32  unNotificationBufferSize)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (void *)%p, (uint32 )%d)\n", instancePtr, pchServiceNotification, pNotificationBuffer, unNotificationBufferSize);
  auto result = SteamAPI_ISteamUnifiedMessages_SendNotification(instancePtr, pchServiceNotification, pNotificationBuffer, unNotificationBufferSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamController_Init_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamController_Init(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamController_Shutdown_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamController_Shutdown(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  SteamAPI_ISteamController_RunFrame_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  SteamAPI_ISteamController_RunFrame(instancePtr);
  
}


void  SteamAPI_ISteamController_TriggerHapticPulse_(intptr_t  instancePtr, ControllerHandle_t  controllerHandle, ESteamControllerPad  eTargetPad, unsigned short  usDurationMicroSec)
{
  TRACE("((intptr_t )%p, (ControllerHandle_t )%p, (ESteamControllerPad )%p, (unsigned short )%p)\n", instancePtr, controllerHandle, eTargetPad, usDurationMicroSec);
  SteamAPI_ISteamController_TriggerHapticPulse(instancePtr, controllerHandle, eTargetPad, usDurationMicroSec);
  
}


UGCQueryHandle_t  SteamAPI_ISteamUGC_CreateQueryUserUGCRequest_(intptr_t  instancePtr, AccountID_t  unAccountID, EUserUGCList  eListType, EUGCMatchingUGCType  eMatchingUGCType, EUserUGCListSortOrder  eSortOrder, AppId_t  nCreatorAppID, AppId_t  nConsumerAppID, uint32  unPage)
{
  TRACE("((intptr_t )%p, (AccountID_t )%p, (EUserUGCList )%p, (EUGCMatchingUGCType )%p, (EUserUGCListSortOrder )%p, (AppId_t )%p, (AppId_t )%p, (uint32 )%d)\n", instancePtr, unAccountID, eListType, eMatchingUGCType, eSortOrder, nCreatorAppID, nConsumerAppID, unPage);
  auto result = SteamAPI_ISteamUGC_CreateQueryUserUGCRequest(instancePtr, unAccountID, eListType, eMatchingUGCType, eSortOrder, nCreatorAppID, nConsumerAppID, unPage);
  TRACE("() = (UGCQueryHandle_t )%p\n", result);

  return result;
}


UGCQueryHandle_t  SteamAPI_ISteamUGC_CreateQueryAllUGCRequest_(intptr_t  instancePtr, EUGCQuery  eQueryType, EUGCMatchingUGCType  eMatchingeMatchingUGCTypeFileType, AppId_t  nCreatorAppID, AppId_t  nConsumerAppID, uint32  unPage)
{
  TRACE("((intptr_t )%p, (EUGCQuery )%p, (EUGCMatchingUGCType )%p, (AppId_t )%p, (AppId_t )%p, (uint32 )%d)\n", instancePtr, eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, unPage);
  auto result = SteamAPI_ISteamUGC_CreateQueryAllUGCRequest(instancePtr, eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, unPage);
  TRACE("() = (UGCQueryHandle_t )%p\n", result);

  return result;
}


UGCQueryHandle_t  SteamAPI_ISteamUGC_CreateQueryUGCDetailsRequest_(intptr_t  instancePtr, PublishedFileId_t * pvecPublishedFileID, uint32  unNumPublishedFileIDs)
{
  TRACE("((intptr_t )%p, (PublishedFileId_t *)%p, (uint32 )%d)\n", instancePtr, pvecPublishedFileID, unNumPublishedFileIDs);
  auto result = SteamAPI_ISteamUGC_CreateQueryUGCDetailsRequest(instancePtr, pvecPublishedFileID, unNumPublishedFileIDs);
  TRACE("() = (UGCQueryHandle_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamUGC_SendQueryUGCRequest_(intptr_t  instancePtr, UGCQueryHandle_t  handle)
{
  TRACE("((intptr_t )%p, (UGCQueryHandle_t )%p)\n", instancePtr, handle);
  auto result = SteamAPI_ISteamUGC_SendQueryUGCRequest(instancePtr, handle);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_GetQueryUGCResult_(intptr_t  instancePtr, UGCQueryHandle_t  handle, uint32  index, SteamUGCDetails_t * pDetails)
{
  TRACE("((intptr_t )%p, (UGCQueryHandle_t )%p, (uint32 )%d, (SteamUGCDetails_t *)%p)\n", instancePtr, handle, index, pDetails);
  auto result = SteamAPI_ISteamUGC_GetQueryUGCResult(instancePtr, handle, index, pDetails);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_GetQueryUGCPreviewURL_(intptr_t  instancePtr, UGCQueryHandle_t  handle, uint32  index, char * pchURL, uint32  cchURLSize)
{
  TRACE("((intptr_t )%p, (UGCQueryHandle_t )%p, (uint32 )%d, (char *)\"%s\", (uint32 )%d)\n", instancePtr, handle, index, pchURL, cchURLSize);
  auto result = SteamAPI_ISteamUGC_GetQueryUGCPreviewURL(instancePtr, handle, index, pchURL, cchURLSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_GetQueryUGCMetadata_(intptr_t  instancePtr, UGCQueryHandle_t  handle, uint32  index, char * pchMetadata, uint32  cchMetadatasize)
{
  TRACE("((intptr_t )%p, (UGCQueryHandle_t )%p, (uint32 )%d, (char *)\"%s\", (uint32 )%d)\n", instancePtr, handle, index, pchMetadata, cchMetadatasize);
  auto result = SteamAPI_ISteamUGC_GetQueryUGCMetadata(instancePtr, handle, index, pchMetadata, cchMetadatasize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_GetQueryUGCChildren_(intptr_t  instancePtr, UGCQueryHandle_t  handle, uint32  index, PublishedFileId_t * pvecPublishedFileID, uint32  cMaxEntries)
{
  TRACE("((intptr_t )%p, (UGCQueryHandle_t )%p, (uint32 )%d, (PublishedFileId_t *)%p, (uint32 )%d)\n", instancePtr, handle, index, pvecPublishedFileID, cMaxEntries);
  auto result = SteamAPI_ISteamUGC_GetQueryUGCChildren(instancePtr, handle, index, pvecPublishedFileID, cMaxEntries);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_GetQueryUGCStatistic_(intptr_t  instancePtr, UGCQueryHandle_t  handle, uint32  index, EItemStatistic  eStatType, uint64 * pStatValue)
{
  TRACE("((intptr_t )%p, (UGCQueryHandle_t )%p, (uint32 )%d, (EItemStatistic )%p, (uint64 *)%d)\n", instancePtr, handle, index, eStatType, pStatValue);
  auto result = SteamAPI_ISteamUGC_GetQueryUGCStatistic(instancePtr, handle, index, eStatType, pStatValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


uint32  SteamAPI_ISteamUGC_GetQueryUGCNumAdditionalPreviews_(intptr_t  instancePtr, UGCQueryHandle_t  handle, uint32  index)
{
  TRACE("((intptr_t )%p, (UGCQueryHandle_t )%p, (uint32 )%d)\n", instancePtr, handle, index);
  auto result = SteamAPI_ISteamUGC_GetQueryUGCNumAdditionalPreviews(instancePtr, handle, index);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_GetQueryUGCAdditionalPreview_(intptr_t  instancePtr, UGCQueryHandle_t  handle, uint32  index, uint32  previewIndex, char * pchURLOrVideoID, uint32  cchURLSize, char * pchOriginalFileName, uint32  cchOriginalFileNameSize, EItemPreviewType * pPreviewType)
{
  TRACE("((intptr_t )%p, (UGCQueryHandle_t )%p, (uint32 )%d, (uint32 )%d, (char *)\"%s\", (uint32 )%d, (char *)\"%s\", (uint32 )%d, (EItemPreviewType *)%p)\n", instancePtr, handle, index, previewIndex, pchURLOrVideoID, cchURLSize, pchOriginalFileName, cchOriginalFileNameSize, pPreviewType);
  auto result = SteamAPI_ISteamUGC_GetQueryUGCAdditionalPreview(instancePtr, handle, index, previewIndex, pchURLOrVideoID, cchURLSize, pchOriginalFileName, cchOriginalFileNameSize, pPreviewType);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_ReleaseQueryUGCRequest_(intptr_t  instancePtr, UGCQueryHandle_t  handle)
{
  TRACE("((intptr_t )%p, (UGCQueryHandle_t )%p)\n", instancePtr, handle);
  auto result = SteamAPI_ISteamUGC_ReleaseQueryUGCRequest(instancePtr, handle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_AddRequiredTag_(intptr_t  instancePtr, UGCQueryHandle_t  handle, char * pTagName)
{
  TRACE("((intptr_t )%p, (UGCQueryHandle_t )%p, (char *)\"%s\")\n", instancePtr, handle, pTagName);
  auto result = SteamAPI_ISteamUGC_AddRequiredTag(instancePtr, handle, pTagName);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_AddExcludedTag_(intptr_t  instancePtr, UGCQueryHandle_t  handle, char * pTagName)
{
  TRACE("((intptr_t )%p, (UGCQueryHandle_t )%p, (char *)\"%s\")\n", instancePtr, handle, pTagName);
  auto result = SteamAPI_ISteamUGC_AddExcludedTag(instancePtr, handle, pTagName);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_SetReturnLongDescription_(intptr_t  instancePtr, UGCQueryHandle_t  handle, bool  bReturnLongDescription)
{
  TRACE("((intptr_t )%p, (UGCQueryHandle_t )%p, (bool )%d)\n", instancePtr, handle, bReturnLongDescription);
  auto result = SteamAPI_ISteamUGC_SetReturnLongDescription(instancePtr, handle, bReturnLongDescription);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_SetReturnMetadata_(intptr_t  instancePtr, UGCQueryHandle_t  handle, bool  bReturnMetadata)
{
  TRACE("((intptr_t )%p, (UGCQueryHandle_t )%p, (bool )%d)\n", instancePtr, handle, bReturnMetadata);
  auto result = SteamAPI_ISteamUGC_SetReturnMetadata(instancePtr, handle, bReturnMetadata);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_SetReturnChildren_(intptr_t  instancePtr, UGCQueryHandle_t  handle, bool  bReturnChildren)
{
  TRACE("((intptr_t )%p, (UGCQueryHandle_t )%p, (bool )%d)\n", instancePtr, handle, bReturnChildren);
  auto result = SteamAPI_ISteamUGC_SetReturnChildren(instancePtr, handle, bReturnChildren);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_SetReturnAdditionalPreviews_(intptr_t  instancePtr, UGCQueryHandle_t  handle, bool  bReturnAdditionalPreviews)
{
  TRACE("((intptr_t )%p, (UGCQueryHandle_t )%p, (bool )%d)\n", instancePtr, handle, bReturnAdditionalPreviews);
  auto result = SteamAPI_ISteamUGC_SetReturnAdditionalPreviews(instancePtr, handle, bReturnAdditionalPreviews);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_SetReturnTotalOnly_(intptr_t  instancePtr, UGCQueryHandle_t  handle, bool  bReturnTotalOnly)
{
  TRACE("((intptr_t )%p, (UGCQueryHandle_t )%p, (bool )%d)\n", instancePtr, handle, bReturnTotalOnly);
  auto result = SteamAPI_ISteamUGC_SetReturnTotalOnly(instancePtr, handle, bReturnTotalOnly);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_SetAllowCachedResponse_(intptr_t  instancePtr, UGCQueryHandle_t  handle, uint32  unMaxAgeSeconds)
{
  TRACE("((intptr_t )%p, (UGCQueryHandle_t )%p, (uint32 )%d)\n", instancePtr, handle, unMaxAgeSeconds);
  auto result = SteamAPI_ISteamUGC_SetAllowCachedResponse(instancePtr, handle, unMaxAgeSeconds);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_SetCloudFileNameFilter_(intptr_t  instancePtr, UGCQueryHandle_t  handle, char * pMatchCloudFileName)
{
  TRACE("((intptr_t )%p, (UGCQueryHandle_t )%p, (char *)\"%s\")\n", instancePtr, handle, pMatchCloudFileName);
  auto result = SteamAPI_ISteamUGC_SetCloudFileNameFilter(instancePtr, handle, pMatchCloudFileName);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_SetMatchAnyTag_(intptr_t  instancePtr, UGCQueryHandle_t  handle, bool  bMatchAnyTag)
{
  TRACE("((intptr_t )%p, (UGCQueryHandle_t )%p, (bool )%d)\n", instancePtr, handle, bMatchAnyTag);
  auto result = SteamAPI_ISteamUGC_SetMatchAnyTag(instancePtr, handle, bMatchAnyTag);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_SetSearchText_(intptr_t  instancePtr, UGCQueryHandle_t  handle, char * pSearchText)
{
  TRACE("((intptr_t )%p, (UGCQueryHandle_t )%p, (char *)\"%s\")\n", instancePtr, handle, pSearchText);
  auto result = SteamAPI_ISteamUGC_SetSearchText(instancePtr, handle, pSearchText);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_SetRankedByTrendDays_(intptr_t  instancePtr, UGCQueryHandle_t  handle, uint32  unDays)
{
  TRACE("((intptr_t )%p, (UGCQueryHandle_t )%p, (uint32 )%d)\n", instancePtr, handle, unDays);
  auto result = SteamAPI_ISteamUGC_SetRankedByTrendDays(instancePtr, handle, unDays);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamUGC_RequestUGCDetails_(intptr_t  instancePtr, PublishedFileId_t  nPublishedFileID, uint32  unMaxAgeSeconds)
{
  TRACE("((intptr_t )%p, (PublishedFileId_t )%p, (uint32 )%d)\n", instancePtr, nPublishedFileID, unMaxAgeSeconds);
  auto result = SteamAPI_ISteamUGC_RequestUGCDetails(instancePtr, nPublishedFileID, unMaxAgeSeconds);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamUGC_CreateItem_(intptr_t  instancePtr, AppId_t  nConsumerAppId, EWorkshopFileType  eFileType)
{
  TRACE("((intptr_t )%p, (AppId_t )%p, (EWorkshopFileType )%p)\n", instancePtr, nConsumerAppId, eFileType);
  auto result = SteamAPI_ISteamUGC_CreateItem(instancePtr, nConsumerAppId, eFileType);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


UGCUpdateHandle_t  SteamAPI_ISteamUGC_StartItemUpdate_(intptr_t  instancePtr, AppId_t  nConsumerAppId, PublishedFileId_t  nPublishedFileID)
{
  TRACE("((intptr_t )%p, (AppId_t )%p, (PublishedFileId_t )%p)\n", instancePtr, nConsumerAppId, nPublishedFileID);
  auto result = SteamAPI_ISteamUGC_StartItemUpdate(instancePtr, nConsumerAppId, nPublishedFileID);
  TRACE("() = (UGCUpdateHandle_t )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_SetItemTitle_(intptr_t  instancePtr, UGCUpdateHandle_t  handle, char * pchTitle)
{
  TRACE("((intptr_t )%p, (UGCUpdateHandle_t )%p, (char *)\"%s\")\n", instancePtr, handle, pchTitle);
  auto result = SteamAPI_ISteamUGC_SetItemTitle(instancePtr, handle, pchTitle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_SetItemDescription_(intptr_t  instancePtr, UGCUpdateHandle_t  handle, char * pchDescription)
{
  TRACE("((intptr_t )%p, (UGCUpdateHandle_t )%p, (char *)\"%s\")\n", instancePtr, handle, pchDescription);
  auto result = SteamAPI_ISteamUGC_SetItemDescription(instancePtr, handle, pchDescription);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_SetItemMetadata_(intptr_t  instancePtr, UGCUpdateHandle_t  handle, char * pchMetaData)
{
  TRACE("((intptr_t )%p, (UGCUpdateHandle_t )%p, (char *)\"%s\")\n", instancePtr, handle, pchMetaData);
  auto result = SteamAPI_ISteamUGC_SetItemMetadata(instancePtr, handle, pchMetaData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_SetItemVisibility_(intptr_t  instancePtr, UGCUpdateHandle_t  handle, ERemoteStoragePublishedFileVisibility  eVisibility)
{
  TRACE("((intptr_t )%p, (UGCUpdateHandle_t )%p, (ERemoteStoragePublishedFileVisibility )%p)\n", instancePtr, handle, eVisibility);
  auto result = SteamAPI_ISteamUGC_SetItemVisibility(instancePtr, handle, eVisibility);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_SetItemTags_(intptr_t  instancePtr, UGCUpdateHandle_t  updateHandle, SteamParamStringArray_t * pTags)
{
  TRACE("((intptr_t )%p, (UGCUpdateHandle_t )%p, (SteamParamStringArray_t *)%p)\n", instancePtr, updateHandle, pTags);
  auto result = SteamAPI_ISteamUGC_SetItemTags(instancePtr, updateHandle, pTags);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_SetItemContent_(intptr_t  instancePtr, UGCUpdateHandle_t  handle, char * pszContentFolder)
{
  TRACE("((intptr_t )%p, (UGCUpdateHandle_t )%p, (char *)\"%s\")\n", instancePtr, handle, pszContentFolder);
  auto result = SteamAPI_ISteamUGC_SetItemContent(instancePtr, handle, pszContentFolder);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_SetItemPreview_(intptr_t  instancePtr, UGCUpdateHandle_t  handle, char * pszPreviewFile)
{
  TRACE("((intptr_t )%p, (UGCUpdateHandle_t )%p, (char *)\"%s\")\n", instancePtr, handle, pszPreviewFile);
  auto result = SteamAPI_ISteamUGC_SetItemPreview(instancePtr, handle, pszPreviewFile);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamUGC_SubmitItemUpdate_(intptr_t  instancePtr, UGCUpdateHandle_t  handle, char * pchChangeNote)
{
  TRACE("((intptr_t )%p, (UGCUpdateHandle_t )%p, (char *)\"%s\")\n", instancePtr, handle, pchChangeNote);
  auto result = SteamAPI_ISteamUGC_SubmitItemUpdate(instancePtr, handle, pchChangeNote);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


EItemUpdateStatus  SteamAPI_ISteamUGC_GetItemUpdateProgress_(intptr_t  instancePtr, UGCUpdateHandle_t  handle, uint64 * punBytesProcessed, uint64 * punBytesTotal)
{
  TRACE("((intptr_t )%p, (UGCUpdateHandle_t )%p, (uint64 *)%d, (uint64 *)%d)\n", instancePtr, handle, punBytesProcessed, punBytesTotal);
  auto result = SteamAPI_ISteamUGC_GetItemUpdateProgress(instancePtr, handle, punBytesProcessed, punBytesTotal);
  TRACE("() = (EItemUpdateStatus )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamUGC_AddItemToFavorites_(intptr_t  instancePtr, AppId_t  nAppId, PublishedFileId_t  nPublishedFileID)
{
  TRACE("((intptr_t )%p, (AppId_t )%p, (PublishedFileId_t )%p)\n", instancePtr, nAppId, nPublishedFileID);
  auto result = SteamAPI_ISteamUGC_AddItemToFavorites(instancePtr, nAppId, nPublishedFileID);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamUGC_RemoveItemFromFavorites_(intptr_t  instancePtr, AppId_t  nAppId, PublishedFileId_t  nPublishedFileID)
{
  TRACE("((intptr_t )%p, (AppId_t )%p, (PublishedFileId_t )%p)\n", instancePtr, nAppId, nPublishedFileID);
  auto result = SteamAPI_ISteamUGC_RemoveItemFromFavorites(instancePtr, nAppId, nPublishedFileID);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamUGC_SubscribeItem_(intptr_t  instancePtr, PublishedFileId_t  nPublishedFileID)
{
  TRACE("((intptr_t )%p, (PublishedFileId_t )%p)\n", instancePtr, nPublishedFileID);
  auto result = SteamAPI_ISteamUGC_SubscribeItem(instancePtr, nPublishedFileID);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamUGC_UnsubscribeItem_(intptr_t  instancePtr, PublishedFileId_t  nPublishedFileID)
{
  TRACE("((intptr_t )%p, (PublishedFileId_t )%p)\n", instancePtr, nPublishedFileID);
  auto result = SteamAPI_ISteamUGC_UnsubscribeItem(instancePtr, nPublishedFileID);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


uint32  SteamAPI_ISteamUGC_GetNumSubscribedItems_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamUGC_GetNumSubscribedItems(instancePtr);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


uint32  SteamAPI_ISteamUGC_GetSubscribedItems_(intptr_t  instancePtr, PublishedFileId_t * pvecPublishedFileID, uint32  cMaxEntries)
{
  TRACE("((intptr_t )%p, (PublishedFileId_t *)%p, (uint32 )%d)\n", instancePtr, pvecPublishedFileID, cMaxEntries);
  auto result = SteamAPI_ISteamUGC_GetSubscribedItems(instancePtr, pvecPublishedFileID, cMaxEntries);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


uint32  SteamAPI_ISteamUGC_GetItemState_(intptr_t  instancePtr, PublishedFileId_t  nPublishedFileID)
{
  TRACE("((intptr_t )%p, (PublishedFileId_t )%p)\n", instancePtr, nPublishedFileID);
  auto result = SteamAPI_ISteamUGC_GetItemState(instancePtr, nPublishedFileID);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_GetItemInstallInfo_(intptr_t  instancePtr, PublishedFileId_t  nPublishedFileID, uint64 * punSizeOnDisk, char * pchFolder, uint32  cchFolderSize, uint32 * punTimeStamp)
{
  TRACE("((intptr_t )%p, (PublishedFileId_t )%p, (uint64 *)%d, (char *)\"%s\", (uint32 )%d, (uint32 *)%d)\n", instancePtr, nPublishedFileID, punSizeOnDisk, pchFolder, cchFolderSize, punTimeStamp);
  auto result = SteamAPI_ISteamUGC_GetItemInstallInfo(instancePtr, nPublishedFileID, punSizeOnDisk, pchFolder, cchFolderSize, punTimeStamp);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_GetItemDownloadInfo_(intptr_t  instancePtr, PublishedFileId_t  nPublishedFileID, uint64 * punBytesDownloaded, uint64 * punBytesTotal)
{
  TRACE("((intptr_t )%p, (PublishedFileId_t )%p, (uint64 *)%d, (uint64 *)%d)\n", instancePtr, nPublishedFileID, punBytesDownloaded, punBytesTotal);
  auto result = SteamAPI_ISteamUGC_GetItemDownloadInfo(instancePtr, nPublishedFileID, punBytesDownloaded, punBytesTotal);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamUGC_DownloadItem_(intptr_t  instancePtr, PublishedFileId_t  nPublishedFileID, bool  bHighPriority)
{
  TRACE("((intptr_t )%p, (PublishedFileId_t )%p, (bool )%d)\n", instancePtr, nPublishedFileID, bHighPriority);
  auto result = SteamAPI_ISteamUGC_DownloadItem(instancePtr, nPublishedFileID, bHighPriority);
  TRACE("() = (bool )%d\n", result);

  return result;
}


uint32  SteamAPI_ISteamAppList_GetNumInstalledApps_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamAppList_GetNumInstalledApps(instancePtr);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


uint32  SteamAPI_ISteamAppList_GetInstalledApps_(intptr_t  instancePtr, AppId_t * pvecAppID, uint32  unMaxAppIDs)
{
  TRACE("((intptr_t )%p, (AppId_t *)%p, (uint32 )%d)\n", instancePtr, pvecAppID, unMaxAppIDs);
  auto result = SteamAPI_ISteamAppList_GetInstalledApps(instancePtr, pvecAppID, unMaxAppIDs);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


int  SteamAPI_ISteamAppList_GetAppName_(intptr_t  instancePtr, AppId_t  nAppID, char * pchName, int  cchNameMax)
{
  TRACE("((intptr_t )%p, (AppId_t )%p, (char *)\"%s\", (int )%d)\n", instancePtr, nAppID, pchName, cchNameMax);
  auto result = SteamAPI_ISteamAppList_GetAppName(instancePtr, nAppID, pchName, cchNameMax);
  TRACE("() = (int )%d\n", result);

  return result;
}


int  SteamAPI_ISteamAppList_GetAppInstallDir_(intptr_t  instancePtr, AppId_t  nAppID, char * pchDirectory, int  cchNameMax)
{
  TRACE("((intptr_t )%p, (AppId_t )%p, (char *)\"%s\", (int )%d)\n", instancePtr, nAppID, pchDirectory, cchNameMax);
  auto result = SteamAPI_ISteamAppList_GetAppInstallDir(instancePtr, nAppID, pchDirectory, cchNameMax);
  TRACE("() = (int )%d\n", result);

  return result;
}


int  SteamAPI_ISteamAppList_GetAppBuildId_(intptr_t  instancePtr, AppId_t  nAppID)
{
  TRACE("((intptr_t )%p, (AppId_t )%p)\n", instancePtr, nAppID);
  auto result = SteamAPI_ISteamAppList_GetAppBuildId(instancePtr, nAppID);
  TRACE("() = (int )%d\n", result);

  return result;
}


void  SteamAPI_ISteamHTMLSurface_DestructISteamHTMLSurface_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  SteamAPI_ISteamHTMLSurface_DestructISteamHTMLSurface(instancePtr);
  
}


bool  SteamAPI_ISteamHTMLSurface_Init_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamHTMLSurface_Init(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamHTMLSurface_Shutdown_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamHTMLSurface_Shutdown(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamHTMLSurface_CreateBrowser_(intptr_t  instancePtr, char * pchUserAgent, char * pchUserCSS)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (char *)\"%s\")\n", instancePtr, pchUserAgent, pchUserCSS);
  auto result = SteamAPI_ISteamHTMLSurface_CreateBrowser(instancePtr, pchUserAgent, pchUserCSS);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


void  SteamAPI_ISteamHTMLSurface_RemoveBrowser_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p)\n", instancePtr, unBrowserHandle);
  SteamAPI_ISteamHTMLSurface_RemoveBrowser(instancePtr, unBrowserHandle);
  
}


void  SteamAPI_ISteamHTMLSurface_LoadURL_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle, char * pchURL, char * pchPostData)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p, (char *)\"%s\", (char *)\"%s\")\n", instancePtr, unBrowserHandle, pchURL, pchPostData);
  SteamAPI_ISteamHTMLSurface_LoadURL(instancePtr, unBrowserHandle, pchURL, pchPostData);
  
}


void  SteamAPI_ISteamHTMLSurface_SetSize_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle, uint32  unWidth, uint32  unHeight)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p, (uint32 )%d, (uint32 )%d)\n", instancePtr, unBrowserHandle, unWidth, unHeight);
  SteamAPI_ISteamHTMLSurface_SetSize(instancePtr, unBrowserHandle, unWidth, unHeight);
  
}


void  SteamAPI_ISteamHTMLSurface_StopLoad_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p)\n", instancePtr, unBrowserHandle);
  SteamAPI_ISteamHTMLSurface_StopLoad(instancePtr, unBrowserHandle);
  
}


void  SteamAPI_ISteamHTMLSurface_Reload_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p)\n", instancePtr, unBrowserHandle);
  SteamAPI_ISteamHTMLSurface_Reload(instancePtr, unBrowserHandle);
  
}


void  SteamAPI_ISteamHTMLSurface_GoBack_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p)\n", instancePtr, unBrowserHandle);
  SteamAPI_ISteamHTMLSurface_GoBack(instancePtr, unBrowserHandle);
  
}


void  SteamAPI_ISteamHTMLSurface_GoForward_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p)\n", instancePtr, unBrowserHandle);
  SteamAPI_ISteamHTMLSurface_GoForward(instancePtr, unBrowserHandle);
  
}


void  SteamAPI_ISteamHTMLSurface_AddHeader_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle, char * pchKey, char * pchValue)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p, (char *)\"%s\", (char *)\"%s\")\n", instancePtr, unBrowserHandle, pchKey, pchValue);
  SteamAPI_ISteamHTMLSurface_AddHeader(instancePtr, unBrowserHandle, pchKey, pchValue);
  
}


void  SteamAPI_ISteamHTMLSurface_ExecuteJavascript_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle, char * pchScript)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p, (char *)\"%s\")\n", instancePtr, unBrowserHandle, pchScript);
  SteamAPI_ISteamHTMLSurface_ExecuteJavascript(instancePtr, unBrowserHandle, pchScript);
  
}


void  SteamAPI_ISteamHTMLSurface_MouseUp_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton  eMouseButton)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p, (ISteamHTMLSurface::EHTMLMouseButton )%p)\n", instancePtr, unBrowserHandle, eMouseButton);
  SteamAPI_ISteamHTMLSurface_MouseUp(instancePtr, unBrowserHandle, eMouseButton);
  
}


void  SteamAPI_ISteamHTMLSurface_MouseDown_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton  eMouseButton)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p, (ISteamHTMLSurface::EHTMLMouseButton )%p)\n", instancePtr, unBrowserHandle, eMouseButton);
  SteamAPI_ISteamHTMLSurface_MouseDown(instancePtr, unBrowserHandle, eMouseButton);
  
}


void  SteamAPI_ISteamHTMLSurface_MouseDoubleClick_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton  eMouseButton)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p, (ISteamHTMLSurface::EHTMLMouseButton )%p)\n", instancePtr, unBrowserHandle, eMouseButton);
  SteamAPI_ISteamHTMLSurface_MouseDoubleClick(instancePtr, unBrowserHandle, eMouseButton);
  
}


void  SteamAPI_ISteamHTMLSurface_MouseMove_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle, int  x, int  y)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p, (int )%d, (int )%d)\n", instancePtr, unBrowserHandle, x, y);
  SteamAPI_ISteamHTMLSurface_MouseMove(instancePtr, unBrowserHandle, x, y);
  
}


void  SteamAPI_ISteamHTMLSurface_MouseWheel_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle, int32  nDelta)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p, (int32 )%d)\n", instancePtr, unBrowserHandle, nDelta);
  SteamAPI_ISteamHTMLSurface_MouseWheel(instancePtr, unBrowserHandle, nDelta);
  
}


void  SteamAPI_ISteamHTMLSurface_KeyDown_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle, uint32  nNativeKeyCode, ISteamHTMLSurface::EHTMLKeyModifiers  eHTMLKeyModifiers)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p, (uint32 )%d, (ISteamHTMLSurface::EHTMLKeyModifiers )%p)\n", instancePtr, unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
  SteamAPI_ISteamHTMLSurface_KeyDown(instancePtr, unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
  
}


void  SteamAPI_ISteamHTMLSurface_KeyUp_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle, uint32  nNativeKeyCode, ISteamHTMLSurface::EHTMLKeyModifiers  eHTMLKeyModifiers)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p, (uint32 )%d, (ISteamHTMLSurface::EHTMLKeyModifiers )%p)\n", instancePtr, unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
  SteamAPI_ISteamHTMLSurface_KeyUp(instancePtr, unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
  
}


void  SteamAPI_ISteamHTMLSurface_KeyChar_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle, uint32  cUnicodeChar, ISteamHTMLSurface::EHTMLKeyModifiers  eHTMLKeyModifiers)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p, (uint32 )%d, (ISteamHTMLSurface::EHTMLKeyModifiers )%p)\n", instancePtr, unBrowserHandle, cUnicodeChar, eHTMLKeyModifiers);
  SteamAPI_ISteamHTMLSurface_KeyChar(instancePtr, unBrowserHandle, cUnicodeChar, eHTMLKeyModifiers);
  
}


void  SteamAPI_ISteamHTMLSurface_SetHorizontalScroll_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle, uint32  nAbsolutePixelScroll)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p, (uint32 )%d)\n", instancePtr, unBrowserHandle, nAbsolutePixelScroll);
  SteamAPI_ISteamHTMLSurface_SetHorizontalScroll(instancePtr, unBrowserHandle, nAbsolutePixelScroll);
  
}


void  SteamAPI_ISteamHTMLSurface_SetVerticalScroll_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle, uint32  nAbsolutePixelScroll)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p, (uint32 )%d)\n", instancePtr, unBrowserHandle, nAbsolutePixelScroll);
  SteamAPI_ISteamHTMLSurface_SetVerticalScroll(instancePtr, unBrowserHandle, nAbsolutePixelScroll);
  
}


void  SteamAPI_ISteamHTMLSurface_SetKeyFocus_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle, bool  bHasKeyFocus)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p, (bool )%d)\n", instancePtr, unBrowserHandle, bHasKeyFocus);
  SteamAPI_ISteamHTMLSurface_SetKeyFocus(instancePtr, unBrowserHandle, bHasKeyFocus);
  
}


void  SteamAPI_ISteamHTMLSurface_ViewSource_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p)\n", instancePtr, unBrowserHandle);
  SteamAPI_ISteamHTMLSurface_ViewSource(instancePtr, unBrowserHandle);
  
}


void  SteamAPI_ISteamHTMLSurface_CopyToClipboard_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p)\n", instancePtr, unBrowserHandle);
  SteamAPI_ISteamHTMLSurface_CopyToClipboard(instancePtr, unBrowserHandle);
  
}


void  SteamAPI_ISteamHTMLSurface_PasteFromClipboard_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p)\n", instancePtr, unBrowserHandle);
  SteamAPI_ISteamHTMLSurface_PasteFromClipboard(instancePtr, unBrowserHandle);
  
}


void  SteamAPI_ISteamHTMLSurface_Find_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle, char * pchSearchStr, bool  bCurrentlyInFind, bool  bReverse)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p, (char *)\"%s\", (bool )%d, (bool )%d)\n", instancePtr, unBrowserHandle, pchSearchStr, bCurrentlyInFind, bReverse);
  SteamAPI_ISteamHTMLSurface_Find(instancePtr, unBrowserHandle, pchSearchStr, bCurrentlyInFind, bReverse);
  
}


void  SteamAPI_ISteamHTMLSurface_StopFind_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p)\n", instancePtr, unBrowserHandle);
  SteamAPI_ISteamHTMLSurface_StopFind(instancePtr, unBrowserHandle);
  
}


void  SteamAPI_ISteamHTMLSurface_GetLinkAtPosition_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle, int  x, int  y)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p, (int )%d, (int )%d)\n", instancePtr, unBrowserHandle, x, y);
  SteamAPI_ISteamHTMLSurface_GetLinkAtPosition(instancePtr, unBrowserHandle, x, y);
  
}


void  SteamAPI_ISteamHTMLSurface_SetCookie_(intptr_t  instancePtr, char * pchHostname, char * pchKey, char * pchValue, char * pchPath, RTime32  nExpires, bool  bSecure, bool  bHTTPOnly)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (char *)\"%s\", (char *)\"%s\", (char *)\"%s\", (RTime32 )%p, (bool )%d, (bool )%d)\n", instancePtr, pchHostname, pchKey, pchValue, pchPath, nExpires, bSecure, bHTTPOnly);
  SteamAPI_ISteamHTMLSurface_SetCookie(instancePtr, pchHostname, pchKey, pchValue, pchPath, nExpires, bSecure, bHTTPOnly);
  
}


void  SteamAPI_ISteamHTMLSurface_SetPageScaleFactor_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle, float  flZoom, int  nPointX, int  nPointY)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p, (float )%f, (int )%d, (int )%d)\n", instancePtr, unBrowserHandle, flZoom, nPointX, nPointY);
  SteamAPI_ISteamHTMLSurface_SetPageScaleFactor(instancePtr, unBrowserHandle, flZoom, nPointX, nPointY);
  
}


void  SteamAPI_ISteamHTMLSurface_SetBackgroundMode_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle, bool  bBackgroundMode)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p, (bool )%d)\n", instancePtr, unBrowserHandle, bBackgroundMode);
  SteamAPI_ISteamHTMLSurface_SetBackgroundMode(instancePtr, unBrowserHandle, bBackgroundMode);
  
}


void  SteamAPI_ISteamHTMLSurface_AllowStartRequest_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle, bool  bAllowed)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p, (bool )%d)\n", instancePtr, unBrowserHandle, bAllowed);
  SteamAPI_ISteamHTMLSurface_AllowStartRequest(instancePtr, unBrowserHandle, bAllowed);
  
}


void  SteamAPI_ISteamHTMLSurface_JSDialogResponse_(intptr_t  instancePtr, HHTMLBrowser  unBrowserHandle, bool  bResult)
{
  TRACE("((intptr_t )%p, (HHTMLBrowser )%p, (bool )%d)\n", instancePtr, unBrowserHandle, bResult);
  SteamAPI_ISteamHTMLSurface_JSDialogResponse(instancePtr, unBrowserHandle, bResult);
  
}


EResult  SteamAPI_ISteamInventory_GetResultStatus_(intptr_t  instancePtr, SteamInventoryResult_t  resultHandle)
{
  TRACE("((intptr_t )%p, (SteamInventoryResult_t )%p)\n", instancePtr, resultHandle);
  auto result = SteamAPI_ISteamInventory_GetResultStatus(instancePtr, resultHandle);
  TRACE("() = (EResult )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamInventory_GetResultItems_(intptr_t  instancePtr, SteamInventoryResult_t  resultHandle, SteamItemDetails_t * pOutItemsArray, uint32 * punOutItemsArraySize)
{
  TRACE("((intptr_t )%p, (SteamInventoryResult_t )%p, (SteamItemDetails_t *)%p, (uint32 *)%d)\n", instancePtr, resultHandle, pOutItemsArray, punOutItemsArraySize);
  auto result = SteamAPI_ISteamInventory_GetResultItems(instancePtr, resultHandle, pOutItemsArray, punOutItemsArraySize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


uint32  SteamAPI_ISteamInventory_GetResultTimestamp_(intptr_t  instancePtr, SteamInventoryResult_t  resultHandle)
{
  TRACE("((intptr_t )%p, (SteamInventoryResult_t )%p)\n", instancePtr, resultHandle);
  auto result = SteamAPI_ISteamInventory_GetResultTimestamp(instancePtr, resultHandle);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamInventory_CheckResultSteamID_(intptr_t  instancePtr, SteamInventoryResult_t  resultHandle, CSteamID  steamIDExpected)
{
  TRACE("((intptr_t )%p, (SteamInventoryResult_t )%p, (CSteamID )%p)\n", instancePtr, resultHandle, steamIDExpected);
  auto result = SteamAPI_ISteamInventory_CheckResultSteamID(instancePtr, resultHandle, steamIDExpected);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  SteamAPI_ISteamInventory_DestroyResult_(intptr_t  instancePtr, SteamInventoryResult_t  resultHandle)
{
  TRACE("((intptr_t )%p, (SteamInventoryResult_t )%p)\n", instancePtr, resultHandle);
  SteamAPI_ISteamInventory_DestroyResult(instancePtr, resultHandle);
  
}


bool  SteamAPI_ISteamInventory_GetAllItems_(intptr_t  instancePtr, SteamInventoryResult_t * pResultHandle)
{
  TRACE("((intptr_t )%p, (SteamInventoryResult_t *)%p)\n", instancePtr, pResultHandle);
  auto result = SteamAPI_ISteamInventory_GetAllItems(instancePtr, pResultHandle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamInventory_GetItemsByID_(intptr_t  instancePtr, SteamInventoryResult_t * pResultHandle, SteamItemInstanceID_t * pInstanceIDs, uint32  unCountInstanceIDs)
{
  TRACE("((intptr_t )%p, (SteamInventoryResult_t *)%p, (SteamItemInstanceID_t *)%p, (uint32 )%d)\n", instancePtr, pResultHandle, pInstanceIDs, unCountInstanceIDs);
  auto result = SteamAPI_ISteamInventory_GetItemsByID(instancePtr, pResultHandle, pInstanceIDs, unCountInstanceIDs);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamInventory_SerializeResult_(intptr_t  instancePtr, SteamInventoryResult_t  resultHandle, void * pOutBuffer, uint32 * punOutBufferSize)
{
  TRACE("((intptr_t )%p, (SteamInventoryResult_t )%p, (void *)%p, (uint32 *)%d)\n", instancePtr, resultHandle, pOutBuffer, punOutBufferSize);
  auto result = SteamAPI_ISteamInventory_SerializeResult(instancePtr, resultHandle, pOutBuffer, punOutBufferSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamInventory_DeserializeResult_(intptr_t  instancePtr, SteamInventoryResult_t * pOutResultHandle, void * pBuffer, uint32  unBufferSize, bool  bRESERVED_MUST_BE_FALSE)
{
  TRACE("((intptr_t )%p, (SteamInventoryResult_t *)%p, (void *)%p, (uint32 )%d, (bool )%d)\n", instancePtr, pOutResultHandle, pBuffer, unBufferSize, bRESERVED_MUST_BE_FALSE);
  auto result = SteamAPI_ISteamInventory_DeserializeResult(instancePtr, pOutResultHandle, pBuffer, unBufferSize, bRESERVED_MUST_BE_FALSE);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamInventory_GenerateItems_(intptr_t  instancePtr, SteamInventoryResult_t * pResultHandle, SteamItemDef_t * pArrayItemDefs, uint32 * punArrayQuantity, uint32  unArrayLength)
{
  TRACE("((intptr_t )%p, (SteamInventoryResult_t *)%p, (SteamItemDef_t *)%p, (uint32 *)%d, (uint32 )%d)\n", instancePtr, pResultHandle, pArrayItemDefs, punArrayQuantity, unArrayLength);
  auto result = SteamAPI_ISteamInventory_GenerateItems(instancePtr, pResultHandle, pArrayItemDefs, punArrayQuantity, unArrayLength);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamInventory_GrantPromoItems_(intptr_t  instancePtr, SteamInventoryResult_t * pResultHandle)
{
  TRACE("((intptr_t )%p, (SteamInventoryResult_t *)%p)\n", instancePtr, pResultHandle);
  auto result = SteamAPI_ISteamInventory_GrantPromoItems(instancePtr, pResultHandle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamInventory_AddPromoItem_(intptr_t  instancePtr, SteamInventoryResult_t * pResultHandle, SteamItemDef_t  itemDef)
{
  TRACE("((intptr_t )%p, (SteamInventoryResult_t *)%p, (SteamItemDef_t )%p)\n", instancePtr, pResultHandle, itemDef);
  auto result = SteamAPI_ISteamInventory_AddPromoItem(instancePtr, pResultHandle, itemDef);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamInventory_AddPromoItems_(intptr_t  instancePtr, SteamInventoryResult_t * pResultHandle, SteamItemDef_t * pArrayItemDefs, uint32  unArrayLength)
{
  TRACE("((intptr_t )%p, (SteamInventoryResult_t *)%p, (SteamItemDef_t *)%p, (uint32 )%d)\n", instancePtr, pResultHandle, pArrayItemDefs, unArrayLength);
  auto result = SteamAPI_ISteamInventory_AddPromoItems(instancePtr, pResultHandle, pArrayItemDefs, unArrayLength);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamInventory_ConsumeItem_(intptr_t  instancePtr, SteamInventoryResult_t * pResultHandle, SteamItemInstanceID_t  itemConsume, uint32  unQuantity)
{
  TRACE("((intptr_t )%p, (SteamInventoryResult_t *)%p, (SteamItemInstanceID_t )%p, (uint32 )%d)\n", instancePtr, pResultHandle, itemConsume, unQuantity);
  auto result = SteamAPI_ISteamInventory_ConsumeItem(instancePtr, pResultHandle, itemConsume, unQuantity);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamInventory_ExchangeItems_(intptr_t  instancePtr, SteamInventoryResult_t * pResultHandle, SteamItemDef_t * pArrayGenerate, uint32 * punArrayGenerateQuantity, uint32  unArrayGenerateLength, SteamItemInstanceID_t * pArrayDestroy, uint32 * punArrayDestroyQuantity, uint32  unArrayDestroyLength)
{
  TRACE("((intptr_t )%p, (SteamInventoryResult_t *)%p, (SteamItemDef_t *)%p, (uint32 *)%d, (uint32 )%d, (SteamItemInstanceID_t *)%p, (uint32 *)%d, (uint32 )%d)\n", instancePtr, pResultHandle, pArrayGenerate, punArrayGenerateQuantity, unArrayGenerateLength, pArrayDestroy, punArrayDestroyQuantity, unArrayDestroyLength);
  auto result = SteamAPI_ISteamInventory_ExchangeItems(instancePtr, pResultHandle, pArrayGenerate, punArrayGenerateQuantity, unArrayGenerateLength, pArrayDestroy, punArrayDestroyQuantity, unArrayDestroyLength);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamInventory_TransferItemQuantity_(intptr_t  instancePtr, SteamInventoryResult_t * pResultHandle, SteamItemInstanceID_t  itemIdSource, uint32  unQuantity, SteamItemInstanceID_t  itemIdDest)
{
  TRACE("((intptr_t )%p, (SteamInventoryResult_t *)%p, (SteamItemInstanceID_t )%p, (uint32 )%d, (SteamItemInstanceID_t )%p)\n", instancePtr, pResultHandle, itemIdSource, unQuantity, itemIdDest);
  auto result = SteamAPI_ISteamInventory_TransferItemQuantity(instancePtr, pResultHandle, itemIdSource, unQuantity, itemIdDest);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  SteamAPI_ISteamInventory_SendItemDropHeartbeat_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  SteamAPI_ISteamInventory_SendItemDropHeartbeat(instancePtr);
  
}


bool  SteamAPI_ISteamInventory_TriggerItemDrop_(intptr_t  instancePtr, SteamInventoryResult_t * pResultHandle, SteamItemDef_t  dropListDefinition)
{
  TRACE("((intptr_t )%p, (SteamInventoryResult_t *)%p, (SteamItemDef_t )%p)\n", instancePtr, pResultHandle, dropListDefinition);
  auto result = SteamAPI_ISteamInventory_TriggerItemDrop(instancePtr, pResultHandle, dropListDefinition);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamInventory_TradeItems_(intptr_t  instancePtr, SteamInventoryResult_t * pResultHandle, CSteamID  steamIDTradePartner, SteamItemInstanceID_t * pArrayGive, uint32 * pArrayGiveQuantity, uint32  nArrayGiveLength, SteamItemInstanceID_t * pArrayGet, uint32 * pArrayGetQuantity, uint32  nArrayGetLength)
{
  TRACE("((intptr_t )%p, (SteamInventoryResult_t *)%p, (CSteamID )%p, (SteamItemInstanceID_t *)%p, (uint32 *)%d, (uint32 )%d, (SteamItemInstanceID_t *)%p, (uint32 *)%d, (uint32 )%d)\n", instancePtr, pResultHandle, steamIDTradePartner, pArrayGive, pArrayGiveQuantity, nArrayGiveLength, pArrayGet, pArrayGetQuantity, nArrayGetLength);
  auto result = SteamAPI_ISteamInventory_TradeItems(instancePtr, pResultHandle, steamIDTradePartner, pArrayGive, pArrayGiveQuantity, nArrayGiveLength, pArrayGet, pArrayGetQuantity, nArrayGetLength);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamInventory_LoadItemDefinitions_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamInventory_LoadItemDefinitions(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamInventory_GetItemDefinitionIDs_(intptr_t  instancePtr, SteamItemDef_t * pItemDefIDs, uint32 * punItemDefIDsArraySize)
{
  TRACE("((intptr_t )%p, (SteamItemDef_t *)%p, (uint32 *)%d)\n", instancePtr, pItemDefIDs, punItemDefIDsArraySize);
  auto result = SteamAPI_ISteamInventory_GetItemDefinitionIDs(instancePtr, pItemDefIDs, punItemDefIDsArraySize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamInventory_GetItemDefinitionProperty_(intptr_t  instancePtr, SteamItemDef_t  iDefinition, char * pchPropertyName, char * pchValueBuffer, uint32 * punValueBufferSizeOut)
{
  TRACE("((intptr_t )%p, (SteamItemDef_t )%p, (char *)\"%s\", (char *)\"%s\", (uint32 *)%d)\n", instancePtr, iDefinition, pchPropertyName, pchValueBuffer, punValueBufferSizeOut);
  auto result = SteamAPI_ISteamInventory_GetItemDefinitionProperty(instancePtr, iDefinition, pchPropertyName, pchValueBuffer, punValueBufferSizeOut);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  SteamAPI_ISteamVideo_GetVideoURL_(intptr_t  instancePtr, AppId_t  unVideoAppID)
{
  TRACE("((intptr_t )%p, (AppId_t )%p)\n", instancePtr, unVideoAppID);
  SteamAPI_ISteamVideo_GetVideoURL(instancePtr, unVideoAppID);
  
}


bool  SteamAPI_ISteamVideo_IsBroadcasting_(intptr_t  instancePtr, int * pnNumViewers)
{
  TRACE("((intptr_t )%p, (int *)%d)\n", instancePtr, pnNumViewers);
  auto result = SteamAPI_ISteamVideo_IsBroadcasting(instancePtr, pnNumViewers);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamGameServer_InitGameServer_(intptr_t  instancePtr, uint32  unIP, uint16  usGamePort, uint16  usQueryPort, uint32  unFlags, AppId_t  nGameAppId, char * pchVersionString)
{
  TRACE("((intptr_t )%p, (uint32 )%d, (uint16 )%d, (uint16 )%d, (uint32 )%d, (AppId_t )%p, (char *)\"%s\")\n", instancePtr, unIP, usGamePort, usQueryPort, unFlags, nGameAppId, pchVersionString);
  auto result = SteamAPI_ISteamGameServer_InitGameServer(instancePtr, unIP, usGamePort, usQueryPort, unFlags, nGameAppId, pchVersionString);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  SteamAPI_ISteamGameServer_SetProduct_(intptr_t  instancePtr, char * pszProduct)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pszProduct);
  SteamAPI_ISteamGameServer_SetProduct(instancePtr, pszProduct);
  
}


void  SteamAPI_ISteamGameServer_SetGameDescription_(intptr_t  instancePtr, char * pszGameDescription)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pszGameDescription);
  SteamAPI_ISteamGameServer_SetGameDescription(instancePtr, pszGameDescription);
  
}


void  SteamAPI_ISteamGameServer_SetModDir_(intptr_t  instancePtr, char * pszModDir)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pszModDir);
  SteamAPI_ISteamGameServer_SetModDir(instancePtr, pszModDir);
  
}


void  SteamAPI_ISteamGameServer_SetDedicatedServer_(intptr_t  instancePtr, bool  bDedicated)
{
  TRACE("((intptr_t )%p, (bool )%d)\n", instancePtr, bDedicated);
  SteamAPI_ISteamGameServer_SetDedicatedServer(instancePtr, bDedicated);
  
}


void  SteamAPI_ISteamGameServer_LogOn_(intptr_t  instancePtr, char * pszToken)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pszToken);
  SteamAPI_ISteamGameServer_LogOn(instancePtr, pszToken);
  
}


void  SteamAPI_ISteamGameServer_LogOnAnonymous_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  SteamAPI_ISteamGameServer_LogOnAnonymous(instancePtr);
  
}


void  SteamAPI_ISteamGameServer_LogOff_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  SteamAPI_ISteamGameServer_LogOff(instancePtr);
  
}


bool  SteamAPI_ISteamGameServer_BLoggedOn_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamGameServer_BLoggedOn(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamGameServer_BSecure_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamGameServer_BSecure(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


uint64  SteamAPI_ISteamGameServer_GetSteamID_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamGameServer_GetSteamID(instancePtr);
  TRACE("() = (uint64 )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamGameServer_WasRestartRequested_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamGameServer_WasRestartRequested(instancePtr);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  SteamAPI_ISteamGameServer_SetMaxPlayerCount_(intptr_t  instancePtr, int  cPlayersMax)
{
  TRACE("((intptr_t )%p, (int )%d)\n", instancePtr, cPlayersMax);
  SteamAPI_ISteamGameServer_SetMaxPlayerCount(instancePtr, cPlayersMax);
  
}


void  SteamAPI_ISteamGameServer_SetBotPlayerCount_(intptr_t  instancePtr, int  cBotplayers)
{
  TRACE("((intptr_t )%p, (int )%d)\n", instancePtr, cBotplayers);
  SteamAPI_ISteamGameServer_SetBotPlayerCount(instancePtr, cBotplayers);
  
}


void  SteamAPI_ISteamGameServer_SetServerName_(intptr_t  instancePtr, char * pszServerName)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pszServerName);
  SteamAPI_ISteamGameServer_SetServerName(instancePtr, pszServerName);
  
}


void  SteamAPI_ISteamGameServer_SetMapName_(intptr_t  instancePtr, char * pszMapName)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pszMapName);
  SteamAPI_ISteamGameServer_SetMapName(instancePtr, pszMapName);
  
}


void  SteamAPI_ISteamGameServer_SetPasswordProtected_(intptr_t  instancePtr, bool  bPasswordProtected)
{
  TRACE("((intptr_t )%p, (bool )%d)\n", instancePtr, bPasswordProtected);
  SteamAPI_ISteamGameServer_SetPasswordProtected(instancePtr, bPasswordProtected);
  
}


void  SteamAPI_ISteamGameServer_SetSpectatorPort_(intptr_t  instancePtr, uint16  unSpectatorPort)
{
  TRACE("((intptr_t )%p, (uint16 )%d)\n", instancePtr, unSpectatorPort);
  SteamAPI_ISteamGameServer_SetSpectatorPort(instancePtr, unSpectatorPort);
  
}


void  SteamAPI_ISteamGameServer_SetSpectatorServerName_(intptr_t  instancePtr, char * pszSpectatorServerName)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pszSpectatorServerName);
  SteamAPI_ISteamGameServer_SetSpectatorServerName(instancePtr, pszSpectatorServerName);
  
}


void  SteamAPI_ISteamGameServer_ClearAllKeyValues_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  SteamAPI_ISteamGameServer_ClearAllKeyValues(instancePtr);
  
}


void  SteamAPI_ISteamGameServer_SetKeyValue_(intptr_t  instancePtr, char * pKey, char * pValue)
{
  TRACE("((intptr_t )%p, (char *)\"%s\", (char *)\"%s\")\n", instancePtr, pKey, pValue);
  SteamAPI_ISteamGameServer_SetKeyValue(instancePtr, pKey, pValue);
  
}


void  SteamAPI_ISteamGameServer_SetGameTags_(intptr_t  instancePtr, char * pchGameTags)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchGameTags);
  SteamAPI_ISteamGameServer_SetGameTags(instancePtr, pchGameTags);
  
}


void  SteamAPI_ISteamGameServer_SetGameData_(intptr_t  instancePtr, char * pchGameData)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pchGameData);
  SteamAPI_ISteamGameServer_SetGameData(instancePtr, pchGameData);
  
}


void  SteamAPI_ISteamGameServer_SetRegion_(intptr_t  instancePtr, char * pszRegion)
{
  TRACE("((intptr_t )%p, (char *)\"%s\")\n", instancePtr, pszRegion);
  SteamAPI_ISteamGameServer_SetRegion(instancePtr, pszRegion);
  
}


bool  SteamAPI_ISteamGameServer_SendUserConnectAndAuthenticate_(intptr_t  instancePtr, uint32  unIPClient, void * pvAuthBlob, uint32  cubAuthBlobSize, CSteamID * pSteamIDUser)
{
  TRACE("((intptr_t )%p, (uint32 )%d, (void *)%p, (uint32 )%d, (CSteamID *)%p)\n", instancePtr, unIPClient, pvAuthBlob, cubAuthBlobSize, pSteamIDUser);
  auto result = SteamAPI_ISteamGameServer_SendUserConnectAndAuthenticate(instancePtr, unIPClient, pvAuthBlob, cubAuthBlobSize, pSteamIDUser);
  TRACE("() = (bool )%d\n", result);

  return result;
}


uint64  SteamAPI_ISteamGameServer_CreateUnauthenticatedUserConnection_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamGameServer_CreateUnauthenticatedUserConnection(instancePtr);
  TRACE("() = (uint64 )%d\n", result);

  return result;
}


void  SteamAPI_ISteamGameServer_SendUserDisconnect_(intptr_t  instancePtr, CSteamID  steamIDUser)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDUser);
  SteamAPI_ISteamGameServer_SendUserDisconnect(instancePtr, steamIDUser);
  
}


bool  SteamAPI_ISteamGameServer_BUpdateUserData_(intptr_t  instancePtr, CSteamID  steamIDUser, char * pchPlayerName, uint32  uScore)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (char *)\"%s\", (uint32 )%d)\n", instancePtr, steamIDUser, pchPlayerName, uScore);
  auto result = SteamAPI_ISteamGameServer_BUpdateUserData(instancePtr, steamIDUser, pchPlayerName, uScore);
  TRACE("() = (bool )%d\n", result);

  return result;
}


HAuthTicket  SteamAPI_ISteamGameServer_GetAuthSessionTicket_(intptr_t  instancePtr, void * pTicket, int  cbMaxTicket, uint32 * pcbTicket)
{
  TRACE("((intptr_t )%p, (void *)%p, (int )%d, (uint32 *)%d)\n", instancePtr, pTicket, cbMaxTicket, pcbTicket);
  auto result = SteamAPI_ISteamGameServer_GetAuthSessionTicket(instancePtr, pTicket, cbMaxTicket, pcbTicket);
  TRACE("() = (HAuthTicket )%p\n", result);

  return result;
}


EBeginAuthSessionResult  SteamAPI_ISteamGameServer_BeginAuthSession_(intptr_t  instancePtr, void * pAuthTicket, int  cbAuthTicket, CSteamID  steamID)
{
  TRACE("((intptr_t )%p, (void *)%p, (int )%d, (CSteamID )%p)\n", instancePtr, pAuthTicket, cbAuthTicket, steamID);
  auto result = SteamAPI_ISteamGameServer_BeginAuthSession(instancePtr, pAuthTicket, cbAuthTicket, steamID);
  TRACE("() = (EBeginAuthSessionResult )%p\n", result);

  return result;
}


void  SteamAPI_ISteamGameServer_EndAuthSession_(intptr_t  instancePtr, CSteamID  steamID)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamID);
  SteamAPI_ISteamGameServer_EndAuthSession(instancePtr, steamID);
  
}


void  SteamAPI_ISteamGameServer_CancelAuthTicket_(intptr_t  instancePtr, HAuthTicket  hAuthTicket)
{
  TRACE("((intptr_t )%p, (HAuthTicket )%p)\n", instancePtr, hAuthTicket);
  SteamAPI_ISteamGameServer_CancelAuthTicket(instancePtr, hAuthTicket);
  
}


EUserHasLicenseForAppResult  SteamAPI_ISteamGameServer_UserHasLicenseForApp_(intptr_t  instancePtr, CSteamID  steamID, AppId_t  appID)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (AppId_t )%p)\n", instancePtr, steamID, appID);
  auto result = SteamAPI_ISteamGameServer_UserHasLicenseForApp(instancePtr, steamID, appID);
  TRACE("() = (EUserHasLicenseForAppResult )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamGameServer_RequestUserGroupStatus_(intptr_t  instancePtr, CSteamID  steamIDUser, CSteamID  steamIDGroup)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (CSteamID )%p)\n", instancePtr, steamIDUser, steamIDGroup);
  auto result = SteamAPI_ISteamGameServer_RequestUserGroupStatus(instancePtr, steamIDUser, steamIDGroup);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  SteamAPI_ISteamGameServer_GetGameplayStats_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  SteamAPI_ISteamGameServer_GetGameplayStats(instancePtr);
  
}


SteamAPICall_t  SteamAPI_ISteamGameServer_GetServerReputation_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamGameServer_GetServerReputation(instancePtr);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


uint32  SteamAPI_ISteamGameServer_GetPublicIP_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  auto result = SteamAPI_ISteamGameServer_GetPublicIP(instancePtr);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamGameServer_HandleIncomingPacket_(intptr_t  instancePtr, void * pData, int  cbData, uint32  srcIP, uint16  srcPort)
{
  TRACE("((intptr_t )%p, (void *)%p, (int )%d, (uint32 )%d, (uint16 )%d)\n", instancePtr, pData, cbData, srcIP, srcPort);
  auto result = SteamAPI_ISteamGameServer_HandleIncomingPacket(instancePtr, pData, cbData, srcIP, srcPort);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  SteamAPI_ISteamGameServer_GetNextOutgoingPacket_(intptr_t  instancePtr, void * pOut, int  cbMaxOut, uint32 * pNetAdr, uint16 * pPort)
{
  TRACE("((intptr_t )%p, (void *)%p, (int )%d, (uint32 *)%d, (uint16 *)%d)\n", instancePtr, pOut, cbMaxOut, pNetAdr, pPort);
  auto result = SteamAPI_ISteamGameServer_GetNextOutgoingPacket(instancePtr, pOut, cbMaxOut, pNetAdr, pPort);
  TRACE("() = (int )%d\n", result);

  return result;
}


void  SteamAPI_ISteamGameServer_EnableHeartbeats_(intptr_t  instancePtr, bool  bActive)
{
  TRACE("((intptr_t )%p, (bool )%d)\n", instancePtr, bActive);
  SteamAPI_ISteamGameServer_EnableHeartbeats(instancePtr, bActive);
  
}


void  SteamAPI_ISteamGameServer_SetHeartbeatInterval_(intptr_t  instancePtr, int  iHeartbeatInterval)
{
  TRACE("((intptr_t )%p, (int )%d)\n", instancePtr, iHeartbeatInterval);
  SteamAPI_ISteamGameServer_SetHeartbeatInterval(instancePtr, iHeartbeatInterval);
  
}


void  SteamAPI_ISteamGameServer_ForceHeartbeat_(intptr_t  instancePtr)
{
  TRACE("((intptr_t )%p)\n", instancePtr);
  SteamAPI_ISteamGameServer_ForceHeartbeat(instancePtr);
  
}


SteamAPICall_t  SteamAPI_ISteamGameServer_AssociateWithClan_(intptr_t  instancePtr, CSteamID  steamIDClan)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDClan);
  auto result = SteamAPI_ISteamGameServer_AssociateWithClan(instancePtr, steamIDClan);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamGameServer_ComputeNewPlayerCompatibility_(intptr_t  instancePtr, CSteamID  steamIDNewPlayer)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDNewPlayer);
  auto result = SteamAPI_ISteamGameServer_ComputeNewPlayerCompatibility(instancePtr, steamIDNewPlayer);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamGameServerStats_RequestUserStats_(intptr_t  instancePtr, CSteamID  steamIDUser)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDUser);
  auto result = SteamAPI_ISteamGameServerStats_RequestUserStats(instancePtr, steamIDUser);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  SteamAPI_ISteamGameServerStats_GetUserStat_(intptr_t  instancePtr, CSteamID  steamIDUser, char * pchName, int32 * pData)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (char *)\"%s\", (int32 *)%d)\n", instancePtr, steamIDUser, pchName, pData);
  auto result = SteamAPI_ISteamGameServerStats_GetUserStat(instancePtr, steamIDUser, pchName, pData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamGameServerStats_GetUserStat0_(intptr_t  instancePtr, CSteamID  steamIDUser, char * pchName, float * pData)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (char *)\"%s\", (float *)%f)\n", instancePtr, steamIDUser, pchName, pData);
  auto result = SteamAPI_ISteamGameServerStats_GetUserStat0(instancePtr, steamIDUser, pchName, pData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamGameServerStats_GetUserAchievement_(intptr_t  instancePtr, CSteamID  steamIDUser, char * pchName, bool * pbAchieved)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (char *)\"%s\", (bool *)%d)\n", instancePtr, steamIDUser, pchName, pbAchieved);
  auto result = SteamAPI_ISteamGameServerStats_GetUserAchievement(instancePtr, steamIDUser, pchName, pbAchieved);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamGameServerStats_SetUserStat_(intptr_t  instancePtr, CSteamID  steamIDUser, char * pchName, int32  nData)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (char *)\"%s\", (int32 )%d)\n", instancePtr, steamIDUser, pchName, nData);
  auto result = SteamAPI_ISteamGameServerStats_SetUserStat(instancePtr, steamIDUser, pchName, nData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamGameServerStats_SetUserStat0_(intptr_t  instancePtr, CSteamID  steamIDUser, char * pchName, float  fData)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (char *)\"%s\", (float )%f)\n", instancePtr, steamIDUser, pchName, fData);
  auto result = SteamAPI_ISteamGameServerStats_SetUserStat0(instancePtr, steamIDUser, pchName, fData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamGameServerStats_UpdateUserAvgRateStat_(intptr_t  instancePtr, CSteamID  steamIDUser, char * pchName, float  flCountThisSession, double  dSessionLength)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (char *)\"%s\", (float )%f, (double )%f)\n", instancePtr, steamIDUser, pchName, flCountThisSession, dSessionLength);
  auto result = SteamAPI_ISteamGameServerStats_UpdateUserAvgRateStat(instancePtr, steamIDUser, pchName, flCountThisSession, dSessionLength);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamGameServerStats_SetUserAchievement_(intptr_t  instancePtr, CSteamID  steamIDUser, char * pchName)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (char *)\"%s\")\n", instancePtr, steamIDUser, pchName);
  auto result = SteamAPI_ISteamGameServerStats_SetUserAchievement(instancePtr, steamIDUser, pchName);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  SteamAPI_ISteamGameServerStats_ClearUserAchievement_(intptr_t  instancePtr, CSteamID  steamIDUser, char * pchName)
{
  TRACE("((intptr_t )%p, (CSteamID )%p, (char *)\"%s\")\n", instancePtr, steamIDUser, pchName);
  auto result = SteamAPI_ISteamGameServerStats_ClearUserAchievement(instancePtr, steamIDUser, pchName);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  SteamAPI_ISteamGameServerStats_StoreUserStats_(intptr_t  instancePtr, CSteamID  steamIDUser)
{
  TRACE("((intptr_t )%p, (CSteamID )%p)\n", instancePtr, steamIDUser);
  auto result = SteamAPI_ISteamGameServerStats_StoreUserStats(instancePtr, steamIDUser);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}

}
