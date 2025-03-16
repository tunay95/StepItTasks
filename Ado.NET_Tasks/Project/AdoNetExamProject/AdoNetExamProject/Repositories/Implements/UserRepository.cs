using AdoNetExamProject.Entities;
using AdoNetExamProject.Repositories.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdoNetExamProject.Repositories.Implements
{
	public class UserRepository : IRepository<User>
	{
		private readonly AppDbContext _dbContext;

		public UserRepository(AppDbContext appDbContext)
		{
			_dbContext = appDbContext;
		}


		public IEnumerable<User> GetAll() => _dbContext.Users.Where(q => q != null);


		public User GetById(int id) => _dbContext.Users.Find(id);


		public void Add(User user)
		{
			ArgumentNullException.ThrowIfNull(user, "User Should not be Null !!");
			_dbContext.Users.Add(user);
			_dbContext.SaveChanges();
		}


		public void Update(User user)
		{
			ArgumentNullException.ThrowIfNull(user, "User should not be Null");
			_dbContext.Users.Update(user);
			_dbContext.SaveChanges();
		}


		public void DeleteById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id, "Id should not be Zero or Negative !!");
			var deletedUser = _dbContext.Users.Find(id);
			_dbContext.Users.Remove(deletedUser);
			_dbContext.SaveChanges();
		}


		public void DeleteAll()
		{
			var deletedUsers = _dbContext.Users.ToList();
			_dbContext.Users.RemoveRange(deletedUsers);
			_dbContext.SaveChanges();
		}

	}
}
