using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdoNetExamProject.Entities
{
	public class UserQuiz
	{
        public int Id;
        public int UserId { get; set; }
        public int QuizId { get; set; }
        public Quiz Quiz { get; set; }
        public User User { get; set; }
        public int Rank { get; set; }
        public double SuccessRate { get; set; }
        public int CorrectAnswerCount { get; set; }
        public int PassedAnswerCount { get; set; }
        public int WrongAnswerCount { get; set; }
    }
}
