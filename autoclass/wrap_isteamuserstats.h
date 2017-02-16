#ifndef WRAP_ISTEAMUSERSTATS_H
#define WRAP_ISTEAMUSERSTATS_H
#include "steam_api.h"
class ISteamUserStats_ 
{
  virtual bool RequestCurrentStats() __attribute__((thiscall));
  virtual bool GetStat( const char *pchName, int32 *pData ) __attribute__((thiscall));
  virtual bool GetStat( const char *pchName, float *pData ) __attribute__((thiscall));
  virtual bool SetStat( const char *pchName, int32 nData ) __attribute__((thiscall));
  virtual bool SetStat( const char *pchName, float fData ) __attribute__((thiscall));
  virtual bool UpdateAvgRateStat( const char *pchName, float flCountThisSession, double dSessionLength ) __attribute__((thiscall));
  virtual bool GetAchievement( const char *pchName, bool *pbAchieved ) __attribute__((thiscall));
  virtual bool SetAchievement( const char *pchName ) __attribute__((thiscall));
  virtual bool ClearAchievement( const char *pchName ) __attribute__((thiscall));
  virtual bool GetAchievementAndUnlockTime( const char *pchName, bool *pbAchieved, uint32 *punUnlockTime ) __attribute__((thiscall));
  virtual bool StoreStats() __attribute__((thiscall));
  virtual int GetAchievementIcon( const char *pchName ) __attribute__((thiscall));
  virtual const char * GetAchievementDisplayAttribute( const char *pchName, const char *pchKey ) __attribute__((thiscall));
  virtual bool IndicateAchievementProgress( const char *pchName, uint32 nCurProgress, uint32 nMaxProgress ) __attribute__((thiscall));
  virtual uint32 GetNumAchievements() __attribute__((thiscall));
  virtual const char * GetAchievementName( uint32 iAchievement ) __attribute__((thiscall));
  virtual SteamAPICall_t RequestUserStats( CSteamID steamIDUser ) __attribute__((thiscall));
  virtual bool GetUserStat( CSteamID steamIDUser, const char *pchName, int32 *pData ) __attribute__((thiscall));
  virtual bool GetUserStat( CSteamID steamIDUser, const char *pchName, float *pData ) __attribute__((thiscall));
  virtual bool GetUserAchievement( CSteamID steamIDUser, const char *pchName, bool *pbAchieved ) __attribute__((thiscall));
  virtual bool GetUserAchievementAndUnlockTime( CSteamID steamIDUser, const char *pchName, bool *pbAchieved, uint32 *punUnlockTime ) __attribute__((thiscall));
  virtual bool ResetAllStats( bool bAchievementsToo ) __attribute__((thiscall));
  virtual SteamAPICall_t FindOrCreateLeaderboard( const char *pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType ) __attribute__((thiscall));
  virtual SteamAPICall_t FindLeaderboard( const char *pchLeaderboardName ) __attribute__((thiscall));
  virtual const char * GetLeaderboardName( SteamLeaderboard_t hSteamLeaderboard ) __attribute__((thiscall));
  virtual int GetLeaderboardEntryCount( SteamLeaderboard_t hSteamLeaderboard ) __attribute__((thiscall));
  virtual ELeaderboardSortMethod GetLeaderboardSortMethod( SteamLeaderboard_t hSteamLeaderboard ) __attribute__((thiscall));
  virtual ELeaderboardDisplayType GetLeaderboardDisplayType( SteamLeaderboard_t hSteamLeaderboard ) __attribute__((thiscall));
  virtual SteamAPICall_t DownloadLeaderboardEntries( SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd ) __attribute__((thiscall));
  virtual bool GetDownloadedLeaderboardEntry( SteamLeaderboardEntries_t hSteamLeaderboardEntries, int index, LeaderboardEntry_t *pLeaderboardEntry, int32 *pDetails, int cDetailsMax ) __attribute__((thiscall));
  virtual SteamAPICall_t UploadLeaderboardScore( SteamLeaderboard_t hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int32 nScore, const int32 *pScoreDetails, int cScoreDetailsCount ) __attribute__((thiscall));
  virtual SteamAPICall_t AttachLeaderboardUGC( SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC ) __attribute__((thiscall));
  virtual SteamAPICall_t GetNumberOfCurrentPlayers() __attribute__((thiscall));
  virtual SteamAPICall_t RequestGlobalAchievementPercentages() __attribute__((thiscall));
  virtual int GetMostAchievedAchievementInfo( char *pchName, uint32 unNameBufLen, float *pflPercent, bool *pbAchieved ) __attribute__((thiscall));
  virtual int GetNextMostAchievedAchievementInfo( int iIteratorPrevious, char *pchName, uint32 unNameBufLen, float *pflPercent, bool *pbAchieved ) __attribute__((thiscall));
  virtual bool GetAchievementAchievedPercent( const char *pchName, float *pflPercent ) __attribute__((thiscall));
  virtual SteamAPICall_t RequestGlobalStats( int nHistoryDays ) __attribute__((thiscall));
  virtual bool GetGlobalStat( const char *pchStatName, int64 *pData ) __attribute__((thiscall));
  virtual bool GetGlobalStat( const char *pchStatName, double *pData ) __attribute__((thiscall));
  virtual int32 GetGlobalStatHistory( const char *pchStatName, ARRAY_COUNT(cubData) int64 *pData, uint32 cubData ) __attribute__((thiscall));
  virtual int32 GetGlobalStatHistory( const char *pchStatName, ARRAY_COUNT(cubData) double *pData, uint32 cubData ) __attribute__((thiscall));
  public:
    ISteamUserStats *internal;
};
#endif
