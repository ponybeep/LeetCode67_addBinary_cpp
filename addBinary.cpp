#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include <iostream>
#include <string>
#include <math.h>
#include <vector>

//��Ŀ������
//���������������ַ��� �������ǵĺͣ��ö����Ʊ�ʾ��
//����Ϊ�ǿ� �ַ�����ֻ��������1��0��
//ÿ���ַ��������ַ���0����1�����
//l<a.length, b.length<=10^4;
//�ַ����������"0"���Ͳ���ǰ��0��


//����˼·һ��
//�������ҵ��ϳ����ַ��������ĳ��ȣ����ҵ��϶̵��ַ��������ĳ��ȡ����巵�ؽ��Ϊ�ַ������� string ret;
//����һ��forѭ�����ӽ϶̵��ַ������һλss[len_s-1]������ss[0],����λ�������������Ϊ'0','1'�����в���;����Ϊ'2'����sumtemp=1,ret[Ntemp]=0;����Ϊ'3',��sumtemp=1,ret[Ntemp]=1��
//������һ��forѭ�����ӽϳ��ַ�������-�϶��ַ������� ������ls[0],����ls[len_l-len_s-1]������ls[0],Ҳ�Ǵ�ls[Ntemp]������ls[0],��������Ĺ������λ���㡣
//������λsumtemp��Ȼ����1�������ַ���֮ǰ����һ��'1'����ret.insert(ret.begin(),'1');Ҳ����ret='1'+ret;


class Solution1 {
public:
	string addBinary(string a, string b) {
		int len_a = a.length();
		int len_b = b.length();
		int len_l;
		int len_s;
		string ss, ls;
		if (len_a > len_b)
		{
			len_l = a.length();
			ls = a;
			len_s = b.length();
			ss = b;
		}
		else
		{
			len_l = b.length();
			ls = b;
			len_s = a.length();
			ss = a;
		}
		string ret;
		ret.resize(len_l);
		int Ntemp = len_l - 1;
		char sumtemp = '0';
		for (int i = len_s - 1; i >= 0; --i)
		{
			ret[Ntemp] = ss[i] - '0' + ls[Ntemp] - '0' + sumtemp;
			if (ret[Ntemp] == '2')
			{
				ret[Ntemp] = '0';
				sumtemp = '1';
			}
			else if (ret[Ntemp] == '3')
			{
				ret[Ntemp] = '1';
				sumtemp = '1';
			}
			else
			{
				sumtemp = '0';
			}
			Ntemp--;
		}
		for (int j = Ntemp; j >= 0; --j)
		{
			ret[Ntemp] = ls[Ntemp] - '0' + sumtemp;
			if (ret[Ntemp] == '2')
			{
				ret[Ntemp] = '0';
				sumtemp = '1';
			}
			else if (ret[Ntemp] == '3')
			{
				ret[Ntemp] = '1';
				sumtemp = '1';
			}
			else
			{
				sumtemp = '0';
			}
			Ntemp--;
		}
		if (sumtemp == '1')
		{
			ret.insert(ret.begin(), '1');
		}
		return ret;
	}
};

void test01()
{
	string a = "1110";
	string b = "101";
	Solution1 solution;
	string ret = solution.addBinary(a, b);
	for (int i = 0; i < ret.length(); i++)
	{
		cout << ret[i];
	}
	cout << endl;
}
//����˼·����
//���ò�0��˼���a��b���ȱ���һ�¡�
//���û����˼����sumtemp��Ϊ�������λ���㣬����ֵΪsumtemp%2,��λֵΪsumtemp/2��



class Solution2
{
public:
	string addBinary(string a, string b)
	{
		int len_a = a.length();
		int	len_b = b.length();
		while (len_a<len_b)
		{
			a = '0' + a;
			len_a++;
		}
		while (len_a > len_b)
		{
			b = '0' + b;
			len_b++;
		}
		int sumtemp = 0;
		for (int i = len_a-1; i >= 0; i--)
		{
			sumtemp = a[i] - '0' + b[i] - '0' + sumtemp;
			a[i] = sumtemp % 2 + '0';
			sumtemp /= 2;
		}
		if (sumtemp > 0)
		{
			a = '1' + a;
		}
		return a;
	}
};

void test02()
{
	string a = "10110";
	string b = "11";
	Solution2 solution;
	string ret = solution.addBinary(a, b);
	for (int i = 0; i < ret.length(); i++)
	{
		cout << ret[i];
	}
	cout << endl;
}


//����˼·�������ڸ߼�����python3,�����ǳ��̣����Ǽ����ִ����ʱ24ms,�ڴ�15MB,���֮��c++��ʱ0ms,�ڴ�����6.2MB,����˵c++����ΪЧ��֮��
//���Ƕ����˵�Ч����˵������python3Ч�ʸ��ߣ�Ҳ����˵�����Կ���Ч��������������python����Ч��һ�㣬��������Ϊ��Щ����������׷�������Ч��������ʱ��c++�����ƾͺ�������
//����ѧ��python3���и�Ч����֤��������ֲ��c++����һ�������ѡ��
//���渽��python3�ļ򵥴��룬ֻ������
//class Solution :
//	def addBinary(self, a, b)->str :
//	return '{0:b}'.format(int(a, 2) + int(b, 2))


int main() {


	test01();
	cout << "---------���ַ���֮��ķָ���------------" << endl;
	test02();




	system("pause");
	return 0;
}