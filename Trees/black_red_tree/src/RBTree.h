#include <vector>


template <typename T>
class RBTree{
    enum Color : bool {
    black = false,
    red = true
    };
    struct Node{
        Node* left=nullptr;
        Node* right=nullptr;
        Node* parent=nullptr;
        T key;
        Color color=Color::black;
        Node(T key=T(), Color color=Color::black, Node* left=nullptr, Node* right = nullptr, Node* parent = nullptr)
            :key(key), color(color), left(left), right(right), parent(parent){}
        void setColor(Color color){
            this->color=color;
        }
        bool isRed(){
            return color==Color::red;
        }
        bool isBlack(){
            return color==Color::black;
        }
    };

    Node * root = nullptr;
    Node * watcher = nullptr;

    void dealocateTree(Node * node){
        if(node!=watcher){
            dealocateTree(node->left);
            dealocateTree(node->right);
            delete node;
        }
    }

    std::vector<T> inOrder(Node * node) const{
        std::vector<T> keys;
        if(node != watcher){
            auto left = inOrder(node->left);
            for(auto num:left)
                keys.push_back(num);
            keys.push_back(node->key);
            auto right = inOrder(node->right);
            for(auto num:right)
                keys.push_back(num);
        }
        return keys;
    }

    Node* minimum(Node * node){
        auto traversingNode = node;
        while(traversingNode->left!=watcher){
            traversingNode = traversingNode->left;
        }
        return traversingNode;
    }

    Node* maximum(Node * node){
        auto traversingNode = node;
        while(traversingNode->right!=watcher){
            traversingNode = traversingNode->right;
        }
        return traversingNode;
    }

    Node* successor(Node * node){
        if(node->right != watcher)
            return minimum(node->right);
        auto temp = node->parent;
        while(temp!=watcher && node == temp->right){
            node = temp;
            temp = temp->parent;
        }
        return temp==watcher ? nullptr : temp;
    }

    Node* predecessor(Node * node){
        if(node->left != watcher)
            return maximum(node->left);
        auto temp = node->parent;
        while(temp!=watcher && node == temp->left){
            node = temp;
            temp = temp->parent;
        }
        return temp==watcher ? nullptr : temp;
    }

    Node * search(T value, Node * node) const noexcept{
        auto traversingNode = node;
        while(traversingNode!=watcher && traversingNode->key!=value){
            if(value>=traversingNode->key)
                traversingNode = traversingNode->right;
            else
                traversingNode = traversingNode->left;
        }
        return traversingNode;
    }

    int count(Node * node) const noexcept{
        if(node==watcher) return 0;
        return 1 + count(node->left) + count(node->right);
    }

    void leftRotation(Node * node){
        auto median = node->right;
        node->right = median->left;
        if(median->left!=watcher){
            median->left->parent = node;
        }
        median->parent = node->parent;
        if(node->parent == watcher){
            this->root = median;
        }else if(node == node->parent->left){
            node->parent->left = median;
        }else
            node->parent->right = median;
        median->left = node;
        node->parent = median;
    }

    void rightRotation(Node * node){
        auto median = node->left;
        node->left = median->right;
        if(median->right != watcher){
            median->right->parent = node;
        }
        median->parent = node->parent;
        if(node->parent == watcher){
            this->root = median;
        }else if(node == node->parent->left){
            node->parent->left = median;
        }else
            node->parent->right = median;
        median->right = node;
        node->parent = median;
    }

    void recolorClosestAncestors(Node * node){
        node->parent->parent->right->setColor(Color::black);
        node->parent->parent->left->setColor(Color::black);
        node->parent->parent->setColor(Color::red);
    }

    bool isRightSon(Node * node){
        return node == node->parent->right;
    }

    bool isLeftSon(Node * node){
        return node == node->parent->left;
    }

    void InsertFixup(Node * node){
        while(node->parent->isRed()){
            if(isLeftSon(node->parent)){
                auto uncle = node->parent->parent->right;
                if(uncle->isRed()){
                    recolorClosestAncestors(node);
                    node = node->parent->parent;
                }else{
                    if(isRightSon(node)){
                        node=node->parent;
                        leftRotation(node);
                    }
                    node->parent->setColor(Color::black);
                    node->parent->parent->setColor(Color::red);
                    rightRotation(node->parent->parent);
                }
            }else{
                auto uncle = node->parent->parent->left;
                if(uncle->isRed()){
                    recolorClosestAncestors(node);
                    node = node->parent->parent;
                }else{
                    if(isLeftSon(node)){
                        node=node->parent;
                        rightRotation(node);
                    }
                    node->parent->color = Color::black;
                    node->parent->parent->color = Color::red;
                    leftRotation(node->parent->parent);
                }
            }
        }
        root->setColor(Color::black);
    }

    bool insert(T value, Node * node){
        Node * traversingNode=node;
        Node * insertPlace = watcher;
        while(traversingNode!=watcher){
            insertPlace = traversingNode;
            if(traversingNode->key > value)
                traversingNode = traversingNode->left;
            else if(traversingNode->key < value)
                traversingNode = traversingNode->right;
            else return false;
        }
        auto newNode = new Node(value, Color::red, watcher, watcher, insertPlace);
        newNode->parent = insertPlace;
        if(insertPlace == watcher)
            root=newNode;
        else if(newNode->key < insertPlace->key)
            insertPlace->left = newNode;
        else
            insertPlace->right = newNode;
        InsertFixup(newNode);
        return true;
    }

    void transplant(Node * transplanted, Node * transplant){
        if(transplanted->parent==watcher)
            root = transplant;
        else if(isLeftSon(transplanted))
            transplanted->parent->left = transplant;
        else
            transplanted->parent->right = transplant;
        transplant->parent = transplanted->parent;
    }

    void DeleteFixup(Node * node){
    while(node!=root && node->isBlack()){
        Node * w;
        if(isLeftSon(node)){
            w = node->parent->right;
            if(w->isRed()){
                w->color = Color::black;
                node->parent->color = Color::red;
                leftRotation(node->parent);
                w = node->parent->right;
            }
            if(w->left->isBlack() && w->right->isBlack()){
                w->color = Color::red;
                node = node->parent;
            }else{
            if(w->right->isBlack()){
                w->left->color = Color::black;
                w->color = Color::red;
                rightRotation(w);
                w = node->parent->right;
            }
            w->color = node->parent->color;
            node->parent->color = Color::black;
            w->right->color = Color::black;
            leftRotation(node->parent);
            node = root;
            }
        }else{
            w = node->parent->left;
            if(w->isRed()){
                w->color = Color::black;
                node->parent->color = Color::red;
                rightRotation(node->parent);
                w = node->parent->left;
            }
            if(w->right->isBlack() && w->left->isBlack()){
                w->color = Color::red;
                node = node->parent;
            }else{
            if(w->left->isBlack()){
                w->right->color = Color::black;
                w->color = Color::red;
                leftRotation(w);
                w = node->parent->left;
            }
            w->color = node->parent->color;
            node->parent->color = Color::black;
            w->left->color = Color::black;
            rightRotation(node->parent);
            node = root;
            }
        }
        watcher->parent = watcher;
        watcher->color = Color::black;
        }
    }

    bool deleteNode(T value, Node * node){
        auto temp = node;
        auto oldColor = temp->color;
        Node * x;
        if(node->left == watcher){
            x = node->right;
            transplant(node, node->right);
        }else if(node->right == watcher)
        {
            x = node->left;
            transplant(node, node->left);
        }else{
            temp = minimum(node->right);
            oldColor = temp->color;
            x = temp->right;
            if(temp->parent == node)
                x->parent = temp;
            else{
                transplant(temp, temp->right);
                temp->right = node->right;
                temp->right->parent = temp;
            }
            transplant(node, temp);
            temp->left = node->left;
            temp->left->parent = temp;
            temp->color = node->color;
        }
        if(oldColor == Color::black){
            DeleteFixup(x);
        }
        delete node;
        return true;
    }
    public:
    RBTree(){
        watcher = new Node();
        watcher->left = watcher;
        watcher->right = watcher;
        watcher->parent = watcher;
        root=watcher;
    }

    RBTree(T value) : RBTree(){
        insert(value);
    }

    RBTree(RBTree const& tree) : RBTree(){
        auto values = tree.inOrder();
        for(auto num:values){
            this->insert(num);
        }
    }

    RBTree& operator=(RBTree const& tree){
        if(this==&tree)
            return *this;
        this->dealocateTree(this->root);
        delete watcher;
        watcher = new Node();
        watcher->left = watcher;
        watcher->right = watcher;
        watcher->parent = watcher;
        this->root = watcher;
        auto numbers = tree.inOrder();
        for(auto num:numbers)
            this->insert(num);
        return *this;
    }

    ~RBTree(){
        dealocateTree(this->root);
        delete watcher;
    }

    std::vector<T> inOrder() const{
        return this->inOrder(this->root);
    }

    Node * minimum(){
        auto node = minimum(root);
        return node==watcher ? nullptr : node;
    }

    Node * maximum(){
        auto node = maximum(root);
        return node==watcher ? nullptr : node;
    }

    Node* successor(T value){
        auto node = search(value);
        if(node==nullptr)
            return node;
        return successor(node);
    }


    Node* predecessor(T value){
        auto node = search(value);
        if(node==nullptr)
            return node;
        return predecessor(node);
    }


    Node * search(T value) const noexcept{
    auto node = search(value, root);
    return node != watcher ? node : nullptr;
    }


    int count() const noexcept{
        return count(this->root);
    }

    bool insert(T value){
        return insert(value, this->root);
    }

    bool deleteNode(T value){
        auto node = search(value, root);
        if(node == watcher)
            return false;
        return deleteNode(value, node);
    }
};