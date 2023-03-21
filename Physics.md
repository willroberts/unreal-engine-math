# Unreal Engine Math: Physics

[Return to Table of Contents](README.md)

## Kinematic Equations

Kinematics, in Physics, is the process of describing the motion of points, bodies, or systems in space. In particular, many applications of Kinematics are concerned with velocity, acceleration, and speed.

There is a set of Kinematic Equations we can use to determine the magnitude and result of motion. These Equations are concerned with the following variables:

```text
Δx: displacement delta
t: time interval
v0: initial velocity
v: final velocity
a: constant acceleration
```

Note that Kinematic formulas are only applicable with constant acceleration. If acceleration is dynamic, the formulas will not be accurate.

There are four Kinematic Equations we can use to determine these values if we have access to the missing variables:

```text
Determine final velocity without access to distance:
v = v0 + (a * t)

Determine displacement without access to acceleration:
Δx = ((v + v0) / 2) * t

Determine displacement without access to final velocity:
Δx = (v0 * t) + ((a * t**2) / 2)

Determine final velocity without access to time:
v ** 2 = (v0 ** 2) + (2 * a * Δx)
```

These formulas can also be used to solve for acceleration, time, etc. by isolating those variables.

## Kinematics in Unreal Engine

In Unreal Engine, Kinematics are used for Actor motion, and are useful in game logic when dealing with velocity, acceleration, or displacement.

You will also see the term "Kinematics" come into play with characters when working with systems like [Inverse Kinematics](https://docs.unrealengine.com/4.27/en-US/AnimatingObjects/SkeletalMeshAnimation/IKSetups/) for rigging. However, this is referring not to Kinematic equations, but to the new UE5 rig systems which allow the engine to intelligently transform a skeleton when a World object is displacing bones in a pose (such as when a skeleton is standing with one leg on an elevated object).

Unreal Engine also uses the term "Kinematic" when setting the "Physics Type" on bones in a Skeleton. This functionality disables Physics simulation on the affected bones, while allowing attached bones to continue simulating Physics. For more info, see [Using Kinematic Bodies with Simulated Parents](https://docs.unrealengine.com/4.27/en-US/InteractiveExperiences/Physics/PhysicsAssetEditor/HowTo/KinematicWithSimulatedParents/).