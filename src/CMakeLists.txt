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
foundation/db/CppSQLite3.cpp
foundation/db/sqlite3.c
foundation/messaging/Message.cpp
foundation/messaging/MessagePort.cpp
foundation/timing/linux/LinuxTimer.cpp
)

SET(Mada_MADA_SRCS
mada/Game.cpp
mada/GameServer.cpp
mada/MasterTime.cpp
mada/game/Component.cpp
mada/game/FeatureServer.cpp
mada/game/GameObject.cpp
mada/game/GameState.cpp
mada/game/Manager.cpp
mada/game/core/CoreFeatureServer.cpp
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

