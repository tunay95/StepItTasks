
#region Task

/*
 Console üçün Register & Login proqramı yazın. 
Bütün məlumatlar Database-e yazilmali və oxunmalıdır

1. Sign In
2. Sign Up
3. Exit
*/

#endregion


using Microsoft.Data.SqlClient;

string connectionString = @"Server = (localdb)\MSSQLLocalDB; Database = Users; Integrated Security = True; Trust Server Certificate = True";
using SqlConnection sqlConnection = new SqlConnection(connectionString);
SqlCommand sqlCommand;

while (true)
{
	Thread.Sleep(1000);
	Console.Clear();

	Console.Write("1. Sign In\n2. Sign Up\n3. Exit\n\nYour Choice: ");
	int choice = int.Parse(Console.ReadLine());

	sqlConnection.Open();

	string selectQuery = @"SELECT FirstName, LastName, Login, Password  FROM  Users";
	sqlCommand = new SqlCommand(selectQuery, sqlConnection);
	SqlDataReader reader = sqlCommand.ExecuteReader();

	switch (choice)
	{
		case 1:

			int wrongAttempt = 0;
			bool isLogined = false;
			Console.Write("Enter Login: ");
			string login2 = Console.ReadLine();

			while (reader.Read())
			{
				if (reader["Login"].ToString() == login2)
				{
					isLogined = true;

					while (wrongAttempt <= 3)
					{
						Console.Write("Enter Password: ");
						string password2 = Console.ReadLine();

						if (reader["Password"].ToString() == password2)
						{
							Console.WriteLine($"\nWelcome {reader["FirstName"]} {reader["LastName"]}");
							return;
						}

						Console.WriteLine("Wrong Password! Try Again..");
						wrongAttempt++;
					}

					if (wrongAttempt == 4)
					{
						Console.WriteLine("So Many Wrong Attempts !!");
					}
				}
			}

			if (!isLogined) Console.WriteLine("The Login you entered is wrong!");

			sqlConnection.Close();

			break;



		case 2:

			string firstName;
			while (true)
			{
				Console.Write("Enter FirstName: ");
				firstName = Console.ReadLine();

				if (firstName.Length > 20 || firstName.Length < 3)
				{
					Console.WriteLine("Enter the size of FirstName correctly!");
					continue;
				}

				break;
			}


			string lastName;
			while (true)
			{
				Console.Write("Enter LastName: ");
				lastName = Console.ReadLine();

				if (lastName.Length > 20 || lastName.Length < 5)
				{
					Console.WriteLine("Enter the size of LastName correctly!");
					continue;
				}

				break;
			}


			int age;
			while (true)
			{
				Console.Write("Enter Age: ");
				age = int.Parse(Console.ReadLine());

				if (age > 150 || age < 8)
				{
					Console.WriteLine("Enter Age Correctly or You're Underage!");
					continue;
				}

				break;
			}


			string login;
			while (true)
			{
				Console.Write("Enter Login: ");
				login = Console.ReadLine();

				if (login.Length > 15 || login.Length < 4)
				{
					Console.WriteLine("Enter the size of LastName correctly!");
					continue;
				}

				break;
			}

			while (reader.Read())
			{
				if (reader["Login"].ToString() == login)
				{
					Console.WriteLine("The Login You entered already exsist. Enter Login Again.");
				}

				break;
			}
			sqlConnection.Close();


			string password;
			while (true)
			{
				Console.Write("Enter Password: ");
				password = Console.ReadLine();

				if (password.Length > 20 || password.Length < 6)
				{
					Console.WriteLine("Enter the size of Password correctly!");
					continue;
				}

				break;
			}


			sqlConnection.Open();

			User user = new User(firstName, lastName, age, login, password);

			string insertQuery = @$"INSERT INTO Users(FirstName, LastName, Age, Login, Password)
					   VALUES('{user.FirstName}','{user.LastName}','{user.Age}','{user.Login}','{user.Password}')";

			sqlCommand = new SqlCommand(insertQuery, sqlConnection);

			sqlCommand.ExecuteNonQuery();

			sqlConnection.Close();

			break;


		case 3:
			sqlConnection.Close();
			return;

		default:
			Console.WriteLine("Enter Correct Choice!!");
			sqlConnection.Close();
			break;
	}

}








