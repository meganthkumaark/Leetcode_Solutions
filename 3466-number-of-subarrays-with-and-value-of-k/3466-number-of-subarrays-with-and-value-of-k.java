class Solution {
    public long countSubarrays(int[] nums, int k) {
        long res=0;
        
        Map<Long, Long> map = new HashMap<>(); // prev_results
        for(int i=0; i<nums.length; i++){
            Map<Long, Long> currRes = new HashMap<>(); // current_results
            if(nums[i]==k){
                res++;
            }
            
            currRes.put((long)nums[i], 1L);
            for(var key:map.keySet()){
                long newRes = key & nums[i];
                if(newRes==k){
                    res+=map.get(key);
                }
                
                currRes.put(newRes, currRes.getOrDefault(newRes, 0L)+map.get(key));
            }
            map = currRes;
        }
        return res;
    }
}