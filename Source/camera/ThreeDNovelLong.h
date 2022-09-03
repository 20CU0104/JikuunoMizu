// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "ThreeDNovelLong.generated.h"

/**
 * 
 */
UCLASS()
class CAMERA_API UThreeDNovelLong : public UUserWidget
{
	GENERATED_BODY()

private:

	// メッセージ
	FString s_Message;
	// スピーカーの名前
	FString s_CharaName;
	// 喋っている人の名前
	FString s_TakerName;
	// 差分
	int i_StandNum;
	// 削除フラグ
	bool b_Delete;
	// 文字列の番号取得
	int MessageNumber;

	


	FLinearColor InColorAndOpacity_Before;
	FLinearColor InColorAndOpacity_After;

	// 要素
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UImage* RightStand;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UImage* LeftStand;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UImage* MessageWindow;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UTextBlock* TakerName;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UTextBlock* MessageBlock;


	// テクスチャ
	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* MessageWindowTex;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* TomeiTex;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* PlayerStandTex1;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* PlayerStandTex2;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* PlayerStandTex3;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* PlayerStandTex4;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* PlayerStandTex5;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* PlayerStandTex6;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* PlayerStandTex7;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* PlayerStandTex8;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* PlayerStandTex9;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* PlayerStandTex10;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* PlayerStandTex11;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* SubStandTex;

protected:

	// イベントの番号
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		bool b_Mojiokuri = false;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		bool b_MessageSoundOn = false;

	// 文字送り用
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		float f_WordTime = 0.f;

	// 時間
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		float f_Time;

	// イベントナンバー
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		int i_EventNum;
public:

	// コンストラクタ
	virtual void NativeConstruct() override;

	// tick処理
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

	// データテーブルの中身を受け取る
	UFUNCTION(BlueprintCallable, Category = "MyBPLibrary")
		void SetDataTable(FString CharaName, FString Message,FString TarkerName,int StandNum,int EventNum,bool Delete,float Time);

	// アップデート用
	void UpdateText(float DeltaTime);

	// 一文字ずつ表示
	void SetTextData(UTextBlock* Block);
};
