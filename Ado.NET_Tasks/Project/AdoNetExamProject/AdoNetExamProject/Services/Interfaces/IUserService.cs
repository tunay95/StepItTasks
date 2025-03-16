using AdoNetExamProject.Entities;
using AdoNetExamProject.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdoNetExamProject.Services.Interfaces
{
	public interface IUserService : IService<User>
	{
		User Create(string firstName, string lastName, string username, string password, DateTime? birthDate, UserRole? userRole);
		User Update(int id, string? firstName, string? lastName, string? username, string? password, DateTime? birthDate, UserRole? userRole);
		void DeleteById(int id);
		void DeleteAll();
	}
}
