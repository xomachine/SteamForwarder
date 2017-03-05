#include <steam_api_.h>
#include <isteamappticket.h>
class ISteamAppTicket_
{
public:
  virtual uint32  GetAppOwnershipTicketData(uint32  nAppID, void * pvBuffer, uint32  cbBufferLength, uint32 * piAppId, uint32 * piSteamId, uint32 * piSignature, uint32 * pcbSignature) __attribute__((thiscall));
  ISteamAppTicket_(ISteamAppTicket*to_wrap);
  ~ISteamAppTicket_();
private:
  ISteamAppTicket * internal;
};
