#include <vector>
class Solution {
public:

    void sum_row(const std::vector<int>* prev_row, std::vector<int>* curr_row)
    {
        const int prev_size = prev_row->size();
        curr_row->resize(prev_size + 1);
        (*curr_row)[0] = 1;
        for (int i = 0; i < prev_size - 1; i++)
        {
            (*curr_row)[i + 1] = (*prev_row)[i] + (*prev_row)[i + 1];
        }
        (*curr_row)[prev_size] = 1;
        return;
    }

    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> rows(numRows);
        if (numRows == 1)
        {
            rows[0] = {1};
            return rows;
        }
        else if (numRows == 2)
        {
            rows[0] = {1};
            rows[1] = {1, 1};
            return rows;
        }
        rows[0] = {1};
        rows[1] = {1, 1};
        for (int i = 2; i < numRows; i++)
        {
            sum_row(&rows[i - 1], &rows[i]);
        }
        return rows;
    }
};