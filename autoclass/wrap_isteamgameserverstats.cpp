#ifndef WRAP_ISTEAMGAMESERVERSTATS_CPP
#define WRAP_ISTEAMGAMESERVERSTATS_CPP
#include "autoclass/steam_api_.h" 
#include "windef.h"
#include "wine/debug.h"
#include "config.h"
SteamAPICall_t ISteamGameServerStats_::RequestUserStats( CSteamID steamIDUser )
{
  TRACE("((this[ISteamGameServerStats])%p, (CSteamID)%p)\n", this, steamIDUser);
  SteamAPICall_t result = this->internal->RequestUserStats(steamIDUser);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
bool ISteamGameServerStats_::GetUserStat( CSteamID steamIDUser, const char *pchName, int32 *pData )
{
  TRACE("((this[ISteamGameServerStats])%p, (CSteamID)%p, (const char *)\"%s\", (int32 *)%p)\n", this, steamIDUser, pchName, pData);
  bool result = this->internal->GetUserStat(steamIDUser, pchName, pData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamGameServerStats_::GetUserStat( CSteamID steamIDUser, const char *pchName, float *pData )
{
  TRACE("((this[ISteamGameServerStats])%p, (CSteamID)%p, (const char *)\"%s\", (float *)%f)\n", this, steamIDUser, pchName, pData);
  bool result = this->internal->GetUserStat(steamIDUser, pchName, pData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamGameServerStats_::GetUserAchievement( CSteamID steamIDUser, const char *pchName, bool *pbAchieved )
{
  TRACE("((this[ISteamGameServerStats])%p, (CSteamID)%p, (const char *)\"%s\", (bool *)%p)\n", this, steamIDUser, pchName, pbAchieved);
  bool result = this->internal->GetUserAchievement(steamIDUser, pchName, pbAchieved);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamGameServerStats_::SetUserStat( CSteamID steamIDUser, const char *pchName, int32 nData )
{
  TRACE("((this[ISteamGameServerStats])%p, (CSteamID)%p, (const char *)\"%s\", (int32)%d)\n", this, steamIDUser, pchName, nData);
  bool result = this->internal->SetUserStat(steamIDUser, pchName, nData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamGameServerStats_::SetUserStat( CSteamID steamIDUser, const char *pchName, float fData )
{
  TRACE("((this[ISteamGameServerStats])%p, (CSteamID)%p, (const char *)\"%s\", (float)%f)\n", this, steamIDUser, pchName, fData);
  bool result = this->internal->SetUserStat(steamIDUser, pchName, fData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamGameServerStats_::UpdateUserAvgRateStat( CSteamID steamIDUser, const char *pchName, float flCountThisSession, double dSessionLength )
{
  TRACE("((this[ISteamGameServerStats])%p, (CSteamID)%p, (const char *)\"%s\", (float)%f, (double)%p)\n", this, steamIDUser, pchName, flCountThisSession, dSessionLength);
  bool result = this->internal->UpdateUserAvgRateStat(steamIDUser, pchName, flCountThisSession, dSessionLength);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamGameServerStats_::SetUserAchievement( CSteamID steamIDUser, const char *pchName )
{
  TRACE("((this[ISteamGameServerStats])%p, (CSteamID)%p, (const char *)\"%s\")\n", this, steamIDUser, pchName);
  bool result = this->internal->SetUserAchievement(steamIDUser, pchName);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamGameServerStats_::ClearUserAchievement( CSteamID steamIDUser, const char *pchName )
{
  TRACE("((this[ISteamGameServerStats])%p, (CSteamID)%p, (const char *)\"%s\")\n", this, steamIDUser, pchName);
  bool result = this->internal->ClearUserAchievement(steamIDUser, pchName);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t ISteamGameServerStats_::StoreUserStats( CSteamID steamIDUser )
{
  TRACE("((this[ISteamGameServerStats])%p, (CSteamID)%p)\n", this, steamIDUser);
  SteamAPICall_t result = this->internal->StoreUserStats(steamIDUser);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
#endif
