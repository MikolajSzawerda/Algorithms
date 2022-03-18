#include <iostream>
#include <vector>
#include <limits.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void insertionSort(std::vector<int> & numbers){
    for(int i=1;i<numbers.size();i++){
        int key = numbers[i];
        int j=i-1;
        while(j>=0 && numbers[j]>key){
            numbers[j+1]=numbers[j];
            j--;
        }
        numbers[j+1]=key;
    }
}

void listIterate(ListNode * head){
    auto index = head;
    while(index!=nullptr){
        std::cout<<index->val<<std::endl;
        index=index->next;
    }
}

ListNode * createList(std::vector<int> numbers){
    ListNode *head = new ListNode();
    auto index=head;
    for(auto number:numbers){
        index->next = new ListNode(number);
        index = index->next;
    }
    return head->next;
}

ListNode* insertionSortList(ListNode* head) {
    ListNode *temp = new ListNode(INT_MAX);
    auto index = head;
    ListNode *next;
    while(index!=nullptr){
        next = index->next;
        int val = index->val;
        ListNode* insertionIndex = temp;
        while(insertionIndex->next!=nullptr && insertionIndex->next->val<val) insertionIndex = insertionIndex->next;
        auto currNext = insertionIndex->next;
        insertionIndex->next = index;
        index->next = currNext;
        index = next;
    }
    return temp->next;
}

int main(int, char**) {
    // std::vector<int> numbers = {6,4,1,5,3,2};
    // insertionSort(numbers);
    // for(auto num : numbers){
    //     std::cout<<num<<std::endl;
    // }
    auto tail = ListNode(3);
    auto node3 = ListNode(1, &tail);
    auto node2 = ListNode(2, &node3);
    auto head = ListNode(4, &node2);

    std::vector<int> numbers = {-1,5,3,4,0};
    auto list = createList(numbers);

    listIterate(insertionSortList(list));
}
