num1=2
while (num1>0):
    num2=2
    while (num2>0):
        print("Sri Lanka")
        num2=num2-1
    num1=num1-1

tot=0
for num in range(5):
    if num==3:
        break
    tot=tot+num
print(tot)

tot=0
for num in range(5):
    if num>=3:
        continue
    tot=tot+num
print(tot)

tot=1
for num in range(5):
    pass
print(tot)

numbers = [3,2,5,7,8]
count = 0
for number in numbers:
    count+=1
    if number==1:
        break
else:
    count=-1
print(count)

for counter in [1,2,3,5]:
    print("Hello World")

list(range(0, 10, 4))

num = 5
while (num !=0):
    num = num - 1 
    if (num == 2): 
        continue
    print ("Hello World!") 