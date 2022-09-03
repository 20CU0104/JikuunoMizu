// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

// インクルード
#include "CoreMinimal.h"
#include "GameFramework/Character.h"	// ACharacterを継承しているため
#include "cameraCharacter.generated.h"

// 前方宣言
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class CAMERA_API AcameraCharacter : public ACharacter
{
	// UE4のオブジェクトクラスで必ず先頭に書くマクロ
	GENERATED_BODY()

public:
	// コンストラクタ
	AcameraCharacter();

protected:
	// ゲームスタート時、または生成時に呼ばれる処理
	virtual void BeginPlay() override;

public:
	// 毎フレームの更新処理
	virtual void Tick(float DeltaTime) override;

	// 各入力関係メソッドとのバインド処理
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// カメラ更新処理
	void UpdateCamera(float _deltaTime);

	// 移動処理
	void UpdateMove(float _deltaTime);

	//更新処理
	//void UpdateWalk(float DeltaTime);


private:
	// 【入力バインド】カメラ回転：Pitch（Y軸）
	void Cam_RotatePitch(float _axisValue);
	// 【入力バインド】カメラ回転：Yaw（Z軸）
	void Cam_RotateYaw(float _axisValue);
	// 【入力バインド】キャラ移動：前後
	void Chara_MoveForward(float _axisValue);
	// 【入力バインド】キャラ移動：左右
	void Chara_MoveRight(float _axisValue);

private:
	// UPROPERTYにすることで、ブループリント上で変数の確認、編集などができる

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* m_pSpringArm;					// スプリングアーム

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* m_pCamera;						//カメラ


	TArray<AActor*> m_pHitActors;		//ヒットActor　（SpringArmの直線と衝突しているActor）

	FVector2D m_charaMoveInput;					// Pawn移動入力量
	FVector2D m_cameraRotateInput;				// カメラの回転入力量

	UPROPERTY(EditAnywhere, Category = "Camera")
		FVector2D m_cameraPitchLimit;			// カメラのピッチ範囲

	UPROPERTY(EditAnywhere, Category = "Move")
		float m_moveSpeed;						// 移動量

	// ----------------------------
	// 歩き関連の関数、変数（小田口）
	// ----------------------------
	//歩くスピードの最大値
	int maxwalkspeed = 10;
	//歩くスピード
	int walkspeed = 0;
	UFUNCTION(BlueprintCallable, Category = "Function")
		void SetIsWalkSpeed(int i_speed) { walkspeed = i_speed; }
	//右に歩いてたか
	bool b_rightflag;
	//滑るかどうかのフラグ
	bool b_slipflag;

	// 歩いているか確認フラグ
	bool b_Walking;

	//地面と接しているか確認する
	bool b_Ground;

	//　停止フラグ
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
	bool b_StopCharacter;

	// ゲームパッド
	bool b_PadConnected;



	// 現在位置を保持する変数
	FVector v_PlayerPosition;

	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsJumping()const { return b_JumpFlag; }

	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsWalking()const { return b_Walking; }



	// ---------------------
	// ジャンプ関連の変数
	// ---------------------

	// ジャンプ力
	float f_JumpPower;
	// ジャンプの時間
	float f_JumpTime;
	// 現在のジャンプ量
	float f_NowJumpHeight;
	// 前のジャンプ量
	float f_prevJumpHeight;
	// ジャンプしているかのフラグ
	bool b_JumpFlag;
	// ジャンプが終わったかのフラグ
	bool b_JumpEndFlag;

	UFUNCTION(BlueprintCallable, Category = "Function")
		void SetIsJumpFlag(bool b_Jump) { b_JumpFlag = b_Jump; }
	// ジャンプ前の座標を保持
	FVector v_posBeforeJump;
	// 重力
	float f_Gravity;

	// Tickで確認
	void UpdateJump(float DeltaTime);
	// 入力のバインド
	void JumpStart();
	// 入力のバインド
	void JumpEnd();

	//接地判定を取る
	virtual void NotifyHit
	(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved
		, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;


	// ---------------------
	// 放水関連の変数
	// ---------------------
	bool m_bSprayWaterFlag;
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetSprayWaterFlag(bool _bWaterFlag) { m_bSprayWaterFlag = _bWaterFlag; }



public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float f_StopTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)

		bool m_bRolling;							// 回転中フラグ


	bool m_bKaiten;							// 回転フラグ

	//ゲームパッドに接続されているか
	UFUNCTION(BlueprintCallable)
		bool IsGamePadConnected();

	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsGamePadConnected()const { return b_PadConnected; }

};
