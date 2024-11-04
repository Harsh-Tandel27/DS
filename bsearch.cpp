#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[10];
    int target, result;

    printf("Enter 10 sorted values:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter a value to search: ");
    scanf("%d", &target);

    result = binarySearch(arr, 10, target);
    if (result != -1) {
        printf("Value %d found at position: %d\n", target, result + 1);
    } else {
        printf("Value %d not found in the array.\n", target);
    }

    return 0;
}
