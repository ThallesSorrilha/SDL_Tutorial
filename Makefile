all:
	g++ source/main.cpp source/Game.cpp source/TextureManager.cpp source/GameObject.cpp source/Map.cpp source/InputHandler.cpp source/Player.cpp source/Enemy.cpp source/Animation.cpp source/Control.cpp source/Vector2D.cpp source/Physics.cpp source/Dimension.cpp source/Collision.cpp source/Timer.cpp -o executable/main.exe `sdl2-config --cflags --libs` -lSDL2_image
	./executable/main.exe