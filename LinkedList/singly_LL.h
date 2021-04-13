#pragma once
#include <iostream>
#include "Node.h"

class LinkedList {
	Node* head;
	Node* tail;
	
public:
	int length;
	LinkedList() {
		head = nullptr;
		tail = nullptr;
		length = 0;
	}

	void append(int value) {
		Node* const newNode = new Node(value);

		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		length++;
	}

	void prepend(int value) {
		Node* const newNode = new Node(value);

		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}

		length++;
	}

	void insert(int value, int index){

		if (index == 0 || head == nullptr) {
			prepend(value);
			return;
		}
		else if (index == length) {
			append(value);
			return;
		}
		else {
			Node* curr = head;
			Node* newNode = new Node(value);
			for (int i = 0; i < index - 1; i++) {
				curr = curr->next;
			}
			newNode->next = curr->next;
			curr->next = newNode;
		}
		length++;
	}

	void deleteAt(int index) {

		if (head == nullptr) {
			return;
		}
		else if (index == 0) {
			prepop();
			return;
		}
		else if (index == length - 1) {
			pop();
			return;
		}
		else {
			Node* curr = head;
			for (int i = 0; i < index - 1; i++) {
				curr = curr->next;
			}
			length--;
			Node* delNode = curr->next;
			curr->next = curr->next->next;
			delete delNode;
		}
		length--;
	}

	void pop() {
		if (head == nullptr) {
			std::cout << "List empty ";
			return;
		}
		else {
			Node* curr = head;
			while (curr->next->next != nullptr) {
				curr = curr->next;
			}
			Node* delNode = curr->next;
			curr->next = curr->next->next;
			delete delNode;
			tail = curr;
		}
		length--;
	}

	void prepop() {
		if (head == nullptr) {
			std::cout << "List empty ";
			return;
		}
		else {
			Node* temp = head->next;
			delete head;
			head = temp;
		}
		length--;
	}

	void print() {
		Node* curr = head;

		while(curr != nullptr){
			std::cout << curr->value << " ";
			curr = curr->next;
		}
		std::cout << "\n";
	}

	void reverse();
};

