using System;
using System.Diagnostics;
using System.Linq;

while (true)
{
	Process[] processes = Process.GetProcesses();
	int num = 1;

	List<Process> blacklist = new();

	Console.Write(@"1. Get List all Process
2. Start process by Name
3. Kill process by Id
4. Kill processes by Name
5. Add Black list
6. Remove from Black list
7. Exit

Enter Choice: ");

	string choiceStr = Console.ReadLine();
	if (choiceStr == "")
		Console.WriteLine("\n\n Enter Some Choice.\n");

	int choice;
	int.TryParse(choiceStr, out choice);

	Console.Clear();

	switch (choice)
	{
		case 1:

			foreach (Process process in processes)
			{
				if (!blacklist.Contains(process))
				{ Console.WriteLine($"No: {num},	  Process Name: {process.ProcessName.PadLeft(20)},		Process Id: {process.Id},		Process Priority: {process.BasePriority}."); }
				num++;
			}

			break;


		case 2:

			Console.Write("Enter Process Name: ");
			string processInput = Console.ReadLine();

			if (processInput == "")
				Console.WriteLine("\n\nProcess Not Found.\n");


			Console.WriteLine();

			var processByName = Process.Start(processInput);

			if (blacklist.Contains(processByName))
			{
				processByName.Kill();
				Console.WriteLine("THE PROCESS CONTAINS IN BLACKLIST !!!");
			}

			else Console.WriteLine($"Process with Name => {processByName.ProcessName} & Id => {processByName.Id} has started in {processByName.StartTime}.");

			break;


		case 3:

			Console.Write("Enter Process Id: ");

			string processIdInput = Console.ReadLine();
			if (processIdInput == "")
				Console.WriteLine("\n\nProcess Not Found.\n");

			int processById;
			int.TryParse(processIdInput, out processById);

			var processId = Process.GetProcessById(processById);

			if (blacklist.Contains(processId))
			{
				Console.WriteLine("THE PROCESS IS ALREADY BLACKLISTED !!!");
			}

			else
			{
				processId.Kill();
				Console.WriteLine($"Process with Name => {processId.ProcessName} & Id => {processId.Id} has ended in {DateTime.Now}.");
			}

			break;


		case 4:

			Console.Write("Enter Process Name: ");

			string processName = Console.ReadLine();
			if (processName == "")
				Console.WriteLine("\n\nEnter SMTH.\n");

			var processAddName = Process.GetProcessesByName(processName);

			foreach (var process in processAddName)
			{
				if (blacklist.Contains(process))
				{
					Console.WriteLine("THE PROCESS IS ALREADY BLACKLISTED !!!");
				}

				else
				{
					process.Kill();
					Console.WriteLine($"Process with Name => {processName}  has ended in {DateTime.Now}.");
				}
			}

			break;


		case 5:

			Console.Write("Enter Process Name: ");

			string processName2 = Console.ReadLine();
			if (processName2 == "")
				Console.WriteLine("\n\nEnter SMTH.\n");

			var processAddName2 = Process.GetProcessesByName(processName2);

			foreach (var process in processAddName2)
			{
				if (blacklist.Contains(process))
				{
					Console.WriteLine("\n\nTHE PROCESS IS ALREADY BLACKLISTED !!!\n");
				}

				else
				{
					blacklist.Add(process);
                    Console.WriteLine("\n\nSuccessfully BlackListed.\n");
				}
			}

			break;


		case 6:

			Console.Write("Enter Process Name: ");

			string processName3 = Console.ReadLine();
			if (processName3 == "")
				Console.WriteLine("\n\nEnter SMTH.\n");

			var processAddName3 = Process.GetProcessesByName(processName3);

			foreach (var process in processAddName3)
			{
				if (!blacklist.Contains(process))
				{
					Console.WriteLine("\n\nTHE PROCESS WAS NOT BLACKLISTED !!!\n");
				}

				else
				{
					blacklist.Remove(process);
                    Console.WriteLine("\n\nSuccessfully Removed From BlackList.\n");
				}
			}

			break;


		case 7:

			return;


		default:

			Console.WriteLine("\n\nWrong Choice.\n");
			break;
	}

	Thread.Sleep(3000);
	Console.ReadKey();
	Console.Clear();
}














