http =  int (input("Enter your  HTTP  local host : "))
print(http)

if http == 400 and 3600: 
    print ("Server is Wroked")
if http == 504 or 500 :
    print("Currently Not avaialbe in that server")  
else:
    print("unkown Server")

#swich case
match http:
    case 400 | 3600 :
        print("Server is Wroked")
    case 504:
        print("Currently Not avaialbe in that server")
    case _ :
        print("Unkown ")
