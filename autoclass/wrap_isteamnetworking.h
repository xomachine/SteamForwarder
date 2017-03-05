#include <steam_api_.h>
#include <isteamnetworking.h>
class ISteamNetworking_
{
public:
  virtual bool  SendP2PPacket(CSteamID  steamIDRemote, void * pubData, uint32  cubData, EP2PSend  eP2PSendType, int  nChannel) __attribute__((thiscall));
  virtual bool  IsP2PPacketAvailable(uint32 * pcubMsgSize, int  nChannel) __attribute__((thiscall));
  virtual bool  ReadP2PPacket(void * pubDest, uint32  cubDest, uint32 * pcubMsgSize, CSteamID * psteamIDRemote, int  nChannel) __attribute__((thiscall));
  virtual bool  AcceptP2PSessionWithUser(CSteamID  steamIDRemote) __attribute__((thiscall));
  virtual bool  CloseP2PSessionWithUser(CSteamID  steamIDRemote) __attribute__((thiscall));
  virtual bool  CloseP2PChannelWithUser(CSteamID  steamIDRemote, int  nChannel) __attribute__((thiscall));
  virtual bool  GetP2PSessionState(CSteamID  steamIDRemote, P2PSessionState_t * pConnectionState) __attribute__((thiscall));
  virtual bool  AllowP2PPacketRelay(bool  bAllow) __attribute__((thiscall));
  virtual SNetListenSocket_t  CreateListenSocket(int  nVirtualP2PPort, uint32  nIP, uint16  nPort, bool  bAllowUseOfPacketRelay) __attribute__((thiscall));
  virtual SNetSocket_t  CreateP2PConnectionSocket(CSteamID  steamIDTarget, int  nVirtualPort, int  nTimeoutSec, bool  bAllowUseOfPacketRelay) __attribute__((thiscall));
  virtual SNetSocket_t  CreateConnectionSocket(uint32  nIP, uint16  nPort, int  nTimeoutSec) __attribute__((thiscall));
  virtual bool  DestroySocket(SNetSocket_t  hSocket, bool  bNotifyRemoteEnd) __attribute__((thiscall));
  virtual bool  DestroyListenSocket(SNetListenSocket_t  hSocket, bool  bNotifyRemoteEnd) __attribute__((thiscall));
  virtual bool  SendDataOnSocket(SNetSocket_t  hSocket, void * pubData, uint32  cubData, bool  bReliable) __attribute__((thiscall));
  virtual bool  IsDataAvailableOnSocket(SNetSocket_t  hSocket, uint32 * pcubMsgSize) __attribute__((thiscall));
  virtual bool  RetrieveDataFromSocket(SNetSocket_t  hSocket, void * pubDest, uint32  cubDest, uint32 * pcubMsgSize) __attribute__((thiscall));
  virtual bool  IsDataAvailable(SNetListenSocket_t  hListenSocket, uint32 * pcubMsgSize, SNetSocket_t * phSocket) __attribute__((thiscall));
  virtual bool  RetrieveData(SNetListenSocket_t  hListenSocket, void * pubDest, uint32  cubDest, uint32 * pcubMsgSize, SNetSocket_t * phSocket) __attribute__((thiscall));
  virtual bool  GetSocketInfo(SNetSocket_t  hSocket, CSteamID * pSteamIDRemote, int * peSocketStatus, uint32 * punIPRemote, uint16 * punPortRemote) __attribute__((thiscall));
  virtual bool  GetListenSocketInfo(SNetListenSocket_t  hListenSocket, uint32 * pnIP, uint16 * pnPort) __attribute__((thiscall));
  virtual ESNetSocketConnectionType  GetSocketConnectionType(SNetSocket_t  hSocket) __attribute__((thiscall));
  virtual int  GetMaxPacketSize(SNetSocket_t  hSocket) __attribute__((thiscall));
  ISteamNetworking_(ISteamNetworking*to_wrap);
  ~ISteamNetworking_();
private:
  ISteamNetworking * internal;
};
