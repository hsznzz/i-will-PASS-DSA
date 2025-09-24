#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int hours;
    int minutes;
} Time;

typedef struct {
    int id;
    char airline[50];
    char origin[50];
    char destination[50];
    Time departure_time;
    Time arrival_time;
    int age;
} Flight;

typedef struct {
    Flight arr[MAX];
    int front;
    int rear;
    int count;
} FlightQueue;

/* ---------- Time helpers ---------- */
int timeToMinutes(Time t) {
    return t.hours * 60 + t.minutes;
}

int compareTime(Time t1, Time t2) {
    return timeToMinutes(t1) - timeToMinutes(t2);
}

int calculateFlightDuration(Time departure, Time arrival) {
    int dep = timeToMinutes(departure);
    int arr = timeToMinutes(arrival);
    if (arr < dep) arr += 24 * 60;   // next day arrival
    return arr - dep;
}

int compareDurations(Time dep1, Time arr1, Time dep2, Time arr2) {
    return calculateFlightDuration(dep1, arr1) - calculateFlightDuration(dep2, arr2);
}

/* ---------- Queue helpers ---------- */
static inline bool isEmptyQ(const FlightQueue *q) { return q->count == 0; }
static inline bool isFullQ (const FlightQueue *q) { return q->count == MAX; }

void initQueue(FlightQueue *q) {
    q->front = 0;
    q->rear  = MAX - 1;
    q->count = 0;
}

void enqueueFlight(FlightQueue *q, Flight f) {
    if (isFullQ(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = f;
    q->count++;
}

Flight dequeueFlight(FlightQueue *q) {
    Flight dummy = {0};
    if (isEmptyQ(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return dummy;
    }
    Flight f = q->arr[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    return f;
}

void displayQueue(const FlightQueue *q) {
    if (isEmptyQ(q)) {
        printf("Queue is empty!\n\n");
        return;
    }

    printf("%5s | %20s | %15s | %15s | %10s | %10s | %s\n",
           "ID", "AIRLINE", "ORIGIN", "DESTINATION", "DEPARTURE", "ARRIVAL", "AGE");

    int idx = q->front;
    for (int i = 0; i < q->count; ++i) {
        Flight f = q->arr[idx];
        printf("%5d | %20s | %15s | %15s | %02d:%02d      | %02d:%02d     | %d\n",
               f.id, f.airline, f.origin, f.destination,
               f.departure_time.hours, f.departure_time.minutes,
               f.arrival_time.hours, f.arrival_time.minutes, f.age);
        idx = (idx + 1) % MAX;
    }
    printf("\n");
}

/* ---------- Required features ---------- */
/* Insert into a queue kept sorted by flight duration (ascending). */

void insertSorted(FlightQueue *q, Flight f) {
    if (isFullQ(q)) return;                 

    int n = q->count;                      
    bool inserted = false;

    for (int i = 0; i < n; ++i) {
        Flight cur = dequeueFlight(q);      // take from front

        // Insert f before the first longer flight
        if (!inserted && compareDurations(f.departure_time, f.arrival_time, cur.departure_time, cur.arrival_time) < 0) {
            enqueueFlight(q, f);
            inserted = true;
        }

        enqueueFlight(q, cur);              // keep existing order
    }

    if (!inserted) {
        enqueueFlight(q, f);
    }
}



/* Filter by airline without mutating the original queue. */
FlightQueue *getAirlineList(FlightQueue *q, const char airline[]) {
    FlightQueue *out = malloc(sizeof(FlightQueue));
    if (out != NULL){
        initQueue(out);

        int n   = q->count;
        int idx = q->front;
        for (int i = 0; i < n; ++i) {
            Flight cur = q->arr[idx];
            if (strcmp(cur.airline, airline) == 0) {
                enqueueFlight(out, cur);
            }
            idx = (idx + 1) % MAX;  // use your queue capacity constant
        }
    }   
    return out;
}

/* Remove the FIRST passenger with matching id. Preserves order of others. */
bool removePassenger(FlightQueue *q, int id) {
    if(isEmptyQ(q)) return false;

    bool flag = false;
    int x = 0;
    int count = q->count;

    for(x = 0; x < count; x++){
        Flight check = dequeueFlight(q);
        if(!flag && check.id == id){
            flag = true;
        } else {
            enqueueFlight(q, check);
        }
    }

    return flag;
}

/* Sort the entire queue by ID (ascending), stable enough for small N). */
void sortPassengerByID(FlightQueue *q) {
    int n = q->count;
    if (n <= 1) return;

    FlightQueue out;
    initQueue(&out);

    for (int k = 0; k < n; k++) {
        int m = q->count;           // how many remain
        Flight minF = dequeueFlight(q);
        enqueueFlight(q, minF);

        // 1) find smallest id among the m items
        for (int i = 0; i < m; i++) {
            Flight cur = dequeueFlight(q);
            if (cur.id < minF.id) {
                minF = cur; //container of the smallest id
            }
            enqueueFlight(q, cur);
        }
        

        // 2) append smallest to output
        enqueueFlight(&out, minF);

        // 3) remove first occurrence of that smallest to not double after inputing to out
        int removed = 0;
        for (int i = 0; i < m; i++) {
            Flight cur = dequeueFlight(q);
            if (!removed && cur.id == minF.id) {
                removed = 1;          // drop it (don't re-enqueue)
            } else {
                enqueueFlight(q, cur);
            }
        }
    }

    // 4) move output back into q (now sorted)
    while (!isEmptyQ(&out)) {
        enqueueFlight(q, dequeueFlight(&out));
    }
}



/* ---------- Demo ---------- */
int main(void) {
    FlightQueue q;
    initQueue(&q);

    Flight f1 = {101, "Philippine Airlines", "Manila", "Cebu",   {8, 30},  {10, 0},  25};
    Flight f2 = {102, "Cebu Pacific",        "Cebu",   "Davao",  {11, 0},  {1, 45},  30}; // wraps to next day
    Flight f3 = {103, "AirAsia",             "Manila", "Iloilo", {9, 0},   {11, 30}, 22};
    Flight f4 = {104, "Cebu Pacific",        "Manila", "Cebu",   {14, 0},  {15, 45}, 28};

    printf("Initial empty queue:\n");
    displayQueue(&q);

    printf("Inserting flights (sorted by duration):\n");
    insertSorted(&q, f1);
    insertSorted(&q, f2);
    insertSorted(&q, f3);
    insertSorted(&q, f4);
    displayQueue(&q);

    printf("Getting Cebu Pacific flights:\n");
    FlightQueue *cebuFlights = getAirlineList(&q, "Cebu Pacific");
    if (cebuFlights) {
        displayQueue(cebuFlights);
        free(cebuFlights);
    }

    printf("Removing passenger with ID 101:\n");
    bool removed = removePassenger(&q, 101);
    if (removed) {
        printf("Passenger removed successfully.\n");
    } else {
        printf("Passenger not found.\n");
    }
    displayQueue(&q);

    printf("Sorting passengers by ID:\n");
    sortPassengerByID(&q);
    displayQueue(&q);

    return 0;
}
