// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "NovelSecond.generated.h"




/**
 * 
 */
UCLASS()
class CAMERA_API UNovelSecond : public UUserWidget
{
	GENERATED_BODY()
private:

	// ���b�Z�[�W
	FString s_Message;
	// �X�s�[�J�̖��O
	FString s_CharaName;
	// �����Ă���l�̖��O
	FString s_TarkerName;
	// �X�`���̗L��
	bool b_Stil;
	// �X�`���ԍ�
	int i_StilNum;
	// ����
	int i_StandNum;
	
	


	FLinearColor InColorAndOpacity_Before;
	FLinearColor InColorAndOpacity_After;

	// �폜
	bool b_Delete;

	// ������̔ԍ��擾
	int MessageNumber;

	// �I�p�V�e�B
	float Opacity = 0.f;

	


	// �v�f
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UImage* BackGround;

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
		UTexture2D* AIStandTex;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* BackGroundTex;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* Stil1Tex;

	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* Stil2Tex;

protected:

	// ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		float f_Time;

	// �����邩
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		bool b_SoundOn;

	// ���̔ԍ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		int i_SoundNum;

	// �C�x���g�̔ԍ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		int i_Event;

	// �C�x���g�̔ԍ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		bool b_Mojiokuri = false;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		bool b_MessageSoundOn = false;

	// ��������p
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		float f_WordTime = 0.f;


public:

	// �R���X�g���N�^
	virtual void NativeConstruct() override;

	// tick����
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

	// �f�[�^�e�[�u���̒��g���󂯎��
	UFUNCTION(BlueprintCallable, Category = "MyBPLibrary")
		void SetDataTable(FString CharaName, FString Message, FString TarkerName,bool StilFlag, int StilNum, int StandNum, bool SoundOn, int SoundNum, int Event, float Time, bool Delete);

	// �A�b�v�f�[�g�p
	void UpdateText(float DeltaTime);

	// �ꕶ�����\��
	void SetTextData(UTextBlock* Block);
};
