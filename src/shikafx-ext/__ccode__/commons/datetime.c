#include "./datetime.h"

int WeekdayKind_toInt(WeekdayKind weekdays) {
    return (int)weekdays;
}

WeekdayKind WeekdayKind_parseInt(int weekdays) {
    if (0 <= weekdays && weekdays < 7) return (WeekdayKind)weekdays;
    panic("invalid weekday value, must be between 0 and 6 inclusive");
    return Monday;
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

const data_t* WeekdayKind_toString(WeekdayKind weekdays) {
    const char* name = weekdayNames[weekdays];
    const size_t size = strlen(name);
    byte_t* temp = create_byte_stack(size);
    memcpy(temp, name, size);
    return create_data(temp, strlen(name));
}

WeekdayKind WeekdayKind_parse(data_t* data) {
    const data_t* temp = data_toLowerCase(data_toTrim(data));
    const char* name = (const char*)temp->data;
    size_t size = temp->size;


}

int MonthKind_toInt(MonthKind months) {
    return (int)months;
}

MonthKind MonthKind_parseInt(int months) {
    if (1 <= months && months < 13) return (MonthKind)months;
    panic("invalid weekday value, must be between 1 and 12 inclusive");
    return January;
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

const data_t* MonthKind_toString(MonthKind months) {
    const char* name = monthNames[months];
    const size_t size = strlen(name);
    byte_t* temp = create_byte_stack(size);
    memcpy(temp, name, size);
    return create_data(temp, strlen(name));
}

MonthKind MonthKind_parse(data_t* data) {

}
