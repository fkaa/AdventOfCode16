#include <stdlib.h>
#include <stdio.h>
#include <immintrin.h>

int main(int argc, char *argv[argc + 1]) {
    __m128i triangles = _mm_set1_epi32(0);
    int nums[12] = {0};
    while (scanf(" %d %d %d\n"
                 " %d %d %d\n"
                 " %d %d %d\n", &nums[0], &nums[1], &nums[2],
                                &nums[4], &nums[5], &nums[6],
                                &nums[8], &nums[9], &nums[10]) > 0)
    {
        __m128i a = _mm_load_si128((__m128i*)&nums[0]),
                b = _mm_load_si128((__m128i*)&nums[4]),
                c = _mm_load_si128((__m128i*)&nums[8]);
        __m128i r1, r2, r3;

        r1 = _mm_add_epi32(a, b);
        r2 = _mm_add_epi32(b, c);
        r3 = _mm_add_epi32(c, a);

        a = _mm_cmpgt_epi32(r2, a);
        b = _mm_cmpgt_epi32(r3, b);
        c = _mm_cmpgt_epi32(r1, c);

        triangles = _mm_add_epi32(triangles, _mm_and_si128(_mm_and_si128(a, b), c));
    }

    triangles = _mm_add_epi32(triangles, _mm_srli_si128(triangles, 8));
    triangles = _mm_add_epi32(triangles, _mm_srli_si128(triangles, 4));

    printf("%d\n", -_mm_cvtsi128_si32(triangles));

    return 0;
}


