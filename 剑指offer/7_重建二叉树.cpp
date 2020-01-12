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
	if (startPreorder == endPreorder) // 如果前序遍历的第一个节点的指针== 前序遍历的最后一个节点的指针(都指向一个节点)
	{
		if (startInorder == endInorder&&  //中序遍历的第一个节点 == 中序遍历的最后一个节点
			*startPreorder == *startInorder) // 前序遍历的第一个节点的值 == 中序遍历第一个节点的值
		{
			return root; //肯定就是只有一个根节点，直接返回。
		}
	}
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;
	int leftLength = rootInorder - startPreorder;
	int* leftPreorderEnd = startPreorder + leftLength;

	if (leftLength > 0)
	{
		//构建左子树
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
