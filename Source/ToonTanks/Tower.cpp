// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 탱크까지의 거리 구하기
	if (Tank)
	{
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
	
		// 탱크가 사정거리에 있는지 확인
		if (Distance <= FireRange)
		{
			// 사정거리 내에 있으면 포탑을 탱크를 향해 회전
			RotateTurret(Tank->GetActorLocation());
		}


	}

}

void ATower::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}
