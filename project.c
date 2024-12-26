#include <stdio.h>
#include <stdlib.h>

#define MAX_QUES_LEN 300
#define MAX_OPTION_LEN 100

typedef struct
{
    char question[MAX_QUES_LEN];
    char options[4][MAX_OPTION_LEN];
    char correctAnswer;
    int points;
} Question;


void playGame(Question *questions, int numberOfQuestions);
void printQuestion(Question question);

int main()
{

    printf("\nDhruv Final C project\nQuizGame\n");
    Question *questions;
    FILE *file = fopen("questions.txt", "r");
    if (file == NULL)
    {
        printf("Unable to open file. Exiting");
        exit(0);
    }
    char str[MAX_QUES_LEN];
    int lineCounter = 0;
    while (fgets(str, MAX_QUES_LEN, file))
    {
        lineCounter++;
    }
    rewind(file);
    int numberOfQuestions = lineCounter / 7;
    questions = (Question *)malloc(numberOfQuestions * sizeof(Question));

    for (int i = 0; i < numberOfQuestions; i++)
    {
        fgets((questions)[i].question, MAX_QUES_LEN, file);
        for (int j = 0; j < 4; j++)
        {
            fgets((questions)[i].options[j], MAX_OPTION_LEN, file);
        }

        char option[10];
        fgets(option, 10, file);
        (questions)[i].correctAnswer = option[0];

        char point[10];
        fgets(point, 10, file);
        (questions)[i].points = atoi(point);
    }
    playGame(questions, numberOfQuestions);
    fclose(file);
}

void printQuestion(Question question)
{
    printf("\n\n%s", question.question);
    for (int i = 0; i < 4; i++)
    {
        if (question.options[i] != '\0')
        {
            printf("%c. %s", 'A' + i, question.options[i]);
        }
    }

    printf("Enter your Answer (A , B , C , D): ");
}

void playGame(Question *questions, int numberOfQuestions)
{
    int score = 0;
    char answer;
    for (int i = 0; i < numberOfQuestions; i++)
    {
        printQuestion(questions[i]);
        scanf(" %c", &answer);

        if (answer == questions[i].correctAnswer)
        {
            printf("\nCorrect!");
            score += questions[i].points;
            printf("\nYou Scored: %d Points", questions[i].points);
        }
        else
        {
            printf("\nWrong! Correct answer is %c.", questions[i].correctAnswer);
            break;
        }
    }
    printf("\n\nGame Over! Your total score is: %d\n", score);
}
