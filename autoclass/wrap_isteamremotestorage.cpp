#include <steam_api_.h>

bool  ISteamRemoteStorage_::FileWrite(char * pchFile, void * pvData, int32  cubData)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\", (void *)%p, (int32 )%d)\n", this, pchFile, pvData, cubData);
  auto result = this->internal->FileWrite(pchFile, pvData, cubData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int32  ISteamRemoteStorage_::FileRead(char * pchFile, void * pvData, int32  cubDataToRead)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\", (void *)%p, (int32 )%d)\n", this, pchFile, pvData, cubDataToRead);
  auto result = this->internal->FileRead(pchFile, pvData, cubDataToRead);
  TRACE("() = (int32 )%d\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::FileWriteAsync(char * pchFile, void * pvData, uint32  cubData)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\", (void *)%p, (uint32 )%d)\n", this, pchFile, pvData, cubData);
  auto result = this->internal->FileWriteAsync(pchFile, pvData, cubData);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::FileReadAsync(char * pchFile, uint32  nOffset, uint32  cubToRead)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\", (uint32 )%d, (uint32 )%d)\n", this, pchFile, nOffset, cubToRead);
  auto result = this->internal->FileReadAsync(pchFile, nOffset, cubToRead);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  ISteamRemoteStorage_::FileReadAsyncComplete(SteamAPICall_t  hReadCall, void * pvBuffer, uint32  cubToRead)
{
  TRACE("((ISteamRemoteStorage *)%p, (SteamAPICall_t )%p, (void *)%p, (uint32 )%d)\n", this, hReadCall, pvBuffer, cubToRead);
  auto result = this->internal->FileReadAsyncComplete(hReadCall, pvBuffer, cubToRead);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::FileForget(char * pchFile)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\")\n", this, pchFile);
  auto result = this->internal->FileForget(pchFile);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::FileDelete(char * pchFile)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\")\n", this, pchFile);
  auto result = this->internal->FileDelete(pchFile);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::FileShare(char * pchFile)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\")\n", this, pchFile);
  auto result = this->internal->FileShare(pchFile);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  ISteamRemoteStorage_::SetSyncPlatforms(char * pchFile, ERemoteStoragePlatform  eRemoteStoragePlatform)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\", (ERemoteStoragePlatform )%p)\n", this, pchFile, eRemoteStoragePlatform);
  auto result = this->internal->SetSyncPlatforms(pchFile, eRemoteStoragePlatform);
  TRACE("() = (bool )%d\n", result);

  return result;
}


UGCFileWriteStreamHandle_t  ISteamRemoteStorage_::FileWriteStreamOpen(char * pchFile)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\")\n", this, pchFile);
  auto result = this->internal->FileWriteStreamOpen(pchFile);
  TRACE("() = (UGCFileWriteStreamHandle_t )%p\n", result);

  return result;
}


bool  ISteamRemoteStorage_::FileWriteStreamWriteChunk(UGCFileWriteStreamHandle_t  writeHandle, void * pvData, int32  cubData)
{
  TRACE("((ISteamRemoteStorage *)%p, (UGCFileWriteStreamHandle_t )%p, (void *)%p, (int32 )%d)\n", this, writeHandle, pvData, cubData);
  auto result = this->internal->FileWriteStreamWriteChunk(writeHandle, pvData, cubData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::FileWriteStreamClose(UGCFileWriteStreamHandle_t  writeHandle)
{
  TRACE("((ISteamRemoteStorage *)%p, (UGCFileWriteStreamHandle_t )%p)\n", this, writeHandle);
  auto result = this->internal->FileWriteStreamClose(writeHandle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::FileWriteStreamCancel(UGCFileWriteStreamHandle_t  writeHandle)
{
  TRACE("((ISteamRemoteStorage *)%p, (UGCFileWriteStreamHandle_t )%p)\n", this, writeHandle);
  auto result = this->internal->FileWriteStreamCancel(writeHandle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::FileExists(char * pchFile)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\")\n", this, pchFile);
  auto result = this->internal->FileExists(pchFile);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::FilePersisted(char * pchFile)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\")\n", this, pchFile);
  auto result = this->internal->FilePersisted(pchFile);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int32  ISteamRemoteStorage_::GetFileSize(char * pchFile)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\")\n", this, pchFile);
  auto result = this->internal->GetFileSize(pchFile);
  TRACE("() = (int32 )%d\n", result);

  return result;
}


int64  ISteamRemoteStorage_::GetFileTimestamp(char * pchFile)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\")\n", this, pchFile);
  auto result = this->internal->GetFileTimestamp(pchFile);
  TRACE("() = (int64 )%d\n", result);

  return result;
}


ERemoteStoragePlatform  ISteamRemoteStorage_::GetSyncPlatforms(char * pchFile)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\")\n", this, pchFile);
  auto result = this->internal->GetSyncPlatforms(pchFile);
  TRACE("() = (ERemoteStoragePlatform )%p\n", result);

  return result;
}


int32  ISteamRemoteStorage_::GetFileCount()
{
  TRACE("((ISteamRemoteStorage *)%p)\n", this);
  auto result = this->internal->GetFileCount();
  TRACE("() = (int32 )%d\n", result);

  return result;
}


char * ISteamRemoteStorage_::GetFileNameAndSize(int  iFile, int32 * pnFileSizeInBytes)
{
  TRACE("((ISteamRemoteStorage *)%p, (int )%d, (int32 *)%d)\n", this, iFile, pnFileSizeInBytes);
  auto result = this->internal->GetFileNameAndSize(iFile, pnFileSizeInBytes);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


bool  ISteamRemoteStorage_::GetQuota(uint64 * pnTotalBytes, uint64 * puAvailableBytes)
{
  TRACE("((ISteamRemoteStorage *)%p, (uint64 *)%d, (uint64 *)%d)\n", this, pnTotalBytes, puAvailableBytes);
  auto result = this->internal->GetQuota(pnTotalBytes, puAvailableBytes);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::IsCloudEnabledForAccount()
{
  TRACE("((ISteamRemoteStorage *)%p)\n", this);
  auto result = this->internal->IsCloudEnabledForAccount();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::IsCloudEnabledForApp()
{
  TRACE("((ISteamRemoteStorage *)%p)\n", this);
  auto result = this->internal->IsCloudEnabledForApp();
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  ISteamRemoteStorage_::SetCloudEnabledForApp(bool  bEnabled)
{
  TRACE("((ISteamRemoteStorage *)%p, (bool )%d)\n", this, bEnabled);
  this->internal->SetCloudEnabledForApp(bEnabled);
  
}


SteamAPICall_t  ISteamRemoteStorage_::UGCDownload(UGCHandle_t  hContent, uint32  unPriority)
{
  TRACE("((ISteamRemoteStorage *)%p, (UGCHandle_t )%p, (uint32 )%d)\n", this, hContent, unPriority);
  auto result = this->internal->UGCDownload(hContent, unPriority);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  ISteamRemoteStorage_::GetUGCDownloadProgress(UGCHandle_t  hContent, int32 * pnBytesDownloaded, int32 * pnBytesExpected)
{
  TRACE("((ISteamRemoteStorage *)%p, (UGCHandle_t )%p, (int32 *)%d, (int32 *)%d)\n", this, hContent, pnBytesDownloaded, pnBytesExpected);
  auto result = this->internal->GetUGCDownloadProgress(hContent, pnBytesDownloaded, pnBytesExpected);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::GetUGCDetails(UGCHandle_t  hContent, AppId_t * pnAppID, char ** ppchName, int32 * pnFileSizeInBytes, CSteamID * pSteamIDOwner)
{
  TRACE("((ISteamRemoteStorage *)%p, (UGCHandle_t )%p, (AppId_t *)%p, (char **)\"%s\", (int32 *)%d, (CSteamID *)%p)\n", this, hContent, pnAppID, ppchName, pnFileSizeInBytes, pSteamIDOwner);
  auto result = this->internal->GetUGCDetails(hContent, pnAppID, ppchName, pnFileSizeInBytes, pSteamIDOwner);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int32  ISteamRemoteStorage_::UGCRead(UGCHandle_t  hContent, void * pvData, int32  cubDataToRead, uint32  cOffset, EUGCReadAction  eAction)
{
  TRACE("((ISteamRemoteStorage *)%p, (UGCHandle_t )%p, (void *)%p, (int32 )%d, (uint32 )%d, (EUGCReadAction )%p)\n", this, hContent, pvData, cubDataToRead, cOffset, eAction);
  auto result = this->internal->UGCRead(hContent, pvData, cubDataToRead, cOffset, eAction);
  TRACE("() = (int32 )%d\n", result);

  return result;
}


int32  ISteamRemoteStorage_::GetCachedUGCCount()
{
  TRACE("((ISteamRemoteStorage *)%p)\n", this);
  auto result = this->internal->GetCachedUGCCount();
  TRACE("() = (int32 )%d\n", result);

  return result;
}


UGCHandle_t  ISteamRemoteStorage_::GetCachedUGCHandle(int32  iCachedContent)
{
  TRACE("((ISteamRemoteStorage *)%p, (int32 )%d)\n", this, iCachedContent);
  auto result = this->internal->GetCachedUGCHandle(iCachedContent);
  TRACE("() = (UGCHandle_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::PublishWorkshopFile(char * pchFile, char * pchPreviewFile, AppId_t  nConsumerAppId, char * pchTitle, char * pchDescription, ERemoteStoragePublishedFileVisibility  eVisibility, SteamParamStringArray_t * pTags, EWorkshopFileType  eWorkshopFileType)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\", (char *)\"%s\", (AppId_t )%p, (char *)\"%s\", (char *)\"%s\", (ERemoteStoragePublishedFileVisibility )%p, (SteamParamStringArray_t *)%p, (EWorkshopFileType )%p)\n", this, pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, pTags, eWorkshopFileType);
  auto result = this->internal->PublishWorkshopFile(pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, pTags, eWorkshopFileType);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


PublishedFileUpdateHandle_t  ISteamRemoteStorage_::CreatePublishedFileUpdateRequest(PublishedFileId_t  unPublishedFileId)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileId_t )%p)\n", this, unPublishedFileId);
  auto result = this->internal->CreatePublishedFileUpdateRequest(unPublishedFileId);
  TRACE("() = (PublishedFileUpdateHandle_t )%p\n", result);

  return result;
}


bool  ISteamRemoteStorage_::UpdatePublishedFileFile(PublishedFileUpdateHandle_t  updateHandle, char * pchFile)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileUpdateHandle_t )%p, (char *)\"%s\")\n", this, updateHandle, pchFile);
  auto result = this->internal->UpdatePublishedFileFile(updateHandle, pchFile);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t  updateHandle, char * pchPreviewFile)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileUpdateHandle_t )%p, (char *)\"%s\")\n", this, updateHandle, pchPreviewFile);
  auto result = this->internal->UpdatePublishedFilePreviewFile(updateHandle, pchPreviewFile);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::UpdatePublishedFileTitle(PublishedFileUpdateHandle_t  updateHandle, char * pchTitle)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileUpdateHandle_t )%p, (char *)\"%s\")\n", this, updateHandle, pchTitle);
  auto result = this->internal->UpdatePublishedFileTitle(updateHandle, pchTitle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::UpdatePublishedFileDescription(PublishedFileUpdateHandle_t  updateHandle, char * pchDescription)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileUpdateHandle_t )%p, (char *)\"%s\")\n", this, updateHandle, pchDescription);
  auto result = this->internal->UpdatePublishedFileDescription(updateHandle, pchDescription);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t  updateHandle, ERemoteStoragePublishedFileVisibility  eVisibility)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileUpdateHandle_t )%p, (ERemoteStoragePublishedFileVisibility )%p)\n", this, updateHandle, eVisibility);
  auto result = this->internal->UpdatePublishedFileVisibility(updateHandle, eVisibility);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::UpdatePublishedFileTags(PublishedFileUpdateHandle_t  updateHandle, SteamParamStringArray_t * pTags)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileUpdateHandle_t )%p, (SteamParamStringArray_t *)%p)\n", this, updateHandle, pTags);
  auto result = this->internal->UpdatePublishedFileTags(updateHandle, pTags);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::CommitPublishedFileUpdate(PublishedFileUpdateHandle_t  updateHandle)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileUpdateHandle_t )%p)\n", this, updateHandle);
  auto result = this->internal->CommitPublishedFileUpdate(updateHandle);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::GetPublishedFileDetails(PublishedFileId_t  unPublishedFileId, uint32  unMaxSecondsOld)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileId_t )%p, (uint32 )%d)\n", this, unPublishedFileId, unMaxSecondsOld);
  auto result = this->internal->GetPublishedFileDetails(unPublishedFileId, unMaxSecondsOld);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::DeletePublishedFile(PublishedFileId_t  unPublishedFileId)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileId_t )%p)\n", this, unPublishedFileId);
  auto result = this->internal->DeletePublishedFile(unPublishedFileId);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::EnumerateUserPublishedFiles(uint32  unStartIndex)
{
  TRACE("((ISteamRemoteStorage *)%p, (uint32 )%d)\n", this, unStartIndex);
  auto result = this->internal->EnumerateUserPublishedFiles(unStartIndex);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::SubscribePublishedFile(PublishedFileId_t  unPublishedFileId)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileId_t )%p)\n", this, unPublishedFileId);
  auto result = this->internal->SubscribePublishedFile(unPublishedFileId);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::EnumerateUserSubscribedFiles(uint32  unStartIndex)
{
  TRACE("((ISteamRemoteStorage *)%p, (uint32 )%d)\n", this, unStartIndex);
  auto result = this->internal->EnumerateUserSubscribedFiles(unStartIndex);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::UnsubscribePublishedFile(PublishedFileId_t  unPublishedFileId)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileId_t )%p)\n", this, unPublishedFileId);
  auto result = this->internal->UnsubscribePublishedFile(unPublishedFileId);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  ISteamRemoteStorage_::UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t  updateHandle, char * pchChangeDescription)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileUpdateHandle_t )%p, (char *)\"%s\")\n", this, updateHandle, pchChangeDescription);
  auto result = this->internal->UpdatePublishedFileSetChangeDescription(updateHandle, pchChangeDescription);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::GetPublishedItemVoteDetails(PublishedFileId_t  unPublishedFileId)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileId_t )%p)\n", this, unPublishedFileId);
  auto result = this->internal->GetPublishedItemVoteDetails(unPublishedFileId);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::UpdateUserPublishedItemVote(PublishedFileId_t  unPublishedFileId, bool  bVoteUp)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileId_t )%p, (bool )%d)\n", this, unPublishedFileId, bVoteUp);
  auto result = this->internal->UpdateUserPublishedItemVote(unPublishedFileId, bVoteUp);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::GetUserPublishedItemVoteDetails(PublishedFileId_t  unPublishedFileId)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileId_t )%p)\n", this, unPublishedFileId);
  auto result = this->internal->GetUserPublishedItemVoteDetails(unPublishedFileId);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::EnumerateUserSharedWorkshopFiles(CSteamID  steamId, uint32  unStartIndex, SteamParamStringArray_t * pRequiredTags, SteamParamStringArray_t * pExcludedTags)
{
  TRACE("((ISteamRemoteStorage *)%p, (CSteamID )%p, (uint32 )%d, (SteamParamStringArray_t *)%p, (SteamParamStringArray_t *)%p)\n", this, steamId, unStartIndex, pRequiredTags, pExcludedTags);
  auto result = this->internal->EnumerateUserSharedWorkshopFiles(steamId, unStartIndex, pRequiredTags, pExcludedTags);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::PublishVideo(EWorkshopVideoProvider  eVideoProvider, char * pchVideoAccount, char * pchVideoIdentifier, char * pchPreviewFile, AppId_t  nConsumerAppId, char * pchTitle, char * pchDescription, ERemoteStoragePublishedFileVisibility  eVisibility, SteamParamStringArray_t * pTags)
{
  TRACE("((ISteamRemoteStorage *)%p, (EWorkshopVideoProvider )%p, (char *)\"%s\", (char *)\"%s\", (char *)\"%s\", (AppId_t )%p, (char *)\"%s\", (char *)\"%s\", (ERemoteStoragePublishedFileVisibility )%p, (SteamParamStringArray_t *)%p)\n", this, eVideoProvider, pchVideoAccount, pchVideoIdentifier, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, pTags);
  auto result = this->internal->PublishVideo(eVideoProvider, pchVideoAccount, pchVideoIdentifier, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, pTags);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::SetUserPublishedFileAction(PublishedFileId_t  unPublishedFileId, EWorkshopFileAction  eAction)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileId_t )%p, (EWorkshopFileAction )%p)\n", this, unPublishedFileId, eAction);
  auto result = this->internal->SetUserPublishedFileAction(unPublishedFileId, eAction);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::EnumeratePublishedFilesByUserAction(EWorkshopFileAction  eAction, uint32  unStartIndex)
{
  TRACE("((ISteamRemoteStorage *)%p, (EWorkshopFileAction )%p, (uint32 )%d)\n", this, eAction, unStartIndex);
  auto result = this->internal->EnumeratePublishedFilesByUserAction(eAction, unStartIndex);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType  eEnumerationType, uint32  unStartIndex, uint32  unCount, uint32  unDays, SteamParamStringArray_t * pTags, SteamParamStringArray_t * pUserTags)
{
  TRACE("((ISteamRemoteStorage *)%p, (EWorkshopEnumerationType )%p, (uint32 )%d, (uint32 )%d, (uint32 )%d, (SteamParamStringArray_t *)%p, (SteamParamStringArray_t *)%p)\n", this, eEnumerationType, unStartIndex, unCount, unDays, pTags, pUserTags);
  auto result = this->internal->EnumeratePublishedWorkshopFiles(eEnumerationType, unStartIndex, unCount, unDays, pTags, pUserTags);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::UGCDownloadToLocation(UGCHandle_t  hContent, char * pchLocation, uint32  unPriority)
{
  TRACE("((ISteamRemoteStorage *)%p, (UGCHandle_t )%p, (char *)\"%s\", (uint32 )%d)\n", this, hContent, pchLocation, unPriority);
  auto result = this->internal->UGCDownloadToLocation(hContent, pchLocation, unPriority);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}
ISteamRemoteStorage_::ISteamRemoteStorage_(ISteamRemoteStorage * towrap)
{
  this->internal = towrap;
}

ISteamRemoteStorage_::~ISteamRemoteStorage_()
{
  delete this->internal;
}
