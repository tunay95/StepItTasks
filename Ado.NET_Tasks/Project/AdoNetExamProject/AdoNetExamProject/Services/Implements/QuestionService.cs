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
	public class QuestionService : Service<Question>
	{
		public QuestionService(Repository<Question> repository) : base(repository)
		{
		}

		public override IEnumerable<Question> GetAll() => _repository.GetAll().ToList();


		public override Question GetById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			return _repository.GetById(id);
		}


		public override Question Create(params object[] parameters)
		{
			ArgumentNullException.ThrowIfNull(parameters[0] as string, "Statement should not be null.");

			switch (parameters[3])
			{
				case 1:

					FourOptionQuestion fourOptionQuestion = new()
					{
						Statement = parameters[0] as string,
						OptionsList = (List<Option>?)parameters[1],
						QuizId = parameters[2] as int?
					};

					_repository.Add(fourOptionQuestion);

					return fourOptionQuestion;

				case 2:

					MultipleChoiceQuestion multipleChoiceQuestion = new()
					{
						Statement = parameters[0] as string,
						OptionsList = (List<Option>?)parameters[1],
						QuizId = parameters[2] as int?
					};

					_repository.Add(multipleChoiceQuestion);

					return multipleChoiceQuestion;

				case 3:

					TrueFalseQuestion trueFalseQuestion = new()
					{
						Statement = parameters[0] as string,
						OptionsList = (List<Option>?)parameters[1],
						QuizId = parameters[2] as int?
					};

					_repository.Add(trueFalseQuestion);

					return trueFalseQuestion;

				case 4:

					FillTheGap fillTheGap = new()
					{
						Statement = parameters[0] as string,
						OptionsList = (List<Option>?)parameters[1],
						QuizId = parameters[2] as int?
					};

					_repository.Add(fillTheGap);

					return fillTheGap;

				default:

					Console.WriteLine("\nChoose The Correct Choice !!");
					return null;

			}

		}


		public override Question Update(params object[] parameters)
		{
			var newQuestion = _repository.GetById((int)parameters[0]);

			ArgumentNullException.ThrowIfNull(newQuestion, "\nQuestion not found");

			if ((string?)parameters[1] is not null) newQuestion.Statement = (string?)parameters[1];
			if ((List<Option>?)parameters[2] is not null) newQuestion.OptionsList = (List<Option>?)parameters[2];
			if (parameters[3] as int? is not null) newQuestion.QuizId = parameters[2] as int?;

			_repository.Update(newQuestion);

			return newQuestion;
		}


		public override void DeleteById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			_repository.DeleteById(id);
		}


		public override void DeleteAll() => _repository.DeleteAll();

	}
}
