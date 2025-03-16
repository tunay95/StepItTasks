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
	public class UserService : IUserService
	{
		private readonly UserRepository _userRepository;

		public UserService(UserRepository userRepository)
		{
			_userRepository = userRepository;
		}


		public IEnumerable<User> GetAll() => _userRepository.GetAll().ToList();


		public User GetById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			return _userRepository.GetById(id);
		}


		public User Create(string firstName, string lastName, string username, string password, DateTime? birthDate, UserRole? userRole)
		{
			ArgumentNullException.ThrowIfNull(firstName, "FirstName should not be Null.");
			ArgumentNullException.ThrowIfNull(lastName, "LastName should not be Null.");
			ArgumentNullException.ThrowIfNull(username, "Username should not be Null.");
			ArgumentNullException.ThrowIfNull(password, "Password should not be Null.");

			User user = new User()
			{
				FirstName = firstName,
				LastName = lastName,
				Username = username,
				Password = password,
				BirthDate = birthDate,
				UserRole = userRole
			};

			_userRepository.Add(user);

			return user;
		}


		public User Update(int id, string? firstName, string? lastName, string? username, string? password, DateTime? birthDate, UserRole? userRole)
		{

			var newUser = _userRepository.GetById(id);

			ArgumentNullException.ThrowIfNull(newUser, "\nUser not found");
			if (firstName is not null) newUser.FirstName = firstName;
			if (lastName is not null) newUser.LastName = lastName;
			if (username is not null) newUser.Username = username;
			if (password is not null) newUser.Password = password;

			_userRepository.Update(newUser);

			return newUser;
		}


		public void DeleteById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			_userRepository.DeleteById(id);
		}


		public void DeleteAll() => _userRepository.DeleteAll();

	}
}
