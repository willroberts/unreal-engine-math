# Unreal Engine Math: Vectors

[Return to Table of Contents](README.md)

## Vectors

A Vector is a physical property which has both magnitude (length) and direction (angle). A "Unit Vector" is a Vector with a magnitude/length of 1. 

Vectors are useful for modeling positions on a coordinate plane, force in 3D spaces, and more. Vectors are commonly used in game development, since basic Vector math is generally less computationally expensive than Trigonometric functions like `sin()` and `cos()`.

When used on a coordinate plane, Vectors inherently form right triangles from the origin. This can be combined with the Pythagorean Theorem to determine the distance between two points.

## Basic Vector Operations

Vector addition and subtraction are straightforward, and can be used to determine the end result of two transforms:

```text
V1 = <  3  5 >
V2 = < -1 -1 >

V1 + V2 = < 2 4 >
```

Vector multiplication is similarly straightforward, and can be used to scale the magnitude of a Vector:

```text
V1 = < 5 5 >
V2 = < 2 2 >

V1 * V2 = < 10 10 >
```

## Vector Dot Products

The Vector Dot Product (i.e. `V1 ⋅ V2`) is used to calculate angles without trigonometry.

The Dot Product of orthogonal Vectors is always `0`, since 90 degrees is `π/2` Radians, and `cos(π/2) = 0`.

Multiplying two Vectors with the Dot Product produces a Scalar value:

```text
V1 = < 1 2 3 >
V2 = < 4 5 6 >

V1 ⋅ V2 = 1*4 + 2*5 + 3*6 = 32
```

Alternatively, the Dot Product can be expressed as a function of length and angles:

```text
V1 ⋅ V2 = len(V1) * len(V2) * cos(Theta)
```

Or (rearranged to prioritize the angle):

```text
V1 ⋅ V2 / (len(V1) * len(V2)) = cos(Theta)
```

The formula is simpler when dealing with Unit Vectors, since the length of each Vector is 1:

```text
V1 ⋅ V2 = cos(Theta)
```

This can be inverted with the `acos()` function to yield the angle in Radians.

## Vector Cross Products

The Vector Cross Product (i.e. `V1 ⨯ V2`) is used to find a Vector orthogonal to the plane containing the input Vectors.

This is especially useful in Physics, when working with Force or Torque. The Vector Cross Product can also be used to measure the area of the parallelogram formed by two vectors.

The Cross Product of identical Vectors (i.e. `V1 ⨯ V1`) is always zero. Parallel vectors also have cross product of zero, since they share angles.

To find a Vector's Cross Product, create a Matrix containing variables `i`, `j`, and `k`, as well as the two input Vectors:

```text
V1 = < 1 2 3 >
V2 = < 4 5 6 >

V1 ⨯ V2 = [ i j k ]
          [ 1 2 3 ]
          [ 4 5 6 ]
```

Then find the determinant of the Matrix:

```text
det(V1 ⨯ V2) = i*(2*6 + 3*5) - j*(1*6 + 3*4) + k*(1*5 + 2*4) = 27i - 18j + 13k
```

The result forms a new Vector, which is the Cross Product:

```text
< 27 -18 13 >
```

## Vectors in Unreal Engine

[`FVector`](https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FVector/): A vector in 3D space with float components X, Y, and Z.

Given a `FVector&` reference in Unreal C++, cross and dot products can be obtained from the [`CrossProduct`](https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FVector/CrossProduct/) and [`DotProduct`](https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FVector/DotProduct/) static functions, respectively. Blueprint nodes also exist for these operations. As with Matrices, basic math operations can be used on `FVector` instances in C++, e.g. `V1 + V2`.

There are also [`FVector4`](https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FVector4/) (W, X, Y, and Z) and [`FVector2D`](https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FVector2D/) (X and Y) classes available.

## Linear Transformation of Vectors

Linear transformations in Vector spaces, sometimes called linear maps since they map one Vector space to another Vector space, are useful for expanding, compacting, reflecting, rotating, or shifting coordinate systems.

Like function transformations, e.g. `f(x) = y`, linear transformations can operate on Vectors, e.g. `L(V) = W`. Linear transformations can change the dimensions of Vectors, such as turning a 2x2 Matrix into a 3-component Vector, or turning a 2-component Vector into a Scalar.

Linear transformations can be represented as `L(V) = A*V`, where `A` is an `m*n` Matrix. As an example, we can transform 2-component Vectors into 3-component Vectors, where `a` and `b` are the input Vector's components:

```text
L(V) = [     b ]
       [ a + b ]
       [ a - b ]

V1 = < 1 0 >
L(V1) = [ 0 ]
        [ 1 ]
        [ 1 ]

V2 = < 0 1 >
L(V2) = [  1 ]
        [  1 ]
        [ -1 ]
```

## Linear Transformation in Unreal Engine

[`FTransform`](https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FTransform/): A transform composed of scale, rotation (as a quaternion), and translation.

https://docs.unrealengine.com/4.27/en-US/Basics/Actors/Transform/#worldandlocaltransformationmodes

https://docs.unrealengine.com/5.1/en-US/transforming-actors-in-unreal-engine/

To set an Actor's transform, use [SetActorTransform](https://docs.unrealengine.com/5.1/en-US/API/Runtime/Engine/GameFramework/AActor/SetActorTransform/), or [SetActorRelativeTransform](https://docs.unrealengine.com/5.1/en-US/API/Runtime/Engine/GameFramework/AActor/SetActorRelativeTransform/) to target the Actor's Root Component.

To apply a delta to the Actor's existing transform, use []() to transform according to local space (based on the Actor's orientation), or []() to transform according to world space (based on the world's orientation).


https://docs.unrealengine.com/5.1/en-US/API/Runtime/Engine/GameFramework/AActor/AddActorLocalTransform/
https://docs.unrealengine.com/5.1/en-US/API/Runtime/Engine/GameFramework/AActor/AddActorWorldTransform/

Sweep (Collision) and Teleport (Physics)

Blueprint: Transform Vector node

For additional info, see [Transforming Actors in Unreal Engine](https://docs.unrealengine.com/5.1/en-US/transforming-actors-in-unreal-engine/).

## Linear Interpolation

AKA Lerp

## Linear Interpolation in Unreal Engine

RinterpTo