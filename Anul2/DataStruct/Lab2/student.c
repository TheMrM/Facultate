#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
#define MARKSNUMBER 5

struct Date
{
    unsigned short dd;
    unsigned short mm;
    unsigned short yyyy;
};

typedef struct Date Date;

struct Student
{
    char name[MAXSIZE];
    char surname[MAXSIZE];
    unsigned short marks[MARKSNUMBER];
    double marksAverage; // Corrected spelling
    char biologicalCategory;
    Date birthday; // Use the typedef
};

typedef struct Student Student;

void readStudent(FILE *f, Student *student);
void printStudent(FILE *f, Student *student);
Student maxGrade(Student s1, Student s2, Student s3);

int main()
{
    FILE *fin = fopen("student.in", "r");
    if (!fin)
    {
        fprintf(stderr, "fopen failed in file %s!\n", __FILE__);
        exit(EXIT_FAILURE);
    }

    Student s1, s2, s3;

    readStudent(fin, &s1);
    readStudent(fin, &s2);
    readStudent(fin, &s3);

    fclose(fin);

    Student studentWithMaxGrade = maxGrade(s1, s2, s3);

    FILE *fout = fopen("student.out", "w");

    printStudent(fout, &s1);
    printStudent(fout, &s2);
    printStudent(fout, &s3);

    fprintf(fout, "Student with highest marks average: %s %s\n", studentWithMaxGrade.name, studentWithMaxGrade.surname);

    fclose(fout);

    return 0;
}

void readStudent(FILE *f, Student *student)
{
    fscanf(f, "%s %s", student->name, student->surname);
    for (size_t i = 0; i < MARKSNUMBER; i++)
    {
        fscanf(f, "%hu", &student->marks[i]);
    }

    student->marksAverage = 0;
    for (size_t i = 0; i < MARKSNUMBER; i++)
    {
        student->marksAverage += student->marks[i];
    }
    student->marksAverage /= MARKSNUMBER;

    fscanf(f, " %c %hu %hu %hu", &student->biologicalCategory, &student->birthday.dd, &student->birthday.mm, &student->birthday.yyyy);
}

void printStudent(FILE *f, Student *student)
{
    fprintf(f, "%s %s ", student->name, student->surname);
    for (size_t i = 0; i < MARKSNUMBER; i++)
    {
        fprintf(f, "%hu ", student->marks[i]);
    }
    fprintf(f, "%c %hu/%hu/%hu Average Marks: %.2f\n", student->biologicalCategory, student->birthday.dd, student->birthday.mm, student->birthday.yyyy, student->marksAverage);
}

Student maxGrade(Student s1, Student s2, Student s3)
{
    Student maxStudentGrade = s1;
    if (s2.marksAverage > maxStudentGrade.marksAverage)
    {
        maxStudentGrade = s2;
    }
    if (s3.marksAverage > maxStudentGrade.marksAverage)
    {
        maxStudentGrade = s3;
    }
    return maxStudentGrade;
}