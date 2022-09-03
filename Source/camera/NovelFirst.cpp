
#include "NovelFirst.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"


// コンストラクタ
void UNovelFirst::NativeConstruct()
{
	Super::NativeConstruct();


}
// tick処理
void UNovelFirst::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);

	UpdateText(DeltaTime);
}

// データテーブルの中身を受け取ると同時にほかの変数も初期化
void UNovelFirst::SetDataTable(FString Message, bool Delete)
{
	s_Message += Message;
	b_Delete = Delete;
	Opacity = 0.f;
	Time = 0.f;

	if (b_Delete == true)
	{
		// 一回０にする
		FText sText = FText::FromString("");
		PlayerMessage->SetText(sText);

		MessageNumber = 0;
		s_Message = Message;
	}
}

void UNovelFirst::UpdateText(float DeltaTime)
{
	SetTextData(PlayerMessage);

	Time += DeltaTime;

	if (Opacity <= 1.0)
	{
		Opacity += 0.01;
		PlayerMessage->SetRenderOpacity(Opacity);
	}
}

void UNovelFirst::SetTextData(UTextBlock* Block)
{
	if (s_Message.Len() >= MessageNumber)
	{
		MessageNumber++;

		FText sText = FText::FromString(s_Message.Left(MessageNumber));

		Block->SetText(sText);
	}
}

void UNovelFirst::SetChoiceText()
{
}

