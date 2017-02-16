#ifndef WRAP_ISTEAMINVENTORY_H
#define WRAP_ISTEAMINVENTORY_H
#include "steam_api.h"
class ISteamInventory_ 
{
  virtual EResult GetResultStatus( SteamInventoryResult_t resultHandle ) __attribute__((thiscall));
  virtual uint32 GetResultTimestamp( SteamInventoryResult_t resultHandle ) __attribute__((thiscall));
  virtual bool CheckResultSteamID( SteamInventoryResult_t resultHandle, CSteamID steamIDExpected ) __attribute__((thiscall));
  virtual void DestroyResult( SteamInventoryResult_t resultHandle ) __attribute__((thiscall));
  virtual bool GetAllItems( SteamInventoryResult_t *pResultHandle ) __attribute__((thiscall));
  virtual bool GetItemsByID( SteamInventoryResult_t *pResultHandle, ARRAY_COUNT( unCountInstanceIDs ) const SteamItemInstanceID_t *pInstanceIDs, uint32 unCountInstanceIDs ) __attribute__((thiscall));
  virtual bool SerializeResult( SteamInventoryResult_t resultHandle, OUT_BUFFER_COUNT(punOutBufferSize) void *pOutBuffer, uint32 *punOutBufferSize ) __attribute__((thiscall));
  virtual bool DeserializeResult( SteamInventoryResult_t *pOutResultHandle, BUFFER_COUNT(punOutBufferSize) const void *pBuffer, uint32 unBufferSize, bool bRESERVED_MUST_BE_FALSE = false ) __attribute__((thiscall));
  virtual bool GenerateItems( SteamInventoryResult_t *pResultHandle, ARRAY_COUNT(unArrayLength) const SteamItemDef_t *pArrayItemDefs, ARRAY_COUNT(unArrayLength) const uint32 *punArrayQuantity, uint32 unArrayLength ) __attribute__((thiscall));
  virtual bool GrantPromoItems( SteamInventoryResult_t *pResultHandle ) __attribute__((thiscall));
  virtual bool AddPromoItem( SteamInventoryResult_t *pResultHandle, SteamItemDef_t itemDef ) __attribute__((thiscall));
  virtual bool AddPromoItems( SteamInventoryResult_t *pResultHandle, ARRAY_COUNT(unArrayLength) const SteamItemDef_t *pArrayItemDefs, uint32 unArrayLength ) __attribute__((thiscall));
  virtual bool ConsumeItem( SteamInventoryResult_t *pResultHandle, SteamItemInstanceID_t itemConsume, uint32 unQuantity ) __attribute__((thiscall));
  virtual bool TransferItemQuantity( SteamInventoryResult_t *pResultHandle, SteamItemInstanceID_t itemIdSource, uint32 unQuantity, SteamItemInstanceID_t itemIdDest ) __attribute__((thiscall));
  virtual void SendItemDropHeartbeat() __attribute__((thiscall));
  virtual bool TriggerItemDrop( SteamInventoryResult_t *pResultHandle, SteamItemDef_t dropListDefinition ) __attribute__((thiscall));
  virtual bool LoadItemDefinitions() __attribute__((thiscall));
  virtual SteamAPICall_t RequestEligiblePromoItemDefinitionsIDs( CSteamID steamID ) __attribute__((thiscall));
  public:
    ISteamInventory *internal;
};
#endif
