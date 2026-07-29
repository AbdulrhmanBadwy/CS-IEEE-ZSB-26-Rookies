# Task 7

## Strategy Pattern

The Strategy Pattern is a behavioral design pattern that lets you define a family of algorithms, put each one in a separate class, and make them interchangeable at runtime. Instead of hard-coding a bunch of `if/else` or `switch` statements to pick behavior, you extract each behavior into its own class that implements a common interface, then inject whichever strategy you need into the context object.

**Why it matters:**
- Avoids bloated conditional logic that grows every time a new behavior is added.
- Makes it easy to add new algorithms without touching existing code (Open/Closed Principle).
- Each strategy is testable in isolation.

**Example use case:** a payment system where you can pay with `CreditCardStrategy`, `PaypalStrategy`, or `CashStrategy`, all implementing a `PaymentStrategy` interface, and the checkout class just calls `$strategy->pay($amount)` without caring which one it is.

## Factory Design Pattern

The Factory Pattern is a creational design pattern used to centralize and encapsulate object creation logic. Instead of calling `new SomeClass()` directly all over the codebase, you delegate that responsibility to a factory method/class that decides which concrete class to instantiate based on given input.

**Why it matters:**
- Decouples the client code from concrete classes.
- Centralizes creation logic in one place, so if the creation process changes, you only edit the factory.
- Works very well combined with interfaces, since the factory can return any class that implements the expected interface.

**Example use case:** a `NotificationFactory` that returns an `EmailNotification`, `SmsNotification`, or `PushNotification` object depending on a `$type` parameter, while the rest of the app only depends on a `Notification` interface.

## Concurrency

Concurrency is about a program dealing with multiple tasks that are in progress at the same time (not necessarily executing at the exact same instant, but making progress together, e.g. via interleaving or context switching). This is different from parallelism, where tasks literally run at the same time on multiple cores/processors.

**Key takeaways:**
- Concurrency is a way of *structuring* a program to handle multiple things at once (e.g. handling multiple requests, background jobs, or I/O operations).
- Shared resources (memory, database rows, files) accessed by multiple concurrent tasks are where things get dangerous if not handled carefully.
- Backend frameworks (like Laravel with queues/jobs) rely on concurrency concepts even if the underlying PHP process itself is mostly single-threaded per request.

### Race Conditions

A race condition happens when two or more processes/threads access and modify shared data at the same time, and the final result depends on the unpredictable order of execution. This can lead to lost updates, corrupted data, or inconsistent state.

**Example:** two requests both read a product's `stock = 5`, both decrement it by 1, and both write back `stock = 4` — even though two units were actually sold, so stock should be 3. Without proper locking, one update silently overwrites the other.

**How to prevent it:**
- Database-level locking (`SELECT ... FOR UPDATE`, pessimistic locking).
- Optimistic locking (versioning rows and checking the version before committing).
- Atomic database operations (e.g. `increment()`/`decrement()` in Laravel instead of read-then-write).
- Queues/jobs to serialize access to a critical section instead of letting it run concurrently.

## Deadlocks

A deadlock happens when two or more processes are each waiting on a resource that the other process holds, and none of them can proceed because they're stuck waiting on each other forever. This typically happens when multiple locks are acquired in different orders by different transactions.

**Classic example:** Transaction A locks Row 1 and waits for Row 2. Transaction B locks Row 2 and waits for Row 1. Both wait forever, so the database (or OS) has to detect the deadlock and forcibly kill/rollback one of the transactions.

**Conditions that must all be true for a deadlock to occur:**
1. Mutual exclusion (a resource can only be held by one process at a time).
2. Hold and wait (a process holds a resource while waiting for another).
3. No preemption (a resource can't be forcibly taken from a process).
4. Circular wait (a cycle of processes each waiting on the next).

**How to avoid deadlocks:**
- Always acquire locks in the same, consistent order across the whole application.
- Keep transactions short so locks are held for the shortest time possible.
- Use timeouts so a stuck transaction gets rolled back instead of waiting forever.
- Let the database's built-in deadlock detector handle it (most RDBMS like MySQL automatically detect and roll back one of the transactions).

## Resources I used

- Official video resources linked in the Task 28 sheet (Strategy Pattern, Factory Pattern, Concurrency, Race Conditions demo, Deadlocks, Deadlocks demo).
- Searched general articles/documentation to reinforce the difference between concurrency and parallelism, and how MySQL handles locking and deadlock detection.

## LLM Chat Notes

Asked Claude to help clarify the difference between race conditions and deadlocks, and to confirm real-world backend examples (e.g. stock decrement race condition, transaction lock ordering for deadlocks) to make sure the explanations above are accurate and phrased in my own words rather than copied from the source videos.
