# Library directories


INCLUDE_DIRECTORIES(
${OGRE_INCLUDE_DIRS}
${MADA_MADA_INCLUDE_DIR}
${MADA_FOUNDATION_INCLUDE_DIR})

SET(Mada_FOUNDATION_SRCS
foundation/core/Factory.cpp
foundation/core/RefCounted.cpp
foundation/core/Rtti.cpp
foundation/core/linux/LinuxSysUtils.cpp
foundation/properties/Property.cpp
foundation/properties/PropertyDefinitionBase.cpp
foundation/properties/PropertyId.cpp
foundation/properties/PropertyTable.cpp
foundation/db/Command.cpp
foundation/db/Database.cpp
foundation/db/DatabaseServer.cpp
foundation/db/DbReader.cpp
foundation/db/sqlite/sqlite3.c
foundation/graphics/GraphicsEntity.cpp
foundation/graphics/GraphicsServer.cpp
foundation/messaging/Message.cpp
foundation/messaging/MessagePort.cpp
foundation/messaging/MessageDispatcher.cpp
foundation/physics/CollisionShapeFactory.cpp
foundation/physics/MotionState.cpp
foundation/physics/PhysicsEntity.cpp	
foundation/physics/PhysicsServer.cpp	
foundation/physics/btogre/BtOgre.cpp
foundation/sound/OggSoundFormat.cpp
foundation/sound/Sound.cpp
foundation/sound/SoundEntity.cpp
foundation/sound/SoundFormat.cpp
foundation/sound/SoundServer.cpp
foundation/sound/WavSoundFormat.cpp
foundation/timing/linux/LinuxTimer.cpp
)

SET(Mada_MADA_SRCS
mada/Game.cpp
mada/GameServer.cpp
mada/MasterTime.cpp
mada/game/base/Component.cpp
mada/game/base/FeatureServer.cpp
mada/game/core/GameObject.cpp
mada/game/base/GameState.cpp
mada/game/base/Manager.cpp
mada/game/core/CategoryManager.cpp
mada/game/core/CoreFeatureServer.cpp
mada/game/core/CoreProperties.cpp
mada/game/core/GameObjectManager.cpp
mada/game/core/GameStateManager.cpp
mada/graphicsfeature/GraphicsFeatureServer.cpp
mada/graphicsfeature/GraphicsProperties.cpp
mada/graphicsfeature/MeshGraphicsComponent.cpp
mada/graphicsfeature/MeshGraphicsManager.cpp
mada/physicsfeature/PhysicsFeatureServer.cpp
mada/physicsfeature/PhysicsProperties.cpp
mada/soundfeature/SoundFeatureServer.cpp
mada/soundfeature/SoundProperties.cpp
)

SET(Mada_LIGHTGAME_SRCS
lightgame/main.cpp
lightgame/LightGame.cpp
)


ADD_EXECUTABLE(light_game ${Mada_LIGHTGAME_SRCS} ${Mada_FOUNDATION_SRCS} ${Mada_MADA_SRCS})

TARGET_LINK_LIBRARIES(light_game ${OGRE_LIBRARIES} alut ${BULLET_LIBRARIES})


INSTALL(TARGETS light_game RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/${BINDIR})

