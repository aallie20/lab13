# Polymorphism notes

Answer in your own words. Use the words **static dispatch** and **dynamic dispatch**.

## 1. The non-virtual destructor

What did the sanitizer report when `~Game` was not virtual? Explain which destructor ran and which did not.

When ~Game was not virtual, AddressSanitizer reported a problem when the Arcade deleted game objects through a Game *. With a non-virtual destructor, static dispatch was used, so only the Game destructor ran. The derived destructor (Hangman, Dungeon, Blackjack, or Minesweeper) did not run correctly, which is undefined behavior and can lead to resource leaks. When the destructor is virtual, dynamic dispatch ensures the derived destructor runs first and then the Game destructor.

## 2. Game is abstract

In two sentences, explain why `Game g;` no longer compiles.

Game g; no longer compiles because Game contains the pure virtual function play(). A class with at least one pure virtual function is an abstract class, and abstract classes cannot be instantiated directly

## 3. override

What does `override` protect you from? Give an example of a mistake it catches.

override protects you from accidentally creating a function that does not actually override a base-class virtual function. For example, if the base class declares:

virtual void play();

## 4. Last week versus this week

Repeat the Week 12 experiment: `Game *g = &hangman; g->play();`. What printed last week, and what prints now? Name the kind of dispatch that happened each time.

Last week, Game *g = &hangman; g->play(); called Game::play(), because play() was not virtual. That used static dispatch, where the function call was chosen based on the pointer type (Game *).

This week, Game *g = &hangman; g->play(); calls Hangman::play(), because play() is virtual. That uses dynamic dispatch, where the function call is chosen at runtime based on the actual object type (Hangman).
