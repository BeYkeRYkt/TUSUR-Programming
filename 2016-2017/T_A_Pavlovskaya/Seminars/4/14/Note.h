#include <string>

using namespace std;

// 179
class Note {
private:
	string name;
	string familyName;
	int* date = new int[3];
	int phone;
public:
	string getName();
	string getFamilyName();
	int* getDate();
	int getPhoneNumber();

	void setName(string name);
	void setFamilyName(string name);
	void setDate(int* date);
	void setPhoneNumber(int number);
};