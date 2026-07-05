# Laravel Notes

---

# Blade Templates

## What is Blade?

Blade is Laravel's built-in templating engine.

A Blade file is simply an HTML view mixed with Blade syntax, and every Blade template uses the following extension:

```text
.blade.php
```

## Request Flow

```
Route
   ↓
Controller
   ↓
Blade Template
   ↓
Browser
```

### 1. Define a Route

```php
Route::get('/about', [AboutController::class, 'index']);
```

### 2. Prepare Data Inside the Controller

```php
public function index()
{
    $title = 'About Us';

    return view('about', compact('title'));
}
```

### 3. Display Data in Blade

```php
<!DOCTYPE html>
<html>

<head>
    <title>{{ $title }}</title>
</head>

<body>

    <h1>About Us</h1>

</body>
</html>
```

---

# ORM (Object Relational Mapping)

## What is ORM?

ORM (Object Relational Mapping) allows developers to communicate with databases using PHP objects instead of writing raw SQL.

Example:

```php
$users = User::where('age', '>', 20)->get();
```

## Benefits

- Cleaner and more readable code
- Reduces the need to write SQL manually
- Easy relationship handling
- Built-in CRUD methods
- Faster application development

---

# Facade Design Pattern

## What is a Facade?

The Facade Pattern provides one simple interface that hides the complexity of multiple classes.

Instead of dealing with every subsystem separately, the application communicates with one facade class.

Example:

```php
class CPU
{
    public function process()
    {
        echo "CPU Processing...\n";
    }
}

class Memory
{
    public function load()
    {
        echo "Memory Loaded...\n";
    }
}

class ComputerFacade
{
    protected $cpu;
    protected $memory;

    public function __construct()
    {
        $this->cpu = new CPU();
        $this->memory = new Memory();
    }

    public function start()
    {
        $this->memory->load();
        $this->cpu->process();
    }
}

$computer = new ComputerFacade();
$computer->start();
```

---

# Factory Design Pattern

## What is Factory?

The Factory Pattern is responsible for creating objects instead of instantiating them directly using `new`.

This keeps object creation centralized and easier to extend.

```php
interface Car
{
    public function drive();
}

class BMW implements Car
{
    public function drive()
    {
        echo "Driving BMW";
    }
}

class Audi implements Car
{
    public function drive()
    {
        echo "Driving Audi";
    }
}

class CarFactory
{
    public static function make($type)
    {
        return match ($type) {
            'bmw' => new BMW(),
            'audi' => new Audi(),
            default => throw new Exception("Unknown car type"),
        };
    }
}

$car = CarFactory::make('bmw');
$car->drive();
```

---

# SOLID Principles

SOLID consists of five design principles that make software easier to maintain and extend.

---

## S — Single Responsibility Principle (SRP)

A class should have **one responsibility** and therefore only one reason to change.

**One Class = One Job**

```php
class Attack
{
    public function attack()
    {
    }
}

class Defense
{
    public function defense()
    {
    }
}

class GameMatch
{
    private $attack;
    private $defense;

    public function __construct()
    {
        $this->attack = new Attack();
        $this->defense = new Defense();
    }

    public function start()
    {
        echo "Start Play";
    }
}
```

---

## O — Open / Closed Principle (OCP)

Software components should be:

- Open for extension
- Closed for modification

You should be able to add new functionality without editing existing code.

```php
interface Discount
{
    public function getDiscount(): int;
}

class Regular implements Discount
{
    public function getDiscount(): int
    {
        return 10;
    }
}

class VIP implements Discount
{
    public function getDiscount(): int
    {
        return 20;
    }
}

echo (new Regular())->getDiscount();
echo (new VIP())->getDiscount();
```

---

## L — Liskov Substitution Principle (LSP)

A child class should be able to replace its parent without changing the expected behavior of the program.

```php
interface Shape
{
    public function getArea(): int;
}

class Rectangle implements Shape
{
    protected int $width;
    protected int $height;

    public function __construct(int $width, int $height)
    {
        $this->width = $width;
        $this->height = $height;
    }

    public function getArea(): int
    {
        return $this->width * $this->height;
    }
}

class Square implements Shape
{
    protected int $side;

    public function __construct(int $side)
    {
        $this->side = $side;
    }

    public function getArea(): int
    {
        return $this->side * $this->side;
    }
}
```

---

## I — Interface Segregation Principle (ISP)

Don't force classes to implement methods they don't need.

### Without ISP

```php
interface Machine
{
    public function print();
    public function scan();
    public function fax();
}

class SimplePrinter implements Machine
{
    public function print() {}

    public function scan() {}

    public function fax() {}
}
```

### With ISP

```php
interface Printer
{
    public function print();
}

interface Scanner
{
    public function scan();
}

class BasicPrinter implements Printer
{
    public function print()
    {
        echo "Print";
    }
}
```

---

## D — Dependency Inversion Principle (DIP)

High-level modules should depend on abstractions (interfaces), not concrete implementations.

### Without DIP

```php
class MySQLDatabase
{
    public function save()
    {
        echo "Saved to MySQL";
    }
}

class OrderService
{
    private $db;

    public function __construct()
    {
        $this->db = new MySQLDatabase();
    }
}
```

### With DIP

```php
interface Database
{
    public function save();
}

class MySQLDatabase implements Database
{
    public function save()
    {
        echo "Saved to MySQL";
    }
}

class MongoDatabase implements Database
{
    public function save()
    {
        echo "Saved to Mongo";
    }
}

class OrderService
{
    private Database $db;

    public function __construct(Database $db)
    {
        $this->db = $db;
    }
}

$service = new OrderService(new MySQLDatabase());
```

---

# Building a Modern Web Application

## Planning

- Project idea
- Validation
- PRD
- Marketing
- Reviews

## Design

- ERD
- Design Documents
- Tech Stack
- API Design
- Client Architecture
- Authentication & Authorization
- Deployment Strategy
- Design Review

## UI / UX

- Wireframes
- Visual Design
- User Testing

## Development

- Host code on Git
- Implement features
- Testing

## Deployment

- SSL Certificate
- Cloud Hosting / Self Hosting

---

# Web Authentication

## Authentication

Verifies **who the user is**.

## Authorization

Determines **what the user is allowed to do**.

---

## Stateful Authentication

The server stores the user session.

Example:

```php
session_start();

$_SESSION['username'] = 'JohnDoe';

session_destroy();
```

Used in:

- PHP Sessions
- Traditional Laravel applications

---

## Stateless Authentication

The client stores a token instead of the server storing a session.

Example:

```php
cookie('login', 'true', 60 * 24 * 30);
```

Common examples:

- JWT
- Local Storage
- API Authentication

---

| Stateful | Stateless |
|----------|------------|
| Session stored on server | Token stored on client |
| Session ID is sent | JWT is sent |
| Server checks session | Server validates token |
| Logout by deleting session | Logout requires token expiration or revocation |
| Best for web apps | Best for APIs & mobile apps |

---

# Tips for Receiving Code Reviews

1. Build the project.
2. Run the application.
3. Test everything before opening a PR.
4. Keep the pull request small.
5. Write a clear PR description.
6. Review your own code first.

---

# Tips for Giving Code Reviews

1. Automate repetitive checks whenever possible.
2. Be respectful and constructive.
3. Give clear and specific feedback.