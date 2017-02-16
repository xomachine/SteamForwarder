#ifndef WRAP_ISTEAMHTTP_H
#define WRAP_ISTEAMHTTP_H
#include "steam_api.h"
class ISteamHTTP_ 
{
  virtual HTTPRequestHandle CreateHTTPRequest( EHTTPMethod eHTTPRequestMethod, const char *pchAbsoluteURL ) __attribute__((thiscall));
  virtual bool SetHTTPRequestContextValue( HTTPRequestHandle hRequest, uint64 ulContextValue ) __attribute__((thiscall));
  virtual bool SetHTTPRequestNetworkActivityTimeout( HTTPRequestHandle hRequest, uint32 unTimeoutSeconds ) __attribute__((thiscall));
  virtual bool SetHTTPRequestHeaderValue( HTTPRequestHandle hRequest, const char *pchHeaderName, const char *pchHeaderValue ) __attribute__((thiscall));
  virtual bool SetHTTPRequestGetOrPostParameter( HTTPRequestHandle hRequest, const char *pchParamName, const char *pchParamValue ) __attribute__((thiscall));
  virtual bool SendHTTPRequest( HTTPRequestHandle hRequest, SteamAPICall_t *pCallHandle ) __attribute__((thiscall));
  virtual bool SendHTTPRequestAndStreamResponse( HTTPRequestHandle hRequest, SteamAPICall_t *pCallHandle ) __attribute__((thiscall));
  virtual bool DeferHTTPRequest( HTTPRequestHandle hRequest ) __attribute__((thiscall));
  virtual bool PrioritizeHTTPRequest( HTTPRequestHandle hRequest ) __attribute__((thiscall));
  virtual bool GetHTTPResponseHeaderSize( HTTPRequestHandle hRequest, const char *pchHeaderName, uint32 *unResponseHeaderSize ) __attribute__((thiscall));
  virtual bool GetHTTPResponseHeaderValue( HTTPRequestHandle hRequest, const char *pchHeaderName, uint8 *pHeaderValueBuffer, uint32 unBufferSize ) __attribute__((thiscall));
  virtual bool GetHTTPResponseBodySize( HTTPRequestHandle hRequest, uint32 *unBodySize ) __attribute__((thiscall));
  virtual bool GetHTTPResponseBodyData( HTTPRequestHandle hRequest, uint8 *pBodyDataBuffer, uint32 unBufferSize ) __attribute__((thiscall));
  virtual bool GetHTTPStreamingResponseBodyData( HTTPRequestHandle hRequest, uint32 cOffset, uint8 *pBodyDataBuffer, uint32 unBufferSize ) __attribute__((thiscall));
  virtual bool ReleaseHTTPRequest( HTTPRequestHandle hRequest ) __attribute__((thiscall));
  virtual bool GetHTTPDownloadProgressPct( HTTPRequestHandle hRequest, float *pflPercentOut ) __attribute__((thiscall));
  virtual bool SetHTTPRequestRawPostBody( HTTPRequestHandle hRequest, const char *pchContentType, uint8 *pubBody, uint32 unBodyLen ) __attribute__((thiscall));
  virtual HTTPCookieContainerHandle CreateCookieContainer( bool bAllowResponsesToModify ) __attribute__((thiscall));
  virtual bool ReleaseCookieContainer( HTTPCookieContainerHandle hCookieContainer ) __attribute__((thiscall));
  virtual bool SetCookie( HTTPCookieContainerHandle hCookieContainer, const char *pchHost, const char *pchUrl, const char *pchCookie ) __attribute__((thiscall));
  virtual bool SetHTTPRequestCookieContainer( HTTPRequestHandle hRequest, HTTPCookieContainerHandle hCookieContainer ) __attribute__((thiscall));
  virtual bool SetHTTPRequestUserAgentInfo( HTTPRequestHandle hRequest, const char *pchUserAgentInfo ) __attribute__((thiscall));
  virtual bool SetHTTPRequestRequiresVerifiedCertificate( HTTPRequestHandle hRequest, bool bRequireVerifiedCertificate ) __attribute__((thiscall));
  virtual bool SetHTTPRequestAbsoluteTimeoutMS( HTTPRequestHandle hRequest, uint32 unMilliseconds ) __attribute__((thiscall));
  virtual bool GetHTTPRequestWasTimedOut( HTTPRequestHandle hRequest, bool *pbWasTimedOut ) __attribute__((thiscall));
  public:
    ISteamHTTP *internal;
};
#endif
