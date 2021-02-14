#include <iostream>

union Date {
private:
	struct { unsigned short int m_year : 7, m_month : 4, m_day : 5; };

public:
	unsigned short int m_date;

	Date() : Date(0, 0, 0) {}

	Date(unsigned short year, unsigned short month, unsigned short day) {
		m_date = 0;
		SetYear(year);
		SetMonth(month);
		SetDay(day);
	}

	~Date() {}

	unsigned short GetYear() const {
		return m_year;
	}
	unsigned short GetMonth() const {
		return m_month;
	}
	unsigned short GetDay() const {
		return m_day;
	}

	void SetYear(unsigned short year) {
		m_year = year;
	}
	void SetMonth(unsigned short month) {
		m_month = month;
	}
	void SetDay(unsigned short day) {
		m_day = day;
	}
};

int main() {
	Date date{ 21, 2, 14 };
	std::cout << sizeof(date) << std::endl;
	std::cout << "Year: 20" << date.GetYear() << ", Month: " << date.GetMonth() << ", Day: " << date.GetDay() << std::endl;
}
