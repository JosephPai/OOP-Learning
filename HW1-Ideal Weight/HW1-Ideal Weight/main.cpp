#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
    string name, feetString, inchesString;
    bool feetFlag, inchesFlag;
    double feet, inches, idealWeight;
    ifstream inStream;
    inStream.open("weight.txt");		//使用fstream從文檔讀入數據

    if (inStream.fail())  				//對於文件開啟失敗進行異常處理
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    //使用while處理多筆數據
    while (getline(inStream, name))  		//首使用getline()函數讀入帶有space的name
    {
        feetFlag = (bool)getline(inStream, feetString);			//用temp以string格式暫存讀入的feet,inches的值
        inchesFlag = (bool)getline(inStream, inchesString);		//用flag以bool格式確定是否有數據成功讀入

        if (feetString[0] >= '0' && feetString[0] <= '9' && inchesString[0] >= '0' && inchesString[0] <= '9' && feetFlag == true && inchesFlag == true)
        {
            //根據首字母判斷getline()得到的是否為正確數字類型
            feet = atof(feetString.c_str());
            inches = atof(inchesString.c_str());		//將string轉換成double類型
        }
        else
        {
            cout << "Input Error! Lack of data.\n";
            exit(1);
        }

        if (inches > 11 || inches != inches || feet != feet || inches < 0)  		//檢測inches讀入數字大小是否合格
        {
            cout << "Input Error! Invalid inches.\n";
            exit(1);
        }

        if (feet < 5)	//計算Ideal Weight
        {
            idealWeight = 110;
        }
        else
        {
            idealWeight = ((feet - 5) * 12 + inches) * 5 + 110;
        }

        cout << name << endl;

        if (inches != 0)  			//對於inches=0的情況做特殊處理
        {
            cout << "Height: " << feet << " feet and " << inches << " inches" << endl;
        }
        else
        {
            cout << "Height: " << feet << " feet" << endl;
        }

        cout << "Ideal Weight: " << idealWeight << " pounds\n" << endl;
    }

    inStream.close();		//程序結束關閉文件
    return 0;
}
