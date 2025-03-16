using AdoNetExamProject.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdoNetExamProject.Services.Interfaces
{
	public interface IOptionService : IService<Option>
	{
		Option Create(string text, bool? isCorrect, int? questionId);
		Option Update(int id, string? text, bool? isCorrect, int? questionId);
		void DeleteById(int id);
		void DeleteAll();
	}
}
