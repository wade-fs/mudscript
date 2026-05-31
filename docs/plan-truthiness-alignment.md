# Plan: Align Truthiness and Initialization with Legacy LPC

## Objective
Update MudScript's truthiness and variable initialization logic to match MudOS/ES2 standards, where empty collections are considered `TRUE` and uninitialized variables are `0`.

## Key Changes

### 1. Driver & Evaluator (Go)

#### `evaluator/evaluator.go`
- **`isTruthy`**: Remove length checks for `Array` and `Mapping`. Any non-nil, non-zero collection will be truthy.
- **`GetDefaultLPCValue`**: Change the default return value for `mapping` and `array` types from empty collections to `&object.Integer{Value: 0}`.

#### `driver/efun.go`
- **`isLPCTrue`**: Remove length checks for `Array` and `Mapping`.

### 2. Mudlib (LPC)

#### Audit and Update `mudlib/`
- Scan for patterns like `if (arr)`, `if (!arr)`, `if (map)`, `if (!map)` and replace with `if (sizeof(arr) > 0)`, `if (sizeof(arr) == 0)`, etc.
- Ensure all collection variables are initialized (e.g., `m = ([ ])`) before being used with index operators or collection-specific Efuns.

## Implementation Steps

1.  **Modify Driver Logic**: Update `isTruthy`, `GetDefaultLPCValue`, and `isLPCTrue`.
2.  **Audit Mudlib**: Use `grep_search` to find problematic patterns.
3.  **Apply Mudlib Fixes**: Update affected files in `mudlib/`.
4.  **Verify**: Run `make test` and `make test-fs`.

## Verification & Testing
- **Modern Mudlib**: `make test` must pass all tests.
- **Legacy Mudlib**: `make test-fs` must proceed through guest login and beyond.
- **Specific Tests**: Verify that `if (({}) )` is now true and `mapping m; if (m)` is false.
