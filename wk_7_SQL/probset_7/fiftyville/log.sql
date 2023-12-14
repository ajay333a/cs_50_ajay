-- Keep a log of any SQL queries you execute as you solve the mystery.

-- checking crime scene report
SELECT * FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

/*
Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
*/

--checking transcripts of the interviews
SELECT * FROM interviews
WHERE month = 7 AND day = 28;

/*
From - Ruth: Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.

From - Eugene: I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery,
I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

From - Raymond: As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call,
I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
The thief then asked the person on the other end of the phone to purchase the flight ticket
 */

-- checking bakery security logs around 10 hour of 28th July 2021
SELECT * FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND activity = 'exit';

/*
Nine vehicles were reported to exit the bakery around 10 o'clock
*/

-- checking any of the people have the license plate that exited bakery around 10 AM
SELECT name FROM people AS exited_bakery
WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs
                        WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25 AND activity = 'exit')
ORDER BY name;
/* Barry, Bruce, Diana, Iman, Kelsey, Luca, Sofia, Vanessa left bakry after 10 minutes of theft */

-- checking atm transactions at Leggett Street
SELECT * FROM atm_transactions
WHERE month = 7 AND day = 28 AND atm_location LIKE 'Leggett Street' AND transaction_type = 'withdraw';

/*
eight withdrawls happened on the theft location and bank_accounts contain person_id
*/

--checking the names of the people who withdrew amount from theft location
SELECT name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
WHERE account_number IN (SELECT account_number FROM atm_transactions
                         WHERE month = 7 AND day = 28 AND atm_location LIKE 'Leggett Street' AND transaction_type = 'withdraw')
ORDER BY name;
--Benista, Brooke, Bruce, Diana, Iman Kenny , Luca , Taylor withdrew money from atm at theft location

/*
Bruce, Diana, Iman, Luca withdrew amount from theft location and exited the bakery around 10 AM
*/

-- checking outgoing phone calls on day of theft where call duration was less than a minute
SELECT people.name, phone_calls.caller, phone_calls.receiver FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE month = 7 AND day = 28 AND duration < 60;

/*
Bruce, Diana, Iman, Luca, Taylor withdrew amount from theft location and exited the bakery around 10 AM
Bruce, Diana made outgoing phone calls less than 60 seconds on 28th july, withdrew amount from theft location and exited the bakery around 10 AM
*/

-- checking the call recivers name
SELECT name FROM people
JOIN phone_calls ON phone_calls.receiver = people.phone_number
WHERE month = 7 AND day = 28 AND duration < 60 AND phone_calls.caller IN (SELECT phone_number FROM people
                                                                          WHERE name IN ('Bruce', 'Diana'));
--Bruce called Robin, Diana called James

-- finding to which city the earliest flight leaves from Fiftyville
SELECT flights.id, city, hour, minute FROM flights
JOIN airports ON airports.id = flights.destination_airport_id
WHERE month = 7 AND day = 29 AND flights.origin_airport_id = (SELECT id FROM airports
WHERE city LIKE 'Fiftyville')
ORDER BY hour;

-- finding passport number and name
SELECT name FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
WHERE passengers.flight_id = (SELECT flights.id FROM flights
                                JOIN airports ON airports.id = flights.destination_airport_id
                                WHERE month = 7 AND day = 29 AND flights.origin_airport_id = (SELECT id FROM airports
                                WHERE city LIKE 'Fiftyville')
                                ORDER BY hour
                                LIMIT 1);

/* Bruce is the only passenger who has call record of outgoing call less than a minute and a flight ticket on earliest flight leaving from Fiftyvelle*/

