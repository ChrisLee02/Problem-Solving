#include <iostream>
#include <vector>


int d(int n){

    int dn = n;
    while(n!= 0){

        dn += n % 10;
        n /= 10;
    }
    return dn;
}

int main(){
    const int size = 10000;

    bool arr[size-1] = {true,};

    // 생성자로부터 만들어지는 셀프넘버를 전부, false로 취급할것
    for (int i =0 ; i < size;  i++){
        int new_number = d(i);

        if(arr[new_number]){
           
           if(new_number < 10000) arr[new_number] = false;

        }
    }

    for (int j = 0; j < size; j++){

        if(arr[j]) std::cout << j+1 << std::endl;

    }

    return 0;

    
}
