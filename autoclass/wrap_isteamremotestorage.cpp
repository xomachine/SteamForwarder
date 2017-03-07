#include <steam_api_.h>

bool  ISteamRemoteStorage_::FileWrite(char * pchFile, void * pvData, int32  cubData)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\", (void *)%p, (int32 )%d)\n", this, pchFile, pvData, cubData);
  bool  result = this->internal->FileWrite(pchFile, pvData, cubData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int32  ISteamRemoteStorage_::FileRead(char * pchFile, void * pvData, int32  cubDataToRead)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\", (void *)%p, (int32 )%d)\n", this, pchFile, pvData, cubDataToRead);
  int32  result = this->internal->FileRead(pchFile, pvData, cubDataToRead);
  TRACE("() = (int32 )%d\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::FileWriteAsync(char * pchFile, void * pvData, uint32  cubData)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\", (void *)%p, (uint32 )%d)\n", this, pchFile, pvData, cubData);
  SteamAPICall_t  result = this->internal->FileWriteAsync(pchFile, pvData, cubData);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::FileReadAsync(char * pchFile, uint32  nOffset, uint32  cubToRead)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\", (uint32 )%d, (uint32 )%d)\n", this, pchFile, nOffset, cubToRead);
  SteamAPICall_t  result = this->internal->FileReadAsync(pchFile, nOffset, cubToRead);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  ISteamRemoteStorage_::FileReadAsyncComplete(SteamAPICall_t  hReadCall, void * pvBuffer, uint32  cubToRead)
{
  TRACE("((ISteamRemoteStorage *)%p, (SteamAPICall_t )%p, (void *)%p, (uint32 )%d)\n", this, hReadCall, pvBuffer, cubToRead);
  bool  result = this->internal->FileReadAsyncComplete(hReadCall, pvBuffer, cubToRead);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::FileForget(char * pchFile)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\")\n", this, pchFile);
  bool  result = this->internal->FileForget(pchFile);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::FileDelete(char * pchFile)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\")\n", this, pchFile);
  bool  result = this->internal->FileDelete(pchFile);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::FileShare(char * pchFile)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\")\n", this, pchFile);
  SteamAPICall_t  result = this->internal->FileShare(pchFile);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  ISteamRemoteStorage_::SetSyncPlatforms(char * pchFile, ERemoteStoragePlatform  eRemoteStoragePlatform)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\", (ERemoteStoragePlatform )%p)\n", this, pchFile, eRemoteStoragePlatform);
  bool  result = this->internal->SetSyncPlatforms(pchFile, eRemoteStoragePlatform);
  TRACE("() = (bool )%d\n", result);

  return result;
}


UGCFileWriteStreamHandle_t  ISteamRemoteStorage_::FileWriteStreamOpen(char * pchFile)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\")\n", this, pchFile);
  UGCFileWriteStreamHandle_t  result = this->internal->FileWriteStreamOpen(pchFile);
  TRACE("() = (UGCFileWriteStreamHandle_t )%p\n", result);

  return result;
}


bool  ISteamRemoteStorage_::FileWriteStreamWriteChunk(UGCFileWriteStreamHandle_t  writeHandle, void * pvData, int32  cubData)
{
  TRACE("((ISteamRemoteStorage *)%p, (UGCFileWriteStreamHandle_t )%p, (void *)%p, (int32 )%d)\n", this, writeHandle, pvData, cubData);
  bool  result = this->internal->FileWriteStreamWriteChunk(writeHandle, pvData, cubData);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::FileWriteStreamClose(UGCFileWriteStreamHandle_t  writeHandle)
{
  TRACE("((ISteamRemoteStorage *)%p, (UGCFileWriteStreamHandle_t )%p)\n", this, writeHandle);
  bool  result = this->internal->FileWriteStreamClose(writeHandle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::FileWriteStreamCancel(UGCFileWriteStreamHandle_t  writeHandle)
{
  TRACE("((ISteamRemoteStorage *)%p, (UGCFileWriteStreamHandle_t )%p)\n", this, writeHandle);
  bool  result = this->internal->FileWriteStreamCancel(writeHandle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::FileExists(char * pchFile)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\")\n", this, pchFile);
  bool  result = this->internal->FileExists(pchFile);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::FilePersisted(char * pchFile)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\")\n", this, pchFile);
  bool  result = this->internal->FilePersisted(pchFile);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int32  ISteamRemoteStorage_::GetFileSize(char * pchFile)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\")\n", this, pchFile);
  int32  result = this->internal->GetFileSize(pchFile);
  TRACE("() = (int32 )%d\n", result);

  return result;
}


int64  ISteamRemoteStorage_::GetFileTimestamp(char * pchFile)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\")\n", this, pchFile);
  int64  result = this->internal->GetFileTimestamp(pchFile);
  TRACE("() = (int64 )%d\n", result);

  return result;
}


ERemoteStoragePlatform  ISteamRemoteStorage_::GetSyncPlatforms(char * pchFile)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\")\n", this, pchFile);
  ERemoteStoragePlatform  result = this->internal->GetSyncPlatforms(pchFile);
  TRACE("() = (ERemoteStoragePlatform )%p\n", result);

  return result;
}


int32  ISteamRemoteStorage_::GetFileCount()
{
  TRACE("((ISteamRemoteStorage *)%p)\n", this);
  int32  result = this->internal->GetFileCount();
  TRACE("() = (int32 )%d\n", result);

  return result;
}


char * ISteamRemoteStorage_::GetFileNameAndSize(int  iFile, int32 * pnFileSizeInBytes)
{
  TRACE("((ISteamRemoteStorage *)%p, (int )%d, (int32 *)%d)\n", this, iFile, pnFileSizeInBytes);
  char * result = this->internal->GetFileNameAndSize(iFile, pnFileSizeInBytes);
  TRACE("() = (char *)\"%s\"\n", result);

  return result;
}


bool  ISteamRemoteStorage_::GetQuota(uint64 * pnTotalBytes, uint64 * puAvailableBytes)
{
  TRACE("((ISteamRemoteStorage *)%p, (uint64 *)%d, (uint64 *)%d)\n", this, pnTotalBytes, puAvailableBytes);
  bool  result = this->internal->GetQuota(pnTotalBytes, puAvailableBytes);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::IsCloudEnabledForAccount()
{
  TRACE("((ISteamRemoteStorage *)%p)\n", this);
  bool  result = this->internal->IsCloudEnabledForAccount();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::IsCloudEnabledForApp()
{
  TRACE("((ISteamRemoteStorage *)%p)\n", this);
  bool  result = this->internal->IsCloudEnabledForApp();
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
  SteamAPICall_t  result = this->internal->UGCDownload(hContent, unPriority);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  ISteamRemoteStorage_::GetUGCDownloadProgress(UGCHandle_t  hContent, int32 * pnBytesDownloaded, int32 * pnBytesExpected)
{
  TRACE("((ISteamRemoteStorage *)%p, (UGCHandle_t )%p, (int32 *)%d, (int32 *)%d)\n", this, hContent, pnBytesDownloaded, pnBytesExpected);
  bool  result = this->internal->GetUGCDownloadProgress(hContent, pnBytesDownloaded, pnBytesExpected);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::GetUGCDetails(UGCHandle_t  hContent, AppId_t * pnAppID, char ** ppchName, int32 * pnFileSizeInBytes, CSteamID * pSteamIDOwner)
{
  TRACE("((ISteamRemoteStorage *)%p, (UGCHandle_t )%p, (AppId_t *)%p, (char **)\"%s\", (int32 *)%d, (CSteamID *)%p)\n", this, hContent, pnAppID, ppchName, pnFileSizeInBytes, pSteamIDOwner);
  bool  result = this->internal->GetUGCDetails(hContent, pnAppID, ppchName, pnFileSizeInBytes, pSteamIDOwner);
  TRACE("() = (bool )%d\n", result);

  return result;
}


int32  ISteamRemoteStorage_::UGCRead(UGCHandle_t  hContent, void * pvData, int32  cubDataToRead, uint32  cOffset, EUGCReadAction  eAction)
{
  TRACE("((ISteamRemoteStorage *)%p, (UGCHandle_t )%p, (void *)%p, (int32 )%d, (uint32 )%d, (EUGCReadAction )%p)\n", this, hContent, pvData, cubDataToRead, cOffset, eAction);
  int32  result = this->internal->UGCRead(hContent, pvData, cubDataToRead, cOffset, eAction);
  TRACE("() = (int32 )%d\n", result);

  return result;
}


int32  ISteamRemoteStorage_::GetCachedUGCCount()
{
  TRACE("((ISteamRemoteStorage *)%p)\n", this);
  int32  result = this->internal->GetCachedUGCCount();
  TRACE("() = (int32 )%d\n", result);

  return result;
}


UGCHandle_t  ISteamRemoteStorage_::GetCachedUGCHandle(int32  iCachedContent)
{
  TRACE("((ISteamRemoteStorage *)%p, (int32 )%d)\n", this, iCachedContent);
  UGCHandle_t  result = this->internal->GetCachedUGCHandle(iCachedContent);
  TRACE("() = (UGCHandle_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::PublishWorkshopFile(char * pchFile, char * pchPreviewFile, AppId_t  nConsumerAppId, char * pchTitle, char * pchDescription, ERemoteStoragePublishedFileVisibility  eVisibility, SteamParamStringArray_t * pTags, EWorkshopFileType  eWorkshopFileType)
{
  TRACE("((ISteamRemoteStorage *)%p, (char *)\"%s\", (char *)\"%s\", (AppId_t )%p, (char *)\"%s\", (char *)\"%s\", (ERemoteStoragePublishedFileVisibility )%p, (SteamParamStringArray_t *)%p, (EWorkshopFileType )%p)\n", this, pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, pTags, eWorkshopFileType);
  SteamAPICall_t  result = this->internal->PublishWorkshopFile(pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, pTags, eWorkshopFileType);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


PublishedFileUpdateHandle_t  ISteamRemoteStorage_::CreatePublishedFileUpdateRequest(PublishedFileId_t  unPublishedFileId)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileId_t )%p)\n", this, unPublishedFileId);
  PublishedFileUpdateHandle_t  result = this->internal->CreatePublishedFileUpdateRequest(unPublishedFileId);
  TRACE("() = (PublishedFileUpdateHandle_t )%p\n", result);

  return result;
}


bool  ISteamRemoteStorage_::UpdatePublishedFileFile(PublishedFileUpdateHandle_t  updateHandle, char * pchFile)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileUpdateHandle_t )%p, (char *)\"%s\")\n", this, updateHandle, pchFile);
  bool  result = this->internal->UpdatePublishedFileFile(updateHandle, pchFile);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t  updateHandle, char * pchPreviewFile)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileUpdateHandle_t )%p, (char *)\"%s\")\n", this, updateHandle, pchPreviewFile);
  bool  result = this->internal->UpdatePublishedFilePreviewFile(updateHandle, pchPreviewFile);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::UpdatePublishedFileTitle(PublishedFileUpdateHandle_t  updateHandle, char * pchTitle)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileUpdateHandle_t )%p, (char *)\"%s\")\n", this, updateHandle, pchTitle);
  bool  result = this->internal->UpdatePublishedFileTitle(updateHandle, pchTitle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::UpdatePublishedFileDescription(PublishedFileUpdateHandle_t  updateHandle, char * pchDescription)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileUpdateHandle_t )%p, (char *)\"%s\")\n", this, updateHandle, pchDescription);
  bool  result = this->internal->UpdatePublishedFileDescription(updateHandle, pchDescription);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t  updateHandle, ERemoteStoragePublishedFileVisibility  eVisibility)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileUpdateHandle_t )%p, (ERemoteStoragePublishedFileVisibility )%p)\n", this, updateHandle, eVisibility);
  bool  result = this->internal->UpdatePublishedFileVisibility(updateHandle, eVisibility);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamRemoteStorage_::UpdatePublishedFileTags(PublishedFileUpdateHandle_t  updateHandle, SteamParamStringArray_t * pTags)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileUpdateHandle_t )%p, (SteamParamStringArray_t *)%p)\n", this, updateHandle, pTags);
  bool  result = this->internal->UpdatePublishedFileTags(updateHandle, pTags);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::CommitPublishedFileUpdate(PublishedFileUpdateHandle_t  updateHandle)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileUpdateHandle_t )%p)\n", this, updateHandle);
  SteamAPICall_t  result = this->internal->CommitPublishedFileUpdate(updateHandle);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::GetPublishedFileDetails(PublishedFileId_t  unPublishedFileId, uint32  unMaxSecondsOld)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileId_t )%p, (uint32 )%d)\n", this, unPublishedFileId, unMaxSecondsOld);
  SteamAPICall_t  result = this->internal->GetPublishedFileDetails(unPublishedFileId, unMaxSecondsOld);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::DeletePublishedFile(PublishedFileId_t  unPublishedFileId)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileId_t )%p)\n", this, unPublishedFileId);
  SteamAPICall_t  result = this->internal->DeletePublishedFile(unPublishedFileId);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::EnumerateUserPublishedFiles(uint32  unStartIndex)
{
  TRACE("((ISteamRemoteStorage *)%p, (uint32 )%d)\n", this, unStartIndex);
  SteamAPICall_t  result = this->internal->EnumerateUserPublishedFiles(unStartIndex);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::SubscribePublishedFile(PublishedFileId_t  unPublishedFileId)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileId_t )%p)\n", this, unPublishedFileId);
  SteamAPICall_t  result = this->internal->SubscribePublishedFile(unPublishedFileId);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::EnumerateUserSubscribedFiles(uint32  unStartIndex)
{
  TRACE("((ISteamRemoteStorage *)%p, (uint32 )%d)\n", this, unStartIndex);
  SteamAPICall_t  result = this->internal->EnumerateUserSubscribedFiles(unStartIndex);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::UnsubscribePublishedFile(PublishedFileId_t  unPublishedFileId)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileId_t )%p)\n", this, unPublishedFileId);
  SteamAPICall_t  result = this->internal->UnsubscribePublishedFile(unPublishedFileId);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  ISteamRemoteStorage_::UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t  updateHandle, char * pchChangeDescription)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileUpdateHandle_t )%p, (char *)\"%s\")\n", this, updateHandle, pchChangeDescription);
  bool  result = this->internal->UpdatePublishedFileSetChangeDescription(updateHandle, pchChangeDescription);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::GetPublishedItemVoteDetails(PublishedFileId_t  unPublishedFileId)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileId_t )%p)\n", this, unPublishedFileId);
  SteamAPICall_t  result = this->internal->GetPublishedItemVoteDetails(unPublishedFileId);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::UpdateUserPublishedItemVote(PublishedFileId_t  unPublishedFileId, bool  bVoteUp)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileId_t )%p, (bool )%d)\n", this, unPublishedFileId, bVoteUp);
  SteamAPICall_t  result = this->internal->UpdateUserPublishedItemVote(unPublishedFileId, bVoteUp);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::GetUserPublishedItemVoteDetails(PublishedFileId_t  unPublishedFileId)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileId_t )%p)\n", this, unPublishedFileId);
  SteamAPICall_t  result = this->internal->GetUserPublishedItemVoteDetails(unPublishedFileId);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::EnumerateUserSharedWorkshopFiles(CSteamID  steamId, uint32  unStartIndex, SteamParamStringArray_t * pRequiredTags, SteamParamStringArray_t * pExcludedTags)
{
  TRACE("((ISteamRemoteStorage *)%p, (CSteamID )%p, (uint32 )%d, (SteamParamStringArray_t *)%p, (SteamParamStringArray_t *)%p)\n", this, steamId, unStartIndex, pRequiredTags, pExcludedTags);
  SteamAPICall_t  result = this->internal->EnumerateUserSharedWorkshopFiles(steamId, unStartIndex, pRequiredTags, pExcludedTags);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::PublishVideo(EWorkshopVideoProvider  eVideoProvider, char * pchVideoAccount, char * pchVideoIdentifier, char * pchPreviewFile, AppId_t  nConsumerAppId, char * pchTitle, char * pchDescription, ERemoteStoragePublishedFileVisibility  eVisibility, SteamParamStringArray_t * pTags)
{
  TRACE("((ISteamRemoteStorage *)%p, (EWorkshopVideoProvider )%p, (char *)\"%s\", (char *)\"%s\", (char *)\"%s\", (AppId_t )%p, (char *)\"%s\", (char *)\"%s\", (ERemoteStoragePublishedFileVisibility )%p, (SteamParamStringArray_t *)%p)\n", this, eVideoProvider, pchVideoAccount, pchVideoIdentifier, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, pTags);
  SteamAPICall_t  result = this->internal->PublishVideo(eVideoProvider, pchVideoAccount, pchVideoIdentifier, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, pTags);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::SetUserPublishedFileAction(PublishedFileId_t  unPublishedFileId, EWorkshopFileAction  eAction)
{
  TRACE("((ISteamRemoteStorage *)%p, (PublishedFileId_t )%p, (EWorkshopFileAction )%p)\n", this, unPublishedFileId, eAction);
  SteamAPICall_t  result = this->internal->SetUserPublishedFileAction(unPublishedFileId, eAction);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::EnumeratePublishedFilesByUserAction(EWorkshopFileAction  eAction, uint32  unStartIndex)
{
  TRACE("((ISteamRemoteStorage *)%p, (EWorkshopFileAction )%p, (uint32 )%d)\n", this, eAction, unStartIndex);
  SteamAPICall_t  result = this->internal->EnumeratePublishedFilesByUserAction(eAction, unStartIndex);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType  eEnumerationType, uint32  unStartIndex, uint32  unCount, uint32  unDays, SteamParamStringArray_t * pTags, SteamParamStringArray_t * pUserTags)
{
  TRACE("((ISteamRemoteStorage *)%p, (EWorkshopEnumerationType )%p, (uint32 )%d, (uint32 )%d, (uint32 )%d, (SteamParamStringArray_t *)%p, (SteamParamStringArray_t *)%p)\n", this, eEnumerationType, unStartIndex, unCount, unDays, pTags, pUserTags);
  SteamAPICall_t  result = this->internal->EnumeratePublishedWorkshopFiles(eEnumerationType, unStartIndex, unCount, unDays, pTags, pUserTags);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


SteamAPICall_t  ISteamRemoteStorage_::UGCDownloadToLocation(UGCHandle_t  hContent, char * pchLocation, uint32  unPriority)
{
  TRACE("((ISteamRemoteStorage *)%p, (UGCHandle_t )%p, (char *)\"%s\", (uint32 )%d)\n", this, hContent, pchLocation, unPriority);
  SteamAPICall_t  result = this->internal->UGCDownloadToLocation(hContent, pchLocation, unPriority);
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
