using AdoNetExamProject.Entities;
using AdoNetExamProject.Repositories.Implements;
using AdoNetExamProject.Services.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdoNetExamProject.Services.Implements
{
	public class UserService : Service<User>
	{
		public UserService(Repository<User> repository) : base(repository)
		{
		}

		public override IEnumerable<User> GetAll() => _repository.GetAll().ToList();


		public override User GetById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			return _repository.GetById(id);
		}


		public override User Create(params object[] parameters)
		{
			ArgumentNullException.ThrowIfNull(parameters[0] as string, "FirstName should not be Null.");
			ArgumentNullException.ThrowIfNull(parameters[1] as string, "LastName should not be Null.");
			ArgumentNullException.ThrowIfNull(parameters[2] as string, "Username should not be Null.");
			ArgumentNullException.ThrowIfNull(parameters[3] as string, "Password should not be Null.");

			User user = new User()
			{
				FirstName = parameters[0] as string,
				LastName = parameters[1] as string,
				Username = parameters[2] as string,
				Password = parameters[3] as string,
				BirthDate = parameters[4] as DateTime?,
				UserRole = parameters[5] as UserRole?
			};

			_repository.Add(user);

			return user;
		}


		public override User Update(params object[] parameters)
		{

			var newUser = _repository.GetById((int)parameters[0]);

			ArgumentNullException.ThrowIfNull(newUser, "\nUser not found");
			if ((string?)parameters[1] is not null) newUser.FirstName = (string?)parameters[1];
			if ((string?)parameters[2] is not null) newUser.LastName = (string?)parameters[2];
			if ((string?)parameters[3] is not null) newUser.Username = (string?)parameters[3];
			if ((string?)parameters[4] is not null) newUser.Password = (string?)parameters[4];

			_repository.Update(newUser);

			return newUser;
		}


		public override void DeleteById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			_repository.DeleteById(id);
		}


		public override void DeleteAll() => _repository.DeleteAll();


		public  bool Login(string username, string password, UserRole? userRole = UserRole.User) => _repository.GetAll().Any(u => u.Username == username && u.Password == password && u.UserRole == userRole);

	}
}
