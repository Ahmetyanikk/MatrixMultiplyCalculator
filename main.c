// Malloc için stdlib.h ve zaman için time.h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void matrixMatrixMultiply(int *a,float* arr1,float* arr2,float* arr3){
    // Zamanı tutması için t'i atıyoruz ve zaman tutmaya başlıyor
    clock_t t;
     t = clock();


     // satır ve sütunları gezmek için *a'ı kullanıyoruz
    for (int i=0;i<*a ;i++ ) {
            for (int j=0;j<*a ;j++ ) {
                for (int k=0;k<j ;k++ ) {
                    //pointerla çektiğimiz arrayleri  birbirlerini çarpıp  arr3'e atıyoruz
                *(arr3 + i* *a + j)=*(arr1 + i* *a + j) * *(arr2 + i* *a + j);



                }

            }
       }
    //ölçtüğümüz saatin çıktısını alıyoruz
  t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf(" %f saniye surdu  \n", time_taken);
};






int main()
{
// Matrix boyutunun belirtilmesi
    int a =1000;
    int *p=&a;

    //Malloc ile hafızada yer açılması
   float *arr1 = (float *)malloc(a *a* sizeof(float));
    float *arr2 = (float * )malloc(a*a* sizeof(float));
     float *arr3 = (float * )malloc(a*a* sizeof(float));

 //Matrikslerin rastgele sayılarla doldurulması
     for (int i=0;i<a ;i++ ) {
         for (int j=0;j<a ;j++ ) {
              *(arr1 + i*a + j)= (float)rand();
         }
     }
     for (int i=0;i<a ;i++ ) {
         for (int j=0;j<a ;j++ ) {
             *(arr1 + i*a + j)= (float)rand();
         }
        }
//Kodun çalıştırılması için
     matrixMatrixMultiply(p,arr1,arr2,arr3);

    return 0;
}
