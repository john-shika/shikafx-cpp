#ifndef C_SHIKAFX_EXTRAS_COMMON_DATETIME
#define C_SHIKAFX_EXTRAS_COMMON_DATETIME

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef int64_t Timestamp_Ms_t;

// date
typedef int Duration_y_t;
typedef int Duration_m_t;
typedef int Duration_d_t;

// time
typedef int Duration_H_t;
typedef int Duration_M_t;
typedef int Duration_S_t;

// watch
typedef int Duration_Ms_t;
typedef int Duration_Us_t;
typedef int Duration_Ns_t;

static const Duration_y_t MONTHS_IN_YEAR = 12;
static const Duration_d_t DAYS_IN_YEAR = 365;
static const Duration_d_t DAYS_IN_LEAP_YEAR = 366;
static const Duration_d_t DAYS_IN_WEEK = 7;

// time
static const Duration_H_t HOURS_IN_DAY = 24;
static const Duration_M_t MINUTES_IN_HOUR = 60;
static const Duration_S_t SECONDS_IN_MINUTE = 60;

// watch
static const Duration_Ms_t MILLISECONDS_IN_SECOND = 1000;
static const Duration_Us_t MICROSECONDS_IN_MILLISECOND = 1000;
static const Duration_Ns_t NANOSECONDS_IN_MICROSECOND = 1000;

typedef enum {
    UTC,
    Local
} TimeZone_k;

typedef enum {
    Monday = 0,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday,
} Weekdays_k;

Weekdays_k Weekdays_parse(const char* name);
const char* Weekdays_toString(Weekdays_k weekdaysKind);

typedef enum {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December,
} Months_k;

Months_k Months_parse(const char* name);
const char* Months_toString(Months_k monthsKind);

typedef struct {
    Duration_y_t years;
    Duration_m_t months;
    Duration_d_t days;
    Duration_H_t hours;
    Duration_M_t minutes;
    Duration_S_t seconds;
    Duration_Ms_t milliseconds;
    Duration_Us_t microseconds;
    Duration_Ns_t nanoseconds;
} Timedelta_t;

typedef struct {
    Timedelta_t m_timedelta;
    TimeZone_k m_timezone;
    Timestamp_Ms_t m_timestamp;
    Duration_Ms_t m_microseconds;
    Duration_Ns_t m_nanoseconds;
    Weekdays_k m_weekdays;
} DateTimePreload_t;

typedef struct {
    DateTimePreload_t m_dateTimeCache;
    Timedelta_t m_timedelta;
} DateTime_t;

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_SHIKAFX_EXTRAS_COMMON_DATETIME
