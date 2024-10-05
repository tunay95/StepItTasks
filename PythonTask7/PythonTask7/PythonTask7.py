#==================Task1(while)=====================#

# Klaviaturadan 10 tam ədəd daxil edilir, mənfi ədədlərin
# faizini, müsbət ədədlərin faizini və 0-ların faizini tapın.

"""
counter=0
countPos=0
countNeg=0
countZero=0

while counter<10:
    number=int(input("Enter The Number: "))
    counter+=1
    if(number>0):
        countPos+=1
    elif(number<0):
        countNeg+=1
    else:
        countZero+=1
print(f"Müsbət ədədlərin faizi: {(countPos*100)/10}%")
print(f"Mənfi ədədlərin faizi: {(countNeg*100)/10}%")
print(f"Sıfırların faizi: {(countZero*100)/10}%")
"""

#==================(for)=====================#

"""
countPos=0
countNeg=0
countZero=0

for counter in range(10):
    number=int(input("Enter The Number: "))
    if(number>0):
        countPos+=1
    elif(number<0):
        countNeg+=1
    else:
        countZero+=1
   

print("")        
print(f"1.Müsbət ədədlərin faizi: {(countPos*100)/10}%\n2.Mənfi ədədlərin faizi: {(countNeg*100)/10}%\n3.Sıfırların faizi: {(countZero*100)/10}%")
"""




#==================Task2(while)=====================#

# Klaviaturadan 10 tam ədəd daxil edilir. Cütlərin və
# təklərin neçə faiz olduğunu hesablayan proqram yazın.

"""
counter=0
countOdd=0
countEven=0
notOddEven=0

while counter<10:
    number=int(input("Enter The Number: "))
    counter+=1
    if(number%2==0):
        countEven+=1
    elif(number%2==1):
        countOdd+=1
    else:
        notOddEven+=1
        
print(f"Müsbət ədədlərin faizi: {(countEven*100)/10}%")
print(f"Mənfi ədədlərin faizi: {(countOdd*100)/10}%")
print(f"Sıfırların faizi: {(notOddEven*100)/10}%")
"""

#==================(for)=====================#

"""
counter=0
countOdd=0
countEven=0
notOddEven=0

for counter in range(10):
    number=int(input("Enter The Number: "))
    counter+=1
    if(number%2==0):
        countEven+=1
    elif(number%2==1):
        countOdd+=1
    else:
        notOddEven+=1
        
print(f"Müsbət ədədlərin faizi: {(countEven*100)/10}%")
print(f"Mənfi ədədlərin faizi: {(countOdd*100)/10}%")
print(f"Sıfırların faizi: {(notOddEven*100)/10}%")
"""

#==================BonusTask(while)=====================#

"""
number=int(input("Enter The Number: "))

while number!=0:
    digit=number%10
    number//=10
    if(digit == number%10):
        print(f"Ardicil Tekrarlanan reqem var: {digit}")
        break
    elif(number==0):
        print("Ardicil Terkarlanan reqemin yoxdur.")
        break
"""    
    