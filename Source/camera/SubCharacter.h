// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SubCharacter.generated.h"

UCLASS()
class CAMERA_API ASubCharacter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASubCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Text)
		class UDataTable* TextDataTable1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Text)
		class UDataTable* TextDataTable2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Text)
		class UDataTable* TextDataTable3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Text)
		class UDataTable* TextDataTable4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Text)
		class UDataTable* TextDataTable5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Text)
		class UDataTable* TextDataTable6;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Text)
		class UDataTable* TextDataTable7;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Text)
		class UDataTable* TextDataTable8;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Text)
		class UDataTable* TextDataTable9;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Text)
		class UDataTable* TextDataTable10;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
