def beeramid(bonus, price):
    if bonus < 0:
        return 0
    else:
        count_money = 0
        k = 3
        n = 1
        count_beer = 0
        while count_money <= bonus:
            money = price * n
            n += k
            k += 2
            count_money += money
            count_beer += 1
        return (count_beer-1)

print(beeramid(5000,64))