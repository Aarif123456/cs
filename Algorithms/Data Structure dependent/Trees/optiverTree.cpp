#include <stack>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <regex>

using namespace std;

struct TreeNode {
    char val;
    unordered_set<char> children;

    TreeNode() : val(-1) {}

    explicit TreeNode(char c) : val(c) {}

    bool addChild(char child) {
        auto initSize = children.size();
        children.insert(child);
        return children.size() > initSize;
    }

    bool operator<(const TreeNode &other) const {
        return val < other.val;
    }
};

constexpr char INVALID_INPUT[] = "INVALID";

typedef unordered_map<char, TreeNode> Nodes;

string getInput();
unordered_set<char> getRootNode(const Nodes &nodes);

bool isInputValid(string &input); // E1
bool createTree(string &input, Nodes &nodes); // E2
bool isTreeBinary(const Nodes &nodes); // E3
char getRoot(const unordered_set<char> &rootNodes); // E4 and E5(one case)
bool doesTreeHaveCycles(const Nodes &nodes, char root); // E5
void printTree(const Nodes &nodes, char cur);

int main() {
    auto input = getInput();
    Nodes nodes;
    if (!isInputValid(input)) {
        std::cout << "E1";
        return 0;
    }
    if (!createTree(input, nodes)) { // create tree if we have no duplicate edges
        std::cout << "E2";
        return 0;
    }
    if (!isTreeBinary(nodes)) {
        std::cout << "E3";
        return 0;
    }
    auto rootNodes = getRootNode(nodes);
    int numRoot = static_cast<int>(rootNodes.size());
    if (numRoot > 1) {
        std::cout << "E4";
        return 0;
    }
    char root = getRoot(rootNodes);
    if (numRoot == 0 || doesTreeHaveCycles(nodes, root)) {
        std::cout << "E5";
        return 0;
    }
    printTree(nodes, root);
    return 0;
}

string getInput() {
    string input, throwaway;
    if (!getline(std::cin, input)) return INVALID_INPUT;
    if (getline(std::cin, throwaway)) return INVALID_INPUT;
    return input;
}

bool isInputValid(string &input) {
    return input != INVALID_INPUT && std::regex_match(input, std::regex(R"(^(\([A-Z],[A-Z]\) )*\([A-Z],[A-Z]\)$)"));
}

// create Tree node and return true if we don't have any duplicates
bool createTree(string &input, Nodes &nodes) {
    int n = static_cast<int>(input.length());
    for (char c: input) {
        // find new valid characters and make nodes
        if (c >= 'A' && c <= 'Z' && nodes.count(c) == 0) {
            nodes[c] = TreeNode(c);
        }
    }
    for (int i = 0; i < n; i++) {
        char p = input[i]; // parent node
        // Skip invalid, because string is validated
        if (p < 'A' || p > 'Z') continue;
        i += 2; // skip in between ","
        char c = input[i]; // child node;

        // If nodes was not added we have a duplicate
        if (!nodes[p].addChild(c)) {
            return false;
        }
    }

    return true;
}

/* Check all nodes and make sure we have a max of two children */
bool isTreeBinary(const Nodes &nodes) {
    return std::all_of(nodes.begin(), nodes.end(), [](const auto &node) { return node.second.children.size() <= 2; });
}

unordered_set<char> getRootNode(const Nodes &nodes) {
    unordered_set<char> rootNodes;
    /* Initialize map */
    for (auto &node: nodes) {
        rootNodes.insert(node.first);
    }
    /* If node has a parent it cannot be a root, but not counting self loop */
    for (auto &node: nodes) {
        for (auto child: node.second.children) {
            if (child != node.first && rootNodes.find(child) != rootNodes.end()) rootNodes.erase(child);
        }
    }
    return rootNodes;
}

char getRoot(const unordered_set<char> &rootNodes) {
    for (auto c: rootNodes) {
        return c;
    }
    return 0;
}

// Do DFS to check for cycle
bool doesTreeHaveCycles(const Nodes &nodes, char root) {
    unordered_set<char> visited;
    stack<char> s;
    s.push(root);
    while (!s.empty()) {
        char cur = s.top();
        s.pop();
        if (visited.find(cur) != visited.end()) return true;
        visited.insert(cur);
        for (const auto &c: nodes.at(cur).children) {
            s.push(c);
        }
    }
    return false;
}

void printTree(const Nodes &nodes, char cur) {
    cout << "(" << nodes.at(cur).val;
    vector<char> children(nodes.at(cur).children.begin(), nodes.at(cur).children.end());
    if (!children.empty()) sort(children.begin(), children.end());
    for (auto c: children) printTree(nodes, c);
    cout << ")";
}