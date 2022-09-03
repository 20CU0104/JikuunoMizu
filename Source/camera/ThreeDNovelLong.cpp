// Fill out your copyright notice in the Description page of Project Settings.


#include "ThreeDNovelLong.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"


// コンストラクタ
void UThreeDNovelLong::NativeConstruct()
{
	Super::NativeConstruct();

	InColorAndOpacity_Before.R = 1.f;
	InColorAndOpacity_Before.G = 1.f;
	InColorAndOpacity_Before.B = 1.f;
	InColorAndOpacity_Before.A = 1.f;

	InColorAndOpacity_After.R = 0.2f;
	InColorAndOpacity_After.G = 0.2f;
	InColorAndOpacity_After.B = 0.2f;
	InColorAndOpacity_After.A = 1.f;
}

// tick処理
void UThreeDNovelLong::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);

	UpdateText(DeltaTime);
}

// データテーブルの中身を受け取ると同時にほかの変数も初期化
void UThreeDNovelLong::SetDataTable(FString CharaName, FString Message, FString TarkerName, int StandNum, int EventNum, bool Delete, float Time)
{
	s_Message = Message;
	s_CharaName = CharaName;
	s_TakerName = TarkerName;
	i_StandNum = StandNum;
	i_EventNum = EventNum;
	b_Delete = Delete;
	f_Time = Time;
	MessageNumber = 0;
	b_Mojiokuri = false;

	FText sTextName = FText::FromString(s_TakerName);
	TakerName->SetText(sTextName);
}

void UThreeDNovelLong::UpdateText(float DeltaTime)
{
	f_WordTime += DeltaTime;
	if (f_WordTime >= 0.05f)
	{
		SetTextData(MessageBlock);
		f_WordTime = 0.f;
	}

	UImage* TextWindow[3];

	TextWindow[0] = MessageWindow;
	TextWindow[1] = RightStand;
	TextWindow[2] = LeftStand;

	UTexture2D* PlayerTex[11];

	PlayerTex[0] = PlayerStandTex1;
	PlayerTex[1] = PlayerStandTex2;
	PlayerTex[2] = PlayerStandTex3;
	PlayerTex[3] = PlayerStandTex4;
	PlayerTex[4] = PlayerStandTex5;
	PlayerTex[5] = PlayerStandTex6;
	PlayerTex[6] = PlayerStandTex7;
	PlayerTex[7] = PlayerStandTex8;
	PlayerTex[8] = PlayerStandTex9;
	PlayerTex[9] = PlayerStandTex10;
	PlayerTex[10] = PlayerStandTex11;


	TextWindow[0]->SetBrushFromTexture(MessageWindowTex);

	if (b_Delete == true)
	{
		TextWindow[1]->SetBrushFromTexture(TomeiTex);
		TextWindow[2]->SetBrushFromTexture(TomeiTex);
	}
	else
	{
		// 主人公がしゃべってたら
		if (s_CharaName == "Shitrin")
		{
			TextWindow[1]->SetBrushFromTexture(PlayerTex[i_StandNum]);
			TextWindow[1]->SetColorAndOpacity(InColorAndOpacity_Before);
			TextWindow[2]->SetColorAndOpacity(InColorAndOpacity_After);

		}
		else
		{
			TextWindow[2]->SetBrushFromTexture(SubStandTex);
			TextWindow[2]->SetColorAndOpacity(InColorAndOpacity_Before);
			TextWindow[1]->SetColorAndOpacity(InColorAndOpacity_After);

		}
	}
}

void UThreeDNovelLong::SetTextData(UTextBlock* Block)
{
	if (s_Message.Len() >= MessageNumber)
	{
		if (b_Mojiokuri == true)
		{
			FText sText = FText::FromString(s_Message);

			Block->SetText(sText);
		}
		else
		{
			MessageNumber++;

			FText sText = FText::FromString(s_Message.Left(MessageNumber));

			Block->SetText(sText);

			b_MessageSoundOn = true;
		}
	}
	else
	{
		b_Mojiokuri = true;
	}
}
