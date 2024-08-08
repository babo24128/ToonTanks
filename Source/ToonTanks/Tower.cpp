// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ��ũ������ �Ÿ� ���ϱ�
	if (Tank)
	{
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
	
		// ��ũ�� �����Ÿ��� �ִ��� Ȯ��
		if (Distance <= FireRange)
		{
			// �����Ÿ� ���� ������ ��ž�� ��ũ�� ���� ȸ��
			RotateTurret(Tank->GetActorLocation());
		}


	}

}

void ATower::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}
