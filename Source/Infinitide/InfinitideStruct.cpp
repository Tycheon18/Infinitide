// Fill out your copyright notice in the Description page of Project Settings.


#include "InfinitideStruct.h"
#include "Engine/Engine.h"

AInfinitideStruct::AInfinitideStruct()
{

}

FInfinitideUpgradeOption::FInfinitideUpgradeOption()
	: Name(TEXT("")),
	  Description(TEXT("")),
	  UpgradeId(0),
	  Type(0),
	  Value(0.f)
	
{
}

FInfinitideUpgradeOption::~FInfinitideUpgradeOption()
{
}
