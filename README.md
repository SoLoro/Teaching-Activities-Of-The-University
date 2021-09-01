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
- After downloading the files, you first need to restore the developed database. The folder ,,Database,, contains 2 views of the same database, using either or each of them, you can get full access to the idea and implementation of the project.
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
            
        - **In terminal environments, all commands will be similar to paragraph 1.2), except for the use of the additional option ,,sudo,,**
