# What what?

## Calm down. This is just something I'm proud of today.

I've always had difficulty thinking about how I would manage to have, say, a Hash or a List which can take any type of data and deal with it gracefully. It would be cool if the list could do the mallocing and freeing for you, but also be really generic. I can just pass it data and it'll deal with it, and when I tell it "stop existing", I don't have to go manually kill every one of its members.

How to do that has always been clear to me, but it's always seemed like a nearly insurmountable task for some reason. You've got to make functions to deal with the individual data types (allocating and freeing them), and then you've got to make a slot somewhere which will hold a function pointer to the correct function depending on the data stored at that element of the list of hash. Function pointers in structs! It may as well be object oriented!

So it's always been something I've wanted to do, or to see done, and today I thought for a few minutes and then wrote it. Took a bit less than an hour and once it compiled (I had a minor syntax issue - I made my init function "void (\*init)()" to start, instead of "void \*(\*init)()". Also had some funniness with h being a double-pointer or not.) it ran perfectly.

The test for fitness was that valgrind would run it with no errors and tell me that it doesn't leak - and it did just that. So, huzzah. Now it's on here so I don't lose it :)

## Thanks for reading!

Wyatt Carss is a silly programmer  
He's 22ish and lives in Guelph, Ontario  
you can find him at wcarss.ca  
