// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 *
 */
UCLASS()
class CAMERA_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	//コンストラクタ
	UMyGameInstance();

public:

	// 現在の時間移動フラグを設定
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsCTimetravel(bool _bCTimetravelflag) { m_bCTimetravelflag = _bCTimetravelflag; }

	// 現在の時間移動フラグを取得
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsCTimetravel()const { return m_bCTimetravelflag; }

	// 過去の時間移動フラグを設定
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsPTimetravel(bool _bPTimetravelflag) { m_bPTimetravelflag = _bPTimetravelflag; }

	// 過去の時間移動フラグを取得
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsPTimetravel()const { return m_bPTimetravelflag; }

	// 未来の時間移動フラグを設定
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsFTimetravel(bool _bFTimetravelflag) { m_bFTimetravelflag = _bFTimetravelflag; }

	// 未来の時間移動フラグを取得
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsFTimetravel()const { return m_bFTimetravelflag; }

	// 時間移動が起動できるか確認するフラグを設定
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsOKTimetravel(bool _bOKTimetravelflag) { m_bOKTimetravelflag = _bOKTimetravelflag; }

	// 時間移動が起動できるか確認するフラグを取得
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsOKTimetravel()const { return m_bOKTimetravelflag; }

	
	// 秤のギミックフラグを取得
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsBalanceGimmick()const { return  m_bBalanceGimmick; }

	// 秤のギミックフラグを設定
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsBalanceGimmick(bool _iBGimmick) { m_bBalanceGimmick = _iBGimmick; }

	// 橋ギミックフラグを取得
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsRotationGimmick()const { return  m_bRotationGimmick; }

	// 橋ギミックフラグを設定
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsRotationGimmick(bool _iRGimmick) { m_bRotationGimmick = _iRGimmick; }

	// 海水取得ギミックフラグを取得
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsSeaGimmick()const { return  m_bSeaGimmick; }

	// 海水取得ギミックフラグを設定
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsSeaGimmick(bool _iSeaGimmick) { m_bSeaGimmick = _iSeaGimmick; }

	// 水車のギミックフラグを取得
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsMoveGroundGimmick()const { return  m_bMoveGroundGimmick; }

	// 水車のギミックフラグを設定
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsMoveGroundGimmick(bool _iMGimmick) { m_bMoveGroundGimmick = _iMGimmick; }

	// 扉のギミックフラグを取得
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsMoveDoorGimmick()const { return  m_bMoveDoorGimmick; }

	// 扉のギミックフラグを設定
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsMoveDoorGimmick(bool _iDGimmick) { m_bMoveDoorGimmick = _iDGimmick; }

	// スライダーのギミックフラグを取得
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsSlideGimmick()const { return  m_bSlideGimmick; }

	// スライダーのギミックフラグを設定
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsSlideGimmick(bool _iSGimmick) { m_bSlideGimmick = _iSGimmick; }

	// 奇麗にするギミックフラグを取得
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsCleanGimmick()const { return  m_bCleanGimmick; }

	// 奇麗にするギミックフラグを設定
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsCleanGimmick(bool _iSCGimmick) { m_bCleanGimmick = _iSCGimmick; }

	// 噴水のギミックフラグを取得
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsWaterJumpGimmick()const { return  m_bWaterJumpGimmick; }

	// 噴水のギミックフラグを設定
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsWaterJumpGimmick(bool _iWGimmick) { m_bWaterJumpGimmick = _iWGimmick; }

	// 布のギミックフラグを取得
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsClothGimmick()const { return  m_bClothGimmick; }

	// 布のギミックフラグを設定
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsClothGimmick(bool _iCGimmick) { m_bClothGimmick = _iCGimmick; }

	// 木のギミックフラグを取得
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsWoodGimmick()const { return  m_bWoodGimmick; }

	// 木のギミックフラグを設定
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsWoodGimmick(bool _iWGimmick) { m_bWoodGimmick = _iWGimmick; }

	// 給水のギミックフラグを取得
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsWatersupplyGimmick()const { return  m_bWatersupplyGimmick; }

	// 給水のギミックフラグを設定
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsWatersupplyGimmick(bool _iWSGimmick) { m_bWatersupplyGimmick = _iWSGimmick; }

	// 水の残量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		float i_WaterAmount;

	// 水のエフェクトを出すフラグを取得
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsWaterEffect()const { return  m_bWaterEffect; }

	// 水のエフェクトを出すフラグを設定
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsWaterEffect(bool _iWaterEffect) { m_bWaterEffect = _iWaterEffect; }


private:
	bool m_bCTimetravelflag;
	bool m_bPTimetravelflag;
	bool m_bFTimetravelflag;
	bool m_bOKTimetravelflag;
	bool m_bItemGetOKflag;
	bool m_bBalanceGimmick;
	bool m_bRotationGimmick;
	bool m_bSeaGimmick;
	bool m_bMoveGroundGimmick;
	bool m_bMoveDoorGimmick;
	bool m_bCleanGimmick;
	bool m_bWaterJumpGimmick;
	bool m_bClothGimmick;
	bool m_bWoodGimmick;
	bool m_bWatersupplyGimmick;
	bool m_bWaterEffect;
	bool m_bSlideGimmick;




	//アイテムを管理する構造体
	/*typedef struct
	{
		int Herb = 0;
		int Key = 0;
		int Drug = 0;
	} _Item;
	_Item Items;*/

};