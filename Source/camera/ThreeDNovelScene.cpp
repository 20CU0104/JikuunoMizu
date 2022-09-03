// Fill out your copyright notice in the Description page of Project Settings.


#include "ThreeDNovelScene.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"


// コンストラクタ
void UThreeDNovelScene::NativeConstruct()
{
	Super::NativeConstruct();
}

// tick処理
void UThreeDNovelScene::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);

	UpdateText(DeltaTime);
}

// データテーブルの中身を受け取ると同時にほかの変数も初期化
void UThreeDNovelScene::SetDataTable(FString Message)
{
	s_Message = Message;
}

void UThreeDNovelScene::UpdateText(float DeltaTime)
{
	SetTextData(MessageBlock);

	MessageWindow->SetBrushFromTexture(MessageWindowTex);
}

void UThreeDNovelScene::SetTextData(UTextBlock* Block)
{
	if (s_Message.Len() >= MessageNumber)
	{
		MessageNumber++;

		FText sText = FText::FromString(s_Message.Left(MessageNumber));

		Block->SetText(sText);
	}
}