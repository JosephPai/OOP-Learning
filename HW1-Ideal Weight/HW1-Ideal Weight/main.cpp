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
    inStream.open("weight.txt");		//ʹ��fstream���ęn�x�딵��

    if (inStream.fail())  				//����ļ��_��ʧ���M�Ю���̎��
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    //ʹ��while̎���P����
    while (getline(inStream, name))  		//��ʹ��getline()�����x�뎧��space��name
    {
        feetFlag = (bool)getline(inStream, feetString);			//��temp��string��ʽ�����x���feet,inches��ֵ
        inchesFlag = (bool)getline(inStream, inchesString);		//��flag��bool��ʽ�_���Ƿ��Д����ɹ��x��

        if (feetString[0] >= '0' && feetString[0] <= '9' && inchesString[0] >= '0' && inchesString[0] <= '9' && feetFlag == true && inchesFlag == true)
        {
            //��������ĸ�Д�getline()�õ����Ƿ�����_�������
            feet = atof(feetString.c_str());
            inches = atof(inchesString.c_str());		//��string�D�Q��double���
        }
        else
        {
            cout << "Input Error! Lack of data.\n";
            exit(1);
        }

        if (inches > 11 || inches != inches || feet != feet || inches < 0)  		//�z�yinches�x�딵�ִ�С�Ƿ�ϸ�
        {
            cout << "Input Error! Invalid inches.\n";
            exit(1);
        }

        if (feet < 5)	//Ӌ��Ideal Weight
        {
            idealWeight = 110;
        }
        else
        {
            idealWeight = ((feet - 5) * 12 + inches) * 5 + 110;
        }

        cout << name << endl;

        if (inches != 0)  			//���inches=0����r������̎��
        {
            cout << "Height: " << feet << " feet and " << inches << " inches" << endl;
        }
        else
        {
            cout << "Height: " << feet << " feet" << endl;
        }

        cout << "Ideal Weight: " << idealWeight << " pounds\n" << endl;
    }

    inStream.close();		//����Y���P�]�ļ�
    return 0;
}
