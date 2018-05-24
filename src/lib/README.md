# Library

## Entity-Component-System

Component - it's just a structure, data holder

Entity = Collection<Component>
    Player = (TransformComponent, ControlComponent, RenderComponent, CollisionComponent, ...)

System - controls Components behaviour. 
For example, MovementSystem controls components for entities which have TransformComponent and ControlComponent

## Event Loop

We need a mechanism to send events without threading. Just put a message or task into the eventLoop.