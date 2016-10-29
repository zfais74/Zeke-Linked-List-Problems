/*
 * DLL.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: Debra
        Student: Zeke Faison
 */

#include "DLL.hpp"
#include "DNode.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

DLL::DLL(){
	first = NULL;
	last = NULL;
	size = 0;
}
DLL::~DLL(){
	DNode *tmp = first;
	while (first != NULL) {
		tmp = first->next;
		delete first;
		first = tmp;
		size --;
	}
	first = NULL;
	last = NULL;
}
void DLL::printDLL() {
    //prints DLL
	DNode *tmp = first;
	while (tmp != NULL) {
		cout << tmp->data << "->";
		tmp = tmp->next;
	}
	cout << endl;
}//printDLL

void DLL::printRevDLL() {
    //prints reversed DLL
	DNode *tmp = last;
	while (tmp != NULL) {
		cout << tmp->data << "->";
		tmp = tmp->prev;
	}
	cout << endl;
}//printRevDLL

void DLL::addFirst(int x) { //2 pts
//add very first element to list
    DNode *start = new DNode(x);
    size++;
    first = start;
    last = start;
    return;
    
}//addFirst

void DLL::addAtFront(int x) { //2 pts
//	add a new node to the beginning of the list
    DNode *front = new DNode(x);
    first->prev = front;
    front->next = first;
    front->prev = NULL;
    first = front;
    size++;
}//addAtFront

void DLL::push(int x) { //2 pts
// add a new node to the end of the list
    DNode *addList = new DNode(x);
    size++;
    last->next = addList;
    addList->prev = last;
    last = addList;
}//push

void DLL::addAtK(int x, int k){ //4 pts
//add at position k a new node with x as the data
    if(k == 0){
        addAtFront(x);
    }//if
    else{
    DNode *tmp = first;
    DNode *addIn = new DNode(x);
    size++;
    int counter = 0;
    while(counter !=k-1){
        cout<<"Here's tmp"<<tmp<<endl;
        cout<<"Here's its next" << tmp->next<<endl;
        tmp = tmp->next;
        counter++;
    }//while
    addIn->next = tmp->next;
    addIn->prev = tmp;
    tmp->next = addIn;
    }//else
}//addAtK

void DLL::join(DLL *list2){ //2 pts
// join list 2 to the end of the list, modifying the size of the list
    DNode *tmp = list2->first;
    cout<<tmp->data<<endl;
    cout<<list2->last->data<<endl;
    cout<<last->data<<endl;
    size += list2->size;
    tmp->prev = last;
    cout<<"last data: " << last->data<<endl;
    last->next = tmp;
    last = list2->last;
    cout<<"final last data: " << last->data<<endl;
}//join


int DLL::pop() { //5 pts
//popping the last node off the end of the list and returning that data
    DNode *backwards = last->prev;
    int poppedNum = last->data;
    backwards->next = NULL;
    last->prev = NULL;
    delete last;
    size--;
    last = backwards;
    cout<<"last's data: "<<last->data<<endl;
    return poppedNum;
 
}//pop
 

DNode *DLL::findKth(int k) { 
//find the element at the kth position and returning a pointer to that node
    DNode *tmp = first;
    int counter = 0;
    while(counter !=k){
        tmp = tmp->next;
        counter++;
    }//
    return tmp;
}//findKth
 
int DLL::findK(int k) {
    //find node that holds k value in data
	DNode *tmp = first;
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
}//findK

int DLL::remFirst() { //2 pts
//remove the first node from the list, returning its data
    int firstNum = first->data;
    DNode *newFirst = first->next;
    first->next = NULL;
    newFirst->prev = NULL;
    delete first;
    first = newFirst;
    size--;
    cout<<"size: "<<size<<endl;
    return firstNum;
}//remFirst


int DLL::remKth(int k) { //4 pts
//remove the kth element of the list, returning its data
    if(k == size-1){
        int poppedNum = pop();
        return poppedNum;
    }//if
    
    else if(k == 0){
        int firstNum = remFirst();
        return firstNum;
    }//elif
    
    else{
        DNode *tmp = first;
        DNode *nodeBefore;
        int counter = 0;
        while(counter !=k){
            tmp = tmp->next;
            counter++;
        }//while
        nodeBefore = tmp->prev;
        tmp->prev->next = nodeBefore;
        tmp->next->prev = nodeBefore;
        nodeBefore->next = tmp->next;
        int removedNum = tmp->data;
        tmp->prev = NULL;
        tmp->next = NULL;
        delete tmp;
        size--;
        cout<<"last data remove kths: " << last->data<<endl;
        cout<<"bye: " << removedNum << endl;
        return removedNum;
        
    }//else
    
}//remKth
 
void RecursiveReverse(DLL *l2) { //6 pts
// RECURSIVELY reverses the list
    
    
}
void DLL::sortDLL() { //10 pts
//sort the list from smallest to largest
    DNode *tmp = first;
    bool isInOrder = false;
    int counter = 0;
    //keeps on going until the numbers are in order
    while(isInOrder == false){
        //i'm sort of lazy, so i decided to move the data to different nodes instead of moving node pointers
        while(counter < size-1){
            if(tmp->data > tmp->next->data){
                int tmpNum = tmp->data;
                tmp->data = tmp->next->data;
                tmp->next->data = tmpNum;
            }//if
            
            tmp = tmp->next;
            
            counter ++;
        }//while
         //testing out the order of numbers in the list
        counter = 0;
        tmp = first;
        isInOrder = true;
        for(int i =0; i < size-1 ; i++){
            if(tmp->data > tmp->next->data ){
                isInOrder = false;
            }//if
            tmp = tmp->next;
        }//for
        tmp = first;
        
    }//while
}//sortDLL

void DLL::Merge2(DLL *l2) { //10 pts
//Merge two sorted lists into one longer sorted list, and setting
//the current list to the longer sorted list
// Note that I sorted both lists before I called this.
//also note that joining the two lists and then sorting is NOT what I want
//here - I want this function to start at the beginning of each list,
//and pull the smallest of the 2 values into the new list, then move up
//one in that particular list.  
// e.g., 
// l1 = 3,7,12,15,22,23,24,29    l2=4,8,12,13,27
// n=3
// l1 = 7,12,15,22,23,24,29    l2=4,8,12,13,27
// n=3,4
// l1 = 7,12,15,22,23,24,29    l2=8,12,13,27
// n=3,4,7
// l1 = 12,15,22,23,24,29    l2=8,12,13,27
// n=3,4,7,8
// l1 = 12,15,22,23,24,29    l2=12,13,27
// n=3,4,7,8,12
// l1 = 15,22,23,24,29    l2=12,13,27
// n=3,4,7,8,12,12
// l1 = 15,22,23,24,29    l2=13,27
// n=3,4,7,8,12,12,13
// l1 = 15,22,23,24,29    l2=27
// n=3,4,7,8,12,12,13
// l1 = 15,22,23,24,29    l2=27
// n=3,4,7,8,12,12,13,15
// l1 = 22,23,24,29    l2=27
// n=3,4,7,8,12,12,13,15,22
// l1 = 23,24,29    l2=27
// n=3,4,7,8,12,12,13,15,22,23
// l1 = 24,29    l2=27
// n=3,4,7,8,12,12,13,15,22,23,24
// l1 = 29    l2=27
// n=3,4,7,8,12,12,13,15,22,23,24,27
// l1 = 29    l2
// n=3,4,7,8,12,12,13,15,22,23,24,27,29
    size += l2->size;
    //i made two nodes to move along the lists and one
    //node to move around the list after the head node was found
    //i feel like there is a more elegant way to doing this
    
    DNode *traversel1 = NULL;
    DNode *traversel2 = NULL;
    DNode *headNode = NULL;
    
    //if the first value in the 1st list smaller, make that the head
    // if not, make the first value in the 2nd list the head
    
    if(first->data < l2->first->data){
        traversel1 = first->next;
        traversel2 = l2->first;
    }//if
    
    else{
        traversel1 = first;
        first = l2->first;
        traversel2 = l2->first->next;
    }//else
    
    headNode = first;
    
    //if the number in the first list is smaller, make that node next
    while(traversel1 != NULL && traversel2 !=NULL){
        if(traversel1->data < traversel2->data){
            headNode->next = traversel1;
            traversel1->prev = headNode;
            traversel1 = traversel1->next;
            headNode = headNode->next;
        }//if
        
         //just in case any evil twins pop up
        else if(traversel1->data == traversel2->data){
            headNode->next = traversel1;
            traversel1->prev = headNode;
            traversel1 = traversel1->next;
            headNode = headNode->next;
        }//elif
        
        //if the number in the second list is smaller, make that node next
        else{
            headNode->next = traversel2;
            traversel2->prev = headNode;
            traversel2 = traversel2->next;
            headNode = headNode->next;
        }//else
        
        
    }//while
     //it finds the last number needed to complete the list by looking at the node that has reached the end and picking the opposite
     //to pop to the end of the list
    if(traversel1 == NULL){
        headNode->next = traversel2;
        traversel2->prev = headNode;
        traversel2->next = NULL;
        headNode = headNode->next;
        last = headNode;
    }//if
    else{
        headNode->next = traversel1;
        traversel1->prev = headNode;
        traversel1->next = NULL;
        last = headNode->next;
    }//else

    
    
}//merge
void DLL::RemoveDuplicates() { //12pts
// assumes the list is unsorted, removes all duplicates from the list
//Note how massively easier this would be if we just sorted the list first...
// Note also that you can use a helper function if you like
    
    //can i do this? if not, skip!
    /*sortDLL();
    bool isNoDups = false;
    int counter = 0;
    DNode *tmp = first;
    //keeps on going if there are duplicates
    while(isNoDups == false){
        while(counter < size-1){
            
            if(tmp->data == tmp->next->data){
                //removes the duplicates
                int pos = findK(tmp->data);
                remKth(pos+1);
            }//if
            
            cout<<"tmp next num : "<<tmp->next->data<<endl;
            
            tmp = tmp->next;
            counter ++;
        }//while
        
        counter = 0;
        tmp = first;
        isNoDups = true;
        //goes through the list if it there are any duplicates, it'll keep the while loop going
        for(int i =0; i < size-1 ; i++){
            if(tmp->data == tmp->next->data ){
                isNoDups = false;
            }//if
            tmp = tmp->next;
        }//for
        tmp = first;
    }//while
    */
    
   
    DNode *tmp = first;
    DNode *deleteDup = NULL;
    DNode *traverse = NULL;
    int counter= 0;
    //the loop keeps on going unitl the tmp node points to nukk
    while(tmp->next !=NULL && tmp!=NULL){
        traverse = tmp;
        while(traverse->next !=NULL){
            //deletes the duplicate number if the funciton finds one
            if(tmp->data == traverse->next->data){
                deleteDup = traverse->next;
                traverse->next = traverse->next->next;
                remKth(counter);
            }//if
            else{
                traverse = traverse->next;
            }//else
            counter++;
            
        }//while
        if(tmp->next !=NULL){
            tmp = tmp->next;
        }//if
        
        counter = 0;
    }//while
}//removeDuplicates




