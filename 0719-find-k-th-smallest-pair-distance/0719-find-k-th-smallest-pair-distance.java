class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        int n=nums.length;
        int e=nums[n-1]-nums[0];
        int s=0;
        while(s<e){
            int mid=s+(e-s)/2;
            if(count(nums,k,mid)){
                e=mid;
            }
            else{
                s=mid+1;
            }
        }

        return s;
    }
    private boolean count(int[] nums,int k,int mid){
            int j=0;
            int cnt=0;
            for(int i=1;i<nums.length;i++){
                while(nums[i]-nums[j]>mid)j++;
                cnt+=(i-j);
            }
            return cnt>=k;
    }
}