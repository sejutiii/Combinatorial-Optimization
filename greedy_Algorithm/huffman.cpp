#include <iostream>
#include <cstdlib> 
using namespace std;

#define MTH 100

typedef struct node
{
    char key;
    int freq;
    struct node *left;
    struct node *right;
} node;

typedef struct heap
{
    int size;
    int capacity;
    node **array;
} heap;

node *createNode(int freq, char key)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->key = key;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

heap *createHeap(int capacity)
{
    heap *minheap = (heap *)malloc(sizeof(heap));
    minheap->capacity = capacity;
    minheap->array = (node **)malloc(sizeof(node *) * minheap->capacity);
    minheap->size = 0;

    return minheap;
}

void swapNodes(node **a, node **b)
{
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(heap *minheap, int index)
{
    int min = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minheap->size && minheap->array[left]->freq < minheap->array[min]->freq)
    {
        min = left;
    }

    if (right < minheap->size && minheap->array[right]->freq < minheap->array[min]->freq)
    {
        min = right;
    }

    if (min != index)
    {
        swapNodes(&minheap->array[min], &minheap->array[index]);
        heapify(minheap, min);
    }
}

bool isLastElement(heap *minheap)
{
    return (minheap->size == 1);
}

node *extractRoot(heap *minheap)
{
    node *root = minheap->array[0];
    minheap->array[0] = minheap->array[minheap->size - 1];
    minheap->size--;
    heapify(minheap, 0);
    return root;
}

void insertNode(heap *minheap, node *heapNode)
{
    minheap->size++;
    int index = minheap->size - 1;

    while (index != 0 && heapNode->freq < minheap->array[(index - 1) / 2]->freq)
    {
        minheap->array[index] = minheap->array[(index - 1) / 2];
        index = (index - 1) / 2;
    }

    minheap->array[index] = heapNode;
}

heap *buildHeap(char keys[], int freq[], int capacity)
{
    heap *minheap = createHeap(capacity);

    for (int i = 0; i < capacity; i++)
    {
        minheap->array[i] = createNode(freq[i], keys[i]);
    }

    minheap->size = capacity;

    int n = minheap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; i--) // Fixed the loop condition here
    {
        heapify(minheap, i);
    }

    return minheap;
}

bool isLeaf(node *heapnode)
{
    return (!heapnode->left && !heapnode->right);
}

node *buildHuffmanTree(int freq[], char keys[], int size)
{
    node *leftchild, *rightchild, *root;
    heap *minheap = buildHeap(keys, freq, size);

    while (!isLastElement(minheap))
    {
        leftchild = extractRoot(minheap);
        rightchild = extractRoot(minheap);

        root = createNode(leftchild->freq + rightchild->freq, '#');

        root->left = leftchild;
        root->right = rightchild;

        insertNode(minheap, root);
    }

    return extractRoot(minheap);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << "\n";
}

void printCodes(node *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root))
    {
        cout << root->key << ": ";
        printArray(arr, top);
    }
}

void generateHuffmanCodes(char keys[], int freq[], int size)
{
    node *root = buildHuffmanTree(freq, keys, size);

    int arr[MTH], top = 0;

    printCodes(root, arr, top);
}

int main()
{
    char keys[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(keys) / sizeof(keys[0]);

    generateHuffmanCodes(keys, freq, size);

    return 0;
}