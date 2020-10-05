class KthLargest {
    priority_queue<int, vector<int>, greater<int>> h;
    vector <int> v;
    int count, k;
       public: KthLargest(int k, vector<int>& nums){
        this-> k= k;    v= nums;
        count=0;
        for(int i=0; i<nums.size(); i++)  {
            if(count<k)   {
                h.push(nums[i]);    count++;
            }
            else {
                if(nums[i]> h.top())  {
                    h.pop();        h.push(nums[i]);
                }
            }
        }
    }
    int findKth()  {
        if(count<k)  {
            h.push(v[v.size()-1]);  count++;
        }
        else {
            if(v[v.size()-1] > h.top())
            {   h.pop();
                h.push(v[v.size()-1]);                
            }
        }
        return h.top();
    }
    int add(int value)
    {
        v.push_back(value);
        return findKth();
    }
};