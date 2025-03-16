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
	public class UserQuizService : IUserQuizService
	{
		private readonly UserQuizRepository _userQuizRepository;

		public UserQuizService(UserQuizRepository userQuizRepository)
		{
			_userQuizRepository = userQuizRepository;
		}


		public IEnumerable<UserQuiz> GetAll() => _userQuizRepository.GetAll().ToList();


		public UserQuiz GetById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			return _userQuizRepository.GetById(id);
		}


		public UserQuiz Create(int userId, int quizId, int rank, double succesRate, int correctAnswerCount, int passedAnswerCount, int wrongAnswerCount)
		{
			ArgumentNullException.ThrowIfNull(userId, "UserId Should not be Null.");
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(userId, "UserId should not be Negative or Zero.");

			ArgumentNullException.ThrowIfNull(userId, "QuizId Should not be Null.");
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(quizId, "QuizId should not be Negative or Zero.");

			if (correctAnswerCount < 0 || correctAnswerCount > 20) throw new ArgumentOutOfRangeException("Correct Answers Count should be between 0 and 20.");
			if (passedAnswerCount < 0 || passedAnswerCount > 20) throw new ArgumentOutOfRangeException("Passed Answers Count should be between 0 and 20.");
			if (wrongAnswerCount < 0 || wrongAnswerCount > 20) throw new ArgumentOutOfRangeException("Wrong Answers Count should be between 0 and 20.");

			UserQuiz userQuiz = new()
			{
				UserId = userId,
				QuizId = quizId,
				Rank = rank,
				SuccessRate = succesRate,
				CorrectAnswerCount = correctAnswerCount,
				PassedAnswerCount = passedAnswerCount,
				WrongAnswerCount = wrongAnswerCount
			};

			_userQuizRepository.Add(userQuiz);

			return userQuiz;
		}


		public UserQuiz Update(int id, int correctAnswerCount, int passedAnswerCount, int wrongAnswerCount, double succesRate, int userId = 0, int quizId = 0, int rank = 0)
		{
			var newUserQuiz = _userQuizRepository.GetById(id);

			if (userId != 0) newUserQuiz.UserId = userId;
			if (quizId != 0) newUserQuiz.QuizId = quizId;
			if (rank != 0) newUserQuiz.Rank = rank;
			newUserQuiz.CorrectAnswerCount = correctAnswerCount;
			newUserQuiz.PassedAnswerCount = passedAnswerCount;
			newUserQuiz.WrongAnswerCount = wrongAnswerCount;
			newUserQuiz.SuccessRate = succesRate;


			_userQuizRepository.Update(newUserQuiz);

			return newUserQuiz;
		}


		public void DeleteById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			_userQuizRepository.DeleteById(id);
		}


		public void DeleteAll() => _userQuizRepository.DeleteAll();

	}
}
