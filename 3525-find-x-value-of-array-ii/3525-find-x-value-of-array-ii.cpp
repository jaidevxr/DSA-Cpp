class Solution {
public:
    struct Node {
        int prod;
        int cnt[5];

        Node(int k = 5) {
            prod = 1;
            memset(cnt, 0, sizeof(cnt));
        }
    };

    int k;
    vector<Node> tree;

    Node merge(Node &a, Node &b) {
        Node res;
        res.prod = (a.prod * b.prod) % k;

        for(int i = 0; i < k; i++) {
            res.cnt[i] = a.cnt[i];
        }

        for(int i = 0; i < k; i++) {
            int rem = (a.prod * i) % k;
            res.cnt[rem] += b.cnt[i];
        }

        return res;
    }

    void build(vector<int>& nums, int node, int l, int r) {
        if(l == r) {
            int rem = nums[l] % k;
            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if(l == r) {
            memset(tree[node].cnt, 0, sizeof(tree[node].cnt));

            int rem = val % k;
            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;
            return;
        }

        int mid = (l + r) / 2;

        if(idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        if(qr <= mid)
            return query(node * 2, l, mid, ql, qr);

        if(ql > mid)
            return query(node * 2 + 1, mid + 1, r, ql, qr);

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int K, vector<vector<int>>& queries) {
        k = K;

        int n = nums.size();
        tree.resize(4 * n);

        build(nums, 1, 0, n - 1);

        vector<int> ans;

        for(auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, index, value);

            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};