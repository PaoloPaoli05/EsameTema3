//
// Created by paolo on 13/07/2025.
//
#include <gtest/gtest.h>
#include "Activity.h"


//test per il costruttore e i getter con valori validi
TEST(ActivityTest, ConstructorAndGettersWithValidValues) {
    Activity activity("Meeting", "Team sync", "09:00", "10:30");

    EXPECT_EQ(activity.getName(), "Meeting");
    EXPECT_EQ(activity.getDescription(), "Team sync");
    EXPECT_EQ(activity.getStartingTime(), "09:00");
    EXPECT_EQ(activity.getEndingTime(), "10:30");
    EXPECT_EQ(activity.getDuration(), "01:30");
}

//test per il costruttore con nome non valido
TEST(ActivityTest, ConstructorWithInvalidName) {
    EXPECT_THROW(Activity("", "Descrizione", "09:00", "10:00"), std::invalid_argument);
    EXPECT_THROW(Activity("   ", "Descrizione", "09:00", "10:00"), std::invalid_argument);
}

//test per il costruttore con descrizione non valida
TEST(ActivityTest, ConstructorWithInvalidDescription) {
    EXPECT_THROW(Activity("Nome", "", "09:00", "10:00"), std::invalid_argument);
    EXPECT_THROW(Activity("Nome", "   ", "09:00", "10:00"), std::invalid_argument);
}

//test per il costruttore con orario di inizio non valido
TEST(ActivityTest, ConstructorWithInvalidStartTime) {
    EXPECT_THROW(Activity("Nome", "Descrizione", "25:00", "10:00"), std::invalid_argument);
    EXPECT_THROW(Activity("Nome", "Descrizione", "09:60", "10:00"), std::invalid_argument);
    EXPECT_THROW(Activity("Nome", "Descrizione", "0900", "10:00"), std::invalid_argument);
}

//test per il costruttore con orario di fine non valido
TEST(ActivityTest, ConstructorWithInvalidEndTime) {
    EXPECT_THROW(Activity("Nome", "Descrizione", "09:00", "25:00"), std::invalid_argument);
    EXPECT_THROW(Activity("Nome", "Descrizione", "09:00", "10:60"), std::invalid_argument);
    EXPECT_THROW(Activity("Nome", "Descrizione", "09:00", "1000"), std::invalid_argument);
}

//test per il costruttore con orario di fine precedente all'inizio
TEST(ActivityTest, ConstructorWithEndTimeBeforeStartTime) {
    EXPECT_THROW(Activity("Nome", "Descrizione", "10:00", "09:00"), std::invalid_argument);
    EXPECT_THROW(Activity("Nome", "Descrizione", "10:00", "10:00"), std::invalid_argument);
    EXPECT_THROW(Activity("Nome", "Descrizione", "10:30", "10:00"), std::invalid_argument);
}

//test per il calcolo della durata in vari casi
TEST(ActivityTest, DurationCalculation) {
    Activity activity1("A", "B", "09:00", "10:00");
    EXPECT_EQ(activity1.getDuration(), "01:00");

    Activity activity2("A", "B", "09:00", "09:30");
    EXPECT_EQ(activity2.getDuration(), "00:30");

    Activity activity3("A", "B", "09:00", "11:45");
    EXPECT_EQ(activity3.getDuration(), "02:45");

}

//test per verificare che i campi siano correttamente inizializzati con valori limite
TEST(ActivityTest, BoundaryValues) {
    Activity activity("Valid Name", "Valid Description", "00:00", "23:59");

    EXPECT_EQ(activity.getName(), "Valid Name");
    EXPECT_EQ(activity.getDescription(), "Valid Description");
    EXPECT_EQ(activity.getStartingTime(), "00:00");
    EXPECT_EQ(activity.getEndingTime(), "23:59");
    EXPECT_EQ(activity.getDuration(), "23:59");
}

