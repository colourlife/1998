	vector<vector<int> > Print(TreeNode* pRoot) {
		queue<TreeNode*> queue1;
		queue<TreeNode*> queue2;
		vector<vector<int> > ret;
		vector<int> tmp;
		TreeNode* cur = pRoot;
		if (pRoot == nullptr)
			return ret;
		queue1.push(cur);
		tmp.push_back(cur->val);
		ret.push_back(tmp);
		while (!queue1.empty() || !queue2.empty())
		{
			tmp.clear();
			while (!queue1.empty())
			{
				cur = queue1.front();
				if (cur->left != nullptr)
					queue2.push(cur->left);
				if (cur->right != nullptr)
					queue2.push(cur->right);
				tmp.push_back(cur->val);
				queue1.pop();
			}
			ret.push_back(tmp);
			tmp.clear();
			while (!queue2.empty())
			{
				cur = queue2.front();
				if (cur->left != nullptr)
					queue1.push(cur->left);
				if (cur->right != nullptr)
					queue1.push(cur->right);
				tmp.push_back(cur->val);
				queue2.pop();
			}
			if (tmp.size() != 0)
				ret.push_back(tmp);
		}
		return ret;
	}
