#include <steam_api_.h>

bool  ISteamNetworking_::SendP2PPacket(CSteamID  steamIDRemote, void * pubData, uint32  cubData, EP2PSend  eP2PSendType, int  nChannel)
{
  TRACE("((ISteamNetworking *)%p, (CSteamID )%p, (void *)%p, (uint32 )%p, (EP2PSend )%p, (int )%d)\n", this, steamIDRemote, pubData, cubData, eP2PSendType, nChannel);
  auto result = this->internal->SendP2PPacket(steamIDRemote, pubData, cubData, eP2PSendType, nChannel);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamNetworking_::IsP2PPacketAvailable(uint32 * pcubMsgSize, int  nChannel)
{
  TRACE("((ISteamNetworking *)%p, (uint32 *)%p, (int )%d)\n", this, pcubMsgSize, nChannel);
  auto result = this->internal->IsP2PPacketAvailable(pcubMsgSize, nChannel);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamNetworking_::ReadP2PPacket(void * pubDest, uint32  cubDest, uint32 * pcubMsgSize, CSteamID * psteamIDRemote, int  nChannel)
{
  TRACE("((ISteamNetworking *)%p, (void *)%p, (uint32 )%p, (uint32 *)%p, (CSteamID *)%p, (int )%d)\n", this, pubDest, cubDest, pcubMsgSize, psteamIDRemote, nChannel);
  auto result = this->internal->ReadP2PPacket(pubDest, cubDest, pcubMsgSize, psteamIDRemote, nChannel);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamNetworking_::AcceptP2PSessionWithUser(CSteamID  steamIDRemote)
{
  TRACE("((ISteamNetworking *)%p, (CSteamID )%p)\n", this, steamIDRemote);
  auto result = this->internal->AcceptP2PSessionWithUser(steamIDRemote);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamNetworking_::CloseP2PSessionWithUser(CSteamID  steamIDRemote)
{
  TRACE("((ISteamNetworking *)%p, (CSteamID )%p)\n", this, steamIDRemote);
  auto result = this->internal->CloseP2PSessionWithUser(steamIDRemote);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamNetworking_::CloseP2PChannelWithUser(CSteamID  steamIDRemote, int  nChannel)
{
  TRACE("((ISteamNetworking *)%p, (CSteamID )%p, (int )%d)\n", this, steamIDRemote, nChannel);
  auto result = this->internal->CloseP2PChannelWithUser(steamIDRemote, nChannel);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamNetworking_::GetP2PSessionState(CSteamID  steamIDRemote, P2PSessionState_t * pConnectionState)
{
  TRACE("((ISteamNetworking *)%p, (CSteamID )%p, (P2PSessionState_t *)%p)\n", this, steamIDRemote, pConnectionState);
  auto result = this->internal->GetP2PSessionState(steamIDRemote, pConnectionState);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamNetworking_::AllowP2PPacketRelay(bool  bAllow)
{
  TRACE("((ISteamNetworking *)%p, (bool )%d)\n", this, bAllow);
  auto result = this->internal->AllowP2PPacketRelay(bAllow);
  TRACE("() = (bool )%d\n", result);

  return result;
}


SNetListenSocket_t  ISteamNetworking_::CreateListenSocket(int  nVirtualP2PPort, uint32  nIP, uint16  nPort, bool  bAllowUseOfPacketRelay)
{
  TRACE("((ISteamNetworking *)%p, (int )%d, (uint32 )%p, (uint16 )%p, (bool )%d)\n", this, nVirtualP2PPort, nIP, nPort, bAllowUseOfPacketRelay);
  auto result = this->internal->CreateListenSocket(nVirtualP2PPort, nIP, nPort, bAllowUseOfPacketRelay);
  TRACE("() = (SNetListenSocket_t )%p\n", result);

  return result;
}


SNetSocket_t  ISteamNetworking_::CreateP2PConnectionSocket(CSteamID  steamIDTarget, int  nVirtualPort, int  nTimeoutSec, bool  bAllowUseOfPacketRelay)
{
  TRACE("((ISteamNetworking *)%p, (CSteamID )%p, (int )%d, (int )%d, (bool )%d)\n", this, steamIDTarget, nVirtualPort, nTimeoutSec, bAllowUseOfPacketRelay);
  auto result = this->internal->CreateP2PConnectionSocket(steamIDTarget, nVirtualPort, nTimeoutSec, bAllowUseOfPacketRelay);
  TRACE("() = (SNetSocket_t )%p\n", result);

  return result;
}


SNetSocket_t  ISteamNetworking_::CreateConnectionSocket(uint32  nIP, uint16  nPort, int  nTimeoutSec)
{
  TRACE("((ISteamNetworking *)%p, (uint32 )%p, (uint16 )%p, (int )%d)\n", this, nIP, nPort, nTimeoutSec);
  auto result = this->internal->CreateConnectionSocket(nIP, nPort, nTimeoutSec);
  TRACE("() = (SNetSocket_t )%p\n", result);

  return result;
}


bool  ISteamNetworking_::DestroySocket(SNetSocket_t  hSocket, bool  bNotifyRemoteEnd)
{
  TRACE("((ISteamNetworking *)%p, (SNetSocket_t )%p, (bool )%d)\n", this, hSocket, bNotifyRemoteEnd);
  auto result = this->internal->DestroySocket(hSocket, bNotifyRemoteEnd);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamNetworking_::DestroyListenSocket(SNetListenSocket_t  hSocket, bool  bNotifyRemoteEnd)
{
  TRACE("((ISteamNetworking *)%p, (SNetListenSocket_t )%p, (bool )%d)\n", this, hSocket, bNotifyRemoteEnd);
  auto result = this->internal->DestroyListenSocket(hSocket, bNotifyRemoteEnd);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamNetworking_::SendDataOnSocket(SNetSocket_t  hSocket, void * pubData, uint32  cubData, bool  bReliable)
{
  TRACE("((ISteamNetworking *)%p, (SNetSocket_t )%p, (void *)%p, (uint32 )%p, (bool )%d)\n", this, hSocket, pubData, cubData, bReliable);
  auto result = this->internal->SendDataOnSocket(hSocket, pubData, cubData, bReliable);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamNetworking_::IsDataAvailableOnSocket(SNetSocket_t  hSocket, uint32 * pcubMsgSize)
{
  TRACE("((ISteamNetworking *)%p, (SNetSocket_t )%p, (uint32 *)%p)\n", this, hSocket, pcubMsgSize);
  auto result = this->internal->IsDataAvailableOnSocket(hSocket, pcubMsgSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamNetworking_::RetrieveDataFromSocket(SNetSocket_t  hSocket, void * pubDest, uint32  cubDest, uint32 * pcubMsgSize)
{
  TRACE("((ISteamNetworking *)%p, (SNetSocket_t )%p, (void *)%p, (uint32 )%p, (uint32 *)%p)\n", this, hSocket, pubDest, cubDest, pcubMsgSize);
  auto result = this->internal->RetrieveDataFromSocket(hSocket, pubDest, cubDest, pcubMsgSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamNetworking_::IsDataAvailable(SNetListenSocket_t  hListenSocket, uint32 * pcubMsgSize, SNetSocket_t * phSocket)
{
  TRACE("((ISteamNetworking *)%p, (SNetListenSocket_t )%p, (uint32 *)%p, (SNetSocket_t *)%p)\n", this, hListenSocket, pcubMsgSize, phSocket);
  auto result = this->internal->IsDataAvailable(hListenSocket, pcubMsgSize, phSocket);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamNetworking_::RetrieveData(SNetListenSocket_t  hListenSocket, void * pubDest, uint32  cubDest, uint32 * pcubMsgSize, SNetSocket_t * phSocket)
{
  TRACE("((ISteamNetworking *)%p, (SNetListenSocket_t )%p, (void *)%p, (uint32 )%p, (uint32 *)%p, (SNetSocket_t *)%p)\n", this, hListenSocket, pubDest, cubDest, pcubMsgSize, phSocket);
  auto result = this->internal->RetrieveData(hListenSocket, pubDest, cubDest, pcubMsgSize, phSocket);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamNetworking_::GetSocketInfo(SNetSocket_t  hSocket, CSteamID * pSteamIDRemote, int * peSocketStatus, uint32 * punIPRemote, uint16 * punPortRemote)
{
  TRACE("((ISteamNetworking *)%p, (SNetSocket_t )%p, (CSteamID *)%p, (int *)%d, (uint32 *)%p, (uint16 *)%p)\n", this, hSocket, pSteamIDRemote, peSocketStatus, punIPRemote, punPortRemote);
  auto result = this->internal->GetSocketInfo(hSocket, pSteamIDRemote, peSocketStatus, punIPRemote, punPortRemote);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamNetworking_::GetListenSocketInfo(SNetListenSocket_t  hListenSocket, uint32 * pnIP, uint16 * pnPort)
{
  TRACE("((ISteamNetworking *)%p, (SNetListenSocket_t )%p, (uint32 *)%p, (uint16 *)%p)\n", this, hListenSocket, pnIP, pnPort);
  auto result = this->internal->GetListenSocketInfo(hListenSocket, pnIP, pnPort);
  TRACE("() = (bool )%d\n", result);

  return result;
}


ESNetSocketConnectionType  ISteamNetworking_::GetSocketConnectionType(SNetSocket_t  hSocket)
{
  TRACE("((ISteamNetworking *)%p, (SNetSocket_t )%p)\n", this, hSocket);
  auto result = this->internal->GetSocketConnectionType(hSocket);
  TRACE("() = (ESNetSocketConnectionType )%p\n", result);

  return result;
}


int  ISteamNetworking_::GetMaxPacketSize(SNetSocket_t  hSocket)
{
  TRACE("((ISteamNetworking *)%p, (SNetSocket_t )%p)\n", this, hSocket);
  auto result = this->internal->GetMaxPacketSize(hSocket);
  TRACE("() = (int )%d\n", result);

  return result;
}
ISteamNetworking_::ISteamNetworking_(ISteamNetworking * towrap)
{
  this->internal = towrap;
}

ISteamNetworking_::~ISteamNetworking_()
{
  delete this->internal;
}
