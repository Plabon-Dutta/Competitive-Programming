struct node {
    bool end;
    node* next[27];
    node() {
        end = false;
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
} *root;

void insert(string str) {
    node* curr = root;
    int len = str.size();
    for(int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if(curr -> next[id] == NULL) {
            curr -> next[id] = new node();
        }
        curr = curr -> next[id];
    }
    curr -> end = true;
}

bool search(string str) {
    int len = str.size();
    node* curr = root;
    for(int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if(curr -> next[id] == NULL) return false;
        curr = curr -> next[id];
    }
    return curr -> end;
}

void del(node* curr) {
    for (int i = 0; i < 26; i++) {
        if (curr -> next[i]) {
            del(curr -> next[i]);
        }
    }
    delete(curr);
}
