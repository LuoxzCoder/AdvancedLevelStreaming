#include "DreamGameMode.h"
#include "LevelManager.h"

ADreamGameMode::ADreamGameMode()
	: Super()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ADreamGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	LevelManager = NewObject<ULevelManager>(this);
	LevelManager->Initialize();
}

void ADreamGameMode::StartPlay()
{
	LevelManager->OnStartPlay();
	Super::StartPlay();;
}

void ADreamGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	LevelManager->Tick(DeltaSeconds);
}

