# HauntedHouse_Zork
## Introduction

This game has been created as part of the application for the "Advanced Programming for AAA Video Games" master's degree offered by UPC Talents School.

This game is a variation on the Zork game where you must find a way to escape the hunted house, it's has been created to explore the possibilities that the c++ offer us. 

As a person who does not come from a technical background, it has been a new adventure in which I have suffered, especially for those silly mistakes that cause 4999382 errors and many other warnings, but I have also had a lot of fun and I have learned to overcome each silly mistake.

Author: Sandra Campaña

## Goal
The player must find the exit of the haunted house through the creation of a key, these keys will be hidden throughout the house. Can you find them all?

[Room 1 Basement.pdf](https://github.com/csandra24/HauntedHouse_Zork/files/9552334/Room.1.Basement.pdf)


## Final Path *(spoiler alert)*

1. The player is in the basement, here he must take the bag and open it, to get the first key fragment. It is very important that this is done now, because once you go up the stairs, you will not be able to go back down. 
```
pick or take bag
open bag
```

2. Once this is done, proceed to the east and go up the stairs. 
```
go east
go up
```
3. Once in the hall the player will have 3 options to go to: 
```
move or go east -> kitchen
move or go west -> bedroom
move or go north -> Outdoor, where you will need the key to exit.
```
4. To find the rest of the keys, it is necessary to go to the kitchen and take the trash, and open it. Then, you must go back to the hall and go to the bedroom where the last key fragment is. 
```
pick trash
open trash

go east
go west
```
5. Finally, the player must go back out to the hall and craft the key, with the following command:
```
craft key
go north -> Outdoor
```

## Commands
**1. Inventory** - List of player's inventory.

**2. Look** - Description of the room in which the player is located.

**3. End/Quit** - End the game.

**4. Look** - Detailed description.

**5. Move/Go (direction)** - Player movement towards that direction.

**6. Pick/Take/Get (item)** - Add item to player's inventory.

**7.	Drop (item)** - Remove item from player's inventory and leave it on the floor.

**8.  Craft (recipe)** - Remove recipe's items from inventory and add the crafted one.

**9.	Open (container)** - Open any container and put its content in player's inventory.

**10.	Save/Put (item) in (container)** - Removes an object from the player's inventory and adds it to a container, such as a bag.


## License
MIT License

Copyright © 2022

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Github Sandra Campaña: [csandra24](https://github.com/csandra24/HauntedHouse_Zork)
