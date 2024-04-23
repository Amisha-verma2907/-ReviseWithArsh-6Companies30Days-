class Solution {
    private void permutation(int[] nums,List<List<Integer>> ans,List<Integer> v,boolean [] freq){
        if(v.size() == nums.length){
            ans.add(new ArrayList<>(v));
            return;
        }
        for(int i=0;i<nums.length;i++)
        {
            if(!freq[i]){
                freq[i] = true;
                v.add(nums[i]);
                permutation(nums,ans,v,freq);
                v.remove(v.size()-1);
                freq[i]=false;
            }
        }
    }
    public List<List<Integer>> permute(int[] nums) {
       List<List<Integer>> ans = new ArrayList<>();
        List<Integer> v = new ArrayList<>();
        
        boolean freq[] =  new boolean[nums.length];
        permutation(nums,ans,v,freq);
        return ans;
    }
}