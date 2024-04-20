//////PROBLEM STATEMENT 2
//
//#include<stdio.h>
//#include<stdlib.h>
//
//int* leader(int arr[], int n) {
//    int* leaders = (int*)malloc(n*sizeof(int)); 
//    int maxright = arr[n - 1]; 
//    int count = 0;
//    
//	leaders[count++]=maxright;
//	
//	
//}
// 
//int main() {
//	
//	int i,leaders[30],n;
//    int arr[] = {16, 17, 4, 3, 5, 2};
//    
//	int* leaders = leader(arr, n);
//
//    printf("Leaders in the array: ");
//    for (i = 0; i < n; i++) {
//        printf("%d ", leaders[i]);
//    }
//    printf("\n");
//    
//}

#include <stdio.h>
#include <stdlib.h>

int* leader(int A[], int n) {
	int i;
    int* leaders = (int*)malloc(sizeof(int) * n);
    int max_right = A[n - 1];
    int leader_count = 0;

    for ( i = n - 1; i >= 0; i--) {
        if (A[i] >= max_right) {
            leaders[leader_count++] = A[i];
            max_right = A[i];
        }
    }

    leaders = (int*)realloc(leaders, sizeof(int) * leader_count);

    for ( i = 0; i < leader_count / 2; i++) {
        int temp = leaders[i];
        leaders[i] = leaders[leader_count - i - 1];
        leaders[leader_count - i - 1] = temp;
    }

    return leaders;
}

int main() {
	int i;
    int A[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(A) / sizeof(A[0]);

    int* leaders = leader(A, n);

    printf("Leaders: ");
    for ( i = 0; i < n; i++) {
        printf("%d ", leaders[i]);
    }
    printf("\n");

    free(leaders);
    return 0;
}


