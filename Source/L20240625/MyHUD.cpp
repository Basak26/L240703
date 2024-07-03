// Fill out your copyright notice in the Description page of Project Settings.

#include "MyHUD.h"
#include "Engine/Canvas.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

AMyHUD::AMyHUD()
{
    CrosshairHalfSize = 15;
    CrosshairMaxOpen = 30;
}

void AMyHUD::DrawHUD()
{
    Super::DrawHUD();

    SetCenterX(Canvas->SizeX / 2);
    SetCenterY(Canvas->SizeY / 2);

    // 폰 찾기
    ACharacter* Character = GetControlledCharacter();
    // 비율 구하기
    float MovementRatio = CalculateMovementRatio(Character);

    // 떨어진 거리 구하기
    SetCrosshairOpen(MovementRatio * CrosshairMaxOpen);

    // 크로스헤어 그리기
    DrawCrossHair();
}

void AMyHUD::DrawCrossHair()
{
    FLinearColor LineColor = FLinearColor::Red;
    float LineThickness = 2.0f;

    // Left
    DrawLine(CenterX - CrosshairHalfSize - CrosshairOpen, CenterY, CenterX - CrosshairOpen, CenterY, LineColor, LineThickness);
    // Right
    DrawLine(CenterX + CrosshairOpen, CenterY, CenterX + CrosshairHalfSize + CrosshairOpen, CenterY, LineColor, LineThickness);
    // Up
    DrawLine(CenterX, CenterY - CrosshairHalfSize - CrosshairOpen, CenterX, CenterY - CrosshairOpen, LineColor, LineThickness);
    // Down
    DrawLine(CenterX, CenterY + CrosshairOpen, CenterX, CenterY + CrosshairHalfSize + CrosshairOpen, LineColor, LineThickness);
}

ACharacter* AMyHUD::GetControlledCharacter()
{
    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

    if (PlayerController)
    {
        APawn* ControlledPawn = PlayerController->GetPawn();
        if (ControlledPawn)
        {
            ACharacter* ControlledCharacter = Cast<ACharacter>(ControlledPawn);
            return ControlledCharacter;
        }
    }

    return nullptr;
}

float AMyHUD::CalculateMovementRatio(ACharacter* Character)
{
    if (Character)
    {
        UCharacterMovementComponent* MovementComponent = Character->GetCharacterMovement();
        if (MovementComponent)
        {
            FVector Velocity = Character->GetVelocity();
            float MaxSpeed = MovementComponent->GetMaxSpeed();

            return Velocity.Size2D() / MaxSpeed;
        }
    }
    return 0.0f;
}

int AMyHUD::GetCenterX()
{
    return CenterX;
}

int AMyHUD::GetCenterY()
{
    return CenterY;
}

int AMyHUD::GetCrosshairHalfSize()
{
    return CrosshairHalfSize;
}

int AMyHUD::GetCrosshairMaxOpen()
{
    return CrosshairMaxOpen;
}

float AMyHUD::GetCrosshairOpen()
{
    return CrosshairOpen;
}

void AMyHUD::SetCenterX(int Value)
{
    CenterX = Value;
}

void AMyHUD::SetCenterY(int Value)
{
    CenterY = Value;
}

void AMyHUD::SetCrosshairHalfSize(int Value)
{
    CrosshairHalfSize = Value;
}

void AMyHUD::SetCrosshairMaxOpen(int Value)
{
    CrosshairMaxOpen = Value;
}

void AMyHUD::SetCrosshairOpen(float Value)
{
    CrosshairOpen = Value;
}