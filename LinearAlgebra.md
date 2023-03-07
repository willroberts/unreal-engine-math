# Unreal Engine Math: Linear Algebra

[Return to Table of Contents](README.md)

## Systems of Linear Equations

Systems of Linear Equations solve multiple Linear Equations by attempting to find their linear intersection. "Consistent" Systems intersect, while "inconsistent" Systems do not.

These Systems can represent 2D lines, 3D planes, or more dimensions with Matrices.

As a basic example, consider the following System of Linear Equations:

```text
2x + y = 5
-x + y = 2
```

Solving these yields `x = 1` and `y = 3`, which is the coordinate pair (`(1,3)`) of the linear intersection of these equations.

## Matrices

As Systems of Linear Equations grow in number of Equations and Terms, Matrices provide a simplified way of solving these Systems.

As an example, consider the following System of Linear Equations:

```text
7x + 5y - 3z = 16
3x - 5y + 2z = -8
5x + 3y - 7z = 0
```

We can represent this as a Coefficient Matrix, which only contains coefficient values from the above equations:

```text
[ 7  5 -3 ]
[ 3 -5  2 ]
[ 5  3 -7 ]

Note: This is not 3 Vectors, but a single Matrix. The brackets repeating on each line is a Markdown limitation.
```

The above Matrix can be described as a 3 x 3 Matrix, using the `m` x `n` naming pattern, where `m` refers to the number of equations in the System, and `n` refers to the number of variables present.

An Augmented Matrix (`m` x `n+1`) also contains the solutions to each equation, sometimes separated by a dotted line:

```text
[ 7  5 -3 : 16 ]
[ 3 -5  2 : -8 ]
[ 5  3 -7 :  0 ]

Note: `:` characters serve as the dotted line here. Further examples will omit the line.
```

## Solving Matrices with Gauss-Jordan Elimination

This method of solving Matrices involves simplifying equations by dividing terms, or creating new matrix rows by addition. The goal is to reduce at least one column's value to `0`, and ideally to have `1` values in other columns.

As an example, consider the following System of Linear Equations:

```text
4x + 6y = -2
5x - 3y =  8
```

And in Matrix form:

```text
[ 4  6 -2 ]
[ 5 -3  8 ]
```

We can linearly scale any equation by multiplaying or dividing each side by the same value. For example, divide the first equation's terms by 2:

```text
[ 2  3 -1 ]
[ 5 -3  8 ]
```

We can then add or subtract any two equations in the System to create a new equation which is part of the same System. Adding the equations together and replacing the second equation with the result produces a new matrix:

```text
[ 2 3 -1 ]
[ 7 0  7 ]
```

The second equation now represents `7x + 0y = 7`, which can be reduced to `x = 1`. The System can now be solved by reducing `2(1) + 3y = -1` to `y = -1`.

An example C++ implementation of Gauss-Jordan Elimination on a 3x3 Matrix can be seen [here](Source/GaussJordanElimination/GaussJordanElimination.cpp).

## Matrix Multiplication

Matrix multiplication is useful in linear transformations of vectors, for rotation or other purposes.

To perform Matrix multiplications, multiply the row values of the first matrix by the column values of the second matrix, then sum the resulting products:

```
[ 1 2 ] x [ 5 6 ] => [ (1*5)+(2*7) (1*6)+(2*8) ] => [ 19 22 ]
[ 3 4 ]   [ 7 8 ]    [ (3*5)+(4*7) (3*6)+(4*8) ]    [ 43 50 ]
```

Multiplied Matrices don't need to be identical in size. When multiplying differently-sized Matrices, the result will have the number of rows from the first matrix, and the number of columns from the second matrix.

## Determinants of Square Matrices

Given a transformation represented by a Square Matrix, the determinant of that Matrix is a Scalar value which characterizes properties of the Matrix, as well as its linear transform representation. This can give insight into whether a Linear System of Equations can be solved, whether Vectors are linearly dependent, whether a Vector's basis is consistent with or opposite to the standard basis, or what kind of volume a shape will have following transformation by a Matrix.

When the determinant of a Matrix is nonzero, the Matrix is invertible, and the original state can be restored. When the determinant of a Matrix is zero, the result of the transform will have no area/volume, such as transforming a shape into a point or line.

To find the determinant, each value is multiplied by the values not in the same row or column before summing the results. For example, with a 2x2 Matrix:

```text
A = [ a b ]
    [ c d ]

det(A) = ad - bc

B = [ 1 2 ]
    [ 3 4 ]

det(B) = 1*4 - 2*3 = -2
```

With a 3x3 Matrix, the same principle applies with more terms. Instead of multiplying individual values, we multiply values by the determinants of the values not in the same row or column:

```text
C = [ 1 2 3 ]
    [ 4 5 6 ]
    [ 7 8 9 ]

det(C) = 1*(5*9 - 6*8) - 2*(4*9 - 6*7) + 3*(5*7 - 4*8) = 18
```

Notice that the third term here is added instead of subtracted. The operators will alternate (-, +, -, +, etc.) for each added term.

## Matrices in Unreal Engine

[`FMatrix`](https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FMatrix/): A 4x4 Matrix of float values. `FMatrix` can be initialized with any size; 4x4 is the default since translation transformations require a 4x4 Matrix and a 1x4 Vector.

Given two `FMatrix&` references `A` and `B` in Unreal C++, you can simply use `A + B`, `A * B`, etc. to perform Matrix math. `FMatrix` also has a `Determinant()` function, which returns a `float` Scalar value.

If you only wish to perform Vector rotation rather than scaling or translation, there is a simpler subclass of `FMatrix` called [`FRotationMatrix`](https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FRotationMatrix/), which constructs an `FMatrix` from an [`FRotator`](https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FRotator/) of Pitch, Roll, and Yaw values.

Matrix math operations, such as addition, multiplication, transforms, and determinants, are also available as Blueprint nodes implemented in C++.