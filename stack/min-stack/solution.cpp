class MinStack {
public:
    struct Node{
        int val;
        int min_val;
        Node* prev;
        Node(int x) {
            val = x;
            min_val = x;
            prev = NULL;
        }
    };
    Node* top_node;
    MinStack() {
        top_node = NULL;
    }
    ~MinStack() {
        while(top_node != NULL) {
            Node* node = top_node->prev;
            delete top_node;
            top_node = node;
        }
    }
    void push(int x) {
        if(top_node == NULL) {
            top_node = new Node(x);
        }
        else {
            Node* node = new Node(x);
            node->min_val = min(x, top_node->min_val);
            node->prev = top_node;
            top_node = node;
        }
    }

    void pop() {
        if(top_node == NULL) {
            return;
        }
        Node* node = top_node;
        if(node->prev != NULL)
            top_node = node->prev;
        else
            top_node = NULL;
        delete node;
    }

    int top() {
        return top_node->val;
    }

    int getMin() {
        return top_node->min_val;
    }
};