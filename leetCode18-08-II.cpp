#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int> > tree;  //unorderemaping key is node and value is node's subtree
    int goodNodesCount;

    Solution() : goodNodesCount(0) {}

    int countGoodNodes(vector<vector<int> >& edges) { //vector containing vector of(edges):-Adjacency in List
        int n = edges.size() + 1;  // Number of nodes is the number of edges + 1
        goodNodesCount = 0;

        // Build the adjacency list for the tree
        for (size_t i = 0; i < edges.size(); ++i) {
            int a = edges[i][0];
            int b = edges[i][1];
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        for(const auto&entry:tree){
            int node=entry.first;
            const vector<int>& neighbours=entry.second;
            cout<<"Node "<<node<<" is conneted to :";
            for(int neighbour:neighbours){
                cout<<neighbour<<" ";
            }
            cout<<endl;
        }

        // Call the DFS function to start traversal from the root node (0) with no parent (-1)
        subtreeSize(0, -1);

        return goodNodesCount;
    }

private:
    int subtreeSize(int node, int parent) {
        vector<int> childSizes;
        int totalSize = 1;

        // Iterate through each child of the current node
        for (size_t i = 0; i < tree[node].size(); ++i) {
            int child = tree[node][i];
            if (child != parent) {
                int size = subtreeSize(child, node);
                childSizes.push_back(size);
                totalSize += size;
            }
        }

        if (!childSizes.empty()) { // First checking on non-leaf Nodes by using condition 

            bool allEqual = true;
            for (size_t i = 1; i < childSizes.size(); ++i) {
                if (childSizes[i] != childSizes[0]) {    //// Check if all children have the same subtree size
                    allEqual = false;
                    break;
                }
            }
            if (allEqual) {
                goodNodesCount++;
            }
        } else {
            // Leaf nodes are considered good nodes
            // By definition In General every leaf node is a goodnode
            goodNodesCount++;
        }

        return totalSize;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int> > edges;

    edges.push_back(vector<int>(2, 0));
    edges.back()[0] = 0;
    edges.back()[1] = 1;

    edges.push_back(vector<int>(2, 0));
    edges.back()[0] = 1;
    edges.back()[1] = 2;

    edges.push_back(vector<int>(2, 0));
    edges.back()[0] = 2;                   //Using traditional method u can use new supported by compiler
    edges.back()[1] = 3;

    edges.push_back(vector<int>(2, 0));
    edges.back()[0] = 3;
    edges.back()[1] = 4;

    edges.push_back(vector<int>(2, 0));
    edges.back()[0] = 0;
    edges.back()[1] = 5;

    edges.push_back(vector<int>(2, 0));
    edges.back()[0] = 1;
    edges.back()[1] = 6;

    edges.push_back(vector<int>(2, 0));
    edges.back()[0] = 2;
    edges.back()[1] = 7;

    edges.push_back(vector<int>(2, 0));
    edges.back()[0] = 3;
    edges.back()[1] = 8;

    int result = sol.countGoodNodes(edges);
    cout << "Result: " << result << endl;

    return 0;
}

// ************** CODED BY HASSAM FATHE @hassamcoddes *********************** //


///////////////// ************* APLLICATIONS *******************  ///////////////////////////

/*

Self-Thought:

**Organized Designing Of Platform
**Even Distribution Of supplies
**Mapping Of Location
**Network of Connections


*/