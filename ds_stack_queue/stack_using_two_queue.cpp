/*
Implement Stack using Queues By making push() operation costly:]

The idea is to keep newly entered element at the front of ‘q1’ so that pop operation dequeues from ‘q1’. ‘q2’ is used to put every new element in front of ‘q1’.

    push(s, x): O(N)
        Enqueue x to q2.
        One by one dequeue everything from q1 and enqueue to q2.
        Swap the queues of q1 and q2.
    pop(s): O(1)
        Dequeue an item from q1 and return it.
*/
/* Program to implement a stack using
two queue */
#include <bits/stdc++.h>

using namespace std;

class Stack {
	// Two inbuilt queues
	queue<int> q1, q2;

public:
	void push(int x)
	{
		// Push x first in empty q2
		q2.push(x);

		// Push all the remaining
		// elements in q1 to q2.
		while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}

		// swap the names of two queues
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
	}

	void pop()
	{
		// if no elements are there in q1
		if (q1.empty())
			return;
		q1.pop();
	}

	int top()
	{
		if (q1.empty())
			return -1;
		return q1.front();
	}

	int size() { return q1.size(); }
};

// Driver code
int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);

	cout << "current size: " << s.size() << endl;
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;

	cout << "current size: " << s.size() << endl;
	return 0;
}

/*
Implement Stack using Queues by making pop() operation costly:
The new element is always enqueued to q1. In pop() operation, if q2 is empty then all the elements except the last, are moved to q2. Finally, the last element is dequeued from q1 and returned.

Push(s, x): O(1) 
    Enqueue x to q1 (assuming the size of q1 is unlimited).
Pop(s): O(N) 
    One by one dequeue everything except the last element from q1 and enqueue to q2.
    Dequeue the last item of q1, the dequeued item is the result, store it.
    Swap the names of q1 and q2
    Return the item stored in step 2.
*/

// Program to implement a stack
// using two queue
#include <bits/stdc++.h>
using namespace std;

class Stack {
	queue<int> q1, q2;

public:
	void pop()
	{
		if (q1.empty())
			return;

		// Leave one element in q1 and
		// push others in q2.
		while (q1.size() != 1) {
			q2.push(q1.front());
			q1.pop();
		}

		// Pop the only left element
		// from q1
		q1.pop();

		// swap the names of two queues
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
	}

	void push(int x) { q1.push(x); }

	int top()
	{
		if (q1.empty())
			return -1;

		while (q1.size() != 1) {
			q2.push(q1.front());
			q1.pop();
		}

		// last pushed element
		int temp = q1.front();

		// to empty the auxiliary queue after
		// last operation
		q1.pop();

		// push last element to q2
		q2.push(temp);

		// swap the two queues names
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
		return temp;
	}

	int size() { return q1.size(); }
};

// Driver code
int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);

	cout << "current size: " << s.size() << endl;
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	cout << "current size: " << s.size() << endl;
	return 0;
}
// This code is contributed by Chhavi
