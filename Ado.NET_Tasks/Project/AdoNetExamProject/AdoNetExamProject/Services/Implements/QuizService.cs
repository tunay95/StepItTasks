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
	public class QuizService : IQuizService
	{
		private readonly QuizRepository _quizRepository;

		public QuizService(QuizRepository quizRepository)
		{
			_quizRepository = quizRepository;
		}


		public IEnumerable<Quiz> GetAll() => _quizRepository.GetAll().ToList();


		public Quiz GetById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			return _quizRepository.GetById(id);
		}


		public Quiz Create(string quizName, List<Question>? questions, int? categoryId)
		{
			ArgumentNullException.ThrowIfNull
				
				(quizName, "Text should not be null.");

			Quiz quiz = new()
			{
				QuizName = quizName,
				Questions = questions,
				CategoryId = categoryId
			};

			_quizRepository.Add(quiz);

			return quiz;
		}


		public Quiz Update(int id, string? quizName, int? categoryId)
		{
			var newQuiz = _quizRepository.GetById(id);

			if (quizName is not null) newQuiz.QuizName = quizName;
			if (categoryId is not null) newQuiz.CategoryId = categoryId;

			_quizRepository.Update(newQuiz);

			return newQuiz;
		}


		public void DeleteById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			_quizRepository.DeleteById(id);
		}


		public void DeleteAll() => _quizRepository.DeleteAll();

	}
}
