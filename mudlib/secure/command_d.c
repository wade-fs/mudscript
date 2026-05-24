// /secure/command_d.c
// 指令守護進程 (Command Daemon)
// 負責管理與分發全域指令，避免每個玩家物件都要載入大量指令模組

mapping cmd_map;

inherit "/std/object";

int rehash() {
    string *dirs = ({ "/cmds/", "/cmds/admin/" });
    cmd_map = ([]);
    int count = 0;

    foreach (string dir in dirs) {
        string *files = get_dir(dir);
        if (!files) continue;

        foreach (string file in files) {
            if (strlen(file) < 3 || substr(file, strlen(file)-2, 2) != ".c") continue;
            
            string full_path = dir + file;
            object cmd_ob = find_object(full_path);
            if (!cmd_ob) cmd_ob = load_object(full_path);
            if (!cmd_ob) continue;

            mixed verbs = cmd_ob->query_verbs();
            if (!verbs || !sizeof(verbs)) {
                string v = file;
                if (strsrch(v, "cmd_") == 0) v = substr(v, 4, strlen(v)-4);
                v = substr(v, 0, strlen(v)-2);
                verbs = ({ v });
            }

            foreach (string v in verbs) {
                cmd_map[v] = full_path;
                count++;
            }
        }
    }
    return count;
}

void create() {
    ::create();
    rehash();
}

int execute(object me, string verb, string arg) {
    mixed cmd_file = cmd_map[verb];
    
    if (!cmd_file) return 0; 

    object cmd_ob = load_object(cmd_file);
    if (!cmd_ob) {
        write("系統錯誤：找不到指令實作檔案 " + cmd_file + "\n");
        return 1;
    }

    return cmd_ob->main(me, verb, arg);
}

mapping query_cmd_map() { return cmd_map; }

// 🚀 新增：提供給 UI 使用的分類指令清單
mapping query_categorized_commands() {
    mapping res = ([]);
    string *verbs = sort_array(keys(cmd_map), 1);
    
    foreach (string v in verbs) {
        string file = cmd_map[v];
        object ob = find_object(file);
        if (!ob) ob = load_object(file);
        
        string cat = "Other";
        if (ob) {
            mixed c = ob->query_category();
            if (stringp(c)) cat = c;
        }
        
        // 排除管理指令（除非是巫師）
        if (strsrch(file, "/cmds/admin/") == 0) {
            cat = "Admin";
        }

        if (!res[cat]) res[cat] = ({});
        res[cat] += ({ v });
    }
    return res;
}
