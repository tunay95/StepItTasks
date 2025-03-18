using AdoNetExamProject.Entities;
using Microsoft.EntityFrameworkCore;


namespace AdoNetExamProject
{
	public class AppDbContext : DbContext
	{
		public AppDbContext()
		{
			//Database.EnsureCreated();
		}

		public DbSet<User> Users { get; set; }
		public DbSet<Quiz> Quizzes { get; set; }
		public DbSet<Question> Questions { get; set; }
		public DbSet<UserQuiz> UserQuizzes { get; set; }
		public DbSet<Category> Categories { get; set; }
		public DbSet<Option> Options { get; set; }

		protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
		{
			optionsBuilder.UseSqlServer(@"Server=(localdb)\MSSQLLocalDB;Database=QuizProject;Integrated Security=True;Trust Server Certificate=True;");
		}

		protected override void OnModelCreating(ModelBuilder modelBuilder)
		{

			// Category

			modelBuilder.Entity<Category>()
				.Property(c => c.Id)
				.ValueGeneratedOnAdd();

			modelBuilder.Entity<Category>()
				.Property(c => c.Name)
				.IsRequired()
				.HasMaxLength(15);

			modelBuilder.Entity<Category>()
				.HasIndex(c => c.Name)
				.IsUnique();

			modelBuilder.Entity<Category>()
				.ToTable(c => c.HasCheckConstraint("CK_CategoryName_MinValue",
				"LEN([Name]) >= 3"));


			// User

			modelBuilder.Entity<User>()
				.Property(u => u.Id)
				.ValueGeneratedOnAdd();

			modelBuilder.Entity<User>()
				.Property(u => u.FirstName)
				.IsRequired()
				.HasMaxLength(15);

			modelBuilder.Entity<User>()
				.Property(u => u.LastName)
				.IsRequired()
				.HasMaxLength(15);

			modelBuilder.Entity<User>()
				.Property(u => u.Username)
				.IsRequired()
				.HasMaxLength(15);

			modelBuilder.Entity<User>()
				.Property(u => u.Password)
				.IsRequired()
				.HasMaxLength(15);

			modelBuilder.Entity<User>()
				.HasIndex(u => u.Username)
				.IsUnique();

			modelBuilder.Entity<User>()
				.Property(u => u.UserRole)
				.HasConversion<string>()
				.HasDefaultValue(UserRole.User);

			modelBuilder.Entity<User>()
				.ToTable(u => u.HasCheckConstraint("CK_BirthDate",
				"YEAR(BirthDate) BETWEEN 1950 AND 2015"));

			modelBuilder.Entity<User>()
				.ToTable(q => q.HasCheckConstraint("CK_FirstName_MinValue",
				"LEN([FirstName]) >= 3"));

			modelBuilder.Entity<User>()
				.ToTable(q => q.HasCheckConstraint("CK_LastName_MinValue",
				"LEN([LastName]) >= 3"));

			modelBuilder.Entity<User>()
				.ToTable(q => q.HasCheckConstraint("CK_Username_MinValue",
				"LEN([Username]) >= 5"));

			modelBuilder.Entity<User>()
				.ToTable(q => q.HasCheckConstraint("CK_Password_MinValue",
				"LEN([Password]) >= 6"));


			// Quiz

			modelBuilder.Entity<Quiz>()
				.HasOne(q => q.Category)
				.WithMany(q => q.Quizzes)
				.HasForeignKey(q => q.CategoryId)
				.OnDelete(DeleteBehavior.NoAction)
				.HasConstraintName("FK_Categories");

			modelBuilder.Entity<Quiz>()
				.Property(x => x.Id)
				.ValueGeneratedOnAdd();

			modelBuilder.Entity<Quiz>()
				.Property(q => q.QuizName)
				.IsRequired()
				.HasMaxLength(15);

			modelBuilder.Entity<Quiz>()
				.HasIndex(q => q.QuizName)
				.IsUnique();


			// UserQuiz

			modelBuilder.Entity<UserQuiz>()
				.Property(x => x.Id)
				.ValueGeneratedOnAdd();

			modelBuilder.Entity<UserQuiz>()
				.HasKey(uq => new { uq.UserId, uq.QuizId });

			modelBuilder.Entity<UserQuiz>()
				.HasOne(uq => uq.User)
				.WithMany(uq => uq.UserQuizzes)
				.HasForeignKey(uq => uq.UserId)
				.OnDelete(DeleteBehavior.NoAction)
				.HasConstraintName("FK_Users");

			modelBuilder.Entity<UserQuiz>()
				.HasOne(uq => uq.Quiz)
				.WithMany(uq => uq.UserQuizzes)
				.HasForeignKey(uq => uq.QuizId)
				.OnDelete(DeleteBehavior.NoAction)
				.HasConstraintName("FK_Quizzes_UserQuizzes");

			modelBuilder.Entity<UserQuiz>()
				.Property(uq => uq.Rank)
				.HasDefaultValue(0);

			modelBuilder.Entity<UserQuiz>()
				.Property(uq => uq.CorrectAnswerCount)
				.HasDefaultValue(0);

			modelBuilder.Entity<UserQuiz>()
				.Property(uq => uq.WrongAnswerCount)
				.HasDefaultValue(0);

			modelBuilder.Entity<UserQuiz>()
				.Property(uq => uq.PassedAnswerCount)
				.HasDefaultValue(0);

			modelBuilder.Entity<UserQuiz>()
				.ToTable(uq => uq.HasCheckConstraint("CK_Rank",
				"Rank >= 0"));

			modelBuilder.Entity<UserQuiz>()
				.ToTable(uq => uq.HasCheckConstraint("CK_SuccessRate",
				"SuccessRate BETWEEN 0.0 AND 100.0"));

			modelBuilder.Entity<UserQuiz>()
				.ToTable(uq => uq.HasCheckConstraint("CK_CorrectAnswerCount",
				"CorrectAnswerCount BETWEEN 0 AND 20"));

			modelBuilder.Entity<UserQuiz>()
				.ToTable(uq => uq.HasCheckConstraint("CK_PassedAnswerCount",
				"PassedAnswerCount BETWEEN 0 AND 20"));

			modelBuilder.Entity<UserQuiz>()
				.ToTable(uq => uq.HasCheckConstraint("CK_WrongAnswerCount",
				"WrongAnswerCount BETWEEN 0 AND 20"));

			modelBuilder.Entity<UserQuiz>()
				.ToTable(uq => uq.HasCheckConstraint("CK_Passed_Wrong_Correct",
				"PassedAnswerCount + WrongAnswerCount + CorrectAnswerCount = 20"));


			// Question

			modelBuilder.Entity<Question>()
				.HasDiscriminator<string>("QuestionType")
				.HasValue<FourOptionQuestion>("FourOptionQuestion")
				.HasValue<MultipleChoiceQuestion>("MultipleChoiceQuestion")
				.HasValue<TrueFalseQuestion>("TrueFalseQuestion")
				.HasValue<FillTheGap>("OpenEndedQuestion");

			modelBuilder.Entity<Question>()
				.HasOne(q => q.Quiz)
				.WithMany(q => q.Questions)
				.HasForeignKey(q => q.QuizId)
				.OnDelete(DeleteBehavior.NoAction)
				.HasConstraintName("FK_Quizzes_Questions");

			modelBuilder.Entity<Question>()
				.Property(q => q.Id)
				.ValueGeneratedOnAdd();

			modelBuilder.Entity<Question>()
				.Property(q => q.Statement)
				.IsRequired()
				.HasMaxLength(250);

			modelBuilder.Entity<Question>()
				.HasIndex(q => q.Statement)
				.IsUnique();

			modelBuilder.Entity<Question>()
				.ToTable(q => q.HasCheckConstraint("CK_Statement_MinValue",
				"LEN([Statement]) >= 3"));

			// Option

			modelBuilder.Entity<Option>()
				.HasOne(o => o.Question)
				.WithMany(o => o.OptionsList)
				.HasForeignKey(o => o.QuestionId)
				.OnDelete(DeleteBehavior.Cascade)
				.HasConstraintName("FK_Questions");

			modelBuilder.Entity<Option>()
				.Property(o => o.Id)
				.ValueGeneratedOnAdd();

			modelBuilder.Entity<Option>()
				.Property(o => o.Text)
				.HasMaxLength(50);

			modelBuilder.Entity<Option>()
				.HasIndex(o => new { o.QuestionId, o.Text })
				.IsUnique();

		}
	}
}
