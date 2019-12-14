# Apocalypse
Rules:

1. Every year a human object can make one randon move vertically, horizontally, or diagonally in the grid.
2. If two Human objects come into contact with one another and are the opposite gender, unmarried, over the age of 18, and uninfected, then they will spawn another Human object on the grid somewhere(randomly assigned gender).
3. Every 10 years another Virus object appears on the grid in a random spot.
4. If a Human object comes into contact with a Virus object then if their immunity value is greater than 0.25 then a number between 0 and 1 will be randomly calculated and subtracted from the Human's immunity value.
5. If a human object comes into contact with a Virus object and if their immunity value is less than 0.25 then they will appear on the grid as ! to signify that they are infected.
6. If randomly generated move from any Human is illegal(not in bounds) then no move is made
7. When the Human object reaches age 65, then their health(initially 10) decreases by .5 each year.
8. When a human is spawned, the spawn will have the combined immunity of the parents.
9. If a human comes into contact with an infected human, they will be attacked just like they would be with a virus (Refer to rules 4 and 5)
10. If a human comes into contact with another human and they are not able to have children, then the human is moved until it finds its own space


Starting Condition: The simulation will start with 10 Humans, age 0 and immunity of 1(5 male and 5 female) and 1 Virus object randomly placed in the grid. Each round of the program will symbolize a year passed.

Stopping Condition: There are no more uninfected humans or the game goes on for 100 years has passed.

Overwritten Operators: Operator(+)- This adds two humans together when the simulation deems them allowed to have children. A human is returned with their combined immunity.
  Operator(==): boolean value returned if the calling human is able to have a baby with the parameterized human.
Description:
