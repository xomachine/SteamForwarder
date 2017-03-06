#include <steam_api_.h>

UGCQueryHandle_t  ISteamUGC_::CreateQueryUserUGCRequest(AccountID_t  unAccountID, EUserUGCList  eListType, EUGCMatchingUGCType  eMatchingUGCType, EUserUGCListSortOrder  eSortOrder, AppId_t  nCreatorAppID, AppId_t  nConsumerAppID, uint32  unPage)
{
  TRACE("((ISteamUGC *)%p, (AccountID_t )%p, (EUserUGCList )%p, (EUGCMatchingUGCType )%p, (EUserUGCListSortOrder )%p, (AppId_t )%p, (AppId_t )%p, (uint32 )%d)\n", this, unAccountID, eListType, eMatchingUGCType, eSortOrder, nCreatorAppID, nConsumerAppID, unPage);
  auto result = this->internal->CreateQueryUserUGCRequest(unAccountID, eListType, eMatchingUGCType, eSortOrder, nCreatorAppID, nConsumerAppID, unPage);
  TRACE("() = (UGCQueryHandle_t )%p\n", result);

  return result;
}


UGCQueryHandle_t  ISteamUGC_::CreateQueryAllUGCRequest(EUGCQuery  eQueryType, EUGCMatchingUGCType  eMatchingeMatchingUGCTypeFileType, AppId_t  nCreatorAppID, AppId_t  nConsumerAppID, uint32  unPage)
{
  TRACE("((ISteamUGC *)%p, (EUGCQuery )%p, (EUGCMatchingUGCType )%p, (AppId_t )%p, (AppId_t )%p, (uint32 )%d)\n", this, eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, unPage);
  auto result = this->internal->CreateQueryAllUGCRequest(eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, unPage);
  TRACE("() = (UGCQueryHandle_t )%p\n", result);

  return result;
}


UGCQueryHandle_t  ISteamUGC_::CreateQueryUGCDetailsRequest(PublishedFileId_t * pvecPublishedFileID, uint32  unNumPublishedFileIDs)
{
  TRACE("((ISteamUGC *)%p, (PublishedFileId_t *)%p, (uint32 )%d)\n", this, pvecPublishedFileID, unNumPublishedFileIDs);
  auto result = this->internal->CreateQueryUGCDetailsRequest(pvecPublishedFileID, unNumPublishedFileIDs);
  TRACE("() = (UGCQueryHandle_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamUGC_::SendQueryUGCRequest(UGCQueryHandle_t  handle)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p)\n", this, handle);
  auto result = this->internal->SendQueryUGCRequest(handle);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  ISteamUGC_::GetQueryUGCResult(UGCQueryHandle_t  handle, uint32  index, SteamUGCDetails_t * pDetails)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (uint32 )%d, (SteamUGCDetails_t *)%p)\n", this, handle, index, pDetails);
  auto result = this->internal->GetQueryUGCResult(handle, index, pDetails);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::GetQueryUGCPreviewURL(UGCQueryHandle_t  handle, uint32  index, char * pchURL, uint32  cchURLSize)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (uint32 )%d, (char *)\"%s\", (uint32 )%d)\n", this, handle, index, pchURL, cchURLSize);
  auto result = this->internal->GetQueryUGCPreviewURL(handle, index, pchURL, cchURLSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::GetQueryUGCMetadata(UGCQueryHandle_t  handle, uint32  index, char * pchMetadata, uint32  cchMetadatasize)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (uint32 )%d, (char *)\"%s\", (uint32 )%d)\n", this, handle, index, pchMetadata, cchMetadatasize);
  auto result = this->internal->GetQueryUGCMetadata(handle, index, pchMetadata, cchMetadatasize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::GetQueryUGCChildren(UGCQueryHandle_t  handle, uint32  index, PublishedFileId_t * pvecPublishedFileID, uint32  cMaxEntries)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (uint32 )%d, (PublishedFileId_t *)%p, (uint32 )%d)\n", this, handle, index, pvecPublishedFileID, cMaxEntries);
  auto result = this->internal->GetQueryUGCChildren(handle, index, pvecPublishedFileID, cMaxEntries);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::GetQueryUGCStatistic(UGCQueryHandle_t  handle, uint32  index, EItemStatistic  eStatType, uint64 * pStatValue)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (uint32 )%d, (EItemStatistic )%p, (uint64 *)%d)\n", this, handle, index, eStatType, pStatValue);
  auto result = this->internal->GetQueryUGCStatistic(handle, index, eStatType, pStatValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


uint32  ISteamUGC_::GetQueryUGCNumAdditionalPreviews(UGCQueryHandle_t  handle, uint32  index)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (uint32 )%d)\n", this, handle, index);
  auto result = this->internal->GetQueryUGCNumAdditionalPreviews(handle, index);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


bool  ISteamUGC_::GetQueryUGCAdditionalPreview(UGCQueryHandle_t  handle, uint32  index, uint32  previewIndex, char * pchURLOrVideoID, uint32  cchURLSize, char * pchOriginalFileName, uint32  cchOriginalFileNameSize, EItemPreviewType * pPreviewType)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (uint32 )%d, (uint32 )%d, (char *)\"%s\", (uint32 )%d, (char *)\"%s\", (uint32 )%d, (EItemPreviewType *)%p)\n", this, handle, index, previewIndex, pchURLOrVideoID, cchURLSize, pchOriginalFileName, cchOriginalFileNameSize, pPreviewType);
  auto result = this->internal->GetQueryUGCAdditionalPreview(handle, index, previewIndex, pchURLOrVideoID, cchURLSize, pchOriginalFileName, cchOriginalFileNameSize, pPreviewType);
  TRACE("() = (bool )%d\n", result);

  return result;
}


uint32  ISteamUGC_::GetQueryUGCNumKeyValueTags(UGCQueryHandle_t  handle, uint32  index)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (uint32 )%d)\n", this, handle, index);
  auto result = this->internal->GetQueryUGCNumKeyValueTags(handle, index);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


bool  ISteamUGC_::GetQueryUGCKeyValueTag(UGCQueryHandle_t  handle, uint32  index, uint32  keyValueTagIndex, char * pchKey, uint32  cchKeySize, char * pchValue, uint32  cchValueSize)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (uint32 )%d, (uint32 )%d, (char *)\"%s\", (uint32 )%d, (char *)\"%s\", (uint32 )%d)\n", this, handle, index, keyValueTagIndex, pchKey, cchKeySize, pchValue, cchValueSize);
  auto result = this->internal->GetQueryUGCKeyValueTag(handle, index, keyValueTagIndex, pchKey, cchKeySize, pchValue, cchValueSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::ReleaseQueryUGCRequest(UGCQueryHandle_t  handle)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p)\n", this, handle);
  auto result = this->internal->ReleaseQueryUGCRequest(handle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::AddRequiredTag(UGCQueryHandle_t  handle, char * pTagName)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (char *)\"%s\")\n", this, handle, pTagName);
  auto result = this->internal->AddRequiredTag(handle, pTagName);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::AddExcludedTag(UGCQueryHandle_t  handle, char * pTagName)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (char *)\"%s\")\n", this, handle, pTagName);
  auto result = this->internal->AddExcludedTag(handle, pTagName);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::SetReturnOnlyIDs(UGCQueryHandle_t  handle, bool  bReturnOnlyIDs)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (bool )%d)\n", this, handle, bReturnOnlyIDs);
  auto result = this->internal->SetReturnOnlyIDs(handle, bReturnOnlyIDs);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::SetReturnKeyValueTags(UGCQueryHandle_t  handle, bool  bReturnKeyValueTags)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (bool )%d)\n", this, handle, bReturnKeyValueTags);
  auto result = this->internal->SetReturnKeyValueTags(handle, bReturnKeyValueTags);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::SetReturnLongDescription(UGCQueryHandle_t  handle, bool  bReturnLongDescription)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (bool )%d)\n", this, handle, bReturnLongDescription);
  auto result = this->internal->SetReturnLongDescription(handle, bReturnLongDescription);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::SetReturnMetadata(UGCQueryHandle_t  handle, bool  bReturnMetadata)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (bool )%d)\n", this, handle, bReturnMetadata);
  auto result = this->internal->SetReturnMetadata(handle, bReturnMetadata);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::SetReturnChildren(UGCQueryHandle_t  handle, bool  bReturnChildren)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (bool )%d)\n", this, handle, bReturnChildren);
  auto result = this->internal->SetReturnChildren(handle, bReturnChildren);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::SetReturnAdditionalPreviews(UGCQueryHandle_t  handle, bool  bReturnAdditionalPreviews)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (bool )%d)\n", this, handle, bReturnAdditionalPreviews);
  auto result = this->internal->SetReturnAdditionalPreviews(handle, bReturnAdditionalPreviews);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::SetReturnTotalOnly(UGCQueryHandle_t  handle, bool  bReturnTotalOnly)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (bool )%d)\n", this, handle, bReturnTotalOnly);
  auto result = this->internal->SetReturnTotalOnly(handle, bReturnTotalOnly);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::SetLanguage(UGCQueryHandle_t  handle, char * pchLanguage)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (char *)\"%s\")\n", this, handle, pchLanguage);
  auto result = this->internal->SetLanguage(handle, pchLanguage);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::SetAllowCachedResponse(UGCQueryHandle_t  handle, uint32  unMaxAgeSeconds)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (uint32 )%d)\n", this, handle, unMaxAgeSeconds);
  auto result = this->internal->SetAllowCachedResponse(handle, unMaxAgeSeconds);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::SetCloudFileNameFilter(UGCQueryHandle_t  handle, char * pMatchCloudFileName)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (char *)\"%s\")\n", this, handle, pMatchCloudFileName);
  auto result = this->internal->SetCloudFileNameFilter(handle, pMatchCloudFileName);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::SetMatchAnyTag(UGCQueryHandle_t  handle, bool  bMatchAnyTag)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (bool )%d)\n", this, handle, bMatchAnyTag);
  auto result = this->internal->SetMatchAnyTag(handle, bMatchAnyTag);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::SetSearchText(UGCQueryHandle_t  handle, char * pSearchText)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (char *)\"%s\")\n", this, handle, pSearchText);
  auto result = this->internal->SetSearchText(handle, pSearchText);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::SetRankedByTrendDays(UGCQueryHandle_t  handle, uint32  unDays)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (uint32 )%d)\n", this, handle, unDays);
  auto result = this->internal->SetRankedByTrendDays(handle, unDays);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::AddRequiredKeyValueTag(UGCQueryHandle_t  handle, char * pKey, char * pValue)
{
  TRACE("((ISteamUGC *)%p, (UGCQueryHandle_t )%p, (char *)\"%s\", (char *)\"%s\")\n", this, handle, pKey, pValue);
  auto result = this->internal->AddRequiredKeyValueTag(handle, pKey, pValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  ISteamUGC_::RequestUGCDetails(PublishedFileId_t  nPublishedFileID, uint32  unMaxAgeSeconds)
{
  TRACE("((ISteamUGC *)%p, (PublishedFileId_t )%p, (uint32 )%d)\n", this, nPublishedFileID, unMaxAgeSeconds);
  auto result = this->internal->RequestUGCDetails(nPublishedFileID, unMaxAgeSeconds);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamUGC_::CreateItem(AppId_t  nConsumerAppId, EWorkshopFileType  eFileType)
{
  TRACE("((ISteamUGC *)%p, (AppId_t )%p, (EWorkshopFileType )%p)\n", this, nConsumerAppId, eFileType);
  auto result = this->internal->CreateItem(nConsumerAppId, eFileType);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


UGCUpdateHandle_t  ISteamUGC_::StartItemUpdate(AppId_t  nConsumerAppId, PublishedFileId_t  nPublishedFileID)
{
  TRACE("((ISteamUGC *)%p, (AppId_t )%p, (PublishedFileId_t )%p)\n", this, nConsumerAppId, nPublishedFileID);
  auto result = this->internal->StartItemUpdate(nConsumerAppId, nPublishedFileID);
  TRACE("() = (UGCUpdateHandle_t )%p\n", result);

  return result;
}


bool  ISteamUGC_::SetItemTitle(UGCUpdateHandle_t  handle, char * pchTitle)
{
  TRACE("((ISteamUGC *)%p, (UGCUpdateHandle_t )%p, (char *)\"%s\")\n", this, handle, pchTitle);
  auto result = this->internal->SetItemTitle(handle, pchTitle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::SetItemDescription(UGCUpdateHandle_t  handle, char * pchDescription)
{
  TRACE("((ISteamUGC *)%p, (UGCUpdateHandle_t )%p, (char *)\"%s\")\n", this, handle, pchDescription);
  auto result = this->internal->SetItemDescription(handle, pchDescription);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::SetItemUpdateLanguage(UGCUpdateHandle_t  handle, char * pchLanguage)
{
  TRACE("((ISteamUGC *)%p, (UGCUpdateHandle_t )%p, (char *)\"%s\")\n", this, handle, pchLanguage);
  auto result = this->internal->SetItemUpdateLanguage(handle, pchLanguage);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::SetItemMetadata(UGCUpdateHandle_t  handle, char * pchMetaData)
{
  TRACE("((ISteamUGC *)%p, (UGCUpdateHandle_t )%p, (char *)\"%s\")\n", this, handle, pchMetaData);
  auto result = this->internal->SetItemMetadata(handle, pchMetaData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::SetItemVisibility(UGCUpdateHandle_t  handle, ERemoteStoragePublishedFileVisibility  eVisibility)
{
  TRACE("((ISteamUGC *)%p, (UGCUpdateHandle_t )%p, (ERemoteStoragePublishedFileVisibility )%p)\n", this, handle, eVisibility);
  auto result = this->internal->SetItemVisibility(handle, eVisibility);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::SetItemTags(UGCUpdateHandle_t  updateHandle, SteamParamStringArray_t * pTags)
{
  TRACE("((ISteamUGC *)%p, (UGCUpdateHandle_t )%p, (SteamParamStringArray_t *)%p)\n", this, updateHandle, pTags);
  auto result = this->internal->SetItemTags(updateHandle, pTags);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::SetItemContent(UGCUpdateHandle_t  handle, char * pszContentFolder)
{
  TRACE("((ISteamUGC *)%p, (UGCUpdateHandle_t )%p, (char *)\"%s\")\n", this, handle, pszContentFolder);
  auto result = this->internal->SetItemContent(handle, pszContentFolder);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::SetItemPreview(UGCUpdateHandle_t  handle, char * pszPreviewFile)
{
  TRACE("((ISteamUGC *)%p, (UGCUpdateHandle_t )%p, (char *)\"%s\")\n", this, handle, pszPreviewFile);
  auto result = this->internal->SetItemPreview(handle, pszPreviewFile);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::RemoveItemKeyValueTags(UGCUpdateHandle_t  handle, char * pchKey)
{
  TRACE("((ISteamUGC *)%p, (UGCUpdateHandle_t )%p, (char *)\"%s\")\n", this, handle, pchKey);
  auto result = this->internal->RemoveItemKeyValueTags(handle, pchKey);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::AddItemKeyValueTag(UGCUpdateHandle_t  handle, char * pchKey, char * pchValue)
{
  TRACE("((ISteamUGC *)%p, (UGCUpdateHandle_t )%p, (char *)\"%s\", (char *)\"%s\")\n", this, handle, pchKey, pchValue);
  auto result = this->internal->AddItemKeyValueTag(handle, pchKey, pchValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::AddItemPreviewFile(UGCUpdateHandle_t  handle, char * pszPreviewFile, EItemPreviewType  type)
{
  TRACE("((ISteamUGC *)%p, (UGCUpdateHandle_t )%p, (char *)\"%s\", (EItemPreviewType )%p)\n", this, handle, pszPreviewFile, type);
  auto result = this->internal->AddItemPreviewFile(handle, pszPreviewFile, type);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::AddItemPreviewVideo(UGCUpdateHandle_t  handle, char * pszVideoID)
{
  TRACE("((ISteamUGC *)%p, (UGCUpdateHandle_t )%p, (char *)\"%s\")\n", this, handle, pszVideoID);
  auto result = this->internal->AddItemPreviewVideo(handle, pszVideoID);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::UpdateItemPreviewFile(UGCUpdateHandle_t  handle, uint32  index, char * pszPreviewFile)
{
  TRACE("((ISteamUGC *)%p, (UGCUpdateHandle_t )%p, (uint32 )%d, (char *)\"%s\")\n", this, handle, index, pszPreviewFile);
  auto result = this->internal->UpdateItemPreviewFile(handle, index, pszPreviewFile);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::UpdateItemPreviewVideo(UGCUpdateHandle_t  handle, uint32  index, char * pszVideoID)
{
  TRACE("((ISteamUGC *)%p, (UGCUpdateHandle_t )%p, (uint32 )%d, (char *)\"%s\")\n", this, handle, index, pszVideoID);
  auto result = this->internal->UpdateItemPreviewVideo(handle, index, pszVideoID);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::RemoveItemPreview(UGCUpdateHandle_t  handle, uint32  index)
{
  TRACE("((ISteamUGC *)%p, (UGCUpdateHandle_t )%p, (uint32 )%d)\n", this, handle, index);
  auto result = this->internal->RemoveItemPreview(handle, index);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  ISteamUGC_::SubmitItemUpdate(UGCUpdateHandle_t  handle, char * pchChangeNote)
{
  TRACE("((ISteamUGC *)%p, (UGCUpdateHandle_t )%p, (char *)\"%s\")\n", this, handle, pchChangeNote);
  auto result = this->internal->SubmitItemUpdate(handle, pchChangeNote);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


EItemUpdateStatus  ISteamUGC_::GetItemUpdateProgress(UGCUpdateHandle_t  handle, uint64 * punBytesProcessed, uint64 * punBytesTotal)
{
  TRACE("((ISteamUGC *)%p, (UGCUpdateHandle_t )%p, (uint64 *)%d, (uint64 *)%d)\n", this, handle, punBytesProcessed, punBytesTotal);
  auto result = this->internal->GetItemUpdateProgress(handle, punBytesProcessed, punBytesTotal);
  TRACE("() = (EItemUpdateStatus )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamUGC_::SetUserItemVote(PublishedFileId_t  nPublishedFileID, bool  bVoteUp)
{
  TRACE("((ISteamUGC *)%p, (PublishedFileId_t )%p, (bool )%d)\n", this, nPublishedFileID, bVoteUp);
  auto result = this->internal->SetUserItemVote(nPublishedFileID, bVoteUp);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamUGC_::GetUserItemVote(PublishedFileId_t  nPublishedFileID)
{
  TRACE("((ISteamUGC *)%p, (PublishedFileId_t )%p)\n", this, nPublishedFileID);
  auto result = this->internal->GetUserItemVote(nPublishedFileID);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamUGC_::AddItemToFavorites(AppId_t  nAppId, PublishedFileId_t  nPublishedFileID)
{
  TRACE("((ISteamUGC *)%p, (AppId_t )%p, (PublishedFileId_t )%p)\n", this, nAppId, nPublishedFileID);
  auto result = this->internal->AddItemToFavorites(nAppId, nPublishedFileID);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamUGC_::RemoveItemFromFavorites(AppId_t  nAppId, PublishedFileId_t  nPublishedFileID)
{
  TRACE("((ISteamUGC *)%p, (AppId_t )%p, (PublishedFileId_t )%p)\n", this, nAppId, nPublishedFileID);
  auto result = this->internal->RemoveItemFromFavorites(nAppId, nPublishedFileID);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamUGC_::SubscribeItem(PublishedFileId_t  nPublishedFileID)
{
  TRACE("((ISteamUGC *)%p, (PublishedFileId_t )%p)\n", this, nPublishedFileID);
  auto result = this->internal->SubscribeItem(nPublishedFileID);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamUGC_::UnsubscribeItem(PublishedFileId_t  nPublishedFileID)
{
  TRACE("((ISteamUGC *)%p, (PublishedFileId_t )%p)\n", this, nPublishedFileID);
  auto result = this->internal->UnsubscribeItem(nPublishedFileID);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


uint32  ISteamUGC_::GetNumSubscribedItems()
{
  TRACE("((ISteamUGC *)%p)\n", this);
  auto result = this->internal->GetNumSubscribedItems();
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


uint32  ISteamUGC_::GetSubscribedItems(PublishedFileId_t * pvecPublishedFileID, uint32  cMaxEntries)
{
  TRACE("((ISteamUGC *)%p, (PublishedFileId_t *)%p, (uint32 )%d)\n", this, pvecPublishedFileID, cMaxEntries);
  auto result = this->internal->GetSubscribedItems(pvecPublishedFileID, cMaxEntries);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


uint32  ISteamUGC_::GetItemState(PublishedFileId_t  nPublishedFileID)
{
  TRACE("((ISteamUGC *)%p, (PublishedFileId_t )%p)\n", this, nPublishedFileID);
  auto result = this->internal->GetItemState(nPublishedFileID);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


bool  ISteamUGC_::GetItemInstallInfo(PublishedFileId_t  nPublishedFileID, uint64 * punSizeOnDisk, char * pchFolder, uint32  cchFolderSize, uint32 * punTimeStamp)
{
  TRACE("((ISteamUGC *)%p, (PublishedFileId_t )%p, (uint64 *)%d, (char *)\"%s\", (uint32 )%d, (uint32 *)%d)\n", this, nPublishedFileID, punSizeOnDisk, pchFolder, cchFolderSize, punTimeStamp);
  auto result = this->internal->GetItemInstallInfo(nPublishedFileID, punSizeOnDisk, pchFolder, cchFolderSize, punTimeStamp);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::GetItemDownloadInfo(PublishedFileId_t  nPublishedFileID, uint64 * punBytesDownloaded, uint64 * punBytesTotal)
{
  TRACE("((ISteamUGC *)%p, (PublishedFileId_t )%p, (uint64 *)%d, (uint64 *)%d)\n", this, nPublishedFileID, punBytesDownloaded, punBytesTotal);
  auto result = this->internal->GetItemDownloadInfo(nPublishedFileID, punBytesDownloaded, punBytesTotal);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::DownloadItem(PublishedFileId_t  nPublishedFileID, bool  bHighPriority)
{
  TRACE("((ISteamUGC *)%p, (PublishedFileId_t )%p, (bool )%d)\n", this, nPublishedFileID, bHighPriority);
  auto result = this->internal->DownloadItem(nPublishedFileID, bHighPriority);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamUGC_::BInitWorkshopForGameServer(DepotId_t  unWorkshopDepotID, char * pszFolder)
{
  TRACE("((ISteamUGC *)%p, (DepotId_t )%p, (char *)\"%s\")\n", this, unWorkshopDepotID, pszFolder);
  auto result = this->internal->BInitWorkshopForGameServer(unWorkshopDepotID, pszFolder);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  ISteamUGC_::SuspendDownloads(bool  bSuspend)
{
  TRACE("((ISteamUGC *)%p, (bool )%d)\n", this, bSuspend);
  this->internal->SuspendDownloads(bSuspend);
  
}


SteamAPICall_t  ISteamUGC_::StartPlaytimeTracking(PublishedFileId_t * pvecPublishedFileID, uint32  unNumPublishedFileIDs)
{
  TRACE("((ISteamUGC *)%p, (PublishedFileId_t *)%p, (uint32 )%d)\n", this, pvecPublishedFileID, unNumPublishedFileIDs);
  auto result = this->internal->StartPlaytimeTracking(pvecPublishedFileID, unNumPublishedFileIDs);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamUGC_::StopPlaytimeTracking(PublishedFileId_t * pvecPublishedFileID, uint32  unNumPublishedFileIDs)
{
  TRACE("((ISteamUGC *)%p, (PublishedFileId_t *)%p, (uint32 )%d)\n", this, pvecPublishedFileID, unNumPublishedFileIDs);
  auto result = this->internal->StopPlaytimeTracking(pvecPublishedFileID, unNumPublishedFileIDs);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamUGC_::StopPlaytimeTrackingForAllItems()
{
  TRACE("((ISteamUGC *)%p)\n", this);
  auto result = this->internal->StopPlaytimeTrackingForAllItems();
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}
ISteamUGC_::ISteamUGC_(ISteamUGC * towrap)
{
  this->internal = towrap;
}

ISteamUGC_::~ISteamUGC_()
{
  delete this->internal;
}
