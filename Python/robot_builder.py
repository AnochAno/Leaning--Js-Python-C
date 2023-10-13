import turtle as t
def rectagluar (horizontal,vertical,color):

    t.pendown()
    t.pensize(1)
    t.color(color)
    t.begin_fill()
    for counter in range(1,3):
        t.forward(horizontal)
        t.right(90)
        t.forward(vertical)
        t.right(90)
    t.end_fill()
    t.penup()
    
t.penup()
t.speed('slow')
t.bgcolor('dodger blue')


#feet
t.goto(-100,-150)
rectagluar(50,20,'blue')
t.goto(-30,-150)
rectagluar(50,20,'blue')

#legs
t.goto(-25,-50)
rectagluar(15,100,'gray')
t.goto(-55,-50)
rectagluar(15,100,'gray')

#body
t.goto(-90,100)
rectagluar(100,150,'red')

#Amrs
t.goto(-150,-70)
rectagluar(60,15,'gray')
t.goto(-150,-110)
rectagluar(15,40,'gray')

t.goto(10,70)
rectagluar(60,15,'gray')
t.goto(55,110)
rectagluar(15,40,'gray')

#neck
t.goto(-50,120)
rectagluar(15,20,'gray')

#head
t.goto(-85,170)
rectagluar(80,50,'red')

#eyes
t.goto(-60,160)
rectagluar(30,10,'white')
t.goto(-55,155)
rectagluar(5,5,'black')
t.goto(-40,155)
rectagluar(5,5,'black')

#mouth
t.goto(-65,135)
t.right(5)
rectagluar(40,5,'black')

t.hideturtle
