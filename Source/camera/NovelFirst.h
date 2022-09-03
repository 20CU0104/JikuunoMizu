// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "NovelFirst.generated.h"

/**
 * 
 */
UCLASS()
class CAMERA_API UNovelFirst : public UUserWidget
{
	GENERATED_BODY()
	
private:
	// メッセージ
	FString s_Message;

	bool b_Delete = false;

	// 文字列の番号取得
	int MessageNumber;

	// オパシティ
	float Opacity = 0.f;



	// 要素
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UImage* Water;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UTextBlock* PlayerMessage;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		float Time = 0.f;

public:

	// コンストラクタ
	virtual void NativeConstruct() override;

	// tick処理
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

	// データテーブルの中身を受け取る
	UFUNCTION(BlueprintCallable, Category = "MyBPLibrary")
		void SetDataTable(FString Message, bool Delete);

	// アップデート用
	void UpdateText(float DeltaTime);

	// 一文字ずつ表示
	void SetTextData(UTextBlock* Block);

	// 選択肢
	void SetChoiceText();
};
