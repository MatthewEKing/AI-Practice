// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AIPatrolController.generated.h"

/**
 * 
 */
UCLASS()
class AI_EXPERIMENTS_API AAIPatrolController : public AAIController
{
	GENERATED_BODY()

	//Behavior Tree Component
	UBehaviorTreeComponent* BehaviorComp;

	//Blackboard Component
	UBlackboardComponent* BlackboardComp;

	//Blackboard Keys
	UPROPERTY(EditDefaultsOnly, Category = AI)
	FName LocationToGoKey;

	UPROPERTY(EditDefaultsOnly, Category = AI)
	FName PlayerKey;

	TArray<AActor*> PatrolPoints;

	virtual void OnPossess(APawn* Pawn) override;

public:

	AAIPatrolController();

	void SetPlayerCaught(APawn* Pawn);

	//Inline Getter Functions
	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; };
	FORCEINLINE TArray<AActor*> GetPatrolPoints() const { return PatrolPoints; };

	int32 CurrentPatrolPoint = 0;
	
};
