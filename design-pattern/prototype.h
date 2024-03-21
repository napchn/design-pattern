#pragma once

#include <iostream>
#include <string>

class Order {
public:
	virtual std::string GetId() = 0;
	virtual std::string GetName() = 0;
	virtual int GetQuantity() = 0;
	virtual void SetId(const std::string &id) = 0;
	virtual void SetName(const std::string &name) = 0;
	virtual void SetQuantity(const int &quantity) = 0;
	virtual Order* clone() = 0;
	virtual void print() = 0;

protected:
	std::string id;
	std::string name;
	int quantity;
};

class CHNOrder : public Order {
public:
	std::string GetId() { return id; }
	std::string GetName() { return name; }
	int GetQuantity() { return quantity; }
	void SetId(const std::string& paraId) { id = paraId; }
	void SetName(const std::string& paraName) { name = paraName; }
	void SetQuantity(const int& paraQuantity) { quantity = paraQuantity; }
	Order* clone() {
		CHNOrder* order = new CHNOrder;
		order->SetId(GetId());
		order->SetName(GetName());
		order->SetQuantity(GetQuantity());
		return order;
	}
	void print() { std::cout << "[CHN]\t" << GetId() << "\t" << GetName() << "\t" << GetQuantity() << std::endl; };
};

class USOrder : public Order {
public:
	std::string GetId() { return id; }
	std::string GetName() { return name; }
	int GetQuantity() { return quantity; }
	void SetId(const std::string& paraId) { id = paraId; }
	void SetName(const std::string& paraName) { name = paraName; }
	void SetQuantity(const int& paraQuantity) { quantity = paraQuantity; }
	Order* clone() {
		USOrder* order = new USOrder;
		order->SetId(GetId());
		order->SetName(GetName());
		order->SetQuantity(GetQuantity());
		return order;
	}
	void print() { std::cout << "[US]\t" << GetId() << "\t" << GetName() << "\t" << GetQuantity() << std::endl; };
};

class OrderManager {
public:
	void SaveOrder(Order* order) {
		while (order->GetQuantity() > 200)
		{
			// DRY: Don't repeat yourself
			//Order* newOrder = nullptr;
			//if (dynamic_cast<CHNOrder*>(order) != nullptr)
			//{
			//	newOrder = new CHNOrder;
			//	newOrder->SetId(order->GetId());
			//	newOrder->SetName(order->GetName());
			//	newOrder->SetQuantity(200);
			//}
			//if (dynamic_cast<USOrder*>(order) != nullptr)
			//{
			//	newOrder = new USOrder;
			//	newOrder->SetId(order->GetId());
			//	newOrder->SetName(order->GetName());
			//	newOrder->SetQuantity(200);
			//}
			Order* newOrder = order->clone();
			newOrder->SetQuantity(200);
			newOrder->print();
			order->SetQuantity(order->GetQuantity() - 200);
		}
		order->print();
	}
};

