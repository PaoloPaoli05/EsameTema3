//
// Created by paolo on 13/07/2025.
//
#include <gtest/gtest.h>
#include "Day.h"
#include "Activity.h"

//test per verificare l'aggiunta di attività
TEST(DayTest, AddActivity) {
    Day day;
    Activity activity1("Riunione", "Divisione dei ruoli", "09:00", "10:00");
    Activity activity2("Pranzo", "Pausa pranzo", "12:30", "13:30");

    //aggiunta prima attività
    day.addActivity(activity1);
    auto activities = day.getDayActivities();
    ASSERT_EQ(activities.size(), 1);
    EXPECT_EQ(activities[0].getName(), "Riunione");

    // Aggiunta seconda attività
    day.addActivity(activity2);
    activities = day.getDayActivities();
    ASSERT_EQ(activities.size(), 2);
    EXPECT_EQ(activities[1].getName(), "Pranzo");
}

//test per verificare la rimozione di attività
TEST(DayTest, RemoveActivity) {
    Day day;
    Activity activity1("Riunione", "Divisione dei ruoli", "09:00", "10:00");
    Activity activity2("Pranzo", "Pausa pranzo", "12:30", "13:30");

    day.addActivity(activity1);
    day.addActivity(activity2);

    //rimozione attività esistente
    day.removeActivity("Riunione");
    auto activities = day.getDayActivities();
    ASSERT_EQ(activities.size(), 1);
    EXPECT_EQ(activities[0].getName(), "Pranzo");

    //tentativo di rimozione attività non esistente
    EXPECT_THROW(day.removeActivity("Non esistente"), std::invalid_argument);
    activities = day.getDayActivities();
    ASSERT_EQ(activities.size(), 1);
}


//test per verificare l'ordine di inserimento delle attività e getter
TEST(DayTest, ActivitiesOrder) {
    Day day;
    Activity activity1("Prima", "Prima attività", "09:00", "10:00");
    Activity activity2("Seconda", "Seconda attività", "11:00", "12:00");
    Activity activity3("Terza", "Terza attività", "13:00", "14:00");

    day.addActivity(activity1);
    day.addActivity(activity2);
    day.addActivity(activity3);

    auto activities = day.getDayActivities();
    ASSERT_EQ(activities.size(), 3);
    EXPECT_EQ(activities[0].getName(), "Prima");
    EXPECT_EQ(activities[1].getName(), "Seconda");
    EXPECT_EQ(activities[2].getName(), "Terza");
}

//test per verificare la rimozione di attività con lo stesso nome
TEST(DayTest, RemoveDuplicateActivity) {
    Day day;
    Activity activity1("Nome", "Prima", "09:00", "10:00");
    Activity activity2("Nome", "Seconda", "11:00", "12:00");

    day.addActivity(activity1);
    day.addActivity(activity2);

    day.removeActivity("Nome");
    auto activities = day.getDayActivities();
    ASSERT_EQ(activities.size(), 1);
    EXPECT_EQ(activities[0].getDescription(), "Seconda");
}
