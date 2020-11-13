#include <iostream>
#include <stdio.h>
#include <vector>
using std::vector;
using std::cout;
using std::endl;


class Node
{
    public:
        int idx;
        Node * addr = nullptr;
        Node * parent_addr = nullptr;
    
        Node (int init_idx, Node * init_parent) {
            idx = init_idx;
            parent_addr = init_parent;
        }
};

void PrintNode(Node & n) {
    cout << "idx: " << n.idx << " addr: " << n.addr << " parent_addr: " << n.parent_addr << endl;
}

void PrintNodeList (vector<Node> & path) {
    for (Node n : path) {PrintNode(n);}
}

void CreateNodeList (const int node_count, vector<Node> & node_list) {
    for (int i=0; i<=(node_count - 1); i++) {
        if (i==0) {
            //  first node parent is null
            node_list.push_back(Node(i, nullptr));
        } else {
            // subsequent nodes parent is previous node
            node_list.push_back(Node(i, &node_list[i-1]));
        }
        // store address of node to clearly follow forward and reverse traversals
        node_list[i].addr = &node_list[i];
    }
    cout << "Node List..." << endl;
    PrintNodeList(node_list);
}

void ConstructFinalPathSimplified(Node * current_node) {
    cout << endl << "Traversing node list in reverse..." << endl;
    while (current_node != nullptr) {
        PrintNode(*current_node);
        current_node = current_node->parent_addr;
    }
    cout << endl << "Completed reverse traversal." << endl;
}

int main() {
    // generate list of nodes
    const int node_count = 5;
    vector<Node> node_list;
    CreateNodeList (node_count, node_list);
        
    // reverse traverse the list of nodes
    const int last_node = node_count - 1;
    ConstructFinalPathSimplified(&node_list[last_node]);
    
    return 0;
}
