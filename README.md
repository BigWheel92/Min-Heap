# Min-Heap
Implementation of min Heap data structure in C++ using dynamic arrays.

The following methods are available in the public interface of Min Heap

-> MinHeap()

-> MinHeap(int _capacity)  :   assigns a capacity of given size to the heap.

-> void insert(k const key, v const value)  : insert a new <key,value> pair in the heap. The key will be used to maintain heap ordering.

-> void getMin(v & value)  : returns the value whose key is minimum via the parameter passed by reference.

-> void deleteMin()  :   deletes the heap item whose key is minimum

-> bool isEmpty() const  : returns true if the heap has no item, else false

-> void deleteAll()  : completely destroys the heap. The capacity is set to 0. and the array in the heap is set to nullptr.

-> ~MinHeap() :  destructor


The following private methods are available:

-> void doubleCapacity()  : doubles the capacity of heap. For example, if the current capacity of heap is 10, then after calling this function, the capacity will become 20. This method is used by insert method to increase the capacity when the heap is full.

-> void shiftUp(int index)  :  It is a recursive method that, in a single recursive call, shifts the item stored at given index one step up if its key is smaller than the key of its parent. Insert method uses this method to recursivley shift the new item to the root if its key is minimum.

-> void shiftDown(int index)   :  It is a recursive method that, in a single recursive call, shifts the item stored at given index one step down if its key is smaller than the key of any of its children. deleteMin method uses this method. To delete the minimum item (the one at index 0), deleteMin method first moves the last item to index 0, and then it calls shiftDown method to recursively move down the last item to its appropriate location. 
