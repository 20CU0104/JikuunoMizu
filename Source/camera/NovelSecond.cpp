// Fill out your copyright notice in the Description page of Project Settings.


#include "NovelSecond.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"


// コンストラクタ
void UNovelSecond::NativeConstruct()
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
void UNovelSecond::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);

	UpdateText(DeltaTime);
}

// データテーブルの中身を受け取ると同時にほかの変数も初期化
void UNovelSecond::SetDataTable(FString CharaName, FString Message, FString TarkerName, bool StilFlag,
	int StilNum, int StandNum, bool SoundOn, int SoundNum, int Event, float Time, bool Delete)
{
	s_Message = Message;
	s_CharaName = CharaName;
	s_TarkerName = TarkerName;
	b_Stil = StilFlag;
	i_StilNum = StilNum;
	i_StandNum = StandNum;
	b_SoundOn = SoundOn;
	i_SoundNum = SoundNum;
	i_Event = Event;
	f_Time = Time;
	b_Delete = Delete;
	MessageNumber = 0;
	b_Mojiokuri = false;

	FText sText = FText::FromString(s_TarkerName);
	TakerName->SetText(sText);
}

void UNovelSecond::UpdateText(float DeltaTime)
{
	f_WordTime += DeltaTime;
	if (f_WordTime >= 0.05f)
	{
		SetTextData(MessageBlock);
		f_WordTime = 0.f;
	}
	
	UImage* TextWindow[4];

	TextWindow[0] = MessageWindow;
	TextWindow[1] = BackGround;
	TextWindow[2] = RightStand;
	TextWindow[3] = LeftStand;

	UTexture2D* StilTex[3];

	StilTex[0] = Stil1Tex;
	StilTex[1] = Stil2Tex;
	StilTex[2] = Stil2Tex;

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

	if (b_Stil != false)
	{
		TextWindow[2]->SetBrushFromTexture(TomeiTex);
		TextWindow[3]->SetBrushFromTexture(TomeiTex);

		TextWindow[1]->SetBrushFromTexture(StilTex[i_StilNum]);
		if (i_Event == 5)
		{
			TextWindow[0]->SetBrushFromTexture(TomeiTex);
		}
	}
	else
	{
		TextWindow[1]->SetBrushFromTexture(BackGroundTex);
		// 主人公がしゃべってたら
		if (s_CharaName == "Shitrin")
		{
			TextWindow[2]->SetBrushFromTexture(PlayerTex[i_StandNum]);
			TextWindow[2]->SetColorAndOpacity(InColorAndOpacity_Before);
			TextWindow[3]->SetColorAndOpacity(InColorAndOpacity_After);
		}
		else
		{
			TextWindow[3]->SetBrushFromTexture(AIStandTex);
			TextWindow[3]->SetColorAndOpacity(InColorAndOpacity_Before);
			TextWindow[2]->SetColorAndOpacity(InColorAndOpacity_After);
		}
	}
}

void UNovelSecond::SetTextData(UTextBlock* Block)
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