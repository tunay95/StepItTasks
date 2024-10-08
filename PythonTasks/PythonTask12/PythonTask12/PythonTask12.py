#==================Task 1=====================#

# users_dict={"nurane":"nurane123","Stepguest":"Guest112","narmin":"nurane123"}

# User username ve password daxil edir. Əgər database'də belə bir user varsa və 
# Password da düzdürsə, "Welcome" sözü çap olunsun. Əks halda səhvin nədə olduğunu desin.


"""
input_username=input("Enter The Username: ")
input_password=input("Enter The Password: ")

users_dict={
    "nurane":"nurane123",
    "Stepguest":"Guest112",
    "narmin":"nurane123",
    }

errorPswrd=1                                 #Səhvin nədə olduğunu müəyyən etmək üçün.

for user in users_dict:
    if input_username==user:
        if input_password==users_dict[user]:
            break
        else:
            errorPswrd*=-1  
    else:
        errorPswrd*=1

if input_username==user and input_password==users_dict[user]:
    print(f"\n!==============================================! \n\nWelcome!! , {input_username} \n")                                        # Hər ikisi düzgün olduqda.
elif errorPswrd>0:
    print(f"\n!==============================================! \n\nThere is no username as {input_username}. \n")                           #'username' düzgün olmadıqda.
else:
    print("\n!==============================================! \n\nYour password doesn't match up!! Please enter correct one. \n")           #'username' düzgün olub, 'password' səhv olduqda.
"""



#==================Task 2=====================#

# Registration

# User username və password daxil edir. Əgər database'də belə bir user varsa, yenisini daxil etməlidir.
# Çünki belə bir user artiq var. Yox əgər yoxdursa, database'ə əlavə edilsin.


"""
print("!================ REGISTRATION ================!\n")
input_username=input("Enter The Username: ")


users_dict={
    "nurane":"nurane123",
    "Stepguest":"Guest112",
    "narmin":"nurane123"
    }

flag=False

for user in users_dict:
    if input_username==user:
        break 
    else:
        flag=True
        
if input_username==user:
     print(f"\n!==============================================! \n\n❗ Username '{input_username}' is also added. Please try with another one.❗\n") 
else:
    input_password=input("Enter The Password: ")
    if input_username=="admin" and input_password=="admin123":
        print("\n!==============================================! \n\nWelcome Admin.\n")                
        print("*======================**======================*")
        print("|        Name          ||       Password       |")                                           #Əgər database'də belə bir user varsa.
        countt=1
        
        for user in users_dict:
            print("|======================||======================|")
            print(f"| {countt}.    {user+(15-len(user))*" "}||      {users_dict[user]+(16-len(users_dict[user]))*" "}|")
            countt+=1
        
        print("*======================**======================*")
    elif input_username=="admin" and input_password!="admin123":
        print("\n!==============================================! \n\n❗ARE YOU SURE YOU ARE AN ADMIN ? If You are not, Please enter another different username.❗\n")            #Admin olmadan 'admin' adından qeydiyyatdan keçmək istədikdə.
    else:
        # users_dict.update({input_username:input_password})                               #Adi qaydada 'member' kimi qeydiyyatdan keçdikdə.               
        users_dict[input_username]=input_password                                          #'Dictionary'-ə element əlavə etməyin 2-ci yolu.
        print("\n!==============================================! \n\n🎉🎉 Congrats!! 🎉🎉 You Registered. 🎉🎉 \n")                                  
"""
    
    
