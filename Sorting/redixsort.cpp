#include <bits/stdc++.h>
using namespace std;
void padStrings(vector<string>& strings,int& maxsize) {
    for (auto& str : strings) {
        stringstream ss;
        ss << setw(maxsize) << setfill('0') << str;  // Set width to 8 and fill with '0'
        str = ss.str();  // Assign the formatted string back to the vector element
    }
}
void radixSort(vector<int>& arr, int n) 
{
   int highestnumber=*max_element(arr.begin(),arr.end());
   vector<string> numbers;
   int maxsize=0;
   for(int i=0;i<n;i++){
       string num=to_string(arr[i]);
       if(num.length()>maxsize){
           maxsize=num.length();
       }
       numbers.push_back(num);
   }
   // add zeros presiding the smaller digits
   padStrings(numbers,maxsize);
   for(int i=maxsize-1;i>=0;i--){
       map<int,vector<string>> mp;
        for(auto str:numbers){
            int digit=stoi(to_string(str[i]));
            mp[digit].push_back(str);
        }
        numbers.clear();
        for (const auto& pair : mp) {
        // 'pair.first' is the key (int)
        // 'pair.second' is the value (vector<int>)

        // Iterate over the vector (value part of the pair)
        for (string val : pair.second) {
            // Append each element to the result vector
            numbers.push_back(val);
            // cout<<" OK "<<val;
        }
        
    }
    // cout<<endl;
    mp.clear();
   }
//   arr.clear();
   for(int i=0;i<n;i++){
       arr[i]=stoi(numbers[i]);
   }
    
} 
int main(){
    vector<int> arr={15,1,321,10,802,2,123,90,109,11};
    radixSort(arr,arr.size());
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}