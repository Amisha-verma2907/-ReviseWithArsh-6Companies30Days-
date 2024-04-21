class Solution {
    private void combination( List<List<Integer>>ans,List<Integer>v, int[] candidates,int target,int ind){
        if(ind == candidates.length)
        {
            if(target == 0){
                ans.add(new ArrayList<>(v));
            }
            return;
        }
        if(candidates[ind]<=target){
            v.add(candidates[ind]);
            combination(ans,v,candidates,target-candidates[ind],ind);
            v.remove(v.size()-1);
            
     }
        combination(ans,v,candidates,target,ind+1);
        
    }
        
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        combination(ans,new ArrayList<>(),candidates,target,0);
        return ans;
    }
}