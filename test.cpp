// Kevin Tang
// 8/12/2019

// To compile: g++ test.cpp -o test

#include "MyStack.h"
#include <deque>
#include <cassert>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	MyStack<int> s;
	deque<int> ref;

	for (int i = 0; i < 100; ++i) {
		ref.push_back(i);
		s.push(i);

		if (i % 7 == 0) {
			assert(ref.back() == s.pop());
			ref.pop_back();
		}
		else if (i % 6 == 0) {
			assert(ref.back() == s.pop());
			ref.pop_back();
			assert(ref.back() == s.pop());
			ref.pop_back();
			assert(ref.back() == s.pop());
			ref.pop_back();
		}
		else if (i % 3 == 0) {
			int num = (100 - i) * (i % 7);
			ref.push_back(num);
			s.push(num);
		}


	}

	while (!ref.empty()) {
		cout << ref.back() << endl;
		assert(ref.back() == s.pop());
		ref.pop_back();
	}
}

