    bool IsSubtree(TreeNode* cur1,TreeNode* cur2)
    {
        if(cur2 == nullptr)
            return true;
        if(cur1 == nullptr)
            return false;
        if(cur1->val != cur2->val)
            return false;
        bool ret = true;
        if(ret)
            ret = IsSubtree(cur1->left,cur2->left);
        if(ret)
            ret = IsSubtree(cur1->right,cur2->right);
        return ret;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool res = false;
        if(pRoot1 == nullptr || pRoot2 == nullptr)
            return false;
        if(pRoot1->val == pRoot2->val)
            res = IsSubtree(pRoot1,pRoot2);
        if(!res)
            res = HasSubtree(pRoot1->left,pRoot2);
        if(!res)
            res = HasSubtree(pRoot1->right,pRoot2);
        return res;
    }