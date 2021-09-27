sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev
cd minilibx-linux
git submodule init
git submodule update
cd ..
make