#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define MAX_WORD_SIZE 46
//made a global variable to count how many unique words there are
int dictionaryCount = 0;

//program to calulate the Cosine Similarity between given instructor answers and 
//user defined answers. 

/* Splits the input string to individual words
   Input: pointer to char array
   Output: array of pointers (to char arrays) */
char** tokenize(char * str) {
    size_t str_len = strlen(str);
    if (str_len == 0)
        return NULL;
    char** tokens = malloc(sizeof(char*) * 2);
    int token_size = 2;

    char word[MAX_WORD_SIZE] = "\0";
    int word_count = 0;
    for (register int i = 0, j = 0; i < str_len + 1; i++) {
        if (str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '\0' || i == str_len) {
            size_t word_len = strlen(word);
            // Add a null character at the end
            if (word_len >= MAX_WORD_SIZE)
                word[j - 1] = '\0';
            else if (word_len > 0)
                word[j] = '\0';
            else { // Empty word
                j = 0;
                continue;
            }             

            // Grow size
            if (word_count >= token_size - 1) {
                token_size *= 2;
                tokens = realloc(tokens, sizeof(char*) * token_size);
            }

            tokens[word_count] = malloc(sizeof(char) * word_len + 1);
            strcpy(tokens[word_count++], word);

            j = 0;
            word[0] = '\0';
            continue;
        }

        if (j < MAX_WORD_SIZE - 1)
            word[j++] = str[i];
    }

    if (word_count == 0)
        tokens[1] = NULL;

    tokens[word_count] = NULL;

    return tokens;
}
char** getUniqueWords(char** strs) {

    char** uniques = malloc(sizeof(char*) * 2);
    int unique_size = 2;

    int unique_count = 0;

    for (register int i = 0; ; i++) {
        if (strs[i] == NULL)
            break;
        // Detect duplication
        bool is_duplicated = false;
        for (register int j = 0; j < unique_count; j++) {
            if (strcmp(strs[i], uniques[j]) == 0) {
                is_duplicated = true;
                break;
            }
        }

        if (!is_duplicated) {
            
            // Grow size
            if (unique_count >= unique_size - 1) {
                unique_size *= 2;
                uniques = realloc(uniques, sizeof(char*) * unique_size);
            }

            uniques[unique_count] = malloc(sizeof(char) * strlen(strs[i]) + 1);
            strcpy(uniques[unique_count++], strs[i]);
        }
    }

    if (unique_count == 0) {
        free(uniques);
        return NULL;
    }

    uniques[unique_count] = NULL;
    //sets the count of unique words
    dictionaryCount=unique_count-1;
    return uniques;
}
//Converts a char to lowercase by adding 32 to the char if it is A-Z
char toLowercase(char c){
  if(c=='\0'){
    return '\0';
  }
  else if((int)c>=65&&(int)c<=90){
    c+=32;
  }
  return c;
}
//method which merges the student and instructor tokenized arrays 
//this is used as a parameter for getUniqueWords in order to get the dictionary

char** combineTokenized(char** student, char** instructor) {
  int index = 0;
  //since student and instructor tokenized answers have a maximum of 500 words per question, the max number of elements would be 500 * 5 * 2
  const int MAX_ELEMENTS = (500 * 5) * 2;
  char** combined;
  //allocate memory;
  combined = (char**) malloc(MAX_ELEMENTS* sizeof(char*));
  for(int i = 0; i < MAX_ELEMENTS; i++) {
    combined[i] = (char*) malloc(MAX_WORD_SIZE* sizeof(char));
  }
  //combine tokenized student array
  for(int i = 0; i < MAX_ELEMENTS; i++) {
    if(student[i] != NULL){
      for(int j = 0; j < MAX_WORD_SIZE; j++) {
        if(student[i][j] == '\0') break;
          combined[i][j] = student[i][j];
        }
    }
    else {
      index = i;
      break;
    }
  }
  //combine tokenized instructor array
  for(int i = index, j=0;j<MAX_ELEMENTS; i++, j++) {
    if(instructor[j] == NULL){
      break;
    } 
    else {
     for(int x = 0; x < MAX_WORD_SIZE; x++) {
        if(instructor[j][x] != '\0') {
          combined[i][x] = instructor[j][x];
        }
        else {
          break;
        }
      }
    }
  }
  return combined;
}

//gets the answers as user input and converts them to lowercase letter by letter
char **getStudentAnswers(const char **questions, int n, int len) {
  char **studentAnswers;
  studentAnswers=(char**)malloc(5*sizeof(char*));
  for(int i=0;i<5;i++){
    studentAnswers[i] = (char*)malloc(1+MAX_WORD_SIZE*len*sizeof(char));
  }
  char tempArr[MAX_WORD_SIZE*len];
  for(int i=0;i<sizeof(tempArr);i++){
    tempArr[i]='\0';
  }
  for(int i = 0; i < n; i++) {
    printf("%s\n", questions[i]);
    scanf("%[^\n]%*c",tempArr);
    for(int j=0;j<sizeof(tempArr);j++){
      studentAnswers[i][j] = toLowercase(tempArr[j]);
    }
  }
  return studentAnswers;
}
//method to check if a word is contained in a list of words
bool contains(char **arr, char* str){
  int count = 0;
  for(int i=0;i<500;i++){
    if(arr[i] == NULL) break;
    //while the words equal eachother
    while(arr[i][count] == str[count]) {
      if(arr[i][count] == '\0' || str[count] == '\0') break;
      count++;
    }
    //if both words reach terminating character, then they are equal so return true
    if(arr[i][count] == '\0' && str[count] == '\0') {
      return true;
    }
    //reset count
    count = 0;
  }
  return false;
}

int **ans2Vectors(char *instructor_answer, char *student_answer) {
  int **vectors=(int**)malloc(2*sizeof(int*));
  char **tokenizedStudentAnswers= tokenize(student_answer);
  char **tokenizedInsAnswers= tokenize(instructor_answer);
  char **combined=combineTokenized(tokenizedStudentAnswers, tokenizedInsAnswers);
  char **dictionary = getUniqueWords(combined);
  //instructors vector
  vectors[0] = (int*) malloc(dictionaryCount * sizeof(int));
  //students vector
  vectors[1] = (int*) malloc(dictionaryCount * sizeof(int));
  //get vector for instructor

  //update instructors vector 
  for(int i = 0; i < dictionaryCount; i++) {
    if(contains(tokenizedInsAnswers,dictionary[i])){
      vectors[0][i] = 1;
    }
    else{
      vectors[0][i] = 0;
    }
  }
  //update students vector
  for(int i = 0; i < dictionaryCount; i++) {
     if(contains(tokenizedStudentAnswers,dictionary[i])){
      vectors[1][i] = 1;

      }
    else{
      vectors[1][i] = 0;
    }
  }
  return vectors;
  
}
//calculates the cosine similarity of 2 strings
double cosineSimilarity(char *instructor_answer, char *student_answer){
  
  int **vectors = ans2Vectors(instructor_answer, student_answer);


  //cs1, cs2, and cs2 are different parts that are used to calculate the similarity
  double cs1 = 0, cs2 = 0, cs3 = 0;

  for(int i = 0; i < dictionaryCount; i++) {
    cs1 += (vectors[0][i] * vectors[1][i]);
  }
  for(int i = 0; i < dictionaryCount; i++) {
    cs2 += (vectors[0][i] * vectors[0][i]);
  }
  cs2 = sqrt(cs2);
  for(int i = 0; i < dictionaryCount; i++) {
    cs3 += (vectors[1][i] * vectors[1][i]);
  }
  cs3 = sqrt(cs3);
  dictionaryCount = 0;
  //prevents a divide by 0
  if(cs2==0||cs3==0){
    return 0;
  }
  return cs1/(cs2 * cs3);

}

int main(void) {
  //create 5 questions/answers
  int n = 5;
  char **questions=(char**)malloc(n*sizeof(char*));
  for(int i=0;i<n;i++){
    questions[i]=(char*)malloc(1+MAX_WORD_SIZE*500*sizeof(char));
  }
  questions[0]="What are local variables?";
  questions[1]="What is an identifier?";
  questions[2]="What is recursion?";
  questions[3]="What is a pointer?";
  questions[4]="What is the purpose of applying static to a local array?";
  //delcare and initialize instructor answers
  char **insAnswers=(char**)malloc(n*sizeof(char*));
  for(int i=0;i<n;i++){
    insAnswers[i]=(char*)malloc(1+MAX_WORD_SIZE*500*sizeof(char));
  }
  char **insAnswersLower=(char**)malloc(5*sizeof(char*));
  for(int i=0;i<5;i++){
    insAnswersLower[i]=(char*)malloc(1+MAX_WORD_SIZE*500*sizeof(char));
  }
  insAnswers[0]="Variables defined in function definition are local variables. They can be accessed only in that function scope.";
  insAnswers[1]="Identifiers are user defined names given to variables, functions and arrays.";
  insAnswers[2]="A function calling itself again and again to compute a value is referred to as recursive function or recursion. Recursion is useful for branching processes and is effective where terms are generated successively to compute a value.";
  insAnswers[3]="A pointer is a variable that stores the memory address of another variable as its value.";
  insAnswers[4]="By making a local array definition static the array is not created and initialized every time the function is called and it is not destroyed every time the function is exited. Also, the execution time is reduced.";

  //make every instructor answer lowercase
  int count=0;
  for(int i=0;i<n;i++){
    while(insAnswers[i][count]!='\0'){
      insAnswersLower[i][count]=toLowercase(insAnswers[i][count]);
      count++;
    }
    count=0;
  }

  char ** studentAnswers = getStudentAnswers(questions, n, 500);
  

  puts("\n");
  double average = 0;
  for(int i = 0; i < 5; i++) {
    printf("Question%d: %lf\n", i + 1, cosineSimilarity(insAnswersLower[i], studentAnswers[i]));
    average+=cosineSimilarity(insAnswersLower[i], studentAnswers[i]);
  }
  average/=5;
  printf("marks: %.3lf\%\n",average*100);
}