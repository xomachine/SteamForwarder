#include <steam_api_.h>

int  ISteamMatchmaking_::GetFavoriteGameCount()
{
  TRACE("((ISteamMatchmaking *)%p)\n", this);
  auto result = this->internal->GetFavoriteGameCount();
  TRACE("() = (int )%d\n", result);

  return result;
}


bool  ISteamMatchmaking_::GetFavoriteGame(int  iGame, AppId_t * pnAppID, uint32 * pnIP, uint16 * pnConnPort, uint16 * pnQueryPort, uint32 * punFlags, uint32 * pRTime32LastPlayedOnServer)
{
  TRACE("((ISteamMatchmaking *)%p, (int )%d, (AppId_t *)%p, (uint32 *)%d, (uint16 *)%d, (uint16 *)%d, (uint32 *)%d, (uint32 *)%d)\n", this, iGame, pnAppID, pnIP, pnConnPort, pnQueryPort, punFlags, pRTime32LastPlayedOnServer);
  auto result = this->internal->GetFavoriteGame(iGame, pnAppID, pnIP, pnConnPort, pnQueryPort, punFlags, pRTime32LastPlayedOnServer);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  ISteamMatchmaking_::AddFavoriteGame(AppId_t  nAppID, uint32  nIP, uint16  nConnPort, uint16  nQueryPort, uint32  unFlags, uint32  rTime32LastPlayedOnServer)
{
  TRACE("((ISteamMatchmaking *)%p, (AppId_t )%p, (uint32 )%d, (uint16 )%d, (uint16 )%d, (uint32 )%d, (uint32 )%d)\n", this, nAppID, nIP, nConnPort, nQueryPort, unFlags, rTime32LastPlayedOnServer);
  auto result = this->internal->AddFavoriteGame(nAppID, nIP, nConnPort, nQueryPort, unFlags, rTime32LastPlayedOnServer);
  TRACE("() = (int )%d\n", result);

  return result;
}


bool  ISteamMatchmaking_::RemoveFavoriteGame(AppId_t  nAppID, uint32  nIP, uint16  nConnPort, uint16  nQueryPort, uint32  unFlags)
{
  TRACE("((ISteamMatchmaking *)%p, (AppId_t )%p, (uint32 )%d, (uint16 )%d, (uint16 )%d, (uint32 )%d)\n", this, nAppID, nIP, nConnPort, nQueryPort, unFlags);
  auto result = this->internal->RemoveFavoriteGame(nAppID, nIP, nConnPort, nQueryPort, unFlags);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  ISteamMatchmaking_::RequestLobbyList()
{
  TRACE("((ISteamMatchmaking *)%p)\n", this);
  auto result = this->internal->RequestLobbyList();
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


void  ISteamMatchmaking_::AddRequestLobbyListStringFilter(char * pchKeyToMatch, char * pchValueToMatch, ELobbyComparison  eComparisonType)
{
  TRACE("((ISteamMatchmaking *)%p, (char *)\"%s\", (char *)\"%s\", (ELobbyComparison )%p)\n", this, pchKeyToMatch, pchValueToMatch, eComparisonType);
  this->internal->AddRequestLobbyListStringFilter(pchKeyToMatch, pchValueToMatch, eComparisonType);
  
}


void  ISteamMatchmaking_::AddRequestLobbyListNumericalFilter(char * pchKeyToMatch, int  nValueToMatch, ELobbyComparison  eComparisonType)
{
  TRACE("((ISteamMatchmaking *)%p, (char *)\"%s\", (int )%d, (ELobbyComparison )%p)\n", this, pchKeyToMatch, nValueToMatch, eComparisonType);
  this->internal->AddRequestLobbyListNumericalFilter(pchKeyToMatch, nValueToMatch, eComparisonType);
  
}


void  ISteamMatchmaking_::AddRequestLobbyListNearValueFilter(char * pchKeyToMatch, int  nValueToBeCloseTo)
{
  TRACE("((ISteamMatchmaking *)%p, (char *)\"%s\", (int )%d)\n", this, pchKeyToMatch, nValueToBeCloseTo);
  this->internal->AddRequestLobbyListNearValueFilter(pchKeyToMatch, nValueToBeCloseTo);
  
}


void  ISteamMatchmaking_::AddRequestLobbyListFilterSlotsAvailable(int  nSlotsAvailable)
{
  TRACE("((ISteamMatchmaking *)%p, (int )%d)\n", this, nSlotsAvailable);
  this->internal->AddRequestLobbyListFilterSlotsAvailable(nSlotsAvailable);
  
}


void  ISteamMatchmaking_::AddRequestLobbyListDistanceFilter(ELobbyDistanceFilter  eLobbyDistanceFilter)
{
  TRACE("((ISteamMatchmaking *)%p, (ELobbyDistanceFilter )%p)\n", this, eLobbyDistanceFilter);
  this->internal->AddRequestLobbyListDistanceFilter(eLobbyDistanceFilter);
  
}


void  ISteamMatchmaking_::AddRequestLobbyListResultCountFilter(int  cMaxResults)
{
  TRACE("((ISteamMatchmaking *)%p, (int )%d)\n", this, cMaxResults);
  this->internal->AddRequestLobbyListResultCountFilter(cMaxResults);
  
}


void  ISteamMatchmaking_::AddRequestLobbyListCompatibleMembersFilter(CSteamID  steamIDLobby)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p)\n", this, steamIDLobby);
  this->internal->AddRequestLobbyListCompatibleMembersFilter(steamIDLobby);
  
}


CSteamID * ISteamMatchmaking_::GetLobbyByIndex(CSteamID * hidden, int  iLobby)
{
  TRACE("((ISteamMatchmaking *)%p, (int )%d)\n", this, iLobby);
  *hidden = this->internal->GetLobbyByIndex(iLobby);
  return hidden;
}


SteamAPICall_t  ISteamMatchmaking_::CreateLobby(ELobbyType  eLobbyType, int  cMaxMembers)
{
  TRACE("((ISteamMatchmaking *)%p, (ELobbyType )%p, (int )%d)\n", this, eLobbyType, cMaxMembers);
  auto result = this->internal->CreateLobby(eLobbyType, cMaxMembers);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamMatchmaking_::JoinLobby(CSteamID  steamIDLobby)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p)\n", this, steamIDLobby);
  auto result = this->internal->JoinLobby(steamIDLobby);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


void  ISteamMatchmaking_::LeaveLobby(CSteamID  steamIDLobby)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p)\n", this, steamIDLobby);
  this->internal->LeaveLobby(steamIDLobby);
  
}


bool  ISteamMatchmaking_::InviteUserToLobby(CSteamID  steamIDLobby, CSteamID  steamIDInvitee)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p, (CSteamID )%p)\n", this, steamIDLobby, steamIDInvitee);
  auto result = this->internal->InviteUserToLobby(steamIDLobby, steamIDInvitee);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  ISteamMatchmaking_::GetNumLobbyMembers(CSteamID  steamIDLobby)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p)\n", this, steamIDLobby);
  auto result = this->internal->GetNumLobbyMembers(steamIDLobby);
  TRACE("() = (int )%d\n", result);

  return result;
}


CSteamID * ISteamMatchmaking_::GetLobbyMemberByIndex(CSteamID * hidden, CSteamID  steamIDLobby, int  iMember)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p, (int )%d)\n", this, steamIDLobby, iMember);
  *hidden = this->internal->GetLobbyMemberByIndex(steamIDLobby, iMember);
  return hidden;
}


char * ISteamMatchmaking_::GetLobbyData(CSteamID  steamIDLobby, char * pchKey)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p, (char *)\"%s\")\n", this, steamIDLobby, pchKey);
  auto result = this->internal->GetLobbyData(steamIDLobby, pchKey);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


bool  ISteamMatchmaking_::SetLobbyData(CSteamID  steamIDLobby, char * pchKey, char * pchValue)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p, (char *)\"%s\", (char *)\"%s\")\n", this, steamIDLobby, pchKey, pchValue);
  auto result = this->internal->SetLobbyData(steamIDLobby, pchKey, pchValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  ISteamMatchmaking_::GetLobbyDataCount(CSteamID  steamIDLobby)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p)\n", this, steamIDLobby);
  auto result = this->internal->GetLobbyDataCount(steamIDLobby);
  TRACE("() = (int )%d\n", result);

  return result;
}


bool  ISteamMatchmaking_::GetLobbyDataByIndex(CSteamID  steamIDLobby, int  iLobbyData, char * pchKey, int  cchKeyBufferSize, char * pchValue, int  cchValueBufferSize)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p, (int )%d, (char *)\"%s\", (int )%d, (char *)\"%s\", (int )%d)\n", this, steamIDLobby, iLobbyData, pchKey, cchKeyBufferSize, pchValue, cchValueBufferSize);
  auto result = this->internal->GetLobbyDataByIndex(steamIDLobby, iLobbyData, pchKey, cchKeyBufferSize, pchValue, cchValueBufferSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMatchmaking_::DeleteLobbyData(CSteamID  steamIDLobby, char * pchKey)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p, (char *)\"%s\")\n", this, steamIDLobby, pchKey);
  auto result = this->internal->DeleteLobbyData(steamIDLobby, pchKey);
  TRACE("() = (bool )%d\n", result);

  return result;
}


char * ISteamMatchmaking_::GetLobbyMemberData(CSteamID  steamIDLobby, CSteamID  steamIDUser, char * pchKey)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p, (CSteamID )%p, (char *)\"%s\")\n", this, steamIDLobby, steamIDUser, pchKey);
  auto result = this->internal->GetLobbyMemberData(steamIDLobby, steamIDUser, pchKey);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


void  ISteamMatchmaking_::SetLobbyMemberData(CSteamID  steamIDLobby, char * pchKey, char * pchValue)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p, (char *)\"%s\", (char *)\"%s\")\n", this, steamIDLobby, pchKey, pchValue);
  this->internal->SetLobbyMemberData(steamIDLobby, pchKey, pchValue);
  
}


bool  ISteamMatchmaking_::SendLobbyChatMsg(CSteamID  steamIDLobby, void * pvMsgBody, int  cubMsgBody)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p, (void *)%p, (int )%d)\n", this, steamIDLobby, pvMsgBody, cubMsgBody);
  auto result = this->internal->SendLobbyChatMsg(steamIDLobby, pvMsgBody, cubMsgBody);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  ISteamMatchmaking_::GetLobbyChatEntry(CSteamID  steamIDLobby, int  iChatID, CSteamID * pSteamIDUser, void * pvData, int  cubData, EChatEntryType * peChatEntryType)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p, (int )%d, (CSteamID *)%p, (void *)%p, (int )%d, (EChatEntryType *)%p)\n", this, steamIDLobby, iChatID, pSteamIDUser, pvData, cubData, peChatEntryType);
  auto result = this->internal->GetLobbyChatEntry(steamIDLobby, iChatID, pSteamIDUser, pvData, cubData, peChatEntryType);
  TRACE("() = (int )%d\n", result);

  return result;
}


bool  ISteamMatchmaking_::RequestLobbyData(CSteamID  steamIDLobby)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p)\n", this, steamIDLobby);
  auto result = this->internal->RequestLobbyData(steamIDLobby);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  ISteamMatchmaking_::SetLobbyGameServer(CSteamID  steamIDLobby, uint32  unGameServerIP, uint16  unGameServerPort, CSteamID  steamIDGameServer)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p, (uint32 )%d, (uint16 )%d, (CSteamID )%p)\n", this, steamIDLobby, unGameServerIP, unGameServerPort, steamIDGameServer);
  this->internal->SetLobbyGameServer(steamIDLobby, unGameServerIP, unGameServerPort, steamIDGameServer);
  
}


bool  ISteamMatchmaking_::GetLobbyGameServer(CSteamID  steamIDLobby, uint32 * punGameServerIP, uint16 * punGameServerPort, CSteamID * psteamIDGameServer)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p, (uint32 *)%d, (uint16 *)%d, (CSteamID *)%p)\n", this, steamIDLobby, punGameServerIP, punGameServerPort, psteamIDGameServer);
  auto result = this->internal->GetLobbyGameServer(steamIDLobby, punGameServerIP, punGameServerPort, psteamIDGameServer);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMatchmaking_::SetLobbyMemberLimit(CSteamID  steamIDLobby, int  cMaxMembers)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p, (int )%d)\n", this, steamIDLobby, cMaxMembers);
  auto result = this->internal->SetLobbyMemberLimit(steamIDLobby, cMaxMembers);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  ISteamMatchmaking_::GetLobbyMemberLimit(CSteamID  steamIDLobby)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p)\n", this, steamIDLobby);
  auto result = this->internal->GetLobbyMemberLimit(steamIDLobby);
  TRACE("() = (int )%d\n", result);

  return result;
}


bool  ISteamMatchmaking_::SetLobbyType(CSteamID  steamIDLobby, ELobbyType  eLobbyType)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p, (ELobbyType )%p)\n", this, steamIDLobby, eLobbyType);
  auto result = this->internal->SetLobbyType(steamIDLobby, eLobbyType);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMatchmaking_::SetLobbyJoinable(CSteamID  steamIDLobby, bool  bLobbyJoinable)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p, (bool )%d)\n", this, steamIDLobby, bLobbyJoinable);
  auto result = this->internal->SetLobbyJoinable(steamIDLobby, bLobbyJoinable);
  TRACE("() = (bool )%d\n", result);

  return result;
}


CSteamID * ISteamMatchmaking_::GetLobbyOwner(CSteamID * hidden, CSteamID  steamIDLobby)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p)\n", this, steamIDLobby);
  *hidden = this->internal->GetLobbyOwner(steamIDLobby);
  return hidden;
}


bool  ISteamMatchmaking_::SetLobbyOwner(CSteamID  steamIDLobby, CSteamID  steamIDNewOwner)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p, (CSteamID )%p)\n", this, steamIDLobby, steamIDNewOwner);
  auto result = this->internal->SetLobbyOwner(steamIDLobby, steamIDNewOwner);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamMatchmaking_::SetLinkedLobby(CSteamID  steamIDLobby, CSteamID  steamIDLobbyDependent)
{
  TRACE("((ISteamMatchmaking *)%p, (CSteamID )%p, (CSteamID )%p)\n", this, steamIDLobby, steamIDLobbyDependent);
  auto result = this->internal->SetLinkedLobby(steamIDLobby, steamIDLobbyDependent);
  TRACE("() = (bool )%d\n", result);

  return result;
}
ISteamMatchmaking_::ISteamMatchmaking_(ISteamMatchmaking * towrap)
{
  this->internal = towrap;
}

ISteamMatchmaking_::~ISteamMatchmaking_()
{
  delete this->internal;
}



void  ISteamMatchmakingServerListResponse_::ServerResponded(HServerListRequest  hRequest, int  iServer)
{
  TRACE("((ISteamMatchmakingServerListResponse *)%p, (HServerListRequest )%p, (int )%d)\n", this, hRequest, iServer);
  this->internal->ServerResponded(hRequest, iServer);
  
}


void  ISteamMatchmakingServerListResponse_::ServerFailedToRespond(HServerListRequest  hRequest, int  iServer)
{
  TRACE("((ISteamMatchmakingServerListResponse *)%p, (HServerListRequest )%p, (int )%d)\n", this, hRequest, iServer);
  this->internal->ServerFailedToRespond(hRequest, iServer);
  
}


void  ISteamMatchmakingServerListResponse_::RefreshComplete(HServerListRequest  hRequest, EMatchMakingServerResponse  response)
{
  TRACE("((ISteamMatchmakingServerListResponse *)%p, (HServerListRequest )%p, (EMatchMakingServerResponse )%p)\n", this, hRequest, response);
  this->internal->RefreshComplete(hRequest, response);
  
}
ISteamMatchmakingServerListResponse_::ISteamMatchmakingServerListResponse_(ISteamMatchmakingServerListResponse * towrap)
{
  this->internal = towrap;
}

ISteamMatchmakingServerListResponse_::~ISteamMatchmakingServerListResponse_()
{
  delete this->internal;
}



void  ISteamMatchmakingPingResponse_::ServerResponded(gameserveritem_t & server)
{
  TRACE("((ISteamMatchmakingPingResponse *)%p, (gameserveritem_t &)%p)\n", this, server);
  this->internal->ServerResponded(server);
  
}


void  ISteamMatchmakingPingResponse_::ServerFailedToRespond()
{
  TRACE("((ISteamMatchmakingPingResponse *)%p)\n", this);
  this->internal->ServerFailedToRespond();
  
}
ISteamMatchmakingPingResponse_::ISteamMatchmakingPingResponse_(ISteamMatchmakingPingResponse * towrap)
{
  this->internal = towrap;
}

ISteamMatchmakingPingResponse_::~ISteamMatchmakingPingResponse_()
{
  delete this->internal;
}



void  ISteamMatchmakingPlayersResponse_::AddPlayerToList(char * pchName, int  nScore, float  flTimePlayed)
{
  TRACE("((ISteamMatchmakingPlayersResponse *)%p, (char *)\"%s\", (int )%d, (float )%f)\n", this, pchName, nScore, flTimePlayed);
  this->internal->AddPlayerToList(pchName, nScore, flTimePlayed);
  
}


void  ISteamMatchmakingPlayersResponse_::PlayersFailedToRespond()
{
  TRACE("((ISteamMatchmakingPlayersResponse *)%p)\n", this);
  this->internal->PlayersFailedToRespond();
  
}


void  ISteamMatchmakingPlayersResponse_::PlayersRefreshComplete()
{
  TRACE("((ISteamMatchmakingPlayersResponse *)%p)\n", this);
  this->internal->PlayersRefreshComplete();
  
}
ISteamMatchmakingPlayersResponse_::ISteamMatchmakingPlayersResponse_(ISteamMatchmakingPlayersResponse * towrap)
{
  this->internal = towrap;
}

ISteamMatchmakingPlayersResponse_::~ISteamMatchmakingPlayersResponse_()
{
  delete this->internal;
}



void  ISteamMatchmakingRulesResponse_::RulesResponded(char * pchRule, char * pchValue)
{
  TRACE("((ISteamMatchmakingRulesResponse *)%p, (char *)\"%s\", (char *)\"%s\")\n", this, pchRule, pchValue);
  this->internal->RulesResponded(pchRule, pchValue);
  
}


void  ISteamMatchmakingRulesResponse_::RulesFailedToRespond()
{
  TRACE("((ISteamMatchmakingRulesResponse *)%p)\n", this);
  this->internal->RulesFailedToRespond();
  
}


void  ISteamMatchmakingRulesResponse_::RulesRefreshComplete()
{
  TRACE("((ISteamMatchmakingRulesResponse *)%p)\n", this);
  this->internal->RulesRefreshComplete();
  
}
ISteamMatchmakingRulesResponse_::ISteamMatchmakingRulesResponse_(ISteamMatchmakingRulesResponse * towrap)
{
  this->internal = towrap;
}

ISteamMatchmakingRulesResponse_::~ISteamMatchmakingRulesResponse_()
{
  delete this->internal;
}



HServerListRequest  ISteamMatchmakingServers_::RequestInternetServerList(AppId_t  iApp, MatchMakingKeyValuePair_t ** ppchFilters, uint32  nFilters, ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
  TRACE("((ISteamMatchmakingServers *)%p, (AppId_t )%p, (MatchMakingKeyValuePair_t **)%p, (uint32 )%d, (ISteamMatchmakingServerListResponse *)%p)\n", this, iApp, ppchFilters, nFilters, pRequestServersResponse);
  auto result = this->internal->RequestInternetServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
  TRACE("() = (HServerListRequest )%p\n", result);

  return result;
}


HServerListRequest  ISteamMatchmakingServers_::RequestLANServerList(AppId_t  iApp, ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
  TRACE("((ISteamMatchmakingServers *)%p, (AppId_t )%p, (ISteamMatchmakingServerListResponse *)%p)\n", this, iApp, pRequestServersResponse);
  auto result = this->internal->RequestLANServerList(iApp, pRequestServersResponse);
  TRACE("() = (HServerListRequest )%p\n", result);

  return result;
}


HServerListRequest  ISteamMatchmakingServers_::RequestFriendsServerList(AppId_t  iApp, MatchMakingKeyValuePair_t ** ppchFilters, uint32  nFilters, ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
  TRACE("((ISteamMatchmakingServers *)%p, (AppId_t )%p, (MatchMakingKeyValuePair_t **)%p, (uint32 )%d, (ISteamMatchmakingServerListResponse *)%p)\n", this, iApp, ppchFilters, nFilters, pRequestServersResponse);
  auto result = this->internal->RequestFriendsServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
  TRACE("() = (HServerListRequest )%p\n", result);

  return result;
}


HServerListRequest  ISteamMatchmakingServers_::RequestFavoritesServerList(AppId_t  iApp, MatchMakingKeyValuePair_t ** ppchFilters, uint32  nFilters, ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
  TRACE("((ISteamMatchmakingServers *)%p, (AppId_t )%p, (MatchMakingKeyValuePair_t **)%p, (uint32 )%d, (ISteamMatchmakingServerListResponse *)%p)\n", this, iApp, ppchFilters, nFilters, pRequestServersResponse);
  auto result = this->internal->RequestFavoritesServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
  TRACE("() = (HServerListRequest )%p\n", result);

  return result;
}


HServerListRequest  ISteamMatchmakingServers_::RequestHistoryServerList(AppId_t  iApp, MatchMakingKeyValuePair_t ** ppchFilters, uint32  nFilters, ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
  TRACE("((ISteamMatchmakingServers *)%p, (AppId_t )%p, (MatchMakingKeyValuePair_t **)%p, (uint32 )%d, (ISteamMatchmakingServerListResponse *)%p)\n", this, iApp, ppchFilters, nFilters, pRequestServersResponse);
  auto result = this->internal->RequestHistoryServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
  TRACE("() = (HServerListRequest )%p\n", result);

  return result;
}


HServerListRequest  ISteamMatchmakingServers_::RequestSpectatorServerList(AppId_t  iApp, MatchMakingKeyValuePair_t ** ppchFilters, uint32  nFilters, ISteamMatchmakingServerListResponse * pRequestServersResponse)
{
  TRACE("((ISteamMatchmakingServers *)%p, (AppId_t )%p, (MatchMakingKeyValuePair_t **)%p, (uint32 )%d, (ISteamMatchmakingServerListResponse *)%p)\n", this, iApp, ppchFilters, nFilters, pRequestServersResponse);
  auto result = this->internal->RequestSpectatorServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
  TRACE("() = (HServerListRequest )%p\n", result);

  return result;
}


void  ISteamMatchmakingServers_::ReleaseRequest(HServerListRequest  hServerListRequest)
{
  TRACE("((ISteamMatchmakingServers *)%p, (HServerListRequest )%p)\n", this, hServerListRequest);
  this->internal->ReleaseRequest(hServerListRequest);
  
}


gameserveritem_t * ISteamMatchmakingServers_::GetServerDetails(HServerListRequest  hRequest, int  iServer)
{
  TRACE("((ISteamMatchmakingServers *)%p, (HServerListRequest )%p, (int )%d)\n", this, hRequest, iServer);
  auto result = this->internal->GetServerDetails(hRequest, iServer);
  TRACE("() = (gameserveritem_t *)%p\n", result);

  return result;
}


void  ISteamMatchmakingServers_::CancelQuery(HServerListRequest  hRequest)
{
  TRACE("((ISteamMatchmakingServers *)%p, (HServerListRequest )%p)\n", this, hRequest);
  this->internal->CancelQuery(hRequest);
  
}


void  ISteamMatchmakingServers_::RefreshQuery(HServerListRequest  hRequest)
{
  TRACE("((ISteamMatchmakingServers *)%p, (HServerListRequest )%p)\n", this, hRequest);
  this->internal->RefreshQuery(hRequest);
  
}


bool  ISteamMatchmakingServers_::IsRefreshing(HServerListRequest  hRequest)
{
  TRACE("((ISteamMatchmakingServers *)%p, (HServerListRequest )%p)\n", this, hRequest);
  auto result = this->internal->IsRefreshing(hRequest);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  ISteamMatchmakingServers_::GetServerCount(HServerListRequest  hRequest)
{
  TRACE("((ISteamMatchmakingServers *)%p, (HServerListRequest )%p)\n", this, hRequest);
  auto result = this->internal->GetServerCount(hRequest);
  TRACE("() = (int )%d\n", result);

  return result;
}


void  ISteamMatchmakingServers_::RefreshServer(HServerListRequest  hRequest, int  iServer)
{
  TRACE("((ISteamMatchmakingServers *)%p, (HServerListRequest )%p, (int )%d)\n", this, hRequest, iServer);
  this->internal->RefreshServer(hRequest, iServer);
  
}


HServerQuery  ISteamMatchmakingServers_::PingServer(uint32  unIP, uint16  usPort, ISteamMatchmakingPingResponse * pRequestServersResponse)
{
  TRACE("((ISteamMatchmakingServers *)%p, (uint32 )%d, (uint16 )%d, (ISteamMatchmakingPingResponse *)%p)\n", this, unIP, usPort, pRequestServersResponse);
  auto result = this->internal->PingServer(unIP, usPort, pRequestServersResponse);
  TRACE("() = (HServerQuery )%p\n", result);

  return result;
}


HServerQuery  ISteamMatchmakingServers_::PlayerDetails(uint32  unIP, uint16  usPort, ISteamMatchmakingPlayersResponse * pRequestServersResponse)
{
  TRACE("((ISteamMatchmakingServers *)%p, (uint32 )%d, (uint16 )%d, (ISteamMatchmakingPlayersResponse *)%p)\n", this, unIP, usPort, pRequestServersResponse);
  auto result = this->internal->PlayerDetails(unIP, usPort, pRequestServersResponse);
  TRACE("() = (HServerQuery )%p\n", result);

  return result;
}


HServerQuery  ISteamMatchmakingServers_::ServerRules(uint32  unIP, uint16  usPort, ISteamMatchmakingRulesResponse * pRequestServersResponse)
{
  TRACE("((ISteamMatchmakingServers *)%p, (uint32 )%d, (uint16 )%d, (ISteamMatchmakingRulesResponse *)%p)\n", this, unIP, usPort, pRequestServersResponse);
  auto result = this->internal->ServerRules(unIP, usPort, pRequestServersResponse);
  TRACE("() = (HServerQuery )%p\n", result);

  return result;
}


void  ISteamMatchmakingServers_::CancelServerQuery(HServerQuery  hServerQuery)
{
  TRACE("((ISteamMatchmakingServers *)%p, (HServerQuery )%p)\n", this, hServerQuery);
  this->internal->CancelServerQuery(hServerQuery);
  
}
ISteamMatchmakingServers_::ISteamMatchmakingServers_(ISteamMatchmakingServers * towrap)
{
  this->internal = towrap;
}

ISteamMatchmakingServers_::~ISteamMatchmakingServers_()
{
  delete this->internal;
}
