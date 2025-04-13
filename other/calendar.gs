function doGet(e) {
  var calendars = CalendarApp.getAllCalendars();
  //var cal = CalendarApp.getCalendarsByName('NAME_OF_CALENDAR')[0]; // 0 is subcalendar ID, mostly "0"
  //var cal = CalendarApp.getDefaultCalendar();
  var calendars = CalendarApp.getAllCalendars();

  if (calendars == undefined) {
    Logger.log("No data");
    return ContentService.createTextOutput("no access to calendar hubba");
  }
  var calendars_selected = [];

  for (var ii = 0; ii < calendars.length; ii++) {
    if (calendars[ii].isSelected()) {
      calendars_selected.push(calendars[ii]);
      Logger.log(calendars[ii].getName());
    }
  }

  Logger.log("Old: " + calendars.length + " New: " + calendars_selected.length);
  const now = new Date();
  var start = new Date();
  // start.setHours(0, 0, 0);  // start at midnight
  const oneday = 24 * 3600000; // [msec]
  const stop = new Date(start.getTime() + 1 * oneday); //get appointments for the next 14 days

  //var events = cal.getEvents(start, stop); //pull start/stop time
  var events = mergeCalendarEvents(calendars_selected, start, stop); //pull start/stop time

  var j = 0;
  var str = "";
  for (var ii = 0; ii < events.length && j < 2; ii++) {
    var event = events[ii];
    var myStatus = event.getMyStatus();

    // define valid entryStatus to populate array
    switch (myStatus) {
      case CalendarApp.GuestStatus.OWNER:
      case CalendarApp.GuestStatus.YES:
      case CalendarApp.GuestStatus.NO:
      case CalendarApp.GuestStatus.INVITED:
      case CalendarApp.GuestStatus.MAYBE:
      default:
        break;
    }

    // Show just every entry regardless of GuestStatus to also get events from shared calendars where you haven't set up the appointment on your own
    // str += event.getStartTime() + ';' +
    // //event.isAllDayEvent() + '\t' +
    // //event.getPopupReminders()[0] + '\t' +
    // event.getTitle() +';' +
    // event.isAllDayEvent() + ';';

    // time
    var time_str;
    if (event.isAllDayEvent()) {
      time_str = "ALL D";
      continue;
    } else {
      var time = event.getStartTime();
      time_str = time.toTimeString().slice(0, 5);
    }

    // title - shorten to 12 chars
    var title = event.getTitle();
    title = title.replace(/[^A-Za-z0-9 ]/g, "");
    title = title.replace(/^\s+/g, "");

    const title_length = title.length;
    if (title_length < 12) {
      title = title.padEnd(12);
    } else if (title_length > 12) {
      title = title.slice(0, 10);
      title = title.padEnd(12, ".");
    }

    j++;
    str += time_str + "↘;" + title + ";";
  }

  Logger.log(str);
  return ContentService.createTextOutput(str);
}
function mergeCalendarEvents(calendars, startTime, endTime) {
  var params = { start: startTime, end: endTime, uniqueIds: [] };
  return calendars
    .map(toUniqueEvents_, params)
    .reduce(toSingleArray_)
    .sort(byStart_);
}
function toCalendars_(id) {
  return CalendarApp.getCalendarById(id);
}
function toUniqueEvents_(calendar) {
  return calendar
    .getEvents(this.start, this.end)
    .filter(onlyUniqueEvents_, this.uniqueIds);
}
function onlyUniqueEvents_(event) {
  var eventId = event.getId();
  var uniqueEvent = this.indexOf(eventId) < 0;
  if (uniqueEvent) this.push(eventId);
  return uniqueEvent;
}
function toSingleArray_(a, b) {
  return a.concat(b);
}
function byStart_(a, b) {
  return a.getStartTime().getTime() - b.getStartTime().getTime();
}
