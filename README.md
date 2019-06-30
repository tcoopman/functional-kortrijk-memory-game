# Functional Kortrijk - Memory game

Use visual studio code with `reason-vscode` plugin

## Run Project

```sh
npm install
npm start
# in another terminal
npm run server
```

View in the browser at http://localhost:8000.

To use a port other than 8000 set the `PORT` environment variable (`PORT=8080 npm run server`).

## Assignment

Implement a memory game (match the picture). The start is already given and it's up to you to complete it.

The rules of the game:

* This should be a 2 player game
* You get to turn 2 cards each turn. 
* If you have found a matching pair this pair should stay visible and the player that turned the pair gets one point. This player keeps his turn.
* If you don't find a matching pair the open cards stay visible for 2 seconds and then turn back. The other player gets the turn.
* If all pairs have been found, the player with the most points wins.

Some helping points:

* There are 25 possible images (see `style.css/sprite-n-n`)

Some possible extensions:

* make the visible time configurable.
* instead of 2 player game, make this configurable, so that many player can join.