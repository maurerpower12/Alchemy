# Alchemy
DataStructure assignment to implement a game called Alchemy building upon our 2D templates array. 

# Requirements 
The premise of the game is to turn the grey background squares gold by placing symbols in that specific square. A symbol can only be placed if:

At least one edge is next to another symbol.
The symbol to be placed must either match color or symbol type of all adjacent squares.
The grey square in the screen shot is a wild card and can be placed anywhere on the board.
There is a skull and crossbones symbol that obliterates any one symbol on the board.

Once a row or column is filled, the symbols disappear leaving the squares gold. It is permissible to place symbols in gold squares. The level ends and is advanced to the next level when all squares are gold.

The discard cauldron (pile) only has room for three symbols. Discarding a fourth symbol will end the game. A successful placement removes one of the discard symbols from the cauldron, although you can never have negative symbols in the cauldron.

The score (in your game) is calculated by granting five points for every side a placed symbol touches another symbol.
  
Stipulations
You must use the two dimensional array created in Assignment 3.
Use any symbols you desire but the first level must have five different symbols and five colors. Each level will increase the number of symbols by one as well as the number of colors. The colors are also your choice.
Your game must include at least two levels.
Ignore the Skill Level setting.

Screenshot:
<img src="https://raw.githubusercontent.com/maurerpower12/Alchemy/master/Screen%20Shot%202016-09-27%20at%2010.04.51%20PM.png">
