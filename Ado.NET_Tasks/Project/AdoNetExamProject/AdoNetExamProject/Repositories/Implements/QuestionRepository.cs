using AdoNetExamProject.Repositories.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdoNetExamProject.Repositories.Implements
{
	public class QuestionRepository : IRepository<Question>
	{
		private readonly AppDbContext _dbContext;

		public QuestionRepository(AppDbContext appDbContext)
		{
			_dbContext = appDbContext;
		}


		public IEnumerable<Question> GetAll() => _dbContext.Questions.Where(q => q != null);


		public Question GetById(int id) => _dbContext.Questions.Find(id);


		public void Add(Question question)
		{
			ArgumentNullException.ThrowIfNull(question, "Question Should not be Null !!");
			_dbContext.Questions.Add(question);
			_dbContext.SaveChanges();
		}


		public void Update(Question question)
		{
			ArgumentNullException.ThrowIfNull(question, "Question should not be Null");
			_dbContext.Questions.Update(question);
			_dbContext.SaveChanges();
		}


		public void DeleteById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id, "Id should not be Zero or Negative !!");
			var deletedQuestion = _dbContext.Questions.Find(id);
			_dbContext.Questions.Remove(deletedQuestion);
			_dbContext.SaveChanges();
		}


		public void DeleteAll()
		{
			var deletedQuestions = _dbContext.Questions.ToList();
			_dbContext.Questions.RemoveRange(deletedQuestions);
			_dbContext.SaveChanges();
		}

	}
}
