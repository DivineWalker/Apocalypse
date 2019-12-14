The simulation will start with 10 humans, age 0, initial health of 10 and immunity of 1 (5 male and 5 female). 
When starting the simulation, human objects will be placed randomly on the grid along with one virus object. 
Humans will be represented as H and the virus object will be represented as V. A virus object will appear on the grid in 
a random spot every 10 years. Upon being asked if you wish to continue after every day, the simulation will run accordingly 
until 100 years has passed or their are no more uninfected humans left. Know that every year a human object can make one 
random move vertically, horizontally, or diagonally in the grid. Moves that are generated randomly out of bounds by humans 
is illegal and no move will be made. As the humans move, if two humans come into contact with one another and they are opposite 
genders, on top of being unmarried and over the age of 18, a new human with a randomly assigned gender is spawned on a random 
spot on the grid. If the two humans do not meet the criteria for spawning children, then the human will move until it finds its
own space. Be mindful that the human objects have an immunity value and if a human and a virus object come into contact then their 
immunity, if greater than 0.25,  will be subtracted by a randomized number between 0 and 1. If their immunity is less than 0.25, 
then the human will gain a symbol, !,  that differentiates it from the uninfected humans. Spawned humans do acquire the combined 
immunity of their parents. If a human comes into contact with an infected human, they will be attacked as if they came into contact 
with the virus and will act accordingly as if they have a virus. The humans will age as the simulation continues and once the age of 
65 is reached, their health will decrease by 0.5 each year. 
