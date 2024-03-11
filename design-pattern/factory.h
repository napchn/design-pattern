#pragma once

#include <map>
#include <string>
#include <functional>
#include <iostream>

template <class T>
class IoCCtroller {
public:
	IoCCtroller() = default;

	~IoCCtroller() = default;

	template<class Drived>
	void RegisterType(std::string key) {
		std::function<T* ()> function = [] { return new Drived(); };
		RegisterType(key, function);
	}

	T* Resolve(std::string key) {
		if (!funcMap.contains(key)) {
			return nullptr;
		}
		return funcMap[key]();
	}

	std::shared_ptr<T> ResolveShared(std::string key) {
		return std::shared_ptr<T>(Resolve(key));
	}

private:
	std::map<std::string, std::function<T* ()>> funcMap;

	void RegisterType(std::string key, std::function<T* ()> function) {
		if (funcMap.contains(key)) {
			throw std::invalid_argument("this key already exist!");
		}
		funcMap.emplace(key, function);
	}
};

class Transport {
public:
	virtual void info() const = 0;
};

class Airport : public Transport {
public:
	void info() const {
		std::cout << "This is airport way" << std::endl;
	}
};

class Car : public Transport {
public:
	void info() const {
		std::cout << "This is car way" << std::endl;
	}
};

