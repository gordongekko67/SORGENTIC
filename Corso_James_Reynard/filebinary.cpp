#include <iostream>
#include <string>

using  namespace std;

struct bitmap_file_header {

    char header[2]={'B', 'M'};
    int32_t file_size;
    int32_t reserved=0;
    int32_t data_offset;


};



int main(){



    return 0;
}


