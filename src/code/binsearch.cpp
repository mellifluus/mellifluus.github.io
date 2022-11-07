int binarySearch(int array[], int left, int right, int x) {
  if (right >= left) {
    int middle = (left + (right - left)) / 2;

    if (array[middle] == x) {
      return middle;
    }

    if (array[middle] > x) {
      return binarySearch(array, left, middle - 1, x);
    }
    
    return binarySearch(array, x, middle + 1, right);
  }
  return -1;
}