#include <steam_api_.h>
#include <isteaminventory.h>
class ISteamInventory_
{
public:
  virtual EResult  GetResultStatus(SteamInventoryResult_t  resultHandle) __attribute__((thiscall));
  virtual bool  GetResultItems(SteamInventoryResult_t  resultHandle, SteamItemDetails_t * pOutItemsArray, uint32 * punOutItemsArraySize) __attribute__((thiscall));
  virtual uint32  GetResultTimestamp(SteamInventoryResult_t  resultHandle) __attribute__((thiscall));
  virtual bool  CheckResultSteamID(SteamInventoryResult_t  resultHandle, CSteamID  steamIDExpected) __attribute__((thiscall));
  virtual void  DestroyResult(SteamInventoryResult_t  resultHandle) __attribute__((thiscall));
  virtual bool  GetAllItems(SteamInventoryResult_t * pResultHandle) __attribute__((thiscall));
  virtual bool  GetItemsByID(SteamInventoryResult_t * pResultHandle, SteamItemInstanceID_t * pInstanceIDs, uint32  unCountInstanceIDs) __attribute__((thiscall));
  virtual bool  SerializeResult(SteamInventoryResult_t  resultHandle, void * pOutBuffer, uint32 * punOutBufferSize) __attribute__((thiscall));
  virtual bool  DeserializeResult(SteamInventoryResult_t * pOutResultHandle, void * pBuffer, uint32  unBufferSize, bool  bRESERVED_MUST_BE_FALSE) __attribute__((thiscall));
  virtual bool  GenerateItems(SteamInventoryResult_t * pResultHandle, SteamItemDef_t * pArrayItemDefs, uint32 * punArrayQuantity, uint32  unArrayLength) __attribute__((thiscall));
  virtual bool  GrantPromoItems(SteamInventoryResult_t * pResultHandle) __attribute__((thiscall));
  virtual bool  AddPromoItem(SteamInventoryResult_t * pResultHandle, SteamItemDef_t  itemDef) __attribute__((thiscall));
  virtual bool  AddPromoItems(SteamInventoryResult_t * pResultHandle, SteamItemDef_t * pArrayItemDefs, uint32  unArrayLength) __attribute__((thiscall));
  virtual bool  ConsumeItem(SteamInventoryResult_t * pResultHandle, SteamItemInstanceID_t  itemConsume, uint32  unQuantity) __attribute__((thiscall));
  virtual bool  ExchangeItems(SteamInventoryResult_t * pResultHandle, SteamItemDef_t * pArrayGenerate, uint32 * punArrayGenerateQuantity, uint32  unArrayGenerateLength, SteamItemInstanceID_t * pArrayDestroy, uint32 * punArrayDestroyQuantity, uint32  unArrayDestroyLength) __attribute__((thiscall));
  virtual bool  TransferItemQuantity(SteamInventoryResult_t * pResultHandle, SteamItemInstanceID_t  itemIdSource, uint32  unQuantity, SteamItemInstanceID_t  itemIdDest) __attribute__((thiscall));
  virtual void  SendItemDropHeartbeat() __attribute__((thiscall));
  virtual bool  TriggerItemDrop(SteamInventoryResult_t * pResultHandle, SteamItemDef_t  dropListDefinition) __attribute__((thiscall));
  virtual bool  TradeItems(SteamInventoryResult_t * pResultHandle, CSteamID  steamIDTradePartner, SteamItemInstanceID_t * pArrayGive, uint32 * pArrayGiveQuantity, uint32  nArrayGiveLength, SteamItemInstanceID_t * pArrayGet, uint32 * pArrayGetQuantity, uint32  nArrayGetLength) __attribute__((thiscall));
  virtual bool  LoadItemDefinitions() __attribute__((thiscall));
  virtual bool  GetItemDefinitionIDs(SteamItemDef_t * pItemDefIDs, uint32 * punItemDefIDsArraySize) __attribute__((thiscall));
  virtual bool  GetItemDefinitionProperty(SteamItemDef_t  iDefinition, char * pchPropertyName, char * pchValueBuffer, uint32 * punValueBufferSizeOut) __attribute__((thiscall));
  virtual SteamAPICall_t  RequestEligiblePromoItemDefinitionsIDs(CSteamID  steamID) __attribute__((thiscall));
  virtual bool  GetEligiblePromoItemDefinitionIDs(CSteamID  steamID, SteamItemDef_t * pItemDefIDs, uint32 * punItemDefIDsArraySize) __attribute__((thiscall));
  ISteamInventory_(ISteamInventory*to_wrap);
  ~ISteamInventory_();
private:
  ISteamInventory * internal;
};
