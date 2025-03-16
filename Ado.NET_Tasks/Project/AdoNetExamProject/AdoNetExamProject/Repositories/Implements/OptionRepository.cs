using AdoNetExamProject.Entities;
using AdoNetExamProject.Repositories.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdoNetExamProject.Repositories.Implements
{
	public class OptionRepository : IRepository<Option>
	{
		private readonly AppDbContext _dbContext;

		public OptionRepository(AppDbContext appDbContext)
		{
			_dbContext = appDbContext;
		}

		public IEnumerable<Option> GetAll() => _dbContext.Options.Where(o => o != null);


		public Option GetById(int id) => _dbContext.Options.Find(id);


		public void Add(Option option)
		{
			ArgumentNullException.ThrowIfNull(option, "Option Should not be Null !!");
			_dbContext.Options.Add(option);
			_dbContext.SaveChanges();
		}


		public void Update(Option option)
		{
			ArgumentNullException.ThrowIfNull(option, "Option should not be Null !!");
			_dbContext.Options.Update(option);
			_dbContext.SaveChanges();
		}


		public void DeleteById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id, "Id should not be Zero or Negative !!");
			var deletedOption = _dbContext.Options.Find(id);
			_dbContext.Remove(deletedOption);
			_dbContext.SaveChanges();
		}


		public void DeleteAll()
		{
			var deletedOptions = _dbContext.Options.ToList();
			_dbContext.Options.RemoveRange(deletedOptions);
			_dbContext.SaveChanges();
		}

	}
}
