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
    TimeZoneKind_UTC,
    TimeZoneKind_Local
} TimeZoneKind;

typedef enum {
    WeekdayKind_Monday = 0, // index
    WeekdayKind_Tuesday,
    WeekdayKind_Wednesday,
    WeekdayKind_Thursday,
    WeekdayKind_Friday,
    WeekdayKind_Saturday,
    WeekdayKind_Sunday,
} WeekdayKind;

typedef enum {
    MonthKind_January = 1, // position
    MonthKind_February,
    MonthKind_March,
    MonthKind_April,
    MonthKind_May,
    MonthKind_June,
    MonthKind_July,
    MonthKind_August,
    MonthKind_September,
    MonthKind_October,
    MonthKind_November,
    MonthKind_December,
} MonthKind;

static const char* weekdayNames[7];
static const char* monthNames[12];

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
    TimeZoneKind timezone;
} timedelta_t;

typedef struct {
    timedelta_t* timedelta;
    timedelta_t* timedeltaSeed;
    duration_Us_t microseconds;
    duration_Ns_t nanoseconds;
    timestamp_Ms_t timestamp;
    TimeZoneKind timezone;
    WeekdayKind weekdays;
} datetime_t;

int WeekdayKind_toInt(WeekdayKind weekdays);
WeekdayKind WeekdayKind_parseInt(int weekdays);

WeekdayKind WeekdayKind_next(WeekdayKind weekdays);
WeekdayKind WeekdayKind_prev(WeekdayKind weekdays);

const data_t* WeekdayKind_getName(WeekdayKind weekdays);
WeekdayKind WeekdayKind_parse(data_t* data);

int MonthKind_toInt(MonthKind months);
MonthKind MonthKind_parseInt(int months);

MonthKind MonthKind_next(MonthKind months);
MonthKind MonthKind_prev(MonthKind months);

const data_t* MonthKind_getName(MonthKind months);
MonthKind MonthKind_parse(data_t* data);

const timedelta_t* create_timedelta(
    duration_y_t years,
    duration_m_t months,
    duration_d_t days,
    duration_H_t hours,
    duration_M_t minutes,
    duration_S_t seconds,
    duration_Ms_t milliseconds,
    duration_Us_t microseconds,
    duration_Ns_t nanoseconds,
    TimeZoneKind timezone
);

void drop_timedelta(const timedelta_t* timedelta);

const datetime_t* create_datetime(
    timedelta_t* timedelta,
    timedelta_t* timedeltaSeed,
    duration_Us_t microseconds,
    duration_Ns_t nanoseconds,
    timestamp_Ms_t timestamp,
    TimeZoneKind timezone,
    WeekdayKind weekdays
);

void drop_datetime(const datetime_t* datetime);

static const timedelta_t* TIMEDELTA_ZERO_VAL;
static const timedelta_t* TIMEDELTA_ZERO_UTC;
static const datetime_t* TIMEDELTA_SEEDS[6];

const timedelta_t* timedelta_copy(const timedelta_t* timedelta);
const datetime_t* datetime_copy(const datetime_t* datetime);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_SHIKAFX_EXTRAS_COMMON_DATETIME
