#include "Median.h"
#include "limits.h"
#include <stdexcept>
#include <algorithm>
#include <stdio.h>

int Median::Maximium(std::vector<int> numbers){
    int max = INT_MIN;
    for(int number:numbers){
        if(number > max) max = number;
    }
    return max;
}

int Median::Minimum(std::vector<int> numbers){
    int min = INT_MAX;
    for(int number:numbers){
        if(number < min) min = number;
    }
    return min;
}

std::pair<int, int> Median::MinMax(std::vector<int> numbers){
    int len = numbers.size();
    int min = INT_MAX, max = INT_MIN;
    int k=0;
    if(!len) throw std::invalid_argument("No min and max in empty arr");
    if(len%2){min=numbers[0], max=numbers[0]; k=1; }
    for(int i=k; i<len;i=i+2)
    {
        int potMin=0, potMax=0;
        if(numbers[i]>numbers[i+1]){
            potMax=numbers[i];
            potMin=numbers[i+1];
        }else{
            potMax=numbers[i+1];
            potMin=numbers[i];
        }
        if(potMin<min) min = potMin;
        if(potMax>max) max = potMax;
    }

    return std::pair<int, int>{min, max};
}

int Median::Partition(std::vector<int> & numbers, int start, int end){
    int x = numbers[end];
    int i = start-1;
    for(int j = start; j<=end-1;j++){
        if(numbers[j]<=x) std::swap(numbers[++i], numbers[j]);
    }
    std::swap(numbers[i+1], numbers[end]);
    return ++i;
}

int Median::RandomizedPartition(std::vector<int> & numbers, int start, int end){
    int i = rand()%end+start;
    std::swap(numbers[end], numbers[i]);
    return Partition(numbers, start, end);
}

int Median::Select(std::vector<int> & numbers, int start, int end, int i){
    if(start == end) {
        return numbers[start];
    }
    int q = RandomizedPartition(numbers, start, end);
    int k = q - start + 1;
    if(k==i){
        return numbers[q];
    }
    else if(i < k) return Select(numbers, start, q-1, i);
    return Select(numbers, q+1, end, i-k);

}

