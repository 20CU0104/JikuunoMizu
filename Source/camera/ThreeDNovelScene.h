// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "ThreeDNovelScene.generated.h"

/**
 * 
 */
UCLASS()
class CAMERA_API UThreeDNovelScene : public UUserWidget
{
	GENERATED_BODY()

private:

	// メッセージ
	FString s_Message;
	// 文字列の番号取得
	int MessageNumber;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UImage* MessageWindow;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UTextBlock* MessageBlock;

	// テクスチャ
	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* MessageWindowTex;

public:

	// コンストラクタ
	virtual void NativeConstruct() override;

	// tick処理
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

	// データテーブルの中身を受け取る
	UFUNCTION(BlueprintCallable, Category = "MyBPLibrary")
		void SetDataTable(FString Message);

	// アップデート用
	void UpdateText(float DeltaTime);

	// 一文字ずつ表示
	void SetTextData(UTextBlock* Block);
	
};
