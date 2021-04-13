#pragma once
#include "singly_LL.h"

void LinkedList::reverse() {
	Node* first = head;
	tail = head;
	Node* second = head->next;
	while (second != nullptr) {
		Node* temp = second->next;
		second->next = first;
		first = second;
		second = temp;
	}

	head->next = nullptr;
	head = first;
}
