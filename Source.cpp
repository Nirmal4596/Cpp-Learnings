#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits>

bool checkIfEndPointReached(const double dXpoint, const double dYpoint, const double dXEndPoint, const double dYEndPoint)
{
	//DBL_EPSILON  is the smallest value that differentiates 2 double values.
	if ((abs(dXpoint-dXEndPoint) < (DBL_EPSILON* dXEndPoint)) && (abs(dYpoint - dYEndPoint) < (DBL_EPSILON* dYEndPoint)))
		return true;
	else if (((dXpoint - dXEndPoint) > (DBL_EPSILON * dXEndPoint)) || ((dYpoint - dYEndPoint) > (DBL_EPSILON * dYEndPoint)))
		return false;
	else
		return (checkIfEndPointReached(dXpoint + dYpoint, dYpoint, dXEndPoint, dYEndPoint) || checkIfEndPointReached(dXpoint, dYpoint + dXpoint, dXEndPoint, dYEndPoint));

	return false;
}

void main()
{
	double dXpoint = 0.0, dYpoint = 0.0, dXEndPoint = 0.0, dYEndPoint = 0.0;
	printf("\nEnter start point:\n");
	scanf("%lf%lf", &dXpoint, &dYpoint);
	printf("\nEnter end point:\n");
	scanf("%lf%lf", &dXEndPoint, &dYEndPoint);

	if (dXpoint < 0 || dYpoint < 0 || dXEndPoint < 0 || dYEndPoint < 0)
	{
		printf("\nThe start and end point should be in the positive quadrant");
		return;
	}

	if (dXpoint < DBL_EPSILON && dYpoint < DBL_EPSILON)
	{
		printf("\nOrigin can't be the start point");
		return;
	}

	if (checkIfEndPointReached(dXpoint + dYpoint, dYpoint, dXEndPoint, dYEndPoint) || checkIfEndPointReached(dXpoint, dYpoint + dXpoint, dXEndPoint, dYEndPoint))
		printf("\nEnd point reached");
	else
		printf("\nEnd point can't be reached");
	return;
}