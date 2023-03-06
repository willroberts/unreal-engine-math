# Unreal Engine Math: Geometry

[Return to Table of Contents](README.md)

## Triangles and Vectors

- 2D and 3D Vectors
    - Vectors have magnitude (length) and direction (angle)
    - Unit vectors (magnitude/length of 1) and unit circles (radius of 1)
    - Vectors on coordinate planes with right triangles are useful (Pythagorean Theorem)
    - Also useful for modeling force in 3D spaces
    - Why Vectors?
        - Faster to compute than angles, since is less computationally expensive than trig
            - Sin, Cos, Tan, Sqrt are computationally expensive compared to Vector addition
    - Operations
        - Vector addition solves end result of two transforms: < 3 5 > + < -1 -1 > = < 2 4 >
        - Vector multiplication can be used for scaling the magnitude of the vector (scalar multiplication)
        - Vector subtraction 
    - More operations

- Vector Dot Product: Yields a scalar value, can calculate angles without trigonometry
    - Especially useful with unit vectors, since you can ignore length in formulas below to simply get the angle
    - A = < 1 2 3 >
    - B = < 4 5 6 >
    - A ⋅ B = 1*4 + 2*5 + 3*6 = 32
    - Alternative: A ⋅ B = len(A) * len(B) * cos(Theta)
        - To determine angle between vectors (Theta): cos(Theta) = (A ⋅ B) / (len(A) * len(B))
        - Invert cos() with acos() or sometimes acos2(), which has DivByZero guards, to yield Radians
    - Dot product of orthogonal vectors is always zero (90 degrees is pi/2 radians, and cos(pi/2)==0)

- Vector Cross Product: Yields an orthogonal vector to the plane containing input vectors. Especially useful in physics.
    - A = < 1 2 3 >
    - B = < 4 5 6 >
    - A ⨯ B = [ i j k ]
              [ 1 2 3 ]
              [ 4 5 6 ]
    - Now find determinant: A ⨯ B = -3i + 6j - 3k
        - New vector is < -3 6 -3 >
    - Cross product of same vector is always zero: A ⨯ A = 0
    - Parallel vectors also have cross product of zero, since they share angles
    - Cross Product can find area of parallelogram formed by two vectors:
           >--->
          /   /
         /   /
        ---->
        - Left and right are Vector A, top and bottom are Vector B
        - A ⨯ B = Area

## Vectors in Unreal Engine

[FVector](https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FVector/): A vector in 3D space with float components X, Y, and Z.

Cross products and dot products are implemented as Blueprint nodes.

## Linear Transformation of Vectors

- Linear transformations in Vector spaces
    - Sometimes called linear maps or mappings
    - Useful for expanding, compacting, reflecting, rotating, or shifting coordinate systems
    - Linear transformation: L(V) = b, similar to function transformation f(x) = a
    - Linear transformations can change dimensions of Vectors, e.g. 2x2 Matrix to Vec<3> or Vec<2> to Scalar
    - In other words, LTs map one vector space V to another vector space W (L:V->W)
    - LTs can be represented as a matrix L(V) = A*V, where A is an m*n matrix
        - As an example, L(V) = [     b ]
                                [ a + b ]
                                [ a - b ]
            - Standard basis Vector2:
                [ 1 ] [ 0 ] (top row is value a)
                [ 0 ] [ 1 ] (bottom row is value b)
            - Transformed by L(V):
                [ 0 ] [  1 ]
                [ 1 ] [  1 ]
                [ 1 ] [ -1 ]
            - Matrix A (from L(V)):
                [ 0  1 ]
                [ 1  1 ]
                [ 1 -1 ]
            - Putting it all together: L(V) = A*V
            Multiply rows of first matrix by columns of second matrix, then add the products
                - A*V = [ 0*a +  1*b ] = Same representation as L(V)
                        [ 1*a +  1*b ]
                        [ 1*a + -1*b ]

## Linear Transformations in Unreal Engine

Blueprint: Transform Vector node

## Linear Interpolation

AKA Lerp, RinterpTo