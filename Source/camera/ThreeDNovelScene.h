// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "ThreeDNovelScene.generated.h"

/**
 * 
 */
UCLASS()
class CAMERA_API UThreeDNovelScene : public UUserWidget
{
	GENERATED_BODY()

private:

	// ���b�Z�[�W
	FString s_Message;
	// ������̔ԍ��擾
	int MessageNumber;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UImage* MessageWindow;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UTextBlock* MessageBlock;

	// �e�N�X�`��
	UPROPERTY(EditAnywhere, Category = "Texture")
		UTexture2D* MessageWindowTex;

public:

	// �R���X�g���N�^
	virtual void NativeConstruct() override;

	// tick����
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

	// �f�[�^�e�[�u���̒��g���󂯎��
	UFUNCTION(BlueprintCallable, Category = "MyBPLibrary")
		void SetDataTable(FString Message);

	// �A�b�v�f�[�g�p
	void UpdateText(float DeltaTime);

	// �ꕶ�����\��
	void SetTextData(UTextBlock* Block);
	
};
