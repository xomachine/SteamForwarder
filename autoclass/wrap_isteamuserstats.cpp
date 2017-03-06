#include <steam_api_.h>

bool  ISteamUserStats_::RequestCurrentStats()
{
  TRACE("((ISteamUserStats *)%p)\n", this);
  auto result = this->internal->RequestCurrentStats();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUserStats_::GetStat(char * pchName, int32 * pData)
{
  TRACE("((ISteamUserStats *)%p, (char *)\"%s\", (int32 *)%d)\n", this, pchName, pData);
  auto result = this->internal->GetStat(pchName, pData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUserStats_::GetStat(char * pchName, float * pData)
{
  TRACE("((ISteamUserStats *)%p, (char *)\"%s\", (float *)%f)\n", this, pchName, pData);
  auto result = this->internal->GetStat(pchName, pData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUserStats_::SetStat(char * pchName, int32  nData)
{
  TRACE("((ISteamUserStats *)%p, (char *)\"%s\", (int32 )%d)\n", this, pchName, nData);
  auto result = this->internal->SetStat(pchName, nData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUserStats_::SetStat(char * pchName, float  fData)
{
  TRACE("((ISteamUserStats *)%p, (char *)\"%s\", (float )%f)\n", this, pchName, fData);
  auto result = this->internal->SetStat(pchName, fData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUserStats_::UpdateAvgRateStat(char * pchName, float  flCountThisSession, double  dSessionLength)
{
  TRACE("((ISteamUserStats *)%p, (char *)\"%s\", (float )%f, (double )%f)\n", this, pchName, flCountThisSession, dSessionLength);
  auto result = this->internal->UpdateAvgRateStat(pchName, flCountThisSession, dSessionLength);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUserStats_::GetAchievement(char * pchName, bool * pbAchieved)
{
  TRACE("((ISteamUserStats *)%p, (char *)\"%s\", (bool *)%d)\n", this, pchName, pbAchieved);
  auto result = this->internal->GetAchievement(pchName, pbAchieved);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUserStats_::SetAchievement(char * pchName)
{
  TRACE("((ISteamUserStats *)%p, (char *)\"%s\")\n", this, pchName);
  auto result = this->internal->SetAchievement(pchName);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUserStats_::ClearAchievement(char * pchName)
{
  TRACE("((ISteamUserStats *)%p, (char *)\"%s\")\n", this, pchName);
  auto result = this->internal->ClearAchievement(pchName);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUserStats_::GetAchievementAndUnlockTime(char * pchName, bool * pbAchieved, uint32 * punUnlockTime)
{
  TRACE("((ISteamUserStats *)%p, (char *)\"%s\", (bool *)%d, (uint32 *)%d)\n", this, pchName, pbAchieved, punUnlockTime);
  auto result = this->internal->GetAchievementAndUnlockTime(pchName, pbAchieved, punUnlockTime);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUserStats_::StoreStats()
{
  TRACE("((ISteamUserStats *)%p)\n", this);
  auto result = this->internal->StoreStats();
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  ISteamUserStats_::GetAchievementIcon(char * pchName)
{
  TRACE("((ISteamUserStats *)%p, (char *)\"%s\")\n", this, pchName);
  auto result = this->internal->GetAchievementIcon(pchName);
  TRACE("() = (int )%d\n", result);

  return result;
}


char * ISteamUserStats_::GetAchievementDisplayAttribute(char * pchName, char * pchKey)
{
  TRACE("((ISteamUserStats *)%p, (char *)\"%s\", (char *)\"%s\")\n", this, pchName, pchKey);
  auto result = this->internal->GetAchievementDisplayAttribute(pchName, pchKey);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


bool  ISteamUserStats_::IndicateAchievementProgress(char * pchName, uint32  nCurProgress, uint32  nMaxProgress)
{
  TRACE("((ISteamUserStats *)%p, (char *)\"%s\", (uint32 )%d, (uint32 )%d)\n", this, pchName, nCurProgress, nMaxProgress);
  auto result = this->internal->IndicateAchievementProgress(pchName, nCurProgress, nMaxProgress);
  TRACE("() = (bool )%d\n", result);

  return result;
}


uint32  ISteamUserStats_::GetNumAchievements()
{
  TRACE("((ISteamUserStats *)%p)\n", this);
  auto result = this->internal->GetNumAchievements();
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


char * ISteamUserStats_::GetAchievementName(uint32  iAchievement)
{
  TRACE("((ISteamUserStats *)%p, (uint32 )%d)\n", this, iAchievement);
  auto result = this->internal->GetAchievementName(iAchievement);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


SteamAPICall_t  ISteamUserStats_::RequestUserStats(CSteamID  steamIDUser)
{
  TRACE("((ISteamUserStats *)%p, (CSteamID )%p)\n", this, steamIDUser);
  auto result = this->internal->RequestUserStats(steamIDUser);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  ISteamUserStats_::GetUserStat(CSteamID  steamIDUser, char * pchName, int32 * pData)
{
  TRACE("((ISteamUserStats *)%p, (CSteamID )%p, (char *)\"%s\", (int32 *)%d)\n", this, steamIDUser, pchName, pData);
  auto result = this->internal->GetUserStat(steamIDUser, pchName, pData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUserStats_::GetUserStat(CSteamID  steamIDUser, char * pchName, float * pData)
{
  TRACE("((ISteamUserStats *)%p, (CSteamID )%p, (char *)\"%s\", (float *)%f)\n", this, steamIDUser, pchName, pData);
  auto result = this->internal->GetUserStat(steamIDUser, pchName, pData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUserStats_::GetUserAchievement(CSteamID  steamIDUser, char * pchName, bool * pbAchieved)
{
  TRACE("((ISteamUserStats *)%p, (CSteamID )%p, (char *)\"%s\", (bool *)%d)\n", this, steamIDUser, pchName, pbAchieved);
  auto result = this->internal->GetUserAchievement(steamIDUser, pchName, pbAchieved);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUserStats_::GetUserAchievementAndUnlockTime(CSteamID  steamIDUser, char * pchName, bool * pbAchieved, uint32 * punUnlockTime)
{
  TRACE("((ISteamUserStats *)%p, (CSteamID )%p, (char *)\"%s\", (bool *)%d, (uint32 *)%d)\n", this, steamIDUser, pchName, pbAchieved, punUnlockTime);
  auto result = this->internal->GetUserAchievementAndUnlockTime(steamIDUser, pchName, pbAchieved, punUnlockTime);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUserStats_::ResetAllStats(bool  bAchievementsToo)
{
  TRACE("((ISteamUserStats *)%p, (bool )%d)\n", this, bAchievementsToo);
  auto result = this->internal->ResetAllStats(bAchievementsToo);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  ISteamUserStats_::FindOrCreateLeaderboard(char * pchLeaderboardName, ELeaderboardSortMethod  eLeaderboardSortMethod, ELeaderboardDisplayType  eLeaderboardDisplayType)
{
  TRACE("((ISteamUserStats *)%p, (char *)\"%s\", (ELeaderboardSortMethod )%p, (ELeaderboardDisplayType )%p)\n", this, pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType);
  auto result = this->internal->FindOrCreateLeaderboard(pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamUserStats_::FindLeaderboard(char * pchLeaderboardName)
{
  TRACE("((ISteamUserStats *)%p, (char *)\"%s\")\n", this, pchLeaderboardName);
  auto result = this->internal->FindLeaderboard(pchLeaderboardName);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


char * ISteamUserStats_::GetLeaderboardName(SteamLeaderboard_t  hSteamLeaderboard)
{
  TRACE("((ISteamUserStats *)%p, (SteamLeaderboard_t )%p)\n", this, hSteamLeaderboard);
  auto result = this->internal->GetLeaderboardName(hSteamLeaderboard);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


int  ISteamUserStats_::GetLeaderboardEntryCount(SteamLeaderboard_t  hSteamLeaderboard)
{
  TRACE("((ISteamUserStats *)%p, (SteamLeaderboard_t )%p)\n", this, hSteamLeaderboard);
  auto result = this->internal->GetLeaderboardEntryCount(hSteamLeaderboard);
  TRACE("() = (int )%d\n", result);

  return result;
}


ELeaderboardSortMethod  ISteamUserStats_::GetLeaderboardSortMethod(SteamLeaderboard_t  hSteamLeaderboard)
{
  TRACE("((ISteamUserStats *)%p, (SteamLeaderboard_t )%p)\n", this, hSteamLeaderboard);
  auto result = this->internal->GetLeaderboardSortMethod(hSteamLeaderboard);
  TRACE("() = (ELeaderboardSortMethod )%p\n", result);

  return result;
}


ELeaderboardDisplayType  ISteamUserStats_::GetLeaderboardDisplayType(SteamLeaderboard_t  hSteamLeaderboard)
{
  TRACE("((ISteamUserStats *)%p, (SteamLeaderboard_t )%p)\n", this, hSteamLeaderboard);
  auto result = this->internal->GetLeaderboardDisplayType(hSteamLeaderboard);
  TRACE("() = (ELeaderboardDisplayType )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamUserStats_::DownloadLeaderboardEntries(SteamLeaderboard_t  hSteamLeaderboard, ELeaderboardDataRequest  eLeaderboardDataRequest, int  nRangeStart, int  nRangeEnd)
{
  TRACE("((ISteamUserStats *)%p, (SteamLeaderboard_t )%p, (ELeaderboardDataRequest )%p, (int )%d, (int )%d)\n", this, hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd);
  auto result = this->internal->DownloadLeaderboardEntries(hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamUserStats_::DownloadLeaderboardEntriesForUsers(SteamLeaderboard_t  hSteamLeaderboard, CSteamID * prgUsers, int  cUsers)
{
  TRACE("((ISteamUserStats *)%p, (SteamLeaderboard_t )%p, (CSteamID *)%p, (int )%d)\n", this, hSteamLeaderboard, prgUsers, cUsers);
  auto result = this->internal->DownloadLeaderboardEntriesForUsers(hSteamLeaderboard, prgUsers, cUsers);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  ISteamUserStats_::GetDownloadedLeaderboardEntry(SteamLeaderboardEntries_t  hSteamLeaderboardEntries, int  index, LeaderboardEntry_t * pLeaderboardEntry, int32 * pDetails, int  cDetailsMax)
{
  TRACE("((ISteamUserStats *)%p, (SteamLeaderboardEntries_t )%p, (int )%d, (LeaderboardEntry_t *)%p, (int32 *)%d, (int )%d)\n", this, hSteamLeaderboardEntries, index, pLeaderboardEntry, pDetails, cDetailsMax);
  auto result = this->internal->GetDownloadedLeaderboardEntry(hSteamLeaderboardEntries, index, pLeaderboardEntry, pDetails, cDetailsMax);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  ISteamUserStats_::UploadLeaderboardScore(SteamLeaderboard_t  hSteamLeaderboard, ELeaderboardUploadScoreMethod  eLeaderboardUploadScoreMethod, int32  nScore, int32 * pScoreDetails, int  cScoreDetailsCount)
{
  TRACE("((ISteamUserStats *)%p, (SteamLeaderboard_t )%p, (ELeaderboardUploadScoreMethod )%p, (int32 )%d, (int32 *)%d, (int )%d)\n", this, hSteamLeaderboard, eLeaderboardUploadScoreMethod, nScore, pScoreDetails, cScoreDetailsCount);
  auto result = this->internal->UploadLeaderboardScore(hSteamLeaderboard, eLeaderboardUploadScoreMethod, nScore, pScoreDetails, cScoreDetailsCount);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamUserStats_::AttachLeaderboardUGC(SteamLeaderboard_t  hSteamLeaderboard, UGCHandle_t  hUGC)
{
  TRACE("((ISteamUserStats *)%p, (SteamLeaderboard_t )%p, (UGCHandle_t )%p)\n", this, hSteamLeaderboard, hUGC);
  auto result = this->internal->AttachLeaderboardUGC(hSteamLeaderboard, hUGC);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamUserStats_::GetNumberOfCurrentPlayers()
{
  TRACE("((ISteamUserStats *)%p)\n", this);
  auto result = this->internal->GetNumberOfCurrentPlayers();
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamUserStats_::RequestGlobalAchievementPercentages()
{
  TRACE("((ISteamUserStats *)%p)\n", this);
  auto result = this->internal->RequestGlobalAchievementPercentages();
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


int  ISteamUserStats_::GetMostAchievedAchievementInfo(char * pchName, uint32  unNameBufLen, float * pflPercent, bool * pbAchieved)
{
  TRACE("((ISteamUserStats *)%p, (char *)\"%s\", (uint32 )%d, (float *)%f, (bool *)%d)\n", this, pchName, unNameBufLen, pflPercent, pbAchieved);
  auto result = this->internal->GetMostAchievedAchievementInfo(pchName, unNameBufLen, pflPercent, pbAchieved);
  TRACE("() = (int )%d\n", result);

  return result;
}


int  ISteamUserStats_::GetNextMostAchievedAchievementInfo(int  iIteratorPrevious, char * pchName, uint32  unNameBufLen, float * pflPercent, bool * pbAchieved)
{
  TRACE("((ISteamUserStats *)%p, (int )%d, (char *)\"%s\", (uint32 )%d, (float *)%f, (bool *)%d)\n", this, iIteratorPrevious, pchName, unNameBufLen, pflPercent, pbAchieved);
  auto result = this->internal->GetNextMostAchievedAchievementInfo(iIteratorPrevious, pchName, unNameBufLen, pflPercent, pbAchieved);
  TRACE("() = (int )%d\n", result);

  return result;
}


bool  ISteamUserStats_::GetAchievementAchievedPercent(char * pchName, float * pflPercent)
{
  TRACE("((ISteamUserStats *)%p, (char *)\"%s\", (float *)%f)\n", this, pchName, pflPercent);
  auto result = this->internal->GetAchievementAchievedPercent(pchName, pflPercent);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  ISteamUserStats_::RequestGlobalStats(int  nHistoryDays)
{
  TRACE("((ISteamUserStats *)%p, (int )%d)\n", this, nHistoryDays);
  auto result = this->internal->RequestGlobalStats(nHistoryDays);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  ISteamUserStats_::GetGlobalStat(char * pchStatName, int64 * pData)
{
  TRACE("((ISteamUserStats *)%p, (char *)\"%s\", (int64 *)%d)\n", this, pchStatName, pData);
  auto result = this->internal->GetGlobalStat(pchStatName, pData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUserStats_::GetGlobalStat(char * pchStatName, double * pData)
{
  TRACE("((ISteamUserStats *)%p, (char *)\"%s\", (double *)%f)\n", this, pchStatName, pData);
  auto result = this->internal->GetGlobalStat(pchStatName, pData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int32  ISteamUserStats_::GetGlobalStatHistory(char * pchStatName, int64 * pData, uint32  cubData)
{
  TRACE("((ISteamUserStats *)%p, (char *)\"%s\", (int64 *)%d, (uint32 )%d)\n", this, pchStatName, pData, cubData);
  auto result = this->internal->GetGlobalStatHistory(pchStatName, pData, cubData);
  TRACE("() = (int32 )%d\n", result);

  return result;
}


int32  ISteamUserStats_::GetGlobalStatHistory(char * pchStatName, double * pData, uint32  cubData)
{
  TRACE("((ISteamUserStats *)%p, (char *)\"%s\", (double *)%f, (uint32 )%d)\n", this, pchStatName, pData, cubData);
  auto result = this->internal->GetGlobalStatHistory(pchStatName, pData, cubData);
  TRACE("() = (int32 )%d\n", result);

  return result;
}
ISteamUserStats_::ISteamUserStats_(ISteamUserStats * towrap)
{
  this->internal = towrap;
}

ISteamUserStats_::~ISteamUserStats_()
{
  delete this->internal;
}
