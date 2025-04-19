#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Write your code in this file

#define DEBUG 0 // !!! Set to 0 otherwise test will fail !!!

#define ENTRY 5
#define MAX_NAME_LEN 10

typedef enum Exams{ // Enums for Exam scores, no need to index exam score with magic numbers e.g 0 1 2 ... 4 5 6...
    EXAM_1,  EXAM_2,
    EXAM_3,  EXAM_4,
    EXAM_5,  EXAM_6,
    EXAM_7,  EXAM_8,
    EXAM_9,  EXAM_10,
    EXAM_11, EXAM_12,
    EXAM_13, EXAM_N

} Exams;

typedef struct Student { // Data structure for Students.
    char *name;
    int score[13];
    float mean_score;
} Student;

void get_input(Student *s) { // Get inputs.
    for (int i = 0; i < ENTRY; i++) {
        s[i].name = malloc(MAX_NAME_LEN+1); // Memory allocation for name + null terminator.

        scanf("%s %d %d %d %d %d %d %d %d %d %d %d %d %d",
            s[i].name,
            &s[i].score[EXAM_1], &s[i].score[EXAM_2],
            &s[i].score[EXAM_3], &s[i].score[EXAM_4],
            &s[i].score[EXAM_5], &s[i].score[EXAM_6],
            &s[i].score[EXAM_7], &s[i].score[EXAM_8],
            &s[i].score[EXAM_9], &s[i].score[EXAM_10],
            &s[i].score[EXAM_11], &s[i].score[EXAM_12],
            &s[i].score[EXAM_13]
        );

        if (10 < strlen(s[i].name)) {
            /*
                Exits if name is longer than 10 characters.
            */
            free(s->name);
            exit(1);
        }
    
        for (int j = 0; j < EXAM_N - 1; j++) {
            /*
                Check's if score is less than 0 or greater than 10,
                Exits if conditions are meet.
            */
            (s[i].score[j] < 0 || s[i].score[j] > 10) ? exit(1) : NULL;
        }

        char first_letter = s[i].name[0]; // Get the first letter of the name.

        // check if the first letter in lowercase range.
        if (first_letter >= 'a' && first_letter <= 'z') {
            // Find the uppercase letter of coresponding lowercase.
            first_letter = first_letter - 'a' + 'A';
            // Replace the letter with the uppercase letter.
            s[i].name[0] = first_letter; 
        }
    }

}

void calculate_mean(Student *s) { // Calculate mean score of each student.
    int score_sum = 0;
    for(size_t i = 0; i < ENTRY; i++) {
        for(size_t j = 0; j < EXAM_N - 1; j++) {
            score_sum += s[i].score[j];
        }
        s[i].mean_score = (float)score_sum/EXAM_N - 1;
        score_sum = 0;
    }
}

float calculate_overall_score(Student *s) { // Calculate average score across students.
    float overall_sum = 0;
    for(size_t i = 0; i < ENTRY; i++) {
        overall_sum += s[i].mean_score;
    }
    return overall_sum/ENTRY;
}

char *get_highest_mean_score(Student *s) { // Get student with the highest average score.
    float high_score = 0;
    int index = 0;
    for (size_t i = 0; i < ENTRY; i++) {        
        if (s[i].mean_score > high_score) {
            high_score = s[i].mean_score;
            index = i;
        }
    }
    return s[index].name;
}

void get_predecessor(Student *s, char predecessor[][MAX_NAME_LEN+1], float threshold) { // Get student with score below the average score.
    int index = 0;
    for (size_t i = 0; i < ENTRY; i++) {
        if (threshold >= s[i].mean_score) {
            strcpy(predecessor[index], s[i].name);
            index++;
        }
    }
}

int main() {

    Student s[ENTRY] = {NULL, 0}; // Initialize student object.

    get_input(s); // Driver to get inputs from stdin.
    calculate_mean(s); // calulate each

    float score_threshold = calculate_overall_score(s);
    char *best = get_highest_mean_score(s);
    char predecessor[][MAX_NAME_LEN+1] = {0};
    get_predecessor(s, predecessor, score_threshold);

    puts(best);
    for (size_t i = 0; i < (sizeof(predecessor)/ENTRY); i++)
        puts(predecessor[i]);


    #ifdef DEBUG // For dubugging purpose.
    if (DEBUG){
        printf("\n%10s\n", "-------------------------------------------------------------------------------------");
        printf("|%10s | %34s                             | %1s |\n", "Name", "Score", "Mean");
        printf("|%10s |\n", "----------------------------------------------------------------------------------");
        for (int i = 0; i < ENTRY; i++) {
            printf("|%10s | %2d | %2d | %2d | %2d | %2d | %2d | %2d | %2d | %2d | %2d | %2d | %2d | %2d | %2.1f  |\n",
                s[i].name,
                s[i].score[EXAM_1], s[i].score[EXAM_2],
                s[i].score[EXAM_3], s[i].score[EXAM_4],
                s[i].score[EXAM_5], s[i].score[EXAM_6],
                s[i].score[EXAM_7], s[i].score[EXAM_8],
                s[i].score[EXAM_9], s[i].score[EXAM_10],
                s[i].score[EXAM_11], s[i].score[EXAM_12],
                s[i].score[EXAM_13], s[i].mean_score
            );
        }
        printf("-%10s\n", "------------------------------------------------------------------------------------");
        printf("Overall: %0.1f\n", score_threshold);
    }
    #endif // For dubugging purpose.
    
    return 0;
}
