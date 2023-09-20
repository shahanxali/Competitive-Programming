--Question: https://leetcode.com/problems/combine-two-tables/
--Level: Easy


SELECT Person.firstName, Person.lastName, Address.city, Address.state
FROM Person LEFT JOIN Address
ON Person.personId = Address.personId;