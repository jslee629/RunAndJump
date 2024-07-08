#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "JHUD.generated.h"

/**
 * 
 * This is for UI shows
 * 1. Tutorial Text
 * 2. Progress bar
 * 
 */
UCLASS()
class RUNANDJUMP_API AJHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AJHUD();
	virtual void BeginPlay() override;
	virtual void DrawHUD() override;

	UFUNCTION(BlueprintCallable)
	void SaveText(FString InText);
	UFUNCTION()
	void DeleteText();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "ShowingTime")
	FString TutorialText;
	UPROPERTY(EditDefaultsOnly, Category = "ShowingTime")
	float ShowTime;
	UPROPERTY(EditDefaultsOnly, Category = "ShowingCoord")
	float X;
	UPROPERTY(EditDefaultsOnly, Category = "ShowingCoord")
	float Y;
	UPROPERTY(EditDefaultsOnly, Category = "ShowingCoord")
	float TextScale;
};
