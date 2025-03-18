using AdoNetExamProject.Entities;
using AdoNetExamProject.Interfaces;
using System.ComponentModel.DataAnnotations.Schema;

public abstract class Question :IQuestion
{
	public int Id { get; set; }
	public string Statement { get; set; }
	public List<Option>? OptionsList { get; set; } = [];

	[NotMapped]
	public virtual Dictionary<string, Option> OptionsDic { get; set; } = new Dictionary<string, Option>();
	public int? QuizId { get; set; }
	public Quiz Quiz { get; set; }

	public abstract bool CheckAnswer(string userAnswer);
	public abstract void DisplayQuestion();
}
