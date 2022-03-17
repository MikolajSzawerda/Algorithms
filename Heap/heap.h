#include <vector>

class Heap
{
    private:
        std::vector<int> numbers = {};
        void BuildMaxHeap();
        int Parent(int i);
        int Left(int i);
        int Right(int i);
        int nodeVal(int i);
        void MaxHeapify(int i);
        int heapSize = 0;
    public:
        Heap(std::vector<int> & numbers);
        void MaxHeapInsert(int number);
        int HeapExtractMax();
        void HeapIncreaseKey(int i, int key);
        int HeapMaximum();
        int HeapSize();
        std::vector<int> getHeapArr();
};