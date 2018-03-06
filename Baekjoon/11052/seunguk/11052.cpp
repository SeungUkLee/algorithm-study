/**
 * 붕어빵 1개 팔어서 얻는 최대 수익 d[1]
 * 붕어빵 2개 팔어서 얻는 최대 수익 d[2]
 * .........
 * 붕어빵 n개 팔어서 얻는 최대 수익 d[n]
 * 
 * 경우의 수를 모두 생각하자.
 * 붕어빵 1개를 p[1]에 팔고 남은 붕어빵 갯수는 n-1 => p[1] + d[n-1]
 * 붕어빵 2개를 p[2]에 팔고 남은 붕어빵 갯수는 n-2 => p[2] + d[n-2]
 * .........
 * 붕어빵 n-1개를 p[n-1]에 팔고 남은 붕어빵 갯수는 1 => p[n-1] + d[1]
 * 붕어빵 n  개를 p[n]  에 팔고 남은 붕어빵 갯수는 0 => p[n] + d[0]
 * 
 * 위 모든 경우의 수 중에서 최대값을 찾으면 된다.
 */
#include <iostream>

using namespace std;

int d[10001];

int main() {
    int n; //붕어빵 갯수
    cin >> n;
    int p[n+1]; //붕어빵 가격

    for (int i=1; i<=n; i++) {
        cin >> p[i];
    }

    for (int i=1; i<=n; i++ ) {
        for (int j=1; j<=i; j++) {
            d[i] = max(d[i], p[j] + d[i-j]);
        }
    }

    cout << d[n] << '\n';

    return 0;
}