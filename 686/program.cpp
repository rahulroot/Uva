#include <iostream>
#include <fstream>
#include <math.h>
#include <bitset>
#include <vector>
using namespace std;

/* Prime Number */

#define SIZE 1000000LL
bitset<SIZE+1> prime;
vector<int> gpf;

void sieve()
{
	int sq = ceil(sqrt(SIZE));
	for(int i = 2; i <= sq; ++i)
	{
		if(!prime.test(i))
		{
			for(int j = i*i; j <= SIZE; j += i)
				prime.set(j,1);
		}
	}

	for(int i = 2;i <= SIZE; ++i)
	{
		if(!prime.test(i))
			gpf.push_back(i);
	}
}

bool is_sieve_prime(int num)
{
	if( num < 2) 
		return false;
	return !prime.test(num);
}

int main()
{
	ifstream infile;
	infile.open("./sample.txt");
	sieve();
	int num;

	while( infile >> num )
	{
		if(!num)
			break;
		if( num < 4 || num%2)
		{
			printf("0\n");
			continue;
		}

		vector<int>::iterator it;
		bool found = false;
		int sq = ceil(sqrt(num));
		int count = 0;
		for(it = gpf.begin(); (it != gpf.end() && *it <= num/2); ++it)
		{
			int p = *it;
			if(is_sieve_prime(num-p))
			{
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
