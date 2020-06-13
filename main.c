#include <stdio.h>
#include <string.h>

int main() {

    // referente ao valor da prova e de cada questao

    int questions;
    double score, questionpoints;

    printf("Enter the number of questions: ");
    scanf("%d", &questions);
    printf("What is the overall score? ");
    scanf("%lf", &score);
    questionpoints = score / questions;
    printf("Points for each question: %.1lf\n", questionpoints);
    printf("\n");

    // gabarito

    char answers[questions][50];
    int i;

    printf("What is the answer for each questions: \n");

    for (i = 0; i < questions; i++){
        printf("%d) ",i + 1);
        fseek(stdin, 0, SEEK_END);
        gets(answers[i]);
    }
    printf("\n");

    //quantitativo e registro de alunos;

    int students, j;
    printf("How many students do you have? ");
    scanf("%d", &students);
    printf("\n");

    char names [students] [50];
    char stanswers [students][questions] [50];

    for (i = 0; i < students; i++){
        printf("Type the student's name: ");
        fseek(stdin, 0, SEEK_END);
        gets(names[i]);
        printf("\n");
        printf("Type his/her answers: \n");
        for (j = 0; j < questions; j++){
            printf("%d) ", j + 1);
            fseek(stdin, 0, SEEK_END);
            gets (stanswers[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //PARA O USUARIO: gabarito, resposta dos alunos

    printf("ANSWER KEYS: \n");
    for (i = 0; i < questions; i++){
        printf("%d) %s\n",i + 1, answers[i]);
    }

    printf("\n");

    printf("STUDENT'S ASNWERS: \n");
    for (i = 0; i < students; i++){
        printf("%s: \n", names[i]);
        for (j = 0; j < questions; j++){
            printf("%d) %s\n", j + 1, stanswers[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //NOTASSSS nota = quatidade de questoes certas x valor da questao

    int result, rightanswers;
    double grades[questions][students];

    printf("Students grades: \n");

    for (i = 0; i < students; i++){
        rightanswers = 0;
        printf("%s: ", names[i]);

        for (j = 0; j < questions; j++){

        result = strcmp(answers[j], stanswers[i][j]);

        if (result == 0) {
           rightanswers = rightanswers + 1;
        }
        }
        grades[i][j] = (double) rightanswers * questionpoints;
        printf("%.2lf", grades[i][j]);
        printf("\n");
        printf("\n");
    }

    return 0;
}
