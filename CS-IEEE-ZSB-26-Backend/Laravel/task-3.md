# Laravel Notes

---

# N+1 Query Problem

## What is the N+1 Problem?

The N+1 query problem happens when your code runs **1 query** to fetch a list of records, then runs **N additional queries** (one per record) to fetch related data.

This results in far more database calls than necessary and slows down your application.

## Example (The Problem)

```php
$posts = Post::all(); // 1 query

foreach ($posts as $post) {
    echo $post->user->name; // N queries (one per post)
}
```

If there are 100 posts, this runs **101 queries** total.

## The Fix: Eager Loading

Use `with()` to eager load relationships in a single additional query.

```php
$posts = Post::with('user')->get(); // 2 queries total

foreach ($posts as $post) {
    echo $post->user->name; // no extra queries
}
```

## Eager Loading Multiple Relationships

```php
$posts = Post::with(['user', 'comments'])->get();
```

## Nested Eager Loading

```php
$posts = Post::with('comments.author')->get();
```

## Detecting N+1 Issues

```php
Model::preventLazyLoading();
```

This throws an exception whenever lazy loading occurs, useful in local/testing environments.

## Flow

```text
Without Eager Loading
   ↓
1 query for records
   ↓
N queries for relations (loop)
   ↓
Slow / Many Queries

With Eager Loading
   ↓
1 query for records
   ↓
1 query for relations
   ↓
Fast / Few Queries
```

---

# Attaching, Syncing, Detaching (Many To Many)

## Setup

```php
public function roles()
{
    return $this->belongsToMany(Role::class);
}
```

## attach()

Adds a new record to the pivot table without removing existing ones.

```php
$user->roles()->attach($roleId);
```

Attach with extra pivot data:

```php
$user->roles()->attach($roleId, ['assigned_by' => $adminId]);
```

## detach()

Removes a record from the pivot table.

```php
$user->roles()->detach($roleId);
```

Detach all related records:

```php
$user->roles()->detach();
```

## sync()

Matches the pivot table exactly to the given array — adds missing ones, removes ones not listed.

```php
$user->roles()->sync([1, 2, 3]);
```

## syncWithoutDetaching()

Adds records without removing any existing ones.

```php
$user->roles()->syncWithoutDetaching([4, 5]);
```

## toggle()

Attaches records that aren't present and detaches records that are.

```php
$user->roles()->toggle([1, 2]);
```

## Comparison

| Method | Adds New | Removes Existing | Notes |
|--------|----------|-------------------|-------|
| attach() | ✅ | ❌ | Can duplicate if called twice |
| detach() | ❌ | ✅ | Removes given (or all) records |
| sync() | ✅ | ✅ | Matches array exactly |
| syncWithoutDetaching() | ✅ | ❌ | Safe additive sync |
| toggle() | ✅ | ✅ | Flips attach/detach state |

---

# Livewire

## What is Livewire?

Livewire is a full-stack framework for Laravel that lets you build dynamic, reactive interfaces using plain PHP — without writing much JavaScript.

It works by rendering components on the server and updating the DOM automatically through AJAX requests behind the scenes.

## Creating a Component

```bash
php artisan make:livewire Counter
```

This generates two files:

```text
app/Livewire/Counter.php
resources/views/livewire/counter.blade.php
```

## Component Class

```php
class Counter extends Component
{
    public $count = 0;

    public function increment()
    {
        $this->count++;
    }

    public function render()
    {
        return view('livewire.counter');
    }
}
```

## Component View

```php
<div>
    <h1>{{ $count }}</h1>
    <button wire:click="increment">+</button>
</div>
```

## Using the Component

```php
<livewire:counter />
```

## Key Directives

| Directive | Purpose |
|-----------|---------|
| wire:click | Calls a method on click |
| wire:model | Two-way data binding |
| wire:submit | Handles form submission |
| wire:loading | Shows loading state |
| wire:poll | Refreshes component periodically |

## Livewire Flow

```text
User Interaction (click, input, submit)
   ↓
AJAX Request to Server
   ↓
Component Method Runs (PHP)
   ↓
Component Re-renders
   ↓
DOM Updated Automatically
```

## Why Use Livewire?

- Build reactive UIs with PHP only
- No need for a separate API/frontend layer
- Integrates directly with Blade
- Great for admin panels, dashboards, and forms
