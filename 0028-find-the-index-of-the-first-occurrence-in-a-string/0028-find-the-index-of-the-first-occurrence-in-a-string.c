int strStr(char * haystack, char * needle){
    if(strlen(needle)>strlen(haystack))
    return -1;
    else
    {
        for(int i=0;i<strlen(haystack);
        i++)
        {
            if(!strncmp(haystack+i,needle,strlen(needle)))
            return i;
        }
        return -1;
    }
}