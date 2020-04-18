# KeyboardChanger
Simple windows hook to immulate additional buttons click

Idea my keyboard has 2 charset russian and english
When you type on english ecndoing but you want to produce russian symbols
It's immulates them something like Ш = |_|_|
Why do I need this? I have no idea.

It dosn't work in applications that do not use windows calls to GetMessage() or PeekMEssage()
And that hurt really bad

After start exe file press F6 to turn on/off this mode, or F7 to turn on/off mode
where button click will be recorded as 
  Actual button text - virtual code - scan code
But you have to change FileHandler.h path to already existing file
