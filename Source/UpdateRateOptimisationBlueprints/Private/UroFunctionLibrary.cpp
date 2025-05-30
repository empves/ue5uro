// /* * Copyright (C) 2023 Emptyvessel * * All rights reserved. No part of this software may be reproduced, distributed, * or transmitted in any form or by any means, including photocopying, recording, * or other electronic or mechanical methods, without the prior written permission * of the copyright holder. * */


#include "UroFunctionLibrary.h"

#include "UpdateRateOptimisationBlueprints.h"

void UUroFunctionLibrary::DumpURO(const AActor* Subject)
{
	if (!Subject)
	{
		return;
	}
	UE_LOG(LogUro, Log, TEXT("==== URO info on subjects: %s"), *Subject->GetHumanReadableName());
	TArray<USkeletalMeshComponent*> SkeletalMeshComponents;
	Subject->GetComponents<USkeletalMeshComponent>(SkeletalMeshComponents);
	for (USkeletalMeshComponent* SkeletalMeshComponent : SkeletalMeshComponents)
	{
		if (!SkeletalMeshComponent)
		{
			continue;
		}
		UE_LOG(
			LogUro,
			Log,
			TEXT("%s: tick(%d), uro(%d), MaxDistanceFactor(%f), rate(%d)"),
			*SkeletalMeshComponent->GetName(),
			SkeletalMeshComponent->IsComponentTickEnabled(),
			SkeletalMeshComponent->bEnableUpdateRateOptimizations,
			SkeletalMeshComponent->MaxDistanceFactor,
			SkeletalMeshComponent->AnimUpdateRateParams->UpdateRate
		);
	}
}

void UUroFunctionLibrary::EnableDefaultURO(const AActor* Subject)
{
	TArray<USkeletalMeshComponent*> SkeletalMeshComponents;
	Subject->GetComponents<USkeletalMeshComponent>(SkeletalMeshComponents);
	if (SkeletalMeshComponents.IsEmpty())
	{
		return;
	}
	UE_LOG(LogUro, Log, TEXT("Enable uro with default setting on subject: %s"), *Subject->GetHumanReadableName());
	for (USkeletalMeshComponent* SkeletalMeshComponent : SkeletalMeshComponents)
	{
		SkeletalMeshComponent->bEnableUpdateRateOptimizations = true;	
	}
}

void UUroFunctionLibrary::EnableUROWithDetails(const AActor* Subject)
{
	TArray<USkeletalMeshComponent*> SkeletalMeshComponents;
	Subject->GetComponents<USkeletalMeshComponent>(SkeletalMeshComponents);
	if (SkeletalMeshComponents.IsEmpty())
	{
		return;
	}
	UE_LOG(LogUro, Log, TEXT("Enable uro with detailed settings on subject: %s"), *Subject->GetHumanReadableName());
	for (USkeletalMeshComponent* SkeletalMeshComponent : SkeletalMeshComponents)
	{
		SkeletalMeshComponent->bEnableUpdateRateOptimizations = true;
		SkeletalMeshComponent->AnimUpdateRateParams->bShouldUseLodMap = false;
		SkeletalMeshComponent->AnimUpdateRateParams->bInterpolateSkippedFrames = true;
		
		SkeletalMeshComponent->AnimUpdateRateParams->BaseVisibleDistanceFactorThesholds.Add(0.4f);
		SkeletalMeshComponent->AnimUpdateRateParams->BaseVisibleDistanceFactorThesholds.Add(0.2f);

		SkeletalMeshComponent->AnimUpdateRateParams->MaxEvalRateForInterpolation = 6;
		SkeletalMeshComponent->AnimUpdateRateParams->BaseNonRenderedUpdateRate = 15;
	}
}
