class Solution {
    public int findMinDifference(List<String> timePoints) {
        int[] minutes=new int[timePoints.size()];
        for(int i=0;i<timePoints.size();i++)
        {
            String[] time=timePoints.get(i).split(":");
            int hour =Integer.parseInt(time[0]);
            int minute=Integer.parseInt(time[1]);
            minutes[i]=hour*60+minute;
        }
        Arrays.sort(minutes);
        int minDifference=Integer.MAX_VALUE;
        for(int i=1;i<minutes.length;i++)
        {
            int difference=minutes[i]-minutes[i-1];
            minDifference=Math.min(minDifference,difference);
        }
        int circularDifference=minutes[0]+(24 * 60-minutes[minutes.length-1]);
        minDifference=Math.min(minDifference,circularDifference);
        return minDifference;
    }
}