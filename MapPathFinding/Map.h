#ifndef _MAP_H
#define _MAP_H

#include "Node.h"
#include <vector>

using namespace std;

class Map
{
private:
	int m_nMapSide;
	vector<Node*> m_pMapNode;

public:
	bool SetNodeInMap(int nNodeSign);
	bool SetChildNodeToParent(int nParentNode, int nChildNode);
	bool SetChildrenNodeToParent(int nParentNode, vector<int> vecChildNode);

	bool BFSFindSideFormStartToEnd(int nStart, int nEnd, vector<int>& vecPath);

	void DeleteNodeBySign(int nSign);
	void Show();

	vector<int> GetNodeByPathLength(int nStart, int nPathLength);

	Map(int nNodeNum, int nMapSide);
	Map();
	virtual ~Map();

private:
	Node& GetNodeBySign(int nSign);
	void _setPath(vector<int> vecHeap, vector<int>& vecPath);
};

#endif // !_MAP_H

