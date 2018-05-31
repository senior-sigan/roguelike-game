# Library

## Entity-Component-System

Component - it's just a structure, data holder

Entity = Collection<Component>
    Player = (TransformComponent, ControlComponent, RenderComponent, CollisionComponent, ...)

System - controls Components behaviour. 
For example, MovementSystem controls components for entities which have TransformComponent and ControlComponent

## Events

In a System you can use Events to send info between systems.  
Use `EventSender.Send<MyEvent>(some args)` to send event.
Use `EventListener.RegisterListener<MySystem, MyEvent>(this, &MySystem::MyEventHandler)` to set event listener.