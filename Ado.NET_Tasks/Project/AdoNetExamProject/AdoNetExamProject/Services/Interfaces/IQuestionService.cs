using AdoNetExamProject.Entities;
using AdoNetExamProject.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdoNetExamProject.Services.Interfaces
{
	public interface IQuestionService : IService<Question>
	{
		Question Create(string statement, List<Option>? options, int? quizId, int choice);
		Question Update(int id, string? statement, int? quizId);
		void DeleteById(int id);
		void DeleteAll();
	}
}
