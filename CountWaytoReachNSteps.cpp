#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int nWayToReachNsteps(int nEndStep)
{
	int nMaxJump = 3;
	int *pStepCountArray = NULL;
	pStepCountArray = (int*)malloc(sizeof(int) * (nMaxJump + 1));

	pStepCountArray[0] = 1; //No. of ways to reach 1st step
	pStepCountArray[1] = 2; //No. of ways to reach 2nd step
	pStepCountArray[2] = 4; //No. of ways to reach 3rd step
	pStepCountArray[3] = pStepCountArray[0] + pStepCountArray[1] + pStepCountArray[2];

	for (int i = 3; i < nEndStep; i++)
	{
		pStepCountArray[3] = pStepCountArray[0] + pStepCountArray[1] + pStepCountArray[2];
		pStepCountArray[0] = pStepCountArray[1];
		pStepCountArray[1] = pStepCountArray[2];
		pStepCountArray[2] = pStepCountArray[3];
	}

	switch (nEndStep)
	{
	case 1:
		return pStepCountArray[0];
	case 2:
		return pStepCountArray[1];
	case 3:
		return pStepCountArray[2];
	default:
		return pStepCountArray[3];
	}
	
}

int main()
{
	int nSteps = 0, nWays = 0;
	printf("\nEnter number of steps: ");
	scanf("%d", &nSteps);
	nWays = nWayToReachNsteps(nSteps);
	printf("\nNo. of ways you can reach %d steps is %d", nSteps, nWays);
}