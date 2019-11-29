#include "Node.h"
#include <iostream>

using namespace std;

const int Node::GetNodeSign() const
{
	return this->m_nNodeSign;
}

const int Node::GetNodeNum() const
{
	return this->m_nNodeNum;
}

bool Node::FindNode(int nNodeSign) const
{
	for (int i = 0; i < m_nNodeNum; i++)
	{
		if (m_ppNode[i] != NULL && m_ppNode[i]->GetNodeSign() == nNodeSign)
		{
			return true;
		}
	}
	return false;
}

bool Node::SetChildNode(Node& nChildNode)
{
	for (int i = 0; i < m_nNodeNum; i++)
	{
		if (m_ppNode[i] != NULL && m_ppNode[i]->GetNodeSign() == nChildNode.GetNodeSign())
		{
			return false;
		}
	}

	for (int i = 0; i < m_nNodeNum; i++)
	{
		if (m_ppNode[i] == NULL)
		{
			m_ppNode[i] = &nChildNode;
			return true;
		}
	}

	return false;
}

bool Node::SetChildrenNode(Node* pChildrenNode, int nChildNum)
{
	for (int i = 0; i < nChildNum; i++)
	{
		if (!this->SetChildNode(pChildrenNode[i]))
		{
			return false;
		}
	}
	return true;
}

const vector<int> Node::GetChildeNode() const
{
	vector<int> vecChildNode;
	for (int i = 0; i < m_nNodeNum; i++)
	{
		if (m_ppNode[i] != NULL)
		{
			vecChildNode.push_back(m_ppNode[i]->GetNodeSign());
		}
	}
	return vecChildNode;
}

void Node::SetParentNode(Node& nodeParent)
{
	this->m_pParentNode = &nodeParent;
}

void Node::InitParentNode()
{
	this->m_pParentNode = NULL;
}

void Node::DeleteNode(int nSign)
{
	for (int i = 0; i < m_nNodeNum; i++)
	{
		if (m_ppNode[i] != NULL && m_ppNode[i]->GetNodeSign() == nSign)
		{
			m_ppNode[i] = NULL;
		}
	}
}

Node* Node::GetParentNode()
{
	return this->m_pParentNode;
}

Node::Node(int nSign, int nNodeNum)
{
	m_nNodeSign = nSign;
	m_nNodeNum = nNodeNum;
	m_pParentNode = NULL;
	m_ppNode = new Node * [m_nNodeNum];
	for (int i = 0; i < m_nNodeNum; i++)
	{
		m_ppNode[i] = NULL;
	}
}

Node::Node(int nSign)
{
	Node(nSign, 1);
}

Node::Node()
{
	m_nNodeSign = 0;
	m_nNodeNum = 0;
	m_pParentNode = NULL;
	m_ppNode = NULL;
}

Node::~Node()
{
	for (int i = 0; i < m_nNodeNum; i++)
	{
		m_ppNode[i] = NULL;
		delete m_ppNode[i];
	}
	delete[]m_ppNode;
}