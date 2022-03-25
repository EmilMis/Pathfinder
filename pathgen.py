import random

#config------------------

x, y, mut = input("> ").split(' ')
x = int(x)
y = int(y)
mut = int(mut)

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

s[0][0] = '.'

for l in s:
    sss = ""
    for ll in l:
        sss += ll
    print(sss)
