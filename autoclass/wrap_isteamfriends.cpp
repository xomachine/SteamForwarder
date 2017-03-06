#include <steam_api_.h>

char * ISteamFriends_::GetPersonaName()
{
  TRACE("((ISteamFriends *)%p)\n", this);
  auto result = this->internal->GetPersonaName();
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


SteamAPICall_t  ISteamFriends_::SetPersonaName(char * pchPersonaName)
{
  TRACE("((ISteamFriends *)%p, (char *)\"%s\")\n", this, pchPersonaName);
  auto result = this->internal->SetPersonaName(pchPersonaName);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


EPersonaState  ISteamFriends_::GetPersonaState()
{
  TRACE("((ISteamFriends *)%p)\n", this);
  auto result = this->internal->GetPersonaState();
  TRACE("() = (EPersonaState )%p\n", result);

  return result;
}


int  ISteamFriends_::GetFriendCount(int  iFriendFlags)
{
  TRACE("((ISteamFriends *)%p, (int )%d)\n", this, iFriendFlags);
  auto result = this->internal->GetFriendCount(iFriendFlags);
  TRACE("() = (int )%d\n", result);

  return result;
}


CSteamID * ISteamFriends_::GetFriendByIndex(CSteamID * hidden, int  iFriend, int  iFriendFlags)
{
  TRACE("((ISteamFriends *)%p, (int )%d, (int )%d)\n", this, iFriend, iFriendFlags);
  *hidden = this->internal->GetFriendByIndex(iFriend, iFriendFlags);
  return hidden;
}


EFriendRelationship  ISteamFriends_::GetFriendRelationship(CSteamID  steamIDFriend)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDFriend);
  auto result = this->internal->GetFriendRelationship(steamIDFriend);
  TRACE("() = (EFriendRelationship )%p\n", result);

  return result;
}


EPersonaState  ISteamFriends_::GetFriendPersonaState(CSteamID  steamIDFriend)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDFriend);
  auto result = this->internal->GetFriendPersonaState(steamIDFriend);
  TRACE("() = (EPersonaState )%p\n", result);

  return result;
}


char * ISteamFriends_::GetFriendPersonaName(CSteamID  steamIDFriend)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDFriend);
  auto result = this->internal->GetFriendPersonaName(steamIDFriend);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


bool  ISteamFriends_::GetFriendGamePlayed(CSteamID  steamIDFriend, FriendGameInfo_t * pFriendGameInfo)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p, (FriendGameInfo_t *)%p)\n", this, steamIDFriend, pFriendGameInfo);
  auto result = this->internal->GetFriendGamePlayed(steamIDFriend, pFriendGameInfo);
  TRACE("() = (bool )%d\n", result);

  return result;
}


char * ISteamFriends_::GetFriendPersonaNameHistory(CSteamID  steamIDFriend, int  iPersonaName)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p, (int )%d)\n", this, steamIDFriend, iPersonaName);
  auto result = this->internal->GetFriendPersonaNameHistory(steamIDFriend, iPersonaName);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


int  ISteamFriends_::GetFriendSteamLevel(CSteamID  steamIDFriend)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDFriend);
  auto result = this->internal->GetFriendSteamLevel(steamIDFriend);
  TRACE("() = (int )%d\n", result);

  return result;
}


char * ISteamFriends_::GetPlayerNickname(CSteamID  steamIDPlayer)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDPlayer);
  auto result = this->internal->GetPlayerNickname(steamIDPlayer);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


int  ISteamFriends_::GetFriendsGroupCount()
{
  TRACE("((ISteamFriends *)%p)\n", this);
  auto result = this->internal->GetFriendsGroupCount();
  TRACE("() = (int )%d\n", result);

  return result;
}


FriendsGroupID_t  ISteamFriends_::GetFriendsGroupIDByIndex(int  iFG)
{
  TRACE("((ISteamFriends *)%p, (int )%d)\n", this, iFG);
  auto result = this->internal->GetFriendsGroupIDByIndex(iFG);
  TRACE("() = (FriendsGroupID_t )%p\n", result);

  return result;
}


char * ISteamFriends_::GetFriendsGroupName(FriendsGroupID_t  friendsGroupID)
{
  TRACE("((ISteamFriends *)%p, (FriendsGroupID_t )%p)\n", this, friendsGroupID);
  auto result = this->internal->GetFriendsGroupName(friendsGroupID);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


int  ISteamFriends_::GetFriendsGroupMembersCount(FriendsGroupID_t  friendsGroupID)
{
  TRACE("((ISteamFriends *)%p, (FriendsGroupID_t )%p)\n", this, friendsGroupID);
  auto result = this->internal->GetFriendsGroupMembersCount(friendsGroupID);
  TRACE("() = (int )%d\n", result);

  return result;
}


void  ISteamFriends_::GetFriendsGroupMembersList(FriendsGroupID_t  friendsGroupID, CSteamID * pOutSteamIDMembers, int  nMembersCount)
{
  TRACE("((ISteamFriends *)%p, (FriendsGroupID_t )%p, (CSteamID *)%p, (int )%d)\n", this, friendsGroupID, pOutSteamIDMembers, nMembersCount);
  this->internal->GetFriendsGroupMembersList(friendsGroupID, pOutSteamIDMembers, nMembersCount);
  
}


bool  ISteamFriends_::HasFriend(CSteamID  steamIDFriend, int  iFriendFlags)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p, (int )%d)\n", this, steamIDFriend, iFriendFlags);
  auto result = this->internal->HasFriend(steamIDFriend, iFriendFlags);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  ISteamFriends_::GetClanCount()
{
  TRACE("((ISteamFriends *)%p)\n", this);
  auto result = this->internal->GetClanCount();
  TRACE("() = (int )%d\n", result);

  return result;
}


CSteamID * ISteamFriends_::GetClanByIndex(CSteamID * hidden, int  iClan)
{
  TRACE("((ISteamFriends *)%p, (int )%d)\n", this, iClan);
  *hidden = this->internal->GetClanByIndex(iClan);
  return hidden;
}


char * ISteamFriends_::GetClanName(CSteamID  steamIDClan)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDClan);
  auto result = this->internal->GetClanName(steamIDClan);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


char * ISteamFriends_::GetClanTag(CSteamID  steamIDClan)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDClan);
  auto result = this->internal->GetClanTag(steamIDClan);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


bool  ISteamFriends_::GetClanActivityCounts(CSteamID  steamIDClan, int * pnOnline, int * pnInGame, int * pnChatting)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p, (int *)%d, (int *)%d, (int *)%d)\n", this, steamIDClan, pnOnline, pnInGame, pnChatting);
  auto result = this->internal->GetClanActivityCounts(steamIDClan, pnOnline, pnInGame, pnChatting);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  ISteamFriends_::DownloadClanActivityCounts(CSteamID * psteamIDClans, int  cClansToRequest)
{
  TRACE("((ISteamFriends *)%p, (CSteamID *)%p, (int )%d)\n", this, psteamIDClans, cClansToRequest);
  auto result = this->internal->DownloadClanActivityCounts(psteamIDClans, cClansToRequest);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


int  ISteamFriends_::GetFriendCountFromSource(CSteamID  steamIDSource)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDSource);
  auto result = this->internal->GetFriendCountFromSource(steamIDSource);
  TRACE("() = (int )%d\n", result);

  return result;
}


CSteamID * ISteamFriends_::GetFriendFromSourceByIndex(CSteamID * hidden, CSteamID  steamIDSource, int  iFriend)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p, (int )%d)\n", this, steamIDSource, iFriend);
  *hidden = this->internal->GetFriendFromSourceByIndex(steamIDSource, iFriend);
  return hidden;
}


bool  ISteamFriends_::IsUserInSource(CSteamID  steamIDUser, CSteamID  steamIDSource)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p, (CSteamID )%p)\n", this, steamIDUser, steamIDSource);
  auto result = this->internal->IsUserInSource(steamIDUser, steamIDSource);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  ISteamFriends_::SetInGameVoiceSpeaking(CSteamID  steamIDUser, bool  bSpeaking)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p, (bool )%d)\n", this, steamIDUser, bSpeaking);
  this->internal->SetInGameVoiceSpeaking(steamIDUser, bSpeaking);
  
}


void  ISteamFriends_::ActivateGameOverlay(char * pchDialog)
{
  TRACE("((ISteamFriends *)%p, (char *)\"%s\")\n", this, pchDialog);
  this->internal->ActivateGameOverlay(pchDialog);
  
}


void  ISteamFriends_::ActivateGameOverlayToUser(char * pchDialog, CSteamID  steamID)
{
  TRACE("((ISteamFriends *)%p, (char *)\"%s\", (CSteamID )%p)\n", this, pchDialog, steamID);
  this->internal->ActivateGameOverlayToUser(pchDialog, steamID);
  
}


void  ISteamFriends_::ActivateGameOverlayToWebPage(char * pchURL)
{
  TRACE("((ISteamFriends *)%p, (char *)\"%s\")\n", this, pchURL);
  this->internal->ActivateGameOverlayToWebPage(pchURL);
  
}


void  ISteamFriends_::ActivateGameOverlayToStore(AppId_t  nAppID, EOverlayToStoreFlag  eFlag)
{
  TRACE("((ISteamFriends *)%p, (AppId_t )%p, (EOverlayToStoreFlag )%p)\n", this, nAppID, eFlag);
  this->internal->ActivateGameOverlayToStore(nAppID, eFlag);
  
}


void  ISteamFriends_::SetPlayedWith(CSteamID  steamIDUserPlayedWith)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDUserPlayedWith);
  this->internal->SetPlayedWith(steamIDUserPlayedWith);
  
}


void  ISteamFriends_::ActivateGameOverlayInviteDialog(CSteamID  steamIDLobby)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDLobby);
  this->internal->ActivateGameOverlayInviteDialog(steamIDLobby);
  
}


int  ISteamFriends_::GetSmallFriendAvatar(CSteamID  steamIDFriend)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDFriend);
  auto result = this->internal->GetSmallFriendAvatar(steamIDFriend);
  TRACE("() = (int )%d\n", result);

  return result;
}


int  ISteamFriends_::GetMediumFriendAvatar(CSteamID  steamIDFriend)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDFriend);
  auto result = this->internal->GetMediumFriendAvatar(steamIDFriend);
  TRACE("() = (int )%d\n", result);

  return result;
}


int  ISteamFriends_::GetLargeFriendAvatar(CSteamID  steamIDFriend)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDFriend);
  auto result = this->internal->GetLargeFriendAvatar(steamIDFriend);
  TRACE("() = (int )%d\n", result);

  return result;
}


bool  ISteamFriends_::RequestUserInformation(CSteamID  steamIDUser, bool  bRequireNameOnly)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p, (bool )%d)\n", this, steamIDUser, bRequireNameOnly);
  auto result = this->internal->RequestUserInformation(steamIDUser, bRequireNameOnly);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  ISteamFriends_::RequestClanOfficerList(CSteamID  steamIDClan)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDClan);
  auto result = this->internal->RequestClanOfficerList(steamIDClan);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


CSteamID * ISteamFriends_::GetClanOwner(CSteamID * hidden, CSteamID  steamIDClan)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDClan);
  *hidden = this->internal->GetClanOwner(steamIDClan);
  return hidden;
}


int  ISteamFriends_::GetClanOfficerCount(CSteamID  steamIDClan)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDClan);
  auto result = this->internal->GetClanOfficerCount(steamIDClan);
  TRACE("() = (int )%d\n", result);

  return result;
}


CSteamID * ISteamFriends_::GetClanOfficerByIndex(CSteamID * hidden, CSteamID  steamIDClan, int  iOfficer)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p, (int )%d)\n", this, steamIDClan, iOfficer);
  *hidden = this->internal->GetClanOfficerByIndex(steamIDClan, iOfficer);
  return hidden;
}


uint32  ISteamFriends_::GetUserRestrictions()
{
  TRACE("((ISteamFriends *)%p)\n", this);
  auto result = this->internal->GetUserRestrictions();
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


bool  ISteamFriends_::SetRichPresence(char * pchKey, char * pchValue)
{
  TRACE("((ISteamFriends *)%p, (char *)\"%s\", (char *)\"%s\")\n", this, pchKey, pchValue);
  auto result = this->internal->SetRichPresence(pchKey, pchValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  ISteamFriends_::ClearRichPresence()
{
  TRACE("((ISteamFriends *)%p)\n", this);
  this->internal->ClearRichPresence();
  
}


char * ISteamFriends_::GetFriendRichPresence(CSteamID  steamIDFriend, char * pchKey)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p, (char *)\"%s\")\n", this, steamIDFriend, pchKey);
  auto result = this->internal->GetFriendRichPresence(steamIDFriend, pchKey);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


int  ISteamFriends_::GetFriendRichPresenceKeyCount(CSteamID  steamIDFriend)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDFriend);
  auto result = this->internal->GetFriendRichPresenceKeyCount(steamIDFriend);
  TRACE("() = (int )%d\n", result);

  return result;
}


char * ISteamFriends_::GetFriendRichPresenceKeyByIndex(CSteamID  steamIDFriend, int  iKey)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p, (int )%d)\n", this, steamIDFriend, iKey);
  auto result = this->internal->GetFriendRichPresenceKeyByIndex(steamIDFriend, iKey);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


void  ISteamFriends_::RequestFriendRichPresence(CSteamID  steamIDFriend)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDFriend);
  this->internal->RequestFriendRichPresence(steamIDFriend);
  
}


bool  ISteamFriends_::InviteUserToGame(CSteamID  steamIDFriend, char * pchConnectString)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p, (char *)\"%s\")\n", this, steamIDFriend, pchConnectString);
  auto result = this->internal->InviteUserToGame(steamIDFriend, pchConnectString);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  ISteamFriends_::GetCoplayFriendCount()
{
  TRACE("((ISteamFriends *)%p)\n", this);
  auto result = this->internal->GetCoplayFriendCount();
  TRACE("() = (int )%d\n", result);

  return result;
}


CSteamID * ISteamFriends_::GetCoplayFriend(CSteamID * hidden, int  iCoplayFriend)
{
  TRACE("((ISteamFriends *)%p, (int )%d)\n", this, iCoplayFriend);
  *hidden = this->internal->GetCoplayFriend(iCoplayFriend);
  return hidden;
}


int  ISteamFriends_::GetFriendCoplayTime(CSteamID  steamIDFriend)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDFriend);
  auto result = this->internal->GetFriendCoplayTime(steamIDFriend);
  TRACE("() = (int )%d\n", result);

  return result;
}


AppId_t  ISteamFriends_::GetFriendCoplayGame(CSteamID  steamIDFriend)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDFriend);
  auto result = this->internal->GetFriendCoplayGame(steamIDFriend);
  TRACE("() = (AppId_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamFriends_::JoinClanChatRoom(CSteamID  steamIDClan)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDClan);
  auto result = this->internal->JoinClanChatRoom(steamIDClan);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  ISteamFriends_::LeaveClanChatRoom(CSteamID  steamIDClan)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDClan);
  auto result = this->internal->LeaveClanChatRoom(steamIDClan);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  ISteamFriends_::GetClanChatMemberCount(CSteamID  steamIDClan)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDClan);
  auto result = this->internal->GetClanChatMemberCount(steamIDClan);
  TRACE("() = (int )%d\n", result);

  return result;
}


CSteamID * ISteamFriends_::GetChatMemberByIndex(CSteamID * hidden, CSteamID  steamIDClan, int  iUser)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p, (int )%d)\n", this, steamIDClan, iUser);
  *hidden = this->internal->GetChatMemberByIndex(steamIDClan, iUser);
  return hidden;
}


bool  ISteamFriends_::SendClanChatMessage(CSteamID  steamIDClanChat, char * pchText)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p, (char *)\"%s\")\n", this, steamIDClanChat, pchText);
  auto result = this->internal->SendClanChatMessage(steamIDClanChat, pchText);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  ISteamFriends_::GetClanChatMessage(CSteamID  steamIDClanChat, int  iMessage, void * prgchText, int  cchTextMax, EChatEntryType * peChatEntryType, CSteamID * psteamidChatter)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p, (int )%d, (void *)%p, (int )%d, (EChatEntryType *)%p, (CSteamID *)%p)\n", this, steamIDClanChat, iMessage, prgchText, cchTextMax, peChatEntryType, psteamidChatter);
  auto result = this->internal->GetClanChatMessage(steamIDClanChat, iMessage, prgchText, cchTextMax, peChatEntryType, psteamidChatter);
  TRACE("() = (int )%d\n", result);

  return result;
}


bool  ISteamFriends_::IsClanChatAdmin(CSteamID  steamIDClanChat, CSteamID  steamIDUser)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p, (CSteamID )%p)\n", this, steamIDClanChat, steamIDUser);
  auto result = this->internal->IsClanChatAdmin(steamIDClanChat, steamIDUser);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamFriends_::IsClanChatWindowOpenInSteam(CSteamID  steamIDClanChat)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDClanChat);
  auto result = this->internal->IsClanChatWindowOpenInSteam(steamIDClanChat);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamFriends_::OpenClanChatWindowInSteam(CSteamID  steamIDClanChat)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDClanChat);
  auto result = this->internal->OpenClanChatWindowInSteam(steamIDClanChat);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamFriends_::CloseClanChatWindowInSteam(CSteamID  steamIDClanChat)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamIDClanChat);
  auto result = this->internal->CloseClanChatWindowInSteam(steamIDClanChat);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamFriends_::SetListenForFriendsMessages(bool  bInterceptEnabled)
{
  TRACE("((ISteamFriends *)%p, (bool )%d)\n", this, bInterceptEnabled);
  auto result = this->internal->SetListenForFriendsMessages(bInterceptEnabled);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamFriends_::ReplyToFriendMessage(CSteamID  steamIDFriend, char * pchMsgToSend)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p, (char *)\"%s\")\n", this, steamIDFriend, pchMsgToSend);
  auto result = this->internal->ReplyToFriendMessage(steamIDFriend, pchMsgToSend);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int  ISteamFriends_::GetFriendMessage(CSteamID  steamIDFriend, int  iMessageID, void * pvData, int  cubData, EChatEntryType * peChatEntryType)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p, (int )%d, (void *)%p, (int )%d, (EChatEntryType *)%p)\n", this, steamIDFriend, iMessageID, pvData, cubData, peChatEntryType);
  auto result = this->internal->GetFriendMessage(steamIDFriend, iMessageID, pvData, cubData, peChatEntryType);
  TRACE("() = (int )%d\n", result);

  return result;
}


SteamAPICall_t  ISteamFriends_::GetFollowerCount(CSteamID  steamID)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamID);
  auto result = this->internal->GetFollowerCount(steamID);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamFriends_::IsFollowing(CSteamID  steamID)
{
  TRACE("((ISteamFriends *)%p, (CSteamID )%p)\n", this, steamID);
  auto result = this->internal->IsFollowing(steamID);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamFriends_::EnumerateFollowingList(uint32  unStartIndex)
{
  TRACE("((ISteamFriends *)%p, (uint32 )%d)\n", this, unStartIndex);
  auto result = this->internal->EnumerateFollowingList(unStartIndex);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}
ISteamFriends_::ISteamFriends_(ISteamFriends * towrap)
{
  this->internal = towrap;
}

ISteamFriends_::~ISteamFriends_()
{
  delete this->internal;
}
