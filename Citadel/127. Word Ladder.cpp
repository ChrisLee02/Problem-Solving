#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  inline bool transformable(const string& s1, const string& s2) {
    int count = 0;
    for (int i = 0; i < s1.size(); i++) {
      if (s1[i] != s2[i]) count++;
    }
    return count == 1;
  }

 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordListSet(wordList.begin(), wordList.end());
    unordered_map<string, unordered_set<string>> edges;
    unordered_map<string, int> dist;

    for (int i = 0; i < wordList.size(); i++) {
      for (int cidx = 0; cidx < wordList[i].size(); cidx++) {
        for (char c = 'a'; c <= 'z'; c++) {
          string candidate = wordList[i];
          if (candidate[cidx] == c) continue;

          candidate[cidx] = c;
          if (wordListSet.find(candidate) != wordListSet.end()) {
            edges[wordList[i]].insert(candidate);
          }
        }
      }
    }

    for (int i = 0; i < wordList.size(); i++) {
      if (transformable(beginWord, wordList[i])) {
        edges[beginWord].insert(wordList[i]);
        edges[wordList[i]].insert(beginWord);
      }
    }

    queue<string> Q;
    Q.push(beginWord);
    dist[beginWord] = 1;

    while (!Q.empty()) {
      string vertex = Q.front();
      Q.pop();

      for (string neighbor : edges[vertex]) {
        if (dist.find(neighbor) == dist.end()) {
          dist[neighbor] = dist[vertex] + 1;
          Q.push(neighbor);
        }
      }
    }

    if (dist.find(endWord) == dist.end()) return 0;
    return dist[endWord];
  }
};