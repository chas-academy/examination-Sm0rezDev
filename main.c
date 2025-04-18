#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

//Write your code in this file
#define DEBUG 1 // !!! Set to 0 otherwice test will fail !!!

#define MAX_ENTRY 5
#define MAX_NAME_LEN 10

typedef enum { // Enums for Exam scores, no need to index exam score with magic numbers e.g 0 1 2 ... 4 5 6...
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

void get_input(Student *s) {
    for (int i = 0; i < MAX_ENTRY; i++) {
        s[i].name = malloc(MAX_NAME_LEN);

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
    
        for (int j = 0; j < EXAM_N; j++) {
            /*
                Check's if score is less than 0 or greater than 10,
                Exits if conditions are meet.
            */ 
            (s[i].score[j] < 0 || s[i].score[j] > 10) ? exit(1) : NULL;
        }
    }

}

float get_score_mean(Student *s) {

}

int main() {

    Student s[MAX_ENTRY] = {NULL, 0}; // Initialize student object.

    get_input(s);



    // for (int i = 0; i < MAX_ENTRY; i++) {
    //     s[i].name = malloc(MAX_NAME_LEN);

    //     scanf("%s %d %d %d %d %d %d %d %d %d %d %d %d %d",
    //         s[i].name,
    //         &s[i].score[EXAM_1], &s[i].score[EXAM_2],
    //         &s[i].score[EXAM_3], &s[i].score[EXAM_4],
    //         &s[i].score[EXAM_5], &s[i].score[EXAM_6],
    //         &s[i].score[EXAM_7], &s[i].score[EXAM_8],
    //         &s[i].score[EXAM_9], &s[i].score[EXAM_10],
    //         &s[i].score[EXAM_11], &s[i].score[EXAM_12],
    //         &s[i].score[EXAM_13]
    //     );
    // }


    #ifdef DEBUG // For dubugging purpose.
    if (DEBUG)
        printf("\n%10s\n", "------------------------------------------------------------------------------");
        printf("|%10s | %1s                                                          |\n", "Name", "Score");
        printf("|%10s |\n", "---------------------------------------------------------------------------");
        for (int i = 0; i < MAX_ENTRY; i++) {
            printf("|%10s | %2d | %2d | %2d | %2d | %2d | %2d | %2d | %2d | %2d | %2d | %2d | %2d | %2d |\n",
                s[i].name,
                s[i].score[EXAM_1], s[i].score[EXAM_2],
                s[i].score[EXAM_3], s[i].score[EXAM_4],
                s[i].score[EXAM_5], s[i].score[EXAM_6],
                s[i].score[EXAM_7], s[i].score[EXAM_8],
                s[i].score[EXAM_9], s[i].score[EXAM_10],
                s[i].score[EXAM_11], s[i].score[EXAM_12],
                s[i].score[EXAM_13]
            );
        }
        printf("-%10s\n", "-----------------------------------------------------------------------------");
    #endif // For dubugging purpose.
    
    return 0;
}