#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

string getShortestUniqueSubstring( const vector<char>& arr, const string &str ) 
{
  // your code goes here
  /*"xyyzyzyx"
        l
          r */
   int left = 0, right = 0;
   set<char> st;
   map<char, int> freq;
   if(str.empty()) return "";
  
   int mn = 10000000;
   map<char, bool> exists;
   for(auto ele : arr){
     exists[ele] = true;
   }
  
    if(exists[str[0]]){
      st.insert(str[0]);
      freq[str[0]]++;
    }
  /*
  x , y 
  xzxzy
  s= { x , z}
  
  */
 //                           l  r
  // ["A","B","C"], "ADOBECODEBANCDDD"
  
   int leftIdx = 0;
   while(left <= right){ 
       cout << left << " " << right << "\n";
     if(st.size() < arr.size()){
       right++;
       if(right >= str.size()) break;
       if(exists[str[right]])
         st.insert(str[right]);
       freq[str[right]] ++;
     }else{
       //mn = min(mn, right - left + 1);
       if(right - left + 1 < mn){
         leftIdx = left;
         //rightIdx = right;
         mn = right - left + 1;
         cout << mn << "\n";
       }
       
       freq[str[left]]--;
       if(freq[str[left]] == 0) {
         if(st.find(str[left]) != st.end())
           st.erase(st.find(str[left]));
       }
       left++;
     }
   }
   cout << "mn " << mn << "\n";
   cout << leftIdx << "\n";
   if(mn == 10000000) return "";
   return str.substr(leftIdx, mn);
  
}

int main() {
    freopen("out", "w", stdout);
    cout << getShortestUniqueSubstring({'A', 'B', 'C'}, "ADOBECODEBANCDDD");
  return 0;
}