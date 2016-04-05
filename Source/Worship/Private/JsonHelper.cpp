// Fill out your copyright notice in the Description page of Project Settings.
/*
* Author: Terrence KO
*/
#include "Worship.h"
#include "JsonHelper.h"
#include "FileManager.h"

TSharedPtr<FJsonObject> JsonHelper::loadJsonObject(const FString& fileName) {
	//load game
	FString gameContentDir = FPaths::GameContentDir();
	FString temp = FString("/savedGame/") + *fileName;
	FString writeDir = FPaths::Combine(*gameContentDir, *temp);

	FString JsonStr;
	FFileHelper::LoadFileToString(JsonStr, *writeDir);
	TSharedRef<TJsonReader<>> JsonReader = FJsonStringReader::Create(JsonStr);
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());

	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
	Request->SetVerb(TEXT("POST"));
	Request->SetURL(TEXT("http://localhost:8080/loadWorld"));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->OnProcessRequestComplete().BindRaw(this, &JsonHelper::loadRequestComplete);

	FHttpResponsePtr response = Request->GetResponse();
	FHttpResponsePtr httpnull;
  if (response != httpnull){
      if (Request->GetResponse()->GetContentAsString() != ""){
					TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(Response->GetResponse()->GetContentAsString());
      }
  }

	FJsonSerializer::Deserialize(JsonReader, JsonObject);
	//JsonObject.IsValid()
	return JsonObject;
}
bool JsonHelper::setJsonObject(const FString& fileName) {
	//save game
	//apparently creates JSON reader, not sure what it does really
	// Create a writer and hold it in this FString

	FString JsonStr;
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
	TSharedRef <TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&JsonStr, 0);
	// TSharedRef > JsonWriter = TJsonWriterFactory<>::Create(SaveFile); ????
	// TSharedRef< FPrettyJsonStringWriter > PrettyWriter = FPrettyJsonStringWriterFactory::Create( &JsonStr );
	// ============================Only for direct writing============================================
	// JsonWriter->WriteObjectStart();
	//
	// // ObjectInstance1 (will be MyObject->GetFullPath() or something)
	//   JsonWriter->WriteObjectStart("ObjectInstance1");
	//     JsonWriter->WriteValue("SomeBool", true);
	//     JsonWriter->WriteValue("SomeString", *fileName);
	//     JsonWriter->WriteValue("SomeNumber", 32.0);
	//   JsonWriter->WriteObjectEnd();
	//
	// // Close the writer and finalize the output such that JsonStr has what we want
	// JsonWriter->WriteObjectEnd();
	// JsonWriter->Close();
	// ==================================================================================================

	// JsonObject->SetBoolField("SomeBool", true);
	// JsonObject->SetStringField("SomeString", *fileName);
	// JsonObject->SetNumberField("SomNumber", 32.0);

	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);
	FString gameContentDir = FPaths::GameContentDir();
	FString temp = FString("/savedGame/") + *fileName;
	FString writeDir = FPaths::Combine(*gameContentDir, *temp);
	FFileHelper::SaveStringToFile(*JsonStr, *writeDir);

	// Http = &FHttpModule::Get();
	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
	Request->SetVerb(TEXT("POST"));
	Request->SetURL(TEXT("http://localhost:8080/saveWorld"));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetContentAsString(JsonStr);
	Request->OnProcessRequestComplete().BindRaw(this, &JsonHelper::saveRequestComplete);//holy shit BindRaw worked,
																						//https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/Delegates/index.html#payloaddata for more info
	Request->ProcessRequest();

	return true;
}

void JsonHelper::saveRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
	if (bWasSuccessful && Response->GetContentType() == "text/plain") {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, Response->GetContentAsString());
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "Failed to save at server");
	}

}

void JsonHelper::loadRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
	if (bWasSuccessful && Response->GetContentType() == "application/json") {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "Connected succesfully");
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "Failed to load at server");
	}

}
