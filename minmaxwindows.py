'''
Created on Aug 5, 2017

@author: pantyagi
'''
import sys
from operator import sub
a=[10, 20, 30, 40, 50]
nse=[0]
nsel=[len(a)]*len(a)
pse=[len(a)-1]
for i in range(1,len(a)):
    cur=i
    while len(nse)>0 and a[cur]<a[nse[-1]]:
        nsel[nse[-1]]=cur
        nse.pop()
    nse.append(cur)
psel=[-1]*len(a)
for i in range(len(a)-1,-1,-1):
    cur=i
    while len(pse)>0 and a[cur]<a[pse[-1]]:
        psel[pse[-1]]=cur
        pse.pop()
    pse.append(cur)
ans=[0]*(len(a)+1)

for i in range(0,len(a)):
    lt=nsel[i]-psel[i]-1
    print lt,
    ans[lt]=max(ans[lt],a[i])
print ans
for i in range(len(a)-1,0,-1):
    ans[i]=max(ans[i],ans[i+1])
print ans




    