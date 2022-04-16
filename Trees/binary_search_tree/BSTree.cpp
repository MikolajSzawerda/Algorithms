#include "BSTree.h"
#include <iostream>


BSTree::BSTree(int value){
    auto newNode = new Node(value);
    this->root = newNode;
}

BSTree::BSTree(BSTree const& tree){
    auto values = tree.inOrder();
    for(auto num:values){
        this->insert(num);
    }
}

std::vector<int> BSTree::inOrder(Node * node) const{
    std::vector<int> keys;
    if(node != nullptr){
        auto left = inOrder(node->left);
        keys.push_back(node->key);
        auto right = inOrder(node->right);
        for(auto num:left)
            keys.push_back(num);
        for(auto num:right)
            keys.push_back(num);
    }
    return keys;
}

Node* BSTree::minimum(Node * node){
    auto traversingNode = node;
    while(traversingNode->left){
        traversingNode = traversingNode->left;
    }
    return traversingNode;
}

// Node* BSTree::successor(Node * node){
//     if(node->right != nullptr)
//         return minimum(node->right);

// }

std::vector<int> BSTree::inOrder() const{
    return this->inOrder(this->root);
}

bool BSTree::insert(int value){
    return insert(value, this->root);
}

void BSTree::setRoot(Node * root){
    root->parent = nullptr;
    this->root = root;
}

bool BSTree::insert(int value, Node * node){
    if(node == nullptr){
        auto new_node = new Node(value);
        setRoot(new_node);
        return true;
    }
    if(value>node->key){
        if(node->right == nullptr){
            auto new_node = new Node(value);
            node->insertChild(new_node);
            return true;
        }
        return insert(value, node->right);
    }
    else if(value<node->key){
        if(node->left == nullptr){
            auto new_node = new Node(value);
            node->insertChild(new_node);
            return true;
        }
        return insert(value, node->left);
    }else{
        return false;
    }
}

void BSTree::dealocateTree(Node * node){
    if(node!=nullptr){
        dealocateTree(node->left);
        dealocateTree(node->right);
        delete node;
    }
}

BSTree& BSTree::operator=(BSTree const& tree){
    if(this==&tree)
        return *this;
    this->dealocateTree(this->root);
    this->root = nullptr;
    auto numbers = tree.inOrder();
    for(auto num:numbers)
        this->insert(num);
    return *this;
}


BSTree::~BSTree(){
    dealocateTree(this->root);
}

bool BSTree::deleteNode(int value){
    return deleteNode(value, this->root);
}

void BSTree::transplant(Node * transplanted, Node * transplant){
    if(transplanted->parent==nullptr)
        setRoot(transplant);
    else if(transplanted == transplanted->parent->left)
        transplanted->parent->left = transplant;
    else
        transplanted->parent->right = transplant;
    if(transplant!=nullptr)
        transplant->parent = transplanted->parent;
    delete transplanted;

}

bool BSTree::deleteNode(int value, Node * node){
    if(node == nullptr) return false;
    if(value>node->key)
        return deleteNode(value, node->right);
    else if(value<node->key)
        return deleteNode(value, node->left);
    else{
        if(node->right == nullptr){
            transplant(node, node->left);
            return true;
        }else if(node->left == nullptr){
            transplant(node, node->right);
            return true;
        }else{
            auto successor = minimum(node->right);
            node->key = successor->key;
            deleteNode(successor->key, node->right);
            return true;
        }
    }
}

Node * BSTree::search(int value) const noexcept{
    auto traversingNode = this->root;
    while(traversingNode!=nullptr && traversingNode->key!=value){
        if(value>=traversingNode->key)
            traversingNode = traversingNode->right;
        else
            traversingNode = traversingNode->left;
    }
    return traversingNode;
}

int BSTree::count() const noexcept{
    return count(this->root);
}

int BSTree::count(Node * node) const noexcept{
    if(node==nullptr) return 0;
    return 1 + count(node->left) + count(node->right);
}
