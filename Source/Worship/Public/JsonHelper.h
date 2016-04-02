// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Json.h"
#include "Runtime/Online/HTTP/Public/Http.h" //for http requests
#include "IHttpRequest.h"
#include "Engine.h"


/**
 * 
 */
class WORSHIP_API JsonHelper
{
public:
	TSharedPtr<FJsonObject> loadJsonObject(const FString& FilePath);

	void saveRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void loadRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	bool setJsonObject(const FString& fileName);

	FHttpModule* Http;
};
