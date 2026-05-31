# Plan: Implementing Centralized Tiered Heartbeat Scheduler & Robust Shutdown

## Objective
1. **Heartbeat Scheduler**: Refactor the Driver's heartbeat mechanism from a "per-object goroutine" model to a "Centralized Tiered Daemon" model. This reduces context switching and memory overhead, fixing the OOM (Error 137) during legacy test runs.
2. **Robust Shutdown**: Implement a global panic handler to ensure the server exits gracefully (clearing objects/files) instead of crashing and leaving stale processes.

## Key Changes

### 1. Driver (Go)

#### `driver/heartbeat.go` (NEW)
- Implement `HeartbeatScheduler` struct managing `Fast`, `Normal`, and `Slow` tickers.
- Registry to track active objects and their heartbeat intervals.
- Centralized execution of `heart_beat()` on objects.

#### `driver/driver.go`
- Integrate `HeartbeatScheduler` into the `Driver`.
- Refactor `startHeartBeat` to register objects with the scheduler instead of spawning goroutines.
- Update `d.Start()` to include a `recover()` block for robust panic handling.

### 2. Implementation Steps

1. **Panic Recovery**: Add a `recover()` block in `d.Start()` and `driver.go` loops to log errors and exit gracefully.
2. **Scheduler Implementation**: Create `driver/heartbeat.go` and implement the Tiered Scheduler.
3. **Driver Integration**: Replace per-object ticker loops in `driver/driver.go` with the `HeartbeatScheduler`.
4. **Verification**: Run `make test` and `GUEST_TEST=1 make test-fs`. Ensure no OOM (Exit Code 137) occurs and that tests exit clean.

## Verification & Testing
- **Legacy Mudlib**: Verify that `heart_beat()` calls in `fs/` still execute properly via the new scheduler.
- **Modern Mudlib**: Ensure existing heartbeat-dependent tests pass.
- **Exit Behavior**: Confirm that panics no longer cause hanging processes; the server should print the panic, clean up, and exit.
