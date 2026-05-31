# MudOS Efun 開發優先順序

## P1 — 核心引擎（~70個）
> 沒有這些，任何 LPC 程式都無法運作

### 物件生命週期
- `clone_object`
- `destruct`
- `load_object`
- `new`
- `find_object`
- `reload_object`
- `file_name`

### 函數呼叫
- `call_other`
- `apply`
- `evaluate`
- `function_exists`
- `functionp`
- `bind`
- `origin`

### 類型判斷
- `objectp`
- `stringp`
- `intp`
- `arrayp` / `pointerp`
- `mapp`
- `floatp`
- `nullp` / `undefinedp`
- `bufferp`
- `typeof`

### 控制流
- `catch`
- `throw`
- `error`
- `call_out`
- `remove_call_out`
- `find_call_out`
- `call_out_info`

### 字串基礎
- `sprintf` / `printf`
- `sscanf`
- `explode`
- `implode`
- `strlen`
- `lower_case`
- `capitalize`
- `replace_string`
- `strcmp`
- `strsrch`

### 陣列 / mapping 基礎
- `sizeof`
- `allocate`
- `member_array`
- `sort_array`
- `unique_array`
- `allocate_mapping`
- `keys`
- `values`
- `map_delete`
- `each`

### 類型轉換
- `to_int`
- `to_float`
- `ctime`
- `time`

### I/O 輸出
- `write`
- `say`
- `tell_object`
- `tell_room`
- `shout`
- `message`
- `receive`

### 玩家 / 互動
- `this_player`
- `this_object`
- `this_interactive`
- `users`
- `interactive`
- `input_to`
- `get_char`

### 檔案 I/O
- `read_file`
- `write_file`
- `file_size`
- `get_dir`
- `mkdir`
- `rmdir`
- `rm`
- `rename`
- `cp`

### 物件存取
- `save_object`
- `restore_object`
- `save_variable`
- `restore_variable`

---

## P2 — MUD 遊戲邏輯（~40個）
> 讓 MUD 真正「像 MUD」

### 環境 / 物品系統
- `environment`
- `all_inventory`
- `deep_inventory`
- `first_inventory`
- `next_inventory`
- `move_object`
- `present`
- `set_light`

### 指令 / 動作系統
- `add_action`
- `remove_action`
- `command`
- `commands`
- `notify_fail`
- `query_verb`
- `enable_commands`
- `disable_commands`

### living / 玩家查詢
- `living`
- `livings`
- `set_living_name`
- `find_living`
- `find_player`
- `userp`
- `query_idle`
- `query_ip_name` / `query_ip_number`

### heart beat / reset
- `set_heart_beat`
- `query_heart_beat`
- `set_reset`
- `swap`

### 字串進階
- `regexp`
- `reg_assoc`
- `break_string`
- `process_string`
- `process_value`
- `crypt`

### 陣列 functional
- `map` / `map_array`
- `filter_array`
- `filter_mapping` / `map_mapping`
- `unique_mapping`
- `inherit_list`
- `inherits`

### 安全 / 權限
- `getuid` / `geteuid`
- `seteuid`
- `export_uid`
- `query_privs` / `set_privs`
- `master`
- `previous_object`
- `all_previous_objects`

---

## P3 — 進階功能（~30個）
> 豐富遊戲體驗，可後期補充

### buffer 操作
- `allocate_buffer`
- `read_buffer`
- `write_buffer`
- `read_bytes`
- `write_bytes`

### shadow / 繼承動態
- `shadow`
- `query_shadowing`
- `replace_program`
- `deep_inherit_list`

### wizard / snoop
- `enable_wizard`
- `disable_wizard`
- `wizardp`
- `snoop`
- `query_snoop` / `query_snooping`
- `exec`
- `set_this_player`

### parse / 自然語言
- `parse_command`
- `match_path`

### 數學
- `random`
- `abs` / `pow` / `sqrt`
- `sin` / `cos` / `tan` / `asin` / `acos` / `atan`
- `log` / `exp`
- `floor` / `ceil`

### bit 操作
- `set_bit`
- `clear_bit`
- `test_bit`
- `crc32`

---

## P4 — 偵錯 / 監控 / 統計（~50個）
> 引擎穩定後再補

### 系統監控
- `debug_info`
- `mud_status`
- `rusage`
- `malloc_status` / `debugmalloc`
- `memory_info`
- `cache_stats`
- `uptime`
- `query_load_average`
- `query_host_name`

### 效能分析
- `function_profile`
- `opcprof`
- `trace` / `traceprefix`
- `set_debug_level`
- `time_expression`
- `moncontrol` / `set_malloc_mask`

### 物件管理
- `objects`
- `dumpallobj`
- `dump_prog`
- `generate_source`
- `reclaim_objects`
- `refs`
- `clonep`
- `children`

### eval 控制
- `set_eval_limit` / `max_eval_cost`
- `eval_cost` / `reset_eval_cost`

### 統計
- `author_stats` / `domain_stats`
- `set_author`

### 檔案進階
- `stat`
- `tail`
- `link`
- `dump_file_descriptors`
- `dump_socket_status`

### 其他
- `shutdown`
- `set_hide` / `virtualp`
- `localtime`
- `in_input`
- `tt`
- `ed` / `ed_cmd` / `ed_start` / `in_edit` / `query_ed_mode`
