#include <iostream>
#include "heap.h"
#include <vector>

void presentVector(const std::vector<int> & numbers){
    for(int num : numbers){
        std::cout<<num<<std::endl;
    }
}

int main(int, char**) {
    std::vector<int> numbers = {4, 16, 10, 14, 7, 9, 3, 8, 3, 1};
    Heap h(numbers);
    presentVector(h.getHeapArr());
    h.MaxHeapInsert(20);
    presentVector(h.getHeapArr());
}
