#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  enum class Rotation { TURN_LEFT = -2, TURN_RIGHT = -1 };
  enum class Direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3,
  };

  inline pair<int, int> getDeltaPair(Direction dir) {
    switch (dir) {
      case Direction::NORTH:
        return {0, 1};
      case Direction::EAST:
        return {1, 0};
      case Direction::SOUTH:
        return {0, -1};
      case Direction::WEST:
        return {-1, 0};
      default:
        return {-1, -1};  // not happen
    }
  }

  inline Direction getRotatedDir(Direction dir, Rotation rotation) {
    if (rotation == Rotation::TURN_RIGHT) {
      return Direction((static_cast<int>(dir) + 1) % 4);
    } else {
      return Direction((static_cast<int>(dir) + 4 - 1) % 4);
    }
  }

  struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
      return (static_cast<size_t>(p.first) << 32) ^
             static_cast<size_t>(p.second);
    }
  };

  inline void move_forward(
      pair<int, int>& pos, const Direction dir, const int step,
      const unordered_set<pair<int, int>, PairHash>& obstacles_set) {
    const auto [dx, dy] = getDeltaPair(dir);
    for (int i = 0; i < step; i++) {
      pair<int, int> tmp = pair<int, int>{pos.first + dx, pos.second + dy};
      if (obstacles_set.find(tmp) != obstacles_set.end()) {
        return;
      }

      pos.first += dx;
      pos.second += dy;
    }
  }

 public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    Direction dir = Direction::NORTH;
    pair<int, int> position = {0, 0};
    unordered_set<pair<int, int>, PairHash> obstacles_set;

    for (const vector<int>& obstacle : obstacles) {
      obstacles_set.insert({obstacle[0], obstacle[1]});
    }

    int ans = 0;

    for (int command : commands) {
      if (command == -2) {
        dir = getRotatedDir(dir, Rotation::TURN_LEFT);
      } else if (command == -1) {
        dir = getRotatedDir(dir, Rotation::TURN_RIGHT);
      } else {
        move_forward(position, dir, command, obstacles_set);
        ans = max(ans, position.first * position.first +
                           position.second * position.second);
      }
    }

    return ans;
  }
};