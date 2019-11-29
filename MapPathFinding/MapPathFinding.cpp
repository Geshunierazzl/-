#include <iostream>
#include "Node.h"
#include "Map.h"

using namespace std;

int main()
{
	Map *map = new Map(12, 4);
	for (int i = 1; i < 13; i++)
	{
		if (!map->SetNodeInMap(i))
		{
			cout << "Not set in Map" << endl;
		}
	}
	map->SetChildNodeToParent(1, 2);
	map->SetChildNodeToParent(1, 5);

	map->SetChildNodeToParent(2, 1);
	map->SetChildNodeToParent(2, 6);
	map->SetChildNodeToParent(2, 3);

	map->SetChildNodeToParent(3, 2);
	map->SetChildNodeToParent(3, 4);

	map->SetChildNodeToParent(4, 3);
	map->SetChildNodeToParent(4, 8);

	map->SetChildNodeToParent(5, 1);
	map->SetChildNodeToParent(5, 6);

	map->SetChildNodeToParent(6, 5);
	map->SetChildNodeToParent(6, 2);
	map->SetChildNodeToParent(6, 7);
	map->SetChildNodeToParent(6, 9);

	map->SetChildNodeToParent(7, 6);
	map->SetChildNodeToParent(7, 10);

	map->SetChildNodeToParent(8, 4);
	map->SetChildNodeToParent(8, 11);

	map->SetChildNodeToParent(9, 6);
	map->SetChildNodeToParent(9, 12);

	map->SetChildNodeToParent(10, 7);
	map->SetChildNodeToParent(10, 11);

	map->SetChildNodeToParent(11, 10);
	map->SetChildNodeToParent(11, 8);

	map->SetChildNodeToParent(12, 9);

	map->Show();

	vector<int> vecPath;
	cout << "Map Finding Side:::::" << endl;
	cout << "1----7::::";
	if (map->BFSFindSideFormStartToEnd(1, 7, vecPath))
	{
		cout << "yes.Path is :";
		for (int i = 0; i < vecPath.size(); i++)
		{
			cout << vecPath[i] << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "no." << endl;
	}
	cout << "20----9::::";
	if (map->BFSFindSideFormStartToEnd(20, 9, vecPath))
	{
		cout << "yes." << endl;
	}
	else
	{
		cout << "no." << endl;
	}
	cout << "1----20::::";
	if (map->BFSFindSideFormStartToEnd(1, 20, vecPath))
	{
		cout << "yes." << endl;
	}
	else
	{
		cout << "no." << endl;
	}

	map->DeleteNodeBySign(6);
	cout << "1----7::::";
	if (map->BFSFindSideFormStartToEnd(1, 7, vecPath))
	{
		cout << "yes.Path is :";
		for (int i = 0; i < vecPath.size(); i++)
		{
			cout << vecPath[i] << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "no." << endl;
	}

	map->DeleteNodeBySign(10);
	cout << "1----7::::";
	if (map->BFSFindSideFormStartToEnd(1, 7, vecPath))
	{
		cout << "yes.Path is :";
		for (int i = 0; i < vecPath.size(); i++)
		{
			cout << vecPath[i] << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "no." << endl;
	}
}
