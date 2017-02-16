#ifndef WRAP_ISTEAMREMOTESTORAGE_H
#define WRAP_ISTEAMREMOTESTORAGE_H
#include "steam_api.h"
class ISteamRemoteStorage_ 
{
  virtual bool FileWrite( const char *pchFile, const void *pvData, int32 cubData ) __attribute__((thiscall));
  virtual int32 FileRead( const char *pchFile, void *pvData, int32 cubDataToRead ) __attribute__((thiscall));
  virtual SteamAPICall_t FileWriteAsync( const char *pchFile, const void *pvData, uint32 cubData ) __attribute__((thiscall));
  virtual SteamAPICall_t FileReadAsync( const char *pchFile, uint32 nOffset, uint32 cubToRead ) __attribute__((thiscall));
  virtual bool FileReadAsyncComplete( SteamAPICall_t hReadCall, void *pvBuffer, uint32 cubToRead ) __attribute__((thiscall));
  virtual bool FileForget( const char *pchFile ) __attribute__((thiscall));
  virtual bool FileDelete( const char *pchFile ) __attribute__((thiscall));
  virtual SteamAPICall_t FileShare( const char *pchFile ) __attribute__((thiscall));
  virtual bool SetSyncPlatforms( const char *pchFile, ERemoteStoragePlatform eRemoteStoragePlatform ) __attribute__((thiscall));
  virtual UGCFileWriteStreamHandle_t FileWriteStreamOpen( const char *pchFile ) __attribute__((thiscall));
  virtual bool FileWriteStreamWriteChunk( UGCFileWriteStreamHandle_t writeHandle, const void *pvData, int32 cubData ) __attribute__((thiscall));
  virtual bool FileWriteStreamClose( UGCFileWriteStreamHandle_t writeHandle ) __attribute__((thiscall));
  virtual bool FileWriteStreamCancel( UGCFileWriteStreamHandle_t writeHandle ) __attribute__((thiscall));
  virtual bool FileExists( const char *pchFile ) __attribute__((thiscall));
  virtual bool FilePersisted( const char *pchFile ) __attribute__((thiscall));
  virtual int32 GetFileSize( const char *pchFile ) __attribute__((thiscall));
  virtual int64 GetFileTimestamp( const char *pchFile ) __attribute__((thiscall));
  virtual ERemoteStoragePlatform GetSyncPlatforms( const char *pchFile ) __attribute__((thiscall));
  virtual int32 GetFileCount() __attribute__((thiscall));
  virtual const char * GetFileNameAndSize( int iFile, int32 *pnFileSizeInBytes ) __attribute__((thiscall));
  virtual bool GetQuota( uint64 *pnTotalBytes, uint64 *puAvailableBytes ) __attribute__((thiscall));
  virtual bool IsCloudEnabledForAccount() __attribute__((thiscall));
  virtual bool IsCloudEnabledForApp() __attribute__((thiscall));
  virtual void SetCloudEnabledForApp( bool bEnabled ) __attribute__((thiscall));
  virtual SteamAPICall_t UGCDownload( UGCHandle_t hContent, uint32 unPriority ) __attribute__((thiscall));
  virtual bool GetUGCDownloadProgress( UGCHandle_t hContent, int32 *pnBytesDownloaded, int32 *pnBytesExpected ) __attribute__((thiscall));
  virtual bool GetUGCDetails( UGCHandle_t hContent, AppId_t *pnAppID, OUT_STRING() char **ppchName, int32 *pnFileSizeInBytes, OUT_STRUCT() CSteamID *pSteamIDOwner ) __attribute__((thiscall));
  virtual int32 UGCRead( UGCHandle_t hContent, void *pvData, int32 cubDataToRead, uint32 cOffset, EUGCReadAction eAction ) __attribute__((thiscall));
  virtual int32 GetCachedUGCCount() __attribute__((thiscall));
  virtual UGCHandle_t GetCachedUGCHandle( int32 iCachedContent ) __attribute__((thiscall));
  virtual SteamAPICall_t PublishWorkshopFile( const char *pchFile, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags, EWorkshopFileType eWorkshopFileType ) __attribute__((thiscall));
  virtual PublishedFileUpdateHandle_t CreatePublishedFileUpdateRequest( PublishedFileId_t unPublishedFileId ) __attribute__((thiscall));
  virtual bool UpdatePublishedFileFile( PublishedFileUpdateHandle_t updateHandle, const char *pchFile ) __attribute__((thiscall));
  virtual bool UpdatePublishedFilePreviewFile( PublishedFileUpdateHandle_t updateHandle, const char *pchPreviewFile ) __attribute__((thiscall));
  virtual bool UpdatePublishedFileTitle( PublishedFileUpdateHandle_t updateHandle, const char *pchTitle ) __attribute__((thiscall));
  virtual bool UpdatePublishedFileDescription( PublishedFileUpdateHandle_t updateHandle, const char *pchDescription ) __attribute__((thiscall));
  virtual bool UpdatePublishedFileVisibility( PublishedFileUpdateHandle_t updateHandle, ERemoteStoragePublishedFileVisibility eVisibility ) __attribute__((thiscall));
  virtual bool UpdatePublishedFileTags( PublishedFileUpdateHandle_t updateHandle, SteamParamStringArray_t *pTags ) __attribute__((thiscall));
  virtual SteamAPICall_t CommitPublishedFileUpdate( PublishedFileUpdateHandle_t updateHandle ) __attribute__((thiscall));
  virtual SteamAPICall_t GetPublishedFileDetails( PublishedFileId_t unPublishedFileId, uint32 unMaxSecondsOld ) __attribute__((thiscall));
  virtual SteamAPICall_t DeletePublishedFile( PublishedFileId_t unPublishedFileId ) __attribute__((thiscall));
  virtual SteamAPICall_t EnumerateUserPublishedFiles( uint32 unStartIndex ) __attribute__((thiscall));
  virtual SteamAPICall_t SubscribePublishedFile( PublishedFileId_t unPublishedFileId ) __attribute__((thiscall));
  virtual SteamAPICall_t EnumerateUserSubscribedFiles( uint32 unStartIndex ) __attribute__((thiscall));
  virtual SteamAPICall_t UnsubscribePublishedFile( PublishedFileId_t unPublishedFileId ) __attribute__((thiscall));
  virtual bool UpdatePublishedFileSetChangeDescription( PublishedFileUpdateHandle_t updateHandle, const char *pchChangeDescription ) __attribute__((thiscall));
  virtual SteamAPICall_t GetPublishedItemVoteDetails( PublishedFileId_t unPublishedFileId ) __attribute__((thiscall));
  virtual SteamAPICall_t UpdateUserPublishedItemVote( PublishedFileId_t unPublishedFileId, bool bVoteUp ) __attribute__((thiscall));
  virtual SteamAPICall_t GetUserPublishedItemVoteDetails( PublishedFileId_t unPublishedFileId ) __attribute__((thiscall));
  virtual SteamAPICall_t EnumerateUserSharedWorkshopFiles( CSteamID steamId, uint32 unStartIndex, SteamParamStringArray_t *pRequiredTags, SteamParamStringArray_t *pExcludedTags ) __attribute__((thiscall));
  virtual SteamAPICall_t PublishVideo( EWorkshopVideoProvider eVideoProvider, const char *pchVideoAccount, const char *pchVideoIdentifier, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags ) __attribute__((thiscall));
  virtual SteamAPICall_t SetUserPublishedFileAction( PublishedFileId_t unPublishedFileId, EWorkshopFileAction eAction ) __attribute__((thiscall));
  virtual SteamAPICall_t EnumeratePublishedFilesByUserAction( EWorkshopFileAction eAction, uint32 unStartIndex ) __attribute__((thiscall));
  virtual SteamAPICall_t EnumeratePublishedWorkshopFiles( EWorkshopEnumerationType eEnumerationType, uint32 unStartIndex, uint32 unCount, uint32 unDays, SteamParamStringArray_t *pTags, SteamParamStringArray_t *pUserTags ) __attribute__((thiscall));
  virtual SteamAPICall_t UGCDownloadToLocation( UGCHandle_t hContent, const char *pchLocation, uint32 unPriority ) __attribute__((thiscall));
  public:
    ISteamRemoteStorage *internal;
};
#endif
