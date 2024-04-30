// Add brief description here: This is the reduced version of the coursework for debugging and testing.

#include <stdio.h>
// Enter any other #includes that you deem necessary below
#include <stdlib.h>
#include <math.h>   // Enables mathematical operations to find standard deviation

#define NUMROWS	 5    // map size
#define NUMCOLS  5    // map size
#define NUMWALKS 10 // number of random walks
#define NUMSTEP  3   // number of steps in each walk
// Enter any other #defines as you deem necessary below
int randCALL = 0;



int calc_status(char current_tile, char next_tile, int move_count) {
    if(current_tile == 'B') {
        int result = 1; // Instant win
        return result;
    }
    if(current_tile == 'L' && next_tile == 'B' && move_count <= NUMSTEP) {  // Win even if the move count reached limit per trial, as long as landing on tile 'B'
        int result = 1; // Win
        return result;
    }
    if(current_tile == 'L' && next_tile == 'L' && move_count < NUMSTEP) {   // Only allow further moves if the move count has not reached the limit yet
        int result = 2; // Keep going
        return result;
    }
    else {
        int result = 0; // Lose due to stepping on tiles 'D', 'V', and W'
        return result;
    }
}

int next_step(int random_number) {   // Next step using rand() as input, to be used with the step 2D array.
    int one_step;
    if(random_number % 8 == 0) {
        one_step = 0;
        return one_step;
    }    
    if(random_number % 8 == 1) {
        one_step = 1;
        return one_step;
    }
    if(random_number % 8 == 2) {
        one_step = 2;
        return one_step;
    }    
    if(random_number % 8 == 3) {
        one_step = 3;
        return one_step;
    }
    if(random_number % 8 == 4) {
        one_step = 4;
        return one_step;
    }    
    if(random_number % 8 == 5) {
        one_step = 5;
        return one_step;
    }
    if(random_number % 8 == 6) {
        one_step = 6;
        return one_step;
    }    
    if(random_number % 8 == 7) {
        one_step = 7;
        return one_step;
    }
}

float mean(int data[], int data_count) {  // Mean calculator
    float sum = 0, mean;
    int i;
    for(i = 0; i < data_count; i++) {
        sum += data[i];
    }

    if(data_count > 0) {        // Only runs if there is a data count to avoid dividing by zero
        mean = sum / data_count;
    }
    else {  // If the explorer cannot win due to standing on a dangerous tile, assume mean = 0 to avoid errors
        mean = 0;
    }
    return mean;
}

float stdev(int data[], int data_count) { // Standard deviation calculator
    float sum = 0, mean, variance = 0;
    int i;
    for(i = 0; i < data_count; i++) {
        sum += data[i];
    }

    if(data_count > 0) {
        mean = sum / data_count;
    }
    else {
        mean = 0;
    }

    for(i = 0; i < data_count; i++) {
        variance += pow(data[i] - mean, 2);
    }

    if(data_count > 0) {
        float stdev = sqrt(variance / data_count);
        return stdev;
    }
    else {
        float stdev = 0.0;
        return stdev;
    }
}





int main(void) {
    srand(123456);  // Seed

    int total_steps = 0;    // Total steps for a tile that has been tested throughout the trial
    int move_count = 0;     // Total steps for a trial that has been used
    int trials = 0;         // Number of trials on a tile completed
    int wins = 0;           // Number of wins (successful landing on tile 'B' within move_count <= 10)
    int row_index = 0;        // Variable explorer's index for matrix from 0 to 8 (Syntax: matrix[row_index][column_index])
    int column_index = 0;
    int row_index_next = 0;   // Explorer's next coordinate. Once the movement is complete, this value will be copied to row_index.
    int column_index_next = 0;
    char current_tile;      // Current tile the explorer is at
    char next_tile;         // Tile after one step
    char raw_map[NUMROWS][NUMCOLS];     // Raw map with letters to be processed
    float prob_map[NUMROWS][NUMCOLS];   // Probability of winning, print (%.2f) of storage when showing results
    float leng_map[NUMROWS][NUMCOLS];   // Average path length for winning (%.2f)
    float stdev_map[NUMROWS][NUMCOLS];  // Standard deviation for winning path length (%.2f)

    int row_index_read = 0;   // Number of lines successfully read and also used as a index. It is the index used for opening file.
    int column_index_read = 0;
    int row_index_test = 0;   // The index of the tile where the calculation is ongoing. It is also the number of lines successfully read.
    int column_index_test = 0;
    int step[8][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};   // Stepping array to be added with the indices in raw_map[row_index][column_index]

    int max_row = NUMROWS - 1;      // Used in stepping array adder function to restrict the explorer from leaving the map through edges and corners.
    int max_column = NUMCOLS - 1;


    // Load the map
    FILE *fptr;
    char raw_line[2 * NUMCOLS];

    fptr = fopen("Test.txt","r");

    if(fptr == NULL){
        printf("Error!"); //(File \"island_map.txt\" is required)
        return 1;
    }

    while(!feof(fptr)) {    // Keeps running until end of the file
        if (ferror(fptr)){
            printf("Error!"); // File read error
            return 1;
        }

        for(column_index_read = 0; column_index_read < (2 * NUMCOLS); column_index_read++) {
            raw_line[column_index_read] = fgetc(fptr);
                if(column_index_read == ((2 * NUMCOLS) - 1) && raw_line[column_index_read] != '\n' && raw_line[column_index_read] != '\0' && !feof(fptr)) {
                    printf("Error!"); // End-line character mismatch
                    return 1;

                } // Error message if the 2 * NUMCOLS - 1 index character is not null nor new line. Excluded the final line as '\0' did not show up at the EOF. The next "if" statement tests the final line string length mismatch.
                if(column_index_read % 2 == 1 && column_index_read > 0 && column_index_read < (2 * NUMCOLS) - 2 && raw_line[column_index_read] != ' ') {
                    printf("Error!"); //Incorrect spacing
                    return 1;
                }
                if(column_index_read != ((2 * NUMCOLS) - 1) && feof(fptr)) {
                    printf("Error!"); // Too few string length at the final line
                    return 1;
                } // Error message if there are too few string length at the final line
                if(column_index_read % 2 == 0) {  // Filters indices of only even numbers
                    raw_map[row_index_read][column_index_read / 2] = raw_line[column_index_read];   // Write to raw_map[9][9] array for processing
                }
            }   // Error message if unmasked line length is not (2 * NUMCOLS) - 1.
                // This is tested using the string[2*NUMCOLS] != '\0' or != '\n' (in a single quotation mark).
                // If the '\0' or '\n' is called at the index equal or less than (2*NUMCOLS)-1, then error message.
            row_index_read++;

            if(row_index_read > NUMROWS) {   //If the number of lines that have been read is greater than NUMROWS, show error message.
                printf("Error!");   // Input line count exceeded
                return 1;
            }
        }
    fclose(fptr);





    // Perform random walks and calculate results
// Validating array inputs
    while(row_index_test < NUMROWS && column_index_test <= NUMCOLS) { // Keep running until reading/processing the entire 2D array. column_index also indicates how many rows have been processed so <= is used instead of <.
        for(column_index_test = 0; column_index_test < NUMCOLS; column_index_test++) {   // column_index resets back to zero each cycle. At the end of the row_index cycle, the while loop satisfied the stop condition while the row_index is not zero.
            current_tile = raw_map[row_index_test][column_index_test];   // For the sake of visual compactness
            if(current_tile != 'B' && current_tile != 'D' && current_tile != 'L' && current_tile != 'V' && current_tile != 'W') {
                printf("Error!"); // Invalid character entered
                return 1;
            }   // Character and correct spacing validation. Error message if not satisfied the desired input format.
            
            int winning_moves[NUMWALKS];    // Number of winning moves of a tile for each trial, maximum of NUMWALKS (1000), if taking the largest case of "B" tile at the start.
            trials = 0;         // Number of trials on a tile completed
            wins = 0;           // Number of wins (successful landing on tile 'B' within move_count <= 10)
            total_steps = 0;
            move_count = 0;

            while(total_steps < NUMWALKS) {  
                row_index = row_index_test;     // Each beginning of the trial where the tile is tested, the explorer will return to this test tile initially.
                column_index = column_index_test;
                move_count = 0;

                trials++;       // Current number of trials attempting, starting from 1. For example, at first attempt, trials = 1. Added trial increment here and removed other trial increments from each individual win/lose if statements. This records the unfinished journey as a loss.



                // Instant win/lose without the need to calcualte 1000 trials (maximum trials within NUMWALK) for the guaranteed outcome. Gives conclusion without any moves.
                if(current_tile == 'B') {     // Instant win for starting on tile 'B'
                //    trials = 1;     // Tests one trial
                    wins = 1;       // Record as 1 win on 1 trial (100% winning chance)
                    winning_moves[0] = 0;   // Records as 0 moves for calculating average moves and stdev. The Wins will be 1.
                    break;              // No need for additional trials for this tile as the explorer is guaranteed to win.
                }
                if(current_tile == 'D' || current_tile == 'V' || current_tile == 'W') {     // Instant loss for starting on dangerous tiles 'DVW'
                //    trials++;   // Tests one trial (or more) for calculation
                    //wins = 0; // Optional but should be 0, already initialized as wins = 0 at the beginning of the for loop. 0% winning chance.
                    break;              // No need for additional trials for this tile as the explorer is guaranteed to lose.
                }



                while(move_count < NUMSTEP && total_steps < NUMWALKS) {
                    // Rough move action: row_index + step[next_step()][0], column_index + step[next_step][1]
//                    int random = rand();    // Constant random number for testing moves, randomizes every for loop cycle
                    int move_code = next_step(rand());  // Mapped step direction code from 0 to 7, from north to north-west in clockwise
                    randCALL ++;

                    int row_move = step[move_code][0];
                    int column_move = step[move_code][1];
                    
                    total_steps++;  // Number of steps currently performing. Example: if total_steps = 1, then this is the first step. Therefore, there's no such zero steps.
                    move_count++;

                    // 01234567, N, NE, E, SE, S, SW, W, NW. Filtering movements for preventing explorer from leaving the map through edges and corners. 
                    if((move_code == 0 && row_index > 0) || (move_code == 1 && row_index > 0 && column_index < max_column) || (move_code == 2 && column_index < max_column) || (move_code == 3 && row_index < max_row && column_index < max_column) || (move_code == 4 && column_index < max_column) || (move_code == 5 && row_index < max_row && column_index > 0) || (move_code == 6 && column_index > 0) || (move_code == 7 && row_index > 0 && column_index > 0)) {
                        row_index_next = row_index + row_move;
                        column_index_next = column_index + column_move;
                    } // Move the explorer, does not work if the explorer is at the edge to prevent conflicts
                    else {
                        row_index_next = row_index;
                        column_index_next = column_index;
                    }


                    int status = calc_status(raw_map[row_index][column_index],raw_map[row_index_next][column_index_next],move_count);
                    if(status == 1) {   // Win
                        winning_moves[wins] = move_count;   // Saving the number of moves for winning trials for processing average and stdev. A +1 has been added since the move_count has not been incremented before collecting the move count data.

                    //    trials++;
                        wins++;
   
//                        total_steps++;
                        break;  // Starts a new trial once the journey has concluded.
                    }
                    if(status == 0) {   // Lose
                    //    trials++;

//                        total_steps++;  // (NOTE: If lost by out of move count, then skip this.)
                        break;  // Starts a new trial once the journey has concluded.
                    }
                    else {  // calc_status may be 2. The loop continues as the journey has not yet ended.
//                        move_count++;   
//                        total_steps++;
                        row_index = row_index_next;         // Explorer has moved one step.
                        column_index = column_index_next;
                    }
                }
            }
            // Calculate the escape chance, mean, and stdev of the step and then store them to the prob_map, leng_map, and stdev_map.
            prob_map[row_index_test][column_index_test] = (wins / (float) trials) * 100; // Convert one of the values (type casting) to float to return float value for division between two integers. Display values in percentages.
            leng_map[row_index_test][column_index_test] = mean(winning_moves, wins);
            stdev_map[row_index_test][column_index_test] = stdev(winning_moves, wins);
        }
        row_index_test++;  // Completed rows
    }



    // Print results
    printf("Map:\n");
    for(int i = 0; i < NUMROWS; i++) {
        for(int j = 0; j < NUMCOLS; j ++) {
            if(j < NUMCOLS - 1) {
                printf("%c ", raw_map[i][j]);
            }
            if(j == NUMCOLS - 1) {  // No extra spaces at the end of the string
                printf("%c", raw_map[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nProbability of escape:\n");
    for(int i = 0; i < NUMROWS; i++) {
        for(int j = 0; j < NUMCOLS; j ++) {
            if(j < NUMCOLS - 1) {
                printf("%6.2f ", prob_map[i][j]);
            }
            if(j == NUMCOLS - 1) {
                printf("%6.2f", prob_map[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nMean path length:\n");
    for(int i = 0; i < NUMROWS; i++) {
        for(int j = 0; j < NUMCOLS; j ++) {
            if(j < NUMCOLS - 1) {
                printf("%.2f ", leng_map[i][j]);
            }
            if(j == NUMCOLS - 1) {
                printf("%.2f", leng_map[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nStandard deviation of path length:\n");
    for(int i = 0; i < NUMROWS; i++) {
        for(int j = 0; j < NUMCOLS; j ++) {
            if(j < NUMCOLS - 1) {
                printf("%.2f ", stdev_map[i][j]);
            }
            if(j == NUMCOLS - 1) {
                printf("%.2f", stdev_map[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nRandom Calls: %d", randCALL);
    return 0;
}