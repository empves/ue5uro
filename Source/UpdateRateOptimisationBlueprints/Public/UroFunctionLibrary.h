// /* * Copyright (C) 2023 Emptyvessel * * All rights reserved. No part of this software may be reproduced, distributed, * or transmitted in any form or by any means, including photocopying, recording, * or other electronic or mechanical methods, without the prior written permission * of the copyright holder. * */

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UroFunctionLibrary.generated.h"

/**
 * public static BP-facing functions for URO configuration and debugging
 */
UCLASS()
class UPDATERATEOPTIMISATIONBLUEPRINTS_API UUroFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * log actor's skeletal mesh component's URO setting
	 */
	static void DumpURO(const AActor* Subject);

	/**
	 * Just enabled URO flag on the sk mesh components
	 * 
	 * @param Subject 
	 */
	static void EnableDefaultURO(const AActor* Subject);

	/**
	 * Enable URO flag and config the distance-based settings
	 *
	 * @param Subject 
	 */
	static void EnableUROWithDetails(const AActor* Subject);
};
