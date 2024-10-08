# website = "http://www.google.com"
# course = 'Our course is best in the World, STEP IT ACADEMY Azerbaijan'


#==================Task 1=====================#

# 'course' xarakter siyahisinda nece dene xarakter var ?

"""
course = 'Our course is best in the World, STEP IT ACADEMY Azerbaijan'
length=0

for i in course:
    length+=1
print(f"The Numbers of The Char. : {length}")
"""
   


#==================Task 2=====================#

# 'website' içinden "www" xarakterlerini alin ve print edin.

"""
website = "http://www.google.com"
headLine=website[7]+website[8]+website[9]
                                                #Her Saytda 'www'-nun yeri eyni olduğu üçün
print(headLine)        
"""



#==================Task 3=====================#

# 'website' içinden "com" xarakterlerini alın ve print edin.
 
"""
website = "http://www.google.com"
endLine=website[-3]+website[-2]+website[-1]
                                                 #Her Saytda 'com'-un yeri eyni olduğu üçün
print(endLine)
"""



#==================Task 4=====================#

#  'course' içinden ilk 10 ve son 10 xarakterlerini alın.

"""
course = 'Our course is best in the World, STEP IT ACADEMY Azerbaijan'
first=""
last=""

for i in range(0,11):
    first+=course[i]


for k in range(-11,0):
    last+=course[k]
    
print(f"First 10 Char: {first} \nLast 10 Char: {last}")
"""



#==================Task 5=====================#

# 'Hello programmers' ifadesindeki 'p' herfini 'P' ile evez edin.

"""
data='Hello programmers'
data2=""

for i in data: 
    if ord(i)==112:
        data2+=chr(80) 
        continue
    data2+=i
    
print(data2)
"""