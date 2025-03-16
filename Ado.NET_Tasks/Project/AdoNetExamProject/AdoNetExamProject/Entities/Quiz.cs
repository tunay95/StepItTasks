namespace AdoNetExamProject.Entities;

public class Quiz
{
	public int Id { get; set; }
	public string QuizName { get; set; }
	public List<Question>? Questions { get; set; }
	public List<UserQuiz> UserQuizzes { get; set; } = [];
    public int? CategoryId { get; set; }
    public Category Category { get; set; }

}
