using AdoNetExamProject.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdoNetExamProject.Services.Interfaces
{
	public interface IUserQuizService : IService<UserQuiz>
	{
		UserQuiz Create(int userId, int quizId, int rank, double succesRate, int correctAnswerCount, int passedAnswerCount, int wrongAnswerCount);
		UserQuiz Update(int id, int correctAnswerCount, int passedAnswerCount, int wrongAnswerCount, double succesRate, int userId, int quizId, int rank);
		void DeleteById(int id);
		void DeleteAll();
	}
}
