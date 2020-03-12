#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


#if 0

class Solution1 {
public:
	string longestPalindrome(string cStr)
	{
		if (cStr.size() <= 1)
			return cStr;

		string cTmpStr(cStr.size() * 2 + 1, '#');
	}
};


class Solution {
public:
	int lengthOfLongestSubstring(string &cstr)
	{
		int nSize = cstr.size();
		if (nSize <= 1) return nSize;

		int nRes = 0;
		int nStart = 0, nEnd = 0;
		vector<int> cVec(256, -1);

		while (nStart <= nEnd && nEnd < nSize)
		{
			if (cVec[cstr[nEnd]] == -1)
			{
				cVec[cstr[nEnd]] = nEnd;
			}
			else
			{
				nRes = max(nRes, nEnd - nStart);
				for (int nIdx = nStart; nIdx < cVec[cstr[nEnd]]; nIdx++)
					cVec[cstr[nIdx]] = -1;
				nStart = cVec[cstr[nEnd]] + 1;
				cVec[cstr[nEnd]] = nEnd;
			}
			if (nEnd == nSize - 1)
				break;;
			nEnd++;
		}

		return max(nRes, nEnd - nStart + 1);
	}
};

class Solution2 {
public:
	int lengthOfLongestSubstring(string &cstr)
	{
		int nSize = cstr.size();
		if (nSize <= 1) return nSize;

		int nRes = 0;
		int nEndPos = 0;
		int nStartPos = 0;
		vector<int> cVecPos(256, -1);

		while (nEndPos < nSize)
		{
			char chCur = cstr[nEndPos];
			if (cVecPos[chCur] == -1)
			{
				cVecPos[chCur] = nEndPos;
			}
			else
			{
				nRes = max(nEndPos - nStartPos, nRes);
				for (int nIdx = nStartPos; nIdx < cVecPos[chCur]; nIdx++)
					cVecPos[cstr[nIdx]] = -1;
				nStartPos = cVecPos[chCur] + 1;
				cVecPos[chCur] = nEndPos;
			}

			if (nEndPos == nSize - 1)
				break;;
			nEndPos++;
		}

		return max(nRes, nEndPos - nStartPos + 1);
	}
};



class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) 
	{
		vector<vector<int>> cVec;
		if (nums.size() < 3)
			return cVec;

		std::sort(nums.begin(), nums.end());
		for (int nIdx = 0; nIdx < nums.size() - 2; nIdx++)
		{
			if (nums[nIdx] > 0) break;
			if (nIdx > 0 && nums[nIdx] == nums[nIdx-1]) continue;
			
			int nStart = nIdx + 1;
			int nEnd = nums.size() - 1;
			while (nStart < nEnd)
			{
				int nSum = nums[nStart] + nums[nEnd] + nums[nIdx];
				if (nSum == 0)
				{
					cVec.push_back(vector<int>{nums[nIdx], nums[nStart], nums[nEnd]});
					while (nStart < nEnd && nums[++nStart] == nums[nStart - 1]);
					while (nStart < nEnd && nums[--nEnd] == nums[nEnd + 1]);
				}
				else if (nSum > 0)
					while (nStart < nEnd && nums[--nEnd] == nums[nEnd + 1]);
				else
					while (nStart < nEnd && nums[++nStart] == nums[nStart - 1]);
			}
		}

		return cVec;
	}
};


class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target)
	{
		std::sort(nums.begin(), nums.end());

		if (nums.size() < 3) return 0;

		int nOptDist = 0x7FFFFFFF;
		int nOptRes = 0x7FFFFFFF;
		for (int nIdx = 0; nIdx < nums.size() - 2; nIdx++)
		{
			int nStart = nIdx + 1;
			int nEnd = nums.size() - 1;

			while (nStart < nEnd)
			{
				int nSum = nums[nIdx] + nums[nStart] + nums[nEnd];
				int nCurDist = abs(nSum - target);
				if (nCurDist == 0) return target;

				if (nCurDist < nOptDist)
				{
					nOptDist = nCurDist;
					nOptRes = nSum;
				}

				if (nSum > target)
					while (nEnd > nStart && nums[--nEnd] == nums[nEnd + 1]);
				else
					while (nEnd > nStart && nums[++nStart] == nums[nStart - 1]);
			}
		}

		return nOptRes;
	}
};


class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target)
	{
		std::sort(nums.begin(), nums.end());

		int nTmp = 0;
		int nRes = 0;
		int nSum = 0x7fffffff;
		if (nums.size() < 3) return 0;
		for (int nIdx = 0; nIdx < nums.size() - 2; nIdx++)
		{
			int L = nIdx + 1;
			int R = nums.size() - 1;
			while (L < R)
			{
				nTmp = nums[nIdx] + nums[L] + nums[R] - target;

				if (abs(nTmp) < nSum)
				{
					nSum = abs(nTmp);
					nRes = nTmp;
				}

				if (nTmp == 0) return target;
				else if (nTmp > 0) R--;
				else L++;
			}
		}

		return nRes + target;
	}
};


class Solution {
public:
	int removeDuplicates(vector<int>& nums)
	{
		int nSize = nums.size();
		
		int nIdx = 1;
		int nPos = 1;
		int nCurVal = nums[0];
		for (; nIdx < nSize; nIdx++)
		{
			if (nums[nIdx] != nCurVal)
			{
				nums[nPos++] = nums[nIdx];
				nCurVal = nums[nIdx];
			}
		}

		return nPos;
	}
};



class Solution {
public:
	int removeElement(vector<int>& nums, int val) 
	{
		int nSize = nums.size();
		if (nSize == 0) return 0;

		int nPos = 0;
		for (int nIdx = 0; nIdx < nSize; nIdx++)
		{
			if (nums[nIdx] != val)
				nums[nPos++] = nums[nIdx];
		}
		return nPos;
	}
};



class Solution
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> cRes;
		int nSize = nums.size();
		if (nSize < 3) return cRes;
		std::sort(nums.begin(), nums.end());

		for (int nIdx = 0; nIdx < nSize - 2; nIdx++)
		{
			if (nums[nIdx] > 0) break;

			if (nIdx > 0 && nums[nIdx] == nums[nIdx - 1])
				continue;

			int nSum = -nums[nIdx];
			int nStart = nIdx + 1;
			int nEnd = nSize - 1;
			while (nStart < nEnd)
			{
				if (nums[nStart] + nums[nEnd] == nSum)
				{
					cRes.emplace_back(vector<int>{nums[nIdx], nums[nStart], nums[nEnd]});

					while (nStart < nEnd && nums[++nStart] == nums[nStart - 1]);
					while (nStart < nEnd && nums[--nEnd] == nums[nEnd + 1]);
				}
				else if (nums[nStart] + nums[nEnd] < nSum)
					while (nStart < nEnd && nums[++nStart] == nums[nStart - 1]);
				else
					while (nStart < nEnd && nums[--nEnd] == nums[nEnd + 1]);
			}
		}
		return cRes;
	}
};


class Solution3 {
public:
	vector<int> distributeCandies(int candies, int num_people)
	{
		if (num_people <= 0) return vector<int>();

		int nStart = 1;
		int nTotalCand = 0;
		vector<int> cVecCand(num_people, 0);
		while (true)
		{
			int nPos = (nStart-1) % num_people;
			if (candies <= nStart)
			{
				cVecCand[nPos] = candies;
				return cVecCand;
			}
			candies -= nStart;
			cVecCand[nPos] = nStart++;		
		}

		return cVecCand;
	}
};


inline bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

class Solution {
public:
	int myAtoi(string cStr)
	{
		int nSize = cStr.size();
		if (nSize <= 0) return 0;

		int nIdx = 0;
		while (cStr[nIdx] == ' ') nIdx++;
		bool bPositive = true;

		if (nIdx < cStr.size() && (cStr[nIdx] == '+' || cStr[nIdx] == '-'))
		{
			bPositive = cStr[nIdx] == '+' ? true : false;
		}

		unsigned int nRes = 0;
		unsigned MaxPNum = 0x7FFFFFFF;
		unsigned MaxNPNum = 0x80000000;
		for (; nIdx < nSize; nIdx++)
		{
			if (!isDigit(cStr[nIdx]))
				break;
			nRes = nRes * 10 + cStr[nIdx] - '0';
			if (bPositive && nRes > MaxPNum) return MaxPNum;
			if (!bPositive && nRes > MaxNPNum) return MaxNPNum;
		}

		return bPositive ? nRes : -nRes;
	}
};


struct ListNode 
{
    int val;
    ListNode *next;
	ListNode(int x) 
		: val(x), next(NULL) 
	{}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* pList1, ListNode* pList2)
	{
		if (pList1 == NULL) return pList2;
		if (pList2 == NULL) return pList1;

		int k = 0;   // 用来进位
		ListNode* pListResHead = new ListNode(0);  // 第一头没有用的
		ListNode* pTmp1 = pList1;
		ListNode* pTmp2 = pList2;
		ListNode* pListRes = pListResHead;
		
		while (pTmp1 || pTmp2)
		{
			ListNode* pTmp = new ListNode(0);
			if (pTmp1 && pTmp2)
				pTmp->val = pTmp1->val + pTmp2->val + k;
			else if (pTmp1)
				pTmp->val = pTmp1->val + k;
			else
				pTmp->val = pTmp2->val + k;

			k = pTmp->val / 10;
			pTmp->val %= 10;
			pListRes->next = pTmp;
			pListRes = pListRes->next;
			pTmp1 = pTmp1->next;
			if (pTmp1) pTmp1 = pTmp1->next;
			if (pTmp2) pTmp2 = pTmp2->next;
		}

		if (k)
			pListRes->next = new ListNode(k);

		pListRes = pListResHead->next;
		delete pListResHead;
		pListResHead = NULL;
		return pListRes;
	}
};

#include <queue>
#include <stack>
#include <queue>

struct cmp {
	bool operator () (ListNode *a, ListNode *b) {
		return a->val > b->val;
	}
};

class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		priority_queue<ListNode*, vector<ListNode*>, cmp> q;
		for (int i = 0; i < lists.size(); ++i) {
			if (lists[i]) q.push(lists[i]);
		}
		ListNode *head = NULL, *pre = NULL, *tmp = NULL;
		while (!q.empty()) {
			tmp = q.top();
			q.pop();
			if (!pre) head = tmp;
			else pre->next = tmp;
			pre = tmp;
			if (tmp->next) q.push(tmp->next);
		}
		return head;
	}
};


class Solution
{
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		vector<int> cVec;
		vector<vector<int>> cRes;

		std::sort(candidates.begin(), candidates.end());
		for (int nIdx = 0; nIdx < candidates.size(); nIdx++)
			generateCombination(cRes, vector<int>{candidates[nIdx]}, candidates, candidates[nIdx], target, nIdx);

		return cRes;
	}

	void generateCombination(vector<vector<int>> &cRes, vector<int> &cVec, vector<int> &candidates, int nSum, int tartget, int nPos)
	{
		if (nSum == tartget)
		{
			cRes.push_back(cVec);
			return;
		}

		for (int nIdx = nPos + 1; nIdx < candidates.size(); nIdx++)
		{
			if (nSum + candidates[nIdx] > tartget) return;

			cVec.push_back(candidates[nPos]);
			generateCombination(cRes, cVec, candidates, nSum + candidates[nIdx], tartget, nIdx);
			cVec.pop_back();
		}
	}
};

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) 
	{
		vector<vector<int>> cRes;
		int nSize = nums.size();

		if (nSize)
			generate(cRes, nums, 0);
		return cRes;
	}

	void generate(vector<vector<int>> &cRes, vector<int> &nums, int nPos)
	{
		if (nPos == nums.size())
		{
			cRes.push_back(nums);
			return;
		}

		for (int nIdx = nPos; nIdx < nums.size(); nIdx++)
		{
			std::swap(nums[nPos], nums[nIdx]);
			generate(cRes, nums, nPos + 1);
			std::swap(nums[nPos], nums[nIdx]);
		}
	}
};


#include <map>

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) 
	{
		vector<vector<string>> cRes;
		map<string, vector<string>> cMap;

		map<string, vector<string>>::iterator iter;
		for (int nIdx = 0; nIdx < strs.size(); nIdx++)
		{
			string cTmpStr = strs[nIdx];
			std::sort(cTmpStr.begin(), cTmpStr.end());
			iter = cMap.find(cTmpStr);
			if (iter == cMap.end())
			{
				cMap.insert(pair<string, vector<string>>(cTmpStr, vector<string>{strs[nIdx]}));
			}
			else
				iter->second.push_back(strs[nIdx]);
		}

		for (iter = cMap.begin(); iter != cMap.end(); iter++)
		{
			cRes.emplace_back(iter->second);
		}
		return cRes;
	}
};


class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums)
	{
		vector<vector<int>> cRes;
		int nSize = nums.size();

		if (nSize)
			generate(cRes, nums, 0);
		return cRes;
	}

	void generate(vector<vector<int>> &cRes, vector<int> &nums, int nPos)
	{
		if (nPos == nums.size())
		{
			cRes.push_back(nums);
			return;
		}

		for (int nIdx = nPos + 1; nIdx < nums.size(); nIdx++)
		{
			if (nums[nPos] != nums[nIdx])
			{
				std::swap(nums[nPos], nums[nIdx]);
				generate(cRes, nums, nPos + 1);
				std::swap(nums[nPos], nums[nIdx]);
			}
			else
			{
				generate(cRes, nums, nPos + 1);
			}
		}
	}
};



class Solution {
public:
	double myPow(double x, int n) 
	{
		if (x == 0 || x == 1)
			return x;
		
		if (n == 0) return 1;
		if (n == 1) return x;
		
		if (n < 0) return 1.0 / myPow(x, -n);
		
		double a = myPow(x, n / 2);
		if (n % 2) return a * a * x;
		else return a * a;
	}
};


class Solution {
public:
	int maxSubArray(vector<int>& nums) 
	{
		int nSize = nums.size();
		if (nSize == 0) return 0;
		
		int nMax = nums[0];
		int nPreMax = nums[0];

		for (int nIdx = 1; nIdx < nSize; nIdx++)
		{
			nPreMax = max(nPreMax + nums[nIdx], nums[nIdx]);
			nMax = max(nMax, nPreMax);
		}
		return nMax;
	}
};



/* 设置两个指针，l记录第一个非0的位置，l左边为0，r记录第一个非2的位置，r右边为2。然后使用i从头到尾扫一遍，
nums[i]遇到0就和nums[l]互换，遇到2就和nums[r]互换，遇到1就跳过，直到i>r停止（i要将nums[r]）处理完。*/

class Solution {
public:
	void sortColors(vector<int>& nums)
	{
		int nPosL = 0;   /* 1的位置 */
		int nPosR = nums.size() - 1;  /*  */
	}
};

#include <stack>

 struct TreeNode 
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) 
	{
		vector<int> cVec;
		if (root == NULL) return cVec;

		stack<TreeNode*> cStack;
		TreeNode* ptTmpNode = root;
		while (!cStack.empty() || ptTmpNode)
		{
			while (ptTmpNode)
			{
				cStack.push(ptTmpNode);
				ptTmpNode = ptTmpNode->left;
			}

			ptTmpNode = cStack.top();
			cStack.pop();
			cVec.push_back(ptTmpNode->val);
			ptTmpNode = ptTmpNode->right;
		}
		return cVec;
	}
};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) 
	{
		vector<int> cVec;
		stack<TreeNode*> cStack;
		TreeNode* ptTmpNode = root;
		while (!cStack.empty() || ptTmpNode)
		{
			if (ptTmpNode)
			{
				cVec.push_back(ptTmpNode->val);
				if (ptTmpNode->right)
					cStack.push(ptTmpNode->right);
				ptTmpNode = ptTmpNode->left;
			}
			if (ptTmpNode == NULL)
			{
				ptTmpNode = cStack.top();
				cStack.pop();
			}
		}
		return cVec;
	}
};


class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q)
	{
		if (p == NULL && q == NULL) return true;
		if (p == NULL || q == NULL) return false;
		if (p->val != q->val) return false;
		
		return isSameTree(p->left, p->left) && isSameTree(p->right, q->right);
	}
};



class Solution {
public:
	bool isSymmetric(TreeNode* root) 
	{
		if (root == NULL) return true;
		return isSame(root->left, root->right);
	}

	bool isSame(TreeNode* p, TreeNode* q)
	{
		if (p == NULL && q == NULL) return true;
		if (p == NULL || q == NULL) return false;

		if (p->val != q->val) return false;
		return isSame(p->left, q->right) && isSame(p->right, q->left);
	}
};

#include <queue>

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) 
	{
		vector<vector<int>> cVec;
		if (root == NULL) return cVec;
		queue<TreeNode*> cQueue;
		TreeNode* ptTmpNode = NULL;
		cQueue.push(root);

		while (!cQueue.empty())
		{
			int nSize = cQueue.size();
			vector<int> cTmpVec(nSize);
			for (int nIdx = 0; nIdx < nSize; nIdx++)
			{
				ptTmpNode = cQueue.front();
				cQueue.pop();
				cTmpVec[nIdx] = ptTmpNode->val;
				if (ptTmpNode->left)
					cQueue.push(ptTmpNode->left);
				if (ptTmpNode->right)
					cQueue.push(ptTmpNode->right);
			}

			cVec.emplace_back(cTmpVec);
		}
		return cVec;
	}
};


class Solution {
public:
	int coinChange(vector<int>& coins, int amount)
	{
		if (amount < 0 || coins.size() == 0)
			return -1;
		if (amount == 0)
			return 0;

		std::sort(coins.begin(), coins.end());
		vector<int> cVec(amount + 1, 0x7FFFFFF0);
		cVec[0] = 0;
		for (int nIdx = 1; nIdx <= amount; nIdx++)
		{
			for (int i = 0; i < coins.size() && coins[i] <= nIdx; i++)
			{
				cVec[nIdx] = min(cVec[nIdx - coins[i]] + 1, cVec[nIdx]);
			}
		}
		if (cVec[amount] == 0x7FFFFFF0)
			return -1;
		return cVec[amount];
	}
};


class Solution {
public:
	int jump(vector<int>& nums)
	{
		int nSize = nums.size();
		if (nSize <= 1)
			return 0;

		vector<int> cVec(nSize, false);
		cVec[0] = 0;

		int nCurMax = 0;
		for (int nIdx = 0; nIdx < nums.size(); nIdx++)
		{
			if (nCurMax + nums[nIdx] >= nSize - 1)
				return cVec[nIdx] + 1;

			for (int i = nCurMax + 1; i < nIdx + nums[nIdx]; i++)
			{
				cVec[i] = cVec[nIdx] + 1;
			}
			nCurMax = max(nCurMax, nIdx + nums[nIdx]);
		}
	}
};


class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) 
	{
		int nSize = flowerbed.size();
		if (nSize <= 2) return false;

		int nZeroCount = 0;
		int nFlower = 0;
		for (int nIdx = 0; nIdx < nSize; nIdx++)
		{
			if (flowerbed[nIdx] == 0)
				nZeroCount++;
			else
			{
				nFlower += (nZeroCount - 1) / 2;
				nZeroCount = 0;
			}
		}

		nFlower += (nZeroCount - 1) / 2;
		return nFlower >= n;
	}
};


class Solution {
public:
	bool checkPossibility(vector<int>& nums) 
	{
		int nSize = nums.size();
		if (nSize <= 2) return true;

		int nPosR = nSize - 1;
		int nPosL = 0;

		while (nPosR > 0 && nums[nPosR] < nums[nPosR-1])
			nPosR--;
		
		if (nPosR == 1) return true;
		while (nPosL < nSize - 1 && nums[nPosL] < nums[nPosL + 1])
			nPosL++;

		if (nPosR - nPosL <= 1)
			return true;
		return false;
	}
};


struct  ListNode
{
	int val;
	ListNode* next;
	ListNode(int v)
		:val(v), next(NULL) {};
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		if (head == NULL)
			return NULL;

		ListNode* ptPre = head;
		ListNode* ptCur = head->next;
		while (ptCur)
		{
			if (ptCur->val == ptPre->val)
			{
				ptPre->next = ptCur->next;
				delete ptCur;
				ptCur = ptPre->next;
			}
			else
			{
				ptPre = ptCur;
				ptCur = ptCur->next;
			}
		}
		return head;
	}
};



class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) 
	{
		if (head == NULL) return NULL;

		ListNode* ptHead = new ListNode(0);
		ListNode* ptPre = ptHead;
		ListNode* pyCur = ptHead->next;


	}
};


bool comp(const vector<int> &v1, const vector<int> &v2)
{
	return v1[0] < v2[0];
}

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals)
	{
		vector<vector<int>> cRes;
		int nSize = intervals.size();
		if (nSize == 0) return cRes;

		std::sort(intervals.begin(), intervals.end(), comp);
		for (int nIdx = 0; nIdx < nSize; nIdx++)
		{
			if (cRes.empty())
				cRes.push_back(intervals[nIdx]);
			else
			{
				vector<int> &cRefVec = cRes[cRes.size() - 1];
				if (intervals[nIdx][0] <= cRefVec[1])
					cRefVec[1] = max(intervals[nIdx][1], cRefVec[1]);
				else if (intervals[nIdx][0] > cRefVec[1])
					cRes.push_back(intervals[nIdx]);
			}
		}
		return cRes;
	}
};


class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
	{
		int nSize = preorder.size();
		if (nSize == 0) return NULL;
		if (nSize == 1) return new TreeNode(preorder[0]);

		int nPos = 0;
		int nRootVal = preorder[0];
		for (; nPos < inorder.size(); nPos++)
		{
			if (inorder[nPos] == nRootVal)
				break;
		}
		vector<int> subPreorderLeft, subInorderLeft;
		vector<int> subPreorderRight, subInorderRight;
		for (int nIdx = 0; nIdx < nSize; nIdx++)
		{
			if (nIdx < nPos)
			{
				subPreorderLeft.push_back(preorder[nIdx+1]);
				subInorderLeft.push_back(inorder[nIdx]);
			}	
			else if (nIdx > nPos)
			{
				subPreorderRight.push_back(preorder[nIdx]);
				subInorderRight.push_back(inorder[nIdx]);
			}
		}

		TreeNode *ptRoot = new TreeNode(nRootVal);
		ptRoot->left = buildTree(subPreorderLeft, subInorderLeft);
		ptRoot->right = buildTree(subPreorderRight, subInorderRight);
		return ptRoot;

	}
};



class Solution {
public:
	int findMin(vector<int> &num) {
		int left = 0, right = num.size() - 1;
		if (num[left] > num[right]) {
			while (left != (right - 1)) {
				int mid = (left + right) / 2;
				if (num[left] < num[mid]) left = mid;
				else right = mid;
			}
			return min(num[left], num[right]);
		}
		return num[0];
	}
};


class Solution
{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		if (headA == NULL || headB == NULL)
			return NULL;
		if (headA == headB)
			return headA;
		if (headA->next == NULL)
			return NULL;

		/* 将链表headA首尾相连 */
		ListNode *ptTmp = headA;
		while (ptTmp->next)
		{
			ptTmp = ptTmp->next;
		}
		ptTmp->next = headA;

		/* 对于链表B设置快慢指针 */
		ListNode* ptSlow = headB;
		ListNode* ptFast = headB;
		while (ptSlow && ptFast && ptFast->next)
		{
			ptSlow = ptSlow->next;
			ptFast = ptFast->next->next;
			if (ptSlow == ptFast)
				break;
		}

		if (ptSlow == NULL || ptFast == NULL || ptFast->next == NULL)
			return NULL;

		ptSlow = headB;
		while (ptSlow != ptFast)
		{
			ptSlow = ptSlow->next;
			ptFast = ptFast->next;
		}
		ptTmp->next = NULL;
		return ptSlow;
	}
};

class Solution {
public:
	int findPeakElement(vector<int>& nums)
	{
		int nSize = nums.size();
		if (nSize <= 2)
			return 0;
	
		int nLeft = 0;
		int nRight = nSize - 1;
		int nMid = 0;
		while (nLeft < nRight)
		{
			nMid = (nLeft + nRight) / 2;
			if (nums[nMid])
		}
	}
};


class Solution {
public:
	int rob(vector<int>& nums)
	{
		int nSize = nums.size();
		if (nSize == 0)
			return 0;
		if (nSize == 1)
			return nums[0];

		int nMax1 = rob1(vector<int>(nums.begin(), nums.end() - 1));
		int nMax2 = rob1(vector<int>(nums.begin() + 1, nums.end()));
		return max(nMax1, nMax2);
	}

	int rob1(vector<int> nums)
	{
		int size = nums.size();
		if (size == 0)
			return 0;

		if (size == 1)
			return nums[0];
		if (size == 2)
			return max(nums[0], nums[1]);


		int nPreMax1 = nums[0];
		int nPreMAx2 = nums[1];
		for (int i = 2; i < size; i++)
		{
			int curMax = nPreMax1 + nums[i];
			nPreMax1 = max(nPreMAx2, nPreMax1);
			nPreMAx2 = curMax;
		}

		return max(nPreMax1, nPreMAx2);
	}
};

#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) 
	{
		priority_queue< int, vector<int>, less<int> > cHeap;

		for (int nIdx = 0; nIdx < nums.size(); nIdx++)
		{
			if (nIdx < k)
				cHeap.push(nums[nIdx]);
			else
			{
				if (cHeap.top() > nums[nIdx])
				{
					cHeap.pop();
					cHeap.push(nums[nIdx]);
				}
			}
		}

		return cHeap.top();
	}
};

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
	{
		if (k < 0 || t < 1) return false;
		
		for (int nIdx = 0; nIdx < nums.size() - k; nIdx++)
		{
			for (int i = nIdx + 1; i <= nIdx + k && i < nums.size(); i++)
			{
				if (abs(nums[i] - nums[nIdx]) <= t)
					return true;
			}
		}
		return false;
	}
};

class Solution {
public:
	int lengthOfLIS(vector<int>& nums)
	{
		int nSize = nums.size();
		if (nSize <= 1) return nSize;

		int nMax = 1;
		vector<int> cVec(nSize, 1);
		for (int nIdx = 1; nIdx < nSize; nIdx++)
		{
			for (int i = 0; i < nIdx; i++)
			{
				if (nums[nIdx] > nums[i])
					cVec[nIdx] = max(cVec[nIdx], cVec[i] + 1);
			}
			nMax = max(nMax, cVec[nIdx]);
		}
		return nMax;
	}
};



inline bool isvowel(char ch)
{
	return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		|| (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

class Solution {
public:
	string reverseVowels(string str) 
	{
		int nStart = 0;
		int nEnd = str.size() - 1;
		while (nStart < nEnd)
		{
			while (nStart < nEnd && !isvowel(str[nStart])) { nStart++; };
			while (nStart < nEnd && !isvowel(str[nEnd])) { nEnd--; };

			std::swap(str[nStart++], str[nEnd--]);
		}
		return str;
	}
};


#include <map>


bool comp(const pair<char, int> &a, const pair<char, int> &b)
{
	return a.second < b.second;
}

class Solution {
public:
	string frequencySort(string cStr) 
	{
		map<char, int> cMap;
		map<char, int>::iterator iter;
		for (int nIdx = 0; nIdx < cStr.size(); nIdx++)
			++cMap[cStr[nIdx]];
		vector<pair<char, int>> cVec;
		for (iter = cMap.begin(); iter != cMap.end(); ++iter)
			cVec.push_back(*iter);

		string cRes;
		std::sort(cMap.begin(), cMap.end(), comp);
		for (int nIdx = 0; nIdx < cVec.size(); nIdx++)
		{
			for (int i = 0; i < cVec[nIdx].second; i++)
				cRes.push_back(cVec[nIdx].first);
		}
		return cRes;
	}
};

class Solution {
public:
	int maximumProduct(vector<int>& nums) 
	{
		int nSize = nums.size();
		if (nSize < 3) return 0;
		std::sort(nums.begin(), nums.end());
		return nums[nSize - 1] * nums[nSize - 2] * nums[nSize - 3];
	}
};



 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* bstFromPreorder(vector<int>& preorder) 
	{
		if (preorder.size() == 0)
			return NULL;
		if (preorder.size() == 1)
			return new TreeNode(preorder[0]);

		vector<int> cVecLeft, cVecRight;
		for (int nIdx = 1; nIdx < preorder.size(); nIdx++)
		{
			if (preorder[nIdx] < preorder[0])
				cVecLeft.push_back(preorder[nIdx]);
			else
				cVecRight.push_back(preorder[nIdx]);
		}

		TreeNode* ptRoot = new TreeNode(preorder[0]);
		ptRoot->left = bstFromPreorder(cVecLeft);
		ptRoot->right = bstFromPreorder(cVecRight);
		return ptRoot;
	}
};


class Solution {
public:
	bool flipEquiv(TreeNode* root1, TreeNode* root2) 
	{
		if (root1 == NULL && root2 == NULL) return true;
		if (root1 == NULL || root2 == NULL)	return false;
		if (root1->val != root2->val) return false;

		return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right))
			|| (flipEquiv(root1->right, root2->left) && flipEquiv(root1->left, root2->right));
	}
};


#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms)
	{
		int nSize = rooms.size();
		if (nSize <= 1) return true;

		queue<int> cQueue;
		int nCurRoom = -1;
		cQueue.push(0);
		int nCount = 0;
		vector<bool> bVisted(nSize, false);

		while (!cQueue.empty() && nCount < nSize)
		{
			nCurRoom = cQueue.front();
			cQueue.pop();
			if (!bVisted[nCurRoom])
			{
				nCount++;
				bVisted[0] = true;
				for (int nIdx = 0; nIdx < rooms[nCurRoom].size(); nIdx++)
				{
					if (!bVisted[rooms[nCurRoom][nIdx]])
						cQueue.push(rooms[nCurRoom][nIdx]);
				}
			}
		}
		return nCount == nSize;
	}
};




#include <stack>

class Solution
{
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms)
	{
		int nSize = rooms.size();
		if (nSize <= 1) return true;

		stack<int> cStack;
		cStack.push(0);
		int nCount = 1;
		int nCurRoom = -1;
		vector<bool> bVisted(nSize, false);

		while (!cStack.empty() && nCount < nSize)
		{
			nCurRoom = cStack.top();
			cStack.pop();
			for (int nIdx = 0; nIdx < rooms[nCurRoom].size(); nIdx++)
			{
				if (!bVisted[rooms[nCurRoom][nIdx]])
				{
					bVisted[rooms[nCurRoom][nIdx]] = true;
					nCount++;
					cStack.push(rooms[nCurRoom][nIdx]);
				}
			}
		}

		return nCount == nSize;
	}
};

#include <assert.h>

vector<int> findMax(vector<int> &cVec)
{
	int nSize = cVec.size();
	if (nSize <= 0) return vector<int>();


}

class Solution {
public:
	int findLHS(vector<int>& nums) 
	{
		int nSize = nums.size();
		if (nSize <= 1) return nSize;

		vector<int> cVecMax(nSize, 0);
		vector<int> cVecRes(nSize, 1);
		cVecMax[0] = nums[0];

		for (int nIdx = 0; nIdx < )
	}
};


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };





class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root)
	{
		if (root == NULL) return 0;
		int sum = 0;
		if (isLeaft(root->left))
			sum += root->left->val;
		sum += sumOfLeftLeaves(root->left);
		sum += sumOfLeftLeaves(root->right);
		return sum;
	}

	bool isLeaft(TreeNode* ptNode)
	{
		if (ptNode && ptNode->left == NULL && ptNode->right == nullptr)
			return true;
		return false;
	}
};

#endif

struct MyStruct
{
	int achNum[256];
	int* pn_buf_ptr;
};


int main()
{
	MyStruct s;
	s.pn_buf_ptr = s.achNum;
	cout << &s.pn_buf_ptr << endl;
	cout << s.pn_buf_ptr << endl;
	cout << s.achNum + 256 << endl;

	int *p = NULL;
	cout << &p << endl;
	p = (int*)(&p);

	cout << hex << *p << " " << p << endl;

	*p = 123456;
	cout << hex << *p << " " << p << endl;
	unsigned int a = 0xFFFFFFFF;
	unsigned int b = a + 1;
	cout << a << " " << b << endl;
}