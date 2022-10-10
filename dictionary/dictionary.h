#ifndef DRWEB_ENTRY_TASK_DICTIONARY_H_INCLUDED
#define DRWEB_ENTRY_TASK_DICTIONARY_H_INCLUDED

#include <map>

namespace containers {
//=================== interface =====================

template<class Key, class Value>
class dictionary
{
public:
    virtual ~dictionary() = default;

    virtual const Value& get(const Key& key) const = 0;
    virtual void set(const Key& key, const Value& value) = 0;
    virtual bool is_set(const Key& key) const = 0;
};

template<class Key>
class not_found_exception : public std::exception
{
public:
    virtual const Key& get_key() const noexcept = 0;
};

//=================== implementation =====================

template<class Key, class Value>
class cust_dictionary : public dictionary<Key, Value>
{
public:
    cust_dictionary() : _dict{ }
    {
        //empty
    }

    ~cust_dictionary()
    {
        //empty
    }

public:
    const Value& get(const Key& key) const override
    {
        if (auto it = _dict.find(key); it != _dict.end()) {
            return it->second;
        }
        throw cust_not_found_exception<Key>(key); 
    }

    void set(const Key& key, const Value& value) override
    {
        _dict[key] = value;
    }

    bool is_set(const Key& key) const override
    {
        return _dict.find(key) != _dict.end();
    }

private:
    std::map<Key, Value> _dict;
};

template<class Key>
class cust_not_found_exception : public not_found_exception<Key>
{
public:
    cust_not_found_exception(const Key& key) : _key{ key }
    {
        //empty
    }

    ~cust_not_found_exception()
    {
        //empty
    }

public:
    const Key& get_key() const noexcept override
    {
        return _key;
    }

private:
    Key _key;
};

}

#endif
