#include <steam_api_.h>
#include <isteamremotestorage.h>
class ISteamRemoteStorage_
{
public:
  virtual bool  FileWrite(char * pchFile, void * pvData, int32  cubData) __attribute__((thiscall));
  virtual int32  FileRead(char * pchFile, void * pvData, int32  cubDataToRead) __attribute__((thiscall));
  virtual SteamAPICall_t  FileWriteAsync(char * pchFile, void * pvData, uint32  cubData) __attribute__((thiscall));
  virtual SteamAPICall_t  FileReadAsync(char * pchFile, uint32  nOffset, uint32  cubToRead) __attribute__((thiscall));
  virtual bool  FileReadAsyncComplete(SteamAPICall_t  hReadCall, void * pvBuffer, uint32  cubToRead) __attribute__((thiscall));
  virtual bool  FileForget(char * pchFile) __attribute__((thiscall));
  virtual bool  FileDelete(char * pchFile) __attribute__((thiscall));
  virtual SteamAPICall_t  FileShare(char * pchFile) __attribute__((thiscall));
  virtual bool  SetSyncPlatforms(char * pchFile, ERemoteStoragePlatform  eRemoteStoragePlatform) __attribute__((thiscall));
  virtual UGCFileWriteStreamHandle_t  FileWriteStreamOpen(char * pchFile) __attribute__((thiscall));
  virtual bool  FileWriteStreamWriteChunk(UGCFileWriteStreamHandle_t  writeHandle, void * pvData, int32  cubData) __attribute__((thiscall));
  virtual bool  FileWriteStreamClose(UGCFileWriteStreamHandle_t  writeHandle) __attribute__((thiscall));
  virtual bool  FileWriteStreamCancel(UGCFileWriteStreamHandle_t  writeHandle) __attribute__((thiscall));
  virtual bool  FileExists(char * pchFile) __attribute__((thiscall));
  virtual bool  FilePersisted(char * pchFile) __attribute__((thiscall));
  virtual int32  GetFileSize(char * pchFile) __attribute__((thiscall));
  virtual int64  GetFileTimestamp(char * pchFile) __attribute__((thiscall));
  virtual ERemoteStoragePlatform  GetSyncPlatforms(char * pchFile) __attribute__((thiscall));
  virtual int32  GetFileCount() __attribute__((thiscall));
  virtual char * GetFileNameAndSize(int  iFile, int32 * pnFileSizeInBytes) __attribute__((thiscall));
  virtual bool  GetQuota(uint64 * pnTotalBytes, uint64 * puAvailableBytes) __attribute__((thiscall));
  virtual bool  IsCloudEnabledForAccount() __attribute__((thiscall));
  virtual bool  IsCloudEnabledForApp() __attribute__((thiscall));
  virtual void  SetCloudEnabledForApp(bool  bEnabled) __attribute__((thiscall));
  virtual SteamAPICall_t  UGCDownload(UGCHandle_t  hContent, uint32  unPriority) __attribute__((thiscall));
  virtual bool  GetUGCDownloadProgress(UGCHandle_t  hContent, int32 * pnBytesDownloaded, int32 * pnBytesExpected) __attribute__((thiscall));
  virtual bool  GetUGCDetails(UGCHandle_t  hContent, AppId_t * pnAppID, char ** ppchName, int32 * pnFileSizeInBytes, CSteamID * pSteamIDOwner) __attribute__((thiscall));
  virtual int32  UGCRead(UGCHandle_t  hContent, void * pvData, int32  cubDataToRead, uint32  cOffset, EUGCReadAction  eAction) __attribute__((thiscall));
  virtual int32  GetCachedUGCCount() __attribute__((thiscall));
  virtual UGCHandle_t  GetCachedUGCHandle(int32  iCachedContent) __attribute__((thiscall));
  virtual SteamAPICall_t  PublishWorkshopFile(char * pchFile, char * pchPreviewFile, AppId_t  nConsumerAppId, char * pchTitle, char * pchDescription, ERemoteStoragePublishedFileVisibility  eVisibility, SteamParamStringArray_t * pTags, EWorkshopFileType  eWorkshopFileType) __attribute__((thiscall));
  virtual PublishedFileUpdateHandle_t  CreatePublishedFileUpdateRequest(PublishedFileId_t  unPublishedFileId) __attribute__((thiscall));
  virtual bool  UpdatePublishedFileFile(PublishedFileUpdateHandle_t  updateHandle, char * pchFile) __attribute__((thiscall));
  virtual bool  UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t  updateHandle, char * pchPreviewFile) __attribute__((thiscall));
  virtual bool  UpdatePublishedFileTitle(PublishedFileUpdateHandle_t  updateHandle, char * pchTitle) __attribute__((thiscall));
  virtual bool  UpdatePublishedFileDescription(PublishedFileUpdateHandle_t  updateHandle, char * pchDescription) __attribute__((thiscall));
  virtual bool  UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t  updateHandle, ERemoteStoragePublishedFileVisibility  eVisibility) __attribute__((thiscall));
  virtual bool  UpdatePublishedFileTags(PublishedFileUpdateHandle_t  updateHandle, SteamParamStringArray_t * pTags) __attribute__((thiscall));
  virtual SteamAPICall_t  CommitPublishedFileUpdate(PublishedFileUpdateHandle_t  updateHandle) __attribute__((thiscall));
  virtual SteamAPICall_t  GetPublishedFileDetails(PublishedFileId_t  unPublishedFileId, uint32  unMaxSecondsOld) __attribute__((thiscall));
  virtual SteamAPICall_t  DeletePublishedFile(PublishedFileId_t  unPublishedFileId) __attribute__((thiscall));
  virtual SteamAPICall_t  EnumerateUserPublishedFiles(uint32  unStartIndex) __attribute__((thiscall));
  virtual SteamAPICall_t  SubscribePublishedFile(PublishedFileId_t  unPublishedFileId) __attribute__((thiscall));
  virtual SteamAPICall_t  EnumerateUserSubscribedFiles(uint32  unStartIndex) __attribute__((thiscall));
  virtual SteamAPICall_t  UnsubscribePublishedFile(PublishedFileId_t  unPublishedFileId) __attribute__((thiscall));
  virtual bool  UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t  updateHandle, char * pchChangeDescription) __attribute__((thiscall));
  virtual SteamAPICall_t  GetPublishedItemVoteDetails(PublishedFileId_t  unPublishedFileId) __attribute__((thiscall));
  virtual SteamAPICall_t  UpdateUserPublishedItemVote(PublishedFileId_t  unPublishedFileId, bool  bVoteUp) __attribute__((thiscall));
  virtual SteamAPICall_t  GetUserPublishedItemVoteDetails(PublishedFileId_t  unPublishedFileId) __attribute__((thiscall));
  virtual SteamAPICall_t  EnumerateUserSharedWorkshopFiles(CSteamID  steamId, uint32  unStartIndex, SteamParamStringArray_t * pRequiredTags, SteamParamStringArray_t * pExcludedTags) __attribute__((thiscall));
  virtual SteamAPICall_t  PublishVideo(EWorkshopVideoProvider  eVideoProvider, char * pchVideoAccount, char * pchVideoIdentifier, char * pchPreviewFile, AppId_t  nConsumerAppId, char * pchTitle, char * pchDescription, ERemoteStoragePublishedFileVisibility  eVisibility, SteamParamStringArray_t * pTags) __attribute__((thiscall));
  virtual SteamAPICall_t  SetUserPublishedFileAction(PublishedFileId_t  unPublishedFileId, EWorkshopFileAction  eAction) __attribute__((thiscall));
  virtual SteamAPICall_t  EnumeratePublishedFilesByUserAction(EWorkshopFileAction  eAction, uint32  unStartIndex) __attribute__((thiscall));
  virtual SteamAPICall_t  EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType  eEnumerationType, uint32  unStartIndex, uint32  unCount, uint32  unDays, SteamParamStringArray_t * pTags, SteamParamStringArray_t * pUserTags) __attribute__((thiscall));
  virtual SteamAPICall_t  UGCDownloadToLocation(UGCHandle_t  hContent, char * pchLocation, uint32  unPriority) __attribute__((thiscall));
  ISteamRemoteStorage_(ISteamRemoteStorage*to_wrap);
  ~ISteamRemoteStorage_();
private:
  ISteamRemoteStorage * internal;
};
