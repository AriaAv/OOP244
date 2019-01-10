// Aria Avazkhani
//2018-07-31
//updated: 2018-08-08

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
		
		int c = strlen(src.v_name);
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
			v_name = new char[c];
			for (int i = 0; i < c; ++i) {
				v_name[i] = src.v_name[i];
			}
			v_name[c] = '\0';
		}
		else
			v_name = nullptr;
	}

	void Product::name(const char* name) {
		if (name != nullptr) {
			int c = strlen(name);
			v_name = new char[c +1];
			for (int i = 0; i < c; ++i){
				v_name[i] = name[i];
			}
			v_name[c] = '\0';
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

		 if (this != &cpy){
	
			v_type = cpy.v_type;
			v_qty = cpy.v_qty;
			v_need = cpy.v_need;
			v_price = cpy.v_price;
			v_status = cpy.v_status;
			name(cpy.v_name);
			strncpy(v_sku, cpy.v_sku, strlen(cpy.v_sku));
			v_sku[strlen(cpy.v_sku)] = '\0';
			strncpy(v_unit, cpy.v_unit, strlen(cpy.v_unit));
			v_unit[strlen(cpy.v_unit)] = '\0';
		}
		return *this;
	}
	

	std::fstream& Product::store(std::fstream& file, bool newLine) const {
		file << v_type << ',' << v_sku << ',' << v_name << ',' << v_unit
			 << ',' << v_status <<  ',' << v_price << ',' << v_qty << ','
			 << v_need;
		if (newLine == true)
			file << endl;
		return file;
	}

	std::fstream& Product::load(std::fstream& file) {
		char t_sku[max_sku_length];
		char t_name[max_name_length];
		char t_unit[max_unit_length];
		double t_price;
		int t_qty, t_need;
		char t_tax;
		bool t_status;
		if (file.is_open()){
			file.getline(t_sku, max_sku_length, ',');
			t_sku[strlen(t_sku)] = '\0';
			file.getline(t_name, max_name_length, ',');
			t_name[strlen(t_name)] = '\0';
			file.getline(t_unit, max_unit_length, ',');
			t_unit[strlen(t_unit)] = '\0';
			file >> t_tax;
			if (t_tax == '1')
				t_status = true;
			else if (t_tax == '0')
				t_status = false;
			file.ignore();
			file >> t_price;
			file.ignore();
			file >> t_qty;
			file.ignore();
			file >> t_need;
			file.ignore();
			*this = Product(t_sku, t_name, t_unit, t_qty, t_status, t_price, t_need);
		}
		return file;
	}

	std::ostream& Product::write(std::ostream& os, bool linear) const {
		if (!(v_err.isClear())){
			os << v_err.message();
		}
		else if (linear){
			os << setw(max_sku_length) << left << setfill(' ') << v_sku << '|'
			   << setw(20) << left << v_name << '|'
			   << setw(7) << right << fixed << setprecision(2) << cost() << '|'
			   << setw(4) << right << v_qty << '|'
			   << setw(10) << left << v_unit << '|'
			   << setw(4) << right << v_need << '|';
		}
		else{
			os << " Sku: " << v_sku << endl
			   << " Name (no spaces): " << v_name << endl
			   << " Price: " << v_price << endl;

			if (v_status == true)
				os << " Price after tax: " << cost() << endl;
			else{
				os << " Price after tax: N/A"<< endl;
			}

			os << " Quantity on Hand: " << v_qty << " " << v_unit << endl
			   << " Quantity needed: " << v_need;
		}
		return os;
	}

	std::istream& Product::read(std::istream& is) {
		char tax;
		char* address = new char[max_name_length + 1];
		int qty, need;
		double t_price;
		if (!is.fail()){
			cout << " Sku: ";
			is >> v_sku;
			cin.ignore();
			cout << " Name (no spaces): ";
			is >> address;
			name(address);
			cout << " Unit: ";
			is >> v_unit;
			cout << " Taxed? (y/n): ";
			is >> tax;
			if (!is.fail()){
				v_err.clear();
				if (tax){
					bool yes = tax == 'y' || tax == 'Y';
					bool no = tax == 'n' || tax == 'N';
					if (yes)
						v_status = true;
					if (no)
						v_status = false;
					if (!(yes || no)){
						is.setstate(std::ios::failbit);
						v_err.message("Only (Y)es or (N)o are acceptable");
						return is;
					}
				}
			}
			else{
				is.setstate(std::ios::failbit);
				v_err.message("Only (Y)es or (N)o are acceptable");
				return is;
			}
			cout << " Price: ";
			is >> t_price;
			if (is.fail())			{
				v_err.clear();
				is.setstate(ios::failbit);
				v_err.message("Invalid Price Entry");
				return is;
			}
			else
				prices(t_price);
			cout << " Quantity on hand: ";
			is >> qty;
			if (is.fail()){
				v_err.clear();
				v_err.message("Invalid Quantity Entry");
				is.setstate(ios::failbit);
				return is;
			}
			else
				quantity(qty);
			cout << " Quantity needed: ";
			is >> need;
			cin.ignore();
			if (is.fail())			{
				v_err.clear();
				v_err.message("Invalid Quantity Needed Entry");
				is.setstate(ios::failbit);
				return is;
			}
			else
				qtyNeed(need);
			if (!is.fail()){
				v_err.clear();
			}
		}
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

	void Product::qtyNeed(int nd){

		v_need = nd;

	}

	void Product::prices(double pr){

		v_price = pr;

	}

	bool Product::operator>(const char* prd) const {
		if (strcmp(v_sku, prd) > 0)
			return true;
		else
			return false;
	}

	bool Product::operator>(const iProduct& src) const {
		if (strcmp(v_name, src.name()) > 0)
			return true;
		else
			return false;
	}

	int Product::operator+=(int add) {
		if (add > 0) 
			v_qty += add;	
		return v_qty;
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& pr) {
		return pr.write(os, true);
	}

	std::istream& operator>>(std::istream& is, iProduct& pr) {
		return pr.read(is);
	}

	double operator+=(double& num, const iProduct& pr) {
		return num + pr.total_cost();
	}
}
