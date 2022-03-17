#include "heap.h"
#include <algorithm>

int Heap::HeapSize(){
    return this->heapSize;
}

int Heap::nodeVal(int i){
    return (this->numbers).at(i);
}

void Heap::MaxHeapify(int i){
    int l = Left(i);
    int r = Right(i);

    int val = this->nodeVal(i);
    int heapSize = this->HeapSize();
    int largest=i;

    if(l< heapSize && this->nodeVal(l) > val) largest = l;

    if(r< heapSize && this->nodeVal(r) > this->nodeVal(largest)) largest = r;

    if(largest!=i){
        std::swap((this->numbers).at(i), (this->numbers).at(largest));
        this->MaxHeapify(largest);
    }


}

void Heap::BuildMaxHeap(){
    int middle = (this->HeapSize())/2;
    for(int i=middle;i>=0;--i){
        this->MaxHeapify(i);
    }
}

Heap::Heap(std::vector<int> & numbers){
    this->numbers.insert(this->numbers.end(), numbers.begin(), numbers.end());
    this->heapSize = numbers.size();
    this->BuildMaxHeap();
}

std::vector<int> Heap::getHeapArr(){
    auto v = this->numbers;
    return std::vector<int>(v.begin(),v.end());
}
int Heap::Parent(int i){
    return (i-1)/2;
}
int Heap::Right(int i){
    return 2*i+1;
}
int Heap::Left(int i){
    return 2*i+2;
}

int Heap::HeapMaximum(){
    return *(this->numbers.begin());
}

int Heap::HeapExtractMax(){
    if(!(this->heapSize)){
        throw "Pusty kopiec";
    }
    int max = this->numbers.at(0);
    std::swap(this->numbers.at(0), this->numbers.at(this->heapSize-1));
    this->numbers.pop_back();
    this->heapSize=this->heapSize-1;
    this->MaxHeapify(0);
    return max;
}

void Heap::HeapIncreaseKey(int i, int key){
    if(key<this->numbers.at(i)){
        throw "Błędna wartość";
    }
    this->numbers.at(i) = key;
    while(i>0 && this->numbers.at(this->Parent(i))<this->numbers.at(i)){
        std::swap(this->numbers.at(this->Parent(i)), this->numbers.at(i));
        i = this->Parent(i);
    }
}

void Heap::MaxHeapInsert(int key){
    this->heapSize++;
    this->numbers.push_back(INT32_MIN);
    this->HeapIncreaseKey(this->heapSize-1, key);
}