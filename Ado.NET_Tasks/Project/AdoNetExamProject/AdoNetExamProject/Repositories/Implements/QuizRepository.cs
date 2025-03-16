using AdoNetExamProject.Entities;
using AdoNetExamProject.Interfaces;
using AdoNetExamProject.Repositories.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdoNetExamProject.Repositories.Implements
{
	public class QuizRepository : IRepository<Quiz>
	{
		private readonly AppDbContext _dbContext;

		public QuizRepository(AppDbContext dbContext)
		{
			_dbContext = dbContext;
		}


		public IEnumerable<Quiz> GetAll() => _dbContext.Quizzes.Where(q => q != null);


		public Quiz GetById(int id) => _dbContext.Quizzes.Find(id);


		public void Add(Quiz quiz)
		{
			ArgumentNullException.ThrowIfNull(quiz, "Quiz Should not be Null !!");
			_dbContext.Quizzes.Add(quiz);
			_dbContext.SaveChanges();
		}


		public void Update(Quiz quiz)
		{
			ArgumentNullException.ThrowIfNull(quiz, "Quiz should not be Null");
			_dbContext.Quizzes.Update(quiz);
			_dbContext.SaveChanges();
		}


		public void DeleteById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id, "Id should not be Zero or Negative !!");
			var deletedQuiz = _dbContext.Quizzes.Find(id);
			_dbContext.Quizzes.Remove(deletedQuiz);
			_dbContext.SaveChanges();
		}
		
		
		public void DeleteAll()
		{
			var deletedQuizzes = _dbContext.Quizzes.ToList();
			_dbContext.Quizzes.RemoveRange(deletedQuizzes);
			_dbContext.SaveChanges();
		}

	}
}
