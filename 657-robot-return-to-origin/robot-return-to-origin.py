class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        x,y=0,0
        for ch in moves:
            if(ch=='U'):
                y+=1
            elif(ch=='D'):
                y-=1
            elif(ch=='R'):
                x+=1
            elif(ch=='L'):
                x-=1
        

        return x==0 and y==0
        