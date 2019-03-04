#include <iostream>

// Armv7-A/AArch32
void add_float_neon3(float* dst, float* src1, float* src2, int count)
{
    asm volatile (
    "1: \n"
    "vld1.32 {q0}, [%[src1]]! \n"
    "vld1.32 {q1}, [%[src2]]! \n"
    "vadd.f32 q0, q0, q1 \n"
    "subs %[count], %[count], #4 \n"
    "vst1.32 {q0}, [%[dst]]! \n"
    "bgt 1b \n"
    : [dst] "+r" (dst)
    : [src1] "r" (src1), [src2] "r" (src2), [count] "r" (count)
    : "memory", "q0", "q1"
    );
}

int main(int argc,char** argv){
   float a[]={1.0f,2.0f,3.0f,4.0f},b[]={1.0f,2.0f,3.0f,4.0f},c[4];
   add_float_neon3(c,a,b,4);
   for(int i=0;i<4;i++){
        std::cout<<c[i]<<",";
   }
   std::cout<<std::endl;
   return 0;
}
