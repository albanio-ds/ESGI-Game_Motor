#pragma once
#include <string>
#include <iostream>

namespace Core
{
	namespace Utilities
	{
		static class LogClass
		{
		public:
			static void Print(std::string msg)
			{
				std::cout << msg << std::endl;
			}

			static void PrintError(std::string msg)
			{
				std::cout << "-----ERROR-----" << std::endl;
				std::cout << msg << std::endl;
				std::cout << "---------------" << std::endl;
			}
		};
	}
}

