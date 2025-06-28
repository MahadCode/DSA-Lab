#include"List.h"

int loneLiest(List& I) {
	I.start();

	int maxLone = INT_MIN;
	for (int i = 0; i < I.length(); i++) {
		int current = I.get();
		int sum = 0;

		I.start();
		for (int i = 0; i < I.length(); i++) {
			int adding = current - I.get();
			if (adding < 0) {
				adding = -adding;
			}
			sum = sum + adding;
			I.next();
		}
		
		maxLone = max(maxLone, sum);

		I.start();
		while (current!=I.get()) {
			I.next();
		}

		I.next();
	}


	I.start();
	for (int i = 0; i < I.length(); i++) {
		int current = I.get();
		int sum = 0;

		I.start();
		for (int i = 0; i < I.length(); i++) {
			int adding = current - I.get();
			if (adding < 0) {
				adding = -adding;
			}
			sum += adding;
			I.next();
		}

		if (sum == maxLone) {
			return current;
		}

		I.start();
		while (current != I.get()) {
			I.next();
		}

		I.next();
	}
}

void fold(List& I) {
	int i = 0;
	int noPair = I.length() / 2;

	while (i<noPair) {
		I.start();
		for (int j = 0; j < i; j++) {
			I.next();
		}
		int left = I.get();

		I.end();
		for (int j = 0; j < i; j++) {
			I.back();
		}
		int right = I.get();
		int pair = left + right;

		I.start();
		for (int j = 0; j < i; j++) {
			I.next();
		}
		I.update(pair);

		i++;
	}

	I.end();
	for (int k = 0; k < i; k++) {
		I.remove();
	}
}


//void raindropCascade(List& I, int k) {
//	if (k < 0 || k >= I.length()) {
//		return;
//	}
//
//		I.start();
//		for (int i = 0; i < k; i++) {
//			I.next();
//		}
//
//		int given = I.get();
//		cout << given << endl;
//
//		int j = k;
//		int current;
//		while (true) {
//			j++;
//			I.next();
//			current = I.get();
//			if (current < given || j == I.length()) {
//				break;
//			}
//		}
//
//		I.start();
//		for (int i = 0; i < j; i++) {
//			I.next();
//		}
//		I.update(given);
//	
//	
//}

void raindropCascade(List& I, int k) {
	if (k < 0 || k >= I.length()) {
		return;
	}

	int index=k;
	while (index<=I.length()) {
		I.start();
		for (int i = 0; i < index; i++) {
			I.next();
		}

		int given = I.get();
		cout << given << endl;

		int j = index;
		int current;
		while (true) {
			j++;
			I.next();
			current = I.get();
			if (current < given || j == I.length()) {
				break;
			}
		}

		I.start();
		for (int i = 0; i < j; i++) {
			I.next();
		}
		I.update(given);

		if (j == I.length()) {
			break;
		}
		
		index = j - 1;
	}

}

int main() {

	List b(10);
	b.add(10);
	b.add(15);
	b.add(20);

	cout << loneLiest(b);

	List c(10);
	c.add(3);
	c.add(6);
	c.add(9);
	c.add(12);
	fold(c);
	c.display();

	List a(10);
	a.add(6);
	a.add(3);
	a.add(7);
	a.add(2);
	a.add(5);
	raindropCascade(a, 1);
	a.display();
}