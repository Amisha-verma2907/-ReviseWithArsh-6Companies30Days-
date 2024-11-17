class Solution {
public:
    int valid(vector<int>nums,int ind,bool rdir)
    {
        while(ind>=0 && ind<nums.size())
        {
            if(nums[ind] == 0)
            {
                ind+= (rdir == true)?1:-1;
            }else{
                nums[ind]--;
                rdir = !rdir;
                ind+=(rdir == true)?1:-1;
            }
        }
        
        for(auto a:nums)
        {
            if(a !=0)
            {
                return 0;
            }
        }
        
        return 1;
    }
    int countValidSelections(vector<int>& nums) {
        int cnt = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0)
            {
                cnt+= valid(nums,i,true) + valid(nums,i,false);
            }
        }
        
        return cnt;
    }
};