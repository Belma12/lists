#pragma once
#include<iostream>

template<typename T>
class MyList{
    public:
    
    MyList()=default;
    MyList(const MyList& other);
    MyList(MyList&& other);
    MyList& operator=(const MyList& other);
    MyList& operator=(MyList&& other);
    ~MyList();
    
    
    void push_back(const T& elem);
    void push_back(T&& elem);
    void push_front(const T& elem);
    void push_front(T&& elem);
    void pop_back();
    void pop_front();
    bool empty();
    int size_();
    void clear()
    
    private:
    struct Node{
        T data_;
        Node* next_;
    };
    Node* head_=nullptr;
    Node* tail_=nullptr;
    int size_=0;
};

template<typename T>
MyList<T>::MyList(const MyList& other){
    auto temp=other.head_;
    while(temp!=nullptr){
        push_back(temp->data_);
        temp=temp->next_;
    }
}

template<typename T>
MyList<T>::MyList(MyList&& other):
head_{other.head_}, tail_{other.tail_}, size_{other.size_}{
    other.head_=nullptr;
    other.tail_=nullptr;
    size_=0;
}

template<typename T>
MyList<T>& MyList<T>::operator=(const MyList& other){
    clear();
    auto temp=other.head_;
    while(temp!=other.tail_){
        push_back(temp->data_);
        temp=temp->next_;
    }
    return *this;
}

template<typename T>
MyList<T>& MyList<T>::operator=(MyList&& other){
    clear();
    auto temp=other.head_;
    while(temp!=nullptr){
        push_back(temp->data_);
        temp=temp->next_;
        
    }
    return *this;
}

template<typename T>
MyList<T>::~MyList(){
    clear();
}

template<typename T>
void MyList<T>::clear(){
    while(front!=nullptr){
        auto temp=head_->next_;
        delete head_;
        head_=temp;
    }
    tail_=nullptr;
    size_=0;
}

template<typename T>
bool MyList<T>::empty(){
    return size_==0;
}

template<typename T>
int MyList<T>::size(){
    return size_==0;
}

template<typename T>
void MyList<T>::push_back(const T& elem){
    if(size_==0){
        head_=new  Node{elem, nullptr};
        tail_=head_;
    }
    else{
        auto temp=new Node{elem,nullptr};
        tail_->next_=temp;
        tail_=temp;
    }
    size_++;
}

template<typename T>
void MyList<T>::push_back(T&& elem){
    if(size_==0){
        head_=new Node{std::move(elem), nullptr};
        tail_=head_;
    }
    else{
        auto temp=new Node{std::move(elem), nullptr};
        tail_->next_=temp;
        tail_=temp;
    }
    size_++;
}

template<typename T>
void MyList<T>::push_front(const T& elem){
    if(size_==0){
        push_back(elem);
    }
    else{
        auto temp=new Node{elem, nullptr};
        temp->next_=head_;
        head_=temp;
        size_++;
        
    }
  
}

template<typename T>
void MyList<T>::push_back(T&& elem){
    if(size_==0){
        push_back(std::move(elem));
        
    }
    else{
        auto temp=new Node{std::move(elem), nullptr};
        temp->next_=head_;
        head_=temp;
        size_++;
    }
}

template<typename T>
void MyList<T>::pop_front(){
    if(empty()){
        return;
    }
    else if(size_==1){
        clear();
        return;
    }
    else{
        auto temp=head_->next_;
        head_=temp;
        delete temp;
        size_--;
    }
}

template<typename T>
void MyList<T>::pop_back(){
    if(empty()){
        return;
    }
    else if(size_==1){
        pop_back();
        }
    else{
        auto temp=head_;
        while(temp->next_!=tail_){
            temp=temp->next_;
        }
        delete tail_;
        tail_=temp;
        tail_->next_=nullptr;
        size_--;
        
        
    }
    
};