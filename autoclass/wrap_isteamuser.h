#include <steam_api_.h>
#include <isteamuser.h>
class ISteamUser_
{
public:
  virtual HSteamUser  GetHSteamUser() __attribute__((thiscall));
  virtual bool  BLoggedOn() __attribute__((thiscall));
  virtual CSteamID * GetSteamID(CSteamID * hidden) __attribute__((thiscall));
  virtual int  InitiateGameConnection(void * pAuthBlob, int  cbMaxAuthBlob, CSteamID  steamIDGameServer, uint32  unIPServer, uint16  usPortServer, bool  bSecure) __attribute__((thiscall));
  virtual void  TerminateGameConnection(uint32  unIPServer, uint16  usPortServer) __attribute__((thiscall));
  virtual void  TrackAppUsageEvent(CGameID  gameID, int  eAppUsageEvent, char * pchExtraInfo) __attribute__((thiscall));
  virtual bool  GetUserDataFolder(char * pchBuffer, int  cubBuffer) __attribute__((thiscall));
  virtual void  StartVoiceRecording() __attribute__((thiscall));
  virtual void  StopVoiceRecording() __attribute__((thiscall));
  virtual EVoiceResult  GetAvailableVoice(uint32 * pcbCompressed, uint32 * pcbUncompressed, uint32  nUncompressedVoiceDesiredSampleRate) __attribute__((thiscall));
  virtual EVoiceResult  GetVoice(bool  bWantCompressed, void * pDestBuffer, uint32  cbDestBufferSize, uint32 * nBytesWritten, bool  bWantUncompressed, void * pUncompressedDestBuffer, uint32  cbUncompressedDestBufferSize, uint32 * nUncompressBytesWritten, uint32  nUncompressedVoiceDesiredSampleRate) __attribute__((thiscall));
  virtual EVoiceResult  DecompressVoice(void * pCompressed, uint32  cbCompressed, void * pDestBuffer, uint32  cbDestBufferSize, uint32 * nBytesWritten, uint32  nDesiredSampleRate) __attribute__((thiscall));
  virtual uint32  GetVoiceOptimalSampleRate() __attribute__((thiscall));
  virtual HAuthTicket  GetAuthSessionTicket(void * pTicket, int  cbMaxTicket, uint32 * pcbTicket) __attribute__((thiscall));
  virtual EBeginAuthSessionResult  BeginAuthSession(void * pAuthTicket, int  cbAuthTicket, CSteamID  steamID) __attribute__((thiscall));
  virtual void  EndAuthSession(CSteamID  steamID) __attribute__((thiscall));
  virtual void  CancelAuthTicket(HAuthTicket  hAuthTicket) __attribute__((thiscall));
  virtual EUserHasLicenseForAppResult  UserHasLicenseForApp(CSteamID  steamID, AppId_t  appID) __attribute__((thiscall));
  virtual bool  BIsBehindNAT() __attribute__((thiscall));
  virtual void  AdvertiseGame(CSteamID  steamIDGameServer, uint32  unIPServer, uint16  usPortServer) __attribute__((thiscall));
  virtual SteamAPICall_t  RequestEncryptedAppTicket(void * pDataToInclude, int  cbDataToInclude) __attribute__((thiscall));
  virtual bool  GetEncryptedAppTicket(void * pTicket, int  cbMaxTicket, uint32 * pcbTicket) __attribute__((thiscall));
  virtual int  GetGameBadgeLevel(int  nSeries, bool  bFoil) __attribute__((thiscall));
  virtual int  GetPlayerSteamLevel() __attribute__((thiscall));
  virtual SteamAPICall_t  RequestStoreAuthURL(char * pchRedirectURL) __attribute__((thiscall));
  virtual bool  BIsPhoneVerified() __attribute__((thiscall));
  virtual bool  BIsTwoFactorEnabled() __attribute__((thiscall));
  virtual bool  BIsPhoneIdentifying() __attribute__((thiscall));
  virtual bool  BIsPhoneRequiringVerification() __attribute__((thiscall));
  ISteamUser_(ISteamUser*to_wrap);
  ~ISteamUser_();
private:
  ISteamUser * internal;
};
