#pragma once

struct Node {
	int value;
	Node* next;

	Node(int value) {
		this->value = value;
		next = nullptr;
	}
};


struct NodeD {
	int value;
	NodeD* next;
	NodeD* prev;

	NodeD(int value) {
		this->value = value;
		next = nullptr;
		prev = nullptr;
	}
};