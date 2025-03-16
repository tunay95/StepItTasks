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
	public class CategoryService : ICategoryService
	{
		private readonly CategoryRepository _categoryRepository;

		public CategoryService(CategoryRepository categoryRepository)
		{
			_categoryRepository = categoryRepository;
		}


		public IEnumerable<Category> GetAll() => _categoryRepository.GetAll().ToList();


		public Category GetById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			return _categoryRepository.GetById(id);
		}


		public Category Create(string name, List<Quiz>? quizzes)
		{
			ArgumentNullException.ThrowIfNull(name, "Category Name should not be null.");

			Category category = new()
			{
				Name = name,
				Quizzes = quizzes
			};

			_categoryRepository.Add(category);

			return category;
		}


		public Category Update(int id, string? name, List<Quiz>? quizzes)
		{
			var newCategory = _categoryRepository.GetById(id);

			ArgumentNullException.ThrowIfNull(newCategory, "\nCategory not found");

			if (name is not null) newCategory.Name = name;
			if (quizzes is not null) newCategory.Quizzes = quizzes;

			_categoryRepository.Update(newCategory);

			return newCategory;
		}


		public void DeleteById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			_categoryRepository.DeleteById(id);
		}


		public void DeleteAll() => _categoryRepository.DeleteAll();

	}
}
