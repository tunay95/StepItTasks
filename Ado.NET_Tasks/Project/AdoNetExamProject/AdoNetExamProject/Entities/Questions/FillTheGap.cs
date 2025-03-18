
using AdoNetExamProject.Entities;

public class FillTheGap : Question
{
	public override bool CheckAnswer(string userAnswer) => OptionsList[0].Text == userAnswer;

	public override void DisplayQuestion()
	{
		Console.Write($"{Statement}\n\nYour Answer: ");
	}
}
