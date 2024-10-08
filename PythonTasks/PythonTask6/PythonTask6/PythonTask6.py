#==================Task 1=====================#

# Ekrana istifadəçinin daxil etdiyi say qədər, ulduzlardan üfiqi xətt
# çıxaran proqram yazın.

"""
num1=int(input("Enter The Number of The Stars: "))

while num1!=0:
    print("*",end=" ")
    num1-=1
if(num1==0):    
    print()          #"Press The Key To Contunie" növbəti sətirə düşməsi üçün yazılıb.
"""



    
#==================Task 2=====================#

# Istifadəçinin daxil etdiyi aralıqda (məs. 10 və 30) cüt rəqəmlərin
# cəmini tək rəqəmlərin hasilini hesablayan proqram yazın. 

"""
num1=int(input("Enter The First Number of The Range: "))
num2=int(input("Enter The Second Number of The Range: "))

sum=0
multp=1

if(num1==num2):
        print()        
        print("The Sum of The Even Numbers: 0 ")
        print("The Multiplication of The Odd Numbers: 0 ")

elif(num1<num2):
    while num1<num2:
        if(num1%2==0 ): 
            sum+=num1
            if(num1+1<num2):            #Son tək ədədi vurmamaq şərti 
                multp*=(num1+1)
            num1+=2 
        else:
            multp*=num1 
            if(num1+1<num2):            #Son cüt ədədi toplamamaq şərti
                sum+=(num1+1)
            num1+=2  
    print()  
    print(f"The Sum of The Even Numbers: {sum} ")
    print(f"The Multiplication of The Odd Numbers: {multp} ")

   
elif(num1>num2):    
        while num1>num2:
            if(num1%2==0):    
                sum+=num1
                if(num1-1>num2):            #Son tək ədədi vurmamaq şərti 
                    multp*=(num1-1)
                num1-=2  
            else:
                multp*=num1
                if(num1-1>num2):            #Son cüt ədədi toplamamaq şərti   
                    sum+=(num1-1)
                num1-=2     
        print()  
        print(f"The Sum of The Even Numbers: {sum} ")
        print(f"The Multiplication of The Odd Numbers: {multp} ")
        
else:
        print()          
        print(f"The Sum of The Even Numbers: 0 ")
        print(f"The Multiplication of The Odd Numbers: 0 ")
"""




#==================Task 3=====================#

# Ədədin faktorialını tapan proqram yazın. (Məsələn (! - faktorial işarəsidir) ,
# 5! = 1*2*3*4*5)
 
"""
num1=int(input("Enter The Number: "))
multp=1

if(num1<0):                       
    print("THE NUMBER YOU ENTERED SHOULD BE MORE THAN -1 !!")   #Mənfilik şərti yoxlanılıb.

while num1>1:
    multp*=num1
    num1-=1
print(f"Factorial: {multp}")
"""




#==================Task 4=====================#

# Ədədin üstünü hesablayan proqram yazın (istifadəçi iki ədəd
# daxil edəcək əsas və üst məs. 2 və 3 cavab 8 alınmalıdır). 

"""
num1=float(input("Enter The Number: "))
num2=int(input("Enter The Power: "))          #qüvvət üstünü göstərir.

multp=1

if(num2>0):
    while num2!=0:
        multp*=num1
        num2-=1
    print(round(multp,3))
    
elif(num2<0):
    while num2!=0:
        multp*=num1
        num2+=1
    print(f"{round(1/multp,3)} or 1/{multp}")

else:
    print("Answer: 1")    
"""




#==================Task 5=====================#

# İstifadəçi tam ədəd daxil edir, bu ədədin qalıqsız bölündüyü
# bütün rəqəmləri ekrana çıxaran proqram yazın.

"""
num1=float(input("Enter The Number: "))

divsEr=1                            #1 və ədəin özünü də daxil etmişəm.

while divsEr<=num1:
    if(num1%divsEr==0):
        print(divsEr)
        divsEr+=1
    else:
        divsEr+=1
"""
