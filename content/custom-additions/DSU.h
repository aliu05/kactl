/**
 * Author: me
 * Description: DSU with path compression and union by size.
 * Time: O(\log N)
 */
#pragma once

struct DSU {
    vector<i64> repr, size;
    DSU(i64 n) {
        repr = vector<i64>(n);
        size = vector<i64>(n, 1);
        for(i64 i = 0; i < n; ++i) repr[i] = i;
    }

    i64 getRep(i64 x) { return (repr[x] == x? x : repr[x] = getRep(repr[x])); }
    bool sameSet(i64 x, i64 y) { return getRep(x) == getRep(y); }
    i64 getSize(i64 x) { return size[getRep(x)]; }

    void unite(i64 x, i64 y) {
        x = getRep(x);
        y = getRep(y);
        if(x != y) {
            if(size[x] < size[y]) swap(x, y);
            repr[y] = x;
            size[x] += size[y];
        }
    }
};