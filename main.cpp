//
//  main.cpp
//  LinkList
//
//  Created by Quoc Le on 9/9/15.
//  Copyright © 2015 Quoc Le. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;


struct Data {
public:
    Data(int key, int data);
    
    int key;
    int data;
};

struct Node {
public:
    Node(Data* pData, Node* pNext);
    
    Data* pData;
    Node* pNext;
};

struct List {
public:
    List();
    List(Node* pHead, Node* pTail, int count);
    void initList();
    Node* getMiddleNode(Node* pHead);
    void reduce();
    void printList();
    void insertFirst(Node* node);
    void insertLast(Node* node);
    
    Node* pHead;
    Node* pTail;
    int count;
    
};

// Data
Data::Data(int key, int data) {
    this->key = key;
    this->data = data;
}

// Node
Node::Node(Data* pData, Node* pNext) {
    this->pData = pData;
    this->pNext = pNext;
}

// List
List::List() {
    this->pHead = NULL;
    this->pTail = NULL;
    this->count = 0;
}

List::List(Node* pHead, Node* pTail, int count) {
    this->pHead = pHead;
    this->pTail = pTail;
    this->count = count;
}

void List::initList() {
    Node* pNode = new Node(new Data(4, 45), pHead);
    this->insertLast(pNode);
    
    Node* pNode2 = new Node(new Data(5, 30), pHead);
    this->insertLast(pNode2);

    Node* pNode3 = new Node(new Data(3, 12), pHead);
    this->insertFirst(pNode3);
    
    Node* pNode4 = new Node(new Data(6, 22), pHead);
    this->insertFirst(pNode4);
    
    Node* pNode5 = new Node(new Data(7, 23), pHead);
    this->insertLast(pNode5);
}

void List::printList() {
    if (pHead == NULL) {
        cout << "The List is empty!" << endl;
        return;
    }
    cout << "count: " << count << endl;
    Node* pTem = pHead;
    while (pTem != NULL) {
        cout << "key: " << pTem->pData->key << endl;
        cout << "data: " << pTem->pData->data << endl;
        pTem = pTem->pNext;
    }
    cout << endl;
}

void List::insertFirst(Node* node) {
    if (node == NULL) {
        return;
    }
    if (pHead == NULL) {
        pTail = pHead = node;
        count = 1;
    } else {
        node->pNext = pHead;
        pHead = node;
        count++;
    }
    
}

void List::insertLast(Node* node) {
    if (node == NULL) {
        return;
    }
    if (pHead == NULL) {
        pTail = pHead = node;
        count = 1;
    } else {
        node->pNext = NULL;
        pTail->pNext = node;
        pTail = node;
        count++;
    }
    
}

Node* List::getMiddleNode(Node* pHead) {
    
    Node* pTemp = pHead;
    Node* pMid = pHead;
    while (pTemp != NULL) {
        pTemp = pTemp->pNext;
        if (pTemp) {
            pTemp = pTemp->pNext;
            pMid = pMid->pNext;
        }
    }
    return pMid;
}

void List::reduce() {
    if (pHead == NULL) {
        return;
    } else if (pHead->pNext == NULL) {
        return;
    } else {
        Node* pDel = pHead->pNext;
        pHead->pNext = pDel->pNext;
        pHead->pData->data += pDel->pData->data;
        delete pDel;
        return reduce();
    }
}

int main(int argc, const char * argv[]) {

    List* mList = new List();
    mList->initList();
    mList->printList();
    Node* pMid = mList->getMiddleNode(mList->pHead);
    if (pMid) {
        cout << "pMid: " << pMid->pData->data << endl;
    }
    
    mList->reduce();
    mList->printList();
    return 0;
}

