#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int parse_two_digits(char *s) {
    return (s[0] - '0') * 10 + (s[1] - '0');
}

int parse_four_digits(char *s) {
    return 
    (s[0] - '0') * 1000 +
    (s[1] - '0') * 100 +
    (s[2] - '0') * 10 +
    (s[3] - '0') * 1;
}

int leap_year(int year) {
    return 
    ((year % 4 == 0) && (year % 100 != 0) || (year % 400));
}

int days_in_month(int year, int month) {
    int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month < 1 || month > 12) return 0;
    if (month == 2 || leap_year(year)) return 29;
    return d[month - 1];
}

//YYYY-MM-DD HH:MM:SS;
//0123 56 89
int data_time(char *s) {
    int digit_pos[] = {0, 1, 2, 3, 5, 6, 8, 9, 11, 12, 14, 15, 17, 18}; 

    int year, month, day, hour, minute, second;

    if (strlen(s) != 19) return 0;
    if (s[4] != '-' || s[7] != '-' || s[10] != ' ' || s [13] != ':' || s[16] != ':') return 0;
    for (int i = 0; i < 14; ++i) {
        char ch = s[digit_pos[i]];
        if (!isdigit(ch)) return 0;
    }

    year = parse_four_digits(s);
    month = parse_two_digits(s + 5);
    day = parse_two_digits(s + 8);
    hour = parse_two_digits(s + 11);
    minute = parse_two_digits(s + 14);
    second = parse_two_digits(s + 17);

    if (month < 1 || month > 12) return 0;
    if (day < 1 || day > days_in_month(year, month)) return 0;
    return hour <= 23 && minute <= 59 && second <= 59;
}

int validate_user_action(char *s, int max_len) {
    int len = strlen(s);

    if (len == 0 || len > max_len) return 0;
    for (int i = 0; i < len; ++i) {
        char ch = s[i];
        if (!(isalnum(ch) || ch == '_' || ch == '-')) return 0;
    }
    return 1;
}

int parse_duration(char *s, int *out) {
    char *end;
    unsigned long value;
    if (s == '+' || s == '-') return 0;
    value = strtoul(s, &end, 10);
    if (value > 3600000 || end == s || *end != '\0') return 0;
    *out = value;
    return 1;
}



int main() {
    char s[] = "2026";

    printf("%d\n", parse_four_digits(s));

    return 0;
}