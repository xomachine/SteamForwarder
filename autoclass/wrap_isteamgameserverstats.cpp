#include <steam_api_.h>

SteamAPICall_t  ISteamGameServerStats_::RequestUserStats(CSteamID  steamIDUser)
{
  TRACE("((ISteamGameServerStats *)%p, (CSteamID )%p)\n", this, steamIDUser);
  SteamAPICall_t  result = this->internal->RequestUserStats(steamIDUser);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  ISteamGameServerStats_::GetUserStat(CSteamID  steamIDUser, char * pchName, int32 * pData)
{
  TRACE("((ISteamGameServerStats *)%p, (CSteamID )%p, (char *)\"%s\", (int32 *)%d)\n", this, steamIDUser, pchName, pData);
  bool  result = this->internal->GetUserStat(steamIDUser, pchName, pData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamGameServerStats_::GetUserStat(CSteamID  steamIDUser, char * pchName, float * pData)
{
  TRACE("((ISteamGameServerStats *)%p, (CSteamID )%p, (char *)\"%s\", (float *)%f)\n", this, steamIDUser, pchName, pData);
  bool  result = this->internal->GetUserStat(steamIDUser, pchName, pData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamGameServerStats_::GetUserAchievement(CSteamID  steamIDUser, char * pchName, bool * pbAchieved)
{
  TRACE("((ISteamGameServerStats *)%p, (CSteamID )%p, (char *)\"%s\", (bool *)%d)\n", this, steamIDUser, pchName, pbAchieved);
  bool  result = this->internal->GetUserAchievement(steamIDUser, pchName, pbAchieved);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamGameServerStats_::SetUserStat(CSteamID  steamIDUser, char * pchName, int32  nData)
{
  TRACE("((ISteamGameServerStats *)%p, (CSteamID )%p, (char *)\"%s\", (int32 )%d)\n", this, steamIDUser, pchName, nData);
  bool  result = this->internal->SetUserStat(steamIDUser, pchName, nData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamGameServerStats_::SetUserStat(CSteamID  steamIDUser, char * pchName, float  fData)
{
  TRACE("((ISteamGameServerStats *)%p, (CSteamID )%p, (char *)\"%s\", (float )%f)\n", this, steamIDUser, pchName, fData);
  bool  result = this->internal->SetUserStat(steamIDUser, pchName, fData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamGameServerStats_::UpdateUserAvgRateStat(CSteamID  steamIDUser, char * pchName, float  flCountThisSession, double  dSessionLength)
{
  TRACE("((ISteamGameServerStats *)%p, (CSteamID )%p, (char *)\"%s\", (float )%f, (double )%f)\n", this, steamIDUser, pchName, flCountThisSession, dSessionLength);
  bool  result = this->internal->UpdateUserAvgRateStat(steamIDUser, pchName, flCountThisSession, dSessionLength);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamGameServerStats_::SetUserAchievement(CSteamID  steamIDUser, char * pchName)
{
  TRACE("((ISteamGameServerStats *)%p, (CSteamID )%p, (char *)\"%s\")\n", this, steamIDUser, pchName);
  bool  result = this->internal->SetUserAchievement(steamIDUser, pchName);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamGameServerStats_::ClearUserAchievement(CSteamID  steamIDUser, char * pchName)
{
  TRACE("((ISteamGameServerStats *)%p, (CSteamID )%p, (char *)\"%s\")\n", this, steamIDUser, pchName);
  bool  result = this->internal->ClearUserAchievement(steamIDUser, pchName);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  ISteamGameServerStats_::StoreUserStats(CSteamID  steamIDUser)
{
  TRACE("((ISteamGameServerStats *)%p, (CSteamID )%p)\n", this, steamIDUser);
  SteamAPICall_t  result = this->internal->StoreUserStats(steamIDUser);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}
ISteamGameServerStats_::ISteamGameServerStats_(ISteamGameServerStats * towrap)
{
  this->internal = towrap;
}

ISteamGameServerStats_::~ISteamGameServerStats_()
{
  delete this->internal;
}
