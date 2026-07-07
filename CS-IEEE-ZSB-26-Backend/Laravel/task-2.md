# Laravel Notes

---

# Laravel Gates

## What are Gates?

Laravel Gates provide a simple way to authorize actions without creating a full Policy.

A Gate is a Closure that determines whether a user can perform a specific action.

## Defining a Gate

```php
use Illuminate\Support\Facades\Gate;

public function boot(): void
{
    Gate::define('edit-post', function ($user, $post) {
        return $user->id === $post->user_id;
    });
}
```

## Using Gates

### authorize()

```php
Gate::authorize('edit-post', $post);
```

### allows()

```php
if (Gate::allows('edit-post', $post)) {
    // Allowed
}
```

### denies()

```php
if (Gate::denies('edit-post', $post)) {
    abort(403);
}
```

## Gate Flow

```text
Request
   ↓
Authenticated User
   ↓
Gate::authorize()
   ↓
Registered Gate
   ↓
true / false
   ↓
Allow / 403
```

---

# Sanctum vs Passport

## Laravel Sanctum

- Lightweight authentication package
- Best for SPA
- Mobile apps
- Personal Access Tokens

## Laravel Passport

- Full OAuth2 server
- Third-party authentication
- Authorization Code Grant
- Password Grant
- Client Credentials

## Comparison

| Feature | Sanctum | Passport |
|---------|----------|----------|
| Setup | Easy | Advanced |
| OAuth2 | ❌ | ✅ |
| SPA | ✅ | ✅ |
| Mobile Apps | ✅ | ✅ |
| Third-party APIs | ❌ | ✅ |
| Internal APIs | ✅ | ✅ |

## Which one should you use?

Use **Sanctum** for most Laravel projects.

Use **Passport** only when OAuth2 or third-party authorization is required.

---

# CSRF & XSRF

## What is CSRF?

CSRF (Cross-Site Request Forgery) is an attack where a malicious website tricks an authenticated user into sending unwanted requests.

## What is XSRF?

XSRF and CSRF mean the same thing.

The "X" is simply another naming convention used by some frameworks.

## Laravel Protection

```php
<form method="POST">
    @csrf
</form>
```

Laravel verifies the CSRF token before accepting the request.

---

# Eloquent Relationships

## One To One

```php
public function profile()
{
    return $this->hasOne(Profile::class);
}
```

## One To Many

```php
public function posts()
{
    return $this->hasMany(Post::class);
}
```

## Belongs To

```php
public function user()
{
    return $this->belongsTo(User::class);
}
```

## Many To Many

```php
public function roles()
{
    return $this->belongsToMany(Role::class);
}
```

## Has Many Through

```php
public function posts()
{
    return $this->hasManyThrough(Post::class, User::class);
}
```

## Polymorphic

```php
public function commentable()
{
    return $this->morphTo();
}
```

## Summary

| Relationship | Method |
|--------------|--------|
| One To One | hasOne() |
| One To Many | hasMany() |
| Belongs To | belongsTo() |
| Many To Many | belongsToMany() |
| Has Many Through | hasManyThrough() |
| Polymorphic | morphTo() |
