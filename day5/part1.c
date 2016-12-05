#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(__APPLE__)
#  define COMMON_DIGEST_FOR_OPENSSL
#  include <CommonCrypto/CommonDigest.h>
#else
#  include <openssl/md5.h>
#endif

void md5(const char *str, int length, char out[static 8]) {
    unsigned char digest[MD5_DIGEST_LENGTH];

    MD5_CTX c;

    MD5_Init(&c);
    MD5_Update(&c, str, length);
    MD5_Final(digest, &c);

    snprintf(out, 8, "%02x%02x%02x%02x", digest[0], digest[1], digest[2], digest[3]);
}


int main(int argc, char *argv[]) {
    char hash[9] = {0};
    char pwd[9] = {0};
    char input[64] = "wtnhxymk";

    char *cur = pwd;
    int n = 0;

    while (cur != &pwd[8]) {
        int sz = snprintf(&input[8], 56, "%d", n++);
        md5(input, 8 + sz, hash);

        if (!memcmp("00000", hash, 5)) {
            *cur++ = hash[5];
        }
    }

    printf("%s\n", pwd);

    return 0;
}


