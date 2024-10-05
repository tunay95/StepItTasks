clothes_dict={1:{"Name ":"T-shirt","Price":20,"Count":100},
              2:{"Name ":"Jean","Price":60,"Count":50},
              3:{"Name ":"Shoe","Price":80,"Count":80}}

def CreateClothes(Id,name,price,count):
    global clothes_dict
    clothes_dict[Id]={"Name ":name,"Price":price,"Count":count}
    print()
    

def ShowAll():
    global clothes_dict
    print("\n*------------------------------------*\nDo you wanna see last version of DB ?\n")
    choice3=int(input("1)Yes  or  2)No \n\nYour Choice: "))
    
    if choice3==1:
        print("\n*------------------------------------*\n")
        for i in clothes_dict:
            print(f"№{i} pr.----------------------*")
            for k in clothes_dict[i]:     
                print(f"|  {k}  ||  {(str(clothes_dict[i][k]).ljust(13))} |\n*---------------------------*") 
        print("\n\n")        
    elif choice3==2:
        return 0
    else:
        print("\n*------------------------------------*\nPlease select one of those choices.\n\n")


def Update():
    global clothes_dict
    print("\n*------------------------------------*\nWhich field do you wanna change?\n\n1)Name\t2)Price\t 3)Count  ")
    choice3=int(input("\n\nYour Choice: "))
    if choice3==1:
        inputName=input("Enter Name: ")
        clothes_dict[inputId]["Name "]=inputName.capitalize()
    elif choice3==2:
        inputPrice=float(input("Enter Price: "))
        clothes_dict[inputId]["Price"]=inputPrice
    elif choice3==3:
        inputCount=int(input("Enter Count: "))
        clothes_dict[inputId]["Count"]=inputCount
    print("\nData Base has been updated.")

    
def Delete(Id):
    global clothes_dict
    del clothes_dict[Id]
    return clothes_dict
    
def ShowById(Id):
    print(f"№{Id} pr.----------------------*")
    for k in clothes_dict[Id]:     
        print(f"|  {k}  ||  {(str(clothes_dict[Id][k]).ljust(13))} |\n*---------------------------*")


def Search(Id):
    global clothes_dict
    for i in clothes_dict:
        if Id==i:
            return True
    return False
   

while True:
    choice=int(input("""
*------------------Welcome------------------*                     
                     
*============*===*                 
|    Add     | 1 | 
*============*===*                    
|  Show All  | 2 |
*============*===*                    
|   Change   | 3 |
*============*===*                    
|   Delete   | 4 |
*============*===*                     
|  Show wId  | 5 |
*============*===*
|    Exit    | 6 |
*============*===* 
                     
Your Choice: """))
    

    if choice==1:
        inputId=int(input("\n*------------------------------------*\nEnter Id: "))
        if Search(inputId):
            inputCount=int(input("\nThese Clothes are already exsist.\n\nPlease Enter Some Count: "))
            clothes_dict[inputId]["Count"]+=inputCount
            print()
            ShowAll()
          
        else:        
            inputName=input("Enter Name: ")
            inputPrice=float(input("Enter Price: "))
            inputCount=int(input("Enter Count: "))
            print("\nYour New Product Added.")
            CreateClothes(inputId,inputName.capitalize(),inputPrice,inputCount)
            ShowAll()
       
        
    elif choice==2:
        ShowAll() 
        

    elif choice==3:
        inputId=int(input("Enter Id: "))
        if Search(inputId) is not True:
            print("\n*------------------------------------*\nThere is no data about the id you entered.Do you want to create some?\n\n1)Yes \t2)No \n")
            choice2=int(input("Choice: "))
            if choice2==1:
                inputName=input("\n*------------------------------------*\nEnter Name: ")
                inputPrice=float(input("Enter Price: "))
                inputCount=int(input("Enter Count: "))
                print("\nYour New Product Has Been Added.")
                CreateClothes(inputId,inputName.capitalize(),inputPrice,inputCount)
                ShowAll()
            else:
                break
        else:        
            Update()
            print()
            ShowAll()
        
                
    elif choice==4:
        inputId=int(input("Enter Some Id: ")) 
        Delete(inputId)
        print("\nProduct Deleted.\n")
        ShowAll()
        

    elif choice==5:
        inputId=int(input("Enter Some Id: "))
        
        if Search(inputId):
            print("\n*------------------------------------*\n")
            ShowById(inputId)
            print("\n\n")
        else:
            print("\n*------------------------------------*\nWe can't find any data about Id you entered.\n")
           

    elif choice==6:
        break
    
    else:
        print("\nEnter Correct Choice !!\n\n")
