class Solution {
public:
class Car{
    public:
    int pos,speed;
    public: Car(int p,int s){
        pos=p;
        speed=s;
    }
    
};
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        for(int i=0;i<position.size();i++){
        Car c(position[i],speed[i]);
            cars.push_back(c);
        }
        stack<double> st;
        auto cmp=[](Car& a,Car&b){return a.pos<b.pos;};
        sort(cars.begin(),cars.end(),cmp);
        for(auto c:cars){
            double time=(target-c.pos)/(double)c.speed;
            while(!st.empty() and time>=st.top()){
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};