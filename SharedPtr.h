#pragma once

template<class T>
class SharedPtr
{
public:
    SharedPtr(T* ptr) :
        m_ptr(ptr),
        m_links(new int{1})
    {}

    SharedPtr(SharedPtr const& obj)
    {
        Update(obj);
    }

    SharedPtr& operator= (SharedPtr const& obj)
    {
        CleanUp();
        Update(obj);
        return *this;
    }

    void Update(const SharedPtr &obj) {
        m_ptr = obj.m_ptr;
        m_links = obj.m_links;
        ++(*obj.m_links);
    }

    T* Get() const
    {
        return m_ptr;
    }

    T* operator->()
    {
        return Get();
    }

    T& operator*()
    {
        return *Get();
    }

    operator bool ()
    {
        return  m_ptr != nullptr;
    }

    ~SharedPtr()
    {
        CleanUp();
    }

private:
    void CleanUp()
    {
        --(*m_links);
        if (*m_links == 0)
        {
            Free();
        }
    }

    void Free()
    {
        delete m_ptr;
        m_ptr = nullptr;

        delete m_links;
        m_links = nullptr;
    }

private:
    T* m_ptr = nullptr;
    int* m_links = nullptr;
};