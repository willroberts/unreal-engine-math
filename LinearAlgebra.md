# Unreal Engine Math: Linear Algebra

[Return to Table of Contents](README.md)

- Linear Algebra
    - Systems of Linear Equations: Solving multiple Linear Equations by finding their linear intersection
        - Can be 2D lines or 3D planes
        - "Consistent" systems intersect, "Inconsistent" systems don't

    - Matrices: Useful for representing 4+ dimensions
        - 3D example: 7x+5y-3z=16; 3x-5y+2x=-8; 5x+3y-7z=0
        - Coefficient matrix contains only coefficients of above linear equeations (m * n matrix; m=equations; n=variables):
            [ 7, 5, -3 ]
            [ 3, -5 ,2 ]
            [ 5, 3, -7 ]
        - Augmented matrix contains equivalent terms (m * n+1 augmented matrix; +1 is solution column):
            [ 7, 5, -3 : 16]
            [ 3, -5, 2 : -8]
            [ 5, 3, -7 : 0]
        - Gauss-Jordan Elimination: Simplifying equations by dividing or creating new matrix rows by addition to solve systems
            - Try to reduce at least one column to zero, and ideally 1s in other columns
        - Matrix multiplication: Multiply rows of first matrix by columns of second matrix, then add the products
            [ 1 2 ] x [ 5 6 ] => [ 19 22 ]
            [ 3 4 ]   [ 7 8 ]    [ 43 50 ]
            - Multiplied matrices need not be identical. Result will have numRows from first matrix, and numColumns from second matrix.
        - Determinant of square matrix: characterizes matrix properties and linear map representation
            - det(M)=0 when matrix is invertible and linear map is isomorphic.
            - 2x2 matrix is simple:
                A = [ a b ]
                    [ c d ]
                det(A) = | a b | = ad = bc
                         | c d |
            - 3x3 matrix or larger breaks out terms by "ignoring" rows and columns of coefficient, with form det(M) = x - y + z
                B = [ a1 a2 a3 ]
                    [ b1 b2 b3 ]
                    [ c1 c2 c3 ]
                det(B) = a1 * | b2 b3 | - a2 * | b1 b3 | + a3 * | b1 b2 |
                              | c2 c3 |        | c1 c3 |        | c1 c2 |