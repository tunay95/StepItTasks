using AdoNetExamProject.Repositories.Implements;
using AdoNetExamProject.Services.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata.Ecma335;
using System.Text;
using System.Threading.Tasks;

namespace AdoNetExamProject.Services.Implements
{
	public class Service<T> : IService<T> where T : class
	{
		protected readonly Repository<T> _repository;

		public Service(Repository<T> repository)
		{
			_repository = repository;
		}


		public virtual T Create(params object[] parameters)
		{
			T t = null;
			return t;
		}


		public virtual void DeleteAll()
		{ }


		public virtual void DeleteById(int id)
		{ }


		public virtual IEnumerable<T> GetAll()
		{
			IEnumerable<T> t = null;
			return t;
		}


		public virtual T GetById(int id)
		{
			T t = null;
			return t;
		}


		public virtual T Update(params object[] parameters)
		{
			T t = null;
			return t;
		}

	}

}
