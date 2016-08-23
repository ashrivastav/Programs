 unsigned long long number = 0;
    
    for(int i=0; i< A.size(); i++)
    {
        number = number * 10 + A[i];
    }
	number++;
	vector<int> b;
	while(number)
	{
		b.push_back(number %10);
		number = number/10;
	}
	
	reverse(b.begin(), b.end());
    return b;
