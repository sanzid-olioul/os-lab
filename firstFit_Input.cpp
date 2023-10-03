#include<bits/stdc++.h>
using namespace std;

int main()
{
	/*int blockSize[] = {100, 500, 200, 300, 600};
	int processSize[] = {212, 417, 112, 426};
	int m = sizeof(blockSize) / sizeof(blockSize[0]);
	int n = sizeof(processSize) / sizeof(processSize[0]);*/
    int m,n,i;
	cout<<"Enter Number of Block: ";
	cin>>m;
	cout<<"Enter Number of Process: ";
	cin>>n;

	int blockSize[m],processSize[n];

	cout<<"Enter block sizes: ";
	for(i = 0;i<m;i++){
        cin>>blockSize[i];
	}
	cout<<"Enter process sizes: ";
	for(i = 0;i<n;i++){
        cin>>processSize[i];
	}
	int allocation[n];

	for(int i = 0; i < n; i++){
        allocation[i] = -1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (blockSize[j] >= processSize[i])
			{
				allocation[i] = j;
				blockSize[j] -= processSize[i];
				break;
			}
		}
	}

	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++)
	{
		cout << " " << i+1 << "\t\t"<< processSize[i] << "\t\t";
		if (allocation[i] != -1)
			cout << allocation[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}

	return 0 ;
}


