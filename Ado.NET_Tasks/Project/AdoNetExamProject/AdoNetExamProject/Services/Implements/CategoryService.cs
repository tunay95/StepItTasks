using AdoNetExamProject.Entities;
using AdoNetExamProject.Repositories.Implements;
using AdoNetExamProject.Services.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AdoNetExamProject.Services.Implements
{
	public class CategoryService : Service<Category>
	{
		public CategoryService(Repository<Category> repository) : base(repository)
		{
		}

		public override IEnumerable<Category> GetAll() => _repository.GetAll().ToList();


		public override Category GetById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			return _repository.GetById(id);
		}


		public override Category Create(params object[] parameters)
		{
			ArgumentNullException.ThrowIfNull(parameters[0] as string, "Category Name should not be null.");

			Category category = new()
			{
				Name = parameters[0] as string,
			};

			_repository.Add(category);

			return category;
		}


		public override Category Update(params object[] parameters)
		{
			var newCategory = _repository.GetById((int)parameters[0]);

			ArgumentNullException.ThrowIfNull(newCategory, "\nCategory not found");

			if (parameters[1] as string is not null) newCategory.Name = parameters[1] as string;
			if ((List<Quiz>?)parameters[2] is not null) newCategory.Quizzes = (List<Quiz>?)parameters[2];

			_repository.Update(newCategory);

			return newCategory;
		}


		public override void DeleteById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			_repository.DeleteById(id);
		}


		public override void DeleteAll() => _repository.DeleteAll();

	}
}
