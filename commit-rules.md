Here is a Markdown document based on the Conventional Commits 1.0.0 specification to help guide commit message formatting.

---

# Conventional Commits Guide

This document outlines the commit message conventions for our project. Following these guidelines will help us maintain a clean, explicit, and easy-to-follow commit history, compatible with automated tools and Semantic Versioning (SemVer).

## Commit Message Structure

Each commit message should follow this structure:

```plaintext
<type>[optional scope]: <description>

[optional body]

[optional footer(s)]
```

### Required Elements

- **Type**: Indicates the nature of the commit. Example types include:
  - `fix`: A commit that patches a bug in the codebase (correlates with PATCH in SemVer).
  - `feat`: A commit that introduces a new feature (correlates with MINOR in SemVer).
  - **Breaking Change**: Indicated by adding `!` after the type or scope, or by adding a `BREAKING CHANGE:` footer. This represents a breaking API change (correlates with MAJOR in SemVer).

### Optional Elements

- **Scope**: Provides additional context about the section of the code affected (e.g., `feat(api):`).
- **Description**: A concise summary of the changes (must follow the `type` and `scope` if present).
- **Body**: A more detailed explanation, starting one blank line after the description.
- **Footers**: Additional information, such as references to other issues or pull requests. Footers should follow a format inspired by Git trailers (e.g., `Reviewed-by`, `Refs: #123`).

---

## Commit Types and Examples

### Core Types

| Type  | Description                                         | SemVer Impact |
|-------|-----------------------------------------------------|---------------|
| `fix` | Patches a bug                                       | PATCH         |
| `feat`| Introduces a new feature                            | MINOR         |
| `!`   | Breaking API change (added to any type or scope)    | MAJOR         |

### Breaking Changes

To indicate a breaking change, add:
- `!` after the type or scope (e.g., `feat(api)!:`).
- **OR** add a `BREAKING CHANGE:` footer.

**Example**:
```plaintext
feat!: send an email to the customer when a product is shipped
```

Or with a footer:
```plaintext
feat(api): update API to handle batch processing

BREAKING CHANGE: Requests now require a batch object.
```

### Additional Types

Other types we may use include:
- `build`: Changes that affect the build system or external dependencies.
- `chore`: Minor changes that do not impact application functionality.
- `ci`: Changes to our continuous integration configuration.
- `docs`: Documentation changes.
- `style`: Code style changes (formatting, missing semicolons, etc.).
- `refactor`: Refactoring code without changing functionality.
- `perf`: Performance improvements.
- `test`: Adding or updating tests.

---

## Formatting Rules

- **Type** and **Scope** (if used) must be lowercase and followed by a colon and a space.
- **Description** must start immediately after the type and/or scope and provide a concise summary of the change.
- **Body** (optional) should start after a blank line, with detailed explanations, if needed.
- **Footers** (optional) should follow one blank line after the body and use Git trailer conventions, such as `Reviewed-by:`, `Refs:`, or `BREAKING CHANGE:`.

---

## Examples

Here are some example commit messages following this convention:

1. **Simple feature commit**:
    ```plaintext
    feat: add user authentication
    ```

2. **Bug fix with scope**:
    ```plaintext
    fix(auth): resolve token expiration issue
    ```

3. **Breaking change with !**:
    ```plaintext
    feat(api)!: update API endpoints to new version
    ```

4. **Breaking change with footer**:
    ```plaintext
    chore!: drop support for Node 6

    BREAKING CHANGE: This version no longer supports Node 6.
    ```

5. **Documentation update**:
    ```plaintext
    docs: update README with installation steps
    ```

6. **Commit with body and multiple footers**:
    ```plaintext
    fix: prevent racing of requests

    Introduced a request ID to track latest request and dismiss obsolete ones.
    Removed timeouts previously used to mitigate this issue.

    Reviewed-by: Jane Doe
    Refs: #123
    ```

---

## Key Notes

- Commit messages **must not be case-sensitive**, except for `BREAKING CHANGE`.
- `BREAKING-CHANGE` and `BREAKING CHANGE` are synonymous in the footer section.
- Remember to use the **!** notation in the type or scope, or a `BREAKING CHANGE:` footer for breaking changes.

Following these guidelines ensures clear communication of changes, an improved developer experience, and a commit history that's easy to understand and maintain.