#pragma once
#include <iostream>
#include <assert.h>
#include "Node.h"

class DoublyLinkedList {
	NodeD* head;
	NodeD* tail;
public:
	int length;
	DoublyLinkedList() {
		head = nullptr;
		tail = nullptr;
		length = 0;
	}

	void append(int value) {
		NodeD* newNode = new NodeD(value);
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			NodeD* temp = tail;
			tail->next = newNode;
			tail = newNode;
			newNode->prev = temp;
		}
		length++;
	}

	void prepend(int value) {
		NodeD* newNode = new NodeD(value);
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		length++;
	}

	void insert(int value, int index) {
		//assert(index > length || index < 0);
		if (head == nullptr || index == 0) {
			prepend(value);
			return;
		}
		else if (index == length) {
			append(value);
			return;
		}
		else {
			NodeD* newNode = new NodeD(value);
			NodeD* curr = head;
			for (int i = 0; i < index - 1; i++) {
				curr = curr->next;
			}
			newNode->next = curr->next;
			curr->next = newNode;
			newNode->prev = curr;
			newNode->next->prev = newNode;
		}
		length++;
	}

	void pop() {
		if (head == nullptr) {
			std::cout << "List Empty ";
			return;
		}
		else if (length == 1) {
			NodeD* temp = tail;
			tail = tail->prev;
			delete temp;
		}
		else {
			NodeD* temp = tail;
			tail = tail->prev;
			tail->next = nullptr;
			delete temp;
		}
		length--;
	}

	void prepop() {
		if (head == nullptr) {
			std::cout << "List empty ";
			return;
		}
		else if(length == 1){
			NodeD* temp = head;
			head = head->next;
			delete temp;
		}
		else {
			NodeD* temp = head;
			head = head->next;
			head->prev = nullptr;
			delete temp;
		}
		length--;
	}

	void remove(int index) {
		//assert(index >= length || index < 0);
		if (head == nullptr) {
			std::cout << "List Empty";
			return;
		}
		else if (index == 0) {
			prepop();
			return;
		}
		else if (index == length-1) {
			pop();
			return;
		}
		else {
			NodeD* curr = head;
			for (int i = 0; i < index - 1; i++) {
				curr = curr->next;
			}
			NodeD* temp = curr->next;
			curr->next = curr->next->next;
			curr->next->prev = curr;
			delete temp;
		}
		length--;
	}

	void print() {
		NodeD* curr = tail;
		while (curr != nullptr) {
			std::cout << curr->value << " ";
			curr = curr->prev;
		}
		std::cout << "\n";
	}
};

