//@author Massimiliano Ricci
#include <iostream>
using namespace std;

void heapifyMax(int arr[], int totalNodes, int index)
{
  int largestIndex = index;
  int leftChild = 2 * index;
  int rightChild = 2 * index + 1;

  if (leftChild < totalNodes && arr[leftChild] > arr[largestIndex]) {
    largestIndex = leftChild;
  }
  if (rightChild < totalNodes && arr[rightChild] > arr[largestIndex]) {
    largestIndex = rightChild;
  }
  if (largestIndex != index) {
    swap(arr[index], arr[largestIndex]);
    heapifyMax(arr, totalNodes, largestIndex);
  }
}

void heapifyMin(int arr[], int totalNodes, int index)
{
  int smallestIndex = index;
  int leftChild = 2 * index;
  int rightChild = 2 * index + 1;

  if (leftChild < totalNodes && arr[leftChild] < arr[smallestIndex]) {
    smallestIndex = leftChild;
  }
  if (rightChild < totalNodes && arr[rightChild] < arr[smallestIndex]) {
    smallestIndex = rightChild;
  }
  if (smallestIndex != index) {
    swap(arr[index], arr[smallestIndex]);
    heapifyMin(arr, totalNodes, smallestIndex);
  }
}

void buildHeap(int arr[], int totalNodes, int lastNonLeafNode) {
  if (arr[0] > 0) {
    for (int i = lastNonLeafNode; i >= 1; i--) {
      heapifyMax(arr, totalNodes, i);
    }
  } else {
    for (int i = lastNonLeafNode; i >= 1; i--) {
      heapifyMin(arr, totalNodes, i);
    }
  }
}

void printHeap(int arr[], int N)
{
    cout << "Array representation of Heap is:\n";
 
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
  int arrMax[] = {999999, 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
  int arrMin[] = {-999999, 17, 15, 8, 9, 10, 13, 6, 4, 5, 3, 1};

  int totalNodesMax = sizeof(arrMax) / sizeof(arrMax[0]);
  buildHeap(arrMax, totalNodesMax, totalNodesMax / 2 - 1);
  
  int totalNodesMin = sizeof(arrMin) / sizeof(arrMin[0]);
  buildHeap(arrMin, totalNodesMin, totalNodesMin / 2 - 1);

  return 0;
}