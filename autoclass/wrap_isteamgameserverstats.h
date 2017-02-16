#ifndef WRAP_ISTEAMGAMESERVERSTATS_H
#define WRAP_ISTEAMGAMESERVERSTATS_H
#include "steam_api.h"
class ISteamGameServerStats_ 
{
  virtual SteamAPICall_t RequestUserStats( CSteamID steamIDUser ) __attribute__((thiscall));
  virtual bool GetUserStat( CSteamID steamIDUser, const char *pchName, int32 *pData ) __attribute__((thiscall));
  virtual bool GetUserStat( CSteamID steamIDUser, const char *pchName, float *pData ) __attribute__((thiscall));
  virtual bool GetUserAchievement( CSteamID steamIDUser, const char *pchName, bool *pbAchieved ) __attribute__((thiscall));
  virtual bool SetUserStat( CSteamID steamIDUser, const char *pchName, int32 nData ) __attribute__((thiscall));
  virtual bool SetUserStat( CSteamID steamIDUser, const char *pchName, float fData ) __attribute__((thiscall));
  virtual bool UpdateUserAvgRateStat( CSteamID steamIDUser, const char *pchName, float flCountThisSession, double dSessionLength ) __attribute__((thiscall));
  virtual bool SetUserAchievement( CSteamID steamIDUser, const char *pchName ) __attribute__((thiscall));
  virtual bool ClearUserAchievement( CSteamID steamIDUser, const char *pchName ) __attribute__((thiscall));
  virtual SteamAPICall_t StoreUserStats( CSteamID steamIDUser ) __attribute__((thiscall));
  public:
    ISteamGameServerStats *internal;
};
#endif
