#define _CRT_SECURE_NO_WARNINGS = 1
#pragma once
//创建huffman			公用的		采用模板类
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


template<class W>

struct HuffmanTreeNode{
	HuffmanTreeNode(const W& weight)
		: _parenet(nullptr)
		,_lchild(nullptr)
		,_rchild(nullptr)
		,_weight(weight)
	{}
	HuffmanTreeNode* _parenet;
	HuffmanTreeNode* _lchild;
	HuffmanTreeNode* _rchild;
	W _weight;
};

template<class W>
class compare
{
public:
	typedef HuffmanTreeNode<W>* PNode;
	bool operator()(const PNode left, const PNode right)
	{
		return left->_weight > right->_weight;
	}
};


template <class W>
class HuffmanTree{
	typedef HuffmanTreeNode<W> Node;
	typedef Node* PNode;
public:
	HuffmanTree()
		:_Proot(nullptr)
	{}
	HuffmanTree(const vector<W>& v, const W& flag)
	{
		if (v.empty())
			return;
		//用所给的权值创建二叉树森林
		priority_queue<PNode,vector<PNode>,class compare<W>> q;
		for (size_t i = 0; i < v.size(); ++i)
		{
			if (v[i] != flag)
				q.push(new Node(v[i]));
		}
		while (q.size()>1)
		{
			PNode left = q.top();
			q.pop();
			PNode right = q.top();
			q.pop();

			PNode Parenet =new Node(left->_weight + right->_weight);
			Parenet->_lchild = left;
			Parenet->_rchild = right;

			left->_parenet = Parenet;
			right->_parenet = Parenet;

			q.push(Parenet);
		}
		_Proot = q.top();
	}



	~HuffmanTree()
	{
		_Destroy(_Proot);
	}
private:
	void _Destroy(PNode& Proot)
	{
		if (Proot)
		{
			_Destroy(Proot->_lchild);
			_Destroy(Proot->_rchild);
			delete Proot;
			Proot = nullptr;
		}
	}
public:
	PNode _Proot;
};

