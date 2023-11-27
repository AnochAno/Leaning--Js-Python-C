from tabulate import tabulate

data = []

for _ in range(2):
    name = input("Enter Your Name: ")
    Age = int(input("Enter Your Age: "))
    city = input ("Enter Your City Name: ")
    data.append = ["name", "Age", "City"]

headers = ["Name", "Age", "City"]   

table = tabulate([data,headers,])

print(table)