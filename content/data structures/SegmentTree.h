/**
 * Author: Lukas Polacek
 * Date: 2009-10-26
 * Source: folklore
 * Description: Zero-indexed max-tree. Bounds are inclusive!
 * Time: O(\log N).
 */
#pragma once
#include <vector>
using namespace std;

const int LOW = -1234567890;
struct Tree {
	int n;
	vi s;
	Tree(int _n) {
		n = 1; while (n < _n) n *= 2;
		s.assign(2 * n, 0);
	}
	void update(int pos, int val) {
		pos += n;
		s[pos] = val;
		for (pos /= 2; pos >= 1; pos /= 2)
			s[pos] = max(s[pos * 2], s[pos * 2 + 1]);
	}
	int query(int a, int b) { return que(1, a, b + 1, 0, n); }
	int que(int pos, int a, int b, int x, int y) {
		if (a >= b) return LOW;
		if (a == x && b == y) return s[pos];
		int m = (x + y) / 2;
		return max(que(2 * pos, a, min(b, m), x, m),
				que(2 * pos + 1, max(a, m), b, m, y));
	}
};