#include <stdio.h>

struct person {
    int personId;
    double height;
    double weight;
    double BMI;
};

double calculate (double h, double w){
    return w / (h*h);
}

void write_person(void){
    FILE *file;
    struct person p1;

    if ((file = fopen("bmi.txt", "r+")) == NULL){
        perror("fopen in write_person");
    } else {
        printf("Person ID : "); scanf("%d", &p1.personId);
        printf("Height(m) : "); scanf("%lf",&p1.height);
        printf("Weight(kg): "); scanf("%lf",&p1.weight);
        p1.BMI = calculate(p1.height,p1.weight);
        fwrite(&p1, sizeof(p1), 1, file);
        fclose(file);
     }
}

void read_person(void){
    FILE *file;
    struct person p1;

    if ((fopen("bmi.txt","r+")) == NULL){
        perror("fopen in read_person");
    } else {
        while (fread(&p1, sizeof(p1), 1, file) > 0){
            printf("Person ID: %d\n", p1.personId);
            printf("Height   : %.3f(m)\n", p1.height);
            printf("Weight   : %.1f(kg)\n", p1.weight);
            printf("BMI      : %.2f\n\n", p1.BMI);
        }
        fclose(file);
    }
}

int main (void) {
    write_person();
    read_person();

    return 0;
}
