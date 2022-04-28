file = open('Mysorovoz.txt')
list = file.readlines()

book = {}
m = 10 ** 10
s = 0
n = 0
chet = 0
col = 5
for i in list:
    # if int(list.index(i)) >= (len(list) // 100) * col:
    #     print(col, '%\n')
    #     col += 5
    s = 0
    test = 1
    for i in list:
        i = int(i)
        s += i * n
        if (n < len(list) // 2) and (test == 1):
            n += 1
        else:
            test = 0
            n -= 1
    a = list[0]
    list.remove(a)
    list.append(a)
    book[s] = a

m = min(book)
print(book[m])
