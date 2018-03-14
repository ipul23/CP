import sys
x=int(input())
b=0
a=0
for i in range (1,x+1):
    data=[0]*1005
    a,b = map(int,sys.stdin.readline().split())
    if (b==1):
        print ("Kasus #%d: %d\n" % (i,a))
    else:
        for j in range(2,b+1):
            for k in range(1,a+1):
                if (j*k<=a):
                    if (data[j*k]==0):
                        data[j*k]=1
                    else:
                        data[j*k]=0
                else:
                    break
        hasil=0
        for j in range  (1,a+1):
            if (data[j]==0): hasil+=1
        print ("Kasus #%d: %d\n" % (i,hasil))
