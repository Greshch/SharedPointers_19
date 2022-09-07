#pragma once

#include <iostream>
#include <vector>

template<typename T>
struct Pair {
	T adress;
	int links = 0;
};

template<typename T>
class SharedPtr {
public:

	SharedPtr() = default;

	SharedPtr(T* t) :
		m_ptr(t)
	{
		Add(t);
	}

	SharedPtr(SharedPtr const& other) :
		m_ptr(other.m_ptr)
	{
		int id = GetId(other.m_ptr);
		IncrLinkById(id);
	}

	SharedPtr& operator= (SharedPtr const& other) {
		if (this != &other) {
			int old_id = GetId(m_ptr);
			delete m_ptr;
			CleanById(old_id);
			
			m_ptr = other.m_ptr;
			int new_id = GetId(other.m_ptr);
			IncrLinkById(new_id);
		}
		return *this;
	}

	T* Get() {
		if (m_ptr == nullptr) {
			throw std::runtime_error("It wasn't initialaized");
		}
		return m_ptr;
	}

	T& operator *() {
		return *Get();
	}

	T* operator->() {
		return Get();
	}

	~SharedPtr() {
		int id = GetId(m_ptr);
		DecLinkById(id);
		int links = buffer[id].links;
		if (links == 0) {
			std::cout << "Destr-r completed\t" << *m_ptr << "\n";
			delete m_ptr;
			m_ptr = nullptr;
			CleanById(id);
		}
	}

private:
	T* m_ptr = nullptr;
	static std::vector<Pair<T*>> buffer;

	static const int notFounded = -1;

	static int GetId(T* pT) {
		for (size_t i = 0; i < buffer.size(); i++) {
			if (buffer[i].adress == pT) {
				return i;
			}
		}
		return notFounded;
	}

	static void Add(T* pT) {
		buffer.push_back({pT, 1});
	}

	static void IncrLinkById(int id) {
		buffer[id].links++;
	}

	static void DecLinkById(int id) {
		buffer[id].links--;
	}

	static void CleanById(int id) {
		buffer.erase(buffer.begin() + id);
	}
};

template<typename T>
std::vector<Pair<T*>> SharedPtr<T>::buffer {};