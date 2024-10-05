print("1. \n")

#==================Task 1=====================#

# "Samsung S5,Samsung S6,Samsung S7,Samsung S8" elementlerne sahib bir list yaradin.


data="Samsung S5,Samsung S6,Samsung S7,Samsung S8" 
telephone_list=[]
data2=""

for element in data:
    if element==",":
        telephone_list.append(data2)
        data2=""
    else:
        data2+=element

print(telephone_list)

print("\n==============================")
print("2. \n")



#==================Task 2=====================#

# Listin nece elementi var ?


count=0

for element in telephone_list:
    count+=1

print(f"List-in elementlərinin sayı: {count}")

print("\n==============================")
print("3. \n")



#==================Task 3=====================#

# Listenin ilk ve son elementi nedir ?
 

print(f"List-in Ilk Elementi : {telephone_list[0]} \nList-in Son Elementi : {telephone_list[-1]}")

print("\n==============================")
print("4. \n")



#==================Task 4=====================#

# "Samsung S5" elementini "Samsung S9" ile deyishin.


telephone_list[0]='Samsung S9'

print(telephone_list)

print("\n==============================")
print("5. \n")



#==================Task 5=====================#

# "Samsung S6" listin bir elementidir ?


for element in telephone_list:
    if element=='Samsung S6':
        print("It's One of The Elements.")
        break
    else:
        continue
          
print("\n==============================")
print("6. \n")



#==================Task 6=====================#

# Listin -3 indeksindeki deyeri nedir ?


print(f"List-in '-3' indeksindeki element: {telephone_list[-3]}")

print("\n==============================")
print("7. \n")



#==================Task 7=====================#

# Listin ilk 2 dene elementini alın.


print(f"List-in Ilk Elementi: {telephone_list[0]} \nList-in Ikinci Elementi: {telephone_list[1]}")

print("\n==============================")
print("8. \n")



#==================Task 8=====================#

# Listin son 2 elementinin yerine "Samsung S9" ve "Samsung S10" deyerleri ile evez edin.


telephone_list[-2]='Samsung S9'
telephone_list[-1]='Samsung S10'

print(telephone_list)

print("\n==============================")
print("9. \n")



#==================Task 9=====================#

# Listin üzerine "IPhone X" ve "IPhone XR" deyerlerini elave edin.


telephone_list.append('Iphone X')
telephone_list.append('Iphone XR')

print(telephone_list)

print("\n==============================")
print("10. \n")


#==================Task 10=====================#

# Listenin son elementini silin.



telephone2_list=telephone_list[:-1:]

print(telephone2_list)

print("\n==============================")
print("11. \n")


#==================Task 11=====================#

# Listin elementlerni tersden yazdırın.


reverse_list=telephone2_list[::-1]

print(f"List-in tərsi: {reverse_list}")

print("\n==============================")
print("12. \n")



#==================Task 12=====================#

# Listin elementlerni ekrana yazdırın.


print(f"{reverse_list}\n")



