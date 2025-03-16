using AdoNetExamProject.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdoNetExamProject.Services.Interfaces
{
	public interface IQuizService : IService<Quiz>
	{
		Quiz Create(string quizName, List<Question>? questions, int? categoryId);
		Quiz Update(int id, string? quizName, int? categoryId);
		void DeleteById(int id);
		void DeleteAll();
	}
}
