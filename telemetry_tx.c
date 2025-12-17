#include <stdio.h>
#include <time.h>
#include <math.h>

#ifdef _WIN32
#include <windows.h>
#define sleep_ms(x) Sleep(x)
#else
#include <unistd.h>
#define sleep_ms(x) usleep(x * 1000)
#endif

long timestamp_ms() {
    return (long)(clock() * 1000 / CLOCKS_PER_SEC);
}

unsigned char checksum(const char *s) {
    unsigned char chk = 0;
    while (*s) {
        chk ^= *s++;
    }
    return chk;
}

int main() {
    float t = 0.0f;

    while (1) {
        float ax = sin(t);
        float ay = cos(t);
        float az = 9.81;

        float gx = 0.1 * t;
        float gy = 0.2 * t;
        float gz = 0.3 * t;

        float altitude = 100.0 + t;
        float temperature = 25.0 + 2.0 * sin(t);

        char frame[256];
        snprintf(frame, sizeof(frame),
            "$L1,%ld,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f",
            timestamp_ms(),
            ax, ay, az,
            gx, gy, gz,
            altitude, temperature);

        unsigned char chk = checksum(frame + 1);
        printf("%s*%02X\n", frame, chk);

        t += 0.05f;
        sleep_ms(50);
    }
}
