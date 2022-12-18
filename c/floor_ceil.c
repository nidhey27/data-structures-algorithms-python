#include <stdio.h>

int ceiling(int arr[], int len, int target) {

  int start = 0;
  int end = len - 1;

  while (start <= end) {
    int mid = (start + end) / 2;

    if (target > arr[mid]) {
      start = mid + 1;
    } else if (target < arr[mid]) {
      end = mid - 1;
    } else {
      return mid;
    }
  }
  return start;
}

int flooor(int arr[], int len, int target) {
  int start = 0;
  int end = len - 1;

  while (start <= end) {
    int mid = (start + end) / 2;

    if (target > arr[mid]) {
      start = mid + 1;
    } else if (target < arr[mid]) {
      end = mid - 1;
    } else {
      return mid;
    }
  }
  return end;
}

int main() {
  int target = 15;
  int arr[] = {2, 3, 4, 6, 14, 16, 17, 18};
  int length = sizeof(arr) / sizeof(arr[0]);
  printf("Ceil: %d\n", arr[ceiling(arr, length, target)]);
  printf("Floor: %d\n", arr[flooor(arr, length, target)]);

  return 0;
}