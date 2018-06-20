#ifndef QUEUE_H
#define QUEUE_H


template <class Type>
class Queue{

private:
    size_t size;
    struct Node{
        Type data;
        Node* next;
    };
    Node* first;
public:
    Queue() {first = nullptr; size = 0;}
    void add(Type value); // Добовляет элемент в очередь
    Type remote(); // Возращает значение первого элемента очереди и удаляет элемент из очереди
    size_t getSize();
};

template <class Type>
void Queue<Type>::add(Type value){
    Node* last = first;
    if(first == nullptr){
        first = new Node;
        first->data = value;
        first->next = nullptr;
    }
    else{
        while(last->next){
            last = last->next;
        }
        Node* tmp = new Node;
        tmp->data = value;
        tmp->next = nullptr;
        last->next = tmp;
    }
    size++;
}

template <class Type>
Type Queue<Type>::remote(){
    Node* prev = nullptr;
    if(first == nullptr){
        return nullptr;
    }
    Type data = first->data;
    prev = first;
    first = first->next;
    delete prev;
    size--;
    return data;
}

template <class Type>
size_t Queue<Type>::getSize(){
    return size;
}

#endif // QUEUE_H
