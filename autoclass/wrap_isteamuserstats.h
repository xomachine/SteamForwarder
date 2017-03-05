#include <steam_api_.h>
#include <isteamuserstats.h>
class ISteamUserStats_
{
public:
  virtual bool  RequestCurrentStats() __attribute__((thiscall));
  virtual bool  GetStat(char * pchName, int32 * pData) __attribute__((thiscall));
  virtual bool  GetStat(char * pchName, float * pData) __attribute__((thiscall));
  virtual bool  SetStat(char * pchName, int32  nData) __attribute__((thiscall));
  virtual bool  SetStat(char * pchName, float  fData) __attribute__((thiscall));
  virtual bool  UpdateAvgRateStat(char * pchName, float  flCountThisSession, double  dSessionLength) __attribute__((thiscall));
  virtual bool  GetAchievement(char * pchName, bool * pbAchieved) __attribute__((thiscall));
  virtual bool  SetAchievement(char * pchName) __attribute__((thiscall));
  virtual bool  ClearAchievement(char * pchName) __attribute__((thiscall));
  virtual bool  GetAchievementAndUnlockTime(char * pchName, bool * pbAchieved, uint32 * punUnlockTime) __attribute__((thiscall));
  virtual bool  StoreStats() __attribute__((thiscall));
  virtual int  GetAchievementIcon(char * pchName) __attribute__((thiscall));
  virtual char * GetAchievementDisplayAttribute(char * pchName, char * pchKey) __attribute__((thiscall));
  virtual bool  IndicateAchievementProgress(char * pchName, uint32  nCurProgress, uint32  nMaxProgress) __attribute__((thiscall));
  virtual uint32  GetNumAchievements() __attribute__((thiscall));
  virtual char * GetAchievementName(uint32  iAchievement) __attribute__((thiscall));
  virtual SteamAPICall_t  RequestUserStats(CSteamID  steamIDUser) __attribute__((thiscall));
  virtual bool  GetUserStat(CSteamID  steamIDUser, char * pchName, int32 * pData) __attribute__((thiscall));
  virtual bool  GetUserStat(CSteamID  steamIDUser, char * pchName, float * pData) __attribute__((thiscall));
  virtual bool  GetUserAchievement(CSteamID  steamIDUser, char * pchName, bool * pbAchieved) __attribute__((thiscall));
  virtual bool  GetUserAchievementAndUnlockTime(CSteamID  steamIDUser, char * pchName, bool * pbAchieved, uint32 * punUnlockTime) __attribute__((thiscall));
  virtual bool  ResetAllStats(bool  bAchievementsToo) __attribute__((thiscall));
  virtual SteamAPICall_t  FindOrCreateLeaderboard(char * pchLeaderboardName, ELeaderboardSortMethod  eLeaderboardSortMethod, ELeaderboardDisplayType  eLeaderboardDisplayType) __attribute__((thiscall));
  virtual SteamAPICall_t  FindLeaderboard(char * pchLeaderboardName) __attribute__((thiscall));
  virtual char * GetLeaderboardName(SteamLeaderboard_t  hSteamLeaderboard) __attribute__((thiscall));
  virtual int  GetLeaderboardEntryCount(SteamLeaderboard_t  hSteamLeaderboard) __attribute__((thiscall));
  virtual ELeaderboardSortMethod  GetLeaderboardSortMethod(SteamLeaderboard_t  hSteamLeaderboard) __attribute__((thiscall));
  virtual ELeaderboardDisplayType  GetLeaderboardDisplayType(SteamLeaderboard_t  hSteamLeaderboard) __attribute__((thiscall));
  virtual SteamAPICall_t  DownloadLeaderboardEntries(SteamLeaderboard_t  hSteamLeaderboard, ELeaderboardDataRequest  eLeaderboardDataRequest, int  nRangeStart, int  nRangeEnd) __attribute__((thiscall));
  virtual SteamAPICall_t  DownloadLeaderboardEntriesForUsers(SteamLeaderboard_t  hSteamLeaderboard, CSteamID * prgUsers, int  cUsers) __attribute__((thiscall));
  virtual bool  GetDownloadedLeaderboardEntry(SteamLeaderboardEntries_t  hSteamLeaderboardEntries, int  index, LeaderboardEntry_t * pLeaderboardEntry, int32 * pDetails, int  cDetailsMax) __attribute__((thiscall));
  virtual SteamAPICall_t  UploadLeaderboardScore(SteamLeaderboard_t  hSteamLeaderboard, ELeaderboardUploadScoreMethod  eLeaderboardUploadScoreMethod, int32  nScore, int32 * pScoreDetails, int  cScoreDetailsCount) __attribute__((thiscall));
  virtual SteamAPICall_t  AttachLeaderboardUGC(SteamLeaderboard_t  hSteamLeaderboard, UGCHandle_t  hUGC) __attribute__((thiscall));
  virtual SteamAPICall_t  GetNumberOfCurrentPlayers() __attribute__((thiscall));
  virtual SteamAPICall_t  RequestGlobalAchievementPercentages() __attribute__((thiscall));
  virtual int  GetMostAchievedAchievementInfo(char * pchName, uint32  unNameBufLen, float * pflPercent, bool * pbAchieved) __attribute__((thiscall));
  virtual int  GetNextMostAchievedAchievementInfo(int  iIteratorPrevious, char * pchName, uint32  unNameBufLen, float * pflPercent, bool * pbAchieved) __attribute__((thiscall));
  virtual bool  GetAchievementAchievedPercent(char * pchName, float * pflPercent) __attribute__((thiscall));
  virtual SteamAPICall_t  RequestGlobalStats(int  nHistoryDays) __attribute__((thiscall));
  virtual bool  GetGlobalStat(char * pchStatName, int64 * pData) __attribute__((thiscall));
  virtual bool  GetGlobalStat(char * pchStatName, double * pData) __attribute__((thiscall));
  virtual int32  GetGlobalStatHistory(char * pchStatName, int64 * pData, uint32  cubData) __attribute__((thiscall));
  virtual int32  GetGlobalStatHistory(char * pchStatName, double * pData, uint32  cubData) __attribute__((thiscall));
  ISteamUserStats_(ISteamUserStats*to_wrap);
  ~ISteamUserStats_();
private:
  ISteamUserStats * internal;
};
