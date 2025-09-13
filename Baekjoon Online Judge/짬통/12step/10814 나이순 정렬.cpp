#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class member {
    private:
        string name;
        int age;
        int rank;
    public:
        
        member(string name, int age, int rank) {
            this->name = name;
            this->age = age;
            this->rank = rank;
        }
        bool operator < (const member &b) {
            if(this->age == b.age) return this->rank < b.rank;
            else return this->age < b.age;
        }
        // bool operator == (const word &b) {
        //     return this->content == b.content;
        // }
        void print() {
            cout << this->age << " " << this->name << '\n';
        }

};

int main(void)
{
    int N;
    string tmp;
    int tmp2;
    cin >> N;
    vector<member> members;
    for(int i = 0; i < N; i++) {
        cin >> tmp2 >> tmp;
        members.push_back(member(tmp, tmp2, i));
    }
    sort(members.begin(),members.end());

    for(int k = 0; k < members.size(); k++) {
        members[k].print();
    }
}





