#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char* argv[])
{
	for (unsigned int i = 0; i < 25009; ++i) {
		int c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11;
		scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8, &c9, &c10, &c11);
		cout << c11 << "\t" << c1 << "\t" << c2 << "\t" << c3 << "\t" << c4 << "\t" << c5 << "\t" << c6 << "\t" << c7 << "\t" << c8 << "\t" << c9 << "\t" << c10 << endl;
	}
	return 0;
}
