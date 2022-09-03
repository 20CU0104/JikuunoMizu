// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

// �C���N���[�h
#include "CoreMinimal.h"
#include "GameFramework/Character.h"	// ACharacter���p�����Ă��邽��
#include "cameraCharacter.generated.h"

// �O���錾
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class CAMERA_API AcameraCharacter : public ACharacter
{
	// UE4�̃I�u�W�F�N�g�N���X�ŕK���擪�ɏ����}�N��
	GENERATED_BODY()

public:
	// �R���X�g���N�^
	AcameraCharacter();

protected:
	// �Q�[���X�^�[�g���A�܂��͐������ɌĂ΂�鏈��
	virtual void BeginPlay() override;

public:
	// ���t���[���̍X�V����
	virtual void Tick(float DeltaTime) override;

	// �e���͊֌W���\�b�h�Ƃ̃o�C���h����
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// �J�����X�V����
	void UpdateCamera(float _deltaTime);

	// �ړ�����
	void UpdateMove(float _deltaTime);

	//�X�V����
	//void UpdateWalk(float DeltaTime);


private:
	// �y���̓o�C���h�z�J������]�FPitch�iY���j
	void Cam_RotatePitch(float _axisValue);
	// �y���̓o�C���h�z�J������]�FYaw�iZ���j
	void Cam_RotateYaw(float _axisValue);
	// �y���̓o�C���h�z�L�����ړ��F�O��
	void Chara_MoveForward(float _axisValue);
	// �y���̓o�C���h�z�L�����ړ��F���E
	void Chara_MoveRight(float _axisValue);

private:
	// UPROPERTY�ɂ��邱�ƂŁA�u���[�v�����g��ŕϐ��̊m�F�A�ҏW�Ȃǂ��ł���

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* m_pSpringArm;					// �X�v�����O�A�[��

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* m_pCamera;						//�J����


	TArray<AActor*> m_pHitActors;		//�q�b�gActor�@�iSpringArm�̒����ƏՓ˂��Ă���Actor�j

	FVector2D m_charaMoveInput;					// Pawn�ړ����͗�
	FVector2D m_cameraRotateInput;				// �J�����̉�]���͗�

	UPROPERTY(EditAnywhere, Category = "Camera")
		FVector2D m_cameraPitchLimit;			// �J�����̃s�b�`�͈�

	UPROPERTY(EditAnywhere, Category = "Move")
		float m_moveSpeed;						// �ړ���

	// ----------------------------
	// �����֘A�̊֐��A�ϐ��i���c���j
	// ----------------------------
	//�����X�s�[�h�̍ő�l
	int maxwalkspeed = 10;
	//�����X�s�[�h
	int walkspeed = 0;
	UFUNCTION(BlueprintCallable, Category = "Function")
		void SetIsWalkSpeed(int i_speed) { walkspeed = i_speed; }
	//�E�ɕ����Ă���
	bool b_rightflag;
	//���邩�ǂ����̃t���O
	bool b_slipflag;

	// �����Ă��邩�m�F�t���O
	bool b_Walking;

	//�n�ʂƐڂ��Ă��邩�m�F����
	bool b_Ground;

	//�@��~�t���O
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
	bool b_StopCharacter;

	// �Q�[���p�b�h
	bool b_PadConnected;



	// ���݈ʒu��ێ�����ϐ�
	FVector v_PlayerPosition;

	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsJumping()const { return b_JumpFlag; }

	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsWalking()const { return b_Walking; }



	// ---------------------
	// �W�����v�֘A�̕ϐ�
	// ---------------------

	// �W�����v��
	float f_JumpPower;
	// �W�����v�̎���
	float f_JumpTime;
	// ���݂̃W�����v��
	float f_NowJumpHeight;
	// �O�̃W�����v��
	float f_prevJumpHeight;
	// �W�����v���Ă��邩�̃t���O
	bool b_JumpFlag;
	// �W�����v���I��������̃t���O
	bool b_JumpEndFlag;

	UFUNCTION(BlueprintCallable, Category = "Function")
		void SetIsJumpFlag(bool b_Jump) { b_JumpFlag = b_Jump; }
	// �W�����v�O�̍��W��ێ�
	FVector v_posBeforeJump;
	// �d��
	float f_Gravity;

	// Tick�Ŋm�F
	void UpdateJump(float DeltaTime);
	// ���͂̃o�C���h
	void JumpStart();
	// ���͂̃o�C���h
	void JumpEnd();

	//�ڒn��������
	virtual void NotifyHit
	(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved
		, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;


	// ---------------------
	// �����֘A�̕ϐ�
	// ---------------------
	bool m_bSprayWaterFlag;
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetSprayWaterFlag(bool _bWaterFlag) { m_bSprayWaterFlag = _bWaterFlag; }



public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float f_StopTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)

		bool m_bRolling;							// ��]���t���O


	bool m_bKaiten;							// ��]�t���O

	//�Q�[���p�b�h�ɐڑ�����Ă��邩
	UFUNCTION(BlueprintCallable)
		bool IsGamePadConnected();

	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsGamePadConnected()const { return b_PadConnected; }

};
