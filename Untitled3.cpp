#include <iostream>

using namespace std;

// Fungsi untuk menampilkan papan permainan Tic-Tac-Toe
void displayBoard(char board[3][3]) {
    cout << "  0    1     2\n";
    for (int i = 0; i < 3; i++) {
    	cout<<endl;
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << "  | ";
        }
        cout << endl;
        if(i < 3)cout<< "___________________"<<endl;
        cout<<endl;
    }
}


bool checkWinner(char board[3][3], char player) {
    // Mengecek baris dan kolom
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Mengecek diagonal
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Fungsi untuk mengecek apakah papan sudah penuh (seri)
bool checkTie(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // Papan belum penuh
            }
        }
    }
    return true; // Papan penuh (seri)
}

int main() {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    char currentPlayer = 'x';
    int row, col;

    do {
        // Menampilkan papan permainan
        displayBoard(board);

        // Meminta input dari pemain
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Memeriksa apakah langkah valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Menetapkan langkah pemain ke papan
        board[row][col] = currentPlayer;

        // Memeriksa apakah pemain tersebut menang
        if (checkWinner(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Memeriksa apakah permainan seri
        if (checkTie(board)) {
            displayBoard(board);
            cout << "The game is a tie!" << endl;
            break;
        }

        // Beralih ke pemain berikutnya
        currentPlayer = (currentPlayer == 'x') ? 't' : 'x';

    } while (true);

    return 0;
}

