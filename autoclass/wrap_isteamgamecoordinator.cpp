#include <steam_api_.h>

EGCResults  ISteamGameCoordinator_::SendMessage(uint32  unMsgType, void * pubData, uint32  cubData)
{
  TRACE("((ISteamGameCoordinator *)%p, (uint32 )%d, (void *)%p, (uint32 )%d)\n", this, unMsgType, pubData, cubData);
  auto result = this->internal->SendMessage(unMsgType, pubData, cubData);
  TRACE("() = (EGCResults )%p\n", result);

  return result;
}


bool  ISteamGameCoordinator_::IsMessageAvailable(uint32 * pcubMsgSize)
{
  TRACE("((ISteamGameCoordinator *)%p, (uint32 *)%d)\n", this, pcubMsgSize);
  auto result = this->internal->IsMessageAvailable(pcubMsgSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


EGCResults  ISteamGameCoordinator_::RetrieveMessage(uint32 * punMsgType, void * pubDest, uint32  cubDest, uint32 * pcubMsgSize)
{
  TRACE("((ISteamGameCoordinator *)%p, (uint32 *)%d, (void *)%p, (uint32 )%d, (uint32 *)%d)\n", this, punMsgType, pubDest, cubDest, pcubMsgSize);
  auto result = this->internal->RetrieveMessage(punMsgType, pubDest, cubDest, pcubMsgSize);
  TRACE("() = (EGCResults )%p\n", result);

  return result;
}
ISteamGameCoordinator_::ISteamGameCoordinator_(ISteamGameCoordinator * towrap)
{
  this->internal = towrap;
}

ISteamGameCoordinator_::~ISteamGameCoordinator_()
{
  delete this->internal;
}
