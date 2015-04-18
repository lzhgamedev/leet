class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        width = board[0].size();
        height = board.size();
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                if(dfsCheck(i, j, 0, word, board))
                  return true;
            }
        }
        return false;
    }
private:
    int width;
    int height;
    bool dfsCheck(int i, int j, int word_index, string& word, vector<vector<char> > &board) {
        if(!inBoard(i, j) || board[i][j] != word[word_index] || board[i][j] == '\0') {
            return false;
        }
        if(word_index == word.size() - 1)
            return true;
            
        char t = board[i][j];
        board[i][j] = '\0';
        if(dfsCheck(i+1, j, word_index+1, word, board) ||
            dfsCheck(i-1, j, word_index+1, word, board) ||
            dfsCheck(i, j-1, word_index+1, word, board) ||
            dfsCheck(i, j+1, word_index+1, word, board))
            return true;
        board[i][j] = t;

        return false;
    }
    bool inBoard(int i, int j) {
        if(i >= 0  && i < height &&
            j >= 0 && j < width) {
            return true;
        }
        return false;
    }
};