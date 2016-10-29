/*
 * SLL.cpp
 *
 *  Created on: Sep 26, 2016
 *      Author: Debra
        student: Zeke Faison
 */

#include "SLL.hpp"
#include "SNode.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

SLL::SLL(){
	first = NULL;
	last = NULL;
	size = 0;
}
SLL::~SLL(){
	SNode *tmp = first;
	while (first != NULL) {
		tmp = first->next;
		delete first;
		first = tmp;
		size --;
	}
	first = NULL;
	last = NULL;
}
void SLL::printSLL() {
    //prints SLL
	SNode *tmp = first;
	while (tmp != NULL) {
		cout << tmp->data << "->";
		tmp = tmp->next;
	}
	cout << endl;
}//printSLL

void SLL::addFirst(int x) { // 3 pts
//make a new list of only one node, data is x
    size++;
    SNode *begin = new SNode(x);
    begin->next = NULL;
    first = begin;
    last = begin;
    
    return;
}//addFirst

void SLL::addAtFront(int x) {  //3 pts
//add a new node to the front of the list with data being x
    
    SNode *temp = first;
    
    SNode *newFirst = new SNode(x);
    
    newFirst->next = temp;
    first = newFirst;
    cout<<"first next: " << newFirst->next<<endl;
    
    if(first->next == NULL){
        
        last = temp;
        temp->next = NULL;
    }//if
    cout<< newFirst<<endl;
    return;
}//addAtFront

void SLL::push(int x) { //6 pts
//add a new node to the end of the list, with data x
    size++;
    SNode *end = new SNode(x);
    end->next = NULL;
    last->next = end;
    last = end;
   
}//push

void SLL::addAtK(int x, int k){
    //adds a node to a specific place k into a list
    cout<<"size: " << size<<endl;
	SNode *tmp = first;
	if (k==0) {
		addAtFront(x);
		size++;
    }//if
	if (k < size  && k > 0) {
		for (int i = 0; i < k-1; i++) {
			tmp = tmp->next;
        }//for
		SNode *tmp2 = tmp->next;
		tmp->next = new SNode(x);
		tmp->next->next = tmp2;
		size++;
    }//if
}//addAtK

void SLL::join(SLL *list2){ //3 pts
//join the list with list2, making the current list one longer list
    SNode *temp = list2->first;
    size += list2->size;
    last->next = temp;
    last = temp;
    list2->size--;
    
    last  = list2->last;
    
    return;
}//join

int SLL::pop() {
    //adds nodes to the end of the list
	if (size > 0) {
		int x = last->data;
		if (first != last ){
			SNode *tmp = first;
            cout<<"tmp nex: "<< tmp->next<<endl;
			for (int i = 0; i < size-1;i++) {
                if(tmp->next !=last){
                    tmp = tmp->next;
                }//if
			}
            cout<<"deleting: " << last->data<<endl;
            if(last->next != NULL){
                last->next = NULL;
            }//if
            
			delete last;
			last = tmp;
            cout<<"new last: " <<last->data<< endl;
			last->next = NULL;
		}
		else {
			delete last;
			first = NULL;
			last = NULL;
		}
		size --;
        cout<<"new size: "<<size<<endl;
		return x;
	}
	else {
		return -1;
	}
}//pop

SNode *SLL::findKth(int k) { //4 pts
// find the node at the kth location and return it
    SNode *ap;
    SNode *start = first;
    for(int searching = 0; searching < k; searching ++){
        start = start->next;
        
    }//for
    ap = start;
    return ap;
}//findKth

int SLL::findK(int k) {
    //finds the first instance of a node that holds the value k in data
	SNode *tmp = first;
	int ind = 0;
	while (tmp != NULL && tmp->data != k) {
		tmp = tmp->next;
		ind++;
	}
	if (ind < size) {
		return ind;
	}
	else {
		return -1;
	}
}//findk

int SLL::remFirst() { //3 pts
//remove the first node from the list, returning its data
    int returnData = first->data;
    SNode * temp = first->next;
    first->next = NULL;
    delete first;
    
    size--;
    first = temp;
    cout<<size<<endl;
    return returnData;
    
}//remFirst

int SLL::remKth(int k) {
    //removes a node at kth place in a list
	if (k < size && k > 0) {
		SNode *tmp = first;
		for (int i = 0; i < k -1; i++) {
			tmp = tmp->next;
		}
		int x = tmp->next->data;
		SNode *tmp2= tmp->next;
		tmp->next = tmp->next->next;
		delete tmp2;
        size--;
		return x;
	}
    
    return 0;
}//remKth

void SLL::reverseList(){ //10 pts
//Reverses the list, after completed, the last should be the first
//in the list and the first should be the last
//Challenge - I did this with one pass across the list
    SNode *tmp = first;
    SNode *prev = NULL;
    SNode *next = NULL;
    while(tmp!=NULL){
        next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
    }//while
    first= prev;
}//reverseList

