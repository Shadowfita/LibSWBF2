#pragma once

namespace LibSWBF2::Types
{
	template<class T> 
	class LIBSWBF2_EXP List
	{
	private:
		const static int LIST_DEFAULT_INIT_SIZE = 8;

		T* ArrayPtr = nullptr;
		size_t NumElements = 0;
		size_t MaxElements = 0;

		void Init(size_t ReservedSize);
		void CopyFrom(const List<T>& other);

	public:
		List(size_t ReservedSize);
		List() : List(LIST_DEFAULT_INIT_SIZE) {}
		List(const List<T>& other);
		List(List<T>&& other);
		~List();

		size_t Size() const;
		void Resize(size_t NewMaxSize);
		void Add(const T& Element);
		T& Emplace();

		List<T>& operator=(const List<T>& other);

		const T& operator[](const size_t i) const;
		const T& operator[](const int i) const;
		const T& operator[](const long i) const;
		const T& operator[](const unsigned int i) const;
		const T& operator[](const unsigned long i) const;
		T& operator[](const size_t i);
		T& operator[](const int i);
		T& operator[](const long i);
		T& operator[](const unsigned int i);
		T& operator[](const unsigned long i);


		// TODO: Remove methods

		void Clear();
		T* GetArrayPtr() const;
	};
}