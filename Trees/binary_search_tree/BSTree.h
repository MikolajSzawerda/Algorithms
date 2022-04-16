#include <vector>

struct Node{
    Node* left=nullptr;
    Node* right=nullptr;
    Node* parent=nullptr;
    int key;
    Node(int key, Node* left=nullptr, Node* right = nullptr, Node* parent = nullptr){
        this->key = key;
    }
    void insertChild(Node * node){
        int val = node->key;
        if(val>this->key){
            this->right = node;
            node->parent = this;
        }
        else if(val<this->key){
            this->left = node;
            node->parent = this;
        }
    }
};

class BSTree{
    Node * root = nullptr;
    std::vector<int> inOrder(Node * node) const;
    bool insert(int value, Node * node);
    void setRoot(Node * node);
    void dealocateTree(Node * node);
    bool deleteNode(int value, Node * node);
    void transplant(Node * transplanted, Node * transplant);
    int count(Node * node) const noexcept;
    public:
    BSTree() = default;
    BSTree(int initialNode);
    BSTree(Node& root);
    BSTree(BSTree const& root);
    BSTree& operator=(BSTree const& tree);
    std::vector<int> inOrder() const;
    bool insert(int value);
    Node* search(int value) const noexcept;
    bool deleteNode(int value);
    Node* successor(Node * node);
    Node * minimum(Node * node);
    int count() const noexcept;
    ~BSTree();
};
