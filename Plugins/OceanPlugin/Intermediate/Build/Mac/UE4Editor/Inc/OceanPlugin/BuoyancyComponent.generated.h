// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OCEANPLUGIN_BuoyancyComponent_generated_h
#error "BuoyancyComponent.generated.h already included, missing '#pragma once' in BuoyancyComponent.h"
#endif
#define OCEANPLUGIN_BuoyancyComponent_generated_h

#define WarShips_Plugins_OceanPlugin_Source_OceanPlugin_Classes_BuoyancyComponent_h_33_RPC_WRAPPERS
#define WarShips_Plugins_OceanPlugin_Source_OceanPlugin_Classes_BuoyancyComponent_h_33_RPC_WRAPPERS_NO_PURE_DECLS
#define WarShips_Plugins_OceanPlugin_Source_OceanPlugin_Classes_BuoyancyComponent_h_33_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUBuoyancyComponent(); \
	friend OCEANPLUGIN_API class UClass* Z_Construct_UClass_UBuoyancyComponent(); \
	public: \
	DECLARE_CLASS(UBuoyancyComponent, UMovementComponent, COMPILED_IN_FLAGS(0), 0, OceanPlugin, NO_API) \
	DECLARE_SERIALIZER(UBuoyancyComponent) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<UBuoyancyComponent*>(this); }


#define WarShips_Plugins_OceanPlugin_Source_OceanPlugin_Classes_BuoyancyComponent_h_33_INCLASS \
	private: \
	static void StaticRegisterNativesUBuoyancyComponent(); \
	friend OCEANPLUGIN_API class UClass* Z_Construct_UClass_UBuoyancyComponent(); \
	public: \
	DECLARE_CLASS(UBuoyancyComponent, UMovementComponent, COMPILED_IN_FLAGS(0), 0, OceanPlugin, NO_API) \
	DECLARE_SERIALIZER(UBuoyancyComponent) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<UBuoyancyComponent*>(this); }


#define WarShips_Plugins_OceanPlugin_Source_OceanPlugin_Classes_BuoyancyComponent_h_33_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UBuoyancyComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBuoyancyComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBuoyancyComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBuoyancyComponent); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API UBuoyancyComponent(const UBuoyancyComponent& InCopy); \
public:


#define WarShips_Plugins_OceanPlugin_Source_OceanPlugin_Classes_BuoyancyComponent_h_33_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UBuoyancyComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API UBuoyancyComponent(const UBuoyancyComponent& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBuoyancyComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBuoyancyComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBuoyancyComponent)


#define WarShips_Plugins_OceanPlugin_Source_OceanPlugin_Classes_BuoyancyComponent_h_30_PROLOG
#define WarShips_Plugins_OceanPlugin_Source_OceanPlugin_Classes_BuoyancyComponent_h_33_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WarShips_Plugins_OceanPlugin_Source_OceanPlugin_Classes_BuoyancyComponent_h_33_RPC_WRAPPERS \
	WarShips_Plugins_OceanPlugin_Source_OceanPlugin_Classes_BuoyancyComponent_h_33_INCLASS \
	WarShips_Plugins_OceanPlugin_Source_OceanPlugin_Classes_BuoyancyComponent_h_33_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define WarShips_Plugins_OceanPlugin_Source_OceanPlugin_Classes_BuoyancyComponent_h_33_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WarShips_Plugins_OceanPlugin_Source_OceanPlugin_Classes_BuoyancyComponent_h_33_RPC_WRAPPERS_NO_PURE_DECLS \
	WarShips_Plugins_OceanPlugin_Source_OceanPlugin_Classes_BuoyancyComponent_h_33_INCLASS_NO_PURE_DECLS \
	WarShips_Plugins_OceanPlugin_Source_OceanPlugin_Classes_BuoyancyComponent_h_33_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class BuoyancyComponent."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID WarShips_Plugins_OceanPlugin_Source_OceanPlugin_Classes_BuoyancyComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS