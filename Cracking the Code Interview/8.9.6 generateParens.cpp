/*
* ������8.9.6 ʵ��һ���㷨����ӡn�����ŵ�ȫ����Ч��ϡ�
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>

using namespace std;

class Solution{
public:
	/*����һ���ݹ������ѵõ�n-1�����ŵĺϷ���ϣ�����ÿһ���Ϸ����
	 * ��1���ڵ�һ��������֮�����һ������
	 * ��2���ڵڶ���������֮�����һ������
	 * ��3�����ַ�����ͷ����һ������
	 */
	vector<string> generateParens(int n)
	{
		unordered_set<string> us;
		if (0 == n)
			us.insert("");
		else
		{
			vector<string> tmp = generateParens(n - 1);
			auto iter = tmp.begin();
			for (; iter != tmp.end(); ++iter)
			{
				/*����n-1��������*/
				int len = (*iter).length();
				for (int i = 0; i < len; ++i)
				{
					if ((*iter)[i] == '(')
					{
						/*��i֮�����һ������*/
						string str = (*iter).substr(0, i + 1) + "()" + (*iter).substr(i + 1, len - i - 1);
						us.insert(str);
					}//if
				}//for
				/*���ַ�����ͷ���루��*/
				string str = "()" + (*iter);
				us.insert(str);
			}//for	
		}//else
		return vector<string>(us.begin(), us.end());
	}
};

int main()
{
	Solution s;
	vector<string> ret = s.generateParens(3);
	
	for (unsigned i = 0; i < ret.size(); ++i)
	{
		cout << ret[i] << endl;
	}//for

	system("pause");
	return 0;
}