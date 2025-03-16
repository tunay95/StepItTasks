﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdoNetExamProject.Repositories.Interfaces
{
    public interface IRepository<T> where T : class
    {
		IEnumerable<T> GetAll();
		T GetById(int id);
		void Add(T entity);
		void Update(T entity);
		void DeleteById(int id);
		void DeleteAll();
	}
}
