#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main(){
	int arr[10][10],n,x,y;
	//---khoi tao gia tro 000000  cho ma tran
	ifstream fileIn;
	fileIn.open("input1_2.txt",ios::in);
	fileIn>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			arr[i][j]=0;
		}
		cout<<endl;
	}
	while(!fileIn.eof()){
		fileIn>>x;
		fileIn>>y;
		arr[x-1][y-1]=1;
		arr[y-1][x-1]=1;
	}
	fileIn.close();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	//--danh sach ke
	vector<int> arr1[100];
	int n1,v1,v2;
	ifstream fileIn1;
	fileIn1.open("input1_2.txt",ios::in);
	fileIn1>>n1;
	fileIn1>>v1;
	fileIn1>>v2;
	while(!fileIn1.eof()){
		arr1[v1].push_back(v2);
		arr1[v2].push_back(v1);
		fileIn1>>v1;
		fileIn1>>v2;
	}
	cout<<endl;
	for(int i=1;i<=n1;i++){
		cout<<i<<" : ";
		for(int x=0;x<arr1[i].size();x++){
			cout<<arr1[i][x]<<" ";
		}
		cout<<endl;
	}
	//-----------Bac cua tung dinh
	int bac[10];
	for(int i=1;i<=n1;i++){
		bac[i]=arr1[i].size();
	}
	ofstream fileOut;
	fileOut.open("output1_2.txt",ios::out);
	for(int i=1;i<=n1;i++){
		fileOut<<bac[i]<<" ";
	}
}
