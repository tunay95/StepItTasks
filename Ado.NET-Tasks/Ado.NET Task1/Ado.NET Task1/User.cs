
/*
 Console üçün Register & Login proqramı yazın. Bütün məlumatlar Database-e yazilmali və oxunmalıdır
1. Sign In
2. Sign Up
3. Exit
*/


public class User 
{
    public static int Id = 1;

	public User(string firstName, string lastName, int age, string login, string password)
	{
		FirstName = firstName;
		LastName = lastName;
		Age = age;
		Login = login;
		Password = password;
	}

	public string FirstName { get; set; }    
    public string LastName { get; set; }    
    public int Age { get; set; }
	public string Login { get; set; }
	public string Password { get; set; }
}
