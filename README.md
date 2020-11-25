 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\<"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# NOM
 > Your author list below should include links to all members GitHub and should begin with a "\<" (remove existing author).
 
 > Authors: [Crystal Tong](https://github.com/xtaltong), [Ellie Cheng](https://github.com/ECheng742), [Sahas Poyeker](https://github.com/faultylegend)
 
 > You will be forming a group of **THREE** students and work on an interesting project that you will propose yourself (in this `README.md` document). You can pick any project that you'd like, but it needs ot implement three design patterns. Each of the members in a group is expected to work on at least one design pattern and its test cases. You can, of course, help each other, but it needs to be clear who will be responsible for which pattern and for which general project features.
 
 > ## Expectations
 > * Incorporate **three** distinct design patterns, *two* of the design patterns need to be taught in this course:
 >   * Composite, Strategy, Abstract Factory, Visitor
 > * All three design patterns need to be linked together (it can't be three distinct projects)
 > * Your project should be implemented in C/C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.

## Project Description
 > our project description should summarize the project you are proposing. Be sure to include
 > * Why is it important or interesting to you?
* Food delivery apps are heavily relied on by the college student populace, but has skyrocketed in popularity due to recent events. As a program that could be useful to people who use delivery, we wanted to create something that could be functional and relevant to people's needs today. Because food is a interesting topic to us, we wanted to design this so that people could have an easier time comparing their options when ordering delivery.
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 * [Postmates API](https://postmates.com/developer) - Use data from Postmates API as the basis for the comparison of delivery costs
 * [Grubhub API](https://grubhub-developers.zendesk.com/hc/en-us) - Use data from Grubhub API as the basis for the comparison of delivery costs
 * [Uber Eats API](https://developer.uber.com/docs/eats/introduction) - Use data from Uber Eats API as the basis for the comparison of delivery costs
 * C++
 > * What will be the input/output of your project?
* The input will be the name of a food place and item name(s). Using this information, the program should gather information from various food delivery systems and show the comparisons between these food apps. If time allows, another extra feature could be to receive input of food item(s) and use this to gather information about which food places nearby offer this item in addition to the cost comparisons.
 > * What are the three design patterns you will be using. For each design pattern you must:
 >   * Explain in 3 - 5 sentences why you picked this pattern and what feature you will implement with it
* Strategy: Strategy allows us to pick how to display the availability and prices of items depending on what information the client wants to recieve at runtime. If the client wishes to see the best delivery app price depending on their food item, just the App name and price will show up. If the client wants to see the quickest food delivery or which apps it is available on, it will use a different print format. This will also make in easy to implement a print function for the different API from delivery apps and will allow easy expansion to the program.
* Abstract Factory: By using the Abstract Factory pattern, we can establish a factory that generates different object types for the different delivery apps. This pattern will primarly be used for creating differnt variations of the app information object that will store information from the API of different food delivery apps. If one app uses a different format to store information that the others, the factory object can create a new object that will encapsulate the new API structure. This will be very useful for having each API as a modular object that can be implemented in the program.
* Composite: Composite is a design pattern that treats a group of objects as a single instance of an object. Since we'll be having multiple APIs to work with, being able to treat these interfaces the same is advantageous. This way, the user can interact with objects of varying complexity seamlessly.
 > * This description should be in enough detail that the TA/instructor can determine the complexity of the project and if it is sufficient for the team members to complete in the time allotted. 
* Additional Description: We will be creating a terminal-based application that compares different food delivery apps and their price differences. People should be able to easily see the break down in types of costs involved in food deliveries and menu availability for the different delivery apps. We will be using the Uber Eats, Postmates, and GrubHub APIs and languages C++ to create our project which will be functional only in the terminal, and if time allows, then we want to make the interface available as a web application.

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA

 ## Class Diagram
 > * Include a class diagram(s) for each design pattern and a description of the diagram(s). This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description).  
  <img src="images/Diagram.png?raw=true" width="1000">
 * Description of diagram: We will be going clockwise and starting from the bottom-right to describe the diagram. First, we used the Strategy pattern (named ComparisonStrategy) to provide the client with two different types of algorithms for comparing the breakdowns of different delivery apps for a restaurant of the user’s choice. One method is by using the price strategy and the other is with the time strategy. Both provide benefits depending on what kind of a breakdown the client would like to see. Second, we used the Composite pattern (named Tag) to design a tagging system, where a food item could be categorized and that category can be further specified by another category and so on. These descriptors are mostly for the user’s information and interest in particular food categories. Lastly, we also used the Abstract Factory design pattern (named DeliveryOption) to host the our two concrete factories UberEatsDelivery and DoorDashDelivery. Since we'll be working with different API's, they may differ in their structure and methods of organization in their information so we are using this pattern to encapsulate the two related factories and their products. We need a different implementation to account for differences in the API's to gather the same information we need in common. The family of products we have in the Abstract Factory pattern are PriceBreakdown, TimeBreakdown, and RestaurantList. 
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
* So far the development is going pretty well. Sahas worked on writing the framework for the Timebreakdown product and Tag/ Item framework and functions. Crystal worked on the strategy pattern and delivery factory portion of the project. Ellie has developed the restaurant class and made some methods and created the framework for the PriceBreakdown.
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 * We have not made much progress on the possible GUI for our application. We also did not implement many functions that will be used throughout the application either. We have taken these into consideration when developing the application and will focus on creating the functions and connecting then throughout the program. If time permits, we will implement a GUI system once everything else is done using python.
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 We haven't had bugs yet, mostly because we have created unit tests. There will be unit tests in the next sprint for the classes we've implemented, as well as creating drivers or stubs in place of modules we've not yet created so that we are able to do testing in the meantime. Then, any bugs identified there will be made into issues that can be fixed. Currently, any small bugs we've faced were solved and merged via pull requests.
 >   - What tasks you are planning for this next sprint.
 For the next sprint, we plan to implement the FoodItem and Category functions, the PriceStrategy and TimeStrategy algorithms, and also the virtual functions from DeliveryOption, PriceBreakdown, TimeBreakdown, and RestaurantList. We will gather data or use mock data to run units test for these functions as well as integrated tests that test across the different classes.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
