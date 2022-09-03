// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CorrentActor.generated.h"

UCLASS()
class CAMERA_API ACorrentActor : public AActor
{
	//先頭に書くマクロ
	GENERATED_BODY()

public:
	//コンストラクタ
	ACorrentActor();

protected:
	//ゲームスタート、もしくは生成時に呼ばれる処理
	virtual void BeginPlay() override;

public:
	//毎フレームの更新処理
	virtual void Tick(float DeltaTime) override;


	//エディタ側で編集できるメンバ変数
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* m_pCorrentMesh;

	//protected:
	//	UPROPERTY()
	//		USceneComponent* m_pBase;		//ベースコンポーネント
};