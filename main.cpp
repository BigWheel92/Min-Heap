 #include <iostream>
using namespace std;
#include "MinHeap.h"



int main()
{
	MinHeap<int, int> a; //both key and value are of type int. However, they can be of different type.


	for (int i = 1; i <= 200; i++)
		a.insert(i, i);
	
	a.deleteAll();
	
	for (int i = 201; i <= 300; i++)
		a.insert(i, i);

	while (!a.isEmpty())
	{
		int s;
		a.getMin(s);
		cout << s << endl;
		a.deleteMin();
	}


}
