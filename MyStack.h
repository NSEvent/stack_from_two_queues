// Kevin Tang
// 8/12/2019

// To compile: g++ test.cpp -o test

#include <queue>

template <class T>
class MyStack {
public:
	MyStack() {}

	void push(T val) {
		if (q2.empty()) {
			q1.push(val);	
		}	
		else if (q1.empty()) {
			q2.push(val);
		}
	}

	T pop() {
		if (!q1.empty()) {
			while (q1.size() > 1 ) {
				q2.push(q1.front());
				q1.pop();
			}
			T res = q1.front();
			q1.pop();
			return res;
		}

		else if (!q2.empty()) {
			while (q2.size() > 1 ) {
				q1.push(q2.front());
				q2.pop();
			}
			T res = q2.front();
			q2.pop();
			return res;
		}
	}



private:
	std::queue<T> q1;
	std::queue<T> q2;


};

