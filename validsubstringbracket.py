'''
Created on Aug 2, 2017
#input=string of brackets
#output=valid brackets length
@author: pantyagi
'''
inString=")()()())"
stck=[-1]
maxLen=0
for i in range(len(inString)):
    if inString[i]=='(':
        stck.append(i)
    else:
        stck.pop()
        if len(stck)!=0:
            maxLen=max(maxLen,i-stck[-1])
        else:
            stck.append(i)
print maxLen
            