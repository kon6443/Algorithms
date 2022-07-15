// standard input and output
#include <stdio.h>

// srand
#include <stdlib.h>

// time
#include <time.h>

// 2^8
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

	heap[++heap_count] = data;

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

	// Reconstructing tree structure after popping a root node.
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

        printf("Pushing random numbers repeatedly into a max heap: \n");
	for (int i=0; i<ARRAY_SIZE; i++) push(arr[i]);
	for (int i=0; i<ARRAY_SIZE; i++) printf("%d ", arr[i]);
	printf("\n\n");

	// Descending order
	printf("Popping max heap: \n");
	for (int i=0; i<ARRAY_SIZE; i++) printf("%d ", pop());
	printf("\n");

	return 0;
}

