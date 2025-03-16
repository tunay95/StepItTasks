using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdoNetExamProject.Interfaces
{
	public interface IQuestion
	{
		abstract void DisplayQuestion(); 
		abstract bool? CheckAnswer(string userAnswer); 
	}
}
