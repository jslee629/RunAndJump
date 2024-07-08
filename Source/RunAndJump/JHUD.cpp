#include "JHUD.h"
#include "Global.h"
#include "Engine/Canvas.h"
#include "Components/TextBlock.h"

AJHUD::AJHUD()
{
	TutorialText = "Test";
	ShowTime = 1.f;
	TextScale = 1.f;
}

void AJHUD::BeginPlay()
{
	Super::BeginPlay();
}

void AJHUD::DrawHUD()
{
	Super::DrawHUD();

	DrawText(TutorialText, FLinearColor::Red, X, Y, 0, TextScale);
}

void AJHUD::SaveText(FString InText)
{
	TutorialText = InText;
	UKismetSystemLibrary::K2_SetTimer(this, "DeleteText", ShowTime, false);
}

void AJHUD::DeleteText()
{
	TutorialText = "";
}