#ifndef PERFECT_H
#define PERFECT_H

namespace dsq
{
	long Sigma(unsigned int n)
	{
		long sum = 0;

		for(int i = 1;i <= n;i += 1)
		{
			if(n % i == 0)
			{
				sum += i;
			}
		}
		return sum;
	}
}

#endif
