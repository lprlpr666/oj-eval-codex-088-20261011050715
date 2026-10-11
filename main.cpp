#include <bits/stdc++.h>

using namespace std;

// Simple singly linked list node
struct Node {
    long long val;
    Node* next;
    Node(long long v) : val(v), next(nullptr) {}
};

// Solve subtask 1: simulate using manual linked list and output the first card after each round.
void solve_subtask1(long long n) {
    if (n <= 1) return; // no output needed

    // Build initial list 1..n
    Node* head = new Node(1);
    Node* tail = head;
    for (long long i = 2; i <= n; ++i) {
        tail->next = new Node(i);
        tail = tail->next;
    }

    // Perform n-1 rounds
    for (long long round = 1; round <= n - 1; ++round) {
        // Step 1: move first card to the end
        Node* moveNode = head;
        head = head->next;               // new head
        moveNode->next = nullptr;
        tail->next = moveNode;           // append at tail
        tail = moveNode;

        // Step 2: discard the new first card
        Node* discard = head;
        head = head->next;
        delete discard;

        // After the round, output the first card's value
        if (head) {
            cout << head->val << "\n";
        }
    }

    // Clean up remaining list
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

// Solve subtask 2: compute the last remaining card directly.
long long solve_subtask2(long long n) {
    // The process moves the first card to the end, then discards the new first card.
    // The final remaining card follows the pattern: 1,1,3,1,3,5,7,1,...
    // Derivation leads to: result = 2 * (n - 2^{⌊log2 n⌋}) + 1
    if (n <= 0) return 0;
    // highest power of two <= n
    long long p = 1LL << (63 - __builtin_clzll(n));
    return 2 * (n - p) + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long id, n;
    if (!(cin >> id >> n)) return 0;

    if (id == 1) {
        solve_subtask1(n);
    } else if (id == 2) {
        cout << solve_subtask2(n) << "\n";
    }
    return 0;
}
