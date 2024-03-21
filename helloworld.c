#include <stdio.h> //Includes the standard input/output library for functions like printf.
#include <stdlib.h>//Includes the standard library for functions like exit.
#include <fcntl.h>//Includes the file control library for constants like O_RDWR (read-write mode) and O_CREAT (create if file doesn't exist).
#include <sys/types.h>//Includes system data types.
#include <sys/stat.h>//Includes macros for file status information.
#include <unistd.h>//ncludes POSIX operating system API for functions like open, write, close, etc.

int main() {
    // Open a file named "test.txt" in read-write mode with create if doesn't exist flag
    int fd = open("test.txt", O_RDWR | O_CREAT, 0664);//Opens a file named "test.txt" in read-write mode with the create flag. The 0664 sets the file permissions (read-write for owner, read-only for others). The function returns a file descriptor (fd) that is used to refer to the opened file in subsequent file operations.

    // Check if opening the file was successful
    if (fd == -1)// Checks if the file was opened successfully. If fd is -1, there was an error opening the file, and the perror function is called to print the error message.
  {
        perror("open");//Prints the opening error message to standard error.
        exit(EXIT_FAILURE);//Exits the program with a failure status.
    }

    // Write "Hello World" to the file
    const char *hello_world = "Hello World";//Declares a constant character pointer hello_world that points to the string "Hello World".
    ssize_t bytes_written = write(fd, hello_world, strlen(hello_world));//Writes the content of hello_world (which is "Hello World") to the file referred to by fd. The strlen function calculates the length of the string in bytes (excluding the null terminator). The write function returns the number of bytes written.

    // Check if writing to the file was successful
    if (bytes_written == -1)//Checks if writing to the file was successful. If bytes_written is -1, there was an error writing to the file, and the perror function is called to print the error message.
     {
        perror("write");//Prints the writing error message to standard error.
        exit(EXIT_FAILURE);//Exits the program with a failure status.
    }

    // Close the file
    close(fd);//Closes the file referred to by fd.

    return 0;
}
