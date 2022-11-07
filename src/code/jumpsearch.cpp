int jumpSearch(int arr[], int x, int size) {
  int currentIndex = sqrt(size);
  int prev = 0;

  while (arr[min(currentIndex, size) - 1] < x) {
    prev = currentIndex;
    if (prev >= size) {
      return -1;
    }
    currentIndex += sqrt(size);
  }

  while (arr[prev] < x) {
    prev++;
    if (prev == min(currentIndex, size)) {
      return -1;
    }
  }

  if (arr[prev] == x) {
    return prev;
  }

  return -1;
}