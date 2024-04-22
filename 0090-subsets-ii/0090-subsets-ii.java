class Solution {
    private void subset(int[] nums,int ind,List<Integer> v,List<List<Integer>> ans){
        ans.add(new ArrayList(v));
        for(int i=ind ; i<nums.length;i++)
        {
            if(i>ind && nums[i]==nums[i-1])continue;
            v.add(nums[i]);
            subset(nums,i+1,v,ans);
            v.remove(v.size()-1);
        }
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans= new ArrayList<>();
        List<Integer> v= new ArrayList<>();
        subset(nums,0,v,ans);
        return ans;
    }
}