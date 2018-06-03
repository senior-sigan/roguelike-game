/**
 * Created by Илья Сиганов on 03.06.2018.
 */

#include <ECS/EntityManager.h>
#include <ECS/SystemManager.h>

namespace ECS {
SystemManager::SystemManager(EntityManager *entityManager,
                             Event::EventDispatcher *eventDispatcher,
                             IEngineControl *engineControl1) :
    entityManager(entityManager), eventDispatcher(eventDispatcher), engineControl(engineControl1) {}

SystemManager::~SystemManager() {
    container.clear();
}

void SystemManager::Update(double delta) {
    // TODO: iterate over systems with some order which is set by priority property.

    for (std::pair<SystemTypeID, ISystem *> system: container) {
        system.second->SysUpdate(delta);
    }

    for (auto entity : entityManager->container) {
        for (std::pair<SystemTypeID, ISystem *> system: container) {
            if (system.second->FamilyFilter(entity.second)) {
                system.second->PreUpdate(entity.second, delta);
            }
        }
    }

    for (auto entity : entityManager->container) {
        for (std::pair<SystemTypeID, ISystem *> system: container) {
            if (system.second->FamilyFilter(entity.second)) {
                system.second->Update(entity.second, delta);
            }
        }
    }

    for (auto entity : entityManager->container) {
        for (std::pair<SystemTypeID, ISystem *> system: container) {
            if (system.second->FamilyFilter(entity.second)) {
                system.second->PostUpdate(entity.second, delta);
            }
        }
    }
}
}