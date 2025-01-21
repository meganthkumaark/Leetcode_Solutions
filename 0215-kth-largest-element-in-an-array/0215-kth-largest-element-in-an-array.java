class Solution {
    public int findKthLargest(int[] nums, int k) {
    PriorityQueue<Integer> minheap = new PriorityQueue<>();
    // PriorityQueue<Integer> maxheap = new PriorityQueue<>((a,b) -> b-a); for maxheap
    
    for(int i:nums){
        minheap.add(i);
        if(minheap.size()>k){
            minheap.remove();  
        }
    }
    return minheap.peek();    
    
    }
}