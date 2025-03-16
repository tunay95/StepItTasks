using AdoNetExamProject.Entities;
using AdoNetExamProject.Repositories.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdoNetExamProject.Repositories.Implements
{
	public class CategoryRepository : IRepository<Category>
	{
		private readonly AppDbContext _dbContext;

		public CategoryRepository(AppDbContext dbContext)
		{
			_dbContext = dbContext;
		}


		public IEnumerable<Category> GetAll() => _dbContext.Categories.Where(c => c != null);


		public Category GetById(int id) => _dbContext.Categories.Find(id);


		public void Add(Category category)
		{
			ArgumentNullException.ThrowIfNull(category, "Category Should not be Null !!");
			_dbContext.Categories.Add(category);
			_dbContext.SaveChanges();
		}


		public void Update(Category category)
		{
			ArgumentNullException.ThrowIfNull(category, "Category should not be Null !!");
			_dbContext.Categories.Update(category);
			_dbContext.SaveChanges();
		}


		public void DeleteById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id, "Id should not be Zero or Negative !!");
			var deletedCategory = _dbContext.Categories.Find(id);
			_dbContext.Remove(deletedCategory);
			_dbContext.SaveChanges();
		}


		public void DeleteAll()
		{
			var deletedCatgories = _dbContext.Categories.ToList();
			_dbContext.Categories.RemoveRange(deletedCatgories);
			_dbContext.SaveChanges();
		}

	}
}
