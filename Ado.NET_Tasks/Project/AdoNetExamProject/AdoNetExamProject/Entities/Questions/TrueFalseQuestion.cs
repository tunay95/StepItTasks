
using AdoNetExamProject.Entities;
using System.ComponentModel.DataAnnotations.Schema;
using System.Reflection.Metadata.Ecma335;

public class TrueFalseQuestion : Question
{
	[NotMapped]
	public override Dictionary<string, Option> OptionsDic { get; set; }

	public override bool? CheckAnswer(string userAnswer) => OptionsDic[userAnswer].IsCorrect;

	public override void DisplayQuestion()
	{
		Console.Write($"{Statement}\n\nA) True       B) False\n\nYour Answer: ");
	}
}
