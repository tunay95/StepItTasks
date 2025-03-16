using AdoNetExamProject.Entities;
using AdoNetExamProject.Interfaces;
using System.ComponentModel.DataAnnotations.Schema;


public class MultipleChoiceQuestion : Question, IOptionQuestion
{
	[NotMapped]
	public override Dictionary<string, Option> OptionsDic { get; set; }

	public override bool? CheckAnswer(string userAnswer)
	{
		string[] userMultipleAnswer = userAnswer.Split(',', ' ', '.');
		int length = 0;

		foreach (var option in OptionsList)
		{
			if ((bool)option.IsCorrect) length++;
		}

		if (userMultipleAnswer.Length != length) return false;

		int correctAnswersCount = 0;

		for (int i = 0; i < length; i++)
		{
			userMultipleAnswer[i] = userMultipleAnswer[i].Trim();

			if ((bool)OptionsDic[Convert.ToString(userMultipleAnswer[i])].IsCorrect)
			{
				correctAnswersCount++;
			}

		}

		if (correctAnswersCount == length)  return true;

		return false;
	}

	public override void DisplayQuestion()
	{
		Console.WriteLine($"{Statement}\n");
		foreach (var option in OptionsDic)
		{
			Console.Write($"{option.Key}. {option.Value.Text}\t");
		}
	}

	public Dictionary<string, Option> RandomizeOptions()
	{
		Random randomOption = new Random();
		int index;

		for (int i = 0; i < OptionsList.Count; i++)
		{
			index = randomOption.Next(OptionsList.Count);
			OptionsDic.Add(Convert.ToString(1 + i), OptionsList[index]);
		}

		for (int j = 0; j < OptionsList.Count; j++)
		{
			OptionsList[j] = OptionsDic[Convert.ToString(1+j)];
		}

		return OptionsDic;
	}
}
