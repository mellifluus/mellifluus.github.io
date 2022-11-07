void bubbleSort(int array[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int swaps = 0;
    for (int j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        swap(array[j], array[j + 1]);
        swaps++;
      }
    }
    if (swaps == 0) {
      return;
    }
  }
}