#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class word {
    private:
        
    public:
        string content;
        word(string a) {
            this->content = a;
        }  
        bool operator < (const word &b) {
            if(this->content.length() != b.content.length()) return this->content.length() < b.content.length();
            else return this->content < b.content;
        }
        bool operator == (const word &b) {
            return this->content == b.content;
        }
        void print() {
            cout << this->content << '\n';
        }

};

int main(void)
{
    int N;
    string tmp;
    cin >> N;
    vector<word> words;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        words.push_back(word(tmp));
    }
    sort(words.begin(),words.end());
    unique(words.begin(),words.end());
    words.erase(unique(words.begin(),words.end()), words.end() );
    for(int k = 0; k < words.size(); k++) {
        words[k].print();
    }
}





 // for(int i = 0; i < words.size() - 1; i++) {
    //     for(int j = 0; j < words.size() - 1-i; j++) {
    //         if( words[j].length()==words[j+1].length() ) {
    //             if( words[j] > words[j+1] ) {
    //                 짬통 = words[j+1];
    //                 words[j+1] = words[j];
    //                 words[j] = 짬통;
    //             }
                
    //         }
    //         else {
    //             if( words[j].length() > words[j+1].length() ) {
    //                 짬통 = words[j+1];
    //                 words[j+1] = words[j];
    //                 words[j] = 짬통;
    //             }
    //         }
    //     }
    // }