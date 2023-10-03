
#include<bits/stdc++.h> //Worst Fit Algorithm
using namespace std;

int main()
{
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

	cout<<"Number of blocks: "<<m<<endl<<"Number of process: "<<n<<endl;

	int allocation[n];
	for (int i = 0; i < n; i++)
		allocation[i] = -1;

	for (int i = 0; i < n; i++)
	{
		int bestIdx = -1;
		for (int j = 0; j < m; j++)
		{
			if (blockSize[j] >= processSize[i])
			{
				if (bestIdx == -1)
					bestIdx = j;
				else if (blockSize[bestIdx] > blockSize[j])

					bestIdx = j;
			}
		}
		if (bestIdx != -1)
		{
			allocation[i] = bestIdx;
			blockSize[bestIdx] -= processSize[i];
		}
	}

	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++)
	{
		cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
		if (allocation[i] != -1)
			cout << allocation[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}

	return 0 ;
}
