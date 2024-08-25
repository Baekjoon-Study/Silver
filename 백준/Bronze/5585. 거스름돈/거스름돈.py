money = int(input())
left_money = 1000 - money
coin = 0

while left_money > 0:

    if left_money >= 500:
        left_money -= 500
        coin += 1

    elif left_money >= 100:
        left_money -= 100
        coin += 1 
    
    elif left_money >= 50:
        left_money -= 50
        coin += 1
    
    elif left_money >= 10:
        left_money -= 10
        coin += 1

    elif left_money >= 5:
        left_money -= 5
        coin += 1
    
    else:
        left_money -= 1
        coin += 1

if left_money < 0:
    coin = -1

print(coin)
    