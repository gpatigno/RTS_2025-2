#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/rtc.h>

int main() {
    const char *dev = "/dev/rtc0";     // Cambiar a rtc1 si aplica
    int fd = open(dev, O_RDONLY);
    if (fd < 0) {
        perror("Error abriendo el RTC");
        return 1;
    }

    struct rtc_time rtc;
    if (ioctl(fd, RTC_RD_TIME, &rtc) < 0) {
        perror("Error leyendo el RTC (ioctl)");
        close(fd);
        return 2;
    }

    printf("(%s) Hora RTC DS3231: %04d-%02d-%02d %02d:%02d:%02d\n",
           dev,
           rtc.tm_year + 1900,
           rtc.tm_mon  + 1,
           rtc.tm_mday,
           rtc.tm_hour, rtc.tm_min, rtc.tm_sec);

    close(fd);
    return 0;
}
