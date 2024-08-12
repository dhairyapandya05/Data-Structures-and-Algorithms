vector<int> majorityElement(vector<int> v) {
	// Write your code here
	int n=v.size();
	vector<int> ans;
	int cnt1=0;
	int cnt2=0;
	int ele1=INT_MIN,ele2=INT_MIN;
        for (auto &it : v) {
			if(cnt1==0 and it!=ele2){
				cnt1=1;
				ele1=it;
			}
			else if (cnt2==0 and it!=ele1){
				cnt2=1;
				ele2=it;
			}
			else if(it==ele1){
				cnt1++;
            } 
			else if (it == ele2) {
				cnt2++;
            } else {
                cnt1--;
            	cnt2--;
            }
    }
	// if(ele1!=INT_MIN)
	// ans.push_back(ele1);
	// if(ele2!=INT_MIN)
    // ans.push_back(ele2);
    // sort(ans.begin(), ans.end());
	int hash1=0,hash2=0;
    for (auto &it : v) {
		if(it==ele1){
			hash1++;
		}
		if(it==ele2){
			hash2++;
		}
	}
	if(hash1>ceil(n/3) and ele1!=INT_MIN){
		ans.push_back(ele1);
	}
	if(hash2>ceil(n/3) and ele2!=INT_MIN){
		ans.push_back(ele2);
	}
	sort(ans.begin(),ans.end());
    return ans;
}
// link:https://www.naukri.com/code360/problems/majority-element_6915220?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTabValue=SUBMISSION