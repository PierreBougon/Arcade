## install.sh for  in /home/bougon_p/rendu/TEK2/cpp_arcade
## 
## Made by bougon_p
## Login   <bougon_p@epitech.net>
## 
## Started on  Sun Apr  9 10:11:17 2017 bougon_p
## Last update Sun Apr  9 10:12:20 2017 bougon_p
##

#!/bin/bash

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../soundManager/:sfml/dep/SFML-2.4.2/lib:lapin/dep/SFML-2.3/lib
make arcade RELEASE=YES
