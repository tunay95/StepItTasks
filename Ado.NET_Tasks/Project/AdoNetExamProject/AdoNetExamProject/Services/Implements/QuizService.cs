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
	public class QuizService : Service<Quiz>
	{
		public QuizService(Repository<Quiz> repository) : base(repository)
		{
		}

		public override IEnumerable<Quiz> GetAll() => _repository.GetAll().ToList();


		public override Quiz GetById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			return _repository.GetById(id);
		}


		public override Quiz Create(params object[] parameters)
		{

			ArgumentNullException.ThrowIfNull(parameters[0] as string, "Text should not be null.");

			Quiz quiz = new()
			{
				QuizName = parameters[0] as string,
				Questions = parameters[1] as List<Question>,
				CategoryId = parameters[2] as int?
			};

			_repository.Add(quiz);

			return quiz;
		}


		public override Quiz Update(params object[] parameters)
		{
			var newQuiz = _repository.GetById((int)parameters[0]);

			if ((string?)parameters[1] is not null) newQuiz.QuizName = (string?)parameters[1];
			if (parameters[2] as int? is not null) newQuiz.CategoryId = parameters[2] as int?;

			_repository.Update(newQuiz);

			return newQuiz;
		}


		public override void DeleteById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			_repository.DeleteById(id);
		}


		public override void DeleteAll() => _repository.DeleteAll();

	}
}
