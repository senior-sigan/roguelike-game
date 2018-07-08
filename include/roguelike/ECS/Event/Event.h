/**
 * Created by Илья Сиганов on 31.05.2018.
 */

#ifndef ROGUELIKE_EVENT_H
#define ROGUELIKE_EVENT_H

#include <ECS/Event/IEvent.h>
#include <ECS/Platform.h>
namespace ECS::Event {

template<class TEvent>
class Event : public IEvent {};
}

#endif  // ROGUELIKE_EVENT_H
