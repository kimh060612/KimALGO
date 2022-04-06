#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList<int> L;

	L.addNode(5);
	L.addNode(4);
	L.addNode(3);
	L.addNode(2);
	L.addNode(1);
	L.insertNode(7, 3);

	for (int i = 0; i < 6; i++)
	{
		cout << L.getNode(i) << endl;
	}

	return 0;
}