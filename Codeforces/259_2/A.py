def line(n, idx):
    star_num = n // 2 - idx
    dia_num = 1 + idx * 2
    lr_stars = star_num * "*"
    return lr_stars + dia_num * "D" + lr_stars

n = int(input())

hn = n // 2

for i in range(hn + 1):
    print(line(n, i))
for i in reversed(range(hn)):
    print(line(n, i))

