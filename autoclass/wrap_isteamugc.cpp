#ifndef WRAP_ISTEAMUGC_CPP
#define WRAP_ISTEAMUGC_CPP
#include "autoclass/steam_api_.h" 
#include "windef.h"
#include "wine/debug.h"
#include "config.h"
UGCQueryHandle_t ISteamUGC_::CreateQueryUserUGCRequest( AccountID_t unAccountID, EUserUGCList eListType, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eSortOrder, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage )
{
  TRACE("((this[ISteamUGC])%p, (AccountID_t)%p, (EUserUGCList)%p, (EUGCMatchingUGCType)%p, (EUserUGCListSortOrder)%p, (AppId_t)%p, (AppId_t)%p, (uint32)%d)\n", this, unAccountID, eListType, eMatchingUGCType, eSortOrder, nCreatorAppID, nConsumerAppID, unPage);
  UGCQueryHandle_t result = this->internal->CreateQueryUserUGCRequest(unAccountID, eListType, eMatchingUGCType, eSortOrder, nCreatorAppID, nConsumerAppID, unPage);
  TRACE(" = (UGCQueryHandle_t)%p\n", result);
  return result;
}
UGCQueryHandle_t ISteamUGC_::CreateQueryAllUGCRequest( EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage )
{
  TRACE("((this[ISteamUGC])%p, (EUGCQuery)%p, (EUGCMatchingUGCType)%p, (AppId_t)%p, (AppId_t)%p, (uint32)%d)\n", this, eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, unPage);
  UGCQueryHandle_t result = this->internal->CreateQueryAllUGCRequest(eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, unPage);
  TRACE(" = (UGCQueryHandle_t)%p\n", result);
  return result;
}
UGCQueryHandle_t ISteamUGC_::CreateQueryUGCDetailsRequest( PublishedFileId_t *pvecPublishedFileID, uint32 unNumPublishedFileIDs )
{
  TRACE("((this[ISteamUGC])%p, (PublishedFileId_t *)%p, (uint32)%d)\n", this, pvecPublishedFileID, unNumPublishedFileIDs);
  UGCQueryHandle_t result = this->internal->CreateQueryUGCDetailsRequest(pvecPublishedFileID, unNumPublishedFileIDs);
  TRACE(" = (UGCQueryHandle_t)%p\n", result);
  return result;
}
SteamAPICall_t ISteamUGC_::SendQueryUGCRequest( UGCQueryHandle_t handle )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p)\n", this, handle);
  SteamAPICall_t result = this->internal->SendQueryUGCRequest(handle);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
bool ISteamUGC_::GetQueryUGCResult( UGCQueryHandle_t handle, uint32 index, SteamUGCDetails_t *pDetails )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (uint32)%d, (SteamUGCDetails_t *)%p)\n", this, handle, index, pDetails);
  bool result = this->internal->GetQueryUGCResult(handle, index, pDetails);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::GetQueryUGCPreviewURL( UGCQueryHandle_t handle, uint32 index, OUT_STRING_COUNT(cchURLSize) char *pchURL, uint32 cchURLSize )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (uint32)%d, (char *)%p, (uint32)%d)\n", this, handle, index, pchURL, cchURLSize);
  bool result = this->internal->GetQueryUGCPreviewURL(handle, index, pchURL, cchURLSize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::GetQueryUGCMetadata( UGCQueryHandle_t handle, uint32 index, OUT_STRING_COUNT(cchMetadatasize) char *pchMetadata, uint32 cchMetadatasize )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (uint32)%d, (char *)%p, (uint32)%d)\n", this, handle, index, pchMetadata, cchMetadatasize);
  bool result = this->internal->GetQueryUGCMetadata(handle, index, pchMetadata, cchMetadatasize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::GetQueryUGCChildren( UGCQueryHandle_t handle, uint32 index, PublishedFileId_t* pvecPublishedFileID, uint32 cMaxEntries )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (uint32)%d, (PublishedFileId_t*)%p, (uint32)%d)\n", this, handle, index, pvecPublishedFileID, cMaxEntries);
  bool result = this->internal->GetQueryUGCChildren(handle, index, pvecPublishedFileID, cMaxEntries);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::GetQueryUGCStatistic( UGCQueryHandle_t handle, uint32 index, EItemStatistic eStatType, uint64 *pStatValue )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (uint32)%d, (EItemStatistic)%p, (uint64 *)%p)\n", this, handle, index, eStatType, pStatValue);
  bool result = this->internal->GetQueryUGCStatistic(handle, index, eStatType, pStatValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
uint32 ISteamUGC_::GetQueryUGCNumAdditionalPreviews( UGCQueryHandle_t handle, uint32 index )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (uint32)%d)\n", this, handle, index);
  uint32 result = this->internal->GetQueryUGCNumAdditionalPreviews(handle, index);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
bool ISteamUGC_::GetQueryUGCAdditionalPreview( UGCQueryHandle_t handle, uint32 index, uint32 previewIndex, OUT_STRING_COUNT(cchURLSize) char *pchURLOrVideoID, uint32 cchURLSize, OUT_STRING_COUNT(cchURLSize) char *pchOriginalFileName, uint32 cchOriginalFileNameSize, EItemPreviewType *pPreviewType )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (uint32)%d, (uint32)%d, (char *)%p, (uint32)%d, (char *)%p, (uint32)%d, (EItemPreviewType *)%p)\n", this, handle, index, previewIndex, pchURLOrVideoID, cchURLSize, pchOriginalFileName, cchOriginalFileNameSize, pPreviewType);
  bool result = this->internal->GetQueryUGCAdditionalPreview(handle, index, previewIndex, pchURLOrVideoID, cchURLSize, pchOriginalFileName, cchOriginalFileNameSize, pPreviewType);
  TRACE(" = (bool)%d\n", result);
  return result;
}
uint32 ISteamUGC_::GetQueryUGCNumKeyValueTags( UGCQueryHandle_t handle, uint32 index )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (uint32)%d)\n", this, handle, index);
  uint32 result = this->internal->GetQueryUGCNumKeyValueTags(handle, index);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
bool ISteamUGC_::GetQueryUGCKeyValueTag( UGCQueryHandle_t handle, uint32 index, uint32 keyValueTagIndex, OUT_STRING_COUNT(cchKeySize) char *pchKey, uint32 cchKeySize, OUT_STRING_COUNT(cchValueSize) char *pchValue, uint32 cchValueSize )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (uint32)%d, (uint32)%d, (char *)%p, (uint32)%d, (char *)%p, (uint32)%d)\n", this, handle, index, keyValueTagIndex, pchKey, cchKeySize, pchValue, cchValueSize);
  bool result = this->internal->GetQueryUGCKeyValueTag(handle, index, keyValueTagIndex, pchKey, cchKeySize, pchValue, cchValueSize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::ReleaseQueryUGCRequest( UGCQueryHandle_t handle )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p)\n", this, handle);
  bool result = this->internal->ReleaseQueryUGCRequest(handle);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::AddRequiredTag( UGCQueryHandle_t handle, const char *pTagName )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (const char *)\"%s\")\n", this, handle, pTagName);
  bool result = this->internal->AddRequiredTag(handle, pTagName);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::AddExcludedTag( UGCQueryHandle_t handle, const char *pTagName )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (const char *)\"%s\")\n", this, handle, pTagName);
  bool result = this->internal->AddExcludedTag(handle, pTagName);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::SetReturnOnlyIDs( UGCQueryHandle_t handle, bool bReturnOnlyIDs )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (bool)%d)\n", this, handle, bReturnOnlyIDs);
  bool result = this->internal->SetReturnOnlyIDs(handle, bReturnOnlyIDs);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::SetReturnKeyValueTags( UGCQueryHandle_t handle, bool bReturnKeyValueTags )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (bool)%d)\n", this, handle, bReturnKeyValueTags);
  bool result = this->internal->SetReturnKeyValueTags(handle, bReturnKeyValueTags);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::SetReturnLongDescription( UGCQueryHandle_t handle, bool bReturnLongDescription )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (bool)%d)\n", this, handle, bReturnLongDescription);
  bool result = this->internal->SetReturnLongDescription(handle, bReturnLongDescription);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::SetReturnMetadata( UGCQueryHandle_t handle, bool bReturnMetadata )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (bool)%d)\n", this, handle, bReturnMetadata);
  bool result = this->internal->SetReturnMetadata(handle, bReturnMetadata);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::SetReturnChildren( UGCQueryHandle_t handle, bool bReturnChildren )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (bool)%d)\n", this, handle, bReturnChildren);
  bool result = this->internal->SetReturnChildren(handle, bReturnChildren);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::SetReturnAdditionalPreviews( UGCQueryHandle_t handle, bool bReturnAdditionalPreviews )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (bool)%d)\n", this, handle, bReturnAdditionalPreviews);
  bool result = this->internal->SetReturnAdditionalPreviews(handle, bReturnAdditionalPreviews);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::SetReturnTotalOnly( UGCQueryHandle_t handle, bool bReturnTotalOnly )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (bool)%d)\n", this, handle, bReturnTotalOnly);
  bool result = this->internal->SetReturnTotalOnly(handle, bReturnTotalOnly);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::SetLanguage( UGCQueryHandle_t handle, const char *pchLanguage )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (const char *)\"%s\")\n", this, handle, pchLanguage);
  bool result = this->internal->SetLanguage(handle, pchLanguage);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::SetAllowCachedResponse( UGCQueryHandle_t handle, uint32 unMaxAgeSeconds )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (uint32)%d)\n", this, handle, unMaxAgeSeconds);
  bool result = this->internal->SetAllowCachedResponse(handle, unMaxAgeSeconds);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::SetCloudFileNameFilter( UGCQueryHandle_t handle, const char *pMatchCloudFileName )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (const char *)\"%s\")\n", this, handle, pMatchCloudFileName);
  bool result = this->internal->SetCloudFileNameFilter(handle, pMatchCloudFileName);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::SetMatchAnyTag( UGCQueryHandle_t handle, bool bMatchAnyTag )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (bool)%d)\n", this, handle, bMatchAnyTag);
  bool result = this->internal->SetMatchAnyTag(handle, bMatchAnyTag);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::SetSearchText( UGCQueryHandle_t handle, const char *pSearchText )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (const char *)\"%s\")\n", this, handle, pSearchText);
  bool result = this->internal->SetSearchText(handle, pSearchText);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::SetRankedByTrendDays( UGCQueryHandle_t handle, uint32 unDays )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (uint32)%d)\n", this, handle, unDays);
  bool result = this->internal->SetRankedByTrendDays(handle, unDays);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::AddRequiredKeyValueTag( UGCQueryHandle_t handle, const char *pKey, const char *pValue )
{
  TRACE("((this[ISteamUGC])%p, (UGCQueryHandle_t)%p, (const char *)\"%s\", (const char *)\"%s\")\n", this, handle, pKey, pValue);
  bool result = this->internal->AddRequiredKeyValueTag(handle, pKey, pValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t ISteamUGC_::RequestUGCDetails( PublishedFileId_t nPublishedFileID, uint32 unMaxAgeSeconds )
{
  TRACE("((this[ISteamUGC])%p, (PublishedFileId_t)%p, (uint32)%d)\n", this, nPublishedFileID, unMaxAgeSeconds);
  SteamAPICall_t result = this->internal->RequestUGCDetails(nPublishedFileID, unMaxAgeSeconds);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t ISteamUGC_::CreateItem( AppId_t nConsumerAppId, EWorkshopFileType eFileType )
{
  TRACE("((this[ISteamUGC])%p, (AppId_t)%p, (EWorkshopFileType)%p)\n", this, nConsumerAppId, eFileType);
  SteamAPICall_t result = this->internal->CreateItem(nConsumerAppId, eFileType);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
UGCUpdateHandle_t ISteamUGC_::StartItemUpdate( AppId_t nConsumerAppId, PublishedFileId_t nPublishedFileID )
{
  TRACE("((this[ISteamUGC])%p, (AppId_t)%p, (PublishedFileId_t)%p)\n", this, nConsumerAppId, nPublishedFileID);
  UGCUpdateHandle_t result = this->internal->StartItemUpdate(nConsumerAppId, nPublishedFileID);
  TRACE(" = (UGCUpdateHandle_t)%p\n", result);
  return result;
}
bool ISteamUGC_::SetItemTitle( UGCUpdateHandle_t handle, const char *pchTitle )
{
  TRACE("((this[ISteamUGC])%p, (UGCUpdateHandle_t)%p, (const char *)\"%s\")\n", this, handle, pchTitle);
  bool result = this->internal->SetItemTitle(handle, pchTitle);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::SetItemDescription( UGCUpdateHandle_t handle, const char *pchDescription )
{
  TRACE("((this[ISteamUGC])%p, (UGCUpdateHandle_t)%p, (const char *)\"%s\")\n", this, handle, pchDescription);
  bool result = this->internal->SetItemDescription(handle, pchDescription);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::SetItemUpdateLanguage( UGCUpdateHandle_t handle, const char *pchLanguage )
{
  TRACE("((this[ISteamUGC])%p, (UGCUpdateHandle_t)%p, (const char *)\"%s\")\n", this, handle, pchLanguage);
  bool result = this->internal->SetItemUpdateLanguage(handle, pchLanguage);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::SetItemMetadata( UGCUpdateHandle_t handle, const char *pchMetaData )
{
  TRACE("((this[ISteamUGC])%p, (UGCUpdateHandle_t)%p, (const char *)\"%s\")\n", this, handle, pchMetaData);
  bool result = this->internal->SetItemMetadata(handle, pchMetaData);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::SetItemVisibility( UGCUpdateHandle_t handle, ERemoteStoragePublishedFileVisibility eVisibility )
{
  TRACE("((this[ISteamUGC])%p, (UGCUpdateHandle_t)%p, (ERemoteStoragePublishedFileVisibility)%p)\n", this, handle, eVisibility);
  bool result = this->internal->SetItemVisibility(handle, eVisibility);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::SetItemTags( UGCUpdateHandle_t updateHandle, const SteamParamStringArray_t *pTags )
{
  TRACE("((this[ISteamUGC])%p, (UGCUpdateHandle_t)%p, (const SteamParamStringArray_t *)%p)\n", this, updateHandle, pTags);
  bool result = this->internal->SetItemTags(updateHandle, pTags);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::SetItemContent( UGCUpdateHandle_t handle, const char *pszContentFolder )
{
  TRACE("((this[ISteamUGC])%p, (UGCUpdateHandle_t)%p, (const char *)\"%s\")\n", this, handle, pszContentFolder);
  bool result = this->internal->SetItemContent(handle, pszContentFolder);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::SetItemPreview( UGCUpdateHandle_t handle, const char *pszPreviewFile )
{
  TRACE("((this[ISteamUGC])%p, (UGCUpdateHandle_t)%p, (const char *)\"%s\")\n", this, handle, pszPreviewFile);
  bool result = this->internal->SetItemPreview(handle, pszPreviewFile);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::RemoveItemKeyValueTags( UGCUpdateHandle_t handle, const char *pchKey )
{
  TRACE("((this[ISteamUGC])%p, (UGCUpdateHandle_t)%p, (const char *)\"%s\")\n", this, handle, pchKey);
  bool result = this->internal->RemoveItemKeyValueTags(handle, pchKey);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::AddItemKeyValueTag( UGCUpdateHandle_t handle, const char *pchKey, const char *pchValue )
{
  TRACE("((this[ISteamUGC])%p, (UGCUpdateHandle_t)%p, (const char *)\"%s\", (const char *)\"%s\")\n", this, handle, pchKey, pchValue);
  bool result = this->internal->AddItemKeyValueTag(handle, pchKey, pchValue);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::AddItemPreviewFile( UGCUpdateHandle_t handle, const char *pszPreviewFile, EItemPreviewType type )
{
  TRACE("((this[ISteamUGC])%p, (UGCUpdateHandle_t)%p, (const char *)\"%s\", (EItemPreviewType)%p)\n", this, handle, pszPreviewFile, type);
  bool result = this->internal->AddItemPreviewFile(handle, pszPreviewFile, type);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::AddItemPreviewVideo( UGCUpdateHandle_t handle, const char *pszVideoID )
{
  TRACE("((this[ISteamUGC])%p, (UGCUpdateHandle_t)%p, (const char *)\"%s\")\n", this, handle, pszVideoID);
  bool result = this->internal->AddItemPreviewVideo(handle, pszVideoID);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::UpdateItemPreviewFile( UGCUpdateHandle_t handle, uint32 index, const char *pszPreviewFile )
{
  TRACE("((this[ISteamUGC])%p, (UGCUpdateHandle_t)%p, (uint32)%d, (const char *)\"%s\")\n", this, handle, index, pszPreviewFile);
  bool result = this->internal->UpdateItemPreviewFile(handle, index, pszPreviewFile);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::UpdateItemPreviewVideo( UGCUpdateHandle_t handle, uint32 index, const char *pszVideoID )
{
  TRACE("((this[ISteamUGC])%p, (UGCUpdateHandle_t)%p, (uint32)%d, (const char *)\"%s\")\n", this, handle, index, pszVideoID);
  bool result = this->internal->UpdateItemPreviewVideo(handle, index, pszVideoID);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::RemoveItemPreview( UGCUpdateHandle_t handle, uint32 index )
{
  TRACE("((this[ISteamUGC])%p, (UGCUpdateHandle_t)%p, (uint32)%d)\n", this, handle, index);
  bool result = this->internal->RemoveItemPreview(handle, index);
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t ISteamUGC_::SubmitItemUpdate( UGCUpdateHandle_t handle, const char *pchChangeNote )
{
  TRACE("((this[ISteamUGC])%p, (UGCUpdateHandle_t)%p, (const char *)\"%s\")\n", this, handle, pchChangeNote);
  SteamAPICall_t result = this->internal->SubmitItemUpdate(handle, pchChangeNote);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
EItemUpdateStatus ISteamUGC_::GetItemUpdateProgress( UGCUpdateHandle_t handle, uint64 *punBytesProcessed, uint64* punBytesTotal )
{
  TRACE("((this[ISteamUGC])%p, (UGCUpdateHandle_t)%p, (uint64 *)%p, (uint64*)%p)\n", this, handle, punBytesProcessed, punBytesTotal);
  EItemUpdateStatus result = this->internal->GetItemUpdateProgress(handle, punBytesProcessed, punBytesTotal);
  TRACE(" = (EItemUpdateStatus)%p\n", result);
  return result;
}
SteamAPICall_t ISteamUGC_::SetUserItemVote( PublishedFileId_t nPublishedFileID, bool bVoteUp )
{
  TRACE("((this[ISteamUGC])%p, (PublishedFileId_t)%p, (bool)%d)\n", this, nPublishedFileID, bVoteUp);
  SteamAPICall_t result = this->internal->SetUserItemVote(nPublishedFileID, bVoteUp);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t ISteamUGC_::GetUserItemVote( PublishedFileId_t nPublishedFileID )
{
  TRACE("((this[ISteamUGC])%p, (PublishedFileId_t)%p)\n", this, nPublishedFileID);
  SteamAPICall_t result = this->internal->GetUserItemVote(nPublishedFileID);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t ISteamUGC_::AddItemToFavorites( AppId_t nAppId, PublishedFileId_t nPublishedFileID )
{
  TRACE("((this[ISteamUGC])%p, (AppId_t)%p, (PublishedFileId_t)%p)\n", this, nAppId, nPublishedFileID);
  SteamAPICall_t result = this->internal->AddItemToFavorites(nAppId, nPublishedFileID);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t ISteamUGC_::RemoveItemFromFavorites( AppId_t nAppId, PublishedFileId_t nPublishedFileID )
{
  TRACE("((this[ISteamUGC])%p, (AppId_t)%p, (PublishedFileId_t)%p)\n", this, nAppId, nPublishedFileID);
  SteamAPICall_t result = this->internal->RemoveItemFromFavorites(nAppId, nPublishedFileID);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t ISteamUGC_::SubscribeItem( PublishedFileId_t nPublishedFileID )
{
  TRACE("((this[ISteamUGC])%p, (PublishedFileId_t)%p)\n", this, nPublishedFileID);
  SteamAPICall_t result = this->internal->SubscribeItem(nPublishedFileID);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t ISteamUGC_::UnsubscribeItem( PublishedFileId_t nPublishedFileID )
{
  TRACE("((this[ISteamUGC])%p, (PublishedFileId_t)%p)\n", this, nPublishedFileID);
  SteamAPICall_t result = this->internal->UnsubscribeItem(nPublishedFileID);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
uint32 ISteamUGC_::GetNumSubscribedItems()
{
  TRACE("((this[ISteamUGC])%p)\n", this);
  uint32 result = this->internal->GetNumSubscribedItems();
  TRACE(" = (uint32)%d\n", result);
  return result;
}
uint32 ISteamUGC_::GetSubscribedItems( PublishedFileId_t* pvecPublishedFileID, uint32 cMaxEntries )
{
  TRACE("((this[ISteamUGC])%p, (PublishedFileId_t*)%p, (uint32)%d)\n", this, pvecPublishedFileID, cMaxEntries);
  uint32 result = this->internal->GetSubscribedItems(pvecPublishedFileID, cMaxEntries);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
uint32 ISteamUGC_::GetItemState( PublishedFileId_t nPublishedFileID )
{
  TRACE("((this[ISteamUGC])%p, (PublishedFileId_t)%p)\n", this, nPublishedFileID);
  uint32 result = this->internal->GetItemState(nPublishedFileID);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
bool ISteamUGC_::GetItemInstallInfo( PublishedFileId_t nPublishedFileID, uint64 *punSizeOnDisk, OUT_STRING_COUNT( cchFolderSize ) char *pchFolder, uint32 cchFolderSize, uint32 *punTimeStamp )
{
  TRACE("((this[ISteamUGC])%p, (PublishedFileId_t)%p, (uint64 *)%p, (char *)%p, (uint32)%d, (uint32 *)%p)\n", this, nPublishedFileID, punSizeOnDisk, pchFolder, cchFolderSize, punTimeStamp);
  bool result = this->internal->GetItemInstallInfo(nPublishedFileID, punSizeOnDisk, pchFolder, cchFolderSize, punTimeStamp);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::GetItemDownloadInfo( PublishedFileId_t nPublishedFileID, uint64 *punBytesDownloaded, uint64 *punBytesTotal )
{
  TRACE("((this[ISteamUGC])%p, (PublishedFileId_t)%p, (uint64 *)%p, (uint64 *)%p)\n", this, nPublishedFileID, punBytesDownloaded, punBytesTotal);
  bool result = this->internal->GetItemDownloadInfo(nPublishedFileID, punBytesDownloaded, punBytesTotal);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::DownloadItem( PublishedFileId_t nPublishedFileID, bool bHighPriority )
{
  TRACE("((this[ISteamUGC])%p, (PublishedFileId_t)%p, (bool)%d)\n", this, nPublishedFileID, bHighPriority);
  bool result = this->internal->DownloadItem(nPublishedFileID, bHighPriority);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamUGC_::BInitWorkshopForGameServer( DepotId_t unWorkshopDepotID, const char *pszFolder )
{
  TRACE("((this[ISteamUGC])%p, (DepotId_t)%p, (const char *)\"%s\")\n", this, unWorkshopDepotID, pszFolder);
  bool result = this->internal->BInitWorkshopForGameServer(unWorkshopDepotID, pszFolder);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void ISteamUGC_::SuspendDownloads( bool bSuspend )
{
  TRACE("((this[ISteamUGC])%p, (bool)%d)\n", this, bSuspend);
  this->internal->SuspendDownloads(bSuspend);
}
SteamAPICall_t ISteamUGC_::StartPlaytimeTracking( PublishedFileId_t *pvecPublishedFileID, uint32 unNumPublishedFileIDs )
{
  TRACE("((this[ISteamUGC])%p, (PublishedFileId_t *)%p, (uint32)%d)\n", this, pvecPublishedFileID, unNumPublishedFileIDs);
  SteamAPICall_t result = this->internal->StartPlaytimeTracking(pvecPublishedFileID, unNumPublishedFileIDs);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t ISteamUGC_::StopPlaytimeTracking( PublishedFileId_t *pvecPublishedFileID, uint32 unNumPublishedFileIDs )
{
  TRACE("((this[ISteamUGC])%p, (PublishedFileId_t *)%p, (uint32)%d)\n", this, pvecPublishedFileID, unNumPublishedFileIDs);
  SteamAPICall_t result = this->internal->StopPlaytimeTracking(pvecPublishedFileID, unNumPublishedFileIDs);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
SteamAPICall_t ISteamUGC_::StopPlaytimeTrackingForAllItems()
{
  TRACE("((this[ISteamUGC])%p)\n", this);
  SteamAPICall_t result = this->internal->StopPlaytimeTrackingForAllItems();
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
#endif
