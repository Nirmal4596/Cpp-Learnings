#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

struct linkedListNode
{
	int nData;
	struct linkedListNode* pNext;
}; 

struct linkedListNode *m_pHead = NULL;

void createListNode(int data)
{
	struct linkedListNode *pNode = NULL, *pNewNode = NULL;
	pNewNode = (struct linkedListNode*)malloc(sizeof(struct linkedListNode) * 1);
	
	if (pNewNode)
	{
		pNewNode->nData = data;
		pNewNode->pNext = NULL;

		if (m_pHead == NULL)
			m_pHead = pNewNode;
		else
		{
			pNode = m_pHead;
			while (pNode->pNext != NULL)
				pNode = pNode->pNext;
			pNode->pNext = pNewNode;
		}
	}

	return;
}

void InsertNodeInTheList(int data, int position)
{
	int nCount = 0;
	struct linkedListNode * pNewNode = NULL;
	pNewNode = (struct linkedListNode*)malloc(sizeof(struct linkedListNode) * 1);
	pNewNode->nData = data;
	pNewNode->pNext = NULL;
	
	if (position == 1) //Insertion at start
	{
		pNewNode->pNext = m_pHead;
		m_pHead = pNewNode;
	}
	else
	{
		struct linkedListNode *pNxt_Node = NULL, *pCurrentNode = NULL;
		pCurrentNode = m_pHead;
		nCount = 1;
		while (pNxt_Node = pCurrentNode->pNext)
		{
			nCount++;
			if (nCount == position) //Insertion at middle
			{
				pNewNode->pNext = pCurrentNode->pNext;
				pCurrentNode->pNext = pNewNode;
				break;
			}
			else
				pCurrentNode = pNxt_Node;

			if (!pCurrentNode->pNext) //Insertion at end
			{
				pCurrentNode->pNext = pNewNode;
				break;
			}
		}
	}

	return;
}

void deleteNodeFromList(int data)
{
	struct linkedListNode *pCurrentNode = NULL, *pPrevNode = NULL;
	pCurrentNode = m_pHead;
	pPrevNode = NULL;

	while (pCurrentNode)
	{
		if (pCurrentNode->nData == data)
		{
			if (pPrevNode == NULL)
				m_pHead = pCurrentNode->pNext;
			else
				pPrevNode->pNext = pCurrentNode->pNext;
			free(pCurrentNode);
			break;
		}
		else
		{
			pPrevNode = pCurrentNode;
			pCurrentNode = pCurrentNode->pNext;
		}
	}
	return;
}

void mainTest()
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
	struct linkedListNode *pNode = m_pHead;
	while (pNode)
	{
		printf("\n%d", pNode->nData);
		pNode = pNode->pNext;
	}

	//Insertion
	int nDataToInsert = 0, nPositionToInsert = 0;
	printf("\nEnter data to be inserted:");
	scanf("%d", &nDataToInsert);
	printf("\nEnter position to insert:");
	scanf("%d", &nPositionToInsert);
	InsertNodeInTheList(nDataToInsert, nPositionToInsert);
	//Insertion completed

	//Deletion
	int nDataToDel = 0;
	printf("\nEnter data to be deleted:");
	scanf("%d", &nDataToDel);
	deleteNodeFromList(nDataToDel);
	
	//Printing the final data
	printf("\Final Data:\n");
	pNode = m_pHead;
	while (pNode)
	{
		printf("\n%d", pNode->nData);
		pNode = pNode->pNext;
	}

	//Freeing memory
	pNode = m_pHead;
	struct linkedListNode* pNextNode = NULL;
	while (pNode)
	{
		pNextNode = pNode->pNext;
		free(pNode);
		pNode = pNextNode;
	}

	return;
}