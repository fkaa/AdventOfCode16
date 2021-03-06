#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(__APPLE__)
#  define COMMON_DIGEST_FOR_OPENSSL
#  include <CommonCrypto/CommonDigest.h>
#else
#  include <openssl/md5.h>
#endif

inline void md5(MD5_CTX *c, const char *str, int length, unsigned char out[static 17]) {
    MD5_Init(c);
    MD5_Update(c, str, length);
    MD5_Final(out, c);
}


int main(int argc, char *argv[]) {
    MD5_CTX c;

    unsigned char hash[17] = {0};
    char pwd[9] = {0};
    char input[64] = "wtnhxymk";

    char *cur = pwd;
    int n = 0;

    while (cur != &pwd[8]) {
        int sz = snprintf(&input[8], 56, "%d", n++);
        md5(&c, input, 8 + sz, hash);

        if (!memcmp("\0\0", hash, 2) && hash[2] < 16) {
            sprintf(cur++, "%01x", hash[2]);
        }
    }

    printf("%s\n", pwd);

    return 0;
}


