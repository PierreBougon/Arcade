## install.sh for  in /home/bougon_p/rendu/TEK2/cpp_arcade
## 
## Made by bougon_p
## Login   <bougon_p@epitech.net>
## 
## Started on  Sun Apr  9 10:11:17 2017 bougon_p
## Last update Sun Apr  9 13:16:09 2017 bougon_p
##

#!/bin/bash

echo "export LD_LIBRARY_PATH=\"sfml/dep/SFML-2.4.2/lib:lapin/dep/SFML-2.3/lib:../lib/sfml/dep/SFML-2.4.2/lib\"" >> ~/.bashrc
source ~/.bashrc
make arcade RELEASE=YES
