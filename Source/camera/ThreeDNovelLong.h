// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "ThreeDNovelLong.generated.h"

/**
 * 
 */
UCLASS()
class CAMERA_API UThreeDNovelLong : public UUserWidget
{
	GENERATED_BODY()

private:

	// ���b�Z�[�W
	FString s_Message;
	// �X�s�[�J�[�̖��O
	FString s_CharaName;
	// �����Ă���l�̖��O
	FString s_TakerName;
	// ����
	int i_StandNum;
	// �폜�t���O
	bool b_Delete;
	// ������̔ԍ��擾
	int MessageNumber;

	


	FLinearColor InColorAndOpacity_Before;
	FLinearColor InColorAndOpacity_After;

	// �v�f
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UImage* RightStand;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UImage* LeftStand;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UImage* MessageWindow;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UTextBlock* TakerName;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UTextBlock* MessageBlock;


	// �e�N�X�`��
	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* MessageWindowTex;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* TomeiTex;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* PlayerStandTex1;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* PlayerStandTex2;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* PlayerStandTex3;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* PlayerStandTex4;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* PlayerStandTex5;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* PlayerStandTex6;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* PlayerStandTex7;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* PlayerStandTex8;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* PlayerStandTex9;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* PlayerStandTex10;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* PlayerStandTex11;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* SubStandTex;

protected:

	// �C�x���g�̔ԍ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		bool b_Mojiokuri = false;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		bool b_MessageSoundOn = false;

	// ��������p
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		float f_WordTime = 0.f;

	// ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		float f_Time;

	// �C�x���g�i���o�[
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		int i_EventNum;
public:

	// �R���X�g���N�^
	virtual void NativeConstruct() override;

	// tick����
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

	// �f�[�^�e�[�u���̒��g���󂯎��
	UFUNCTION(BlueprintCallable, Category = "MyBPLibrary")
		void SetDataTable(FString CharaName, FString Message,FString TarkerName,int StandNum,int EventNum,bool Delete,float Time);

	// �A�b�v�f�[�g�p
	void UpdateText(float DeltaTime);

	// �ꕶ�����\��
	void SetTextData(UTextBlock* Block);
};
