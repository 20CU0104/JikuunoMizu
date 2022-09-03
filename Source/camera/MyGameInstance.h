// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 *
 */
UCLASS()
class CAMERA_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	//�R���X�g���N�^
	UMyGameInstance();

public:

	// ���݂̎��Ԉړ��t���O��ݒ�
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsCTimetravel(bool _bCTimetravelflag) { m_bCTimetravelflag = _bCTimetravelflag; }

	// ���݂̎��Ԉړ��t���O���擾
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsCTimetravel()const { return m_bCTimetravelflag; }

	// �ߋ��̎��Ԉړ��t���O��ݒ�
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsPTimetravel(bool _bPTimetravelflag) { m_bPTimetravelflag = _bPTimetravelflag; }

	// �ߋ��̎��Ԉړ��t���O���擾
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsPTimetravel()const { return m_bPTimetravelflag; }

	// �����̎��Ԉړ��t���O��ݒ�
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsFTimetravel(bool _bFTimetravelflag) { m_bFTimetravelflag = _bFTimetravelflag; }

	// �����̎��Ԉړ��t���O���擾
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsFTimetravel()const { return m_bFTimetravelflag; }

	// ���Ԉړ����N���ł��邩�m�F����t���O��ݒ�
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsOKTimetravel(bool _bOKTimetravelflag) { m_bOKTimetravelflag = _bOKTimetravelflag; }

	// ���Ԉړ����N���ł��邩�m�F����t���O���擾
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsOKTimetravel()const { return m_bOKTimetravelflag; }

	
	// ���̃M�~�b�N�t���O���擾
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsBalanceGimmick()const { return  m_bBalanceGimmick; }

	// ���̃M�~�b�N�t���O��ݒ�
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsBalanceGimmick(bool _iBGimmick) { m_bBalanceGimmick = _iBGimmick; }

	// ���M�~�b�N�t���O���擾
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsRotationGimmick()const { return  m_bRotationGimmick; }

	// ���M�~�b�N�t���O��ݒ�
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsRotationGimmick(bool _iRGimmick) { m_bRotationGimmick = _iRGimmick; }

	// �C���擾�M�~�b�N�t���O���擾
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsSeaGimmick()const { return  m_bSeaGimmick; }

	// �C���擾�M�~�b�N�t���O��ݒ�
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsSeaGimmick(bool _iSeaGimmick) { m_bSeaGimmick = _iSeaGimmick; }

	// ���Ԃ̃M�~�b�N�t���O���擾
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsMoveGroundGimmick()const { return  m_bMoveGroundGimmick; }

	// ���Ԃ̃M�~�b�N�t���O��ݒ�
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsMoveGroundGimmick(bool _iMGimmick) { m_bMoveGroundGimmick = _iMGimmick; }

	// ���̃M�~�b�N�t���O���擾
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsMoveDoorGimmick()const { return  m_bMoveDoorGimmick; }

	// ���̃M�~�b�N�t���O��ݒ�
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsMoveDoorGimmick(bool _iDGimmick) { m_bMoveDoorGimmick = _iDGimmick; }

	// �X���C�_�[�̃M�~�b�N�t���O���擾
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsSlideGimmick()const { return  m_bSlideGimmick; }

	// �X���C�_�[�̃M�~�b�N�t���O��ݒ�
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsSlideGimmick(bool _iSGimmick) { m_bSlideGimmick = _iSGimmick; }

	// ���ɂ���M�~�b�N�t���O���擾
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsCleanGimmick()const { return  m_bCleanGimmick; }

	// ���ɂ���M�~�b�N�t���O��ݒ�
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsCleanGimmick(bool _iSCGimmick) { m_bCleanGimmick = _iSCGimmick; }

	// �����̃M�~�b�N�t���O���擾
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsWaterJumpGimmick()const { return  m_bWaterJumpGimmick; }

	// �����̃M�~�b�N�t���O��ݒ�
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsWaterJumpGimmick(bool _iWGimmick) { m_bWaterJumpGimmick = _iWGimmick; }

	// �z�̃M�~�b�N�t���O���擾
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsClothGimmick()const { return  m_bClothGimmick; }

	// �z�̃M�~�b�N�t���O��ݒ�
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsClothGimmick(bool _iCGimmick) { m_bClothGimmick = _iCGimmick; }

	// �؂̃M�~�b�N�t���O���擾
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsWoodGimmick()const { return  m_bWoodGimmick; }

	// �؂̃M�~�b�N�t���O��ݒ�
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsWoodGimmick(bool _iWGimmick) { m_bWoodGimmick = _iWGimmick; }

	// �����̃M�~�b�N�t���O���擾
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsWatersupplyGimmick()const { return  m_bWatersupplyGimmick; }

	// �����̃M�~�b�N�t���O��ݒ�
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsWatersupplyGimmick(bool _iWSGimmick) { m_bWatersupplyGimmick = _iWSGimmick; }

	// ���̎c��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		float i_WaterAmount;

	// ���̃G�t�F�N�g���o���t���O���擾
	UFUNCTION(BlueprintCallable, Category = "My Function")
		bool GetIsWaterEffect()const { return  m_bWaterEffect; }

	// ���̃G�t�F�N�g���o���t���O��ݒ�
	UFUNCTION(BlueprintCallable, Category = "My Function")
		void SetIsWaterEffect(bool _iWaterEffect) { m_bWaterEffect = _iWaterEffect; }


private:
	bool m_bCTimetravelflag;
	bool m_bPTimetravelflag;
	bool m_bFTimetravelflag;
	bool m_bOKTimetravelflag;
	bool m_bItemGetOKflag;
	bool m_bBalanceGimmick;
	bool m_bRotationGimmick;
	bool m_bSeaGimmick;
	bool m_bMoveGroundGimmick;
	bool m_bMoveDoorGimmick;
	bool m_bCleanGimmick;
	bool m_bWaterJumpGimmick;
	bool m_bClothGimmick;
	bool m_bWoodGimmick;
	bool m_bWatersupplyGimmick;
	bool m_bWaterEffect;
	bool m_bSlideGimmick;




	//�A�C�e�����Ǘ�����\����
	/*typedef struct
	{
		int Herb = 0;
		int Key = 0;
		int Drug = 0;
	} _Item;
	_Item Items;*/

};