
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <stack>

using namespace std;
namespace sol1079
{

  class Solution
  {
  private:
    int _find(vector<int> &counter);

  public:
    int findNum(string tiles);
  };
}
#endif