//----------------------------------------------------------
// ファイル名		：darkactor.cpp
// 概要				：画面を暗くするオブジェクトのクラス
// 作成者			：20CU0309 小田口隆龍
// 更新内容			：2022/04/22 作成
//					：
//----------------------------------------------------------


#include "CorrentActor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/BoxComponent.h"

//コンストラクタ
ACorrentActor::ACorrentActor()
{
	// 毎フレーム、このクラスのTick()を呼ぶかどうかを決めるフラグ。必要に応じて、パフォーマンス向上のために切ることもできる。 need it.
	PrimaryActorTick.bCanEverTick = true;

	//メッシュコンポーネント生成
	m_pCorrentMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DarkMesh"));
	m_pCorrentMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACorrentActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACorrentActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

