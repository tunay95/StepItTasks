using AdoNetExamProject;
using AdoNetExamProject.Entities;
using AdoNetExamProject.Repositories.Implements;
using AdoNetExamProject.Services.Implements;
using AdoNetExamProject.Services.Interfaces;
using Microsoft.EntityFrameworkCore;
using System.Linq.Expressions;
using System.Reflection;
using System.Security.Cryptography;
using System.Text;


Console.InputEncoding = Encoding.UTF8;
Console.OutputEncoding = Encoding.UTF8;

//OptionRepository optionRepo = new(dbContext);
//OptionService optionSer = new OptionService(optionRepo);



#region AddDatas

//using AppDbContext dbContext = new AppDbContext();


#region Category

//Category category = new Category()
//{
//	Name = "Biology",
//};

//dbContext.Categories.Add(category);

#endregion


#region Quiz

//Quiz quiz = new Quiz()
//{

//	QuizName = "Imtahan 1",
//	CategoryId = 16,
//	Questions = new List<Question>()
//	{
//		new FourOptionQuestion
//		{
//			Statement = "Hansı hüceyrə tipləri insan orqanizmində çoxalma qabiliyyətinə malikdir?",
//			OptionsList = new List<Option>
//			{
//				new Option { Text = "Tökük hüceyrələr", IsCorrect = false },
//				new Option { Text = "Sinir hüceyrələri", IsCorrect = false },
//				new Option { Text = "Qan hüceyrələri", IsCorrect = true },
//				new Option { Text = "İmmunitet hüceyrələri", IsCorrect = false }
//			}
//		},

//		new FourOptionQuestion
//		{
//			Statement = "Fotosintez prosesi hansı üzvlərdə baş verir?",
//			OptionsList = new List<Option>
//			{
//				new Option { Text = "Kök", IsCorrect = false },
//				new Option { Text = "Gövdə", IsCorrect = false },
//				new Option { Text = "Yarpaqlar", IsCorrect = true },
//				new Option { Text = "Çiçəklər", IsCorrect = false }
//			}
//		},

//		new FourOptionQuestion
//		{
//			Statement = "İnsan orqanizmində hansı orqan qida maddələrinin mənimsənilməsi ilə məşğul olur?",
//			OptionsList = new List<Option>
//			{
//				new Option { Text = "Mədə", IsCorrect = false },
//				new Option { Text = "Qaraciyər", IsCorrect = false },
//				new Option { Text = "Bağırsaqlar", IsCorrect = true },
//				new Option { Text = "Böyrəklər", IsCorrect = false }
//			}
//		},

//		new FourOptionQuestion
//		{
//			Statement = "Hansı hüceyrə tipində xromosomlar daha çox sayda olur?",
//			OptionsList = new List<Option>
//			{
//				new Option { Text = "Erkək hüceyrələri", IsCorrect = false },
//				new Option { Text = "Dişi hüceyrələri", IsCorrect = false },
//				new Option { Text = "Somatik hüceyrələr", IsCorrect = false },
//				new Option { Text = "Cinsi hüceyrələr", IsCorrect = true }
//			}
//		},

//		new FourOptionQuestion
//		{
//			Statement = "İnsan bədənində qan dövranının başlıca məqsədi nədir?",
//			OptionsList = new List<Option>
//			{
//				new Option { Text = "Qida maddələrinin hüceyrələrə çatdırılması", IsCorrect = false },
//				new Option { Text = "Oksigenin hüceyrələrə çatdırılması", IsCorrect = true },
//				new Option { Text = "Zəhərli maddələrin orqanizmdən atılması", IsCorrect = false },
//				new Option { Text = "Təsirli maddələrin sintez olunması", IsCorrect = false }
//			}
//		},

//		new FourOptionQuestion
//		{
//			Statement = "Hangi orqanda insulin hormonunun istehsalı baş verir?",
//			OptionsList = new List<Option>
//			{
//				new Option { Text = "Böyrəklər", IsCorrect = false },
//				new Option { Text = "Qaraciyər", IsCorrect = false },
//				new Option { Text = "Sümük", IsCorrect = false },
//				new Option { Text = "Pankreas", IsCorrect = true }
//			}
//		},

//		new FourOptionQuestion
//		{
//			Statement = "İnsan orqanizmində hansı proses qida maddələrinin enerjiyə çevrilməsini təmin edir?",
//			OptionsList = new List<Option>
//			{
//				new Option { Text = "Fotosintez", IsCorrect = false },
//				new Option { Text = "Qidalanma", IsCorrect = false },
//				new Option { Text = "Tənəffüs", IsCorrect = true },
//				new Option { Text = "Qarışdırma", IsCorrect = false }
//			}
//		},

//		new FourOptionQuestion
//		{
//			Statement = "Hansı tərbiyə dövrü həyatın inkişafında vacibdir?",
//			OptionsList = new List<Option>
//			{
//				new Option { Text = "Yeniyetməlik dövrü", IsCorrect = false },
//				new Option { Text = "Uşaqlıq dövrü", IsCorrect = false },
//				new Option { Text = "Hamiləlik dövrü", IsCorrect = true },
//				new Option { Text = "Yaşlılıq dövrü", IsCorrect = false }
//			}
//		},

//		new MultipleChoiceQuestion
//		{
//			Statement = "Fotosintez prosesinin başlıca məhsulu nədir?",
//			OptionsList = new List<Option>
//			{
//				new Option { Text = "Oksigen", IsCorrect = true },
//				new Option { Text = "Karbondioksid", IsCorrect = false },
//				new Option { Text = "Qlükoza", IsCorrect = true },
//				new Option { Text = "Azot", IsCorrect = false },
//				new Option { Text = "Su", IsCorrect = true }
//			}
//		},

//		new MultipleChoiceQuestion
//		{
//			Statement = "İnsan orqanizmində hansı orqanın fəaliyyətində hormonlar rol oynayır?",
//			OptionsList = new List<Option>
//			{
//				new Option { Text = "Böyrəklər", IsCorrect = true },
//				new Option { Text = "Qaraciyər", IsCorrect = false },
//				new Option { Text = "Sümük", IsCorrect = false },
//				new Option { Text = "Pankreas", IsCorrect = true },
//				new Option { Text = "Böyümə vəzləri", IsCorrect = false }
//			}
//		},

//		new MultipleChoiceQuestion
//		{
//			Statement = "Hangi orqanda qida maddələri əmilir?",
//			OptionsList = new List<Option>
//			{
//				new Option { Text = "Yuxarı bağırsaq", IsCorrect = false },
//				new Option { Text = "Kiçik bağırsaq", IsCorrect = true },
//				new Option { Text = "Sümük", IsCorrect = false },
//				new Option { Text = "Mədə", IsCorrect = false },
//				new Option { Text = "Bağırsaq", IsCorrect = false }
//			}
//		},

//		new MultipleChoiceQuestion
//		{
//			Statement = "Tərkibində ən çox protein olan orqan hansıdadır?",
//			OptionsList = new List<Option>
//			{
//				new Option { Text = "Beyin", IsCorrect = false },
//				new Option { Text = "Pankreas", IsCorrect = false },
//				new Option { Text = "Qaraciyər", IsCorrect = true },
//				new Option { Text = "Sümük", IsCorrect = false },
//				new Option { Text = "Qan", IsCorrect = true }
//			}
//		},

//		new MultipleChoiceQuestion
//		{
//			Statement = "Hansı orqanizm adaptasiyaları təmin edir?",
//			OptionsList = new List<Option>
//			{
//				new Option { Text = "Ətraf mühitin dəyişməsi", IsCorrect = true },
//				new Option { Text = "Genetik dəyişikliklər", IsCorrect = false },
//				new Option { Text = "Fizioloji dəyişikliklər", IsCorrect = true },
//				new Option { Text = "Sosial dəyişikliklər", IsCorrect = false },
//				new Option { Text = "Rəng dəyişikliyi", IsCorrect = false }
//			}
//		},

//		new MultipleChoiceQuestion
//		{
//			Statement = "Hansı maddələr qan dövranında daha çox mövcuddur?",
//			OptionsList = new List<Option>
//			{
//				new Option { Text = "Karbohidratlar", IsCorrect = false },
//				new Option { Text = "Su", IsCorrect = true },
//				new Option { Text = "Yağlar", IsCorrect = false },
//				new Option { Text = "Oksigen", IsCorrect = true },
//				new Option { Text = "Hormonlar", IsCorrect = false }
//			}
//		},

//		 new TrueFalseQuestion
//		{
//			Statement = "Hormonlar insan orqanizmində yalnız böyümə proseslərini tənzimləyir.",
//			OptionsList = new List<Option>
//			{
//				new Option { Text = "True", IsCorrect = false },
//				new Option { Text = "False", IsCorrect = true }
//			},
//		},

//		new TrueFalseQuestion
//		{
//			Statement = "Fotosintez nəticəsində oksigen istehsal olunur.",
//			OptionsList = new List<Option>
//			{
//				new Option { Text = "True", IsCorrect = true },
//				new Option { Text = "False", IsCorrect = false }
//			}
//		},

//		new TrueFalseQuestion
//		{
//			Statement = "Insan orqanizmində bir çox hormon bir-birini tamamlayır.",
//			OptionsList = new List<Option>
//			{
//				new Option { Text = "True", IsCorrect = true },
//				new Option { Text = "False", IsCorrect = false }
//			}
//		},

//		new TrueFalseQuestion
//		{
//			Statement = "İnsan orqanizmində yalnız mədə hüceyrələri qida maddələrini emal edir.",
//			OptionsList = new List<Option>
//			{
//				new Option { Text = "True", IsCorrect = false },
//				new Option { Text = "False", IsCorrect = true }
//			}
//		},

//		new FillTheGap
//		{
//			Statement = "Fotosintez prosesinin əhəmiyyətini izah edin: Fotosintez bitkilərin __________ enerjisini kimyəvi enerjiyə çevirməsi prosesidir.",
//			OptionsList = new List<Option>
//			{
//				new Option { Text = "işıq", IsCorrect = true }
//			}
//		},

//		new FillTheGap
//		{
//			Statement = "İnsan orqanizmində qlükozanın rolu nədir? Qlükoza __________ mənbəyidir.",
//			OptionsList = new List<Option>
//			{
//				new Option { Text = "enerji", IsCorrect = true }
//			}
//		},

//		new FillTheGap
//		{
//			Statement = "Nəzarətçilər və Hormonlar arasındakı əlaqəni izah edin: Hormonlar __________ bezlər tərəfindən istehsal olunur və orqanizmdəki müxtəlif funksiyaları tənzimləyir.",
//			OptionsList = new List<Option>
//			{
//				new Option { Text = "endokrin", IsCorrect = true }
//			}
//		}
//	}
//};

//dbContext.Quizzes.Add(quiz);

#endregion


#region User

//User user = new User()
//{
//	FirstName = "Tunay",
//	LastName = "Huseynli",
//	Username = "tunay95",
//	Password = "Tunay2004",
//	BirthDate = new DateTime(2004, 09, 14),
//	UserRole = UserRole.User
//};

//dbContext.Users.Add(user);

#endregion


#region UserQuiz

//UserQuiz userquiz = new UserQuiz()
//{
//	UserId = 18,
//	QuizId = 6,
//	SuccessRate = 100,
//	CorrectAnswerCount = 20,
//	PassedAnswerCount = 0,
//	WrongAnswerCount = 0,
//};

//dbContext.UserQuizzes.Add(userquiz);

#endregion


//dbContext.SaveChanges();

#endregion

Menu();


static void Menu()
{
	Console.Clear();

	AppDbContext dbContext = new();
	Repository<User> userRepository = new(dbContext);
	UserService userService2 = new(userRepository);
	Service<User> userService = new UserService(userRepository);

	Console.Write(@"1. Admin
2. User
3. Exit

Your Choice: ");

	int choice;
	int.TryParse(Console.ReadLine(), out choice);

	if (choice == 3) return;


	Console.Clear();

	UserRole userRole;

	if (choice == 1) userRole = UserRole.Admin;
	else userRole = UserRole.User;


	Console.Write("1. Login\n2. Register\n\nYour Choice: ");
	int userLogRegChoice;
	int.TryParse(Console.ReadLine(), out userLogRegChoice);

	switch (userLogRegChoice)
	{
		case 1:

			Console.Write("Username: ");
			string usernameUserLogin = Console.ReadLine();

			Console.Write("Password: ");
			string passwordUserLogin = Console.ReadLine();

			if (userService2.Login(usernameUserLogin, passwordUserLogin, userRole))
			{
				if (userRole == UserRole.Admin) AdminMenu(usernameUserLogin);
				else UserMenu(usernameUserLogin);
			}

			else
			{
				Console.WriteLine("\nUsername or Password is wrong.");
			}

			break;

		case 2:

			Console.Write("FirstName: ");
			string firstnameAdminReg = Console.ReadLine();

			Console.Write("LastName: ");
			string lastnameAdminReg = Console.ReadLine();

			Console.Write("Username: ");
			string usernameAdminReg = Console.ReadLine();

			Console.Write("Password: ");
			string passwordAdminReg = Console.ReadLine();

			Console.Write("BirthDate(YYYY - MM - DD): ");
			DateTime birthdateAdminReg = DateTime.Parse(Console.ReadLine());

			User newUser = userService.Create(firstnameAdminReg, lastnameAdminReg, usernameAdminReg, passwordAdminReg, birthdateAdminReg, userRole);

			Console.WriteLine("\nAccount Created");

			break;

		default:

			Console.WriteLine("Choose the correct choice.");
			break;
	}

	Thread.Sleep(2000);

	Menu();

}


static void AdminMenu(string username)
{

	AppDbContext dbContext2 = new AppDbContext();

	Console.WriteLine(@$"-------------- * Account - {username} * --------------

Choose the entity on which you will implement CRUD operations:

1. Category
2. Quiz
3. Question
4. Option
5. Quiz Result
6. User

7. Back
8. Exit

Your Choice: ");


	int choice;
	int.TryParse(Console.ReadLine(), out choice);


	Console.Clear();


	Console.WriteLine(@$"-------------- * Account - {username} * --------------

Choose the entity on which you will implement CRUD operations:

1. Get All
2. Get By Id
3. Create
4. Update
5. Delete
6. Delete All

7. Back
8. Exit

Your Choice: ");


	int choice2;
	int.TryParse(Console.ReadLine(), out choice2);


	switch (choice)         // Which Entity
	{

		case 1:         // Category	

			Repository<Category> repositoryCategory = new(dbContext2);
			Service<Category> serviceCategory = new Service<Category>(repositoryCategory);

			switch (choice2)
			{
				case 1:

					var categories = serviceCategory.GetAll();

					foreach (var category in categories)
					{
						Console.WriteLine($"Id: {category.Id} -> {category.Name}");
					}

					break;

				case 2:

					Console.Write("\nEnter Id: ");
					int idCategoryFind;
					int.TryParse(Console.ReadLine(), out idCategoryFind);

					var category2 = serviceCategory.GetById(idCategoryFind);

					Console.WriteLine($"Id: {category2.Id} -> {category2.Name}");

					break;


				case 3:

					Console.Write("Name: ");
					string categoryCreateName = Console.ReadLine();

					serviceCategory.Create(categoryCreateName);

					Console.WriteLine("\nNew Category Created.");

					break;

				case 4:

					Console.Write("\nEnter Id: ");
					int idCategory;
					int.TryParse(Console.ReadLine(), out idCategory);


					Console.Write(@"
				Which Property do you want to update?

				1. Statement

				Your Answer: ");

					int choiceCategory;
					int.TryParse(Console.ReadLine(), out choiceCategory);


					switch (choice)
					{
						case 1:

							Console.Write("\nStatement: ");
							string statementUpdate = Console.ReadLine();

							var updatedCategory = serviceCategory.Update(idCategory);

							break;


						default:

							Console.WriteLine("\nEnter The Correct Choice.");

							break;

					}

					break;

				case 5:

					Console.Write("\nEnter Id: ");
					int idDeletedCategory;
					int.TryParse(Console.ReadLine(), out idDeletedCategory);

					serviceCategory.DeleteById(idDeletedCategory);

					Console.WriteLine("\nCategory has been deleted.");

					break;

				case 6:

					serviceCategory.DeleteAll();
					Console.WriteLine("\nAll Categories was deleted. ");

					break;

				default:

					break;


			}

			Console.WriteLine("\nOption updated successfully.");

			break;


		case 2:         // Quiz

			Repository<Quiz> repositoryQuiz = new(dbContext2);
			Service<Quiz> serviceQuiz = new(repositoryQuiz);

			break;


		case 3:         // Question

			Repository<Question> repositoryQuestion = new (dbContext2);
			Service<Question> serviceQuestion = new QuestionService(repositoryQuestion);

			switch (choice2)
			{
				case 1:

					var questions = serviceQuestion.GetAll();

					foreach (var quest in questions)
					{
						Console.WriteLine($"Id: {quest.Id} -> {quest.Statement} | QuizId: {quest.QuizId}");
					}
					break;

				case 2:

					Console.Write("\nEnter Id: ");
					int id;
					int.TryParse(Console.ReadLine(), out id);

					var quest2 = serviceQuestion.GetById(id);

					Console.WriteLine($"Id: {quest2.Id} -> {quest2.Statement} | QuizId: {quest2.QuizId}");

					break;

				case 3:

					Console.Write("Statement: ");
					string statement = Console.ReadLine();


					Console.Write("QuestionId: ");
					int questionId;
					int.TryParse(Console.ReadLine(), out questionId);

					serviceQuestion.Create(statement, questionId);

					Console.WriteLine("\nNew Option Created.");

					break;

				case 4:

					Console.Write("\nEnter Id: ");
					int idQuestion;
					int.TryParse(Console.ReadLine(), out idQuestion);


					Console.Write(@"
				Which Property do you want to update?

				1. Statement
				2. QuestionId
				3. Both

				Your Answer: ");

					int choiceQuestion;
					int.TryParse(Console.ReadLine(), out choiceQuestion);


					switch (choiceQuestion)
					{
						case 1:

							Console.Write("\nStatement: ");
							string statementUpdate = Console.ReadLine();

							var updatedQuestion = serviceQuestion.Update(idQuestion, statementUpdate, null, null);

							break;


						case 2:

							Console.Write("\nQuizId: ");
							int quizIdQuestion;
							int.TryParse(Console.ReadLine(), out quizIdQuestion);

							var updatedOption3 = serviceQuestion.Update(idQuestion, null, null, quizIdQuestion);

							break;

						case 3:

							Console.Write("\nText: ");
							string textOption2 = Console.ReadLine();
							Console.Write("IsCorrect: ");

							bool isCorrectOption2;
							bool.TryParse(Console.ReadLine(), out isCorrectOption2);

							Console.Write("QuizId: ");
							int quizIdQuestion2;
							int.TryParse(Console.ReadLine(), out quizIdQuestion2);

							var updatedOption4 = serviceQuestion.Update(idQuestion, textOption2, null, quizIdQuestion2);

							break;

						default:

							Console.WriteLine("\nEnter The Correct Choice.");

							break;

					}

					break;

				case 5:

					Console.Write("\nEnter Id: ");
					int idDeleteqQuestion;
					int.TryParse(Console.ReadLine(), out idDeleteqQuestion);

					serviceQuestion.DeleteById(idDeleteqQuestion);

					Console.WriteLine("\nOption has been deleted.");

					break;

				case 6:

					serviceQuestion.DeleteAll();
					break;

				default:

					break;


			}

			Console.WriteLine("\nOption updated successfully.");

			break;


		case 4:         // Option

			Repository<Option> repositoryOption = new(dbContext2);
			Service<Option> serviceOption = new(repositoryOption);

			switch (choice2)
			{
				case 1:

					var options = serviceOption.GetAll();

					foreach (var opt in options)
					{
						Console.WriteLine($"{opt.Id}  {opt.Text}  {opt.IsCorrect}  {opt.QuestionId}");
					}
					break;

				case 2:

					Console.Write("\nEnter Id: ");
					int id;
					int.TryParse(Console.ReadLine(), out id);

					var option = serviceOption.GetById(id);

					Console.WriteLine($"{option.Id}  {option.Text}  {option.IsCorrect}  {option.QuestionId}");

					break;

				case 3:

					Console.Write("Text: ");
					string text = Console.ReadLine();

					Console.Write("IsCorrect: ");
					bool isCorrect;
					bool.TryParse(Console.ReadLine(), out isCorrect);

					Console.Write("QuestionId: ");
					int questionId;
					int.TryParse(Console.ReadLine(), out questionId);

					serviceOption.Create(text, isCorrect, questionId);

					Console.WriteLine("\nNew Option Created.");

					break;

				case 4:

					Console.Write("\nEnter Id: ");
					int idOption;
					int.TryParse(Console.ReadLine(), out idOption);


					Console.Write(@"
				Which Property do you want to update?

				1. Text
				2. Accuracy
				3. Question Id
				4. All

				Your Answer: ");

					int choiceOption;
					int.TryParse(Console.ReadLine(), out choiceOption);


					switch (choice)
					{
						case 1:

							Console.Write("\nText: ");
							string textOption = Console.ReadLine();

							var updatedOption = serviceOption.Update(idOption, textOption, null, null);

							break;

						case 2:

							Console.Write("\nIsCorrect: ");
							bool isCorrectOption;
							bool.TryParse(Console.ReadLine(), out isCorrectOption);

							var updatedOption2 = serviceOption.Update(idOption, null, isCorrectOption, null);

							break;

						case 3:

							Console.Write("\nQuestionId: ");
							int questionIdOption;
							int.TryParse(Console.ReadLine(), out questionIdOption);

							var updatedOption3 = serviceOption.Update(idOption, null, null, questionIdOption);

							break;

						case 4:

							Console.Write("\nText: ");
							string textOption2 = Console.ReadLine();
							Console.Write("IsCorrect: ");

							bool isCorrectOption2;
							bool.TryParse(Console.ReadLine(), out isCorrectOption2);

							Console.Write("QuestionId: ");
							int questionIdOption2;
							int.TryParse(Console.ReadLine(), out questionIdOption2);

							var updatedOption4 = serviceOption.Update(idOption, textOption2, isCorrectOption2, questionIdOption2);

							break;

						default:

							Console.WriteLine("\nEnter The Correct Choice.");

							break;
					}

					Console.WriteLine("\nOption updated successfully.");

					break;

				case 5:

					Console.Write("\nEnter Id: ");
					int idDeleteOption;
					int.TryParse(Console.ReadLine(), out idDeleteOption);

					serviceOption.DeleteById(idDeleteOption);

					Console.WriteLine("\nOption has been deleted.");

					break;

				case 6:

					serviceOption.DeleteAll();

					break;

				default:

					Console.WriteLine("\n\nChoose The Correct Choice.");

					break;
			}

			break;


		case 5:     // UserQuiz

			Repository<UserQuiz> repositoryUserQuiz = new(dbContext2);
			Service<UserQuiz> serviceUserQuiz = new(repositoryUserQuiz);

			switch (choice2)
			{
				case 1:

					var userquizzes = serviceUserQuiz.GetAll();

					foreach (var uq in userquizzes)
					{
						Console.WriteLine($"{uq.Id}  {uq.UserId}  {uq.QuizId}  {uq.CorrectAnswerCount}  {uq.WrongAnswerCount}  {uq.PassedAnswerCount}  {uq.SuccessRate}");
					}

					break;

				case 2:

					Console.Write("\nEnter Id: ");
					int id;
					int.TryParse(Console.ReadLine(), out id);

					var uq2 = serviceUserQuiz.GetById(id);

					Console.WriteLine($"{uq2.Id}  {uq2.UserId}  {uq2.QuizId}  {uq2.CorrectAnswerCount}  {uq2.WrongAnswerCount}  {uq2.PassedAnswerCount}  {uq2.SuccessRate}");

					break;

				case 3:

					Console.Write("UserId: ");
					int userId;
					int.TryParse(Console.ReadLine(), out userId);

					Console.Write("QuestionId: ");
					int quizId;
					int.TryParse(Console.ReadLine(), out quizId);

					Console.Write("Rank: ");
					int rank;
					int.TryParse(Console.ReadLine(), out rank);

					Console.Write("SuccessRate: ");
					int successRate;
					int.TryParse(Console.ReadLine(), out successRate);

					Console.Write("CorrectAnswerCount: ");
					int correctAnswerCount;
					int.TryParse(Console.ReadLine(), out correctAnswerCount);

					Console.Write("WrongAnswerCount: ");
					int wrongAnswerCount;
					int.TryParse(Console.ReadLine(), out wrongAnswerCount);

					Console.Write("PassedAnswerCount: ");
					int passedAnswerCount;
					int.TryParse(Console.ReadLine(), out passedAnswerCount);

					serviceUserQuiz.Create(userId, quizId, rank, successRate, correctAnswerCount, wrongAnswerCount, passedAnswerCount);

					Console.WriteLine("\nNew Quiz Result Created.");

					break;

				case 4:

					Console.Write("\nEnter Id: ");
					int idResult;
					int.TryParse(Console.ReadLine(), out idResult);


					Console.Write(@"
				Which Property do you want to update?

				1. Correct Answer Count
				2. Passed Answer Count
				3. Wrong Answer Count		
				4. Success Rate
				5. User Id
				6. Quiz Id
				7. Rank
				8. All

				Your Answer: ");

					int choiceResult;
					int.TryParse(Console.ReadLine(), out choiceResult);


					switch (choice)
					{
						case 1:

							Console.Write("CorrectAnswerCount: ");
							int correctAnswerCount2;
							int.TryParse(Console.ReadLine(), out correctAnswerCount2);

							var updatedOption = serviceUserQuiz.Update(idResult, correctAnswerCount2, null, null, null, null, null, null);

							break;

						case 2:

							Console.Write("WrongAnswerCount: ");
							int wrongAnswerCount2;
							int.TryParse(Console.ReadLine(), out wrongAnswerCount2);

							var updatedOption2 = serviceUserQuiz.Update(idResult, null, wrongAnswerCount2, null, null, null, null, null);


							break;

						case 3:

							Console.Write("PassedAnswerCount: ");
							int passedAnswerCount2;
							int.TryParse(Console.ReadLine(), out passedAnswerCount2);

							var updatedOption3 = serviceUserQuiz.Update(idResult, null, null, passedAnswerCount2, null, null, null, null);

							break;


						case 4:

							Console.Write("SuccessRate: ");
							int successRate2;
							int.TryParse(Console.ReadLine(), out successRate2);

							var updatedOption4 = serviceUserQuiz.Update(idResult, null, null, null, successRate2, null, null, null);

							break;

						case 5:

							Console.Write("UserId: ");
							int userId2;
							int.TryParse(Console.ReadLine(), out userId2);

							var updatedOption5 = serviceUserQuiz.Update(idResult, null, null, null, null, userId2, null, null);

							break;


						case 6:

							Console.Write("QuestionId: ");
							int quizId2;
							int.TryParse(Console.ReadLine(), out quizId2);

							var updatedOption6 = serviceUserQuiz.Update(idResult, null, null, null, null, null, quizId2, null);

							break;


						case 7:

							Console.Write("Rank: ");
							int rank2;
							int.TryParse(Console.ReadLine(), out rank2);

							var updatedOption7 = serviceUserQuiz.Update(idResult, null, null, null, null, null, null, null, rank2);

							break;

						case 8:

							Console.Write("UserId: ");
							int userId3;
							int.TryParse(Console.ReadLine(), out userId3);

							Console.Write("QuestionId: ");
							int quizId3;
							int.TryParse(Console.ReadLine(), out quizId3);

							Console.Write("Rank: ");
							int rank3;
							int.TryParse(Console.ReadLine(), out rank3);

							Console.Write("SuccessRate: ");
							int successRate3;
							int.TryParse(Console.ReadLine(), out successRate3);

							Console.Write("CorrectAnswerCount: ");
							int correctAnswerCount3;
							int.TryParse(Console.ReadLine(), out correctAnswerCount3);

							Console.Write("WrongAnswerCount: ");
							int wrongAnswerCount3;
							int.TryParse(Console.ReadLine(), out wrongAnswerCount3);

							Console.Write("PassedAnswerCount: ");
							int passedAnswerCount3;
							int.TryParse(Console.ReadLine(), out passedAnswerCount3);

							serviceUserQuiz.Create(idResult,userId3, quizId3, rank3, successRate3, correctAnswerCount3, wrongAnswerCount3, passedAnswerCount3);

							break;

						default:

							Console.WriteLine("\nEnter The Correct Choice.");

							break;
					}

					Console.WriteLine("\nOption updated successfully.");

					break;

				case 5:

					Console.Write("\nEnter Id: ");
					int idDeleteResult;
					int.TryParse(Console.ReadLine(), out idDeleteResult);

					serviceUserQuiz.DeleteById(idDeleteResult);

					Console.WriteLine("\nResult has been deleted.");

					break;

				case 6:

					serviceUserQuiz.DeleteAll();

					break;

				default:

					Console.WriteLine("\n\nChoose The Correct Choice.");

					break;
			}

			break;


		case 6:     // User

			Repository<User> repositoryUser = new(dbContext2);
			Service<User> serviceUser = new(repositoryUser);



			break;

		case 7:

			Menu();
			break;

		case 8:

			return;

		default:

			Console.WriteLine("Choose the correct choice.");
			break;
	}


}



static void UserMenu(string username)
{

	Console.WriteLine(@"
1. Start Quiz
2. Preious Results
3. Top 20
4. Settings
5. Log out

Your Choice: ");

	int choice;
	int.TryParse(Console.ReadLine(), out choice);

	switch (choice)
	{
		case 1:



		case 2:



		case 3:



		case 4:



		case 5:



		default:

			Console.WriteLine("Choose The correct choice");
			break;
	}


}



#region Get All Options

//var options = optionService.GetAll();

//foreach (var option in options)
//{
//	Console.WriteLine($"{option.Id}  {option.Text}  {option.IsCorrect}  {option.QuestionId}");
//}

#endregion

#region Get By Id Option


//Console.Write("\nEnter Id: ");
//int id;
//int.TryParse(Console.ReadLine(), out id);

//var option = optionService.GetById(id);

//Console.WriteLine($"{option.Id}  {option.Text}  {option.IsCorrect}  {option.QuestionId}");


#endregion

#region Create Option

//Console.Write("Text: ");
//string text = Console.ReadLine();

//Console.Write("IsCorrect: ");
//bool isCorrect;
//bool.TryParse(Console.ReadLine(), out isCorrect);

//Console.Write("QuestionId: ");
//int questionId;
//int.TryParse(Console.ReadLine(), out questionId);

//optionService.Create(text, isCorrect, questionId);

//Console.WriteLine("\nNew Option Created.");

#endregion

#region Update Option

//Console.Write("\nEnter Id: ");
//int id;
//int.TryParse(Console.ReadLine(), out id);


//Console.Write(@"
//Which Property do you want to update?

//1. Text
//2. Accuracy
//3. Question Id
//4. All

//Your Answer: ");

//int choice;
//int.TryParse(Console.ReadLine(), out choice);


//switch (choice)
//{
//	case 1:

//		Console.Write("\nText: ");
//		string text = Console.ReadLine();

//		var updatedOption = optionService.Update(id, text, null, null);

//		break;

//	case 2:

//		Console.Write("\nIsCorrect: ");
//		bool isCorrect;
//		bool.TryParse(Console.ReadLine(), out isCorrect);

//		var updatedOption2 = optionService.Update(id, null, isCorrect, null);

//		break;

//	case 3:

//		Console.Write("\nQuestionId: ");
//		int questionId;
//		int.TryParse(Console.ReadLine(), out questionId);

//		var updatedOption3 = optionService.Update(id, null, null, questionId);

//		break;

//	case 4:

//		Console.Write("\nText: ");
//		string text2 = Console.ReadLine();
//		Console.Write("IsCorrect: ");

//		bool isCorrect2;
//		bool.TryParse(Console.ReadLine(), out isCorrect2);

//		Console.Write("QuestionId: ");
//		int questionId2;
//		int.TryParse(Console.ReadLine(), out questionId2);

//		var updatedOption4 = optionService.Update(id, text2, isCorrect2, questionId2);

//		break;

//	default:

//		Console.WriteLine("\nEnter The Correct Choice.");

//		break;
//}

//Console.WriteLine("\nOption updated successfully.");

#endregion

#region Delete By Id Option

//Console.Write("\nEnter Id: ");
//int id;
//int.TryParse(Console.ReadLine(), out id);

//optionSer.DeleteById(id);

//Console.WriteLine("\nOption has been deleted.");

#endregion

#region Delete All

//optionSer.DeleteAll();

#endregion

