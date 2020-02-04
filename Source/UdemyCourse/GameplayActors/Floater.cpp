// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh"));

	InitialLocation = FVector(0.0f);
	PlacedLocation = FVector(0.0f);
	WorldOrigin = FVector(0.0f, 0.0f, 0.0f);

	InitialDirection = FVector(0.0f, 0.0f, 0.0f);

	bInitializedFloaterLocation = false;
	bShouldFloat = false;

	InitialForce = FVector(200000.f, 0.0f, 0.0f);
	InitialTorque = FVector(200000.f, 0.0f, 0.0f);

	RunningTime = 0.f;

	A = 1.f;
	B = 1.f;
	C = 1.f;

}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();

	float InitialX = FMath::FRandRange(-500.f,500.f);
	float InitialY = FMath::FRandRange(-500.f,500.f);
	float InitialZ = FMath::FRandRange(-500.f,500.f);

	InitialLocation.X = InitialX;
	InitialLocation.Y = InitialY;
	InitialLocation.Z = InitialZ;

	//InitialLocation *= 10.f;


	PlacedLocation = GetActorLocation();

	if (bInitializedFloaterLocation)
	{
		SetActorLocation(InitialLocation);
	}

	SetActorLocation(InitialLocation);
	
	FHitResult HitResult;

	//StaticMesh->AddForce(InitialForce);
	//StaticMesh->AddTorque(InitialTorque);

	//FVector LocalOffset = FVector(200.f, 0.0f, 0.0f);

	//FRotator Rotation = FRotator(30.0f,0.0f,0.0f);

	//AddActorLocalRotation(Rotation);
	//AddActorLocalOffset(LocalOffset, false, &HitResult);
}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bShouldFloat)
	{
		//FHitResult HitResult;
		//AddActorLocalOffset(InitialDirection, false, &HitResult);
		FVector NewLocation = GetActorLocation();
		
		NewLocation.Z = NewLocation.Z + A*FMath::Sin(B*RunningTime) + C;

		SetActorLocation(NewLocation);

		RunningTime += DeltaTime;

	}
}

