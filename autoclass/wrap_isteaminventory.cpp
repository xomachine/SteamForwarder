#include <steam_api_.h>

EResult  ISteamInventory_::GetResultStatus(SteamInventoryResult_t  resultHandle)
{
  TRACE("((ISteamInventory *)%p, (SteamInventoryResult_t )%p)\n", this, resultHandle);
  auto result = this->internal->GetResultStatus(resultHandle);
  TRACE("() = (EResult )%p\n", result);

  return result;
}


bool  ISteamInventory_::GetResultItems(SteamInventoryResult_t  resultHandle, SteamItemDetails_t * pOutItemsArray, uint32 * punOutItemsArraySize)
{
  TRACE("((ISteamInventory *)%p, (SteamInventoryResult_t )%p, (SteamItemDetails_t *)%p, (uint32 *)%d)\n", this, resultHandle, pOutItemsArray, punOutItemsArraySize);
  auto result = this->internal->GetResultItems(resultHandle, pOutItemsArray, punOutItemsArraySize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


uint32  ISteamInventory_::GetResultTimestamp(SteamInventoryResult_t  resultHandle)
{
  TRACE("((ISteamInventory *)%p, (SteamInventoryResult_t )%p)\n", this, resultHandle);
  auto result = this->internal->GetResultTimestamp(resultHandle);
  TRACE("() = (uint32 )%d\n", result);

  return result;
}


bool  ISteamInventory_::CheckResultSteamID(SteamInventoryResult_t  resultHandle, CSteamID  steamIDExpected)
{
  TRACE("((ISteamInventory *)%p, (SteamInventoryResult_t )%p, (CSteamID )%p)\n", this, resultHandle, steamIDExpected);
  auto result = this->internal->CheckResultSteamID(resultHandle, steamIDExpected);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  ISteamInventory_::DestroyResult(SteamInventoryResult_t  resultHandle)
{
  TRACE("((ISteamInventory *)%p, (SteamInventoryResult_t )%p)\n", this, resultHandle);
  this->internal->DestroyResult(resultHandle);
  
}


bool  ISteamInventory_::GetAllItems(SteamInventoryResult_t * pResultHandle)
{
  TRACE("((ISteamInventory *)%p, (SteamInventoryResult_t *)%p)\n", this, pResultHandle);
  auto result = this->internal->GetAllItems(pResultHandle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamInventory_::GetItemsByID(SteamInventoryResult_t * pResultHandle, SteamItemInstanceID_t * pInstanceIDs, uint32  unCountInstanceIDs)
{
  TRACE("((ISteamInventory *)%p, (SteamInventoryResult_t *)%p, (SteamItemInstanceID_t *)%p, (uint32 )%d)\n", this, pResultHandle, pInstanceIDs, unCountInstanceIDs);
  auto result = this->internal->GetItemsByID(pResultHandle, pInstanceIDs, unCountInstanceIDs);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamInventory_::SerializeResult(SteamInventoryResult_t  resultHandle, void * pOutBuffer, uint32 * punOutBufferSize)
{
  TRACE("((ISteamInventory *)%p, (SteamInventoryResult_t )%p, (void *)%p, (uint32 *)%d)\n", this, resultHandle, pOutBuffer, punOutBufferSize);
  auto result = this->internal->SerializeResult(resultHandle, pOutBuffer, punOutBufferSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamInventory_::DeserializeResult(SteamInventoryResult_t * pOutResultHandle, void * pBuffer, uint32  unBufferSize, bool  bRESERVED_MUST_BE_FALSE)
{
  TRACE("((ISteamInventory *)%p, (SteamInventoryResult_t *)%p, (void *)%p, (uint32 )%d, (bool )%d)\n", this, pOutResultHandle, pBuffer, unBufferSize, bRESERVED_MUST_BE_FALSE);
  auto result = this->internal->DeserializeResult(pOutResultHandle, pBuffer, unBufferSize, bRESERVED_MUST_BE_FALSE);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamInventory_::GenerateItems(SteamInventoryResult_t * pResultHandle, SteamItemDef_t * pArrayItemDefs, uint32 * punArrayQuantity, uint32  unArrayLength)
{
  TRACE("((ISteamInventory *)%p, (SteamInventoryResult_t *)%p, (SteamItemDef_t *)%p, (uint32 *)%d, (uint32 )%d)\n", this, pResultHandle, pArrayItemDefs, punArrayQuantity, unArrayLength);
  auto result = this->internal->GenerateItems(pResultHandle, pArrayItemDefs, punArrayQuantity, unArrayLength);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamInventory_::GrantPromoItems(SteamInventoryResult_t * pResultHandle)
{
  TRACE("((ISteamInventory *)%p, (SteamInventoryResult_t *)%p)\n", this, pResultHandle);
  auto result = this->internal->GrantPromoItems(pResultHandle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamInventory_::AddPromoItem(SteamInventoryResult_t * pResultHandle, SteamItemDef_t  itemDef)
{
  TRACE("((ISteamInventory *)%p, (SteamInventoryResult_t *)%p, (SteamItemDef_t )%p)\n", this, pResultHandle, itemDef);
  auto result = this->internal->AddPromoItem(pResultHandle, itemDef);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamInventory_::AddPromoItems(SteamInventoryResult_t * pResultHandle, SteamItemDef_t * pArrayItemDefs, uint32  unArrayLength)
{
  TRACE("((ISteamInventory *)%p, (SteamInventoryResult_t *)%p, (SteamItemDef_t *)%p, (uint32 )%d)\n", this, pResultHandle, pArrayItemDefs, unArrayLength);
  auto result = this->internal->AddPromoItems(pResultHandle, pArrayItemDefs, unArrayLength);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamInventory_::ConsumeItem(SteamInventoryResult_t * pResultHandle, SteamItemInstanceID_t  itemConsume, uint32  unQuantity)
{
  TRACE("((ISteamInventory *)%p, (SteamInventoryResult_t *)%p, (SteamItemInstanceID_t )%p, (uint32 )%d)\n", this, pResultHandle, itemConsume, unQuantity);
  auto result = this->internal->ConsumeItem(pResultHandle, itemConsume, unQuantity);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamInventory_::ExchangeItems(SteamInventoryResult_t * pResultHandle, SteamItemDef_t * pArrayGenerate, uint32 * punArrayGenerateQuantity, uint32  unArrayGenerateLength, SteamItemInstanceID_t * pArrayDestroy, uint32 * punArrayDestroyQuantity, uint32  unArrayDestroyLength)
{
  TRACE("((ISteamInventory *)%p, (SteamInventoryResult_t *)%p, (SteamItemDef_t *)%p, (uint32 *)%d, (uint32 )%d, (SteamItemInstanceID_t *)%p, (uint32 *)%d, (uint32 )%d)\n", this, pResultHandle, pArrayGenerate, punArrayGenerateQuantity, unArrayGenerateLength, pArrayDestroy, punArrayDestroyQuantity, unArrayDestroyLength);
  auto result = this->internal->ExchangeItems(pResultHandle, pArrayGenerate, punArrayGenerateQuantity, unArrayGenerateLength, pArrayDestroy, punArrayDestroyQuantity, unArrayDestroyLength);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamInventory_::TransferItemQuantity(SteamInventoryResult_t * pResultHandle, SteamItemInstanceID_t  itemIdSource, uint32  unQuantity, SteamItemInstanceID_t  itemIdDest)
{
  TRACE("((ISteamInventory *)%p, (SteamInventoryResult_t *)%p, (SteamItemInstanceID_t )%p, (uint32 )%d, (SteamItemInstanceID_t )%p)\n", this, pResultHandle, itemIdSource, unQuantity, itemIdDest);
  auto result = this->internal->TransferItemQuantity(pResultHandle, itemIdSource, unQuantity, itemIdDest);
  TRACE("() = (bool )%d\n", result);

  return result;
}


void  ISteamInventory_::SendItemDropHeartbeat()
{
  TRACE("((ISteamInventory *)%p)\n", this);
  this->internal->SendItemDropHeartbeat();
  
}


bool  ISteamInventory_::TriggerItemDrop(SteamInventoryResult_t * pResultHandle, SteamItemDef_t  dropListDefinition)
{
  TRACE("((ISteamInventory *)%p, (SteamInventoryResult_t *)%p, (SteamItemDef_t )%p)\n", this, pResultHandle, dropListDefinition);
  auto result = this->internal->TriggerItemDrop(pResultHandle, dropListDefinition);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamInventory_::TradeItems(SteamInventoryResult_t * pResultHandle, CSteamID  steamIDTradePartner, SteamItemInstanceID_t * pArrayGive, uint32 * pArrayGiveQuantity, uint32  nArrayGiveLength, SteamItemInstanceID_t * pArrayGet, uint32 * pArrayGetQuantity, uint32  nArrayGetLength)
{
  TRACE("((ISteamInventory *)%p, (SteamInventoryResult_t *)%p, (CSteamID )%p, (SteamItemInstanceID_t *)%p, (uint32 *)%d, (uint32 )%d, (SteamItemInstanceID_t *)%p, (uint32 *)%d, (uint32 )%d)\n", this, pResultHandle, steamIDTradePartner, pArrayGive, pArrayGiveQuantity, nArrayGiveLength, pArrayGet, pArrayGetQuantity, nArrayGetLength);
  auto result = this->internal->TradeItems(pResultHandle, steamIDTradePartner, pArrayGive, pArrayGiveQuantity, nArrayGiveLength, pArrayGet, pArrayGetQuantity, nArrayGetLength);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamInventory_::LoadItemDefinitions()
{
  TRACE("((ISteamInventory *)%p)\n", this);
  auto result = this->internal->LoadItemDefinitions();
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamInventory_::GetItemDefinitionIDs(SteamItemDef_t * pItemDefIDs, uint32 * punItemDefIDsArraySize)
{
  TRACE("((ISteamInventory *)%p, (SteamItemDef_t *)%p, (uint32 *)%d)\n", this, pItemDefIDs, punItemDefIDsArraySize);
  auto result = this->internal->GetItemDefinitionIDs(pItemDefIDs, punItemDefIDsArraySize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamInventory_::GetItemDefinitionProperty(SteamItemDef_t  iDefinition, char * pchPropertyName, char * pchValueBuffer, uint32 * punValueBufferSizeOut)
{
  TRACE("((ISteamInventory *)%p, (SteamItemDef_t )%p, (char *)\"%s\", (char *)\"%s\", (uint32 *)%d)\n", this, iDefinition, pchPropertyName, pchValueBuffer, punValueBufferSizeOut);
  auto result = this->internal->GetItemDefinitionProperty(iDefinition, pchPropertyName, pchValueBuffer, punValueBufferSizeOut);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SteamAPICall_t  ISteamInventory_::RequestEligiblePromoItemDefinitionsIDs(CSteamID  steamID)
{
  TRACE("((ISteamInventory *)%p, (CSteamID )%p)\n", this, steamID);
  auto result = this->internal->RequestEligiblePromoItemDefinitionsIDs(steamID);
  TRACE("() = (SteamAPICall_t )%p\n", result);

  return result;
}


bool  ISteamInventory_::GetEligiblePromoItemDefinitionIDs(CSteamID  steamID, SteamItemDef_t * pItemDefIDs, uint32 * punItemDefIDsArraySize)
{
  TRACE("((ISteamInventory *)%p, (CSteamID )%p, (SteamItemDef_t *)%p, (uint32 *)%d)\n", this, steamID, pItemDefIDs, punItemDefIDsArraySize);
  auto result = this->internal->GetEligiblePromoItemDefinitionIDs(steamID, pItemDefIDs, punItemDefIDsArraySize);
  TRACE("() = (bool )%d\n", result);

  return result;
}
ISteamInventory_::ISteamInventory_(ISteamInventory * towrap)
{
  this->internal = towrap;
}

ISteamInventory_::~ISteamInventory_()
{
  delete this->internal;
}
