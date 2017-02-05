# Boko Runner #

### Description ###

Boko Runner is a C++ OOP project we've done as our DUT second semester's programming project.
It consists in creating a "runner" game (an auto-scrolling platform game) where the player 
has to dodge each obstacles and collect bonuses to increase its score. The game ends when the player's life bar is empty.
The project allowed us to put into practice the Object Oriented Programming notions that we learnt in S2.

Initially made to be based on a Model-View architecture as requested, the project can be considered as 
a Three-Tier Architecture with a DataBase, Models and Views. 

Despite being initially a scholar project ended in May 2016, it is still receiving new features 
and "under the hood" improvements from the repository's owner : Arthur Jolivet.


### Tools used ###

* IDEs : Code::Blocks, QT Creator, CLion(current)
* Language : C++11
* Libraries : SFML & PugiXML


### Authors ###

* Arthur Jolivet - main developer
* Florian Laronze


### Documentation ###

The Doxygen documentation can be found at 
[this address](http://info-timide.iut.u-bordeaux.fr/perso/2017/ajolivet/documentations/BokoRunner/).


### How to build ###

From Project folder do :
  - mkdir build
  - cd build
  - cmake .. && make

*You'll need gcc-4.9/g++-4.9 or higher and some other libs asked by SFML (openal, .


### Licences ###

Our project is mainly licensed under Apache License Version 2.0 but some elements have other licences.
Please take a look at the following paragraphs for more details.


##### Code #####

Our code is licensed under Apache License Version 2.0.
Our project include two libraries contained in /libs folder : 
* PugiXML which is licensed by their creators under MIT Licence.
* SFML which is licensed by their creators under zlib/png license.


##### Images #####

All images are licensed under Apache Licence Version 2.0.
Most of them were created by ourselves or were given by our teachers.
Some of them were made using provided one or were inspired by Material Design (e.g. radios).
The file "shape_buttons.png" incorporates some AOSP icon which are also licensed under Apache License Version 2.0.


##### Audio #####

All audio files are licensed under Apache Licence Version 2.0 apart the following ones which were created by Paul Samra, 
a friend of Florian, under BeerWare licence :
- menu_sound.ogg
- game_normal_sound.ogg
- game_master_sound.ogg


##### Fonts #####

The fonts in /res folder come from Google Fonts. They are licensed under Apache Licence Version 2.0.