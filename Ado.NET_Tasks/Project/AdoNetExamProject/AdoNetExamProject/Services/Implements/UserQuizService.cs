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
	public class UserQuizService : Service<UserQuiz>
	{
		public UserQuizService(Repository<UserQuiz> repository) : base(repository)
		{
		}

		public override IEnumerable<UserQuiz> GetAll() => _repository.GetAll().ToList();


		public override UserQuiz GetById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			return _repository.GetById(id);
		}


		public override UserQuiz Create(params object[] parameters)
		{
			ArgumentNullException.ThrowIfNull((int)parameters[0], "UserId Should not be Null.");
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero((int)parameters[0], "UserId should not be Negative or Zero.");

			ArgumentNullException.ThrowIfNull((int)parameters[1], "QuizId Should not be Null.");
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero((int)parameters[1], "QuizId should not be Negative or Zero.");

			if ((int)parameters[4] < 0 || (int)parameters[4] > 20) throw new ArgumentOutOfRangeException("Correct Answers Count should be between 0 and 20.");
			if ((int)parameters[5] < 0 || (int)parameters[5] > 20) throw new ArgumentOutOfRangeException("Passed Answers Count should be between 0 and 20.");
			if ((int)parameters[6] < 0 || (int)parameters[6] > 20) throw new ArgumentOutOfRangeException("Wrong Answers Count should be between 0 and 20.");

			UserQuiz userQuiz = new()
			{
				UserId = (int)parameters[0],
				QuizId = (int)parameters[1],
				Rank = (int)parameters[2],
				SuccessRate = (double)parameters[3],
				CorrectAnswerCount = (int)parameters[4],
				PassedAnswerCount = (int)parameters[5],
				WrongAnswerCount = (int)parameters[6]
			};

			_repository.Add(userQuiz);

			return userQuiz;
		}


		public override UserQuiz Update(params object[] parameters)
		{
			var newUserQuiz = _repository.GetById((int)parameters[0]);

			if ((int)parameters[5] != 0) newUserQuiz.UserId = (int)parameters[5];
			if ((int)parameters[6] != 0) newUserQuiz.QuizId = (int)parameters[6];
			if ((int)parameters[7] != 0) newUserQuiz.Rank = (int)parameters[7];
			newUserQuiz.CorrectAnswerCount = (int)parameters[1];
			newUserQuiz.PassedAnswerCount = (int)parameters[2];
			newUserQuiz.WrongAnswerCount = (int)parameters[3];
			newUserQuiz.SuccessRate = (double)parameters[4];


			_repository.Update(newUserQuiz);

			return newUserQuiz;
		}


		public override void DeleteById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			_repository.DeleteById(id);
		}


		public override void DeleteAll() => _repository.DeleteAll();

	}
}
