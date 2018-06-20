#ifndef BIN_TREE_H
#define BIN_TREE_H

#include "queue.h"

template <class Type>
class  BinTree{

private:
    struct Node{
        Type data;
        Node* left;
        Node* right;
        Node* parent;
    };
    Node* root;
    size_t size;

private:
    Node* getNodeByValue(Type value){
        Node* tmp = root;
        while(tmp){
            if(value < tmp->data){
                tmp = tmp->left;
                continue;
            }
            else if(tmp->data < value ){
                tmp = tmp->right;
                continue;
            }
            else{
                return tmp;
            }
        }
        return nullptr;
    }
    Node* findMaxNode(Node* curr){
        while(curr->right){
            curr = curr->right;
        }
        return curr;
    }
    void remoteNodeByPtr(Node* target){
        if(target == nullptr){
            return;
        }
        if(target->left && target->right){
            // Two children
            Node* localMax = findMaxNode(target->left);
            target->data = localMax->data;
            remoteNodeByPtr(localMax);
            return;
        }
        else if(target->left){
            // left children
            if (target == target->parent->left) {
                target->parent->left = target->left;
            } else {
                target->parent->right = target->left;
            }
        }
        else if(target->right){
            // right child
            if (target == target->parent->right) {
                target->parent->right = target->right;
            } else {
                target->parent->left = target->right;
            }
        }
        else{
            // No children
            if (target == target->parent->left) {
                target->parent->left = NULL;
            } else {
                target->parent->right = NULL;
            }
        }
        delete target;
        size--;
    }

public:
    BinTree() {root = nullptr; size = 0;}
    void add(Type value);
    void remote(Type value);
    bool empty();
    void printBinTree();
    void traversal(void (*func)(void*), void *params);
    BinTree clone();
    void deleteTree();
    size_t getSize();
};

template<class Type>
void BinTree<Type>:: add(Type value){
    Node* curr = root;
    if(this->empty()){
        root = new Node();
        root->left = nullptr;
        root->right = nullptr;
        root->parent = nullptr;
        root->data = value;
        size++;
        return;
    }
    else{
        while(curr){
            if(value > curr->data){
                if(curr->right){
                    curr = curr->right;
                    continue;
                }
                else{
                    Node* leaf = new Node();
                    leaf->data = value;
                    curr->right = leaf;
                    leaf->parent = curr;
                    leaf->right = nullptr;
                    leaf->left = nullptr;
                    size++;
                    return;
                }
            }
            else{
                if(curr->left){
                   curr = curr->left;
                   continue;
                }
                else{
                    Node* leaf = new Node();
                    leaf->data = value;
                    curr->left = leaf;
                    leaf->parent = curr;
                    leaf->right = nullptr;
                    leaf->left = nullptr;
                    size++;
                    return;
                }
            }
        }
    }
}
template<class Type>
void BinTree<Type>::remote(Type value){
    Node* remoteNode = getNodeByValue(value);
    remoteNodeByPtr(remoteNode);
}

template <class Type>
bool BinTree<Type>::empty(){
    return (root == nullptr) ? true: false;
}

template <class Type>
void BinTree<Type>::printBinTree(){

}
template <class Type>
void BinTree<Type>::traversal(void (*func)(void *), void *params){

    Queue<Node*> queue;

    queue.add(root);

    while(queue.getSize() != 0){
        Node* tmp = queue.remote();
        std::cout<<tmp->data << std::endl;
        if(tmp->left){
            queue.add(tmp->left);
        }
        if(tmp->right){
            queue.add(tmp->right);
        }
    }
}

template <class Type>
BinTree<Type> BinTree<Type>::clone(){
    BinTree<Type> cloneTree;
    if(this->empty()){
        return cloneTree;
    }
    else{
        Queue<Node*> queue;
        queue.add(root);
        while(queue.getSize() != 0){
            Node* tmp = queue.remote();
            cloneTree.add(tmp->data);
            if(tmp->left){
                queue.add(tmp->left);
            }
            if(tmp->right){
                queue.add(tmp->right);
            }
        }
        return cloneTree;
    }
}

//template <class Type>
//void BinTree<Type>::deleteTree(){
//    if(this->empty()){
//        return;
//    }
//    else{
//        Queue<Node*> queue;
//        queue.add(root);
//        while(queue.getSize() != 0){
//            Node* tmp = queue.remote();
//            cloneTree.add(tmp->data);
//            if(tmp->left){
//                queue.add(tmp->left);
//            }
//            if(tmp->right){
//                queue.add(tmp->right);
//            }
//        }
//        return cloneTree;
//    }
//}

template <class Type>
size_t BinTree<Type>::getSize(){
    return size;
}
#endif // BIN_TREE_H
