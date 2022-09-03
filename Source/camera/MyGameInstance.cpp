// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

//コンストラクタ
UMyGameInstance::UMyGameInstance()
	: m_bCTimetravelflag(true)
	, m_bPTimetravelflag(false)
	, m_bFTimetravelflag(false)
	, m_bOKTimetravelflag(false)
	, m_bSeaGimmick(false)
	, m_bMoveDoorGimmick(false)
	, m_bSlideGimmick(false)
	, m_bCleanGimmick(false)
	, m_bWaterJumpGimmick(false)
	, m_bClothGimmick(false)
	, m_bWoodGimmick(false)
	, m_bBalanceGimmick(false)
	, m_bRotationGimmick(false)
	, m_bWaterEffect(false)
	, m_bWatersupplyGimmick(false)
	, i_WaterAmount(0)
{

}