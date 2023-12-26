#include <stdio.h>
#include <stdlib.h>

int input_arr(int *arr, int *str_count, int *stolb_count);
int input_size_oblast(int str_count, int stolb_count, int *size_str_o,
                      int *size_stolb_o);
int find_max_oblast(int *arr, int str_count, int stolb_count, int size_str_o,
                    int size_stolb_o, int *max_i, int *max_j, int *max_sum);
int calc_sum(int *arr, int size_stolb_o, int size_str_o, int i, int j, int *sum,
             int stolb_count);
int output(int *arr, int size_str_o, int size_stolb_o, int max_i, int max_j,
           int max_sum, int stolb_count);

int main() {
  int str_count = 0, stolb_count = 0, size_str_o, size_stolb_o, max_sum = 0,
      max_i = 0, max_j = 0, arr[225], i = 0, j = 0;
  system("chcp 1251 > NUL");
  input_arr(arr, &str_count, &stolb_count);

  input_size_oblast(str_count, stolb_count, &size_str_o, &size_stolb_o);

  find_max_oblast(arr, str_count, stolb_count, size_str_o, size_stolb_o, &max_i,
                  &max_j, &max_sum);

  printf("Для матрицы:\n");
  for (i = 0; i < str_count; i++) { /*Вывод начальной матрицы*/
    for (j = 0; j < stolb_count; j++) {
      printf("[%d] ", *((arr + i * stolb_count) + j));
    }
    printf("\n");
  }

  output(arr, size_str_o, size_stolb_o, max_i, max_j, max_sum, stolb_count);
  system("pause");
  return 0;
}

int input_arr(int *arr, int *str_count, int *stolb_count) {
  int i = 0, j = 0;
  printf("Введите количество строк и столбцов матрицы от 1 до 15 каждый: ");
  while ((scanf("%d%d", str_count, stolb_count) != 2) || *str_count < 1 ||
         *str_count > 15 || *str_count < 1 || *str_count > 15) {
    printf("Неверный ввод чисел!\n");
    printf("Введите количество строк и столбцов матрицы от 1 до 15 каждый:");
    fflush(stdin);
    scanf("%*[^\r\n]");
  }

  for (i = 0; i < *str_count;
       i++) { /*присвоение  значений эллементам матрицы */
    for (j = 0; j < *stolb_count; j++) {
      scanf("%*[^\r\n]");
      printf("Введите значение для эллемента arr[%d][%d]: ", i, j);
      while (scanf("%d", (arr + i * *stolb_count) + j) != 1) {
        scanf("%*[^\r\n]");
        printf("Неверный ввод чисел!\n");
        printf("Введите значение для эллемента ar[%d][%d]: ", i, j);
        fflush(stdin);
      }
    }
  }
  return 0;
}

int input_size_oblast(int str_count, int stolb_count, int *size_str_o,
                      int *size_stolb_o) {
  printf("Введите размер прямоугольной области: ");
  scanf("%*[^\r\n]");
  while ((scanf("%d%d", size_str_o, size_stolb_o) != 2 ||
          *size_str_o > str_count || *size_stolb_o > stolb_count ||
          *size_str_o < 0 || *size_stolb_o < 0)) {
    printf("Неверный ввод чисел!\n");
    printf("Введите размер группы в рамках матрицы: ");
    fflush(stdin);
    scanf("%*[^\r\n]");
  }
  return 0;
}

int find_max_oblast(int *arr, int str_count, int stolb_count, int size_str_o,
                    int size_stolb_o, int *max_i, int *max_j, int *max_sum) {
  int i = 0, j = 0, sum = 0;
  while (i <= str_count - size_str_o) { /*Прохождение по каждой обасти*/
    j = 0;
    while (j <= stolb_count - size_stolb_o) {
      sum = 0;
      calc_sum(arr, size_stolb_o, size_str_o, i, j, &sum, stolb_count);
      if (*max_sum < sum) { /*Сравнение новой суммы и максимальной*/
        *max_sum = sum;
        *max_i = i, *max_j = j; /*Сохранение координат*/
      }
      j++;
    }
    i++;
  }
  return 0;
}

int output(int *arr, int size_str_o, int size_stolb_o, int max_i, int max_j,
           int max_sum, int stolb_count) {
  printf(
      "максимальная сумма = %d\nкоординаты начала:(%d;%d)\n", max_sum,
      max_i + 1,
      max_j + 1); /* Вывод координатов начала области с максимальным значением
                     суммы эллементов со свигом на 1 для НЕпрограммистов*/
  int i = 0, j = 0;
  for (i = max_i; i < max_i + size_str_o;
       i++) { /*Вывод области с максимальным значением суммы эллементов*/
    for (j = max_j; j < max_j + size_stolb_o; j++) {
      printf("[%d] ", *(arr + i * stolb_count + j));
    }
    printf("\n");
  }
  return 0;
}

int calc_sum(int *arr, int size_stolb_o, int size_str_o, int i, int j, int *sum,
             int stolb_count) {
  int k = 0, l = 0;
  for (; l < size_str_o; l++) { /*Вычисление суммы эллементов области*/
    k = 0;
    for (; k < size_stolb_o; k++) {
      *sum += arr[(i + l) * stolb_count + j + k];
    }
  }
  return 0;
}
