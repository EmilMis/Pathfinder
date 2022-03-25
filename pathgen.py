import random

#config------------------

x = 20
y = 20
mut = 4

#config------------------

s = []

for i in range(x):
    ss = []
    for j in range(y):
        ss.append('.')
    s.append(ss)

for i in range(x):
    for j in range(mut):
        s[i][random.randint(0, y - 1)] = '#'

for l in s:
    sss = ""
    for ll in l:
        sss += ll
    print(sss)
