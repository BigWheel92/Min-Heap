#pragma once
#include <assert.h>
#include <algorithm>


template <typename k, typename v>
class MinHeap
{
	//each item in heap will be HeapItem (a <key, value> pair). Both key and value can be of the same datatype or different data type.
	// Key and value can be of a user-defined class as well. If key is of non-primitive datatype, then the > and < operators must be overloaded.
	struct HeapItem
	{
		k key;
		v value;
	};


private:

	HeapItem *arr;
	int capacity;
	int totalItems;

	void doubleCapacity()
	{
		if (this->arr==nullptr)
		{
			this->arr = new HeapItem[1];
			this->capacity = 1;
			return;
		}

		int newCapacity = capacity*2;
		HeapItem *newArr = new HeapItem[newCapacity];

		for (int i = 0; i < this->totalItems; i++)
		{
			newArr[i] = this->arr[i];
		}

		if (this->arr!=nullptr)
		delete this->arr;

		this->capacity = newCapacity;
		this->arr = newArr;
		

	}

	void shiftUp(int index)
	{
		if (index < 1)
			return;

		int parent = (index-1) / 2;

		if (this->arr[index].key < this->arr[parent].key)
			swap(this->arr[index], this->arr[parent]);

		shiftUp(parent);

	}

	void shiftDown(int index)
	{
		int minIndex = -1;
		int lChildIndex = index * 2+1;
		int rChildIndex = (index * 2) + 2;

		if (lChildIndex < totalItems)
		{
			if (arr[index].key > arr[lChildIndex].key)
			{
				minIndex = lChildIndex;
			}
		}

		if (rChildIndex < totalItems)
		{
			if (arr[(minIndex == -1 ? index : minIndex)].key > arr[rChildIndex].key)
			{
				minIndex = rChildIndex;
			}
		}

		if (minIndex == -1)
			return;

		swap(arr[index], arr[minIndex]);
		shiftDown(minIndex);


	}

public:
	MinHeap()
	{
		this->arr = nullptr;
		this->capacity = 0;
		this->totalItems = 0;
	}

	MinHeap(int _capacity)
	{
		assert(_capacity >= 1);

		this->arr = new HeapItem[_capacity];
		this->capacity = _capacity;
		this->totalItems = 0;
	}

	void insert(k const key, v const value)
	{
		if (this->totalItems == this->capacity)
		{
			doubleCapacity();
		}
	
		
		this->arr[totalItems].key = key;
		this->arr[totalItems].value = value;


		shiftUp(totalItems);
		this->totalItems++;

		//iterative shift up
		//for (int i =this->totalItems; i >= 2 && (this->arr[i].key < this->arr[i / 2].key); i=i/ 2)
		//{
		//	swap(this->arr[i], this->arr[i / 2]);
		//}

	}



	void getMin(v & value)
	{
		assert(totalItems != 0);

		value = this->arr[0].value;
	}

	void deleteMin()
	{
		assert(totalItems != 0);

		swap(arr[0], arr[this->totalItems-1]);

		totalItems--;

		//shift down
		shiftDown(0);
	}
	
	bool isEmpty() const
	{
		return (totalItems == 0);
	}

	

	void deleteAll()
	{
		if (this->arr != nullptr)
		{
			delete[]arr;
			arr = nullptr;
			this->capacity = 0;
			this->totalItems = 0;
		}
		
	}

	~MinHeap()
	{
		deleteAll();
	}

};