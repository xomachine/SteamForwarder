#ifndef WRAP_ISTEAMMATCHMAKING_CPP
#define WRAP_ISTEAMMATCHMAKING_CPP
#include "autoclass/steam_api_.h" 
#include "windef.h"
#include "wine/debug.h"
#include "config.h"
int ISteamMatchmaking_::GetFavoriteGameCount()
{
  TRACE("((this[ISteamMatchmaking])%p)\n", this);
  int result = this->internal->GetFavoriteGameCount();
  TRACE(" = (int)%d\n", result);
  return result;
}
bool ISteamMatchmaking_::GetFavoriteGame( int iGame, AppId_t *pnAppID, uint32 *pnIP, uint16 *pnConnPort, uint16 *pnQueryPort, uint32 *punFlags, uint32 *pRTime32LastPlayedOnServer )
{
  TRACE("((this[ISteamMatchmaking])%p, (int)%d, (AppId_t *)%p, (uint32 *)%p, (uint16 *)%p, (uint16 *)%p, (uint32 *)%p, (uint32 *)%p)\n", this, iGame, pnAppID, pnIP, pnConnPort, pnQueryPort, punFlags, pRTime32LastPlayedOnServer);
  bool result = this->internal->GetFavoriteGame(iGame, pnAppID, pnIP, pnConnPort, pnQueryPort, punFlags, pRTime32LastPlayedOnServer);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int ISteamMatchmaking_::AddFavoriteGame( AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer )
{
  TRACE("((this[ISteamMatchmaking])%p, (AppId_t)%p, (uint32)%d, (uint16)%d, (uint16)%d, (uint32)%d, (uint32)%d)\n", this, nAppID, nIP, nConnPort, nQueryPort, unFlags, rTime32LastPlayedOnServer);
  int result = this->internal->AddFavoriteGame(nAppID, nIP, nConnPort, nQueryPort, unFlags, rTime32LastPlayedOnServer);
  TRACE(" = (int)%d\n", result);
  return result;
}
bool ISteamMatchmaking_::RemoveFavoriteGame( AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags )
{
  TRACE("((this[ISteamMatchmaking])%p, (AppId_t)%p, (uint32)%d, (uint16)%d, (uint16)%d, (uint32)%d)\n", this, nAppID, nIP, nConnPort, nQueryPort, unFlags);
  bool result = this->internal->RemoveFavoriteGame(nAppID, nIP, nConnPort, nQueryPort, unFlags);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t ISteamMatchmaking_::RequestLobbyList()
{
  TRACE("((this[ISteamMatchmaking])%p)\n", this);
  SteamAPICall_t result = this->internal->RequestLobbyList();
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
void ISteamMatchmaking_::AddRequestLobbyListStringFilter( const char *pchKeyToMatch, const char *pchValueToMatch, ELobbyComparison eComparisonType )
{
  TRACE("((this[ISteamMatchmaking])%p, (const char *)\"%s\", (const char *)\"%s\", (ELobbyComparison)%p)\n", this, pchKeyToMatch, pchValueToMatch, eComparisonType);
  this->internal->AddRequestLobbyListStringFilter(pchKeyToMatch, pchValueToMatch, eComparisonType);
}
void ISteamMatchmaking_::AddRequestLobbyListNumericalFilter( const char *pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType )
{
  TRACE("((this[ISteamMatchmaking])%p, (const char *)\"%s\", (int)%d, (ELobbyComparison)%p)\n", this, pchKeyToMatch, nValueToMatch, eComparisonType);
  this->internal->AddRequestLobbyListNumericalFilter(pchKeyToMatch, nValueToMatch, eComparisonType);
}
void ISteamMatchmaking_::AddRequestLobbyListNearValueFilter( const char *pchKeyToMatch, int nValueToBeCloseTo )
{
  TRACE("((this[ISteamMatchmaking])%p, (const char *)\"%s\", (int)%d)\n", this, pchKeyToMatch, nValueToBeCloseTo);
  this->internal->AddRequestLobbyListNearValueFilter(pchKeyToMatch, nValueToBeCloseTo);
}
void ISteamMatchmaking_::AddRequestLobbyListFilterSlotsAvailable( int nSlotsAvailable )
{
  TRACE("((this[ISteamMatchmaking])%p, (int)%d)\n", this, nSlotsAvailable);
  this->internal->AddRequestLobbyListFilterSlotsAvailable(nSlotsAvailable);
}
void ISteamMatchmaking_::AddRequestLobbyListDistanceFilter( ELobbyDistanceFilter eLobbyDistanceFilter )
{
  TRACE("((this[ISteamMatchmaking])%p, (ELobbyDistanceFilter)%p)\n", this, eLobbyDistanceFilter);
  this->internal->AddRequestLobbyListDistanceFilter(eLobbyDistanceFilter);
}
void ISteamMatchmaking_::AddRequestLobbyListResultCountFilter( int cMaxResults )
{
  TRACE("((this[ISteamMatchmaking])%p, (int)%d)\n", this, cMaxResults);
  this->internal->AddRequestLobbyListResultCountFilter(cMaxResults);
}
void ISteamMatchmaking_::AddRequestLobbyListCompatibleMembersFilter( CSteamID steamIDLobby )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p)\n", this, steamIDLobby);
  this->internal->AddRequestLobbyListCompatibleMembersFilter(steamIDLobby);
}
CSteamID* ISteamMatchmaking_::GetLobbyByIndex(CSteamID* hidden, int iLobby )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID*)%p, (int)%d)\n", this, hidden, iLobby);
  *hidden = this->internal->GetLobbyByIndex(iLobby);
  return hidden;
}
SteamAPICall_t ISteamMatchmaking_::CreateLobby( ELobbyType eLobbyType, int cMaxMembers )
{
  TRACE("((this[ISteamMatchmaking])%p, (ELobbyType)%p, (int)%d)\n", this, eLobbyType, cMaxMembers);
  SteamAPICall_t result = this->internal->CreateLobby(eLobbyType, cMaxMembers);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t ISteamMatchmaking_::JoinLobby( CSteamID steamIDLobby )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p)\n", this, steamIDLobby);
  SteamAPICall_t result = this->internal->JoinLobby(steamIDLobby);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
void ISteamMatchmaking_::LeaveLobby( CSteamID steamIDLobby )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p)\n", this, steamIDLobby);
  this->internal->LeaveLobby(steamIDLobby);
}
bool ISteamMatchmaking_::InviteUserToLobby( CSteamID steamIDLobby, CSteamID steamIDInvitee )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p, (CSteamID)%p)\n", this, steamIDLobby, steamIDInvitee);
  bool result = this->internal->InviteUserToLobby(steamIDLobby, steamIDInvitee);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int ISteamMatchmaking_::GetNumLobbyMembers( CSteamID steamIDLobby )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p)\n", this, steamIDLobby);
  int result = this->internal->GetNumLobbyMembers(steamIDLobby);
  TRACE(" = (int)%d\n", result);
  return result;
}
CSteamID* ISteamMatchmaking_::GetLobbyMemberByIndex(CSteamID* hidden, CSteamID steamIDLobby, int iMember )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID*)%p, (CSteamID)%p, (int)%d)\n", this, hidden, steamIDLobby, iMember);
  *hidden = this->internal->GetLobbyMemberByIndex(steamIDLobby, iMember);
  return hidden;
}
const char * ISteamMatchmaking_::GetLobbyData( CSteamID steamIDLobby, const char *pchKey )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p, (const char *)\"%s\")\n", this, steamIDLobby, pchKey);
  const char * result = this->internal->GetLobbyData(steamIDLobby, pchKey);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
bool ISteamMatchmaking_::SetLobbyData( CSteamID steamIDLobby, const char *pchKey, const char *pchValue )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p, (const char *)\"%s\", (const char *)\"%s\")\n", this, steamIDLobby, pchKey, pchValue);
  bool result = this->internal->SetLobbyData(steamIDLobby, pchKey, pchValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int ISteamMatchmaking_::GetLobbyDataCount( CSteamID steamIDLobby )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p)\n", this, steamIDLobby);
  int result = this->internal->GetLobbyDataCount(steamIDLobby);
  TRACE(" = (int)%d\n", result);
  return result;
}
bool ISteamMatchmaking_::GetLobbyDataByIndex( CSteamID steamIDLobby, int iLobbyData, char *pchKey, int cchKeyBufferSize, char *pchValue, int cchValueBufferSize )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p, (int)%d, (char *)%p, (int)%d, (char *)%p, (int)%d)\n", this, steamIDLobby, iLobbyData, pchKey, cchKeyBufferSize, pchValue, cchValueBufferSize);
  bool result = this->internal->GetLobbyDataByIndex(steamIDLobby, iLobbyData, pchKey, cchKeyBufferSize, pchValue, cchValueBufferSize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMatchmaking_::DeleteLobbyData( CSteamID steamIDLobby, const char *pchKey )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p, (const char *)\"%s\")\n", this, steamIDLobby, pchKey);
  bool result = this->internal->DeleteLobbyData(steamIDLobby, pchKey);
  TRACE(" = (bool)%d\n", result);
  return result;
}
const char * ISteamMatchmaking_::GetLobbyMemberData( CSteamID steamIDLobby, CSteamID steamIDUser, const char *pchKey )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p, (CSteamID)%p, (const char *)\"%s\")\n", this, steamIDLobby, steamIDUser, pchKey);
  const char * result = this->internal->GetLobbyMemberData(steamIDLobby, steamIDUser, pchKey);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
void ISteamMatchmaking_::SetLobbyMemberData( CSteamID steamIDLobby, const char *pchKey, const char *pchValue )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p, (const char *)\"%s\", (const char *)\"%s\")\n", this, steamIDLobby, pchKey, pchValue);
  this->internal->SetLobbyMemberData(steamIDLobby, pchKey, pchValue);
}
bool ISteamMatchmaking_::SendLobbyChatMsg( CSteamID steamIDLobby, const void *pvMsgBody, int cubMsgBody )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p, (const void *)%p, (int)%d)\n", this, steamIDLobby, pvMsgBody, cubMsgBody);
  bool result = this->internal->SendLobbyChatMsg(steamIDLobby, pvMsgBody, cubMsgBody);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int ISteamMatchmaking_::GetLobbyChatEntry( CSteamID steamIDLobby, int iChatID, OUT_STRUCT() CSteamID *pSteamIDUser, void *pvData, int cubData, EChatEntryType *peChatEntryType )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p, (int)%d, (CSteamID *)%p, (void *)%p, (int)%d, (EChatEntryType *)%p)\n", this, steamIDLobby, iChatID, pSteamIDUser, pvData, cubData, peChatEntryType);
  int result = this->internal->GetLobbyChatEntry(steamIDLobby, iChatID, pSteamIDUser, pvData, cubData, peChatEntryType);
  TRACE(" = (int)%d\n", result);
  return result;
}
bool ISteamMatchmaking_::RequestLobbyData( CSteamID steamIDLobby )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p)\n", this, steamIDLobby);
  bool result = this->internal->RequestLobbyData(steamIDLobby);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void ISteamMatchmaking_::SetLobbyGameServer( CSteamID steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, CSteamID steamIDGameServer )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p, (uint32)%d, (uint16)%d, (CSteamID)%p)\n", this, steamIDLobby, unGameServerIP, unGameServerPort, steamIDGameServer);
  this->internal->SetLobbyGameServer(steamIDLobby, unGameServerIP, unGameServerPort, steamIDGameServer);
}
bool ISteamMatchmaking_::GetLobbyGameServer( CSteamID steamIDLobby, uint32 *punGameServerIP, uint16 *punGameServerPort, OUT_STRUCT() CSteamID *psteamIDGameServer )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p, (uint32 *)%p, (uint16 *)%p, (CSteamID *)%p)\n", this, steamIDLobby, punGameServerIP, punGameServerPort, psteamIDGameServer);
  bool result = this->internal->GetLobbyGameServer(steamIDLobby, punGameServerIP, punGameServerPort, psteamIDGameServer);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMatchmaking_::SetLobbyMemberLimit( CSteamID steamIDLobby, int cMaxMembers )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p, (int)%d)\n", this, steamIDLobby, cMaxMembers);
  bool result = this->internal->SetLobbyMemberLimit(steamIDLobby, cMaxMembers);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int ISteamMatchmaking_::GetLobbyMemberLimit( CSteamID steamIDLobby )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p)\n", this, steamIDLobby);
  int result = this->internal->GetLobbyMemberLimit(steamIDLobby);
  TRACE(" = (int)%d\n", result);
  return result;
}
bool ISteamMatchmaking_::SetLobbyType( CSteamID steamIDLobby, ELobbyType eLobbyType )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p, (ELobbyType)%p)\n", this, steamIDLobby, eLobbyType);
  bool result = this->internal->SetLobbyType(steamIDLobby, eLobbyType);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMatchmaking_::SetLobbyJoinable( CSteamID steamIDLobby, bool bLobbyJoinable )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p, (bool)%d)\n", this, steamIDLobby, bLobbyJoinable);
  bool result = this->internal->SetLobbyJoinable(steamIDLobby, bLobbyJoinable);
  TRACE(" = (bool)%d\n", result);
  return result;
}
CSteamID* ISteamMatchmaking_::GetLobbyOwner(CSteamID* hidden, CSteamID steamIDLobby )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID*)%p, (CSteamID)%p)\n", this, hidden, steamIDLobby);
  *hidden = this->internal->GetLobbyOwner(steamIDLobby);
  return hidden;
}
bool ISteamMatchmaking_::SetLobbyOwner( CSteamID steamIDLobby, CSteamID steamIDNewOwner )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p, (CSteamID)%p)\n", this, steamIDLobby, steamIDNewOwner);
  bool result = this->internal->SetLobbyOwner(steamIDLobby, steamIDNewOwner);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamMatchmaking_::SetLinkedLobby( CSteamID steamIDLobby, CSteamID steamIDLobbyDependent )
{
  TRACE("((this[ISteamMatchmaking])%p, (CSteamID)%p, (CSteamID)%p)\n", this, steamIDLobby, steamIDLobbyDependent);
  bool result = this->internal->SetLinkedLobby(steamIDLobby, steamIDLobbyDependent);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void ISteamMatchmakingServerListResponse_::ServerResponded( HServerListRequest hRequest, int iServer )
{
  TRACE("((this[ISteamMatchmakingServerListResponse])%p, (HServerListRequest)%p, (int)%d)\n", this, hRequest, iServer);
  this->internal->ServerResponded(hRequest, iServer);
}
void ISteamMatchmakingServerListResponse_::ServerFailedToRespond( HServerListRequest hRequest, int iServer )
{
  TRACE("((this[ISteamMatchmakingServerListResponse])%p, (HServerListRequest)%p, (int)%d)\n", this, hRequest, iServer);
  this->internal->ServerFailedToRespond(hRequest, iServer);
}
void ISteamMatchmakingServerListResponse_::RefreshComplete( HServerListRequest hRequest, EMatchMakingServerResponse response )
{
  TRACE("((this[ISteamMatchmakingServerListResponse])%p, (HServerListRequest)%p, (EMatchMakingServerResponse)%p)\n", this, hRequest, response);
  this->internal->RefreshComplete(hRequest, response);
}
void ISteamMatchmakingPingResponse_::ServerResponded( gameserveritem_t &server )
{
  TRACE("((this[ISteamMatchmakingPingResponse])%p, (gameserveritem_t &)%p)\n", this, server);
  this->internal->ServerResponded(server);
}
void ISteamMatchmakingPingResponse_::ServerFailedToRespond()
{
  TRACE("((this[ISteamMatchmakingPingResponse])%p)\n", this);
  this->internal->ServerFailedToRespond();
}
void ISteamMatchmakingPlayersResponse_::AddPlayerToList( const char *pchName, int nScore, float flTimePlayed )
{
  TRACE("((this[ISteamMatchmakingPlayersResponse])%p, (const char *)\"%s\", (int)%d, (float)%f)\n", this, pchName, nScore, flTimePlayed);
  this->internal->AddPlayerToList(pchName, nScore, flTimePlayed);
}
void ISteamMatchmakingPlayersResponse_::PlayersFailedToRespond()
{
  TRACE("((this[ISteamMatchmakingPlayersResponse])%p)\n", this);
  this->internal->PlayersFailedToRespond();
}
void ISteamMatchmakingPlayersResponse_::PlayersRefreshComplete()
{
  TRACE("((this[ISteamMatchmakingPlayersResponse])%p)\n", this);
  this->internal->PlayersRefreshComplete();
}
void ISteamMatchmakingRulesResponse_::RulesResponded( const char *pchRule, const char *pchValue )
{
  TRACE("((this[ISteamMatchmakingRulesResponse])%p, (const char *)\"%s\", (const char *)\"%s\")\n", this, pchRule, pchValue);
  this->internal->RulesResponded(pchRule, pchValue);
}
void ISteamMatchmakingRulesResponse_::RulesFailedToRespond()
{
  TRACE("((this[ISteamMatchmakingRulesResponse])%p)\n", this);
  this->internal->RulesFailedToRespond();
}
void ISteamMatchmakingRulesResponse_::RulesRefreshComplete()
{
  TRACE("((this[ISteamMatchmakingRulesResponse])%p)\n", this);
  this->internal->RulesRefreshComplete();
}
HServerListRequest ISteamMatchmakingServers_::RequestInternetServerList( AppId_t iApp, ARRAY_COUNT(nFilters) MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
  TRACE("((this[ISteamMatchmakingServers])%p, (AppId_t)%p, (MatchMakingKeyValuePair_t **)%p, (uint32)%d, (ISteamMatchmakingServerListResponse *)%p)\n", this, iApp, ppchFilters, nFilters, pRequestServersResponse);
  HServerListRequest result = this->internal->RequestInternetServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
  TRACE(" = (HServerListRequest)%p\n", result);
  return result;
}
HServerListRequest ISteamMatchmakingServers_::RequestLANServerList( AppId_t iApp, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
  TRACE("((this[ISteamMatchmakingServers])%p, (AppId_t)%p, (ISteamMatchmakingServerListResponse *)%p)\n", this, iApp, pRequestServersResponse);
  HServerListRequest result = this->internal->RequestLANServerList(iApp, pRequestServersResponse);
  TRACE(" = (HServerListRequest)%p\n", result);
  return result;
}
HServerListRequest ISteamMatchmakingServers_::RequestFriendsServerList( AppId_t iApp, ARRAY_COUNT(nFilters) MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
  TRACE("((this[ISteamMatchmakingServers])%p, (AppId_t)%p, (MatchMakingKeyValuePair_t **)%p, (uint32)%d, (ISteamMatchmakingServerListResponse *)%p)\n", this, iApp, ppchFilters, nFilters, pRequestServersResponse);
  HServerListRequest result = this->internal->RequestFriendsServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
  TRACE(" = (HServerListRequest)%p\n", result);
  return result;
}
HServerListRequest ISteamMatchmakingServers_::RequestFavoritesServerList( AppId_t iApp, ARRAY_COUNT(nFilters) MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
  TRACE("((this[ISteamMatchmakingServers])%p, (AppId_t)%p, (MatchMakingKeyValuePair_t **)%p, (uint32)%d, (ISteamMatchmakingServerListResponse *)%p)\n", this, iApp, ppchFilters, nFilters, pRequestServersResponse);
  HServerListRequest result = this->internal->RequestFavoritesServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
  TRACE(" = (HServerListRequest)%p\n", result);
  return result;
}
HServerListRequest ISteamMatchmakingServers_::RequestHistoryServerList( AppId_t iApp, ARRAY_COUNT(nFilters) MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
  TRACE("((this[ISteamMatchmakingServers])%p, (AppId_t)%p, (MatchMakingKeyValuePair_t **)%p, (uint32)%d, (ISteamMatchmakingServerListResponse *)%p)\n", this, iApp, ppchFilters, nFilters, pRequestServersResponse);
  HServerListRequest result = this->internal->RequestHistoryServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
  TRACE(" = (HServerListRequest)%p\n", result);
  return result;
}
HServerListRequest ISteamMatchmakingServers_::RequestSpectatorServerList( AppId_t iApp, ARRAY_COUNT(nFilters) MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
  TRACE("((this[ISteamMatchmakingServers])%p, (AppId_t)%p, (MatchMakingKeyValuePair_t **)%p, (uint32)%d, (ISteamMatchmakingServerListResponse *)%p)\n", this, iApp, ppchFilters, nFilters, pRequestServersResponse);
  HServerListRequest result = this->internal->RequestSpectatorServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
  TRACE(" = (HServerListRequest)%p\n", result);
  return result;
}
void ISteamMatchmakingServers_::ReleaseRequest( HServerListRequest hServerListRequest )
{
  TRACE("((this[ISteamMatchmakingServers])%p, (HServerListRequest)%p)\n", this, hServerListRequest);
  this->internal->ReleaseRequest(hServerListRequest);
}
gameserveritem_t * ISteamMatchmakingServers_::GetServerDetails( HServerListRequest hRequest, int iServer )
{
  TRACE("((this[ISteamMatchmakingServers])%p, (HServerListRequest)%p, (int)%d)\n", this, hRequest, iServer);
  gameserveritem_t * result = this->internal->GetServerDetails(hRequest, iServer);
  TRACE(" = (gameserveritem_t *)%p\n", result);
  return result;
}
void ISteamMatchmakingServers_::CancelQuery( HServerListRequest hRequest )
{
  TRACE("((this[ISteamMatchmakingServers])%p, (HServerListRequest)%p)\n", this, hRequest);
  this->internal->CancelQuery(hRequest);
}
void ISteamMatchmakingServers_::RefreshQuery( HServerListRequest hRequest )
{
  TRACE("((this[ISteamMatchmakingServers])%p, (HServerListRequest)%p)\n", this, hRequest);
  this->internal->RefreshQuery(hRequest);
}
bool ISteamMatchmakingServers_::IsRefreshing( HServerListRequest hRequest )
{
  TRACE("((this[ISteamMatchmakingServers])%p, (HServerListRequest)%p)\n", this, hRequest);
  bool result = this->internal->IsRefreshing(hRequest);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int ISteamMatchmakingServers_::GetServerCount( HServerListRequest hRequest )
{
  TRACE("((this[ISteamMatchmakingServers])%p, (HServerListRequest)%p)\n", this, hRequest);
  int result = this->internal->GetServerCount(hRequest);
  TRACE(" = (int)%d\n", result);
  return result;
}
void ISteamMatchmakingServers_::RefreshServer( HServerListRequest hRequest, int iServer )
{
  TRACE("((this[ISteamMatchmakingServers])%p, (HServerListRequest)%p, (int)%d)\n", this, hRequest, iServer);
  this->internal->RefreshServer(hRequest, iServer);
}
HServerQuery ISteamMatchmakingServers_::PingServer( uint32 unIP, uint16 usPort, ISteamMatchmakingPingResponse *pRequestServersResponse )
{
  TRACE("((this[ISteamMatchmakingServers])%p, (uint32)%d, (uint16)%d, (ISteamMatchmakingPingResponse *)%p)\n", this, unIP, usPort, pRequestServersResponse);
  HServerQuery result = this->internal->PingServer(unIP, usPort, pRequestServersResponse);
  TRACE(" = (HServerQuery)%p\n", result);
  return result;
}
HServerQuery ISteamMatchmakingServers_::PlayerDetails( uint32 unIP, uint16 usPort, ISteamMatchmakingPlayersResponse *pRequestServersResponse )
{
  TRACE("((this[ISteamMatchmakingServers])%p, (uint32)%d, (uint16)%d, (ISteamMatchmakingPlayersResponse *)%p)\n", this, unIP, usPort, pRequestServersResponse);
  HServerQuery result = this->internal->PlayerDetails(unIP, usPort, pRequestServersResponse);
  TRACE(" = (HServerQuery)%p\n", result);
  return result;
}
HServerQuery ISteamMatchmakingServers_::ServerRules( uint32 unIP, uint16 usPort, ISteamMatchmakingRulesResponse *pRequestServersResponse )
{
  TRACE("((this[ISteamMatchmakingServers])%p, (uint32)%d, (uint16)%d, (ISteamMatchmakingRulesResponse *)%p)\n", this, unIP, usPort, pRequestServersResponse);
  HServerQuery result = this->internal->ServerRules(unIP, usPort, pRequestServersResponse);
  TRACE(" = (HServerQuery)%p\n", result);
  return result;
}
void ISteamMatchmakingServers_::CancelServerQuery( HServerQuery hServerQuery )
{
  TRACE("((this[ISteamMatchmakingServers])%p, (HServerQuery)%p)\n", this, hServerQuery);
  this->internal->CancelServerQuery(hServerQuery);
}
#endif
