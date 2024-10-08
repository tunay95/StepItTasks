#==================Task 1=====================#

# Göndərilmiş listə cüt ədələrin cəmini return edən funksiya yazın.


"""
number_list1=[1,5,12,6,18,9]
number_list2=[1,5,13,19,21,9]

def EvenReturn(list):
    summ=0
    for number in list:
        if number%2==0:
            summ+=number    

    if summ==0:
        return "There aren't even elements in this list."
    else:
        return summ           

print(EvenReturn(number_list1))
print(EvenReturn(number_list2))
"""



#==================Task 2=====================#

# Göndərilmiş listin indekslərinin cəmini return edən funksiya yazın.


"""
number_list=[1,5,12,19,21,9]

def SumIndex(list):
    indexx=-1
    summ=0
    
    for number in list:
        indexx+=1
        summ+=indexx
    
    return summ        

print(SumIndex(number_list))    
"""



#==================Task 3=====================#

# Göndərilmiş listə indeksi cüt olan elementlərin cəminin tək olan 
# elementlərin ədədi ortasını tapan funksiya yazın


"""
number_list=[1,5,12,7,10,12]

def SumEven(list):
    sumEven=0    

    for number in range(2,len(list)-1,2):       #0-cı index'i cüt saymadım.
        sumEven+=list[number]
        
    return sumEven
 
def SumOdd(list):
    sumOdd=0    

    for number in range(1,len(list)-1,2):
        sumOdd+=list[number]
        
    return sumOdd

def Average(EvenSum,OddSum):
    averageSums=(EvenSum+OddSum)/2

    return f"Sum of Even Nums: {EvenSum}\nSum of Odd Nums: {OddSum}\nAvarage of Them: ({EvenSum}+{OddSum})/2={round(averageSums,2)} "

print(Average(SumEven(number_list),SumOdd(number_list)))
"""



#==================Task 4=====================#

# Göndərilmiş ədədin faktoriyalını return edən funksiya yazın(3!=1x2x3)


"""
number=int(input("Enter The Number: "))

def Factoriall(num):
    fact=1
 
    while num>1:
        fact*=num
        num-=1
    
    return fact

print(f"{number}!={Factoriall(number)}")
"""


