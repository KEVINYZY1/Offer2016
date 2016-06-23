/*
3.4 �����������л��ͷ����л� p103
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
	/**
	* ����������л�������
	*/
	string preSerialize(TreeNode *root) {
		// write your code here
		if (root == NULL)
			return "#!";

		/*����������л����ݹ�ʵ��*/
		char s[10];
		sprintf(s,"%d",root->val);
		string str = string(s) + "!";
		str += preSerialize(root->left);
		str += preSerialize(root->right);

		return str;
	}

	/**
	* ������������л�
	*/
	TreeNode *preDeserialize(string data) {
		// write your code here
		queue<string> vals;

		int beg = 0, i = 0;
		int len = data.length();
		for (; i < len; ++i)
		{
			if (data[i] == '!')
			{
				string str = data.substr(beg, i - beg);
				beg = i + 1;
				vals.push(str);
			}//if
		}//for

		/*����ĩβֵ*/
		vals.push(data.substr(beg, i - beg));

		return preBuildTree(vals);
	}

	TreeNode *preBuildTree(queue<string> vals)
	{
		string val = vals.front();
		vals.pop();

		if (val == "#")
			return NULL;

		TreeNode *node = new TreeNode(atoi(val.c_str()));
		node->left = preBuildTree(vals);
		node->right = preBuildTree(vals);

		return node;
	}

	/*����������л�������*/
	string serialize(TreeNode *root)
	{
		if (root == NULL)
			return "#!";

		char s[10];
		sprintf(s, "%d", root->val);
		string str = string(s) + "!";
		
		queue<TreeNode *> nodes;
		nodes.push(root);
		while (!nodes.empty())
		{
			TreeNode *node = nodes.front();
			nodes.pop();

			if (node->left != NULL)
			{
				char s[10];
				sprintf(s, "%d", node->left->val);
				str = str + string(s) + "!";
				nodes.push(node->left);
			}
			else {
				str += "#!";
			}//else

			if (node->right != NULL)
			{
				char s[10];
				sprintf(s, "%d", node->right->val);
				str = str + string(s) + "!";
				nodes.push(node->right);
			}
			else {
				str += "#!";
			}//else
		}//while

		return str;
	}

	/**
	* ������������л�
	*/
	TreeNode *deserialize(string data) {
		// write your code here
		// write your code here
		vector<string> vals;

		int beg = 0, i = 0;
		int len = data.length();
		for (; i < len; ++i)
		{
			if (data[i] == '!')
			{
				string str = data.substr(beg, i - beg);
				beg = i + 1;
				vals.push_back(str);
			}//if
		}//for

		 /*����ĩβֵ*/
		vals.push_back(data.substr(beg, i - beg));

		return BFSBuildTree(vals);
	}

	TreeNode *BFSBuildTree(vector<string> vals)
	{
		if (vals.empty())
			return NULL;

		int len = vals.size(), idx = 0;
		string str = vals[idx++];
		TreeNode *root = new TreeNode(atoi(str.c_str()));

		queue<TreeNode *> nodes;
		nodes.push(root);
		
		while (!nodes.empty() && idx < len-1)
		{
			TreeNode *node = nodes.front();
			nodes.pop();

			string str = vals[idx++];
			if (str != "#")
			{
				node->left = new TreeNode(atoi(str.c_str()));
				nodes.push(node->left);
			}

			str = vals[idx++];
			if (str != "#")
			{
				node->right = new TreeNode(atoi(str.c_str()));
				nodes.push(node->right);
			}//if
		}//while

		return root;
	}
};


int main()
{
	Solution s;
	string str = "3!9!20!#!#!15!7!";
	TreeNode *root = s.deserialize(str);

	string ret = s.serialize(root);

	cout << ret << endl;

	getchar();

	return 0;
}