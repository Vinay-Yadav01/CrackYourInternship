class Spreadsheet {
private:
    int rows;
    vector<vector<int>> sheet; 
    int getCellValue(const string &token) {
        if (isalpha(token[0])) {
            int col = token[0] - 'A';
            int row = stoi(token.substr(1)) - 1; 
            return sheet[row][col];
        }
        return stoi(token);
    }
    
public:
    Spreadsheet(int rows) : rows(rows) {
        sheet = vector<vector<int>>(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        sheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        sheet[row][col] = 0;
    }
    
    int getValue(string formula) {
        string exp = formula.substr(1);
        size_t pos = exp.find('+');
        string token1 = exp.substr(0, pos);
        string token2 = exp.substr(pos + 1);
        return getCellValue(token1) + getCellValue(token2);
    }
};

