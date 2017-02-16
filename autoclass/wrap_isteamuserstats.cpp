#ifndef WRAP_ISTEAMUSERSTATS_CPP
#define WRAP_ISTEAMUSERSTATS_CPP
#include "autoclass/steam_api_.h" 
#include "windef.h"
#include "wine/debug.h"
#include "config.h"
bool ISteamUserStats_::RequestCurrentStats()
{
  TRACE("((this[ISteamUserStats])%p)\n", this);
  bool result = this->internal->RequestCurrentStats();
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUserStats_::GetStat( const char *pchName, int32 *pData )
{
  TRACE("((this[ISteamUserStats])%p, (const char *)\"%s\", (int32 *)%p)\n", this, pchName, pData);
  bool result = this->internal->GetStat(pchName, pData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUserStats_::GetStat( const char *pchName, float *pData )
{
  TRACE("((this[ISteamUserStats])%p, (const char *)\"%s\", (float *)%f)\n", this, pchName, pData);
  bool result = this->internal->GetStat(pchName, pData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUserStats_::SetStat( const char *pchName, int32 nData )
{
  TRACE("((this[ISteamUserStats])%p, (const char *)\"%s\", (int32)%d)\n", this, pchName, nData);
  bool result = this->internal->SetStat(pchName, nData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUserStats_::SetStat( const char *pchName, float fData )
{
  TRACE("((this[ISteamUserStats])%p, (const char *)\"%s\", (float)%f)\n", this, pchName, fData);
  bool result = this->internal->SetStat(pchName, fData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUserStats_::UpdateAvgRateStat( const char *pchName, float flCountThisSession, double dSessionLength )
{
  TRACE("((this[ISteamUserStats])%p, (const char *)\"%s\", (float)%f, (double)%p)\n", this, pchName, flCountThisSession, dSessionLength);
  bool result = this->internal->UpdateAvgRateStat(pchName, flCountThisSession, dSessionLength);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUserStats_::GetAchievement( const char *pchName, bool *pbAchieved )
{
  TRACE("((this[ISteamUserStats])%p, (const char *)\"%s\", (bool *)%p)\n", this, pchName, pbAchieved);
  bool result = this->internal->GetAchievement(pchName, pbAchieved);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUserStats_::SetAchievement( const char *pchName )
{
  TRACE("((this[ISteamUserStats])%p, (const char *)\"%s\")\n", this, pchName);
  bool result = this->internal->SetAchievement(pchName);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUserStats_::ClearAchievement( const char *pchName )
{
  TRACE("((this[ISteamUserStats])%p, (const char *)\"%s\")\n", this, pchName);
  bool result = this->internal->ClearAchievement(pchName);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUserStats_::GetAchievementAndUnlockTime( const char *pchName, bool *pbAchieved, uint32 *punUnlockTime )
{
  TRACE("((this[ISteamUserStats])%p, (const char *)\"%s\", (bool *)%p, (uint32 *)%p)\n", this, pchName, pbAchieved, punUnlockTime);
  bool result = this->internal->GetAchievementAndUnlockTime(pchName, pbAchieved, punUnlockTime);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUserStats_::StoreStats()
{
  TRACE("((this[ISteamUserStats])%p)\n", this);
  bool result = this->internal->StoreStats();
  TRACE(" = (bool)%d\n", result);
  return result;
}
int ISteamUserStats_::GetAchievementIcon( const char *pchName )
{
  TRACE("((this[ISteamUserStats])%p, (const char *)\"%s\")\n", this, pchName);
  int result = this->internal->GetAchievementIcon(pchName);
  TRACE(" = (int)%d\n", result);
  return result;
}
const char * ISteamUserStats_::GetAchievementDisplayAttribute( const char *pchName, const char *pchKey )
{
  TRACE("((this[ISteamUserStats])%p, (const char *)\"%s\", (const char *)\"%s\")\n", this, pchName, pchKey);
  const char * result = this->internal->GetAchievementDisplayAttribute(pchName, pchKey);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
bool ISteamUserStats_::IndicateAchievementProgress( const char *pchName, uint32 nCurProgress, uint32 nMaxProgress )
{
  TRACE("((this[ISteamUserStats])%p, (const char *)\"%s\", (uint32)%d, (uint32)%d)\n", this, pchName, nCurProgress, nMaxProgress);
  bool result = this->internal->IndicateAchievementProgress(pchName, nCurProgress, nMaxProgress);
  TRACE(" = (bool)%d\n", result);
  return result;
}
uint32 ISteamUserStats_::GetNumAchievements()
{
  TRACE("((this[ISteamUserStats])%p)\n", this);
  uint32 result = this->internal->GetNumAchievements();
  TRACE(" = (uint32)%d\n", result);
  return result;
}
const char * ISteamUserStats_::GetAchievementName( uint32 iAchievement )
{
  TRACE("((this[ISteamUserStats])%p, (uint32)%d)\n", this, iAchievement);
  const char * result = this->internal->GetAchievementName(iAchievement);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
SteamAPICall_t ISteamUserStats_::RequestUserStats( CSteamID steamIDUser )
{
  TRACE("((this[ISteamUserStats])%p, (CSteamID)%p)\n", this, steamIDUser);
  SteamAPICall_t result = this->internal->RequestUserStats(steamIDUser);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
bool ISteamUserStats_::GetUserStat( CSteamID steamIDUser, const char *pchName, int32 *pData )
{
  TRACE("((this[ISteamUserStats])%p, (CSteamID)%p, (const char *)\"%s\", (int32 *)%p)\n", this, steamIDUser, pchName, pData);
  bool result = this->internal->GetUserStat(steamIDUser, pchName, pData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUserStats_::GetUserStat( CSteamID steamIDUser, const char *pchName, float *pData )
{
  TRACE("((this[ISteamUserStats])%p, (CSteamID)%p, (const char *)\"%s\", (float *)%f)\n", this, steamIDUser, pchName, pData);
  bool result = this->internal->GetUserStat(steamIDUser, pchName, pData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUserStats_::GetUserAchievement( CSteamID steamIDUser, const char *pchName, bool *pbAchieved )
{
  TRACE("((this[ISteamUserStats])%p, (CSteamID)%p, (const char *)\"%s\", (bool *)%p)\n", this, steamIDUser, pchName, pbAchieved);
  bool result = this->internal->GetUserAchievement(steamIDUser, pchName, pbAchieved);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUserStats_::GetUserAchievementAndUnlockTime( CSteamID steamIDUser, const char *pchName, bool *pbAchieved, uint32 *punUnlockTime )
{
  TRACE("((this[ISteamUserStats])%p, (CSteamID)%p, (const char *)\"%s\", (bool *)%p, (uint32 *)%p)\n", this, steamIDUser, pchName, pbAchieved, punUnlockTime);
  bool result = this->internal->GetUserAchievementAndUnlockTime(steamIDUser, pchName, pbAchieved, punUnlockTime);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUserStats_::ResetAllStats( bool bAchievementsToo )
{
  TRACE("((this[ISteamUserStats])%p, (bool)%d)\n", this, bAchievementsToo);
  bool result = this->internal->ResetAllStats(bAchievementsToo);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t ISteamUserStats_::FindOrCreateLeaderboard( const char *pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType )
{
  TRACE("((this[ISteamUserStats])%p, (const char *)\"%s\", (ELeaderboardSortMethod)%p, (ELeaderboardDisplayType)%p)\n", this, pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType);
  SteamAPICall_t result = this->internal->FindOrCreateLeaderboard(pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t ISteamUserStats_::FindLeaderboard( const char *pchLeaderboardName )
{
  TRACE("((this[ISteamUserStats])%p, (const char *)\"%s\")\n", this, pchLeaderboardName);
  SteamAPICall_t result = this->internal->FindLeaderboard(pchLeaderboardName);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
const char * ISteamUserStats_::GetLeaderboardName( SteamLeaderboard_t hSteamLeaderboard )
{
  TRACE("((this[ISteamUserStats])%p, (SteamLeaderboard_t)%p)\n", this, hSteamLeaderboard);
  const char * result = this->internal->GetLeaderboardName(hSteamLeaderboard);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
int ISteamUserStats_::GetLeaderboardEntryCount( SteamLeaderboard_t hSteamLeaderboard )
{
  TRACE("((this[ISteamUserStats])%p, (SteamLeaderboard_t)%p)\n", this, hSteamLeaderboard);
  int result = this->internal->GetLeaderboardEntryCount(hSteamLeaderboard);
  TRACE(" = (int)%d\n", result);
  return result;
}
ELeaderboardSortMethod ISteamUserStats_::GetLeaderboardSortMethod( SteamLeaderboard_t hSteamLeaderboard )
{
  TRACE("((this[ISteamUserStats])%p, (SteamLeaderboard_t)%p)\n", this, hSteamLeaderboard);
  ELeaderboardSortMethod result = this->internal->GetLeaderboardSortMethod(hSteamLeaderboard);
  TRACE(" = (ELeaderboardSortMethod)%p\n", result);
  return result;
}
ELeaderboardDisplayType ISteamUserStats_::GetLeaderboardDisplayType( SteamLeaderboard_t hSteamLeaderboard )
{
  TRACE("((this[ISteamUserStats])%p, (SteamLeaderboard_t)%p)\n", this, hSteamLeaderboard);
  ELeaderboardDisplayType result = this->internal->GetLeaderboardDisplayType(hSteamLeaderboard);
  TRACE(" = (ELeaderboardDisplayType)%p\n", result);
  return result;
}
SteamAPICall_t ISteamUserStats_::DownloadLeaderboardEntries( SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd )
{
  TRACE("((this[ISteamUserStats])%p, (SteamLeaderboard_t)%p, (ELeaderboardDataRequest)%p, (int)%d, (int)%d)\n", this, hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd);
  SteamAPICall_t result = this->internal->DownloadLeaderboardEntries(hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
bool ISteamUserStats_::GetDownloadedLeaderboardEntry( SteamLeaderboardEntries_t hSteamLeaderboardEntries, int index, LeaderboardEntry_t *pLeaderboardEntry, int32 *pDetails, int cDetailsMax )
{
  TRACE("((this[ISteamUserStats])%p, (SteamLeaderboardEntries_t)%p, (int)%d, (LeaderboardEntry_t *)%p, (int32 *)%p, (int)%d)\n", this, hSteamLeaderboardEntries, index, pLeaderboardEntry, pDetails, cDetailsMax);
  bool result = this->internal->GetDownloadedLeaderboardEntry(hSteamLeaderboardEntries, index, pLeaderboardEntry, pDetails, cDetailsMax);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t ISteamUserStats_::UploadLeaderboardScore( SteamLeaderboard_t hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int32 nScore, const int32 *pScoreDetails, int cScoreDetailsCount )
{
  TRACE("((this[ISteamUserStats])%p, (SteamLeaderboard_t)%p, (ELeaderboardUploadScoreMethod)%p, (int32)%d, (const int32 *)%p, (int)%d)\n", this, hSteamLeaderboard, eLeaderboardUploadScoreMethod, nScore, pScoreDetails, cScoreDetailsCount);
  SteamAPICall_t result = this->internal->UploadLeaderboardScore(hSteamLeaderboard, eLeaderboardUploadScoreMethod, nScore, pScoreDetails, cScoreDetailsCount);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t ISteamUserStats_::AttachLeaderboardUGC( SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC )
{
  TRACE("((this[ISteamUserStats])%p, (SteamLeaderboard_t)%p, (UGCHandle_t)%p)\n", this, hSteamLeaderboard, hUGC);
  SteamAPICall_t result = this->internal->AttachLeaderboardUGC(hSteamLeaderboard, hUGC);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t ISteamUserStats_::GetNumberOfCurrentPlayers()
{
  TRACE("((this[ISteamUserStats])%p)\n", this);
  SteamAPICall_t result = this->internal->GetNumberOfCurrentPlayers();
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t ISteamUserStats_::RequestGlobalAchievementPercentages()
{
  TRACE("((this[ISteamUserStats])%p)\n", this);
  SteamAPICall_t result = this->internal->RequestGlobalAchievementPercentages();
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
int ISteamUserStats_::GetMostAchievedAchievementInfo( char *pchName, uint32 unNameBufLen, float *pflPercent, bool *pbAchieved )
{
  TRACE("((this[ISteamUserStats])%p, (char *)%p, (uint32)%d, (float *)%f, (bool *)%p)\n", this, pchName, unNameBufLen, pflPercent, pbAchieved);
  int result = this->internal->GetMostAchievedAchievementInfo(pchName, unNameBufLen, pflPercent, pbAchieved);
  TRACE(" = (int)%d\n", result);
  return result;
}
int ISteamUserStats_::GetNextMostAchievedAchievementInfo( int iIteratorPrevious, char *pchName, uint32 unNameBufLen, float *pflPercent, bool *pbAchieved )
{
  TRACE("((this[ISteamUserStats])%p, (int)%d, (char *)%p, (uint32)%d, (float *)%f, (bool *)%p)\n", this, iIteratorPrevious, pchName, unNameBufLen, pflPercent, pbAchieved);
  int result = this->internal->GetNextMostAchievedAchievementInfo(iIteratorPrevious, pchName, unNameBufLen, pflPercent, pbAchieved);
  TRACE(" = (int)%d\n", result);
  return result;
}
bool ISteamUserStats_::GetAchievementAchievedPercent( const char *pchName, float *pflPercent )
{
  TRACE("((this[ISteamUserStats])%p, (const char *)\"%s\", (float *)%f)\n", this, pchName, pflPercent);
  bool result = this->internal->GetAchievementAchievedPercent(pchName, pflPercent);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t ISteamUserStats_::RequestGlobalStats( int nHistoryDays )
{
  TRACE("((this[ISteamUserStats])%p, (int)%d)\n", this, nHistoryDays);
  SteamAPICall_t result = this->internal->RequestGlobalStats(nHistoryDays);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
bool ISteamUserStats_::GetGlobalStat( const char *pchStatName, int64 *pData )
{
  TRACE("((this[ISteamUserStats])%p, (const char *)\"%s\", (int64 *)%p)\n", this, pchStatName, pData);
  bool result = this->internal->GetGlobalStat(pchStatName, pData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUserStats_::GetGlobalStat( const char *pchStatName, double *pData )
{
  TRACE("((this[ISteamUserStats])%p, (const char *)\"%s\", (double *)%p)\n", this, pchStatName, pData);
  bool result = this->internal->GetGlobalStat(pchStatName, pData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int32 ISteamUserStats_::GetGlobalStatHistory( const char *pchStatName, ARRAY_COUNT(cubData) int64 *pData, uint32 cubData )
{
  TRACE("((this[ISteamUserStats])%p, (const char *)\"%s\", (int64 *)%p, (uint32)%d)\n", this, pchStatName, pData, cubData);
  int32 result = this->internal->GetGlobalStatHistory(pchStatName, pData, cubData);
  TRACE(" = (int32)%d\n", result);
  return result;
}
int32 ISteamUserStats_::GetGlobalStatHistory( const char *pchStatName, ARRAY_COUNT(cubData) double *pData, uint32 cubData )
{
  TRACE("((this[ISteamUserStats])%p, (const char *)\"%s\", (double *)%p, (uint32)%d)\n", this, pchStatName, pData, cubData);
  int32 result = this->internal->GetGlobalStatHistory(pchStatName, pData, cubData);
  TRACE(" = (int32)%d\n", result);
  return result;
}
#endif
