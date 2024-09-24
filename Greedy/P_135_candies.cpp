// sc=O(2N)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> lefttoright(n);
        vector<int> righttoleft(n);
        int candies=1;
        lefttoright[0]=1;
        righttoleft[n-1]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                lefttoright[i]=++candies;
            }
            else{
                candies=1;
                lefttoright[i]=candies;
            }
        }
        candies=1;
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                righttoleft[i]=++candies;
            }
            else{
                candies=1;
                righttoleft[i]=candies;
            }
        }
        int candiescnt=0;
        for(int i=0;i<n;i++){
            candiescnt+=max(righttoleft[i],lefttoright[i]);
        }
        return candiescnt;
    }
};

// Method 2
// SC=O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> count(n,1);
        int candies=1;
        count[0]=1;
        count[n-1]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                count[i]=max(count[i-1]+1,count[i]);
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                count[i]=max(count[i+1]+1,count[i]);
            }
        }
        int candiescnt=0;
        for(int i=0;i<n;i++){
            candiescnt+=count[i];
        }
        return candiescnt;
    }
};
// O(1) space optimised
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int i=1;
        int sum=1;
        while(i<n){
            if(i<n and ratings[i]==ratings[i-1]){
                sum+=1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n and ratings[i]>ratings[i-1]){
                peak++;
                i++;
                sum+=peak;
                if(i == n) return sum;
            }
            int down=0;
            while(i<n and ratings[i]<ratings[i-1]){
                down++;
                sum+=down;
                i++;
            }
            if(down+1>peak){
                sum+=down-peak+1;                
            }
        }
        return sum;
    }
};
