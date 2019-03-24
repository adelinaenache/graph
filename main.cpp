#include <iostream>
#include <cassert>
#include "src/Stack.h"
#include "src/Queue.h"

using namespace std;

void stackTests() {
	Stack s;
	s.push(3);
	assert(s.empty() == false);
	assert(s.capacity() == 5);
	assert(s.length() == 1);
	assert(s.peek() == 3);
	s.push(4), s.push(5), s.push(6), s.push(7);
	assert(s.full() == true);
	s.push(8), s.push(9);
	assert(s.capacity() == 10);
	assert(s.length() == 7);
	assert(s.peek() == 9);
	s.pop();
	assert(s.peek() == 8);
	assert(s.length() == 6);
	Stack copy(s);
	assert(copy.length() == 6);
	assert(copy.capacity() == 10);
	assert(copy.peek() == s.peek());
}

void queueTests() {
	Queue q;
	assert(q.empty());
	q.push(1), q.push(2), q.push(3); // should resize store
	assert(q.peek() == 1);
	assert(q.length() == 3);
	assert(q.capacity() == 5);
	q.push(4), q.push(22);
	q.pop();
	assert(q.peek() == 2);
	assert(q.length() == 4);
	assert(q.capacity() == 5);
	q.push(100); // should resize store
	assert(q.capacity() == 10);
	q.push(122), q.push(123);
	while (q.length() > 2) {
		q.pop();
	}
	q.push(143), q.push(144);
	q.pop();
	q.push(150); // should shift values
	assert(q.capacity() == 10);
	assert(q.length() == 4);
	while (q.length() > 0) {
		q.pop();
	}
	assert(q.length() == 0);
	assert(q.empty());
}

int main() {
	stackTests();
	queueTests();
	return 0;
}