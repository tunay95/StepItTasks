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
	public class QuestionService : IQuestionService
	{
		private readonly QuestionRepository _questionRepository;

		public QuestionService(QuestionRepository questionRepository)
		{
			_questionRepository = questionRepository;
		}


		public IEnumerable<Question> GetAll() => _questionRepository.GetAll().ToList();


		public Question GetById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			return _questionRepository.GetById(id);
		}


		public Question Create(string statement, List<Option>? options, int? quizId, int choice)
		{
			ArgumentNullException.ThrowIfNull(statement, "Statement should not be null.");

			switch (choice)
			{
				case 1:

					FourOptionQuestion fourOptionQuestion = new()
					{
						Statement = statement,
						OptionsList = options,
						QuizId = quizId
					};

					_questionRepository.Add(fourOptionQuestion);

					return fourOptionQuestion;

				case 2:

					MultipleChoiceQuestion multipleChoiceQuestion = new()
					{
						Statement = statement,
						OptionsList = options,
						QuizId = quizId
					};

					_questionRepository.Add(multipleChoiceQuestion);

					return multipleChoiceQuestion;

				case 3:

					TrueFalseQuestion trueFalseQuestion = new()
					{
						Statement = statement,
						OptionsList = options,
						QuizId = quizId
					};

					_questionRepository.Add(trueFalseQuestion);

					return trueFalseQuestion;

				case 4:

					FillTheGap fillTheGap = new()
					{
						Statement = statement,
						OptionsList = options,
						QuizId = quizId
					};

					_questionRepository.Add(fillTheGap);

					return fillTheGap;

				default:

					Console.WriteLine("\nChoose The Correct Choice !!");
					return null;

			}

		}


		public Question Update(int id, string? statement, int? quizId)
		{
			var newQuestion = _questionRepository.GetById(id);

			ArgumentNullException.ThrowIfNull(newQuestion, "\nQuestion not found");

			if (statement is not null) newQuestion.Statement = statement;
			if (quizId is not null) newQuestion.QuizId = quizId;

			_questionRepository.Update(newQuestion);

			return newQuestion;
		}


		public void DeleteById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			_questionRepository.DeleteById(id);
		}


		public void DeleteAll() => _questionRepository.DeleteAll();

	}
}
