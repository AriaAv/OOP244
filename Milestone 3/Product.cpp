// Aria Avazkhani
//2018-07-31

#include "Product.h"

namespace AMA {

	Product::Product(char type) {
		v_type = type;
		v_sku[0] = '\0';
		v_unit[0] = '\0';
		v_name = nullptr;
		v_qty = 0;
		v_need = 0;
		v_price = 0.0;
		v_status = false;
	}

	Product::Product(const char* sku, const char* n, const char* unit, int qty, bool status, double price, int need) {
		name(n);
		strncpy(v_sku, sku, max_sku_length);
		v_sku[max_sku_length] = '\0';
		strncpy(v_unit, unit, max_unit_length);
		v_unit[max_unit_length] = '\0';

		v_qty = qty;
		v_need = need;
		v_price = price;
		v_status = status;
	}

	Product::~Product() {
		delete[] v_name;
	}

	Product::Product(const Product& src) {
		
		int length = strlen(src.v_name);
		v_type = src.v_type;
		strncpy(v_sku, src.v_sku, max_sku_length);
		v_sku[max_sku_length] = '\0';
		strncpy(v_unit, src.v_unit, max_unit_length);
		v_unit[max_unit_length] = '\0';
		v_qty = src.v_qty;
		v_need = src.v_need;
		v_price = src.v_price;
		v_status = src.v_status;

		if (src.v_name != nullptr) {
			v_name = nullptr;
			v_name = new char[length];
			for (int i = 0; i < length; ++i) {
				v_name[i] = src.v_name[i];
			}
			v_name[length] = '\0';
		}
		else
			v_name = nullptr;
	}

	void Product::name(const char* name) {
		if (name != nullptr) {
			int length = strlen(name);
			v_name = new char[length];
			for (int i = 0; i < length; ++i){
				v_name[i] = name[i];
			}
			v_name[length] = '\0';
		}
	}

	const char* Product::name() const {
		if (v_name[0] == '\0')
			return nullptr;
		else
			return v_name;
	}

	const char* Product::sku() const {
		return v_sku;
	}

	const char* Product::unit() const {
		return v_unit;
	}

	bool Product::taxed() const {
		return v_status;
	}

	double Product::price() const {
		return v_price;
	}

	double Product::cost() const {
		if (v_status == true)
			return price() * (tax + 1);
		else
			return price();
	}

	void Product::message(const char* err) {
		v_err.message(err);
	}

	bool Product::isClear() const {
		return v_err.isClear();
	}

	Product& Product::operator=(const Product& cpy) {
		if (this != &cpy) {
			v_type = cpy.v_type;
			strncpy(v_sku, cpy.sku(), max_sku_length);
			strncpy(v_unit, cpy.unit(), max_unit_length);
			v_qty = cpy.v_qty;
			v_need = cpy.v_need;
			v_price = cpy.v_price;
			v_status = cpy.v_status;
			delete[] v_name;

			int length = strlen(cpy.v_name);

			if (cpy.v_name != nullptr) {
				v_name = new char[length];
				for (int i = 0; i < length; ++i){
					v_name[i] = cpy.v_name[i];
				}
				v_name[length] = '\0';
			}
			else
				v_name = nullptr;
		}
		return *this;
	}
	

	std::fstream& Product::store(std::fstream& file, bool newLine) const {
		file << v_type << ',' << v_sku << ',' << v_unit << ',' << v_name 
			 << ',' << v_qty << ',' << v_status << ',' << v_price << ',' 
			 << v_need;
		if (newLine == true)
			file << endl;
		return file;
	}

	std::fstream& Product::load(std::fstream& file) {
		Product tmp;
		tmp.v_name = new char[max_name_length + 1];
		if (file.is_open()){
			file >> tmp.v_type >> tmp.v_sku >> tmp.v_unit >> tmp.v_name 
			>> tmp.v_qty >> tmp.v_status >> tmp.v_price >> tmp.v_need;
			*this = tmp;
		}
		delete[] tmp.v_name;
		tmp.v_name = nullptr;
		return file;
	}

	std::ostream& Product::write(std::ostream& os, bool linear) const {
		if (linear == true){
			os << setw(max_sku_length) << left << v_sku << '|'
			   << setw(20) << left << v_name << '|'
			   << setw(7) << right << fixed << setprecision(2) << cost() << '|'
			   << setw(4) << right << v_qty << '|'
			   << setw(10) << left << v_unit << '|'
			   << setw(4) << right << v_need << '|';
		}
		else{
			os << "Sku: " << v_sku << "|" << endl
			   << "Name: " << v_name << "|" << endl
			   << "Price: " << v_price << "|" << endl;

			if (v_status == true)
				os << "Price after tax: " << cost() << "|" << endl;
			else{
				os << "N/A"<< "|" << endl;
			}

			os << "Quantity On hand: " << v_qty << "|" << endl
			   << "Quantity needeed: " << v_need << "|" << endl;
		}
		return os;
	}

	std::istream& Product::read(std::istream& is) {

		char sku[max_sku_length + 1];
		char* name = new char[max_name_length + 1];
		char unit[max_unit_length + 1];
		int qty, need;
		double price;
		char tax;
		bool status;
		ErrorState err;

		cout << " Sku: ";
		is >> sku;
		cout << " Name (no spaces): ";
		is >> name;
		cout << " Unit: ";
		is >> unit;
		cout << " Taxed? (y/n): ";
		is >> tax;
		if (tax == 'Y' || tax == 'y')
			status = true;
		else if (tax == 'N' || tax == 'n')
			status = false;
		else{
			is.setstate(std::ios::failbit);
			err.message("Only(Y)es or (N)o are acceptable");
		}

		if (!is.fail()){
			cout << " Price: ";
			is >> price;
			if (is.fail())
				err.message("Invalid Price Entry");
		}

		if (!is.fail()){
			cout << " Quantity on hand: ";
			is >> qty;
			if (is.fail())
				err.message("Invalid Quantity Entry");
		}

		if (!is.fail()){
			cout << " Quantity needed: ";
			is >> need;
			if (is.fail())
				err.message("Invalid Quantity Needed Entry");
		}

		if (!is.fail()){
			Product tmp = Product(sku, name, unit, qty, status,
				price, need);
			*this = tmp;
		}

		delete[] name;
		name = nullptr;
		return is;
	}

	bool Product::operator==(const char* src) const {
		if (strcmp(src, this->v_sku) == 0)
			return true;
		else
			return false;
	}

	double Product::total_cost() const {
		return static_cast<double>(v_qty * (v_price + (v_price * tax)));
	}

	void Product::quantity(int stock) {
		v_qty = stock;
	}

	bool Product::isEmpty() const {
		if (v_name == nullptr)
			return true;
		else
			return false;
	}

	int Product::qtyNeeded() const {
		return v_need;
	}

	int Product::quantity() const {
		return v_qty;
	}

	bool Product::operator>(const char* prd) const {
		if (strcmp(v_sku, prd) > 0)
			return true;
		else
			return false;
	}

	bool Product::operator>(const Product& src) const {
		if (strcmp(v_name, src.v_name) > 0)
			return true;
		else
			return false;
	}

	int Product::operator+=(int add) {
		if (add > 0) 
			v_qty += add;	
		return v_qty;
	}

	std::ostream& operator<<(std::ostream& os, const Product& pr) {
		return pr.write(os, true);
	}

	std::istream& operator>>(std::istream& is, Product& pr) {
		pr.read(is);
		return is;
	}

	double operator+=(double& num, const Product& pr) {
		return num + pr.total_cost();
	}
}
