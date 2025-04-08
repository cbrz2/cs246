#ifndef NODE_H
#define NODE_H

namespace dsp
{
	template <class T>
	class Node 
	{
		public:
		T data;
		Node<T>* prev;
		Node<T>* next;
		
		Node() : data(T()), prev(nullptr), next(nullptr) {}
		Node(const T& dt) : data(dt), prev(nullptr), next(nullptr) {}
	
		friend Node<T>* Clone(Node<T>* rt)
		{
			if(rt == nullptr)
			{
				return nullptr;
			}
			Node<T> * cp = new Node<T>(rt->data);
			Node<T> * tr = rt;
			Node<T> * tc = cp;

			while(tr->next != nullptr)
			{
				tc->next = new Node<T>(tr->next->data);
				tc->next->prev = tc;
				tc = tc->next;
				tr = tr->next;
			}
			return cp;
		}

		friend void Erase(Node<T>*& rt)
		{
			Node<T>* t;

			while(rt != nullptr)
			{
				t = rt;
				rt = rt->next;
				delete t;
				t = nullptr;
			}
		}
	};
}

#endif
