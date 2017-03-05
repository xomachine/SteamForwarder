#include <steam_api_.h>
#include <isteamgameserverstats.h>
class ISteamGameServerStats_
{
public:
  virtual SteamAPICall_t  RequestUserStats(CSteamID  steamIDUser) __attribute__((thiscall));
  virtual bool  GetUserStat(CSteamID  steamIDUser, char * pchName, int32 * pData) __attribute__((thiscall));
  virtual bool  GetUserStat(CSteamID  steamIDUser, char * pchName, float * pData) __attribute__((thiscall));
  virtual bool  GetUserAchievement(CSteamID  steamIDUser, char * pchName, bool * pbAchieved) __attribute__((thiscall));
  virtual bool  SetUserStat(CSteamID  steamIDUser, char * pchName, int32  nData) __attribute__((thiscall));
  virtual bool  SetUserStat(CSteamID  steamIDUser, char * pchName, float  fData) __attribute__((thiscall));
  virtual bool  UpdateUserAvgRateStat(CSteamID  steamIDUser, char * pchName, float  flCountThisSession, double  dSessionLength) __attribute__((thiscall));
  virtual bool  SetUserAchievement(CSteamID  steamIDUser, char * pchName) __attribute__((thiscall));
  virtual bool  ClearUserAchievement(CSteamID  steamIDUser, char * pchName) __attribute__((thiscall));
  virtual SteamAPICall_t  StoreUserStats(CSteamID  steamIDUser) __attribute__((thiscall));
  ISteamGameServerStats_(ISteamGameServerStats*to_wrap);
  ~ISteamGameServerStats_();
private:
  ISteamGameServerStats * internal;
};
