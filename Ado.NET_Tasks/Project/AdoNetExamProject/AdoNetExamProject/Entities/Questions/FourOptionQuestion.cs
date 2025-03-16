using AdoNetExamProject.Entities;
using AdoNetExamProject.Interfaces;
using System.ComponentModel.DataAnnotations.Schema;

public class FourOptionQuestion : Question, IOptionQuestion
{
	[NotMapped]
	public override Dictionary<string, Option> OptionsDic { get; set; }

	public override bool? CheckAnswer(string userAnswer) => OptionsDic[userAnswer].IsCorrect;


	public override void DisplayQuestion()
	{
		Console.WriteLine($"{Statement}\n");
		foreach (var option in OptionsDic)
		{
			Console.Write($"{option.Key}) {option.Value.Text}\t\t");
		}
	}

	public Dictionary<string, Option> RandomizeOptions()
	{
		Random randomOption = new Random();
		int index;

		for (int i = 0; i < 4; i++)
		{
			index = randomOption.Next(OptionsList.Count);
			OptionsDic.Add(Convert.ToString(65 + i), OptionsList[index]);
			OptionsList.Remove(OptionsList[index]);
		}

		for (int i = 0; i < 4; i++)
		{
			OptionsList[i] = OptionsDic[Convert.ToString(65 + i)];
		}

		return OptionsDic;
	}
}
