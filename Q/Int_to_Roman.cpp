#include <iostream>
using namespace std;

int main()
{
	int num;
	cout<<"Enter Integer : ";
	cin>>num;
	string ans ="";
	int val[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
	string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
	
	for(int i=12;i>=0;i--)
	{
		while(num>=val[i])
		{
			ans += ""+sym[i];
			num-=val[i];
		}
	}
	cout<<"To Roman: "<<ans;
}