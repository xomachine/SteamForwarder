#include <steam_api_.h>
#include <isteamgamecoordinator.h>
class ISteamGameCoordinator_
{
public:
  virtual EGCResults  SendMessage(uint32  unMsgType, void * pubData, uint32  cubData) __attribute__((thiscall));
  virtual bool  IsMessageAvailable(uint32 * pcubMsgSize) __attribute__((thiscall));
  virtual EGCResults  RetrieveMessage(uint32 * punMsgType, void * pubDest, uint32  cubDest, uint32 * pcubMsgSize) __attribute__((thiscall));
  ISteamGameCoordinator_(ISteamGameCoordinator*to_wrap);
  ~ISteamGameCoordinator_();
private:
  ISteamGameCoordinator * internal;
};
