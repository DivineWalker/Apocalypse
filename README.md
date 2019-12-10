# Apocalypse
Rules:

1. Every year a human object can make one randon move vertically, horizontally, or diagonally in the grid.
2. If two Human objects come into contact with one another and are the opposite gender, unmarried, and over the age of 18 then they will spawn another Human object on the grid somewhere(randomly assigned gender).
3. Every 10 years another Virus object appears on the grid in a random spot.
4. If a Human object comes into contact with a Virus object then if their immunity value is greater than 0.25 then a number between 0 and 1 will be randomly calculated and subtracted from the Human's immunity value.
5. If a human object comes into contact with a Virus object then if their immunity value is less than 0.25 then they will disappear from the grid
6. If randomly generated move from any Human is illegal(not in bounds) then no move is made
7. When the Human object reaches a certain age, their health decreases 
8. Immunity of the Human object can increase after every year by 0.1 after the age of 20 and then goes up by 0.2 and consectively each year
9. Spawned Human Object will have the combined immunity of its Parents when born
10. 

Starting Condition:
Stopping Condition: The grid, 10x10, is filled up for 1000 years has passed
Overwritten Operators: Operator(=)- if two objects come into contact and meet the criteria then another Human object will be spawned. 
Human Object Attributes: Age, marriage, health, 
Virus Object Attributes:
Description:
