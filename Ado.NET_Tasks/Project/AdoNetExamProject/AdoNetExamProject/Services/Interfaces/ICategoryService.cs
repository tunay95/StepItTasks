using AdoNetExamProject.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdoNetExamProject.Services.Interfaces
{
	public interface ICategoryService:IService<Category>
	{
		Category Create(string name,List<Quiz>? quizzes);
		Category Update(int id, string? name, List<Quiz>? quizzes);
		void DeleteById(int id);
		void DeleteAll();
	}

}
