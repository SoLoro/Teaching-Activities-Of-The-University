# The project of the organization of teaching activities of the university
____
## Installation
```
    https://github.com/SoLoro/Teaching-Activities-Of-The-University.git
```
____
## Languages
*C++, SQL(PostgreSQL)*
____
## Libraries & Frameworks
*QT*
____
## How to use it?
- After downloading the files, you need to restore the developed database first. The folder ,,Database,, contains 2 views of the same database, using either or each of them, you can get full access to the idea and implementation of the project.
- ___Recovery paths___:

    - **Using a backup:**
 
        - **Using pgAdmin**
     
            - You need to create a new database and name it ,,database,, .
            - Then right-click on it and select ,,Restore,,
            - In the window that opens, change the format to ,,Special,, and find the file database.backup, click ,,Restore,,.
            - *After a couple of seconds, if there is no new data, right - click on our database and select ,,Update,,*
        
        - **Using containers (Docker, Kubernetes and others) (For example, Docker)**

            - First you need to download postgres 
            ```
                docker pull postgres
            ```
            - Then you need to create the appropriate container
            ```
                docker run --name <postgres_container_name> -e  POSTGRES_PASSWORD=<postgres_container_password>-d -p 5432:5432 <postgres_with_version>
            ```
            - Open this container
            ```
                docker exec -it <postgres_container_name> bash 
            ```
            - Log in to it from the user account
            ```
                psql -h localhost -p 5432 -U <your_postgres_user>
            ```
            - Create a database
            ```
                create database database
            ```
            - Switch to it
            ```
                \c database
            ```
            - Go to the file system partition and restore by backup
            ```
                docker exec -i -u <your_postgres_user> <postgres_container_name> pg_restore -C -d postgres < database.backup
            ```
            
        - **In terminal environments, all commands will be similar to paragraph 2, except for the use of the additional option ,,sudo,,**
       
    - **Using an SQL file:**
   
        - **Using pgAdmin**
       
            - You need to create a new database and name it ,,database,,.
            - Then go to the requester window and select the db.sql file, run the execution of this query.
            - *When a pop-up about the successful completion of data processing notification appears , if they are not displayed in the database window, after a couple of seconds, right-click on our database and select ,,Update,,*
           
        - **Using containers (Docker, Kubernetes and others) (For example, Docker):**
       
            - First you need to download postgres 
            ```
                docker pull postgres
            ```
            - Then you need to create the appropriate container
            ```
                docker run --name <postgres_container_name> -e  POSTGRES_PASSWORD=<postgres_container_password>-d -p 5432:5432 <postgres_with_version>
            ```
            - Open this container
            ```
                docker exec -it <postgres_container_name> bash 
            ```
            - Log in to it from the user account
            ```
                psql -h localhost -p 5432 -U <your_postgres_user>
            ```
            - Create a database
            ```
                create database database
            ```
            - Switch to it
            ```
                \c database
            ```
            - Go to the file system partition and restore by backup
            ```
                cat db.sql | docker exec -i <postgres_container_name> psql -U <your_postgres_user>
            ```
           
        - **In terminal environments, all commands will be similar to paragraph 2, except for the use of the additional option ,,sudo,,**
        
- ___Next, you need to run the application Application.pro itself___
- The ,,mainwindow,, authorization window opens in front of you , in which you need to enter the database user data
- *In case of successful authorization, a window ,,application,, , will appear in front of you, on which the main functionality of the program is located*
    - The buttons ,,Teachers,, , ,,Workplans,, , ,,Pulpits,, , ,,Editions,, and ,,Logs,, are responsible for displaying the current database information on the central table window and allow you to work with yourself using the buttons ,,Add,, , ,,Change,, , ,,Delete,,
    - The upper comboBox and the button ,,Functions,, are responsible for receiving and processing specific database requests with their corresponding display on the central window
    - The lower buttons ,,Add,, , ,,Change,, , ,,Delete,, paired with the lower comboBox and double-clicking on the elements in the central window allow you to work with the database in the current time
        - **When you click on ,,Add,, , ,,Change,, a window pops up on the screen with fields for filling in the information corresponding to the requested function**

____
## What is this project about?
This project first of all shows and justifies how the logical chains of the working structure of institutions are interconnected, with the help of which contact occurs between them and how this affects the system as a whole
____
## What is this project for?
I show my skills in developing client-server applications using modern technologies and databases(tables and relationships, complex queries of different types, views, indexes, triggers, stored procedures, commit and rollback transactions, cursors for updating data, scalar and vector functions, referential integrity, distribution of user rights)
   
