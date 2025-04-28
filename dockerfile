# Use the official GCC image to compile and run the C program
FROM gcc:latest

# Set the working directory inside the container
WORKDIR /app

# Copy the C source code into the container
COPY . .

CMD ["sh", "-c", "gcc main.c -o game.out && ./game.out"]