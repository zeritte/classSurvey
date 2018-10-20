#include "LinkedList.h"

LinkedList::LinkedList() {
    this->head=0;
    this->tail=0;
    this->length=0;
}

LinkedList::LinkedList(const LinkedList& list) {
    delete this->head;
    if(list.head!= 0){
        Node *temp=list.head;
        this->head=new Node(temp->name, temp->amount);
        this->tail=this->head;
        while(temp){
            this->tail->next=new Node(temp->name,temp->amount);
            this->tail=this->tail->next;
            temp=temp->next;
        }
        this->length=list.length;
    } else {
        this->head=0;
        this->tail=0;
        this->length=0;
    }
}

LinkedList& LinkedList::operator=(const LinkedList &list) {
    delete this->head;
    if(list.head != 0){
        Node *temp=list.head;
        this->head=new Node(temp->name, temp->amount);
        this->tail=this->head;
        while(temp){
            this->tail->next=new Node(temp->name,temp->amount);
            this->tail=this->tail->next;
            temp=temp->next;
        }
    }else{
        this->head=0;
        this->tail=0;
        this->length=0;
    }
    this->length = list.length;
    return *this;
}

LinkedList::LinkedList(LinkedList &&list) {
    if(head) delete this->head;
    this->head=move(list.head);
    this->tail=move(list.tail);
    this->length=move(list.length);

    // cleaning list itself
    list.length=0;
    list.tail=0;
    list.head=0;
}

LinkedList& LinkedList::operator=(LinkedList &&list) {
    delete this->head;
    delete this->tail;
    this->head=move(list.head);
    this->tail=move(list.tail);
    this->length=move(list.length);

    // cleaning list itself
    list.length=0;
    list.tail=0;
    list.head=0;
    return *this;
}

void LinkedList::pushTail(string _name, float _amount) {
    // pushes new item to the rear of the list
    length++;
    if(this->head==0){
        // if an empty list
        this->head=new Node(_name, _amount);
        this->tail=head;
    } else{
        // if not empty
        this->tail->next=new Node(_name, _amount);
        this->tail=tail->next;
    }
}

void LinkedList::updateNode(string _name, float _amount) {
    // update an existing element, if element doesnot exist then push it
    Node* scanner;
    scanner=this->head;
    if(!scanner){
        // if its an empty list
        pushTail(_name,_amount);
    }else{
        // if its not empty
        while(scanner->name!=_name && scanner->next!= 0){
            // search for same name
            scanner=scanner->next;
        }
        if(scanner->name == _name){
            // if found
            scanner->amount=_amount;
        }else{
            // if not found
            pushTail(_name,_amount);
        }
    }

}

void LinkedList::print(){
    Node* curr;
    curr=this->head;
    while(curr){
        cout <<curr->name<<" "<<curr->amount << endl;
        curr = curr->next;
    }
}

LinkedList::~LinkedList() {
    if (head) delete head;
}

