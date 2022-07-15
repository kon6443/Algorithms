// standard input and output
#include <stdio.h>

// srand
#include <stdlib.h>

// time
#include <time.h>

#define HEAP_SIZE 256
#define ARRAY_SIZE 10

using namespace std;

int heap[HEAP_SIZE];

// heap count is representing that the number of indices and the end index number of a heap DS.
int heap_count = 0; 

void swap(int * a, int * b) {
	int temp = *a; 
	*a = *b; 
	*b = temp;
}

void init() {
	heap_count = 0;
}

int size() {
	return heap_count;
}

void push(int data) {

	// 힙의 가장 끝에 데이터 추가
	heap[++heap_count] = data;

	// 아래의 과정은 child를 parent와 비교하면서 알맞은 위치로 하나씩 올리는 부분
	int child = heap_count;
	int parent = child / 2;
	while (child > 1 && heap[parent] < heap[child]) {
		swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child / 2;
	}

}

int pop() {

    // returning the first element of a heap DS.
	int result = heap[1];

	swap(&heap[1], &heap[heap_count]);
	heap_count--;

	// 아래의 과정은 child를 parent와 비교하면서 알맞은 위치로 하나씩 내리는 부분
	int parent = 1;
	int child = parent * 2;
	if (child + 1 <= heap_count) {
		child = (heap[child] > heap[child + 1]) ? child : child + 1;
	}

	while (child <= heap_count && heap[parent] < heap[child]) {
		swap(&heap[parent], &heap[child]);

		parent = child;
		child = child * 2;
		if (child + 1 <= heap_count) {
			child = (heap[child] > heap[child + 1]) ? child : child + 1;
		}
	}
	return result;
}

int main() {

	int arr[ARRAY_SIZE];
	
	srand(time(NULL));

    // Generating random number from 1 to 50.
	for (int i = 0; i < ARRAY_SIZE; i++) arr[i] = rand() % 50 + 1;

    printf("Pushing into a max heap: \n");
	for (int i=0; i<ARRAY_SIZE; i++) push(arr[i]);
	for (int i=0; i<ARRAY_SIZE; i++) printf("%d ", arr[i]);
	printf("\n\n");

	// Descending order
	printf("Popping max heap: \n");
	for (int i=0; i<ARRAY_SIZE; i++) printf("%d ", pop());
	printf("\n");

	return 0;
}

