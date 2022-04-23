// Fill out your copyright notice in the Description page of Project Settings.

#include "AI_Experiments.h"
#include "AIPatrolController.h"
#include "AIPatrol.h"
#include "AIPatrolPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Kismet/GameplayStatics.h"

AAIPatrolController::AAIPatrolController()
{
	//Initialize Blackboard & Behavior Tree Component
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behavior Tree Component"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard Component"));

	//Initialize Blackboard Keys
	LocationToGoKey = "LocationToGo";
	PlayerKey = "Target";

	CurrentPatrolPoint = 0;
}

void AAIPatrolController::SetPlayerCaught(APawn* MyPawn)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject(PlayerKey, MyPawn);

	}
}


void AAIPatrolController::OnPossess(APawn* MyPawn)
{
	Super::OnPossess(MyPawn);

	//Get ref to character
	AAIPatrol* AICharacter = Cast<AAIPatrol>(MyPawn);

	if (AICharacter)
	{
		if (AICharacter->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*(AICharacter->BehaviorTree->BlackboardAsset));
		}

		//Populate patrol point array
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAIPatrolPoint::StaticClass(), PatrolPoints);

		BehaviorComp->StartTree(*AICharacter->BehaviorTree);
	}
}
