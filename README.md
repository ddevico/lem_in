# lem_in

Shortest path problem project for École 42. The goal is to get n ants across an anthill in the least number of turns possible.
Each ant can move once per turn and only one ant is allowed in each node of the graph unless it's the start or end.

The description of an anthill is given via stdin in the following format:

    3
    ##start
    a 23 3
    2 16 7
    #commentaire
    3 16 3
    4 16 5
    5 9 3
    6 1 5
    7 4 8
    ##end
    0 9 5
    0-4
    0-6
    a-3
    4-3
    5-2
    2-5
    3-5
    #autre commentaire
    4-2
    2-a
    7-6
    7-2
    7-4
    6-5

where:

The number in the first line is the number of ants
'a 23 3' represents a "house" in the anthill with name 'a' and coordinates 23, 3
##start and ##end indicate that the following "house" is the start or end
lines starting with # are coments
lines in the format a-b represent a connection between a and b

### Start the program

- ```Make```
- ```./lem_in [test/*] ```


