// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CorrentActor.generated.h"

UCLASS()
class CAMERA_API ACorrentActor : public AActor
{
	//�擪�ɏ����}�N��
	GENERATED_BODY()

public:
	//�R���X�g���N�^
	ACorrentActor();

protected:
	//�Q�[���X�^�[�g�A�������͐������ɌĂ΂�鏈��
	virtual void BeginPlay() override;

public:
	//���t���[���̍X�V����
	virtual void Tick(float DeltaTime) override;


	//�G�f�B�^���ŕҏW�ł��郁���o�ϐ�
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* m_pCorrentMesh;

	//protected:
	//	UPROPERTY()
	//		USceneComponent* m_pBase;		//�x�[�X�R���|�[�l���g
};