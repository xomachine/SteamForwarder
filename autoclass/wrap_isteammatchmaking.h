#ifndef WRAP_ISTEAMMATCHMAKING_H
#define WRAP_ISTEAMMATCHMAKING_H
#include "steam_api.h"
class ISteamMatchmaking_ 
{
  virtual int GetFavoriteGameCount() __attribute__((thiscall));
  virtual bool GetFavoriteGame( int iGame, AppId_t *pnAppID, uint32 *pnIP, uint16 *pnConnPort, uint16 *pnQueryPort, uint32 *punFlags, uint32 *pRTime32LastPlayedOnServer ) __attribute__((thiscall));
  virtual int AddFavoriteGame( AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer ) __attribute__((thiscall));
  virtual bool RemoveFavoriteGame( AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags ) __attribute__((thiscall));
  virtual SteamAPICall_t RequestLobbyList() __attribute__((thiscall));
  virtual void AddRequestLobbyListStringFilter( const char *pchKeyToMatch, const char *pchValueToMatch, ELobbyComparison eComparisonType ) __attribute__((thiscall));
  virtual void AddRequestLobbyListNumericalFilter( const char *pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType ) __attribute__((thiscall));
  virtual void AddRequestLobbyListNearValueFilter( const char *pchKeyToMatch, int nValueToBeCloseTo ) __attribute__((thiscall));
  virtual void AddRequestLobbyListFilterSlotsAvailable( int nSlotsAvailable ) __attribute__((thiscall));
  virtual void AddRequestLobbyListDistanceFilter( ELobbyDistanceFilter eLobbyDistanceFilter ) __attribute__((thiscall));
  virtual void AddRequestLobbyListResultCountFilter( int cMaxResults ) __attribute__((thiscall));
  virtual void AddRequestLobbyListCompatibleMembersFilter( CSteamID steamIDLobby ) __attribute__((thiscall));
  virtual CSteamID* GetLobbyByIndex(CSteamID* hidden, int iLobby ) __attribute__((thiscall));
  virtual SteamAPICall_t CreateLobby( ELobbyType eLobbyType, int cMaxMembers ) __attribute__((thiscall));
  virtual SteamAPICall_t JoinLobby( CSteamID steamIDLobby ) __attribute__((thiscall));
  virtual void LeaveLobby( CSteamID steamIDLobby ) __attribute__((thiscall));
  virtual bool InviteUserToLobby( CSteamID steamIDLobby, CSteamID steamIDInvitee ) __attribute__((thiscall));
  virtual int GetNumLobbyMembers( CSteamID steamIDLobby ) __attribute__((thiscall));
  virtual CSteamID* GetLobbyMemberByIndex(CSteamID* hidden, CSteamID steamIDLobby, int iMember ) __attribute__((thiscall));
  virtual const char * GetLobbyData( CSteamID steamIDLobby, const char *pchKey ) __attribute__((thiscall));
  virtual bool SetLobbyData( CSteamID steamIDLobby, const char *pchKey, const char *pchValue ) __attribute__((thiscall));
  virtual int GetLobbyDataCount( CSteamID steamIDLobby ) __attribute__((thiscall));
  virtual bool GetLobbyDataByIndex( CSteamID steamIDLobby, int iLobbyData, char *pchKey, int cchKeyBufferSize, char *pchValue, int cchValueBufferSize ) __attribute__((thiscall));
  virtual bool DeleteLobbyData( CSteamID steamIDLobby, const char *pchKey ) __attribute__((thiscall));
  virtual const char * GetLobbyMemberData( CSteamID steamIDLobby, CSteamID steamIDUser, const char *pchKey ) __attribute__((thiscall));
  virtual void SetLobbyMemberData( CSteamID steamIDLobby, const char *pchKey, const char *pchValue ) __attribute__((thiscall));
  virtual bool SendLobbyChatMsg( CSteamID steamIDLobby, const void *pvMsgBody, int cubMsgBody ) __attribute__((thiscall));
  virtual int GetLobbyChatEntry( CSteamID steamIDLobby, int iChatID, OUT_STRUCT() CSteamID *pSteamIDUser, void *pvData, int cubData, EChatEntryType *peChatEntryType ) __attribute__((thiscall));
  virtual bool RequestLobbyData( CSteamID steamIDLobby ) __attribute__((thiscall));
  virtual void SetLobbyGameServer( CSteamID steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, CSteamID steamIDGameServer ) __attribute__((thiscall));
  virtual bool GetLobbyGameServer( CSteamID steamIDLobby, uint32 *punGameServerIP, uint16 *punGameServerPort, OUT_STRUCT() CSteamID *psteamIDGameServer ) __attribute__((thiscall));
  virtual bool SetLobbyMemberLimit( CSteamID steamIDLobby, int cMaxMembers ) __attribute__((thiscall));
  virtual int GetLobbyMemberLimit( CSteamID steamIDLobby ) __attribute__((thiscall));
  virtual bool SetLobbyType( CSteamID steamIDLobby, ELobbyType eLobbyType ) __attribute__((thiscall));
  virtual bool SetLobbyJoinable( CSteamID steamIDLobby, bool bLobbyJoinable ) __attribute__((thiscall));
  virtual CSteamID* GetLobbyOwner(CSteamID* hidden, CSteamID steamIDLobby ) __attribute__((thiscall));
  virtual bool SetLobbyOwner( CSteamID steamIDLobby, CSteamID steamIDNewOwner ) __attribute__((thiscall));
  virtual bool SetLinkedLobby( CSteamID steamIDLobby, CSteamID steamIDLobbyDependent ) __attribute__((thiscall));
  public:
    ISteamMatchmaking *internal;
};
class ISteamMatchmakingServerListResponse_ 
{
  virtual void ServerResponded( HServerListRequest hRequest, int iServer ) __attribute__((thiscall));
  virtual void ServerFailedToRespond( HServerListRequest hRequest, int iServer ) __attribute__((thiscall));
  virtual void RefreshComplete( HServerListRequest hRequest, EMatchMakingServerResponse response ) __attribute__((thiscall));
  public:
    ISteamMatchmakingServerListResponse *internal;
};
class ISteamMatchmakingPingResponse_ 
{
  virtual void ServerResponded( gameserveritem_t &server ) __attribute__((thiscall));
  virtual void ServerFailedToRespond() __attribute__((thiscall));
  public:
    ISteamMatchmakingPingResponse *internal;
};
class ISteamMatchmakingPlayersResponse_ 
{
  virtual void AddPlayerToList( const char *pchName, int nScore, float flTimePlayed ) __attribute__((thiscall));
  virtual void PlayersFailedToRespond() __attribute__((thiscall));
  virtual void PlayersRefreshComplete() __attribute__((thiscall));
  public:
    ISteamMatchmakingPlayersResponse *internal;
};
class ISteamMatchmakingRulesResponse_ 
{
  virtual void RulesResponded( const char *pchRule, const char *pchValue ) __attribute__((thiscall));
  virtual void RulesFailedToRespond() __attribute__((thiscall));
  virtual void RulesRefreshComplete() __attribute__((thiscall));
  public:
    ISteamMatchmakingRulesResponse *internal;
};
class ISteamMatchmakingServers_ 
{
  virtual HServerListRequest RequestInternetServerList( AppId_t iApp, ARRAY_COUNT(nFilters) MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse ) __attribute__((thiscall));
  virtual HServerListRequest RequestLANServerList( AppId_t iApp, ISteamMatchmakingServerListResponse *pRequestServersResponse ) __attribute__((thiscall));
  virtual HServerListRequest RequestFriendsServerList( AppId_t iApp, ARRAY_COUNT(nFilters) MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse ) __attribute__((thiscall));
  virtual HServerListRequest RequestFavoritesServerList( AppId_t iApp, ARRAY_COUNT(nFilters) MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse ) __attribute__((thiscall));
  virtual HServerListRequest RequestHistoryServerList( AppId_t iApp, ARRAY_COUNT(nFilters) MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse ) __attribute__((thiscall));
  virtual HServerListRequest RequestSpectatorServerList( AppId_t iApp, ARRAY_COUNT(nFilters) MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse ) __attribute__((thiscall));
  virtual void ReleaseRequest( HServerListRequest hServerListRequest ) __attribute__((thiscall));
  virtual gameserveritem_t * GetServerDetails( HServerListRequest hRequest, int iServer ) __attribute__((thiscall));
  virtual void CancelQuery( HServerListRequest hRequest ) __attribute__((thiscall));
  virtual void RefreshQuery( HServerListRequest hRequest ) __attribute__((thiscall));
  virtual bool IsRefreshing( HServerListRequest hRequest ) __attribute__((thiscall));
  virtual int GetServerCount( HServerListRequest hRequest ) __attribute__((thiscall));
  virtual void RefreshServer( HServerListRequest hRequest, int iServer ) __attribute__((thiscall));
  virtual HServerQuery PingServer( uint32 unIP, uint16 usPort, ISteamMatchmakingPingResponse *pRequestServersResponse ) __attribute__((thiscall));
  virtual HServerQuery PlayerDetails( uint32 unIP, uint16 usPort, ISteamMatchmakingPlayersResponse *pRequestServersResponse ) __attribute__((thiscall));
  virtual HServerQuery ServerRules( uint32 unIP, uint16 usPort, ISteamMatchmakingRulesResponse *pRequestServersResponse ) __attribute__((thiscall));
  virtual void CancelServerQuery( HServerQuery hServerQuery ) __attribute__((thiscall));
  public:
    ISteamMatchmakingServers *internal;
};
#endif
