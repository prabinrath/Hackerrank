#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
    long a=(long)A;
    /*
    double ex=A-a;
    if(ex>0.5)a++;
    */
    cout<<left<<hex<<showbase<<nouppercase<<a<<endl;
    cout<<setw(15)<<setfill('_');
    cout<<fixed<<setprecision(2)<<right<<showpos<<B<<endl;
    cout<<noshowpos<<scientific<<uppercase<<setprecision(9)<<C<<endl;
 }
 return 0;
}
