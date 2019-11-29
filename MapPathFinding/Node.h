#ifndef _NODE_H
#define _NODE_H

#include <iostream>
#include <vector>

using namespace std;

class Node
{
private:
	int m_nNodeSign;
	int m_nNodeNum;
	Node* m_pParentNode;
	Node** m_ppNode;

public:
	const int GetNodeSign() const;
	const int GetNodeNum() const;
	bool FindNode(int nNodeSign) const;
	bool SetChildNode(Node& nChildNode);
	bool SetChildrenNode(Node* pChildrenNode, int nChildNum);
	const vector<int> GetChildeNode() const;

	void SetParentNode(Node& nodeParent);
	void InitParentNode();
	void DeleteNode(int nSign);

	Node* GetParentNode();

	Node(int nSign, int nNodeNum);
	Node();
	Node(int nSign);
	virtual ~Node();
};


#endif // !NODE_H

