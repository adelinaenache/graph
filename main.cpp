#include <iostream>
#include <cassert>
#include "src/Stack.h"
#include "src/Queue.h"
#include "src/Vector.h"
#include "src/Graph.h"

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

void vectorTests() {
	Vector<int> v, v2;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	// Copy constructor tests
	v2 = v;
	assert(v2[0] == 1);
	assert(v2[1] == 2);
	assert(v2[2] == 3);

}

void graphTests() {
	Vector<Pair> edges;
	edges.push_back(Pair(1, 2));
	edges.push_back(Pair(1, 3));
	edges.push_back(Pair(1, 4));
	edges.push_back(Pair(3, 4));
	edges.push_back(Pair(3, 5));
	edges.push_back(Pair(2, 5));
	
	Graph g(5, edges);

	// BFS Test
	Vector<Pair> sol = g.bfs(1);
	assert(sol.length() == 5);
	assert(sol[0].first() == 1);
	assert(sol[0].second() == 0);
	assert(sol[1].first() == 2);
	assert(sol[1].second() == 1);
	assert(sol[2].first() == 3);
	assert(sol[2].second() == 1);
	assert(sol[3].first() == 4);
	assert(sol[3].second() == 1);
	assert(sol[4].first() == 5);
	assert(sol[4].second() == 2);
}

int main() {
	vectorTests();
	graphTests();
	stackTests();
	queueTests();
	return 0;
}