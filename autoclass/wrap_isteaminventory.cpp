#ifndef WRAP_ISTEAMINVENTORY_CPP
#define WRAP_ISTEAMINVENTORY_CPP
#include "autoclass/steam_api_.h" 
#include "windef.h"
#include "wine/debug.h"
#include "config.h"
EResult ISteamInventory_::GetResultStatus( SteamInventoryResult_t resultHandle )
{
  TRACE("((this[ISteamInventory])%p, (SteamInventoryResult_t)%p)\n", this, resultHandle);
  EResult result = this->internal->GetResultStatus(resultHandle);
  TRACE(" = (EResult)%p\n", result);
  return result;
}
uint32 ISteamInventory_::GetResultTimestamp( SteamInventoryResult_t resultHandle )
{
  TRACE("((this[ISteamInventory])%p, (SteamInventoryResult_t)%p)\n", this, resultHandle);
  uint32 result = this->internal->GetResultTimestamp(resultHandle);
  TRACE(" = (uint32)%d\n", result);
  return result;
}
bool ISteamInventory_::CheckResultSteamID( SteamInventoryResult_t resultHandle, CSteamID steamIDExpected )
{
  TRACE("((this[ISteamInventory])%p, (SteamInventoryResult_t)%p, (CSteamID)%p)\n", this, resultHandle, steamIDExpected);
  bool result = this->internal->CheckResultSteamID(resultHandle, steamIDExpected);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void ISteamInventory_::DestroyResult( SteamInventoryResult_t resultHandle )
{
  TRACE("((this[ISteamInventory])%p, (SteamInventoryResult_t)%p)\n", this, resultHandle);
  this->internal->DestroyResult(resultHandle);
}
bool ISteamInventory_::GetAllItems( SteamInventoryResult_t *pResultHandle )
{
  TRACE("((this[ISteamInventory])%p, (SteamInventoryResult_t *)%p)\n", this, pResultHandle);
  bool result = this->internal->GetAllItems(pResultHandle);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamInventory_::GetItemsByID( SteamInventoryResult_t *pResultHandle, ARRAY_COUNT( unCountInstanceIDs ) const SteamItemInstanceID_t *pInstanceIDs, uint32 unCountInstanceIDs )
{
  TRACE("((this[ISteamInventory])%p, (SteamInventoryResult_t *)%p, (const SteamItemInstanceID_t *)%p, (uint32)%d)\n", this, pResultHandle, pInstanceIDs, unCountInstanceIDs);
  bool result = this->internal->GetItemsByID(pResultHandle, pInstanceIDs, unCountInstanceIDs);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamInventory_::SerializeResult( SteamInventoryResult_t resultHandle, OUT_BUFFER_COUNT(punOutBufferSize) void *pOutBuffer, uint32 *punOutBufferSize )
{
  TRACE("((this[ISteamInventory])%p, (SteamInventoryResult_t)%p, (void *)%p, (uint32 *)%p)\n", this, resultHandle, pOutBuffer, punOutBufferSize);
  bool result = this->internal->SerializeResult(resultHandle, pOutBuffer, punOutBufferSize);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamInventory_::DeserializeResult( SteamInventoryResult_t *pOutResultHandle, BUFFER_COUNT(punOutBufferSize) const void *pBuffer, uint32 unBufferSize, bool bRESERVED_MUST_BE_FALSE = false )
{
  TRACE("((this[ISteamInventory])%p, (SteamInventoryResult_t *)%p, (const void *)%p, (uint32)%d, (bool)%d)\n", this, pOutResultHandle, pBuffer, unBufferSize, bRESERVED_MUST_BE_FALSE);
  bool result = this->internal->DeserializeResult(pOutResultHandle, pBuffer, unBufferSize, bRESERVED_MUST_BE_FALSE);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamInventory_::GenerateItems( SteamInventoryResult_t *pResultHandle, ARRAY_COUNT(unArrayLength) const SteamItemDef_t *pArrayItemDefs, ARRAY_COUNT(unArrayLength) const uint32 *punArrayQuantity, uint32 unArrayLength )
{
  TRACE("((this[ISteamInventory])%p, (SteamInventoryResult_t *)%p, (const SteamItemDef_t *)%p, (const uint32 *)%p, (uint32)%d)\n", this, pResultHandle, pArrayItemDefs, punArrayQuantity, unArrayLength);
  bool result = this->internal->GenerateItems(pResultHandle, pArrayItemDefs, punArrayQuantity, unArrayLength);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamInventory_::GrantPromoItems( SteamInventoryResult_t *pResultHandle )
{
  TRACE("((this[ISteamInventory])%p, (SteamInventoryResult_t *)%p)\n", this, pResultHandle);
  bool result = this->internal->GrantPromoItems(pResultHandle);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamInventory_::AddPromoItem( SteamInventoryResult_t *pResultHandle, SteamItemDef_t itemDef )
{
  TRACE("((this[ISteamInventory])%p, (SteamInventoryResult_t *)%p, (SteamItemDef_t)%p)\n", this, pResultHandle, itemDef);
  bool result = this->internal->AddPromoItem(pResultHandle, itemDef);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamInventory_::AddPromoItems( SteamInventoryResult_t *pResultHandle, ARRAY_COUNT(unArrayLength) const SteamItemDef_t *pArrayItemDefs, uint32 unArrayLength )
{
  TRACE("((this[ISteamInventory])%p, (SteamInventoryResult_t *)%p, (const SteamItemDef_t *)%p, (uint32)%d)\n", this, pResultHandle, pArrayItemDefs, unArrayLength);
  bool result = this->internal->AddPromoItems(pResultHandle, pArrayItemDefs, unArrayLength);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamInventory_::ConsumeItem( SteamInventoryResult_t *pResultHandle, SteamItemInstanceID_t itemConsume, uint32 unQuantity )
{
  TRACE("((this[ISteamInventory])%p, (SteamInventoryResult_t *)%p, (SteamItemInstanceID_t)%p, (uint32)%d)\n", this, pResultHandle, itemConsume, unQuantity);
  bool result = this->internal->ConsumeItem(pResultHandle, itemConsume, unQuantity);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamInventory_::TransferItemQuantity( SteamInventoryResult_t *pResultHandle, SteamItemInstanceID_t itemIdSource, uint32 unQuantity, SteamItemInstanceID_t itemIdDest )
{
  TRACE("((this[ISteamInventory])%p, (SteamInventoryResult_t *)%p, (SteamItemInstanceID_t)%p, (uint32)%d, (SteamItemInstanceID_t)%p)\n", this, pResultHandle, itemIdSource, unQuantity, itemIdDest);
  bool result = this->internal->TransferItemQuantity(pResultHandle, itemIdSource, unQuantity, itemIdDest);
  TRACE(" = (bool)%d\n", result);
  return result;
}
void ISteamInventory_::SendItemDropHeartbeat()
{
  TRACE("((this[ISteamInventory])%p)\n", this);
  this->internal->SendItemDropHeartbeat();
}
bool ISteamInventory_::TriggerItemDrop( SteamInventoryResult_t *pResultHandle, SteamItemDef_t dropListDefinition )
{
  TRACE("((this[ISteamInventory])%p, (SteamInventoryResult_t *)%p, (SteamItemDef_t)%p)\n", this, pResultHandle, dropListDefinition);
  bool result = this->internal->TriggerItemDrop(pResultHandle, dropListDefinition);
  TRACE(" = (bool)%d\n", result);
  return result;
}
bool ISteamInventory_::LoadItemDefinitions()
{
  TRACE("((this[ISteamInventory])%p)\n", this);
  bool result = this->internal->LoadItemDefinitions();
  TRACE(" = (bool)%d\n", result);
  return result;
}
SteamAPICall_t ISteamInventory_::RequestEligiblePromoItemDefinitionsIDs( CSteamID steamID )
{
  TRACE("((this[ISteamInventory])%p, (CSteamID)%p)\n", this, steamID);
  SteamAPICall_t result = this->internal->RequestEligiblePromoItemDefinitionsIDs(steamID);
  TRACE(" = (SteamAPICall_t)%p\n", result);
  return result;
}
#endif
