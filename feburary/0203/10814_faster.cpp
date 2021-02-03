#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
vector<string> v[201];

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        v[age].push_back(name);
    }
}

int main(void)
{
    init();

    for(int i=1; i<=200; i++)
    {
        int size = v[i].size();
        for(int j=0; j<size; j++)
        {
            cout << i << ' ' << v[i][j] << '\n';
        }
    }

    return 0;
}
