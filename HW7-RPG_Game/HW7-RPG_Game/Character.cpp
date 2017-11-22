#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

Character::Character()
{

}

Character::~Character()
{

}

Character::Character(string name, int str, int dex, int con)
{
	this->_name = name;
	this->_str = str;
	this->_dex = dex;
	this->_con = con;
	this->_level = 1;
	this->_exp = 0;
	this->_totalFightTimes = 0;
	this->_failFighttTimes = 0;
}

string Character::GetName()
{
	return this->_name;
}

void Character::GetName(string name)
{
	this->_name = name;
}

int Character::GetLevel()
{
	return this->_level;
}

void Character::SetLevel(int level)
{
	this->_level = level;
}

int Character::GetStr()
{
	return this->_str;
}

void Character::SetStr(int str)
{
	this->_str = str;
}

int Character::GetDex()
{
	return this->_dex;
}

void Character::SetDex(int dex)
{
	this->_dex = dex;
}

int Character::GetCon()
{
	return this->_con;
}

void Character::SetCon(int con)
{
	this->_con = con;
}

int Character::GetExp()
{
	return this->_exp;
}

void Character::SetExp(int exp)
{
	this->_exp = exp;
}

int Character::GetTotalFightTimes()
{
	return this->_totalFightTimes;
}

void Character::SetTotalFightTimes(int times)
{
	this->_totalFightTimes = times;
}

int Character::GetFailFightTimes()
{
	return this->_failFighttTimes;
}

void Character::SetFailFightTimes(int times)
{
	this->_failFighttTimes = times;
}

bool Character::Fight(Character &monster)
{
	int hp1, hp2;
	int monDex, monStr, monCon;
	bool attackOrderFlag;
	monDex = monster.GetDex() + (this->GetLevel() - 1);
	monStr = monster.GetStr() + (this->GetLevel() - 1);
	monCon = monster.GetCon() + (this->GetLevel() - 1);
	hp1 = this->GetDex() * 3;
	hp2 = monDex * 3;
	cout << "\nϵͳѡ����[" << monster.GetName() << "]��Ϊ���ˡ�" << endl;
	cout << this->GetName() << "��DEXΪ" << this->GetDex() << ",";
	cout << monster.GetName() << "��DEXΪ" << monDex << ",��";
	attackOrderFlag = this->GetDex() >= monDex;
	cout << (attackOrderFlag ? this->GetName() : monster.GetName()) << "�Ƚ��й�����\n" << endl;

	while (true)
	{
		if (attackOrderFlag)
		{
			cout << this->GetName() << "������������"
				<< monster.GetName() << "���" << this->GetStr() << "���˺���" << endl;
			cout << monster.GetName() << "��HP��" << hp2 << "��Ϊ";
			if (hp2 > this->GetStr())
			{
				hp2 = hp2 - this->GetStr();
				cout << hp2 << "\n" << endl;
				attackOrderFlag = false;
			}
			else
			{
				hp2 = 0;
				cout << hp2 << "\n" << endl;
				cout << monster.GetName() << "�����ˣ���ʤ���� ��" << this->GetName() << endl;
				this->SetTotalFightTimes(this->GetTotalFightTimes() + 1);
				if (this->GetExp() < 1000)
				{
					this->SetExp(this->GetExp() + 100);
				}
				switch (this->GetExp())
				{
				case 100:	this->LevelUp(2);break;
				case 300:	this->LevelUp(3);break;
				case 600:	this->LevelUp(4);break;
				case 1000:	this->LevelUp(5);break;
				default:
					break;
				}
				return true;
			}
		}
		else
		{
			cout << monster.GetName() << "������������"
				<< this->GetName() << "���" << monStr << "���˺���" << endl;
			cout << this->GetName() << "��HP��" << hp1 << "��Ϊ";
			if (hp1 > monStr)
			{
				hp1 = hp1 - monStr;
				cout << hp1 << "\n" << endl;
				attackOrderFlag = true;
			}
			else
			{
				hp1 = 0;
				cout << hp1 << "\n" << endl;
				cout << this->GetName() << "�����ˣ���ʤ���� ��" << monster.GetName() << endl;
				this->SetTotalFightTimes(this->GetTotalFightTimes() + 1);
				this->SetFailFightTimes(this->GetFailFightTimes() + 1);
				return false;
			}
		}
	}

}

void Character::GetInformation()
{
	cout << "\n��ɫ���� ��" << this->GetName() << endl;
	cout << "Ŀǰ�ȼ� ��" << this->GetLevel() << endl;
	cout << "Ŀǰ����ֵ ��" << this->GetExp() << endl;
	cout << "STR : " << this->GetStr() << endl;
	cout << "DEX : " << this->GetDex() << endl;
	cout << "CON : " << this->GetCon() << endl;
	cout << "��ս������ ��" << this->GetTotalFightTimes() << endl;
	cout << "ս��ʧ�ܳ��� ��" << this->GetFailFightTimes() << "\n" << endl;
}

void Character::LevelUp(int lv)
{
	this->SetLevel(lv);
	int pointTemp = 3;
	string pointSel;
	cout << "��ɫ�����ˣ�����µ�3��������Էֵ���ǰ�����ϣ�(Role upgraded! Get the new 3 points can be assigned to the current property)" << "\n" << endl;
	while (pointTemp != 0)
	{
		cout << "\n1.ĿǰSTR :(Current STR) " << this->GetStr() << endl;
		cout << "2.ĿǰDEX : (Current DEX)" << this->GetDex() << endl;
		cout << "3.ĿǰCON : (Current CON)" << this->GetCon() << endl;
		cout << "Ŀǰʣ����� : (Current remaining points)" << pointTemp << endl;
		cout << "��ѡ��������֮���� : (Please choose to increase the attributes)";
		getline(cin, pointSel);
		pointTemp--;

		if (pointSel.compare("1") == 0)
		{
			this->SetStr(this->GetStr() + 1);
		}
		else if (pointSel.compare("2") == 0)
		{
			this->SetDex(this->GetDex() + 1);
		}
		else if (pointSel.compare("3") == 0)
		{
			this->SetCon(this->GetCon() + 1);
		}
		else
		{
			cout << "ָ��������������롣(Invalid input, please input again.)" << endl;
			pointTemp++;
			continue;
		}
	}
	cout << "\n�����ɣ�(Done!)" << this->GetName() << "Ŀǰ�ĵȼ��ﵽ(level reach to)" << lv << "��" << endl;
	this->GetInformation();
}