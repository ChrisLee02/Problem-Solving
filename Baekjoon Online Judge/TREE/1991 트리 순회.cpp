/*

 */

#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()

using namespace std;

int N, M;

//vector<int> adj[27];
int parent[27];
int Right[27];
int Left[27];

void preorder(int Node) {
    if(Node == -1) {
        return;
    }
    cout << (char)(Node + 'A');
    preorder(Left[Node]);
    preorder(Right[Node]);
}

void inorder(int Node) {
    if(Node == -1) {
        return;
    }
    inorder(Left[Node]);
    cout << (char)(Node + 'A');
    inorder(Right[Node]);
}

void postorder(int Node) {
    if(Node == -1) {
        return;
    }
    postorder(Left[Node]);
    postorder(Right[Node]);
    cout << (char)(Node + 'A');
}


int main()
{
    FastIO;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        char tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        Left[tmp1 - 'A'] = tmp2 =='.' ? -1 : tmp2 - 'A';
        Right[tmp1 - 'A'] = tmp3 =='.' ? -1:tmp3 - 'A';
    }

    preorder(0);
    cout << endl;
    inorder(0);
    cout<<endl;
    postorder(0);





}