#include<iostream>
#include<fstream>
using namespace std;
void luuFile(ofstream& f,string fname,int arr[10][10],int n){
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++){
			cout<<"arr["<<j<<"]["<<i<<"]=";
			cin>>arr[j][i];
		}
	}
	f.open(fname.c_str(),ios::out);// bat dau mo file de ghi 
	f<<n<<endl;//in ra file
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++){
			f<<arr[j][i]<<" ";
		}
		f<<endl;
	}
	f.close();
}
int main(){
	int arr1[10][10],arr2[10][10],n1,n2;
	cout<<" Nhap n1: ";
	cin>>n1;
	ofstream fileOut1,fileOut2;//mo file de ghi
	luuFile(fileOut1,"input1.txt",arr1,n1);//
	cout<<" Nhap n2: ";
	cin>>n2;
	luuFile(fileOut2,"input2.txt",arr2,n2);
}
