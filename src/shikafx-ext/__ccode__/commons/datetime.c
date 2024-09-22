#include "./datetime.h"

static const char* weekdayNames[7] = {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday",
};

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

int WeekdayKind_toInt(WeekdayKind weekdays) {
    return (int)weekdays;
}

WeekdayKind WeekdayKind_parseInt(int weekdays) {
    if (0 <= weekdays && weekdays < 7) return (WeekdayKind)weekdays;
    panic("invalid weekday value, must be between 0 and 6 inclusive");
    return WeekdayKind_Monday;
}

WeekdayKind WeekdayKind_next(WeekdayKind weekdays) {
    int idx = WeekdayKind_toInt(weekdays) + 1;
    if (7 <= idx) idx += -7;
    return WeekdayKind_parseInt(idx);
}

WeekdayKind WeekdayKind_prev(WeekdayKind weekdays) {
    int idx = WeekdayKind_toInt(weekdays) - 1;
    if (idx < 0) idx += 7;
    return WeekdayKind_parseInt(idx);
}

const data_t* WeekdayKind_getName(WeekdayKind weekdays) {
    int idx = WeekdayKind_toInt(weekdays); // index
    const char* name = weekdayNames[idx];
    const size_t count = strlen(name);
    byte_t* temp = create_byte_stack(count);
    memcpy(temp, name, count);
    return create_data(temp, strlen(name));
}

WeekdayKind WeekdayKind_parse(data_t* data) {
    const data_t* temp = data_toTitleCase(data);
    size_t size = temp->size;
    for (int i = 0; i < 7; i++) {
        WeekdayKind weekdays = WeekdayKind_parseInt(i);
        const data_t* name = WeekdayKind_getName(weekdays);
        if (size <= name->size) {
            if (size == name->size) {
                if (data_eq(temp, name)) {
                    WeekdayKind result = WeekdayKind_parseInt(i);
                    DROP_DATA_M(name, temp);
                    return result;
                }
                drop_data(name, true);
                continue;
            }
            const data_t* short_name = data_slice(name, size);
            if (data_eq(temp, short_name)) {
                WeekdayKind result = WeekdayKind_parseInt(i);
                DROP_DATA_M(short_name, name, temp);
                return result;
            }
            drop_data(short_name, true);
        }
        drop_data(name, true);
    }
    drop_data(temp, true);
    panic("unable to parse, the provided data into a valid weekdays");
    return WeekdayKind_Monday;
}

int MonthKind_toInt(MonthKind months) {
    return (int)months;
}

MonthKind MonthKind_parseInt(int months) {
    if (1 <= months && months < 13) return (MonthKind)months;
    panic("invalid weekday value, must be between 1 and 12 inclusive");
    return MonthKind_January;
}

MonthKind MonthKind_next(MonthKind months) {
    int idx = MonthKind_toInt(months) + 1;
    if (13 <= idx) idx += -12;
    return MonthKind_parseInt(idx);
}

MonthKind MonthKind_prev(MonthKind months) {
    int idx = MonthKind_toInt(months) - 1;
    if (idx < 1) idx += 12;
    return MonthKind_parseInt(idx);
}

const data_t* MonthKind_getName(MonthKind months) {
    int idx = MonthKind_toInt(months) - 1; // position
    const char* name = monthNames[idx];
    const size_t count = strlen(name);
    byte_t* temp = create_byte_stack(count);
    memcpy(temp, name, count);
    return create_data(temp, strlen(name));
}

MonthKind MonthKind_parse(data_t* data) {
    const data_t* temp = data_toTitleCase(data);
    size_t size = temp->size;
    for (int i = 1; i < 13; i++) {
        MonthKind months = MonthKind_parseInt(i);
        const data_t* name = MonthKind_getName(months);
        if (size <= name->size) {
            if (size == name->size) {
                if (data_eq(temp, name)) {
                    MonthKind result = MonthKind_parseInt(i);
                    DROP_DATA_M(name, temp);
                    return result;
                }
                drop_data(name, true);
                continue;
            }
            const data_t* short_name = data_slice(name, size);
            if (data_eq(temp, short_name)) {
                MonthKind result = MonthKind_parseInt(i);
                DROP_DATA_M(short_name, name, temp);
                return result;
            }
            drop_data(short_name, true);
        }
        drop_data(name, true);
    }
    drop_data(temp, true);
    panic("unable to parse, the provided data into a valid months");
    return MonthKind_January;
}

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
) {
#ifdef DEBUG
    printf("[CC] create memory allocator for <timedelta_t> pointer\n");
#endif

    timedelta_t* ptr = malloc(sizeof *ptr);
    ptr->years = years;
    ptr->months = months;
    ptr->days = days;
    ptr->hours = hours;
    ptr->minutes = minutes;
    ptr->seconds = seconds;
    ptr->milliseconds = milliseconds;
    ptr->microseconds = microseconds;
    ptr->nanoseconds = nanoseconds;
    ptr->timezone = timezone;
    return ptr;
}

void drop_timedelta(const timedelta_t* timedelta) {
    timedelta_t* ptr = (timedelta_t*)timedelta;
    if (ptr == NULL) return;

#ifdef DEBUG
    printf("[CC] free up memory allocator for <timedelta_t> pointer\n");
#endif

    free(ptr);
}

const datetime_t* create_datetime(
    timedelta_t* timedelta,
    timedelta_t* timedeltaSeed,
    duration_Us_t microseconds,
    duration_Ns_t nanoseconds,
    timestamp_Ms_t timestamp,
    TimeZoneKind timezone,
    WeekdayKind weekdays
) {
#ifdef DEBUG
    printf("[CC] create memory allocator for <datetime_t> pointer\n");
#endif

    datetime_t* ptr = malloc(sizeof *ptr);
    ptr->timedelta = timedelta;
    ptr->timedeltaSeed = timedeltaSeed;
    ptr->microseconds = microseconds;
    ptr->nanoseconds = nanoseconds;
    ptr->timestamp = timestamp;
    ptr->timezone = timezone;
    ptr->weekdays = weekdays;
    return ptr;
}

void drop_datetime(const datetime_t* datetime) {
    datetime_t* ptr = (datetime_t*)datetime;
    if (ptr == NULL) return;

#ifdef DEBUG
    printf("[CC] free up memory allocator for <datetime_t> pointer\n");
#endif

    drop_timedelta(ptr->timedelta);
    drop_timedelta(ptr->timedeltaSeed);
    free(ptr);
}

static const timedelta_t* TIMEDELTA_ZERO_VAL = &(timedelta_t){
    .years = 0,
    .months = 0,
    .days = 0,
    .hours = 0,
    .minutes = 0,
    .seconds = 0,
    .milliseconds = 0,
    .microseconds = 0,
    .timezone = TimeZoneKind_UTC
};

static const timedelta_t* TIMEDELTA_ZERO_UTC = &(timedelta_t){
    .years = 1970,
    .months = 1,
    .days = 1,
    .hours = 0,
    .minutes = 0,
    .seconds = 0,
    .milliseconds = 0,
    .microseconds = 0,
    .timezone = TimeZoneKind_UTC
};

static const datetime_t* TIMEDELTA_SEEDS[6] = {
    &(datetime_t){
        .timedelta = NULL,
        .timedeltaSeed = &(timedelta_t){
            .years = 2020,
            .months = 1,
            .days = 1,
            .hours = 0,
            .minutes = 0,
            .seconds = 0,
            .milliseconds = 0,
            .microseconds = 0,
            .timezone = TimeZoneKind_UTC
        },
        .microseconds = 0,
        .nanoseconds = 0,
        .timestamp = 1577836800000,
        .timezone = TimeZoneKind_UTC,
        .weekdays = 2
    },
    &(datetime_t){
        .timedelta = NULL,
        .timedeltaSeed = &(timedelta_t){
            .years = 2010,
            .months = 1,
            .days = 1,
            .hours = 0,
            .minutes = 0,
            .seconds = 0,
            .milliseconds = 0,
            .microseconds = 0,
            .timezone = TimeZoneKind_UTC
        },
        .microseconds = 0,
        .nanoseconds = 0,
        .timestamp = 1262304000000,
        .timezone = TimeZoneKind_UTC,
        .weekdays = 4
    },
    &(datetime_t){
        .timedelta = NULL,
        .timedeltaSeed = &(timedelta_t){
            .years = 2000,
            .months = 1,
            .days = 1,
            .hours = 0,
            .minutes = 0,
            .seconds = 0,
            .milliseconds = 0,
            .microseconds = 0,
            .timezone = TimeZoneKind_UTC
        },
        .microseconds = 0,
        .nanoseconds = 0,
        .timestamp = 946684800000,
        .timezone = TimeZoneKind_UTC,
        .weekdays = 5
    },
    &(datetime_t){
        .timedelta = NULL,
        .timedeltaSeed = &(timedelta_t){
            .years = 1990,
            .months = 1,
            .days = 1,
            .hours = 0,
            .minutes = 0,
            .seconds = 0,
            .milliseconds = 0,
            .microseconds = 0,
            .timezone = TimeZoneKind_UTC
        },
        .microseconds = 0,
        .nanoseconds = 0,
        .timestamp = 631152000000,
        .timezone = TimeZoneKind_UTC,
        .weekdays = 0
    },
    &(datetime_t){
        .timedelta = NULL,
        .timedeltaSeed = &(timedelta_t){
            .years = 1980,
            .months = 1,
            .days = 1,
            .hours = 0,
            .minutes = 0,
            .seconds = 0,
            .milliseconds = 0,
            .microseconds = 0,
            .timezone = TimeZoneKind_UTC
        },
        .microseconds = 0,
        .nanoseconds = 0,
        .timestamp = 315532800000,
        .timezone = TimeZoneKind_UTC,
        .weekdays = 1
    },
    &(datetime_t){
        .timedelta = NULL,
        .timedeltaSeed = &(timedelta_t){
            .years = 1970,
            .months = 1,
            .days = 1,
            .hours = 0,
            .minutes = 0,
            .seconds = 0,
            .milliseconds = 0,
            .microseconds = 0,
            .timezone = TimeZoneKind_UTC
        },
        .microseconds = 0,
        .nanoseconds = 0,
        .timestamp = 0,
        .timezone = TimeZoneKind_UTC,
        .weekdays = 3
    }
};

const timedelta_t* timedelta_copy(const timedelta_t* timedelta) {
    if (timedelta == NULL) return NULL;
    return create_timedelta(
        timedelta->years,
        timedelta->months,
        timedelta->days,
        timedelta->hours,
        timedelta->minutes,
        timedelta->seconds,
        timedelta->milliseconds,
        timedelta->microseconds,
        timedelta->nanoseconds,
        timedelta->timezone
    );
}

const datetime_t* datetime_copy(const datetime_t* datetime) {
    if (datetime == NULL) return NULL;
    timedelta_t* timedelta = (timedelta_t*)timedelta_copy(datetime->timedelta);
    timedelta_t* timedeltaSeed = (timedelta_t*)timedelta_copy(datetime->timedeltaSeed);
    return create_datetime(
        timedelta,
        timedeltaSeed,
        datetime->microseconds,
        datetime->nanoseconds,
        datetime->timestamp,
        datetime->timezone,
        datetime->weekdays
    );
}


