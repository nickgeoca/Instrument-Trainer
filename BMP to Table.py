a = "73 1b 85 75 21 8a 73 21 8c 71 21 8c 72 21 8e 73 21 91 73 23 94 71 23 94 70 27 95 70 2c 97 6e 2f 97 6a 2f 97 6b 33 9c 69 34 9c 69 34 9b 69 36 9e 66 36 a0 66 3b a4 63 41 a6 5e 42 a6 59 43 a9 5b 49 ae 5b 49 ae 59 4b b0 51 4d ad 4d 4f ad 4a 50 af 47 51 af 47 55 b5 44 56 b5 42 59 b5 42 5c b6 41 5c b6 3e 5c b5 3e 60 ba 3f 62 bc 3e 64 bc 3f 65 bd 40 69 be 42 6b c0 40 6c c0 45 73 c7 44 74 c6 42 74 c6 44 76 c9 47 79 cc 48 7a cc 47 7c cc 46 7d ce 48 81 d0 48 82 ce 49 86 d0 4b 87 d3 4e 8a d6 4d 8a d4 4e 8c d3 53 8f d5 56 93 d7 56 95 d9 58 99 dd 56 9a dd 5a 9f de 5d a3 de 5d a4 dd 5d a7 dd 5e aa df 5c ab de 5d af df 5d af de 60 b3 e0 64 b7 e4 65 b9 e3 63 bb df 67 c1 e0 67 c2 e1 69 c4 e3 ff 6c c6 e4 6a c5 e0 6e c9 e4 6f cc e5 6d cb e2 76 d3 e8 78 d3 e8 7c d5 e9 80 d8 e9 84 db eb 87 d9 ea 8d dd ee 93 e0 f0 9d e6 f4 a4 e9 f3 a9 e7 f1 ab e8 f2 b3 eb f6 b9 eb f7 bf ec f7 c6 f0 f7 cf f5 f9 d1 f4 f7 d8 f5 f9 dd f6 fa e6 f9 fe ea fb fe ef fb ff f5 fc ff f8 fb ff"

def main():
    col = [[],[],[]]
    col2 = [[],[],[]]
    y =  a.find(" ")
    x = 0
    i = 0
    print(col)
    while 1:
        col[i].append(a[x:y])
        x = y + 1
        y = a[x:].find(" ")
        if y == -1:
            break
        y = y + x
        i = (i + 1) % 3

    while col[0]:
        col2[0].append(col[0].pop())
        col2[1].append(col[1].pop())
        col2[2].append(col[2].pop())
    print("{")
    while col2[0]:
        print("{",int(col2[0].pop(), 16),",", int(col2[1].pop(), 16), ",",int(col2[2].pop(), 16), "},")
    print("};")
main()
