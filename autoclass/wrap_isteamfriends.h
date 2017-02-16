#ifndef WRAP_ISTEAMFRIENDS_H
#define WRAP_ISTEAMFRIENDS_H
#include "steam_api.h"
class ISteamFriends_ 
{
  virtual const char * GetPersonaName() __attribute__((thiscall));
  virtual SteamAPICall_t SetPersonaName( const char *pchPersonaName ) __attribute__((thiscall));
  virtual EPersonaState GetPersonaState() __attribute__((thiscall));
  virtual int GetFriendCount( int iFriendFlags ) __attribute__((thiscall));
  virtual CSteamID* GetFriendByIndex(CSteamID* hidden, int iFriend, int iFriendFlags ) __attribute__((thiscall));
  virtual EFriendRelationship GetFriendRelationship( CSteamID steamIDFriend ) __attribute__((thiscall));
  virtual EPersonaState GetFriendPersonaState( CSteamID steamIDFriend ) __attribute__((thiscall));
  virtual const char * GetFriendPersonaName( CSteamID steamIDFriend ) __attribute__((thiscall));
  virtual bool GetFriendGamePlayed( CSteamID steamIDFriend, OUT_STRUCT() FriendGameInfo_t *pFriendGameInfo ) __attribute__((thiscall));
  virtual const char * GetFriendPersonaNameHistory( CSteamID steamIDFriend, int iPersonaName ) __attribute__((thiscall));
  virtual int GetFriendSteamLevel( CSteamID steamIDFriend ) __attribute__((thiscall));
  virtual const char * GetPlayerNickname( CSteamID steamIDPlayer ) __attribute__((thiscall));
  virtual int GetFriendsGroupCount() __attribute__((thiscall));
  virtual FriendsGroupID_t GetFriendsGroupIDByIndex( int iFG ) __attribute__((thiscall));
  virtual const char * GetFriendsGroupName( FriendsGroupID_t friendsGroupID ) __attribute__((thiscall));
  virtual int GetFriendsGroupMembersCount( FriendsGroupID_t friendsGroupID ) __attribute__((thiscall));
  virtual void GetFriendsGroupMembersList( FriendsGroupID_t friendsGroupID, OUT_ARRAY_CALL(nMembersCount, GetFriendsGroupMembersCount, friendsGroupID ) CSteamID *pOutSteamIDMembers, int nMembersCount ) __attribute__((thiscall));
  virtual bool HasFriend( CSteamID steamIDFriend, int iFriendFlags ) __attribute__((thiscall));
  virtual int GetClanCount() __attribute__((thiscall));
  virtual CSteamID* GetClanByIndex(CSteamID* hidden, int iClan ) __attribute__((thiscall));
  virtual const char * GetClanName( CSteamID steamIDClan ) __attribute__((thiscall));
  virtual const char * GetClanTag( CSteamID steamIDClan ) __attribute__((thiscall));
  virtual bool GetClanActivityCounts( CSteamID steamIDClan, int *pnOnline, int *pnInGame, int *pnChatting ) __attribute__((thiscall));
  virtual SteamAPICall_t DownloadClanActivityCounts( ARRAY_COUNT(cClansToRequest) CSteamID *psteamIDClans, int cClansToRequest ) __attribute__((thiscall));
  virtual int GetFriendCountFromSource( CSteamID steamIDSource ) __attribute__((thiscall));
  virtual CSteamID* GetFriendFromSourceByIndex(CSteamID* hidden, CSteamID steamIDSource, int iFriend ) __attribute__((thiscall));
  virtual bool IsUserInSource( CSteamID steamIDUser, CSteamID steamIDSource ) __attribute__((thiscall));
  virtual void SetInGameVoiceSpeaking( CSteamID steamIDUser, bool bSpeaking ) __attribute__((thiscall));
  virtual void ActivateGameOverlay( const char *pchDialog ) __attribute__((thiscall));
  virtual void ActivateGameOverlayToUser( const char *pchDialog, CSteamID steamID ) __attribute__((thiscall));
  virtual void ActivateGameOverlayToWebPage( const char *pchURL ) __attribute__((thiscall));
  virtual void ActivateGameOverlayToStore( AppId_t nAppID, EOverlayToStoreFlag eFlag ) __attribute__((thiscall));
  virtual void SetPlayedWith( CSteamID steamIDUserPlayedWith ) __attribute__((thiscall));
  virtual void ActivateGameOverlayInviteDialog( CSteamID steamIDLobby ) __attribute__((thiscall));
  virtual int GetSmallFriendAvatar( CSteamID steamIDFriend ) __attribute__((thiscall));
  virtual int GetMediumFriendAvatar( CSteamID steamIDFriend ) __attribute__((thiscall));
  virtual int GetLargeFriendAvatar( CSteamID steamIDFriend ) __attribute__((thiscall));
  virtual bool RequestUserInformation( CSteamID steamIDUser, bool bRequireNameOnly ) __attribute__((thiscall));
  virtual SteamAPICall_t RequestClanOfficerList( CSteamID steamIDClan ) __attribute__((thiscall));
  virtual CSteamID* GetClanOwner(CSteamID* hidden, CSteamID steamIDClan ) __attribute__((thiscall));
  virtual int GetClanOfficerCount( CSteamID steamIDClan ) __attribute__((thiscall));
  virtual CSteamID* GetClanOfficerByIndex(CSteamID* hidden, CSteamID steamIDClan, int iOfficer ) __attribute__((thiscall));
  virtual uint32 GetUserRestrictions() __attribute__((thiscall));
  virtual bool SetRichPresence( const char *pchKey, const char *pchValue ) __attribute__((thiscall));
  virtual void ClearRichPresence() __attribute__((thiscall));
  virtual const char * GetFriendRichPresence( CSteamID steamIDFriend, const char *pchKey ) __attribute__((thiscall));
  virtual int GetFriendRichPresenceKeyCount( CSteamID steamIDFriend ) __attribute__((thiscall));
  virtual const char * GetFriendRichPresenceKeyByIndex( CSteamID steamIDFriend, int iKey ) __attribute__((thiscall));
  virtual void RequestFriendRichPresence( CSteamID steamIDFriend ) __attribute__((thiscall));
  virtual bool InviteUserToGame( CSteamID steamIDFriend, const char *pchConnectString ) __attribute__((thiscall));
  virtual int GetCoplayFriendCount() __attribute__((thiscall));
  virtual CSteamID* GetCoplayFriend(CSteamID* hidden, int iCoplayFriend ) __attribute__((thiscall));
  virtual int GetFriendCoplayTime( CSteamID steamIDFriend ) __attribute__((thiscall));
  virtual AppId_t GetFriendCoplayGame( CSteamID steamIDFriend ) __attribute__((thiscall));
  virtual SteamAPICall_t JoinClanChatRoom( CSteamID steamIDClan ) __attribute__((thiscall));
  virtual bool LeaveClanChatRoom( CSteamID steamIDClan ) __attribute__((thiscall));
  virtual int GetClanChatMemberCount( CSteamID steamIDClan ) __attribute__((thiscall));
  virtual CSteamID* GetChatMemberByIndex(CSteamID* hidden, CSteamID steamIDClan, int iUser ) __attribute__((thiscall));
  virtual bool SendClanChatMessage( CSteamID steamIDClanChat, const char *pchText ) __attribute__((thiscall));
  virtual int GetClanChatMessage( CSteamID steamIDClanChat, int iMessage, void *prgchText, int cchTextMax, EChatEntryType *peChatEntryType, OUT_STRUCT() CSteamID *psteamidChatter ) __attribute__((thiscall));
  virtual bool IsClanChatAdmin( CSteamID steamIDClanChat, CSteamID steamIDUser ) __attribute__((thiscall));
  virtual bool IsClanChatWindowOpenInSteam( CSteamID steamIDClanChat ) __attribute__((thiscall));
  virtual bool OpenClanChatWindowInSteam( CSteamID steamIDClanChat ) __attribute__((thiscall));
  virtual bool CloseClanChatWindowInSteam( CSteamID steamIDClanChat ) __attribute__((thiscall));
  virtual bool SetListenForFriendsMessages( bool bInterceptEnabled ) __attribute__((thiscall));
  virtual bool ReplyToFriendMessage( CSteamID steamIDFriend, const char *pchMsgToSend ) __attribute__((thiscall));
  virtual int GetFriendMessage( CSteamID steamIDFriend, int iMessageID, void *pvData, int cubData, EChatEntryType *peChatEntryType ) __attribute__((thiscall));
  virtual SteamAPICall_t GetFollowerCount( CSteamID steamID ) __attribute__((thiscall));
  virtual SteamAPICall_t IsFollowing( CSteamID steamID ) __attribute__((thiscall));
  virtual SteamAPICall_t EnumerateFollowingList( uint32 unStartIndex ) __attribute__((thiscall));
  public:
    ISteamFriends *internal;
};
#endif
