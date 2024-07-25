bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int i,j;
    i=0;
    j=*matrixColSize * matrixSize-1;
    while(i<=j)
    {
        int mid=(i+j)/2;
        int row,col;
        row=mid / *matrixColSize;
        col=mid % *matrixColSize;
        if(matrix[row][col]<target)i=mid+1;
        else if(matrix[row][col]>target)j=mid-1;
        else return true;
    }
    return false;
}