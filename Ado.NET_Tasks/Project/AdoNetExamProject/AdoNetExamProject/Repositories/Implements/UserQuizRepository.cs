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
	public class UserQuizRepository : IRepository<UserQuiz>
	{
		private readonly AppDbContext _dbContext;

		public UserQuizRepository(AppDbContext dbContext)
		{
			_dbContext = dbContext;
		}


		public IEnumerable<UserQuiz> GetAll() => _dbContext.UserQuizzes.Where(q => q != null);


		public UserQuiz GetById(int id) => _dbContext.UserQuizzes.Find(id);


		public void Add(UserQuiz userQuiz)
		{
			ArgumentNullException.ThrowIfNull(userQuiz, "UserQuiz Should not be Null !!");
			_dbContext.UserQuizzes.Add(userQuiz);
			_dbContext.SaveChanges();
		}


		public void Update(UserQuiz userQuiz)
		{
			ArgumentNullException.ThrowIfNull(userQuiz, "UserResult should not be Null");
			_dbContext.UserQuizzes.Update(userQuiz);
			_dbContext.SaveChanges();
		}


		public void DeleteById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id, "Id should not be Zero or Negative !!");
			var deletedUserQuiz = _dbContext.UserQuizzes.Find(id);
			_dbContext.UserQuizzes.Remove(deletedUserQuiz);
			_dbContext.SaveChanges();
		}
		
		
		public void DeleteAll()
		{
			var deletedUserQuizzes = _dbContext.UserQuizzes.ToList();
			_dbContext.UserQuizzes.RemoveRange(deletedUserQuizzes);
			_dbContext.SaveChanges();
		}

	}
}
