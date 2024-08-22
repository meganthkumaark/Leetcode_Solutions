class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        binary = bin(num)  #convert the int to binary
        print(binary)
        comp = ''          #initialize the string variable
        for bit in binary:
            if bit == '0':
                comp+= '1'
            else:
                comp+= '0'
        comp = comp[1:]     #slice the 1st index
        print(comp)
        return int(comp,2)  #conert the binary into int
        