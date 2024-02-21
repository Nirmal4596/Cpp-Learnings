//#include "./../../List.c"
#include "List.c"
int main()
{
	int nNumData = 0;
	m_pHead = NULL;

	printf("\nEnter number of data to be added: ");
	scanf("%d", &nNumData);

	for (int i = 0; i < nNumData; i++)
	{
		int tempData = 0;
		printf("\nEnter data no. %d: ", i + 1);
		scanf("%d", &tempData);

		createListNode(tempData);
	}

	//Printing the input data
	printf("\Input Data:\n");
	struct linkedListNode* pNode = m_pHead;
	while (pNode)
	{
		printf("\n%d", pNode->nData);
		pNode = pNode->pNext;
	}

	struct linkedListNode *pPrevNode = NULL, *pNextNode = NULL, *pCurrentNode = NULL;
	bool bEndReached = false;
	//Reversing list
	pPrevNode = NULL;
	pCurrentNode = m_pHead;

	while (pCurrentNode)
	{
		if (pPrevNode == NULL)
		{
			pPrevNode = pCurrentNode;
			pCurrentNode = pCurrentNode->pNext;
			pPrevNode->pNext = NULL;
		}
		else
		{
			if (pCurrentNode->pNext == NULL)
				bEndReached = true;

			pNextNode = pCurrentNode->pNext;
			pCurrentNode->pNext = pPrevNode;
			pPrevNode = pCurrentNode;
			pCurrentNode = pNextNode;
		}

		if (bEndReached)
		{
			m_pHead = pPrevNode;
			break;
		}
	}

	//Printing the output list 
	printf("\nList after reversal:\n");
	pNode = m_pHead;
	while (pNode)
	{
		printf("\n%d", pNode->nData);
		pNode = pNode->pNext;
	}
}