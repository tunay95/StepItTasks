# website = "http://www.google.com"
# course = 'Our course is best in the World, STEP IT ACADEMY Azerbaijan'


#==================Task 1=====================#

# ' Hello World ' xarakter siyahisinda baş ve sondaki boşluk xarakterlerini silin.

"""
data=' Hello World '
data2=""
count=0

for i in data:
    if data[count]==" ":
       if count==len(data)-1:
            break
       elif (65<=ord(data[count-1])<=90 or 97<=ord(data[count-1])<=122 and 
            65<=ord(data[count+1])<=90 or 97<=ord(data[count-1])<=122):
            data2+=data[count]
            count+=1                                                                #Ortadakı boşluq nəzərə alınaraq...
       else:
            data2+=data[count+1]
            count+=2
    else:
        data2+=data[count]
        count+=1
        
print(data2)  


for i in data:
    if data[count]==" ":
       if count==len(data)-1:
            break
       else:
            data2+=data[count+1]
            count+=2                                                               #Ortadakı boşluq nəzərə alınmayaraq...
    else:
        data2+=data[count]
        count+=1
        
print(data2)  
"""



#==================Task 2=====================#

# 'course' xarakter siyahisinda bütün xarakterlerini kiçik herf edin.

"""
course = 'Our course is best in the World, STEP IT ACADEMY Azerbaijan'
data2=""

for i in course:
    if 65<=ord(i)<=90:
        data2+=chr(ord(i)+32)
    else:
        data2+=i

print(data2)
"""



#==================Task 3=====================#

# 'website' içinde nece dene "a" xarakteri var ?
 
"""
website = "http://www.gaogla.cam"
count=0

for i in website:
    if ord(i)==97:
        count+=1
    else:
        continue   

print(f"\"a\"-ların sayı: {count}")
"""



#==================Task 4=====================#

# 'Contents' ifadesini setirda 60 xarakter içine yerleşdirib sağ ve soluna * elave edin

"""
data='Contents'
data2=""

for i in range(0,60):
    if i==30:
      data2+=data  
    else:
        data2+="*"

print(data2)
"""



#==================Task 5=====================#

# 'course' xarakter siyahisinda bütün boşluq xarakterlerini '-' ile evez edin.

"""
course = 'Our course is best in the World, STEP IT ACADEMY Azerbaijan'
data2=""

for i in course:
    if i==" ":
        data2+="-"
    else:
        data2+=i

print(data2)
"""



#==================Task 6=====================#

# 'Hello World' xarakter siyahisinda 'World' ifadesini 'There' olarak  evez edin.

"""
data='Hello World'
data2=""

for i in range(0,len(data)-1):
    if data[i]=='W' and data[i+1]=='o' and data[i+2]=='r' and data[i+3]=='l' and data[i+4]=='d':
        data2+='T'+'h'+'e'+'r'+'e'
        break
    else:
        data2+=data[i]

print(data2)
"""


