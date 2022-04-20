# Cplusplus-Program

# summarize the project and what problem it was solving

This program works with a file from a grocery store of the items they sold on a given day. The problem that this program solves is that it can quickly and accurately gathers information from the file for the grocery store to use to increase future sales and choose good product placement. From a menu, the user can choose different program options. The options for the program are to display a list of how many times each item was sold, to display how many times a specific item was sold, to display a histogram of the items sold from the file, and to close the program. 

# What did you do particularly well?

The things I did well were implementing the Python functions, setting up the menu display, and validating user input. All three of these components of the program work correctly and efficiently together to give the user the best experience and provide the company with maintainable code that is simple to work with and update in the future. 
Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
While I'm very happy with the program overall, I think one area that could be improved is the C++ print Histogram function. I might have made it more complicated than it needs to be by creating vectors of the items and the times that item was purchased. I think I could have made that component more efficient by simiply having the function read the information from the file and output it to the user according to the histogram format requirements. 
# Which pieces of the code did you find the most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

The piece of code that gave me the biggest challenge was the print Histogram function. The issue I ran into was that the loop used to build the vectors ran one extra time causing the last grocery item (and the times it was purchased) in the file to be entered twice in the vectors. To fix this I reviewed my code in the function. When I saw the code within the function was ok, I looked at the code with a tutor. I learned from my tutor that if the file ends with an empty line (by hitting enter after the last line of text or numbers entered), the end of the file hasn't been reached so the loop runs an "extra" time because of the empty line. To fix this, I removed the new line from the Python code when it wrote the file to pass to the print Histogram function and the program worked perfectly. I'm glad that I learned about this issue that can happen with files being used with programs. It will save time in future programs and give me another area to check if there are bugs in a program I'm creating. 

# What skills from this project will be particularly transferable to other projects or coursework?

I believe the skills from this project that will be transferable to other projects or coursework would be using files in programs. This skill is useful because many apps and programs work with files to perform basic tasks. I also think working with more than one programming language will be a transferable and useful skill for future projects because from what I have learned in my classes so far, it seems like using multiple programming languages is a common practice. It can make more complex programs more efficient and will be a useful tool in the future. 

# How did you make this program maintainable, readable, and adaptable?

I made this program maintainable, readable, and adaptable by I using comments throughout the code that I wrote. I also followed industry-standard best practices for naming functions, variables, vectors, and files. These comments tell the reader the purpose of the command or function, helping the code to be understood easier and for future updates. Following industry-standard best practices gives the reader clarity for what type of element in the program is represented by the variable name. 
