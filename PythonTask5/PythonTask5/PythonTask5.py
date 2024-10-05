#==================Task 1=====================#

# İstifadəçi iki ədəd daxil edir. ( X və Y ) Əgər X Y-ə qalıqsız bölünürsə,
# ekrana Yes çıxır, əks halda No.

"""
num1=float(input("Enter the First Number: "))
num2=float(input("Enter the Second Number: "))

if(num1%num2==0):
    print(f"Yes, Residue: 0")
else:
    print(f"No, Residue: {num1%num2}")
"""    

#==================Task 2=====================#

# İstifadəçi ədəd daxil edir. Onun 3-ə, 5-ə, 7-ə bölünüb bölünməməsini
# (qalıqsız) yoxlayın. (Ayrı-ayrı)


# num1=float(input("Enter the Number: "))

# if(num1==0):
#     print("ALl OPERATIONS WILL END WITHOUT RESIDUE AND EQUAL ZERO.")
    

# else:
#     print("""      
#       1) Division to 3 \\
#       2) Division to 5  = (Without Residue)
#       3) Division to 7 /
      
# Choose one of theese.      
#       """      )

#     operation=int(input("Enter the Number of Operation: "))

#     if(operation==1):
#         if(num1%3==0):
#             print("This Operation ended without Residue.")
#         else:
#             print(f"This Operation ended with Residue, Residue: {num1%3}")
            
#     elif(operation==2):
#         if(num1%5==0):
#             print("This Operation ended without Residue.")
#         else:
#             print(f"This Operation ended with Residue, Residue: {num1%5}")
            
#     elif(operation==3):
#         if(num1%7==0):
#             print("This Operation ended without Residue.")
#         else:
#             print(f"This Operation ended with Residue, Residue: {num1%7}")
            
#     else:
#         print("THERE IS NOT AN OPERATION LIKE YOU ENTEREDD!!")
   
        
#==================Task 3=====================#

# Ədədin modulunu hesablayan program yazın.

"""
num1=float(input("Enter the Number: "))

if(num1<0):
    print(f"|{num1}| = {num1*(-1)}")
else:
    print(f"|{num1}| = {num1}")
"""    

#==================Task 4=====================#

# Maximum 4 rəqəmli ədəd daxil edilir. Ədədin neçə rəqəmdən ibarət
# olduğunu hesablayan program yazın.

"""
num1=int(input("Enter The Number (MAX with 4 Digits Length): "))

if(num1>9999):
    print("THE NUMBER YOU ENTERED SHOULD CONSIST OF 4 DIGITS!!")    
else:  
    if(num1//1000==0):
        print("First Digit mustn't be 0 (Zero).")
    elif(1000<=num1<10000):
        print("The Number is consist of 4 digits.")
    elif(num1//100==0):
        print("First Digit mustn't be 0 (Zero).")        
    elif(100<=num1<1000):
        print("The Number is consist of 3 digits.")  
    elif(num1//10==0):
        print("First Digit mustn't be 0 (Zero).")
    elif(10<=num1<100):
        print("The Number is consist of 2 digits.")  
    elif(0<=num1<10):    
        print("The Number is consist of 1 digits.")  
    else:
        print("THE NUMBER SHOULDN'T BE NEGATIVE!!")    
"""

#==================Task 5=====================#

# 5 rəqəmli ədəd daxil edilir. Onun ploindrom olub olmamasını təyin edən
# program yazın.

"""
num1=int(input("Enter the Number with 5 digits length: "))

if(num1//10000==0):
    print("First Digit mustn't be 0 (Zero).")  
elif(num1>99999 or num1<10000):
    print("You can enter Numbers between 10000 and 99999")     
else:
        if((num1//10000)==(num1%10) and (num1//1000%10)==(num1//10%10)):
            print("This Number is Ploindrom.")
        else:
            print("This Number is not Ploindrom.")    
"""
