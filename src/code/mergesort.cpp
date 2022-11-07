void merge(int arr[], int left, int middle, int right)
{
    int sizeLeft = middle - left + 1;
    int sizeRight = right - middle;

    int tmpLeft[sizeLeft], tmpRight[sizeRight];

    for (int i = 0; i < sizeLeft; i++) {
        tmpLeft[i] = arr[left + i];
    }
    for (int j = 0; j < sizeRight; j++) {
        tmpRight[j] = arr[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while (i < sizeLeft && j < sizeRight) {
        if (tmpLeft[i] <= tmpRight[j]) {
            arr[k] = tmpLeft[i];
            i++;
        }
        else {
            arr[k] = tmpRight[j];
            j++;
        }
        k++;
    }
    while (i < sizeLeft) {
        arr[k] = tmpLeft[i];
        i++;
        k++;
    }
    while (j < sizeRight) {
        arr[k] = tmpRight[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}