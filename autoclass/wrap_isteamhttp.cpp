#include <steam_api_.h>

HTTPRequestHandle  ISteamHTTP_::CreateHTTPRequest(EHTTPMethod  eHTTPRequestMethod, char * pchAbsoluteURL)
{
  TRACE("((ISteamHTTP *)%p, (EHTTPMethod )%p, (char *)\"%s\")\n", this, eHTTPRequestMethod, pchAbsoluteURL);
  auto result = this->internal->CreateHTTPRequest(eHTTPRequestMethod, pchAbsoluteURL);
  TRACE("() = (HTTPRequestHandle )%p\n", result);

  return result;
}


bool  ISteamHTTP_::SetHTTPRequestContextValue(HTTPRequestHandle  hRequest, uint64  ulContextValue)
{
  TRACE("((ISteamHTTP *)%p, (HTTPRequestHandle )%p, (uint64 )%p)\n", this, hRequest, ulContextValue);
  auto result = this->internal->SetHTTPRequestContextValue(hRequest, ulContextValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamHTTP_::SetHTTPRequestNetworkActivityTimeout(HTTPRequestHandle  hRequest, uint32  unTimeoutSeconds)
{
  TRACE("((ISteamHTTP *)%p, (HTTPRequestHandle )%p, (uint32 )%p)\n", this, hRequest, unTimeoutSeconds);
  auto result = this->internal->SetHTTPRequestNetworkActivityTimeout(hRequest, unTimeoutSeconds);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamHTTP_::SetHTTPRequestHeaderValue(HTTPRequestHandle  hRequest, char * pchHeaderName, char * pchHeaderValue)
{
  TRACE("((ISteamHTTP *)%p, (HTTPRequestHandle )%p, (char *)\"%s\", (char *)\"%s\")\n", this, hRequest, pchHeaderName, pchHeaderValue);
  auto result = this->internal->SetHTTPRequestHeaderValue(hRequest, pchHeaderName, pchHeaderValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamHTTP_::SetHTTPRequestGetOrPostParameter(HTTPRequestHandle  hRequest, char * pchParamName, char * pchParamValue)
{
  TRACE("((ISteamHTTP *)%p, (HTTPRequestHandle )%p, (char *)\"%s\", (char *)\"%s\")\n", this, hRequest, pchParamName, pchParamValue);
  auto result = this->internal->SetHTTPRequestGetOrPostParameter(hRequest, pchParamName, pchParamValue);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamHTTP_::SendHTTPRequest(HTTPRequestHandle  hRequest, SteamAPICall_t * pCallHandle)
{
  TRACE("((ISteamHTTP *)%p, (HTTPRequestHandle )%p, (SteamAPICall_t *)%p)\n", this, hRequest, pCallHandle);
  auto result = this->internal->SendHTTPRequest(hRequest, pCallHandle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamHTTP_::SendHTTPRequestAndStreamResponse(HTTPRequestHandle  hRequest, SteamAPICall_t * pCallHandle)
{
  TRACE("((ISteamHTTP *)%p, (HTTPRequestHandle )%p, (SteamAPICall_t *)%p)\n", this, hRequest, pCallHandle);
  auto result = this->internal->SendHTTPRequestAndStreamResponse(hRequest, pCallHandle);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamHTTP_::DeferHTTPRequest(HTTPRequestHandle  hRequest)
{
  TRACE("((ISteamHTTP *)%p, (HTTPRequestHandle )%p)\n", this, hRequest);
  auto result = this->internal->DeferHTTPRequest(hRequest);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamHTTP_::PrioritizeHTTPRequest(HTTPRequestHandle  hRequest)
{
  TRACE("((ISteamHTTP *)%p, (HTTPRequestHandle )%p)\n", this, hRequest);
  auto result = this->internal->PrioritizeHTTPRequest(hRequest);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamHTTP_::GetHTTPResponseHeaderSize(HTTPRequestHandle  hRequest, char * pchHeaderName, uint32 * unResponseHeaderSize)
{
  TRACE("((ISteamHTTP *)%p, (HTTPRequestHandle )%p, (char *)\"%s\", (uint32 *)%p)\n", this, hRequest, pchHeaderName, unResponseHeaderSize);
  auto result = this->internal->GetHTTPResponseHeaderSize(hRequest, pchHeaderName, unResponseHeaderSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamHTTP_::GetHTTPResponseHeaderValue(HTTPRequestHandle  hRequest, char * pchHeaderName, uint8 * pHeaderValueBuffer, uint32  unBufferSize)
{
  TRACE("((ISteamHTTP *)%p, (HTTPRequestHandle )%p, (char *)\"%s\", (uint8 *)%p, (uint32 )%p)\n", this, hRequest, pchHeaderName, pHeaderValueBuffer, unBufferSize);
  auto result = this->internal->GetHTTPResponseHeaderValue(hRequest, pchHeaderName, pHeaderValueBuffer, unBufferSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamHTTP_::GetHTTPResponseBodySize(HTTPRequestHandle  hRequest, uint32 * unBodySize)
{
  TRACE("((ISteamHTTP *)%p, (HTTPRequestHandle )%p, (uint32 *)%p)\n", this, hRequest, unBodySize);
  auto result = this->internal->GetHTTPResponseBodySize(hRequest, unBodySize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamHTTP_::GetHTTPResponseBodyData(HTTPRequestHandle  hRequest, uint8 * pBodyDataBuffer, uint32  unBufferSize)
{
  TRACE("((ISteamHTTP *)%p, (HTTPRequestHandle )%p, (uint8 *)%p, (uint32 )%p)\n", this, hRequest, pBodyDataBuffer, unBufferSize);
  auto result = this->internal->GetHTTPResponseBodyData(hRequest, pBodyDataBuffer, unBufferSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamHTTP_::GetHTTPStreamingResponseBodyData(HTTPRequestHandle  hRequest, uint32  cOffset, uint8 * pBodyDataBuffer, uint32  unBufferSize)
{
  TRACE("((ISteamHTTP *)%p, (HTTPRequestHandle )%p, (uint32 )%p, (uint8 *)%p, (uint32 )%p)\n", this, hRequest, cOffset, pBodyDataBuffer, unBufferSize);
  auto result = this->internal->GetHTTPStreamingResponseBodyData(hRequest, cOffset, pBodyDataBuffer, unBufferSize);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamHTTP_::ReleaseHTTPRequest(HTTPRequestHandle  hRequest)
{
  TRACE("((ISteamHTTP *)%p, (HTTPRequestHandle )%p)\n", this, hRequest);
  auto result = this->internal->ReleaseHTTPRequest(hRequest);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamHTTP_::GetHTTPDownloadProgressPct(HTTPRequestHandle  hRequest, float * pflPercentOut)
{
  TRACE("((ISteamHTTP *)%p, (HTTPRequestHandle )%p, (float *)%f)\n", this, hRequest, pflPercentOut);
  auto result = this->internal->GetHTTPDownloadProgressPct(hRequest, pflPercentOut);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamHTTP_::SetHTTPRequestRawPostBody(HTTPRequestHandle  hRequest, char * pchContentType, uint8 * pubBody, uint32  unBodyLen)
{
  TRACE("((ISteamHTTP *)%p, (HTTPRequestHandle )%p, (char *)\"%s\", (uint8 *)%p, (uint32 )%p)\n", this, hRequest, pchContentType, pubBody, unBodyLen);
  auto result = this->internal->SetHTTPRequestRawPostBody(hRequest, pchContentType, pubBody, unBodyLen);
  TRACE("() = (bool )%d\n", result);

  return result;
}


HTTPCookieContainerHandle  ISteamHTTP_::CreateCookieContainer(bool  bAllowResponsesToModify)
{
  TRACE("((ISteamHTTP *)%p, (bool )%d)\n", this, bAllowResponsesToModify);
  auto result = this->internal->CreateCookieContainer(bAllowResponsesToModify);
  TRACE("() = (HTTPCookieContainerHandle )%p\n", result);

  return result;
}


bool  ISteamHTTP_::ReleaseCookieContainer(HTTPCookieContainerHandle  hCookieContainer)
{
  TRACE("((ISteamHTTP *)%p, (HTTPCookieContainerHandle )%p)\n", this, hCookieContainer);
  auto result = this->internal->ReleaseCookieContainer(hCookieContainer);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamHTTP_::SetCookie(HTTPCookieContainerHandle  hCookieContainer, char * pchHost, char * pchUrl, char * pchCookie)
{
  TRACE("((ISteamHTTP *)%p, (HTTPCookieContainerHandle )%p, (char *)\"%s\", (char *)\"%s\", (char *)\"%s\")\n", this, hCookieContainer, pchHost, pchUrl, pchCookie);
  auto result = this->internal->SetCookie(hCookieContainer, pchHost, pchUrl, pchCookie);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamHTTP_::SetHTTPRequestCookieContainer(HTTPRequestHandle  hRequest, HTTPCookieContainerHandle  hCookieContainer)
{
  TRACE("((ISteamHTTP *)%p, (HTTPRequestHandle )%p, (HTTPCookieContainerHandle )%p)\n", this, hRequest, hCookieContainer);
  auto result = this->internal->SetHTTPRequestCookieContainer(hRequest, hCookieContainer);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamHTTP_::SetHTTPRequestUserAgentInfo(HTTPRequestHandle  hRequest, char * pchUserAgentInfo)
{
  TRACE("((ISteamHTTP *)%p, (HTTPRequestHandle )%p, (char *)\"%s\")\n", this, hRequest, pchUserAgentInfo);
  auto result = this->internal->SetHTTPRequestUserAgentInfo(hRequest, pchUserAgentInfo);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamHTTP_::SetHTTPRequestRequiresVerifiedCertificate(HTTPRequestHandle  hRequest, bool  bRequireVerifiedCertificate)
{
  TRACE("((ISteamHTTP *)%p, (HTTPRequestHandle )%p, (bool )%d)\n", this, hRequest, bRequireVerifiedCertificate);
  auto result = this->internal->SetHTTPRequestRequiresVerifiedCertificate(hRequest, bRequireVerifiedCertificate);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamHTTP_::SetHTTPRequestAbsoluteTimeoutMS(HTTPRequestHandle  hRequest, uint32  unMilliseconds)
{
  TRACE("((ISteamHTTP *)%p, (HTTPRequestHandle )%p, (uint32 )%p)\n", this, hRequest, unMilliseconds);
  auto result = this->internal->SetHTTPRequestAbsoluteTimeoutMS(hRequest, unMilliseconds);
  TRACE("() = (bool )%d\n", result);

  return result;
}


bool  ISteamHTTP_::GetHTTPRequestWasTimedOut(HTTPRequestHandle  hRequest, bool * pbWasTimedOut)
{
  TRACE("((ISteamHTTP *)%p, (HTTPRequestHandle )%p, (bool *)%d)\n", this, hRequest, pbWasTimedOut);
  auto result = this->internal->GetHTTPRequestWasTimedOut(hRequest, pbWasTimedOut);
  TRACE("() = (bool )%d\n", result);

  return result;
}
ISteamHTTP_::ISteamHTTP_(ISteamHTTP * towrap)
{
  this->internal = towrap;
}

ISteamHTTP_::~ISteamHTTP_()
{
  delete this->internal;
}
