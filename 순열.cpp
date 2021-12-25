#include <iostream>
#include <vector>
using namespace std;

int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int cnt, n, r;
int visited[1000];
int order[1000];

void permutation(int now)
{
    if (now == r)
    {
        for (int i = 0; i < r; i++)
        {
            cout << arr[order[i]] << " ";
        }
        cout << endl;
        cnt++;

        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        order[now] = i;
        permutation(now + 1);
        visited[i] = false;
    }
}

int main()
{
    cout << "n : ";
    cin >> n;
    cout << "r : ";
    cin >> r;
    cout << n << 'P' << r << endl;

    permutation(0);
    cout << "순열의 개수 : " << cnt;
}