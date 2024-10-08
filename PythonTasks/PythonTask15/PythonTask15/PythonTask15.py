import json
from pyexpat import model 

users_dict={"Lala":{"password":"lala1234","balance":700,"history_id":[]},"MehemmedAli":{"password":"Ali123","balance":1900,"history_id":[]}}
car_galery_dict={"666FLK8":{"model":"Cadillac","year":1998,"count":0,"price":12000},"65HD7GD3":{"model":"Hyndai","year":2023,"count":2,"price":1700},"65HD7883":{"model":"BMW","year":2023,"count":4,"price":2100}}




def WriteToFile():  
    global car_galery_dict
    with open('convert.txt', 'w') as convert_file: 
         convert_file.write(json.dumps(car_galery_dict))
     
def ReadFromFile():
    global car_galery_dict
    car_galery_dict=json.load(open('convert.txt','r'))

    
try:
    ReadFromFile()
except:
    WriteToFile()


def AdminPanel():
    def Show_All_Cars():
        for fin in car_galery_dict:
            car=car_galery_dict[fin]
            print(f"____{fin}______")
            print("Model: ",car["model"])
            print("Year: ",car["year"])
            print("Count: ",car["count"])
            print("Price: ",car["price"])
         
            print("\n_____________________\n")
    
        
    def Search_Car(fin):        
        if (fin in car_galery_dict):
            car=car_galery_dict[fin]
            print(f"____{fin}______")
            print("Model: ",car["model"])
            print("Year: ",car["year"])
            print("Count: ",car["count"])
            print("Price: ",car["price"])        
        else:
            print("Not Found")

    
    def Add_Car():
        fin=input("Enter fin: ")
        if(fin in car_galery_dict):
            print("This id used!!!")
        else:
            car_dict={}
            car_dict["model"]=input("Enter model: ")
            car_dict["year"]=int(input("Enter year: "))
            car_dict["count"]=int(input("Enter count: "))
            car_dict["price"]=float(input("Enter price: "))
            car_galery_dict[fin]=car_dict
            WriteToFile()
            print("Car added...")
    
    
    def Update_Car():
        fin=input("Enter fin: ")
        if(fin in car_galery_dict):
            model=input("Enter model: ")
            year=input("Enter year: ")
            count=input("Enter count: ")
            price=input("Enter price: ")
            if(model!=""):
               car_galery_dict[fin]["model"]=model 
            if(count!=""):
               car_galery_dict[fin]["count"]=int(count)
            if(price!=""):
               car_galery_dict[fin]["price"]=float(price)
            if(year!=""):
               car_galery_dict[fin]["year"]=int(year)
            WriteToFile()
            print("Updated...")
        else:
            print("Car not found!!!")
            

            
        

    def Delete_Car():
        fin=input("Enter fin: ")
        if(fin in car_galery_dict):
            del car_galery_dict[fin]
            WriteToFile()
            print("Deleted...")
        else:
            print("Car not found!!!")
            


    choice=input("""
                 1. Show Cars
                 2. Search Car
                 3. Add Car
                 4. Update Car
                 5. Delete Car 
                 6. EXIT
                 Choose: 
                 """)
    
    if (choice=="1"):
        Show_All_Cars()
    elif (choice=="2"):
        fin=input("Enter fin: ")
        Search_Car(fin)
    elif (choice=="3"):
        Add_Car()
    elif (choice=="4"):
        Update_Car()
    elif (choice=="5"):
        Delete_Car()
    elif (choice=="6"):
        return 0
    else:
        print("Wrong input")
    
    AdminPanel()



def UserPanel():
        def Show_All_Cars_User():
             for fin in car_galery_dict:
                 if car_galery_dict[fin]["count"]==0:
                     continue
                 print(f"____{fin}______")
                 print("Model: ",car_galery_dict[fin]["model"])
                 print("Year: ",car_galery_dict[fin]["year"])
                 print("Count: ",car_galery_dict[fin]["count"])
                 print("Price: ",car_galery_dict[fin]["price"])
                 print("\n_____________________\n")
                    

        def Search_Car_User(name):
             flagg=True 
             for fin in car_galery_dict:
                 if name == car_galery_dict[fin]["model"]:
                     print(f"\n____{car_galery_dict[fin]["model"]}______")
                     print("Year: ",car_galery_dict[fin]["year"])
                     print("Count: ",car_galery_dict[fin]["count"])
                     print("Price: ",car_galery_dict[fin]["price"])     
                     break
                 else:
                     flagg=False
                 
             if flagg==False:  
                 print("Not Found")

        def Buy_Car(data):
            flag=1
            basket=[]
            for fin in car_galery_dict:
                if data== car_galery_dict[fin]["model"]:
                   if car_galery_dict[fin]["count"]==0:
                       print("This product is not in stock.")
                   else:    
                       basket.append(data)  
                       flag*=-1  
                       print(f"Basket:",basket)
                       if car_galery_dict[fin]["price"]>users_dict[username]["balance"]:
                           print("\nYou don't have enough money. \n\nDo You want to increase your balance? (If you want -> Press 1 , If you don't -> Press 2 .)")
                           choice=int(input("Choice: "))
                           if choice==1:
                               price=float(input("Enter Amount of Payment: "))
                               Increase_Balance(price)
                           elif choice==2:
                               return 0
                           else:
                               print("Enter Correct Choice!")
                       else:
                           print("Do you want to buy? Last desicion. \n\n1.Yes 2.No")
                           choice=int(input("\nEnter Choice: "))
                           if choice==1:
                               print("\nProduct sold.")
                           elif choice==2:
                               return 0
                           else:
                               print("Enter Correct Choice!")
                else:
                   flag=1
            if flag==1:
                print("Not Found")
               
                    
            

        def Increase_Balance(price):
            users_dict[username]["balance"]+=price
            print("Your Last Updated Balance: ",users_dict[username]["balance"])            


        choice=input("""
                 1. Show Cars
                 2. Search Car w/Name
                 3. Buy Car
                 4. Increase Balance
                 5. EXIT
                 Choose: """)
        print()
        
        if (choice=="1"):
            Show_All_Cars_User()
        elif (choice=="2"):
            name=input("Enter Name: ")
            Search_Car_User(name)
        elif (choice=="3"):
            data=input("Enter Name: ")
            Buy_Car(data)
        elif (choice=="4"):
            price=float(input("Enter Amount of Payment: "))
            Increase_Balance(price)
        elif (choice=="5"):
            return 0
        else:
            print("Wrong input")
        
        UserPanel()
      


def Login():
    global username
    username=input("Username: ")
    password=input("Password: ")
    if(username=="admin" and password=="admin123"):
        AdminPanel()
    else:
        if username in users_dict:
            if(password==users_dict[username]["password"]):
                UserPanel()
        else:
            print("Wrong username")
            


Login()
