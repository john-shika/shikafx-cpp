#ifndef C_SHIKAFX_EXTRAS_COMMON_DATETIME
#define C_SHIKAFX_EXTRAS_COMMON_DATETIME

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef int64_t timestamp_Ms_t;

// date
typedef int duration_y_t;
typedef int duration_m_t;
typedef int duration_d_t;

// time
typedef int duration_H_t;
typedef int duration_M_t;
typedef int duration_S_t;

// watch
typedef int duration_Ms_t;
typedef int duration_Us_t;
typedef int duration_Ns_t;

static const duration_y_t MONTHS_IN_YEAR = 12;
static const duration_d_t DAYS_IN_YEAR = 365;
static const duration_d_t DAYS_IN_LEAP_YEAR = 366;
static const duration_d_t DAYS_IN_WEEK = 7;

// time
static const duration_H_t HOURS_IN_DAY = 24;
static const duration_M_t MINUTES_IN_HOUR = 60;
static const duration_S_t SECONDS_IN_MINUTE = 60;

// watch
static const duration_Ms_t MILLISECONDS_IN_SECOND = 1000;
static const duration_Us_t MICROSECONDS_IN_MILLISECOND = 1000;
static const duration_Ns_t NANOSECONDS_IN_MICROSECOND = 1000;

typedef enum {
    UTC,
    Local
} TimeZoneKind;

typedef enum {
    Monday = 0, // index
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday,
} WeekdayKind;

static const char* weekdayNames[7] = {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday",
};

typedef enum {
    January = 1, // position
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
} MonthKind;

static const char* monthNames[12] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December",
};

typedef struct {
    duration_y_t years;
    duration_m_t months;
    duration_d_t days;
    duration_H_t hours;
    duration_M_t minutes;
    duration_S_t seconds;
    duration_Ms_t milliseconds;
    duration_Us_t microseconds;
    duration_Ns_t nanoseconds;
} timedelta_t;

typedef struct {
    timedelta_t timedelta;
    TimeZoneKind timezone;
    timestamp_Ms_t timestamp;
    duration_Ms_t microseconds;
    duration_Ns_t nanoseconds;
    WeekdayKind weekdays;
} dateTimeCache_t;

typedef struct {
    dateTimeCache_t dateTimeCache;
    timedelta_t timedelta;
} datetime_t;

int WeekdayKind_toInt(WeekdayKind weekdays);
WeekdayKind WeekdayKind_parseInt(int weekdays);

WeekdayKind WeekdayKind_next(WeekdayKind weekdays);
WeekdayKind WeekdayKind_prev(WeekdayKind weekdays);

const data_t* WeekdayKind_toString(WeekdayKind weekdays);
WeekdayKind WeekdayKind_parse(data_t* data);

int MonthKind_toInt(MonthKind months);
MonthKind MonthKind_parseInt(int months);

MonthKind MonthKind_next(MonthKind months);
MonthKind MonthKind_prev(MonthKind months);

const data_t* MonthKind_toString(MonthKind months);
MonthKind MonthKind_parse(data_t* data);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_SHIKAFX_EXTRAS_COMMON_DATETIME
