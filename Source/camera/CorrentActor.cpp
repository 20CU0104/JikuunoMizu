//----------------------------------------------------------
// �t�@�C����		�Fdarkactor.cpp
// �T�v				�F��ʂ��Â�����I�u�W�F�N�g�̃N���X
// �쐬��			�F20CU0309 ���c������
// �X�V���e			�F2022/04/22 �쐬
//					�F
//----------------------------------------------------------


#include "CorrentActor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/BoxComponent.h"

//�R���X�g���N�^
ACorrentActor::ACorrentActor()
{
	// ���t���[���A���̃N���X��Tick()���ĂԂ��ǂ��������߂�t���O�B�K�v�ɉ����āA�p�t�H�[�}���X����̂��߂ɐ؂邱�Ƃ��ł���B need it.
	PrimaryActorTick.bCanEverTick = true;

	//���b�V���R���|�[�l���g����
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

