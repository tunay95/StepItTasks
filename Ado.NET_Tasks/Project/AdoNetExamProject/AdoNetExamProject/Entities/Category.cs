﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdoNetExamProject.Entities
{
	public class Category
	{
		public int Id { get; set; }
		public string Name { get; set; }
		public List<Quiz>? Quizzes { get; set; } = [];
	}
}
