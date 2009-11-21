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
foundation/db/sqlite/CppSQLite3.cpp
foundation/db/sqlite/sqlite3.c
foundation/messaging/Message.cpp
foundation/messaging/MessagePort.cpp
foundation/timing/linux/LinuxTimer.cpp
)

SET(Mada_MADA_SRCS
mada/Game.cpp
mada/GameServer.cpp
mada/MasterTime.cpp
mada/game/base/Component.cpp
mada/game/base/FeatureServer.cpp
mada/game/base/GameObject.cpp
mada/game/base/GameState.cpp
mada/game/base/Manager.cpp
mada/game/core/CoreFeatureServer.cpp
mada/game/core/CoreProperties.cpp
mada/game/core/GameStateManager.cpp
mada/graphics/GraphicsFeatureServer.cpp
mada/graphics/MeshGraphicsComponent.cpp
)

SET(Mada_LIGHTGAME_SRCS
lightgame/main.cpp
lightgame/LightGame.cpp
)


ADD_EXECUTABLE(mada_app ${Mada_LIGHTGAME_SRCS} ${Mada_FOUNDATION_SRCS} ${Mada_MADA_SRCS})

TARGET_LINK_LIBRARIES(mada_app ${OGRE_LIBRARIES})


INSTALL(TARGETS mada_app RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/${BINDIR})

