using AdoNetExamProject;
using AdoNetExamProject.Entities;
using AdoNetExamProject.Repositories.Implements;
using AdoNetExamProject.Services.Implements;
using AdoNetExamProject.Services.Interfaces;
using System.Linq.Expressions;
using System.Text;


//Console.InputEncoding = Encoding.UTF8;
//Console.OutputEncoding = Encoding.UTF8;

//AppDbContext dbContext = new();
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



//static void Menu()
//{

//	Console.Write(@"1. Admin
//2. User
//3. Exit

//Your Choice: ");

//	int choice;
//	int.TryParse(Console.ReadLine(), out choice);

//	switch (choice)
//	{
//		case 1:

//			//AdminMenu();
//			break;

//		case 2:

//			//UserMenu();
//			break;

//		case 3:

//			return;

//		default:

//			Console.WriteLine("Choose the correct choice.");
//			break;
//	}

//}


//static void Login(int choice)
//{




//}


//static void Register(int choice)
//{

//	Console.Write("FirstName: ");
//	string firstname = Console.ReadLine();

//	Console.WriteLine("LastName: ");
//	string lastname = Console.ReadLine();

//	Console.Write("FirstName: ");
//	string username = Console.ReadLine();

//	Console.Write("Password: ");
//	string password = Console.ReadLine();

//	Console.Write("BirthDate: ");
//	string birthdate = Console.ReadLine();


//}


//static void AdminMenu() { }


//static void UserMenu()
//{

//	Console.WriteLine(@"
//1. Start Quiz
//2. Preious Results
//3. Top 20
//4. Settings
//5. Log out

//Your Choice: ");

//	int choice;
//	int.TryParse(Console.ReadLine(), out choice);

//	switch (choice)
//	{
//		case 1:



//		case 2:



//		case 3:



//		case 4:



//		case 5:



//		default:

//			Console.WriteLine("Choose The correct choice");
//			break;
//	}


//}



#region Get All Options

//var options = optionSer.GetAll();

//foreach (var option in options)
//{
//	Console.WriteLine($"{option.Id}  {option.Text}  {option.IsCorrect}  {option.QuestionId}");
//}

#endregion

#region Get By Id Option

//Console.Write("\nEnter Id: ");
//int id;
//int.TryParse(Console.ReadLine(), out id);

//var option = optionSer.GetById(id);

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

//optionSer.Create(text, isCorrect, questionId);

//Console.WriteLine("\nNew Option Created.");

#endregion

#region Update Option

//Console.Write("\nEnter Id: ");
//int id;
//int.TryParse(Console.ReadLine(), out id);


//Console.WriteLine(@"
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

//		Console.Write("Text: ");
//		string text = Console.ReadLine();

//		var updatedOption = optionSer.Update(id, text, null, null);

//		break;

//	case 2:

//		Console.Write("IsCorrect: ");
//		bool isCorrect;
//		bool.TryParse(Console.ReadLine(), out isCorrect);

//		var updatedOption2 = optionSer.Update(id, null, isCorrect, null);

//		break;

//	case 3:

//		Console.Write("QuestionId: ");
//		int questionId;
//		int.TryParse(Console.ReadLine(), out questionId);

//		var updatedOption3 = optionSer.Update(id, null, null, questionId);

//		break;

//	case 4:

//		Console.Write("Text: ");
//		string text2 = Console.ReadLine();
//		Console.Write("IsCorrect: ");

//		bool isCorrect2;
//		bool.TryParse(Console.ReadLine(), out isCorrect2);

//		Console.Write("QuestionId: ");
//		int questionId2;
//		int.TryParse(Console.ReadLine(), out questionId2);

//		break;

//	default:

//        Console.WriteLine("Enter The Correct Choice.");

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


