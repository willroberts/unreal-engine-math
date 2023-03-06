#include <array>

using namespace std;

// Perform Gauss-Jordan Elimination on a 3x3 Matrix.
void GaussJordanElimination3x3()
{
    const int NumRows = 3;
    const int NumCols = 3;

    // Create a 3x3 Matrix using C++ 11 arrays. Access via Matrix[Row][Col];
    std::array<std::array<float, NumCols>, NumRows> Matrix = {{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    }};

    // Iterate until we finish processing all rows and columns.
    float DiagonalValue = 0;
    for (int CurrentRow = 0; CurrentRow < NumRows; CurrentRow++)
    {
        // Simplify by dividing each non-zero row value by the diagonal value.
        // Results in all rows/columns having a diagonal value of 1.
        DiagonalValue = Matrix[CurrentRow][CurrentRow];
        for (int CurrentCol = 0; CurrentCol < NumCols; CurrentCol++)
        {
            if (Matrix[CurrentRow][CurrentCol] != 0)
            {
                Matrix[CurrentRow][CurrentCol] = Matrix[CurrentRow][CurrentCol] / DiagonalValue;
            }
        }

        // Further simplify by subtracting the product of each value.
        float CurrentValue = 0;
        for (int ComparedRow = 0; ComparedRow < NumRows; ComparedRow++)
        {
            CurrentValue = Matrix[ComparedRow][CurrentRow];
            for (int CurrentCol = 0; CurrentCol < NumCols; CurrentCol++)
            {
                if (ComparedRow != CurrentRow)
                {
                    Matrix[ComparedRow][CurrentCol] = Matrix[ComparedRow][CurrentCol] - (Matrix[CurrentRow][CurrentCol] * CurrentValue);
                }
            }
        }
    }
}