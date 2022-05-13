#ifdef _MSC_VER
#pragma warning(disable : 4996)

#include "string.h"


string string::operator+(const string& rhs) const {
	string str;		
	str.len = len + rhs.len;
	delete[]str.sData;
	str.sData = new char[str.len + 1];
	strcpy(str.sData, sData);
	strcat(str.sData, rhs.sData);

	return str;

}

string& string::operator=(const string& rhs) {
	if (sData == rhs.sData)
		return *this;
	delete[] sData;
	len = rhs.len;
	sData = new char[len + 1];
	strcpy(sData, rhs.sData);
	return *this;
}

string string::operator+=(const string& rhs) const {
	return *this + rhs;

}

vector<string> string::split(string sep) const {
	vector<string> v;
	for (char* ptr = sData; ptr < sData + size();) {
		char* sep_ptr = strstr(ptr, sep.sData);
		if (sep_ptr == nullptr) {
			string str(ptr);
			v.push_back(str);
			break;
		}
		size_t size = (size_t)(sep_ptr - ptr);
		string str(size);
		memcpy(str.sData, ptr, size);
		str.sData[size] = '\0';
		v.push_back(str);
		ptr = sep_ptr+sep.size();
	}
	return v;
}

std::istream& operator>>(std::istream& is, string& s0) {
	unsigned char ch;
	s0 = string("");        
	std::ios_base::fmtflags fl = is.flags(); 
	is.setf(std::ios_base::skipws);			
	while (is >> ch) {
		is.unsetf(std::ios_base::skipws);
		if (isspace(ch)) {
			is.putback(ch);          
			break;
		}
		else {
			s0 = s0 + ch;             
		}
	}
	is.setf(fl);					
	return is;
}

std::ostream& operator<<(std::ostream& os, const string& s) {
	os << s.getStr();
	return os;
}



#endif