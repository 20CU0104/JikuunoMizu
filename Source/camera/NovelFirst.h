// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "NovelFirst.generated.h"

/**
 * 
 */
UCLASS()
class CAMERA_API UNovelFirst : public UUserWidget
{
	GENERATED_BODY()
	
private:
	// ���b�Z�[�W
	FString s_Message;

	bool b_Delete = false;

	// ������̔ԍ��擾
	int MessageNumber;

	// �I�p�V�e�B
	float Opacity = 0.f;



	// �v�f
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UImage* Water;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UTextBlock* PlayerMessage;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Functions")
		float Time = 0.f;

public:

	// �R���X�g���N�^
	virtual void NativeConstruct() override;

	// tick����
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

	// �f�[�^�e�[�u���̒��g���󂯎��
	UFUNCTION(BlueprintCallable, Category = "MyBPLibrary")
		void SetDataTable(FString Message, bool Delete);

	// �A�b�v�f�[�g�p
	void UpdateText(float DeltaTime);

	// �ꕶ�����\��
	void SetTextData(UTextBlock* Block);

	// �I����
	void SetChoiceText();
};
