# Use the official GCC image to compile and run the C program
FROM gcc:latest

# Set the working directory inside the container
WORKDIR /app

# Copy the C source code into the container
COPY . .

# Compile the C program
RUN gcc -o tic_tac_toe main.c

# Set the default command to run the compiled program
CMD ["./tic_tac_toe"]