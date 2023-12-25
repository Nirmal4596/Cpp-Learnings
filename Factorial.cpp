#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#define Max_Digits 5e5

int Factorial(int nFactorialStartValue, int nFactorialEndValue = 1);

int main()
{
	Factorial(100000);
	return 0;
}

int Factorial(int nFactorialStartValue, int nFactorialEndValue)
{
	int* pNumberArray = NULL, * pBackUpArray = NULL;
	int nFactValue = 0, nLastDigitPos = 0, nTempValue = 0, nDigitValue = 0, nPosValue = 0, nMinFactorialValue = nFactorialEndValue;

	clock_t t = clock();

	//pNumberArray = (int*)malloc(sizeof(int) * Max_Digits);
	//pBackUpArray = (int*)malloc(sizeof(int) * Max_Digits);
	pNumberArray = (int*)calloc(Max_Digits, sizeof(int));
	pBackUpArray = (int*)calloc(Max_Digits, sizeof(int));

	// Filling the initial value on to the array
	nTempValue = nFactValue = nFactorialStartValue * (nFactorialStartValue - 1);
	while (nTempValue  > 0)
	{
		nDigitValue = nTempValue % 10;
		pNumberArray[nPosValue] = nDigitValue;
		pBackUpArray[nPosValue] = nDigitValue;

		nTempValue /= 10;
		nPosValue++;
	}

	// Loop for Finding factorial
	for (int i = nFactorialStartValue - 2; i > nMinFactorialValue; i--)
	{
		int nPosOfMultiplier = 0, nMaxPos = nPosValue;
		nTempValue = i;
		while (nTempValue > 0)
		{
			int nMultipler = nTempValue % 10, nCarryOver = 0;
			for (int j = 0; j < nMaxPos; j++)
			{
				int nValue = 0, nDigit = 0;
				if (nPosOfMultiplier == 0 )
				{
					nValue = pBackUpArray[j] * nMultipler + nCarryOver;
					pNumberArray[j] = nValue % 10;
					nCarryOver = nValue / 10;
				}
				else 
				{
					int nAdditionCarryOver = 0;
					nValue = pBackUpArray[j] * nMultipler + nCarryOver;
					nDigit = nValue % 10;
					nCarryOver = nValue / 10;
					
					if (nAdditionCarryOver = ((pNumberArray[j + nPosOfMultiplier] + nDigit) / 10))
					{
						pNumberArray[j + nPosOfMultiplier] = (pNumberArray[j + nPosOfMultiplier] + nDigit) % 10;
						nCarryOver += nAdditionCarryOver;
					}
					else
						pNumberArray[j + nPosOfMultiplier] += nDigit;
					
					if ((j + nPosOfMultiplier) >= nPosValue)
						nPosValue++;
				}

				if (nCarryOver > 0 && j == (nMaxPos - 1))
				{
					pNumberArray[j+ nPosOfMultiplier+1] = nCarryOver;
					nPosValue++;
					nCarryOver = 0;
				}
			}

			nPosOfMultiplier++;
			nTempValue /= 10;
		}
		// Updating the computed value so that i can be used to mutiply the next value. 
		for (int k = 0; k < nPosValue; k++)
			pBackUpArray[k] = pNumberArray[k];
	}

	t = clock() - t;
	printf("\nTime: %f\n", (float)t / CLOCKS_PER_SEC);
	printf("\n\n\nCount: %d", nPosValue);

	FILE* fp = fopen("factorialValue.py", "w");
	fprintf(fp, "%s", "a=\"");
	for (int k = nPosValue-1; k >= 0; k--)
	{
		fprintf(fp, "%d", pNumberArray[k]);
		//printf("%d", pNumberArray[k]);
	}
	fprintf(fp, "%s", "\"");
	
	fclose(fp);

	return 0;
}