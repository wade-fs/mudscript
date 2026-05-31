# Plan: Implementing Virtual Shared Inheritance (DAG Resolver)

## Objective
Replace the current recursive inheritance copying mechanism in the Driver (`driver/object.go`) with a Directed Acyclic Graph (DAG) resolver. This ensures shared base classes (e.g., `F_DBASE`, `F_MOVE`) are only initialized once per object, preserving state consistency and solving the inheritance "diamond problem" common in legacy ES2 mudlib code.

## Key Changes

### 1. Driver (Go)

#### `driver/object.go`
- **`loadObjectInternal`**: 
    - Remove the existing recursive inheritance loop that copies all variables/functions.
    - Implement a new `applyInherit` function that traverses the inheritance tree as a DAG.
    - Use a `map[string]bool` to track already applied base classes (`appliedInherits`) to prevent duplicate initialization.
    - Ensure that functions (stored with `fn::` prefix) are properly rebound to the target object's environment.

### 2. Mudlib (LPC)
- **No changes needed to `fs/`**. The goal is to make the Driver smart enough to handle the existing structure.

## Implementation Steps

1.  **Refactor `loadObjectInternal`**: Implement the DAG traversal logic.
2.  **Define `applyInherit`**:
    - Recursively traverse inherited objects.
    - Apply variables and functions only if the class has not been applied yet.
    - Use `deepCopyLPCValue` for variables and correct environment rebinding for functions.
3.  **Verify**: Ensure no duplicate definitions exist in `lpcObj.Vars` after loading.

## Verification & Testing
- **Legacy Mudlib**: Run `make test-fs` and verify that no duplicate variable/function errors occur, and that the server loads correctly.
- **Modern Mudlib**: Run `make test` to ensure no regressions in existing inheritance patterns.
- **Functional Check**: Verify that `::func()` calls still work across the shared inheritance tree.
