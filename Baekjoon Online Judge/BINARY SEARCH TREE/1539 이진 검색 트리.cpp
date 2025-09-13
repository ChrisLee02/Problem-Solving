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

int N;

typedef struct node {
    int data;
    node *left;
    node *right;
    int height;

    node(int data, node *left, node *right, int height) {
        this->data = data;
        this->left = left;
        this->right = right;
        this->height = height;
    }
} node;

class BST {
private:
    node root = node(0, nullptr, nullptr, 1);
public:

    void init_BST(int root_value) {
        root.data = root_value;
    }

    void insert(int X) {
        insert_node(&root, X);
    }

    void insert_node(node *V, int x) {
        //   cout <<"value: " << V->data << endl;
        if (x < V->data) {
            if (V->left != nullptr) {
                //  cout << "case 1" << endl;
                insert_node(V->left, x);
            } else {
                // cout << "case 2" << endl;
                V->left = new node(x, nullptr, nullptr, V->height + 1);
            }
        } else {
            if (V->right != nullptr) {
                //  cout << "case 3" << endl;
                insert_node(V->right, x);
            } else {
                // cout << "case 4" << endl;
                V->right = new node(x, nullptr, nullptr, V->height + 1);
            }
        }
    }

    void calculate_height_sum(long long *sum) {
        calculate_height_sum_node(&root, sum);
    }

    void calculate_height_sum_node(node *V, long long *sum) {
        if (V == nullptr) return;
        //cout << V->data << endl;
        *sum += V->height;
        calculate_height_sum_node(V->left, sum);
        calculate_height_sum_node(V->right, sum);
    }


};

// 진짜 BST로 하면 시간초과가 나지 이 사람아,,
// 오름차순, 내림차순의 연속 부분 배열을 한번에 처리할 수 있다면? -> 얘도 소용없음,,

// 그냥 set에 집어넣을거다. 시발련들아. set에 키값과 높이를 pair로 저장할 것.
// 그러면 삽입은 logn에 쌉가능. 문제는 높이를 계산하는건데, 이건 예시를 보면 된다.
// 1 4 5를 넣는다고 생각해보자. 1 -> 5-> 4 순으로 들어간다면 4의 높이는 height(5) + 1 = 3임. 5->1>4  순이면 4의 높이는 height(1) + 1 = 3임
// 다시말해서, 양쪽 노드 중 더 높은 높이의 옆에 삽입된다고 보면 된다.

int main() {
    FastIO;
    cin >> N;
    set<pii> list{};
    int tmp;
    cin >> tmp;
    list.emplace(tmp, 1); // root 초기화
    for (int i = 1; i < N; ++i) {
        cin >> tmp;
        auto p = list.lower_bound(pii(tmp, 0));
        pii tmptmp;
        if (p == list.begin()) {
            tmptmp = pii(tmp, p->second + 1);
        } else if (p == list.end()) {
            tmptmp = pii(tmp, prev(p)->second + 1);
        } else {
            tmptmp = pii(tmp, max(p->second, prev(p)->second) + 1);
        }
        list.insert(tmptmp);
    }
    long long sum = 0;

    for (pii i: list) {
        //cout << i.first << " " << i.second << endl;
        sum += i.second;
    }
    cout << sum;


    /* BST bst{};
     int tmp;
     cin >> tmp;
     bst.init_BST(tmp);

     for (int i = 1; i < N; ++i) {
         cin >> tmp;
         bst.insert(tmp);
     }
     long long sum = 0;

     bst.calculate_height_sum(&sum);

     cout << sum;*/

}