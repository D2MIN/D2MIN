file = open('Mysorovoz.txt')
list = file.readlines()

book = {}
m = 10 ** 10
chet = n = 0
for i in list:
    s = test = 0
    for i in list:
        s += int(i) * n
        if (n < len(list) // 2) and (test == 0): n += 1
        else:
            test = 1
            n -= 1
    a = list[0]
    list.remove(a)
    list.append(a)
    book[s] = a

m = min(book)
print(book[m])
