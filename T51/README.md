# CD exchange

Programming task CD exchange<br>
- Atmiņa: 5 MB 
- Laiks: 0.2/0.3 second 
- Ievadfails: exchange.in 
- Izvadfails: exchange.out

## Description
The inhabitants of Latvia have organized their music CD “exchange and sale” network. Inhabitants have their own CD collection; they want to get their hands on specific CDs, and get rid of their CDs that stopped being so appealing. Because it is hard to find two persons, who want to exchange such CDs among themselves, the exchange is carried out with the help of selling: some people offer their old CDs, others request their desired CDs. If the relevant request and offer are found, i.e. CD names coincide, then the seller and the buyer receive each other’s contact information and try to achieve a consensus about the price. At this moment, both the offer and request are not actual anymore, i.e. they are removed from the database. Should the two fail to agree about the price, they can place their offer and request into the database once anew.

Each new offer (or request) is matched to the first request (or offer) by the time of registration in the system. This principle effectively means that the request and offer processing is carried out in the order of arrival.

You should implement the application that would help to organize the described “exchange-sale”.

There won’t be more than 25000 unfilled request and offers (in total) simultaneously.

## Input:
Each offer and request data is recorded in the following format:
```
Time Action Person_code CD
```
- **Time** - Moment of time written as an integer number [1..1’000’000’000]
- **Action** - letter “A” indicating a request (Ask) or letter “B” indicating an offer (Bid).
- **Person_code** - a string of 11 numeric symbols similar to the personal code used in the Republic of Latvia for person identification. The most important condition – a number [0..99’999’999’999], which has all the leading zeroes, fill the number up to 11 symbols, for example, 01234567890).
- **CD** - CD name, which for reasons of simplicity is written as a symbol string no longer than 50 symbols and allowed symbols are only Latin letters and numbers [a..z, A..Z, 0..9].
Each record is in the according queue and has a unique Time field, and the records are in chronological order, i.e. each next record the time moment is strictly greater than the time moment of the next record.

## Output:
The found person pairs recorded in the following format:

```
Time, Person_code_A, Person_code_B
```
, where:

- Time - The moment of time, when the system has found the person pair (assume that the system gives the result in the same time moment when the given request or offer has come into the system)
- Person_code_A - The requesting person code.
- Person_code_B - The offering person code.
- 
Each record is in the according registration queue and has a unique Time field, and the records are in the chronological order, i.e. each time moment of the record is strictly greater than the time moment of the next record. If no pairs are found, the application should print “0” number.
