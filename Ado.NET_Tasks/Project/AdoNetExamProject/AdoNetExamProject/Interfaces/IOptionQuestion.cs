using AdoNetExamProject.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdoNetExamProject.Interfaces
{
	public interface IOptionQuestion : IQuestion
	{
		abstract Dictionary<string,Option> RandomizeOptions(); 
    }
}
