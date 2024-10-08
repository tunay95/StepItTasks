#Task1 (İstifadəçi 1-20 arası ədəd daxil edir.)
#Ədəd sadədirsə True, mürəkkəbdirsə False çap olunsun.
#Sadə ədədlər yalnız özünə və 1-ə bölünən ədədlərdir

"""
num=int(input("Enter The Number: "))

print("Your Number is Simple:")
print(num==1 or num==3 or num==5 or num==7 or num==11 or num==13 or num== 17 or num==19)
"""


#Task2 (İstifadəçi 5 rəqəmli ədəd daxil ediir.)
#Ədədin polindrom olub olmamasını təyin edin.
#Polindrom - əksinə və düzünə eyni cür oxunur 12321 polindromdur, 12345 polindrom deyil.

"""
num=int(input("Enter The Number: "))

a=num//10000
b=num//1000%10
c=num//100%10
d=num//10%10
e=num%10

print(a==e and b==d)
"""


#Task3 (İstifadəçi rəqəm daxil edir. 1dən - 9 rəqəmliyə kimi ola bilər.)
#Onun neçə rəqəmdən ibarət olduğunu tapın. Sadece 1 dəyişənden istifadə edə bilərsiniz.

"""
num=int(input("Enter The Number: "))

print("1.",num%10!=0)
print("2.",num//10%10!=0)
print("3.",num//100%10!=0)
print("4.",num//1000%10!=0)
print("5.",num//10000%10!=0)
print("6.",num//100000%10!=0)
print("7.",num//1000000%10!=0)
print("8.",num//10000000%10!=0)
print("9.",num//100000000!=0)
"""


#Task4 (İstifadəçi 3 ədəd daxil edir. 
#Proqram , əgər 
#birinci ədəd o birilərdən böyükdürsə, ‘1-ci: True’, 
#ikinci ədəd böyükdürsə ‘2-ci: True’, 
#üçüncü ədəd böyükdürsə ‘3-cu: True’  çap olunsun.)

"""
num1=int(input("Enter The Number: "))
num2=int(input("Enter The Number: "))
num3=int(input("Enter The Number: "))

print("1-ci: ",num1>num2 and num1>num3)
print("2-ci: ",num2>num1 and num2>num3)
print("3-ci: ",num3>num1 and num3>num2)
"""


#Task5 (İstifadəçi 6 rəqəmli ədəd daxil edir. 
#Tək yerdə duranların cəmi cüt yerdə duranların cəmindən çoxdursa , True , və ya False.                                                               
#Numune: (756189) Tək yerdə duranlar - 7,6,8 // Cüt yerdə duranlar - 5,1,9)

"""
num=int(input("Enter The Number: "))

a=num//100000
b=num//10000%10
c=num//1000%10
d=num//100%10
e=num//10%10
f=num%10

print(a+c+e>b+d+f)
"""