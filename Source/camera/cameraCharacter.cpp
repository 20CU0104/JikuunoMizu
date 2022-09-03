// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "cameraCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "Framework/Application/SlateApplication.h"

// 定義
#define JUMP_HEIGHT (f_JumpTime*f_JumpTime*(-f_Gravity)/2)+(f_JumpTime*f_JumpPower)

// 各設定数変更用
#define JUMP_POWER 900.f	// ジャンプのパワー
#define GRAVITY	   3000.f	// 重力


// コンストラクタ
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
	// 毎フレーム、このクラスのTick()を呼ぶかどうかを決めるフラグ。必要に応じて、パフォーマンス向上のために切ることもできる。
	PrimaryActorTick.bCanEverTick = true;

	// デフォルトプレイヤーとして設定
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// スプリングアームのオブジェクトを生成
	m_pSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("m_pSpringArm"));
	if (m_pSpringArm != NULL)
	{
	
	m_pSpringArm->SetupAttachment(RootComponent);

		// アームの長さを設定
		// カメラのコリジョンテストを行うかを設定
		m_pSpringArm->bDoCollisionTest = false;
		// カメラの追従ラグを使うかを設定
		m_pSpringArm->bEnableCameraLag = true;
		// カメラ追従ラグの速度を設定
		m_pSpringArm->CameraLagSpeed = 30.f;
		// カメラ回転ラグを使うかを設定
		m_pSpringArm->bEnableCameraRotationLag = true;
		// カメラ回転ラグの速度を設定
		m_pSpringArm->CameraRotationLagSpeed = 20.f;
	}

	//// カメラオブジェクトを生成
	m_pCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("m_pCamera"));
	if ((m_pCamera != NULL) && (m_pSpringArm != NULL))
	{
		// カメラをスプリングアームにアタッチさせる
		m_pCamera->SetupAttachment(m_pSpringArm, USpringArmComponent::SocketName);
	}
}

// ゲームスタート時、または生成時に呼ばれる処理
void AcameraCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// 毎フレームの更新処理
void AcameraCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// カメラ更新処理
	UpdateCamera(DeltaTime);

	// 移動処理
	UpdateMove(DeltaTime);

	//ジャンプ処理
	UpdateJump(DeltaTime);


}

// 各入力関係メソッドとのバインド処理
void AcameraCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AcameraCharacter::JumpStart);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AcameraCharacter::JumpEnd);

	// カメラの回転
	InputComponent->BindAxis("CameraPitch", this, &AcameraCharacter::Cam_RotatePitch);
	InputComponent->BindAxis("CameraYaw", this, &AcameraCharacter::Cam_RotateYaw);

	// 移動
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
// 関数名：UpdateJump
// 引数	 ：DeltaTime
// 内容	 ：プレイヤーのジャンプ処理
// 戻り値：なし
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
			b_JumpEndFlag = false;//小田口
			f_JumpTime = 0.f;
			f_JumpPower = JUMP_POWER;//小田口

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
		b_JumpEndFlag = false;//小田口
		f_JumpPower = JUMP_POWER;//小田口
	}
	//ジャンプ力を加算する処理（小田口）
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
		b_JumpEndFlag = false;//小田口
		f_JumpPower = JUMP_POWER;//小田口
	}
}

// -----------------------------------
// 関数名：JumpStart
// 引数	 ：なし
// 内容	 ：ジャンプフラグを操作
// 戻り値：なし
// -----------------------------------
void AcameraCharacter::JumpStart()
{
	if (b_JumpFlag == false && b_StopCharacter == false && b_Ground == true)
	{
		b_JumpFlag = true;

		v_posBeforeJump = GetActorLocation();
		b_Ground = false;//小田口
		//m_charaMoveInput.X = 0;
		//m_charaMoveInput.Y = 0;
	}
}

// -----------------------------------
// 関数名：JumpEnd (小田口) 
// 引数	 ：なし
// 内容	 ：ボタンを押す長さでジャンプの高さを変える
// 戻り値：なし
// -----------------------------------
void AcameraCharacter::JumpEnd()
{
	//b_JumpFlag = false;
	b_JumpEndFlag = true;
}

//void AcameraCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
//	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	// オーバーラップした際に実行するイベント
//	if (OtherActor && (OtherActor != this) && OtherComp)
//	{
//		if (OtherActor->ActorHasTag("Enemy"))
//		{
//			//// 攻撃中か
//			//if (b_AttackNow != false)
//			//{
//			//	// エネミーを倒す
//
//			//}
//			//else
//			//{
//			//	b_DamegeNowAnimFlag = true;
//			//	b_StopCharacter = true;
//			//	// HPが減る
//			//	ChangePlayerHP(-1);
//			//}
//		}
//
//		// 決定ボタンが押せる状況下にいるか
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

// カメラ更新処理
void AcameraCharacter::UpdateCamera(float _deltaTime)
{
	// ルートオブジェクトを中心に、スプリングアームについているカメラを回転させる
	USpringArmComponent* pSpringArm = m_pSpringArm;
	if (pSpringArm != NULL)
	{
		// 現在のFPSを測定
		float fps = 1.0f / _deltaTime;

		// 処理落ちしても、一定速度でカメラが回るように補正
		float rotateCorrection = 60.f / fps;

		// カメラの新しい角度を求める
		// 現在の角度を取得
		FRotator NewRotation = pSpringArm->GetRelativeRotation();

		// Yawは入力した分回す
		NewRotation.Yaw += m_cameraRotateInput.X * rotateCorrection;

		// Pitchに関しては、上下の制限角度の範囲内で切る
		NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + (m_cameraRotateInput.Y * rotateCorrection), m_cameraPitchLimit.X, m_cameraPitchLimit.Y);//m_cameraRotateInput.Y * rotateCorrection;

		// 新しい角度を反映
		pSpringArm->SetRelativeRotation(NewRotation);
	}
}

// 移動処理
void AcameraCharacter::UpdateMove(float _deltaTime)
{
	// 移動入力がある場合
	if (!m_charaMoveInput.IsZero())
	{
		if (m_bSprayWaterFlag == false)
		{
			// 止まっている時間
			f_StopTime = 0.f;

			// 入力に合わせて、Actorを左右前後に移動
			USpringArmComponent* pSpringArm = m_pSpringArm;
			if (pSpringArm != NULL)
			{
				FVector NewLocation = GetActorLocation();

				//　キャラクターの移動
				{
					// SpringArmが向く方向に、入力による移動量をPawnMovementComponentに渡す
					const FVector forwardVec = pSpringArm->GetForwardVector();
					AddMovementInput(forwardVec, m_charaMoveInput.Y * m_moveSpeed);
					const FVector rightVec = pSpringArm->GetRightVector();
					AddMovementInput(rightVec, m_charaMoveInput.X * m_moveSpeed);
				}

				// 移動するキャラクターの回転
				{
					// 角度はDegreeの角度の範囲で表記
					USkeletalMeshComponent* pMeshComp = GetMesh();
					if (pMeshComp != NULL)
					{
						// アークタンジェントを使ってコントローラーの入力方向がなす角度を求める
						float angle = atan2(m_charaMoveInput.X, m_charaMoveInput.Y);
						// Radian値をDegreeに変換
						float angleDeg = FMath::RadiansToDegrees(angle);

						// 入力した角度　＋　メッシュの回転角度　＋　Acotrに対して回転しているSpringArmの相対角度
						float newYaw = angleDeg + GetBaseRotationOffsetRotator().Yaw + pSpringArm->GetRelativeRotation().Yaw;

						pMeshComp->SetRelativeRotation(FRotator(pMeshComp->GetRelativeRotation().Pitch, newYaw, pMeshComp->GetRelativeRotation().Roll));
					}
				}
			}
		}
		
	}


}

//プレイヤーのコリジョンを取る（小田口）
void  AcameraCharacter::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved
	, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	//地面と接したらtrueにする
	if (Other && (Other != this) && OtherComp)
	{
		if (Other->ActorHasTag("Jump"))
		{
			b_Ground = true;
			f_JumpPower = 10000;
			b_JumpFlag = true;

			v_posBeforeJump = GetActorLocation();
			b_Ground = false;//小田口


		}
		else if (Other->ActorHasTag("Ground"))
		{
			b_Ground = true;
		}

	}

}

// -----------------------------------
// 関数名：UpdateAnim
// 引数	 ：なし
// 内容	 ：アニメーション切り替え
// 戻り値：なし
// -----------------------------------
//void AcameraCharacter::UpdateWalk(float DeltaTime)
//{
//	//歩いていないとき
//	if (b_Walking == false)
//	{
//		//壁の近くでないとき
//		if (b_slipflag == false)
//		{
//			if (b_JumpFlag == false)
//			{
//				//歩き終わったときに慣性で滑らせる（右）
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
//				//歩き終わったときに慣性で滑らせる（左）
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
//				//歩き終わったときに慣性で滑らせる（右）
//				if (b_rightflag != false && walkspeed > 0)//
//				{
//					v_PlayerPosition.Y += walkspeed;
//					walkspeed -= 1;
//
//					SetActorLocation(v_PlayerPosition);
//				}
//				//歩き終わったときに慣性で滑らせる（左）
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
//			//歩いていないときに壁の近くだった場合、速度を０にする
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
//	// アニメーションをセット
//	if (GetSprite()->GetFlipbook() != NowAnim)
//	{
//		GetSprite()->SetFlipbook(NowAnim);
//	}
//}


// 【入力バインド】カメラ回転：Pitch（Y軸）
void AcameraCharacter::Cam_RotatePitch(float _axisValue)
{
	m_cameraRotateInput.Y = _axisValue;
}

// 【入力バインド】カメラ回転：Yaw（Z軸）
void AcameraCharacter::Cam_RotateYaw(float _axisValue)
{
	m_cameraRotateInput.X = _axisValue;
}

// 【入力バインド】キャラ移動：左右
void AcameraCharacter::Chara_MoveRight(float _axisValue)
{
	m_charaMoveInput.X = FMath::Clamp(_axisValue, -1.0f, 1.0f) * 0.5f;
	//if (b_StopCharacter == false)
	//{

	//	// プレイヤーの現在位置を取得
	//	v_PlayerPosition = GetActorLocation();

	//	// 左方向に移動(小田口)
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
	//	// 右方向に移動(小田口)
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


	//	// 現在地をセット
	//	SetActorLocation(v_PlayerPosition);

	//	// アニメーション切り替え
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
// 【入力バインド】キャラ移動：前後
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