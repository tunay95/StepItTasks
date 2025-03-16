using AdoNetExamProject.Entities;
using AdoNetExamProject.Repositories.Interfaces;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdoNetExamProject.Repositories.Implements
{
	public class Repository<T> : IRepository<T> where T : class
	{
		private readonly AppDbContext _dbContext;
		private readonly DbSet<T> _dbSet;

		public Repository(AppDbContext dbContext)
		{
			_dbContext = dbContext;
			_dbSet = _dbContext.Set<T>();
		}


		public IEnumerable<T> GetAll() => _dbSet.Where(q => q != null);


		public T GetById(int id) => _dbSet.Find(id);


		public void Add(T entity)
		{
			ArgumentNullException.ThrowIfNull(entity, "Quiz Should not be Null !!");
			_dbSet.Add(entity);
			_dbContext.SaveChanges();
		}


		public void Update(T entity)
		{
			ArgumentNullException.ThrowIfNull(entity, "Quiz should not be Null");
			_dbSet.Update(entity);
			_dbContext.SaveChanges();
		}


		public void DeleteById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id, "Id should not be Zero or Negative !!");
			var deletedQuiz = _dbSet.Find(id);
			_dbSet.Remove(deletedQuiz);
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
