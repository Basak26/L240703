// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class L20240625_API AMyHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void DrawHUD() override;

public:
	AMyHUD();
	int CenterX;
	int CenterY;
	int CrosshairHalfSize;
	int CrosshairMaxOpen;
	float CrosshairOpen;

	//�� ���ϱ�
	ACharacter* GetControlledCharacter();

	//���� ���ϱ�
	float CalculateMovementRatio(ACharacter* Character);
	
	//���ڼ� �׸���
	void DrawCrossHair();

	int GetCenterX();
	int GetCenterY();
	int GetCrosshairHalfSize();
	int GetCrosshairMaxOpen();
	float GetCrosshairOpen();
	void SetCenterX(int Value);
	void SetCenterY(int Value);
	void SetCrosshairHalfSize(int Value);
	void SetCrosshairMaxOpen(int Value);
	void SetCrosshairOpen(float Value);
};
