#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace sol1079;
using namespace std;

/*takeaways
- in each iteration, take a distinct letter from the set
  to create a new subsequence guaranteed to be unique as
  it starts with a different letter

- {A,A,B}
  - take A to produce A, and you have {A,B} left (level 1)
    - take A to produce AA, and you have {B} left (level 2)
      - take B to produce AAB (level 3)
    - take B to produce AB, and you have {A} left (level 2)
      - take A to produce ABA (level 3)
  - take B to produce B, and you have {A, A} left (level 1)
    - take A to produce BA, and you have {A} left (level 2)
      - take A to produce BAA (level 3)
- so in total, you have eight different possibilities

*/

int Solution::_find(vector<int> &counter)
{
  auto result = 0;
  for (auto i = 0; i < 26; i++)
  {
    if (counter[i] == 0)
      continue;
    /*  take the tile out of the set
       - this will be the first char of the subsequence created
    */
    counter[i]--;
    result++;
    /* all the possible subsequences formed by the remaining
       chars in the set
    */
    result += _find(counter);
    
    /*restore the state to be ready for the next round */
    counter[i]++; 
   
  }
  return result;
}

int Solution::findNum(string tiles)
{
  auto counter = vector<int>(26);
  for (auto t : tiles)
    counter[t - 'A']++;

  return _find(counter);
}