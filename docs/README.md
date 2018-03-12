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


## Task Queues on videogames


The best form of knowing how to use task queues on videogames is actually, seeing how other games have implemented them. So here are some examples of obvious tasks queues that can be seen at first sight. 
<br>
### They are Billions
In this video (min 24-25) we can see how the player builds several buildings while the game is paused. But in fact, the game doesn't start building them until the game is unpaused. So all the task are saved on a queue and executed once the game unpauses.

[![They_are_Billions](https://user-images.githubusercontent.com/26002028/37255163-d65fd5b0-2548-11e8-9078-554d85dbe2de.jpg)](https://www.youtube.com/watch?v=edaA0w5VxjQ)


### Transistor

In this case we can see how the player gives a series of events and then the game executes them in the order the player has given them. We'll learn how to make on similar system. 
<br>
	[![Transistor](https://user-images.githubusercontent.com/26002028/37254969-1435e594-2546-11e8-80ca-a5be6623a3eb.jpg)](https://www.youtube.com/watch?v=xj-LH76lQvg)

## Command Pattern
<br>
To achieve this task queues, we use whats is known as command pattern. *"Commands are an object-oriented replacement for callbacks"*(Gaming Programming Patterns) so as we treat tasks as objects and not as functions, we can apply command patterns from redefining keys to change the Actor of the action.
![command_pattern svg](https://user-images.githubusercontent.com/26002028/37271451-3fe15aba-25d3-11e8-8b28-fd795e31ea3b.png)
		Wikipedia UML
### Redefining Keys
<br>
First of all we must create a general class "Task" so the rest will inherit from it. This class must have a Constructor and Destructor an a virutal bool function for Execute the task itselfs. 
<br>
![Task Class](https://user-images.githubusercontent.com/26002028/37255436-a999f4b2-254c-11e8-8082-a97badfd8de1.PNG)
<br>
Once this parent class is created, we can create a new subclass for each task we want to add. In this example, we are going to make a simple rect move on four directions. So we create a new subclass for each movement. 
<br>
![MoveRight](https://user-images.githubusercontent.com/26002028/37255463-0241e8d6-254d-11e8-83a6-723eaf322d12.png)
<br>
Now, on our input handler we create a pointer to command for each button we are going to use, in this casa W A S D.
So now we created our pointers, we match them to their respective class
<br>
![Pointers](https://user-images.githubusercontent.com/26002028/37255748-168d958e-2551-11e8-8e6d-7c39e0136f82.png)
<br>
Now, all we have to do is change the effect when the Key A (For example) is pressed.
<br>**Example:**<br>
![moveleft](https://user-images.githubusercontent.com/26002028/37255777-8697531a-2551-11e8-947a-5db4fe5780f9.png)
<br>
### Change Actor
<br>
As we treat task as objects, we can make them act on any character we want. We only have to send as a parameter the actor of the task. So we can make a unique class for the action of jump and use it with all the characters in the game. 
![captura](https://user-images.githubusercontent.com/26002028/37255839-6889c91a-2552-11e8-87e6-31de8039bfae.PNG)
If we change the Actor, the task will execute for a different entity, such as the player, an enemy...
<br>
## Subclass Sandbox
As you can see by now, the possibilities of the command pattern are almost infinite, so you'll finish with a great number of classes. To avoid that you can use a [Subclass Sandbox](http://gameprogrammingpatterns.com/subclass-sandbox.html). I let you a link when you can find all necessary information about it. 
## USEFUL LINKS
Here you can see some links I used to documented my research:
 - [Game Programming Patter](http://gameprogrammingpatterns.com/command.html)
 - [Google Cloud Platform](https://cloud.google.com/appengine/docs/standard/python/taskqueue/)
 - [Source Making](https://sourcemaking.com/design_patterns/command/cpp/2)
 - [Wikipedia](https://en.wikipedia.org/wiki/Command_pattern)


