#include <steam_api_.h>

uint32  ISteamAppTicket_::GetAppOwnershipTicketData(uint32  nAppID, void * pvBuffer, uint32  cbBufferLength, uint32 * piAppId, uint32 * piSteamId, uint32 * piSignature, uint32 * pcbSignature)
{
  TRACE("((ISteamAppTicket *)%p, (uint32 )%p, (void *)%p, (uint32 )%p, (uint32 *)%p, (uint32 *)%p, (uint32 *)%p, (uint32 *)%p)\n", this, nAppID, pvBuffer, cbBufferLength, piAppId, piSteamId, piSignature, pcbSignature);
  auto result = this->internal->GetAppOwnershipTicketData(nAppID, pvBuffer, cbBufferLength, piAppId, piSteamId, piSignature, pcbSignature);
  TRACE("() = (uint32 )%p\n", result);

  return result;
}
ISteamAppTicket_::ISteamAppTicket_(ISteamAppTicket * towrap)
{
  this->internal = towrap;
}

ISteamAppTicket_::~ISteamAppTicket_()
{
  delete this->internal;
}
