#ifndef WRAP_ISTEAMUGC_H
#define WRAP_ISTEAMUGC_H
#include "steam_api.h"
class ISteamUGC_ 
{
  virtual UGCQueryHandle_t CreateQueryUserUGCRequest( AccountID_t unAccountID, EUserUGCList eListType, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eSortOrder, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage ) __attribute__((thiscall));
  virtual UGCQueryHandle_t CreateQueryAllUGCRequest( EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage ) __attribute__((thiscall));
  virtual UGCQueryHandle_t CreateQueryUGCDetailsRequest( PublishedFileId_t *pvecPublishedFileID, uint32 unNumPublishedFileIDs ) __attribute__((thiscall));
  virtual SteamAPICall_t SendQueryUGCRequest( UGCQueryHandle_t handle ) __attribute__((thiscall));
  virtual bool GetQueryUGCResult( UGCQueryHandle_t handle, uint32 index, SteamUGCDetails_t *pDetails ) __attribute__((thiscall));
  virtual bool GetQueryUGCPreviewURL( UGCQueryHandle_t handle, uint32 index, OUT_STRING_COUNT(cchURLSize) char *pchURL, uint32 cchURLSize ) __attribute__((thiscall));
  virtual bool GetQueryUGCMetadata( UGCQueryHandle_t handle, uint32 index, OUT_STRING_COUNT(cchMetadatasize) char *pchMetadata, uint32 cchMetadatasize ) __attribute__((thiscall));
  virtual bool GetQueryUGCChildren( UGCQueryHandle_t handle, uint32 index, PublishedFileId_t* pvecPublishedFileID, uint32 cMaxEntries ) __attribute__((thiscall));
  virtual bool GetQueryUGCStatistic( UGCQueryHandle_t handle, uint32 index, EItemStatistic eStatType, uint64 *pStatValue ) __attribute__((thiscall));
  virtual uint32 GetQueryUGCNumAdditionalPreviews( UGCQueryHandle_t handle, uint32 index ) __attribute__((thiscall));
  virtual bool GetQueryUGCAdditionalPreview( UGCQueryHandle_t handle, uint32 index, uint32 previewIndex, OUT_STRING_COUNT(cchURLSize) char *pchURLOrVideoID, uint32 cchURLSize, OUT_STRING_COUNT(cchURLSize) char *pchOriginalFileName, uint32 cchOriginalFileNameSize, EItemPreviewType *pPreviewType ) __attribute__((thiscall));
  virtual uint32 GetQueryUGCNumKeyValueTags( UGCQueryHandle_t handle, uint32 index ) __attribute__((thiscall));
  virtual bool GetQueryUGCKeyValueTag( UGCQueryHandle_t handle, uint32 index, uint32 keyValueTagIndex, OUT_STRING_COUNT(cchKeySize) char *pchKey, uint32 cchKeySize, OUT_STRING_COUNT(cchValueSize) char *pchValue, uint32 cchValueSize ) __attribute__((thiscall));
  virtual bool ReleaseQueryUGCRequest( UGCQueryHandle_t handle ) __attribute__((thiscall));
  virtual bool AddRequiredTag( UGCQueryHandle_t handle, const char *pTagName ) __attribute__((thiscall));
  virtual bool AddExcludedTag( UGCQueryHandle_t handle, const char *pTagName ) __attribute__((thiscall));
  virtual bool SetReturnOnlyIDs( UGCQueryHandle_t handle, bool bReturnOnlyIDs ) __attribute__((thiscall));
  virtual bool SetReturnKeyValueTags( UGCQueryHandle_t handle, bool bReturnKeyValueTags ) __attribute__((thiscall));
  virtual bool SetReturnLongDescription( UGCQueryHandle_t handle, bool bReturnLongDescription ) __attribute__((thiscall));
  virtual bool SetReturnMetadata( UGCQueryHandle_t handle, bool bReturnMetadata ) __attribute__((thiscall));
  virtual bool SetReturnChildren( UGCQueryHandle_t handle, bool bReturnChildren ) __attribute__((thiscall));
  virtual bool SetReturnAdditionalPreviews( UGCQueryHandle_t handle, bool bReturnAdditionalPreviews ) __attribute__((thiscall));
  virtual bool SetReturnTotalOnly( UGCQueryHandle_t handle, bool bReturnTotalOnly ) __attribute__((thiscall));
  virtual bool SetLanguage( UGCQueryHandle_t handle, const char *pchLanguage ) __attribute__((thiscall));
  virtual bool SetAllowCachedResponse( UGCQueryHandle_t handle, uint32 unMaxAgeSeconds ) __attribute__((thiscall));
  virtual bool SetCloudFileNameFilter( UGCQueryHandle_t handle, const char *pMatchCloudFileName ) __attribute__((thiscall));
  virtual bool SetMatchAnyTag( UGCQueryHandle_t handle, bool bMatchAnyTag ) __attribute__((thiscall));
  virtual bool SetSearchText( UGCQueryHandle_t handle, const char *pSearchText ) __attribute__((thiscall));
  virtual bool SetRankedByTrendDays( UGCQueryHandle_t handle, uint32 unDays ) __attribute__((thiscall));
  virtual bool AddRequiredKeyValueTag( UGCQueryHandle_t handle, const char *pKey, const char *pValue ) __attribute__((thiscall));
  virtual SteamAPICall_t RequestUGCDetails( PublishedFileId_t nPublishedFileID, uint32 unMaxAgeSeconds ) __attribute__((thiscall));
  virtual SteamAPICall_t CreateItem( AppId_t nConsumerAppId, EWorkshopFileType eFileType ) __attribute__((thiscall));
  virtual UGCUpdateHandle_t StartItemUpdate( AppId_t nConsumerAppId, PublishedFileId_t nPublishedFileID ) __attribute__((thiscall));
  virtual bool SetItemTitle( UGCUpdateHandle_t handle, const char *pchTitle ) __attribute__((thiscall));
  virtual bool SetItemDescription( UGCUpdateHandle_t handle, const char *pchDescription ) __attribute__((thiscall));
  virtual bool SetItemUpdateLanguage( UGCUpdateHandle_t handle, const char *pchLanguage ) __attribute__((thiscall));
  virtual bool SetItemMetadata( UGCUpdateHandle_t handle, const char *pchMetaData ) __attribute__((thiscall));
  virtual bool SetItemVisibility( UGCUpdateHandle_t handle, ERemoteStoragePublishedFileVisibility eVisibility ) __attribute__((thiscall));
  virtual bool SetItemTags( UGCUpdateHandle_t updateHandle, const SteamParamStringArray_t *pTags ) __attribute__((thiscall));
  virtual bool SetItemContent( UGCUpdateHandle_t handle, const char *pszContentFolder ) __attribute__((thiscall));
  virtual bool SetItemPreview( UGCUpdateHandle_t handle, const char *pszPreviewFile ) __attribute__((thiscall));
  virtual bool RemoveItemKeyValueTags( UGCUpdateHandle_t handle, const char *pchKey ) __attribute__((thiscall));
  virtual bool AddItemKeyValueTag( UGCUpdateHandle_t handle, const char *pchKey, const char *pchValue ) __attribute__((thiscall));
  virtual bool AddItemPreviewFile( UGCUpdateHandle_t handle, const char *pszPreviewFile, EItemPreviewType type ) __attribute__((thiscall));
  virtual bool AddItemPreviewVideo( UGCUpdateHandle_t handle, const char *pszVideoID ) __attribute__((thiscall));
  virtual bool UpdateItemPreviewFile( UGCUpdateHandle_t handle, uint32 index, const char *pszPreviewFile ) __attribute__((thiscall));
  virtual bool UpdateItemPreviewVideo( UGCUpdateHandle_t handle, uint32 index, const char *pszVideoID ) __attribute__((thiscall));
  virtual bool RemoveItemPreview( UGCUpdateHandle_t handle, uint32 index ) __attribute__((thiscall));
  virtual SteamAPICall_t SubmitItemUpdate( UGCUpdateHandle_t handle, const char *pchChangeNote ) __attribute__((thiscall));
  virtual EItemUpdateStatus GetItemUpdateProgress( UGCUpdateHandle_t handle, uint64 *punBytesProcessed, uint64* punBytesTotal ) __attribute__((thiscall));
  virtual SteamAPICall_t SetUserItemVote( PublishedFileId_t nPublishedFileID, bool bVoteUp ) __attribute__((thiscall));
  virtual SteamAPICall_t GetUserItemVote( PublishedFileId_t nPublishedFileID ) __attribute__((thiscall));
  virtual SteamAPICall_t AddItemToFavorites( AppId_t nAppId, PublishedFileId_t nPublishedFileID ) __attribute__((thiscall));
  virtual SteamAPICall_t RemoveItemFromFavorites( AppId_t nAppId, PublishedFileId_t nPublishedFileID ) __attribute__((thiscall));
  virtual SteamAPICall_t SubscribeItem( PublishedFileId_t nPublishedFileID ) __attribute__((thiscall));
  virtual SteamAPICall_t UnsubscribeItem( PublishedFileId_t nPublishedFileID ) __attribute__((thiscall));
  virtual uint32 GetNumSubscribedItems() __attribute__((thiscall));
  virtual uint32 GetSubscribedItems( PublishedFileId_t* pvecPublishedFileID, uint32 cMaxEntries ) __attribute__((thiscall));
  virtual uint32 GetItemState( PublishedFileId_t nPublishedFileID ) __attribute__((thiscall));
  virtual bool GetItemInstallInfo( PublishedFileId_t nPublishedFileID, uint64 *punSizeOnDisk, OUT_STRING_COUNT( cchFolderSize ) char *pchFolder, uint32 cchFolderSize, uint32 *punTimeStamp ) __attribute__((thiscall));
  virtual bool GetItemDownloadInfo( PublishedFileId_t nPublishedFileID, uint64 *punBytesDownloaded, uint64 *punBytesTotal ) __attribute__((thiscall));
  virtual bool DownloadItem( PublishedFileId_t nPublishedFileID, bool bHighPriority ) __attribute__((thiscall));
  virtual bool BInitWorkshopForGameServer( DepotId_t unWorkshopDepotID, const char *pszFolder ) __attribute__((thiscall));
  virtual void SuspendDownloads( bool bSuspend ) __attribute__((thiscall));
  virtual SteamAPICall_t StartPlaytimeTracking( PublishedFileId_t *pvecPublishedFileID, uint32 unNumPublishedFileIDs ) __attribute__((thiscall));
  virtual SteamAPICall_t StopPlaytimeTracking( PublishedFileId_t *pvecPublishedFileID, uint32 unNumPublishedFileIDs ) __attribute__((thiscall));
  virtual SteamAPICall_t StopPlaytimeTrackingForAllItems() __attribute__((thiscall));
  public:
    ISteamUGC *internal;
};
#endif
