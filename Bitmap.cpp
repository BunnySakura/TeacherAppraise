/*
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	char ch;

	ifstream in;
	in.open("C:\\Users\\ASUS\\Desktop\\pixiv\\qidian.png", ios::binary);   //ios::binary是抑制底层系统服务对文件内容进行的自动转换;如果不加这个，系统会自动把'\n'转为'\r\n';
	if (!in)
	{
		cout << "Cannot open file.";
		return 1;
	}
	ofstream out;
	out.open("C:\\Users\\ASUS\\Desktop\\tmp.jpg", ios::binary);
	if (!out) {

		cout << "Cannot open file.";
		return 1;     //传统意义上，return 1  表示非法结束；return 0  表示正常结束；
	}
	while (in)
	{
		in.get(ch);
		ch = ch ^ char(0xFF);    //字符的二进制码为01100000，它与11111111作异或后变为10011111；
		if (in)   out.put(ch);
	}


	in.close();
	out.close();
	return 0;
}

//'\r' 回车，回到当前行的行首，而不会换到下一行，如果接着输出的话，本行以前的内容会被逐一覆盖；

//'\n' 换行，换到当前位置的下一行，而不会回到行首；

*/

/*
#include <fstream>
#include <iostream>

using namespace std;
int main()
{
	char ch;

	ifstream in;
	in.open("C:\\Users\\ASUS\\Desktop\\tmp.jpg", ios::binary);   //ios::binary是抑制底层系统服务对文件内容进行的自动转换;如果不加这个，系统会自动把'\n'转为'\r\n';
	if (!in)
	{
		cout << "Cannot open file.";
		return 1;
	}
	ofstream out;
	out.open("C:\\Users\\ASUS\\Desktop\\new.jpg", ios::binary);
	if (!out) {

		cout << "Cannot open file.";
		return 1;     //传统意义上，return 1  表示非法结束；return 0  表示正常结束；
	}
	while (in)
	{
		in.get(ch);
		ch = ch ^ char(0xFF);    //字符的二进制码为01100000，它与11111111作异或后变为10011111；
		if (in)   out.put(ch);
	}


	in.close();
	out.close();
	return 0;
}
*/

/*
1.获取程序当前所在目录
2.遍历当前目录及子目录所有文件并输出文件绝对路径
3.确定需要进行的操作:加密/解密
4.调用"inout"类的in方法进行加密,out方法解密
  使用for循环遍历进行操作
*/

#include <fstream>
#include <iostream>
#include<vector>
#include<io.h>
#include <direct.h>
#include<string.h>

using namespace std;

class inout
{
public:
	bool in(const char *str1, const char* str2);
	bool out(const char* str1, const char* str2);

private:

};

bool inout::in(const char *str1, const char* str2)
{
	char ch;

	ifstream in;
	in.open(str1, ios::binary);   //ios::binary是抑制底层系统服务对文件内容进行的自动转换;如果不加这个，系统会自动把'\n'转为'\r\n';
	if (!in)
	{
		cout << "Cannot open file.";
		return 1;
	}
	ofstream out;
	out.open(str2, ios::binary);
	if (!out) {

		cout << "Cannot open file.";
		return 1;     //传统意义上，return 1  表示非法结束；return 0  表示正常结束；
	}
	while (in)
	{
		in.get(ch);
		ch = ch ^ char(0xFF);    //字符的二进制码为01100000，它与11111111作异或后变为10011111；
		if (in)   out.put(ch);
	}


	in.close();
	out.close();
	return true;

//'\r' 回车，回到当前行的行首，而不会换到下一行，如果接着输出的话，本行以前的内容会被逐一覆盖；

//'\n' 换行，换到当前位置的下一行，而不会回到行首；

}

bool inout::out(const char* str1, const char* str2)
{
	char ch;

	ifstream in;
	in.open(str1, ios::binary);   //ios::binary是抑制底层系统服务对文件内容进行的自动转换;如果不加这个，系统会自动把'\n'转为'\r\n';
	if (!in)
	{
		cout << "Cannot open file.";
		return 1;
	}
	ofstream out;
	out.open(str2, ios::binary);
	if (!out) {

		cout << "Cannot open file.";
		return 1;     //传统意义上，return 1  表示非法结束；return 0  表示正常结束；
	}
	while (in)
	{
		in.get(ch);
		ch = ch ^ char(0xFF);    //字符的二进制码为01100000，它与11111111作异或后变为10011111；
		if (in)   out.put(ch);
	}


	in.close();
	out.close();
	return 0;
}
/*
此方案为弃案.搁置不用,仅遗留问题留待日后解决
#define MAX_PATH 80
void getFiles(string path, string path2, vector<string>& files);
*/


int main()
{
	const char* str0;
	const char* str1;
	const char* str2;
	str0 = "C:\\Users\\ASUS\\Desktop\\test\\*.jpg";
	str1 = "C:\\Users\\ASUS\\Desktop\\test\\666.jpg";
	str2 = "C:\\Users\\ASUS\\Desktop\\test\\";

	int i, j;
	long Handle;
	inout pic1;

	struct _finddata_t FileInfo;
	if ((Handle = (_findfirst(str0, &FileInfo))) == -1)
		cout << "File not found! Error!" << endl;
	else {
		//组成绝对路径,使用"安全"的strcat_s,失败!
		//strcat_s((char*)str2, sizeof(str2) + 1, FileInfo.name);
		//printf(str2);
		pic1.in(FileInfo.name, str1);
		while (_findnext(Handle,&FileInfo)==0)
		{
			printf("%s", FileInfo.name);
		}
		_findclose(Handle);
	}


	/*
	vector<string> files;
	char buffer[MAX_PATH];
	_getcwd(buffer, MAX_PATH);
	string filePath;
	filePath.assign(buffer).append("\\");
		////获取该路径下的所有文件
		getFiles(filePath, "", files);
	char str[30];
	int size = files.size();
	for (int i = 0; i < size; i++)
	{
		cout << files[i].c_str() << endl;
	}
	*/
	
	return 0;
}
/*
void getFiles(string path, string path2, vector<string>& files)
{
	//文件句柄
	long hFile = 0;
	//文件信息
	struct _finddata_t fileinfo;
	string p, p2;
	if ((hFile = _findfirst(p.assign(path).append(path2).append("*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之
			//如果不是,加入列表
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "…") != 0)
					getFiles(p.assign(path).append("\\"),p2.assign(fileinfo.name).append("\\"), files );
			}
			else
			{
				files.push_back(p.assign(path2).append(fileinfo.name)); //这一行可以给出相对路径
				//files.push_back(p.assign(fileinfo.name) ); //这一行可以给出文件名
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}


*/
