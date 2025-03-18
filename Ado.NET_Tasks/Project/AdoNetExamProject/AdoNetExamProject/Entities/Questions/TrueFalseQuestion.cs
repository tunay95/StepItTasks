
using AdoNetExamProject.Entities;
using AdoNetExamProject.Interfaces;
using System.ComponentModel.DataAnnotations.Schema;
using System.Reflection.Metadata.Ecma335;

public class TrueFalseQuestion : Question, IOptionQuestion
{
	[NotMapped]
	public override Dictionary<string, Option> OptionsDic { get; set; } = new Dictionary<string, Option>();

	public override bool CheckAnswer(string userAnswer) => (bool)OptionsDic[userAnswer.ToUpper()].IsCorrect;

	public override void DisplayQuestion()
	{
		Console.Write($"{Statement}\n");

		OptionsDic = RandomizeOptions();

		foreach (var option in OptionsDic)
		{
			Console.Write($"{option.Key}) {option.Value.Text}\t\t");
		}

		Console.Write("\n\nYour Answer: ");
	}

	public Dictionary<string, Option> RandomizeOptions()
	{
		Random randomOption = new Random();
		int index;

		for (int i = 0; OptionsList.Count > 0; i++)
		{
			index = randomOption.Next(OptionsList.Count);
			OptionsDic.Add(Convert.ToChar(65 + i).ToString(), OptionsList[index]);
			OptionsList.Remove(OptionsList[index]);
		}

		for (int i = 0; OptionsList.Count < 2; i++)
		{
			OptionsList.Add(OptionsDic[Convert.ToChar(65 + i).ToString()]);
		}

		return OptionsDic;
	}
}
