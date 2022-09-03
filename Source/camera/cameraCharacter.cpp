// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "cameraCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "Framework/Application/SlateApplication.h"

// ��`
#define JUMP_HEIGHT (f_JumpTime*f_JumpTime*(-f_Gravity)/2)+(f_JumpTime*f_JumpPower)

// �e�ݒ萔�ύX�p
#define JUMP_POWER 900.f	// �W�����v�̃p���[
#define GRAVITY	   3000.f	// �d��


// �R���X�g���N�^
AcameraCharacter::AcameraCharacter()
	: m_pSpringArm(NULL)
	, m_pCamera(NULL)
	, b_Walking(false)
	, m_charaMoveInput(FVector2D::ZeroVector)
	, m_cameraRotateInput(FVector2D::ZeroVector)
	, m_moveSpeed(10.f)
	, m_cameraPitchLimit(FVector2D(-70.0f, 20.0f))
	, b_StopCharacter(false)
	, f_JumpPower(JUMP_POWER)
	, f_JumpTime(0.f)
	, f_NowJumpHeight(0.f)
	, f_prevJumpHeight(0.f)
	, b_JumpFlag(false)
	, b_JumpEndFlag(false)
	, f_Gravity(GRAVITY)
	, b_Ground(true)
	, m_bSprayWaterFlag(false)
	, f_StopTime(0.f)
{
	// ���t���[���A���̃N���X��Tick()���ĂԂ��ǂ��������߂�t���O�B�K�v�ɉ����āA�p�t�H�[�}���X����̂��߂ɐ؂邱�Ƃ��ł���B
	PrimaryActorTick.bCanEverTick = true;

	// �f�t�H���g�v���C���[�Ƃ��Đݒ�
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// �X�v�����O�A�[���̃I�u�W�F�N�g�𐶐�
	m_pSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("m_pSpringArm"));
	if (m_pSpringArm != NULL)
	{
	
	m_pSpringArm->SetupAttachment(RootComponent);

		// �A�[���̒�����ݒ�
		// �J�����̃R���W�����e�X�g���s������ݒ�
		m_pSpringArm->bDoCollisionTest = false;
		// �J�����̒Ǐ]���O���g������ݒ�
		m_pSpringArm->bEnableCameraLag = true;
		// �J�����Ǐ]���O�̑��x��ݒ�
		m_pSpringArm->CameraLagSpeed = 30.f;
		// �J������]���O���g������ݒ�
		m_pSpringArm->bEnableCameraRotationLag = true;
		// �J������]���O�̑��x��ݒ�
		m_pSpringArm->CameraRotationLagSpeed = 20.f;
	}

	//// �J�����I�u�W�F�N�g�𐶐�
	m_pCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("m_pCamera"));
	if ((m_pCamera != NULL) && (m_pSpringArm != NULL))
	{
		// �J�������X�v�����O�A�[���ɃA�^�b�`������
		m_pCamera->SetupAttachment(m_pSpringArm, USpringArmComponent::SocketName);
	}
}

// �Q�[���X�^�[�g���A�܂��͐������ɌĂ΂�鏈��
void AcameraCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// ���t���[���̍X�V����
void AcameraCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// �J�����X�V����
	UpdateCamera(DeltaTime);

	// �ړ�����
	UpdateMove(DeltaTime);

	//�W�����v����
	UpdateJump(DeltaTime);


}

// �e���͊֌W���\�b�h�Ƃ̃o�C���h����
void AcameraCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AcameraCharacter::JumpStart);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AcameraCharacter::JumpEnd);

	// �J�����̉�]
	InputComponent->BindAxis("CameraPitch", this, &AcameraCharacter::Cam_RotatePitch);
	InputComponent->BindAxis("CameraYaw", this, &AcameraCharacter::Cam_RotateYaw);

	// �ړ�
	InputComponent->BindAxis("MoveForward", this, &AcameraCharacter::Chara_MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AcameraCharacter::Chara_MoveRight);
}

//void AcameraCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
//{
//	Jump();
//}
//
//void AcameraCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
//{
//	StopJumping();
//}

// -----------------------------------
// �֐����FUpdateJump
// ����	 �FDeltaTime
// ���e	 �F�v���C���[�̃W�����v����
// �߂�l�F�Ȃ�
// -----------------------------------
void AcameraCharacter::UpdateJump(float DeltaTime)
{
	if (b_JumpFlag)
	{
		f_StopTime = 0.f;

		f_NowJumpHeight = JUMP_HEIGHT;

		f_JumpTime += DeltaTime;

		FVector nowPos = GetActorLocation();


		if (f_NowJumpHeight < 0.0f)
		{
			b_JumpFlag = false;
			b_JumpEndFlag = false;//���c��
			f_JumpTime = 0.f;
			f_JumpPower = JUMP_POWER;//���c��

			SetActorLocation(FVector(nowPos.X, nowPos.Y, nowPos.Z));
		}
		else
		{
			SetActorLocation(FVector(nowPos.X, nowPos.Y, v_posBeforeJump.Z + f_NowJumpHeight), true);
		}

		f_prevJumpHeight = f_NowJumpHeight;

	}
	else
	{
		f_JumpTime = 0.f;
		b_JumpEndFlag = false;//���c��
		f_JumpPower = JUMP_POWER;//���c��
	}
	//�W�����v�͂����Z���鏈���i���c���j
	if (b_JumpEndFlag == false)
	{
		if (f_JumpPower <= 300.0)
		{
			f_JumpPower += 70.0;
		}
		else if (f_JumpPower <= 500.0)
		{
			f_JumpPower += 50.0;
		}

	}
	if (b_Ground == true)
	{
		b_JumpFlag = false;
		f_JumpTime = 0.f;
		b_JumpEndFlag = false;//���c��
		f_JumpPower = JUMP_POWER;//���c��
	}
}

// -----------------------------------
// �֐����FJumpStart
// ����	 �F�Ȃ�
// ���e	 �F�W�����v�t���O�𑀍�
// �߂�l�F�Ȃ�
// -----------------------------------
void AcameraCharacter::JumpStart()
{
	if (b_JumpFlag == false && b_StopCharacter == false && b_Ground == true)
	{
		b_JumpFlag = true;

		v_posBeforeJump = GetActorLocation();
		b_Ground = false;//���c��
		//m_charaMoveInput.X = 0;
		//m_charaMoveInput.Y = 0;
	}
}

// -----------------------------------
// �֐����FJumpEnd (���c��) 
// ����	 �F�Ȃ�
// ���e	 �F�{�^�������������ŃW�����v�̍�����ς���
// �߂�l�F�Ȃ�
// -----------------------------------
void AcameraCharacter::JumpEnd()
{
	//b_JumpFlag = false;
	b_JumpEndFlag = true;
}

//void AcameraCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
//	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	// �I�[�o�[���b�v�����ۂɎ��s����C�x���g
//	if (OtherActor && (OtherActor != this) && OtherComp)
//	{
//		if (OtherActor->ActorHasTag("Enemy"))
//		{
//			//// �U������
//			//if (b_AttackNow != false)
//			//{
//			//	// �G�l�~�[��|��
//
//			//}
//			//else
//			//{
//			//	b_DamegeNowAnimFlag = true;
//			//	b_StopCharacter = true;
//			//	// HP������
//			//	ChangePlayerHP(-1);
//			//}
//		}
//
//		// ����{�^����������󋵉��ɂ��邩
//		if (OtherActor->ActorHasTag("Sub"))
//		{
//			if (b_Talking == false)
//			{
//				b_Talking = true;
//			}
//		}
//
//	}
//}

// �J�����X�V����
void AcameraCharacter::UpdateCamera(float _deltaTime)
{
	// ���[�g�I�u�W�F�N�g�𒆐S�ɁA�X�v�����O�A�[���ɂ��Ă���J��������]������
	USpringArmComponent* pSpringArm = m_pSpringArm;
	if (pSpringArm != NULL)
	{
		// ���݂�FPS�𑪒�
		float fps = 1.0f / _deltaTime;

		// �����������Ă��A��葬�x�ŃJ���������悤�ɕ␳
		float rotateCorrection = 60.f / fps;

		// �J�����̐V�����p�x�����߂�
		// ���݂̊p�x���擾
		FRotator NewRotation = pSpringArm->GetRelativeRotation();

		// Yaw�͓��͂�������
		NewRotation.Yaw += m_cameraRotateInput.X * rotateCorrection;

		// Pitch�Ɋւ��ẮA�㉺�̐����p�x�͈͓̔��Ő؂�
		NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + (m_cameraRotateInput.Y * rotateCorrection), m_cameraPitchLimit.X, m_cameraPitchLimit.Y);//m_cameraRotateInput.Y * rotateCorrection;

		// �V�����p�x�𔽉f
		pSpringArm->SetRelativeRotation(NewRotation);
	}
}

// �ړ�����
void AcameraCharacter::UpdateMove(float _deltaTime)
{
	// �ړ����͂�����ꍇ
	if (!m_charaMoveInput.IsZero())
	{
		if (m_bSprayWaterFlag == false)
		{
			// �~�܂��Ă��鎞��
			f_StopTime = 0.f;

			// ���͂ɍ��킹�āAActor�����E�O��Ɉړ�
			USpringArmComponent* pSpringArm = m_pSpringArm;
			if (pSpringArm != NULL)
			{
				FVector NewLocation = GetActorLocation();

				//�@�L�����N�^�[�̈ړ�
				{
					// SpringArm�����������ɁA���͂ɂ��ړ��ʂ�PawnMovementComponent�ɓn��
					const FVector forwardVec = pSpringArm->GetForwardVector();
					AddMovementInput(forwardVec, m_charaMoveInput.Y * m_moveSpeed);
					const FVector rightVec = pSpringArm->GetRightVector();
					AddMovementInput(rightVec, m_charaMoveInput.X * m_moveSpeed);
				}

				// �ړ�����L�����N�^�[�̉�]
				{
					// �p�x��Degree�̊p�x�͈̔͂ŕ\�L
					USkeletalMeshComponent* pMeshComp = GetMesh();
					if (pMeshComp != NULL)
					{
						// �A�[�N�^���W�F���g���g���ăR���g���[���[�̓��͕������Ȃ��p�x�����߂�
						float angle = atan2(m_charaMoveInput.X, m_charaMoveInput.Y);
						// Radian�l��Degree�ɕϊ�
						float angleDeg = FMath::RadiansToDegrees(angle);

						// ���͂����p�x�@�{�@���b�V���̉�]�p�x�@�{�@Acotr�ɑ΂��ĉ�]���Ă���SpringArm�̑��Ίp�x
						float newYaw = angleDeg + GetBaseRotationOffsetRotator().Yaw + pSpringArm->GetRelativeRotation().Yaw;

						pMeshComp->SetRelativeRotation(FRotator(pMeshComp->GetRelativeRotation().Pitch, newYaw, pMeshComp->GetRelativeRotation().Roll));
					}
				}
			}
		}
		
	}


}

//�v���C���[�̃R���W���������i���c���j
void  AcameraCharacter::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved
	, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	//�n�ʂƐڂ�����true�ɂ���
	if (Other && (Other != this) && OtherComp)
	{
		if (Other->ActorHasTag("Jump"))
		{
			b_Ground = true;
			f_JumpPower = 10000;
			b_JumpFlag = true;

			v_posBeforeJump = GetActorLocation();
			b_Ground = false;//���c��


		}
		else if (Other->ActorHasTag("Ground"))
		{
			b_Ground = true;
		}

	}

}

// -----------------------------------
// �֐����FUpdateAnim
// ����	 �F�Ȃ�
// ���e	 �F�A�j���[�V�����؂�ւ�
// �߂�l�F�Ȃ�
// -----------------------------------
//void AcameraCharacter::UpdateWalk(float DeltaTime)
//{
//	//�����Ă��Ȃ��Ƃ�
//	if (b_Walking == false)
//	{
//		//�ǂ̋߂��łȂ��Ƃ�
//		if (b_slipflag == false)
//		{
//			if (b_JumpFlag == false)
//			{
//				//�����I������Ƃ��Ɋ����Ŋ��点��i�E�j
//				if (b_rightflag != false && walkspeed > 0)
//				{
//					if (walkspeed >= 30)
//					{
//						v_PlayerPosition.Y += 8;
//					}
//					else if (walkspeed >= 15)
//					{
//						v_PlayerPosition.Y += 4;
//					}
//					else
//					{
//						v_PlayerPosition.Y += 2;
//					}
//					walkspeed -= 2;
//					if (b_Ground == true)
//					{
//						SetActorLocation(v_PlayerPosition);
//					}
//				}
//				//�����I������Ƃ��Ɋ����Ŋ��点��i���j
//				else if (b_rightflag == false && walkspeed < 0)
//				{
//					if (walkspeed <= 30)
//					{
//						v_PlayerPosition.Y -= 8;
//					}
//					else if (walkspeed <= 15)
//					{
//						v_PlayerPosition.Y -= 4;
//					}
//					else
//					{
//						v_PlayerPosition.Y -= 2;
//					}
//					walkspeed += 2;
//					if (b_Ground == true)
//					{
//						SetActorLocation(v_PlayerPosition);
//					}
//				}
//			}
//			else
//			{
//				//�����I������Ƃ��Ɋ����Ŋ��点��i�E�j
//				if (b_rightflag != false && walkspeed > 0)//
//				{
//					v_PlayerPosition.Y += walkspeed;
//					walkspeed -= 1;
//
//					SetActorLocation(v_PlayerPosition);
//				}
//				//�����I������Ƃ��Ɋ����Ŋ��点��i���j
//				else if (b_rightflag == false && walkspeed < 0)//
//				{
//					v_PlayerPosition.Y += walkspeed;
//					walkspeed += 1;
//					SetActorLocation(v_PlayerPosition);
//				}
//				if (b_Ground == true)
//				{
//					walkspeed = 0;
//				}
//			}
//		}
//		else
//		{
//			//�����Ă��Ȃ��Ƃ��ɕǂ̋߂��������ꍇ�A���x���O�ɂ���
//			walkspeed = 0;
//		}
//
//		/*if(Falling == true)*/
//	}
//
//	/*if (b_JumpFlag == true && b_Walking == false)
//	{
//		if (b_rightflag != false && walkspeed > 0)
//		{
//
//		}
//	}*/
//
//	// �A�j���[�V�������Z�b�g
//	if (GetSprite()->GetFlipbook() != NowAnim)
//	{
//		GetSprite()->SetFlipbook(NowAnim);
//	}
//}


// �y���̓o�C���h�z�J������]�FPitch�iY���j
void AcameraCharacter::Cam_RotatePitch(float _axisValue)
{
	m_cameraRotateInput.Y = _axisValue;
}

// �y���̓o�C���h�z�J������]�FYaw�iZ���j
void AcameraCharacter::Cam_RotateYaw(float _axisValue)
{
	m_cameraRotateInput.X = _axisValue;
}

// �y���̓o�C���h�z�L�����ړ��F���E
void AcameraCharacter::Chara_MoveRight(float _axisValue)
{
	m_charaMoveInput.X = FMath::Clamp(_axisValue, -1.0f, 1.0f) * 0.5f;
	//if (b_StopCharacter == false)
	//{

	//	// �v���C���[�̌��݈ʒu���擾
	//	v_PlayerPosition = GetActorLocation();

	//	// �������Ɉړ�(���c��)
	//	if (InputAxisValue < 0.f)
	//	{
	//		v_PlayerPosition.Y += walkspeed;
	//		if (b_rightflag != false)
	//		{
	//			walkspeed = 0;
	//		}
	//		if (walkspeed > -maxwalkspeed)
	//		{
	//			walkspeed -= 1;
	//		}
	//		b_rightflag = false;
	//	}
	//	// �E�����Ɉړ�(���c��)
	//	if (InputAxisValue > 0.f)
	//	{
	//		v_PlayerPosition.Y += walkspeed;
	//		if (b_rightflag == false)
	//		{
	//			walkspeed = 0;
	//		}
	//		if (walkspeed < maxwalkspeed)
	//		{
	//			walkspeed += 1;
	//		}
	//		b_rightflag = true;
	//	}
	//	v_PlayerPosition.X = -120.f;


	//	// ���ݒn���Z�b�g
	//	SetActorLocation(v_PlayerPosition);

	//	// �A�j���[�V�����؂�ւ�
	//	if (InputAxisValue > 0.f)
	//	{
	//		b_Walking = true;
	//	}
	//	else if (0.f > InputAxisValue)
	//	{
	//		b_Walking = true;
	//	}
	//	else
	//	{
	//		b_Walking = false;
	//	}
	//}

}
// �y���̓o�C���h�z�L�����ړ��F�O��
void AcameraCharacter::Chara_MoveForward(float _axisValue)
{
	m_charaMoveInput.Y = FMath::Clamp(_axisValue, -1.0f, 1.0f) * 0.5f;
}

bool AcameraCharacter::IsGamePadConnected()
{
	auto genericApplication = FSlateApplication::Get().GetPlatformApplication();
	if (genericApplication.Get() != nullptr &&
		genericApplication->IsGamepadAttached())
	{
		return true;
	}

	return false;
}