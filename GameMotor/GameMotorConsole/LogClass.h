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


		class cString
		{
		private:

			bool isNull = true;
			std::string Value = "";

		public:

			cString()
			{
				isNull = true;
			}

			cString(std::string value)
			{
				Value = value;
				isNull = false;
			}

			void Set(std::string value)
			{
				Value = value;
				isNull = false;
			}

			std::string Get()const
			{
				return Value;
			}

			bool operator == (std::string other)
			{
				if (isNull)
				{
					return false;
				}
				return Value == other;
			}

			bool operator == (cString other)
			{
				if (other.isNull && isNull)
				{
					return true;
				}
				else {
					if (other.isNull || isNull)
					{
						return false;
					}
					else
					{
						return other.Value == Value;
					}
				}
			}
		};
	}
}

