#include <bits/stdc++.h>
using namespace std;

// A node of Segment tree
class SegTreeNode {
public:
  int start;
  int end;
  int min;

  SegTreeNode *left;
  SegTreeNode *right;

  SegTreeNode(int start, int end) {
    this->start = start;
    this->end = end;
    left = right = nullptr;
  }
};

int query(SegTreeNode *root, vector<int>& heights, int start, int end) {
	// no overlap
	if (root == nullptr || end < root->start || start > root->end)
		return -1;

	// total overlap
	if (start <= root->start && end >= root->end) {
		return root->min;
	}

	// partial overlap
	int leftMin = query(root->left, heights, start, end);
	int rightMin = query(root->right, heights, start, end);

	// return's minimum of them both
	if (leftMin == -1) return rightMin;
	if (rightMin == -1) return leftMin;

	return heights[leftMin] < heights[rightMin] ? leftMin : rightMin;
}

int calculateMax(vector<int>& heights, SegTreeNode* root, int start, int end) {
	if (start > end) {
		return -1;
	}
	if (start == end) {
		return heights[start];
	}

	/* compare btw, maximum rectange area to the left of the min value index, to the right of the min vaue index, and considering the min value index,
	return whichever is the largest area
	*/
	int minIndex = query(root, heights, start, end);
	int leftMax = calculateMax(heights, root, start, minIndex - 1);
	int rightMax = calculateMax(heights, root, minIndex + 1, end);

	int minMax = heights[minIndex] * (end - start + 1);

	return max( max(leftMax, rightMax), minMax );
}

SegTreeNode *buildSegmentTree(vector<int>& heights, int start, int end) {
	if (start > end) return nullptr;

	// builing a node
	SegTreeNode *root = new SegTreeNode(start, end);		// assinging it's range

	// assinging values to the leaf node
	if (start == end) {
		root->min = start;
		return root;
	}
	else{
		int middle = (start + end) / 2;
		root->left = buildSegmentTree(heights, start, middle);
		root->right = buildSegmentTree(heights, middle + 1, end);

		root->min = heights[root->left->min] < heights[root->right->min] ? root->left->min : root->right->min;
		return root;
	}
}

int largestRectangleArea(vector<int>& heights) {
	if (heights.size() == 0) return 0;

	// first build a segment tree
	SegTreeNode *root = buildSegmentTree(heights, 0, heights.size() - 1);

	// next calculate the maximum area recursively
	return calculateMax(heights, root, 0, heights.size() - 1);
}

int main(){
    vector<int> histogram({12, 3, 5, 7, 23, 11, 12, 6});

    cout << "Maximum area : " << largestRectangleArea(histogram) << endl;

    return 0;
}
