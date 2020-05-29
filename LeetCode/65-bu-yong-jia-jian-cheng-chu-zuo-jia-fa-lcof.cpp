#include "pch.h"

class Solution {
public:
	int add(int a, int b) {
		//a, b, c
		bool C[2][2][2] =
		{
			//[0][x][x]
			{
				//[0][0][x]
				{0, 0}
				//[0][1][x]
				,{0, 1}
			}
			//[1][x][x]
			,{
				//[1][0][x]
				  {0, 1}
				  //[1][1][x]
				  ,{1, 1}
			  }
		};
		bool O[2][2][2] =
		{
			//[0][x][x]
			{
				//[0][0][x]
				{0, 1}
				//[0][1][x]
				,{1, 0}
			}
			//[1][x][x]
			,{
				//[1][0][x]
				  {1, 0}
				  //[1][1][x]
				  ,{0, 1}
			  }
		};
		int res = 0;
		bool c = false;
		for (int i = 0; i < sizeof(int) * 8; ++i)
		{
			const auto mask = (1 << i);
			const bool l1 = a & mask;
			const bool r1 = b & mask;

			if (O[l1][r1][c])
				res |= mask;

			c = C[l1][r1][c];
		}

		return res;
	}
};

void testSum(int a, int b)
{
	Solution s;

	std::cout << a << " + " << b << " = " << s.add(a, b);
	std::cout << " witch is ";
	std::cout << (a + b == s.add(a, b) ? "correct" : "wrong") << std::endl;;
}

void testSum()
{
	testSum(100, 987);
	testSum(100, 9870);
	testSum(200, 9870);
	testSum(1, -2);
}