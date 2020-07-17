#include <iostream>
#include <vector>
using namespace std;

class Deck {
private:
    vector<string> cards;
    int times;
    vector<int> order;
public:
    Deck() {
        cards = {"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
             "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
             "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
             "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13", 
             "J1", "J2"};
    }

    void read() {
        cin >> times;
        int cur;
        for (int i = 0; i < 54; i++) {
            cin >> cur;
            order.push_back(cur);
        }
    }

    void shuffle() {
        for (int j = 0; j < times; j++) {
            vector<string> temp(cards);
            for (size_t i = 0; i < 54; i++) {
                cards[order[i]-1] = temp[i];
            }
        }
    } 

    void print() {
        for (int i = 0; i < 54; i++) {
            cout << cards[i];
            if (i != 53) cout << ' ';
        }
        cout << endl;
    }
};

int main() {
    Deck deck;
    deck.read();
    deck.shuffle();
    deck.print();
    return 0;
}