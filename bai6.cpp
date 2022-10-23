#include<bits/stdc++.h>
#include<fstream>
#include<vector>
using namespace std;
int main(){
	vector<int> arr[10];
	
	int n;
	string str;
	const char* c;
	ifstream fileIn;
	fileIn.open("input2_1.txt",ios::in);
	fileIn>>n;
	for(int i=0;i<=n;i++){
		getline(fileIn,str);
		c = str.c_str();
		for(int j=0;j<str.length();j++){
			arr[i].push_back((c[j]));
		}		
	}
	fileIn.close();
	for(int i=1;i<=n;i++){
		cout<<i<<" : ";
		for(int x=0;x<arr[i].size();x++){
			cout<<char(arr[i][x])<<" ";
		}
		cout<<endl;
	}
	//-----ma tran ke
	cout<<" ma tran ke"<<endl;
	int arr1[10][10];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			arr1[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int x=0;x<arr[i].size();x++){
			arr1[i-1][(arr[i][x])-49]=1;
			arr1[(arr[i][x])-49][i-1]=1;
		}
	}
	for(int k=0;k<n;k++){
		for(int l=0;l<n;l++){
			cout<<arr1[k][l]<<" ";
		}
		cout<<endl;
	}
	//-----danh sach ke
	cout<<"Danh sach ke"<<endl;
	for(int i=1;i<=n;i++){
		for(int x=0;x<arr[i].size();x++){
			if(i<(arr[i][x])-48)
				cout<<i<<" "<<char(arr[i][x])<<endl;
		}
	}
	
	//-----------Bac cua tung dinh
	int bac[10];
	for(int i=1;i<=n;i++){
		bac[i]=arr[i].size();
	}
	ofstream fileOut;
	fileOut.open("output1_1.txt",ios::out);
	for(int i=1;i<=n;i++){
		fileOut<<bac[i]<<" ";
	}
}
