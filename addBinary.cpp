#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include <iostream>
#include <string>
#include <math.h>
#include <vector>

//题目描述：
//给你两个二进制字符串 返回它们的和（用二进制表示）
//输入为非空 字符串且只包含数字1和0。
//每个字符串仅由字符‘0’或‘1’组成
//l<a.length, b.length<=10^4;
//字符串如果不是"0"，就不含前导0。


//解题思路一：
//首先先找到较长的字符串和它的长度，再找到较短的字符串和它的长度。定义返回结果为字符串类型 string ret;
//利用一个for循环，从较短的字符串最后一位ss[len_s-1]遍历到ss[0],进行位运算操作，若和为'0','1'不进行操作;若和为'2'，则sumtemp=1,ret[Ntemp]=0;若和为'3',则sumtemp=1,ret[Ntemp]=1。
//在利用一个for循环，从较长字符串长度-较短字符串长度 遍历到ls[0],即从ls[len_l-len_s-1]遍历到ls[0],也是从ls[Ntemp]遍历到ls[0],运用上面的规则进行位运算。
//若最后进位sumtemp仍然大于1，则在字符串之前加入一个'1'，即ret.insert(ret.begin(),'1');也可以ret='1'+ret;


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
//解题思路二：
//利用补0的思想把a和b长度保持一致。
//利用缓存的思想以sumtemp作为结果进行位运算，返回值为sumtemp%2,进位值为sumtemp/2。



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


//解题思路三：对于高级语言python3,代码会非常短，但是计算机执行用时24ms,内存15MB,相比之下c++用时0ms,内存消耗6.2MB,所以说c++不愧为效率之王
//但是对于人的效率来说，或许python3效率更高，也就是说，若以开发效率来讲，或许用python更有效率一点，但是我认为有些场景，就是追求机器的效率最大，这个时候c++的优势就很明显了
//所以学好python3进行高效的验证，后期移植到c++中是一个不错的选择。
//下面附加python3的简单代码，只有两行
//class Solution :
//	def addBinary(self, a, b)->str :
//	return '{0:b}'.format(int(a, 2) + int(b, 2))


int main() {


	test01();
	cout << "---------两种方法之间的分割线------------" << endl;
	test02();




	system("pause");
	return 0;
}