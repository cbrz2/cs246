#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

namespace dsn
{
	class Object
	{
		virtual std::string toString() const = 0;

		friend std::ostream& operator<<(std::ostream& out,const Object& obj)
		{
			return out << obj.toString();
		}
	};

	template<class T>
	class Array : public Object
	{
		private:
		std::vector<T> content;

		public:
		Array() 
		{
			content = std::vector<T>(20,T());
		}

		Array(size_t sz) 
		{
			content = std::vector<T>(sz,T());
		}

		Array(const Array<T>& obj)
		{
			content = obj.content;
		}

		Array<T>& operator=(const Array<T>& rhs)
		{
			if(this != &rhs)
			{
				content = rhs.content;
			}
			return *this;
		}

		~Array() {}

		const T& operator[](size_t idx) const 
		{
			return content[idx];
		}

		T& operator[](size_t idx) 
		{
			return content[idx];
		}

		size_t size() const {return content.size();}

		std::string toString() const override 
		{
			std::ostringstream out;

			out << "[";

			for(size_t i = 0;i < content.size();i += 1)
			{
				out << content[i];

				if(i + 1 < content.size())
				{
					out << ",";
				}
			}
			out << "]";
			return out.str();
		}
	};

}
#endif
