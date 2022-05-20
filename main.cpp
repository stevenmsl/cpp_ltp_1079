#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1079;

/*
Input: "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
*/

tuple<string, int>
testFixture1()
{

  return make_tuple("AAB", 8);
}

/*
Input: "AAABBC"
Output: 188
*/

tuple<string, int>
testFixture2()
{

  return make_tuple("AAABBC", 188);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << to_string(get<1>(f)) << endl;
  Solution sol;
  cout << sol.findNum(get<0>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see: " << to_string(get<1>(f)) << endl;
  Solution sol;
  cout << sol.findNum(get<0>(f)) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}