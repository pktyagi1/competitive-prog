'''
Created on Aug 1, 2017
#input==array
#aoutput==array of index each index hax value of next greater value index
@author: pantyagi
'''
import sys
arr=[13, 7, 6, 12]

output=[-1]*len(arr)
nge=[0]
for i in range(1,len(arr)):
    nxt=i
    if(len(nge)>0):
        
        while len(nge)>0 and arr[nxt]> arr[nge[-1]]:
            output[nge[-1]]=nxt
            nge.pop()
    nge.append(nxt)
print output
    
    
            



