//overloading << operator for printing class objects to stdout  
ostream& operator<<(ostream& os, Person& p)  
{  
    os << "first_name=" << p.get_first_name() << ",last_name=" << p.get_last_name();  
    return os;  
}

//overloading < operator for sorting the objects of a class
bool operator< (const Message& right) const { return stamp < right.stamp; }
