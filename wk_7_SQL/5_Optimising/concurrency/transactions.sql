-- Demonstrates atomicity of transactions
-- bank.db

-- Show schema, higlight CHECK constraint
.schema

-- View account balances
SELECT * FROM "accounts";

-- Update balance without a transaction
UPDATE "accounts" SET "balance" = "balance" + 10 WHERE "id" = 2;
SELECT * FROM "accounts"; -- Viewing here provides an improper view of total balances
UPDATE "accounts" SET "balance" = "balance" - 10 WHERE "id" = 1;
SELECT * FROM "accounts"; -- Viewing here, after all updated, results in proper view

-- Reset table
UPDATE "accounts" SET "balance" = "balance" - 10 WHERE "id" = 2;
UPDATE "accounts" SET "balance" = "balance" + 10 WHERE "id" = 1;

-- Create a transaction which is successful
-- View state of database from other terminal mid-way through transaction
BEGIN TRANSACTION;
UPDATE "accounts" SET "balance" = "balance" + 10 WHERE "id" = 2;
UPDATE "accounts" SET "balance" = "balance" - 10 WHERE "id" = 1;
COMMIT;

-- Complete invalid update of balance without a transaction
UPDATE "accounts" SET "balance" = "balance" + 10 WHERE "id" = 2;
UPDATE "accounts" SET "balance" = "balance" - 10 WHERE "id" = 1; -- Invokes constraint error, which is ABORTed

-- "Rollback" the balance
UPDATE "accounts" SET "balance" = "balance" - 10 WHERE "id" = 2;

-- Create a transaction which should be rolled back
BEGIN TRANSACTION;
UPDATE "accounts" SET "balance" = "balance" + 10 WHERE "id" = 2;
UPDATE "accounts" SET "balance" = "balance" - 10 WHERE "id" = 1; -- Invokes constraint error, which is ABORTed
ROLLBACK;
