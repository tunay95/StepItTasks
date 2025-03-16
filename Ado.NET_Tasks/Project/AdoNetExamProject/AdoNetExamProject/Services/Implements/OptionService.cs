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
	public class OptionService : IOptionService
	{
		private readonly OptionRepository _optionRepository;

		public OptionService(OptionRepository optionRepository)
		{
			_optionRepository = optionRepository;
		}


		public IEnumerable<Option> GetAll() => _optionRepository.GetAll().ToList();


		public Option GetById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			return _optionRepository.GetById(id);
		}


		public Option Create(string text, bool? isCorrect, int? questionId)
		{
			ArgumentNullException.ThrowIfNullOrEmpty(text, "Text should not be null.");

			Option option = new()
			{
				Text = text,
				IsCorrect = isCorrect,
				QuestionId = questionId
			};

			_optionRepository.Add(option);

			return option;
		}


		public Option Update(int id, string? text, bool? isCorrect, int? questionId)
		{
			var newOption = _optionRepository.GetById(id);

			if (text is not null) newOption.Text = text;
			if (isCorrect is not null) newOption.IsCorrect = isCorrect;
			if (questionId is not null) newOption.QuestionId = questionId;

			_optionRepository.Update(newOption);

			return newOption;
		}


		public void DeleteById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			_optionRepository.DeleteById(id);
		}


		public void DeleteAll() => _optionRepository.DeleteAll();

	}

}
