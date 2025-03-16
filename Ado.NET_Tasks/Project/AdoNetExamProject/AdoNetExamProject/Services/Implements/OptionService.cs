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
	public class OptionService : Service<Option>
	{
		public OptionService(Repository<Option> repository) : base(repository)
		{
		}

		public override IEnumerable<Option> GetAll() => _repository.GetAll().ToList();


		public override Option GetById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			return _repository.GetById(id);
		}


		public override Option Create(params object[] parameters)
		{


			ArgumentNullException.ThrowIfNull(parameters[0] as string, "Text should not be null.");

			Option option = new()
			{
				Text = parameters[0] as string,
				IsCorrect = parameters[1] as bool?,
				QuestionId = parameters[2] as int?
			};

			_repository.Add(option);

			return option;
		}


		public override Option Update(params object[] parameters)
		{
			var newOption = _repository.GetById((int)parameters[0]);

			if ((string?)parameters[1] is not null) newOption.Text = (string?)parameters[1];
			if (parameters[2] as bool? is not null) newOption.IsCorrect = parameters[2] as bool?;
			if (parameters[3] as int? is not null) newOption.QuestionId = parameters[3] as int?;

			_repository.Update(newOption);

			return newOption;
		}


		public override void DeleteById(int id)
		{
			ArgumentOutOfRangeException.ThrowIfNegativeOrZero(id);
			_repository.DeleteById(id);
		}


		public override void DeleteAll() => _repository.DeleteAll();

	}

}
