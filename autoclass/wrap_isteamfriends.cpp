#ifndef WRAP_ISTEAMFRIENDS_CPP
#define WRAP_ISTEAMFRIENDS_CPP
#include "autoclass/steam_api_.h" 
#include "windef.h"
#include "wine/debug.h"
#include "config.h"
const char * ISteamFriends_::GetPersonaName()
{
  TRACE("((this[ISteamFriends])%p)\n", this);
  const char * result = this->internal->GetPersonaName();
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
SteamAPICall_t ISteamFriends_::SetPersonaName( const char *pchPersonaName )
{
  TRACE("((this[ISteamFriends])%p, (const char *)\"%s\")\n", this, pchPersonaName);
  SteamAPICall_t result = this->internal->SetPersonaName(pchPersonaName);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
EPersonaState ISteamFriends_::GetPersonaState()
{
  TRACE("((this[ISteamFriends])%p)\n", this);
  EPersonaState result = this->internal->GetPersonaState();
  TRACE(" = (EPersonaState)%p\n", result);
  return result;
}
int ISteamFriends_::GetFriendCount( int iFriendFlags )
{
  TRACE("((this[ISteamFriends])%p, (int)%d)\n", this, iFriendFlags);
  int result = this->internal->GetFriendCount(iFriendFlags);
  TRACE(" = (int)%d\n", result);
  return result;
}
CSteamID* ISteamFriends_::GetFriendByIndex(CSteamID* hidden, int iFriend, int iFriendFlags )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID*)%p, (int)%d, (int)%d)\n", this, hidden, iFriend, iFriendFlags);
  *hidden = this->internal->GetFriendByIndex(iFriend, iFriendFlags);
  return hidden;
}
EFriendRelationship ISteamFriends_::GetFriendRelationship( CSteamID steamIDFriend )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDFriend);
  EFriendRelationship result = this->internal->GetFriendRelationship(steamIDFriend);
  TRACE(" = (EFriendRelationship)%p\n", result);
  return result;
}
EPersonaState ISteamFriends_::GetFriendPersonaState( CSteamID steamIDFriend )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDFriend);
  EPersonaState result = this->internal->GetFriendPersonaState(steamIDFriend);
  TRACE(" = (EPersonaState)%p\n", result);
  return result;
}
const char * ISteamFriends_::GetFriendPersonaName( CSteamID steamIDFriend )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDFriend);
  const char * result = this->internal->GetFriendPersonaName(steamIDFriend);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
bool ISteamFriends_::GetFriendGamePlayed( CSteamID steamIDFriend, OUT_STRUCT() FriendGameInfo_t *pFriendGameInfo )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p, (FriendGameInfo_t *)%p)\n", this, steamIDFriend, pFriendGameInfo);
  bool result = this->internal->GetFriendGamePlayed(steamIDFriend, pFriendGameInfo);
  TRACE(" = (bool)%d\n", result);
  return result;
}
const char * ISteamFriends_::GetFriendPersonaNameHistory( CSteamID steamIDFriend, int iPersonaName )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p, (int)%d)\n", this, steamIDFriend, iPersonaName);
  const char * result = this->internal->GetFriendPersonaNameHistory(steamIDFriend, iPersonaName);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
int ISteamFriends_::GetFriendSteamLevel( CSteamID steamIDFriend )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDFriend);
  int result = this->internal->GetFriendSteamLevel(steamIDFriend);
  TRACE(" = (int)%d\n", result);
  return result;
}
const char * ISteamFriends_::GetPlayerNickname( CSteamID steamIDPlayer )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDPlayer);
  const char * result = this->internal->GetPlayerNickname(steamIDPlayer);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
int ISteamFriends_::GetFriendsGroupCount()
{
  TRACE("((this[ISteamFriends])%p)\n", this);
  int result = this->internal->GetFriendsGroupCount();
  TRACE(" = (int)%d\n", result);
  return result;
}
FriendsGroupID_t ISteamFriends_::GetFriendsGroupIDByIndex( int iFG )
{
  TRACE("((this[ISteamFriends])%p, (int)%d)\n", this, iFG);
  FriendsGroupID_t result = this->internal->GetFriendsGroupIDByIndex(iFG);
  TRACE(" = (FriendsGroupID_t)%p\n", result);
  return result;
}
const char * ISteamFriends_::GetFriendsGroupName( FriendsGroupID_t friendsGroupID )
{
  TRACE("((this[ISteamFriends])%p, (FriendsGroupID_t)%p)\n", this, friendsGroupID);
  const char * result = this->internal->GetFriendsGroupName(friendsGroupID);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
int ISteamFriends_::GetFriendsGroupMembersCount( FriendsGroupID_t friendsGroupID )
{
  TRACE("((this[ISteamFriends])%p, (FriendsGroupID_t)%p)\n", this, friendsGroupID);
  int result = this->internal->GetFriendsGroupMembersCount(friendsGroupID);
  TRACE(" = (int)%d\n", result);
  return result;
}
void ISteamFriends_::GetFriendsGroupMembersList( FriendsGroupID_t friendsGroupID, OUT_ARRAY_CALL(nMembersCount, GetFriendsGroupMembersCount, friendsGroupID ) CSteamID *pOutSteamIDMembers, int nMembersCount )
{
  TRACE("((this[ISteamFriends])%p, (FriendsGroupID_t)%p, (CSteamID *)%p, (int)%d)\n", this, friendsGroupID, pOutSteamIDMembers, nMembersCount);
  this->internal->GetFriendsGroupMembersList(friendsGroupID, pOutSteamIDMembers, nMembersCount);
}
bool ISteamFriends_::HasFriend( CSteamID steamIDFriend, int iFriendFlags )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p, (int)%d)\n", this, steamIDFriend, iFriendFlags);
  bool result = this->internal->HasFriend(steamIDFriend, iFriendFlags);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int ISteamFriends_::GetClanCount()
{
  TRACE("((this[ISteamFriends])%p)\n", this);
  int result = this->internal->GetClanCount();
  TRACE(" = (int)%d\n", result);
  return result;
}
CSteamID* ISteamFriends_::GetClanByIndex(CSteamID* hidden, int iClan )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID*)%p, (int)%d)\n", this, hidden, iClan);
  *hidden = this->internal->GetClanByIndex(iClan);
  return hidden;
}
const char * ISteamFriends_::GetClanName( CSteamID steamIDClan )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDClan);
  const char * result = this->internal->GetClanName(steamIDClan);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
const char * ISteamFriends_::GetClanTag( CSteamID steamIDClan )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDClan);
  const char * result = this->internal->GetClanTag(steamIDClan);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
bool ISteamFriends_::GetClanActivityCounts( CSteamID steamIDClan, int *pnOnline, int *pnInGame, int *pnChatting )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p, (int *)%p, (int *)%p, (int *)%p)\n", this, steamIDClan, pnOnline, pnInGame, pnChatting);
  bool result = this->internal->GetClanActivityCounts(steamIDClan, pnOnline, pnInGame, pnChatting);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t ISteamFriends_::DownloadClanActivityCounts( ARRAY_COUNT(cClansToRequest) CSteamID *psteamIDClans, int cClansToRequest )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID *)%p, (int)%d)\n", this, psteamIDClans, cClansToRequest);
  SteamAPICall_t result = this->internal->DownloadClanActivityCounts(psteamIDClans, cClansToRequest);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
int ISteamFriends_::GetFriendCountFromSource( CSteamID steamIDSource )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDSource);
  int result = this->internal->GetFriendCountFromSource(steamIDSource);
  TRACE(" = (int)%d\n", result);
  return result;
}
CSteamID* ISteamFriends_::GetFriendFromSourceByIndex(CSteamID* hidden, CSteamID steamIDSource, int iFriend )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID*)%p, (CSteamID)%p, (int)%d)\n", this, hidden, steamIDSource, iFriend);
  *hidden = this->internal->GetFriendFromSourceByIndex(steamIDSource, iFriend);
  return hidden;
}
bool ISteamFriends_::IsUserInSource( CSteamID steamIDUser, CSteamID steamIDSource )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p, (CSteamID)%p)\n", this, steamIDUser, steamIDSource);
  bool result = this->internal->IsUserInSource(steamIDUser, steamIDSource);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void ISteamFriends_::SetInGameVoiceSpeaking( CSteamID steamIDUser, bool bSpeaking )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p, (bool)%d)\n", this, steamIDUser, bSpeaking);
  this->internal->SetInGameVoiceSpeaking(steamIDUser, bSpeaking);
}
void ISteamFriends_::ActivateGameOverlay( const char *pchDialog )
{
  TRACE("((this[ISteamFriends])%p, (const char *)\"%s\")\n", this, pchDialog);
  this->internal->ActivateGameOverlay(pchDialog);
}
void ISteamFriends_::ActivateGameOverlayToUser( const char *pchDialog, CSteamID steamID )
{
  TRACE("((this[ISteamFriends])%p, (const char *)\"%s\", (CSteamID)%p)\n", this, pchDialog, steamID);
  this->internal->ActivateGameOverlayToUser(pchDialog, steamID);
}
void ISteamFriends_::ActivateGameOverlayToWebPage( const char *pchURL )
{
  TRACE("((this[ISteamFriends])%p, (const char *)\"%s\")\n", this, pchURL);
  this->internal->ActivateGameOverlayToWebPage(pchURL);
}
void ISteamFriends_::ActivateGameOverlayToStore( AppId_t nAppID, EOverlayToStoreFlag eFlag )
{
  TRACE("((this[ISteamFriends])%p, (AppId_t)%p, (EOverlayToStoreFlag)%p)\n", this, nAppID, eFlag);
  this->internal->ActivateGameOverlayToStore(nAppID, eFlag);
}
void ISteamFriends_::SetPlayedWith( CSteamID steamIDUserPlayedWith )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDUserPlayedWith);
  this->internal->SetPlayedWith(steamIDUserPlayedWith);
}
void ISteamFriends_::ActivateGameOverlayInviteDialog( CSteamID steamIDLobby )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDLobby);
  this->internal->ActivateGameOverlayInviteDialog(steamIDLobby);
}
int ISteamFriends_::GetSmallFriendAvatar( CSteamID steamIDFriend )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDFriend);
  int result = this->internal->GetSmallFriendAvatar(steamIDFriend);
  TRACE(" = (int)%d\n", result);
  return result;
}
int ISteamFriends_::GetMediumFriendAvatar( CSteamID steamIDFriend )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDFriend);
  int result = this->internal->GetMediumFriendAvatar(steamIDFriend);
  TRACE(" = (int)%d\n", result);
  return result;
}
int ISteamFriends_::GetLargeFriendAvatar( CSteamID steamIDFriend )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDFriend);
  int result = this->internal->GetLargeFriendAvatar(steamIDFriend);
  TRACE(" = (int)%d\n", result);
  return result;
}
bool ISteamFriends_::RequestUserInformation( CSteamID steamIDUser, bool bRequireNameOnly )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p, (bool)%d)\n", this, steamIDUser, bRequireNameOnly);
  bool result = this->internal->RequestUserInformation(steamIDUser, bRequireNameOnly);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t ISteamFriends_::RequestClanOfficerList( CSteamID steamIDClan )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDClan);
  SteamAPICall_t result = this->internal->RequestClanOfficerList(steamIDClan);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
CSteamID* ISteamFriends_::GetClanOwner(CSteamID* hidden, CSteamID steamIDClan )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID*)%p, (CSteamID)%p)\n", this, hidden, steamIDClan);
  *hidden = this->internal->GetClanOwner(steamIDClan);
  return hidden;
}
int ISteamFriends_::GetClanOfficerCount( CSteamID steamIDClan )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDClan);
  int result = this->internal->GetClanOfficerCount(steamIDClan);
  TRACE(" = (int)%d\n", result);
  return result;
}
CSteamID* ISteamFriends_::GetClanOfficerByIndex(CSteamID* hidden, CSteamID steamIDClan, int iOfficer )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID*)%p, (CSteamID)%p, (int)%d)\n", this, hidden, steamIDClan, iOfficer);
  *hidden = this->internal->GetClanOfficerByIndex(steamIDClan, iOfficer);
  return hidden;
}
uint32 ISteamFriends_::GetUserRestrictions()
{
  TRACE("((this[ISteamFriends])%p)\n", this);
  uint32 result = this->internal->GetUserRestrictions();
  TRACE(" = (uint32)%d\n", result);
  return result;
}
bool ISteamFriends_::SetRichPresence( const char *pchKey, const char *pchValue )
{
  TRACE("((this[ISteamFriends])%p, (const char *)\"%s\", (const char *)\"%s\")\n", this, pchKey, pchValue);
  bool result = this->internal->SetRichPresence(pchKey, pchValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void ISteamFriends_::ClearRichPresence()
{
  TRACE("((this[ISteamFriends])%p)\n", this);
  this->internal->ClearRichPresence();
}
const char * ISteamFriends_::GetFriendRichPresence( CSteamID steamIDFriend, const char *pchKey )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p, (const char *)\"%s\")\n", this, steamIDFriend, pchKey);
  const char * result = this->internal->GetFriendRichPresence(steamIDFriend, pchKey);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
int ISteamFriends_::GetFriendRichPresenceKeyCount( CSteamID steamIDFriend )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDFriend);
  int result = this->internal->GetFriendRichPresenceKeyCount(steamIDFriend);
  TRACE(" = (int)%d\n", result);
  return result;
}
const char * ISteamFriends_::GetFriendRichPresenceKeyByIndex( CSteamID steamIDFriend, int iKey )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p, (int)%d)\n", this, steamIDFriend, iKey);
  const char * result = this->internal->GetFriendRichPresenceKeyByIndex(steamIDFriend, iKey);
  TRACE(" = (const char *)\"%s\"\n", result);
  return result;
}
void ISteamFriends_::RequestFriendRichPresence( CSteamID steamIDFriend )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDFriend);
  this->internal->RequestFriendRichPresence(steamIDFriend);
}
bool ISteamFriends_::InviteUserToGame( CSteamID steamIDFriend, const char *pchConnectString )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p, (const char *)\"%s\")\n", this, steamIDFriend, pchConnectString);
  bool result = this->internal->InviteUserToGame(steamIDFriend, pchConnectString);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int ISteamFriends_::GetCoplayFriendCount()
{
  TRACE("((this[ISteamFriends])%p)\n", this);
  int result = this->internal->GetCoplayFriendCount();
  TRACE(" = (int)%d\n", result);
  return result;
}
CSteamID* ISteamFriends_::GetCoplayFriend(CSteamID* hidden, int iCoplayFriend )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID*)%p, (int)%d)\n", this, hidden, iCoplayFriend);
  *hidden = this->internal->GetCoplayFriend(iCoplayFriend);
  return hidden;
}
int ISteamFriends_::GetFriendCoplayTime( CSteamID steamIDFriend )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDFriend);
  int result = this->internal->GetFriendCoplayTime(steamIDFriend);
  TRACE(" = (int)%d\n", result);
  return result;
}
AppId_t ISteamFriends_::GetFriendCoplayGame( CSteamID steamIDFriend )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDFriend);
  AppId_t result = this->internal->GetFriendCoplayGame(steamIDFriend);
  TRACE(" = (AppId_t)%p\n", result);
  return result;
}
SteamAPICall_t ISteamFriends_::JoinClanChatRoom( CSteamID steamIDClan )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDClan);
  SteamAPICall_t result = this->internal->JoinClanChatRoom(steamIDClan);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
bool ISteamFriends_::LeaveClanChatRoom( CSteamID steamIDClan )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDClan);
  bool result = this->internal->LeaveClanChatRoom(steamIDClan);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int ISteamFriends_::GetClanChatMemberCount( CSteamID steamIDClan )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDClan);
  int result = this->internal->GetClanChatMemberCount(steamIDClan);
  TRACE(" = (int)%d\n", result);
  return result;
}
CSteamID* ISteamFriends_::GetChatMemberByIndex(CSteamID* hidden, CSteamID steamIDClan, int iUser )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID*)%p, (CSteamID)%p, (int)%d)\n", this, hidden, steamIDClan, iUser);
  *hidden = this->internal->GetChatMemberByIndex(steamIDClan, iUser);
  return hidden;
}
bool ISteamFriends_::SendClanChatMessage( CSteamID steamIDClanChat, const char *pchText )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p, (const char *)\"%s\")\n", this, steamIDClanChat, pchText);
  bool result = this->internal->SendClanChatMessage(steamIDClanChat, pchText);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int ISteamFriends_::GetClanChatMessage( CSteamID steamIDClanChat, int iMessage, void *prgchText, int cchTextMax, EChatEntryType *peChatEntryType, OUT_STRUCT() CSteamID *psteamidChatter )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p, (int)%d, (void *)%p, (int)%d, (EChatEntryType *)%p, (CSteamID *)%p)\n", this, steamIDClanChat, iMessage, prgchText, cchTextMax, peChatEntryType, psteamidChatter);
  int result = this->internal->GetClanChatMessage(steamIDClanChat, iMessage, prgchText, cchTextMax, peChatEntryType, psteamidChatter);
  TRACE(" = (int)%d\n", result);
  return result;
}
bool ISteamFriends_::IsClanChatAdmin( CSteamID steamIDClanChat, CSteamID steamIDUser )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p, (CSteamID)%p)\n", this, steamIDClanChat, steamIDUser);
  bool result = this->internal->IsClanChatAdmin(steamIDClanChat, steamIDUser);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamFriends_::IsClanChatWindowOpenInSteam( CSteamID steamIDClanChat )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDClanChat);
  bool result = this->internal->IsClanChatWindowOpenInSteam(steamIDClanChat);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamFriends_::OpenClanChatWindowInSteam( CSteamID steamIDClanChat )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDClanChat);
  bool result = this->internal->OpenClanChatWindowInSteam(steamIDClanChat);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamFriends_::CloseClanChatWindowInSteam( CSteamID steamIDClanChat )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamIDClanChat);
  bool result = this->internal->CloseClanChatWindowInSteam(steamIDClanChat);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamFriends_::SetListenForFriendsMessages( bool bInterceptEnabled )
{
  TRACE("((this[ISteamFriends])%p, (bool)%d)\n", this, bInterceptEnabled);
  bool result = this->internal->SetListenForFriendsMessages(bInterceptEnabled);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamFriends_::ReplyToFriendMessage( CSteamID steamIDFriend, const char *pchMsgToSend )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p, (const char *)\"%s\")\n", this, steamIDFriend, pchMsgToSend);
  bool result = this->internal->ReplyToFriendMessage(steamIDFriend, pchMsgToSend);
  TRACE(" = (bool)%d\n", result);
  return result;
}
int ISteamFriends_::GetFriendMessage( CSteamID steamIDFriend, int iMessageID, void *pvData, int cubData, EChatEntryType *peChatEntryType )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p, (int)%d, (void *)%p, (int)%d, (EChatEntryType *)%p)\n", this, steamIDFriend, iMessageID, pvData, cubData, peChatEntryType);
  int result = this->internal->GetFriendMessage(steamIDFriend, iMessageID, pvData, cubData, peChatEntryType);
  TRACE(" = (int)%d\n", result);
  return result;
}
SteamAPICall_t ISteamFriends_::GetFollowerCount( CSteamID steamID )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamID);
  SteamAPICall_t result = this->internal->GetFollowerCount(steamID);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t ISteamFriends_::IsFollowing( CSteamID steamID )
{
  TRACE("((this[ISteamFriends])%p, (CSteamID)%p)\n", this, steamID);
  SteamAPICall_t result = this->internal->IsFollowing(steamID);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t ISteamFriends_::EnumerateFollowingList( uint32 unStartIndex )
{
  TRACE("((this[ISteamFriends])%p, (uint32)%d)\n", this, unStartIndex);
  SteamAPICall_t result = this->internal->EnumerateFollowingList(unStartIndex);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
#endif
