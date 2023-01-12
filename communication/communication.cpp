#include <iostream>
#include <string>
using namespace std;
#define Max 1000//the max number of one book
//the communicater struct
struct communicater
{
	string m_name;
	int m_sex;//man:0 woman:1
	int m_age;
	string m_phone;
	string m_addr;
};
struct book
{
	communicater Person[Max];
	int amount;
};
//the start graph
void showMenu() {
	cout << "***************************************" << endl;
	cout << "******1.add the communicater   ********" << endl;
	cout << "******2.del the communicater   ********" << endl;
	cout << "******3.change the communicater********" << endl;
	cout << "******4.find the communicater  ********" << endl;
	cout << "******5.show the communicaters ********" << endl;
	cout << "******6.del all communicaters  ********" << endl;
	cout << "******0.exit                   ********" << endl;
	cout << "***************************************" << endl;
}
//add
void add(book *textbook) {
	if (textbook->amount == Max)
	{
		cout << "There is no space!" << endl;
		return;
	}
	else
	{
		//name
		string name;
		cout << "Please type the name:" << endl;
		cin >> name;
		textbook->Person[textbook->amount].m_name = name;
		//sex
		cout << "Please type the sex:" << endl;
		cout << "man is 0 ,woman is 1" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 0 || sex == 1) {
				textbook->Person[textbook->amount].m_sex = sex;
				break;
			}
			cout << "Please try again!man is 0 ,woman is 1!" << endl;
		}
		//age
		cout<< "Please type the age:" << endl;
		int age;
		cin >> age;
		textbook->Person[textbook->amount].m_age = age;
		//phone
		cout << "Please type the phone:" << endl;
		string phone;
		cin >> phone;
		textbook->Person[textbook->amount].m_phone = phone;
		//addr
		cout << "Please type the addr:" << endl;
		string addr;
		cin >> addr;
		textbook->Person[textbook->amount].m_addr = addr;
		//renew the book_amount
		textbook->amount++;
		cout << "Finish!" << endl;
		system("pause");
		system("cls");
	}
}
//show
void show(book textbook) {
	if (textbook.amount == 0) {
		cout << "this book is empty!" << endl;
	}
	else
	{
		for (int i = 0; i < textbook.amount; i++)
		{
			cout << "************no." << i+1 <<"************" << endl;
			cout << "name:" << textbook.Person[i].m_name << endl;
			cout << "age:" << textbook.Person[i].m_age << endl;
			cout << "sex:" << textbook.Person[i].m_sex << endl;
			cout << "phone:" << textbook.Person[i].m_phone << endl;
			cout << "addr:" << textbook.Person[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//test the exist
int isexist(book textbook,string name)
{
	for (int i = 0; i < textbook.amount; i++)
	{
		if (textbook.Person[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}
//del
void del(book* textbook)
{
	string name;
	cout << "Please type name:" << endl;
	cin >> name;
	int num = isexist(*textbook, name);
	if (num == -1)
	{
		cout << "NO this man" << endl;
		return;
	}
	else
	{
		for (int i = num; i < textbook->amount; i++)
		{
			textbook->Person[i] = textbook->Person[i + 1];
		}
		textbook->amount--;
		cout << "Finish" << endl;
	}
	system("pause");
	system("cls");
}
//find
void find(book textbook)
{
	cout << "type the name" << endl;
	string name;
	cin >> name;
	int num = isexist(textbook, name);
	if (num != -1)
	{
		cout << "name:" << textbook.Person[num].m_name << endl;
		cout << "age:" << textbook.Person[num].m_age << endl;
		cout << "sex:" << textbook.Person[num].m_sex << endl;
		cout << "phone:" << textbook.Person[num].m_phone << endl;
		cout << "addr:" << textbook.Person[num].m_addr << endl;
	}
	else
	{
		cout << "NO this man" << endl;
	}
	system("pause");
	system("cls");
}
//change
void change(book *textbook)
{
	cout << "type the name" << endl;
	string name;
	cin >> name;
	int num = isexist(*textbook, name);
	if (num != -1)
	{
		//name
		string name;
		cout << "Please type the name:" << endl;
		cin >> name;
		textbook->Person[num].m_name = name;
		//sex
		cout << "Please type the sex:" << endl;
		cout << "man is 0 ,woman is 1" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 0 || sex == 1) {
				textbook->Person[num].m_sex = sex;
				break;
			}
			cout << "Please try again!man is 0 ,woman is 1!" << endl;
		}
		//age
		cout << "Please type the age:" << endl;
		int age;
		cin >> age;
		textbook->Person[num].m_age = age;
		//phone
		cout << "Please type the phone:" << endl;
		string phone;
		cin >> phone;
		textbook->Person[num].m_phone = phone;
		//addr
		cout << "Please type the addr:" << endl;
		string addr;
		cin >> addr;
		textbook->Person[num].m_addr = addr;
		cout << "Finish" << endl;
	}
	else
	{
		cout << "NO this man" << endl;
	}
	system("pause");
	system("cls");
}
//delall
void delall(book*textbook)
{
	cout << "Really?" << endl;
	
	cout << "if do del ,Press 1,NO Press 0" << endl;
	int num;
	cin >> num;
	if (num)
	{
		textbook->amount = 0;
		cout << "finish" << endl;
	}
	system("pause");
	system("cls");
	return;
}
int main() {
	book combook;
	combook.amount = 0;
	int select = 0;
	while (true) {
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://add
			add(&combook);
			break;
		case 2://del
			del(&combook);
			break;
		case 3://change
			change(&combook);
			break;
		case 4://find
			find(combook);
			break;
		case 5://show
			show(combook);
			break;
		case 6://del all
			delall(&combook);
			break;
		case 0://exit
			cout << "Thanks for your using!" << endl;
			system("pause");
			return 0;
			break;
		default://exit

			break;
		}
	}
	cout << "Verify if get here?" << endl;//no get here!
	system("pause");
	return 0;
	
}