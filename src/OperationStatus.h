#ifndef OperationStatusH
#define OperationStatusH

#include "vcl.h"

struct operationStatus
{
	UnicodeString currentOperationName;
	float currentOperationProgress;
	float overallProgress;
	int status; // 0 - in progress, 1 - finished, 2 - error (currentOperationName has description)
};

#endif
