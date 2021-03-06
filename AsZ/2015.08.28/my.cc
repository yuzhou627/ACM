#include <bits/stdc++.h>

#define LL unsigned long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

LL poww(LL a, int b) {
    LL ans = 1;
    while (b) {
        if (b & 1) ans = ans * a;
        b >>= 1;
        a *= a;
    }
    return ans;
}

LL getRoot(LL n, int r) {
    LL rt = pow(1.0 * n + 0.5, 1.0 / r);
    if (poww(rt + 1, r) <= n) rt++;
    return rt;
}

vector<int> fac[70];
int p[30] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};
vector<int> good[70];

bool check(int x, int r) {
    vector<int> tmp;
    REP(i, 18) {
        if (p[i] <= r) tmp.push_back(p[i]);
    }
    REP(i, fac[x].size()) {
        if (fac[x][i] > r) {
            return 0;
        }
    }
    REP(i, fac[x].size()) {
        if (x % (fac[x][i] * fac[x][i]) == 0) {
            return 0;
        }
    }
    return 1;
}

void init() {
    REPP(i, 2, 62) {
        REP(j, 18) {
            if (i % p[j] == 0) {
                fac[i].push_back(p[j]);
            }
        }
    }
    REPP(i, 1, 62) {
        REPP(j, 2, 62) {
            if (check(i, j)) {
                good[j].push_back(i);
            }
        }
    }
}

LL calc(LL n, int r) {
    LL ans = 0;
    int odd = 0, even = 0;
    REP(j, good[r].size()) {
        //cout << "good: " << i << endl;
        int i = good[r][j];
        //cout << i << ' ';
        if (fac[i].size() & 1) {
            ans -= getRoot(n, i);
            odd++;
        }
        else {
            ans += getRoot(n, i);
            even++;
        }
    }
    //cout << endl;
    //cout << odd << ' ' << even << endl;
    ans += odd - even;
    return ans;
}

LL in() {
	char c;
	while (c = getchar(), (c < '0' || c > '9') && (c != '-'));
	bool flag = (c == '-');
	if (flag) c = getchar();
	LL x = 0;
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - 48;
		c = getchar();
	}
	return flag ? -x : x;
}

void out(LL x) { //int
	if (x < 0) putchar('-'), x = -x;
	int len = 0, bit[20]; // LL  -> bit[20]
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
    //freopen("J.in", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
#define lld I64d
#endif
    //clock_t st = clock(), ed;
    init();
    //ed = clock();
#ifdef HOME
    //cout << fixed << setprecision(10) << 1.0 * (ed - st) / CLOCKS_PER_SEC << endl;
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        LL n;
        int r;
        n = in(), r = in();
        //scanf("%lld%d", &n, &r);
        //LL lo = 0, hi = (1LL << 62) - 1;
        LL lo = 0, hi = 2 * n + 5;
        while (lo + 1 < hi) {
            LL mid = (lo + hi) >> 1;
            if (calc(mid, r) < n) lo = mid;
            else hi = mid;
        }
        out(hi);
        //printf("%lld\n", hi);
    }

    return 0;
}
