#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int in() {
    char c;
    while (c = getchar(), (c < '0' || c > '9') && (c != '-'));
    bool flag = (c == '-');
    if (flag) c = getchar();
    int x = 0;
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - 48;
        c = getchar();
    }
    return flag ? -x : x;
}

void out(int x) { //int
    if (x < 0) putchar('-'), x = -x;
    int len = 0, bit[10]; // LL  -> bit[20]
    while (x) {
        bit[len++] = x % 10;
        x /= 10;
    }
    if (!len) bit[len++] = 0;
    while (len--) putchar(bit[len] + 48);
    putchar('\n');
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif


    return 0;
}


