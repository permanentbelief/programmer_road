#define _CRT_SECURE_NO_WARNINGS 1 
struct BinaryTreeNode
{
	int m_Value;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};
BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_Value = rootValue;
	root-> m_pLeft = nullptr;
	root-> m_pRight = nullptr;
	if (startPreorder == endPreorder) // ���ǰ������ĵ�һ���ڵ��ָ��== ǰ����������һ���ڵ��ָ��(��ָ��һ���ڵ�)
	{
		if (startInorder == endInorder&&  //��������ĵ�һ���ڵ� == ������������һ���ڵ�
			*startPreorder == *startInorder) // ǰ������ĵ�һ���ڵ��ֵ == ���������һ���ڵ��ֵ
		{
			return root; //�϶�����ֻ��һ�����ڵ㣬ֱ�ӷ��ء�
		}
	}
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;
	int leftLength = rootInorder - startPreorder;
	int* leftPreorderEnd = startPreorder + leftLength;

	if (leftLength > 0)
	{
		//����������
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
	{
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1,endInorder);
	}
	return root;
}
BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (inorder == nullptr || preorder == nullptr)
		return nullptr;
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}
