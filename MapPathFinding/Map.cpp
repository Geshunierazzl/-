#include "Map.h"
#include <iostream>

using namespace std;

bool Map::SetNodeInMap(int nNodeSign)
{
	Node* newNode = new Node(nNodeSign, m_nMapSide);
	m_pMapNode.push_back(newNode);
	return true;
}

bool Map::SetChildNodeToParent(int nParentNode, int nChildNode)
{
	int nParentPos = -1;
	int nChildPos = -1;
	for (int i = 0; i < m_pMapNode.size(); i++)
	{
		if (m_pMapNode[i]->GetNodeSign() == nParentNode)
		{
			nParentPos = i;
			break;
		}
	}

	for (int i = 0; i < m_pMapNode.size(); i++)
	{
		if (m_pMapNode[i]->GetNodeSign() == nChildNode)
		{
			nChildPos = i;
			break;
		}
	}

	if (nParentPos == -1 || nChildPos == -1 || nParentPos == nChildPos)
	{
		return false;
	}
	else
	{
		m_pMapNode[nParentPos]->SetChildNode(*m_pMapNode[nChildPos]);
		return true;
	}
}

bool Map::SetChildrenNodeToParent(int nParentNode, vector<int> vecChildNode)
{
	for (int i = 0; i < vecChildNode.size(); i++)
	{
		if (!SetChildNodeToParent(nParentNode, vecChildNode[i]))
		{
			return false;
		}
	}
	return true;
}

bool Map::BFSFindSideFormStartToEnd(int nStart, int nEnd, vector<int>& vecPath)
{
	vecPath.clear();
	vector<int> mecNodeHeap ;
	int nCurrentNode = 0;
	int nStartPos = -1;
	int nEndPos = -1;
	for (int i = 0; i < m_pMapNode.size(); i++)
	{
		if (m_pMapNode[i]->GetNodeSign() == nStart)
		{
			nStartPos = i;
			break;
		}
	}
	for (int i = 0; i < m_pMapNode.size(); i++)
	{
		if (m_pMapNode[i]->GetNodeSign() == nEnd)
		{
			nEndPos = i;
			break;
		}
	}
	if (nStartPos == -1 || nEndPos == -1)
	{
		return false;
	}

	if (nStartPos == nEndPos)
	{
		vecPath.push_back(nStart);
		return true;
	}
	else
	{
		mecNodeHeap.push_back(nStart);
		while (nCurrentNode < mecNodeHeap.size())
		{
			if (GetNodeBySign(mecNodeHeap[nCurrentNode]).FindNode(nEnd))
			{
				GetNodeBySign(nEnd).SetParentNode(GetNodeBySign(mecNodeHeap[nCurrentNode]));
				int nPath = 0;
				vecPath.push_back(nEnd);
				while (GetNodeBySign(vecPath[nPath]).GetParentNode() != NULL)
				{
					vecPath.push_back(GetNodeBySign(vecPath[nPath]).GetParentNode()->GetNodeSign());
					nPath++;
				}
				for (int i = 0; i < mecNodeHeap.size(); i++)
				{
					GetNodeBySign(mecNodeHeap[i]).InitParentNode();
				}
				mecNodeHeap.clear();
				return true;
			}
			vector<int> vecChildNode = GetNodeBySign(mecNodeHeap[nCurrentNode]).GetChildeNode();
			for (int i = 0; i < vecChildNode.size(); i++)
			{
				int nPos = -1;
				for (int k = 0; k < mecNodeHeap.size(); k++)
				{
					if (mecNodeHeap[k] == vecChildNode[i])
					{
						nPos = k;
					}
				}
				if (nPos == -1)
				{
					GetNodeBySign(vecChildNode[i]).SetParentNode(GetNodeBySign(mecNodeHeap[nCurrentNode]));
					mecNodeHeap.push_back(vecChildNode[i]);
				}
			}
			nCurrentNode++;
		}
		mecNodeHeap.clear();
		vecPath.clear();
		return false;
	}
}

void Map::DeleteNodeBySign(int nSign)
{
	int nSignPos = -1;
	for (int i = 0; i < m_pMapNode.size(); i++)
	{
		if (m_pMapNode[i]->FindNode(nSign))
		{
			m_pMapNode[i]->DeleteNode(nSign);
		}
		if (m_pMapNode[i]->GetNodeSign() == nSign)
		{
			nSignPos = i;
		}
	}
	m_pMapNode.erase(m_pMapNode.begin() + nSignPos);
}

void Map::Show()
{
	for (int i = 0; i < m_pMapNode.size(); i++)
	{
		cout << m_pMapNode[i]->GetNodeSign() << " :";
		vector<int> vecChildNode = m_pMapNode[i]->GetChildeNode();
		for (int k = 0; k < vecChildNode.size(); k++)
		{
			cout << " " << vecChildNode[k];
		}
		cout << endl;
	}
}

Map::Map(int nNodeNum, int nMapSide)
{
	m_nMapSide = nMapSide;
	m_pMapNode.clear();
}

Map::Map()
{
	m_nMapSide = 0;
	m_pMapNode.clear();
}

Map::~Map()
{
	for (int i = 0; i < m_pMapNode.size(); i++)
	{
		delete m_pMapNode[i];
	}
	m_pMapNode.clear();
}

Node& Map::GetNodeBySign(int nSign)
{
	for (int i = 0; i < m_pMapNode.size(); i++)
	{
		if (m_pMapNode[i]->GetNodeSign() == nSign)
		{
			return *m_pMapNode[i];
		}
	}
}