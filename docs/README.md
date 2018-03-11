# TASK MANAGER

My name is [David Lozano](https://github.com/DavidTheMaaster) and I'm a videogame developer student at [CITM](https://www.citm.upc.edu/), UPC. This content is created for the subject of Project 2 and supervised by [Ricard Pillosu](https://es.linkedin.com/in/ricardpillosu).
This is a research about Task Manager and Task Queues on C++ and I will teach you the basics so you can apply them on your own videogame. 

## Task Queues

<br>
Tasks are work that can be handled asynchronously, because they are long-runnig work and we can't wait until it finishes to continue with the game. To be able to manage them we use a Task Queue, when you add all the tasks you want and it will execute them in the background. 
There are 2 types of Task Queues: Push Queues and Pull queues
While push queue automatically take care of the actions that you put on it, a pull queue had a list of actions that you can execute whenever you want.
<br>
For example, push queues are useful for example in a messaging system, such as Whatsapp, when you can continue sending messages even when the ones you just send haven't reach the addressee.
Pull queues are used for example on RPG games, when you give a character some orders and then the game executes them all in order. 
<br>

<p align="center">
	<a ## Task Queues on videogames>
</p>
<br>
The best form of knowing how to use task queues on videogames is actually, seeing how other games have implemented them. So here are some examples of obvious tasks queues that can be seen at first sight. 
<br>
### Transistor

In this video we can see how the player gives a series of events and then the game executes them in the order the player has given them. We'll learn how to make on similar system. 
<br>
<p align="center">
	[![transistor_image](https://user-images.githubusercontent.com/26002028/37254969-1435e594-2546-11e8-80ca-a5be6623a3eb.jpg)](https://www.youtube.com/watch?v=xj-LH76lQvg)
</p>
