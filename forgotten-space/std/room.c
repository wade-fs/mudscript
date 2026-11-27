// std/room.c - 所有房間的基底類別

#include "/include/ansi.h"
#include "/include/config.h"

inherit "/std/container.c";

string  short_desc;    // 房間標題
string  long_desc;     // 房間描述
mapping exits;         // 出口表：([ "north": "/area/..." ])
mixed   item_ids;      // 房間內可互動的裝飾物描述表

// 🚀 新增：隱藏元素 (用於 search)
mapping hidden_elements; // ([ "id": ([ "type": "exit/item", "value": "...", "msg": "..." ]) ])

// 🚀 新增：五感與物質反饋描述表 (touch / smell / listen) 與身世視角濾鏡
mapping touch_descs;
mapping smell_descs;
mapping listen_descs;
mapping bg_sensory_descs;

// 🚀 新增：宣告式動作規則表 (減少硬編碼 do_xxx，支援第四卷以後擴充)
mapping action_rules;

// 🚀 新增空間座標 (注意：配合 Go 解析器限制，逐行宣告)
int x;
int y;
int z;
int no_combat;         // 🚀 禁止戰鬥屬性
int has_forge;         // 🚀 鍛造設施
int has_lab;           // 🚀 煉金設施
int has_bank;          // 🚀 銀行設施
int has_tavern;        // 🚀 酒館設施
int has_guild;         // 🚀 公會設施
int has_shop;          // 🚀 商店設施
int is_outdoor;        // 🚀 是否為室外

void create() {
    ::create();
    short_desc = "未命名的空房間";
    long_desc  = "這裡什麼都沒有，只有無盡的虛空。\n";
    exits      = ([]);
    item_ids   = ([]);
    hidden_elements = ([]);
    touch_descs = ([]);
    smell_descs = ([]);
    listen_descs = ([]);
    bg_sensory_descs = ([]);
    action_rules = ([]);
    x = 0;
    y = 0;
    z = 0;
    no_combat = 0;
    has_forge = 0;
    has_lab   = 0;
    has_bank  = 0;
    has_tavern= 0;
    has_guild = 0;
    has_shop  = 0;
    is_outdoor = 1; // 預設皆為室外
}

// 判斷物件是否可以進入房間 (房間預設允許所有人進入)
int can_receive(object ob) {
    return 1;
}

// ── 座標設定與查詢 ───────────────────────────────────────
void set_coordinate(int cx, int cy, int cz) {
    x = cx;
    y = cy;
    z = cz;
}

mixed query_coordinate() {
    return ({ x, y, z });
}

// ── 設定函式 ────────────────────────────────────────────
void set_short(string s) { short_desc = s; }
void set_long(string s)  { long_desc  = s; }
void set_no_combat(int v){ no_combat = v; }
void set_has_forge(int v){ has_forge = v; }
void set_has_lab(int v)  { has_lab   = v; }
void set_has_bank(int v) { has_bank  = v; }
void set_has_tavern(int v){ has_tavern = v; }
void set_has_guild(int v){ has_guild = v; }
void set_has_shop(int v) { has_shop  = v; }
void set_is_outdoor(int v){ is_outdoor = v; }

void add_exit(string dir, string path) {
    exits[dir] = resolve_path(path, object_name(this_object()));
}

void set_exits(mapping e) {
    if (!exits) exits = ([]);
    if (!mapp(e)) return;
    mixed ks = keys(e);
    for (int i = 0; i < sizeof(ks); i++) {
        string dir = ks[i];
        exits[dir] = resolve_path(e[dir], object_name(this_object()));
    }
}

void set(string prop, mixed val) {
    if (prop == "no_combat") no_combat = val;
    if (prop == "is_outdoor") is_outdoor = val;
    if (prop == "has_forge") has_forge = val;
    if (prop == "has_shop") has_shop = val;
    if (prop == "has_bank") has_bank = val;
    if (prop == "has_tavern") has_tavern = val;
    if (prop == "has_guild") has_guild = val;
    if (prop == "has_lab") has_lab = val;
    ::set(prop, val);
}

void add_item(string id, string desc) {
    item_ids[id] = desc;
}

void add_hidden_element(string id, mapping data) {
    hidden_elements[id] = data;
}

// ── 五感與身世濾鏡設定與查詢 ──────────────────────────────
void set_touch(string target, string desc) {
    if (!touch_descs) touch_descs = ([]);
    if (!target || target == "") target = "default";
    touch_descs[target] = desc;
}

void set_smell(string target, string desc) {
    if (!smell_descs) smell_descs = ([]);
    if (!target || target == "") target = "default";
    smell_descs[target] = desc;
}

void set_listen(string target, string desc) {
    if (!listen_descs) listen_descs = ([]);
    if (!target || target == "") target = "default";
    listen_descs[target] = desc;
}

void set_bg_sensory(string bg_id, string desc) {
    if (!bg_sensory_descs) bg_sensory_descs = ([]);
    if (!bg_id || bg_id == "") return;
    bg_sensory_descs[bg_id] = desc;
}

string query_touch(string target) {
    if (!touch_descs) return 0;
    if (!target || target == "") target = "default";
    if (touch_descs[target]) return touch_descs[target];
    return touch_descs["default"];
}

string query_smell(string target) {
    if (!smell_descs) return 0;
    if (!target || target == "") target = "default";
    if (smell_descs[target]) return smell_descs[target];
    return smell_descs["default"];
}

string query_listen(string target) {
    if (!listen_descs) return 0;
    if (!target || target == "") target = "default";
    if (listen_descs[target]) return listen_descs[target];
    return listen_descs["default"];
}

string query_bg_sensory_line(object who) {
    if (!who) return "";
    string bg = who->query("background");
    if (!bg || bg == "") return "";
    if (bg_sensory_descs && bg_sensory_descs[bg]) {
        return bg_sensory_descs[bg];
    }
    string rpath = object_name(this_object());
    if (strsrch(rpath, "/d/village/") == 0) {
        if (bg == "herbalist") {
            return CYN "【採藥學徒觸覺】指腹老繭對空氣裡的濕氣與草木苦腥格外敏感，你能從泥縫微光裡分辨藥性與地煞殘毒。" NOR;
        }
        if (bg == "smith") {
            return YEL "【打鐵學徒視角】你的目光本能地掃過四周岩層與木樑的受力節點，耳膜總在捕捉金石碰撞的應力餘音。" NOR;
        }
        if (bg == "hunter") {
            return MAG "【山林獵戶直覺】你逆著風向微翕鼻翼，從泥地壓痕深淺與風裡的血腥氣中讀出了生靈走過的軌跡。" NOR;
        }
        if (bg == "daoist") {
            return HIC "【破落道童靈覺】眉心無垢靈台微涼，你隱約察覺天地間那層看似溫潤的靈氣底下藏著一絲滯澀的冷意。" NOR;
        }
        if (bg == "beggar") {
            return WHT "【流浪乞兒耳目】你的視線習慣性貼著別人的鞋底泥印、腰間錢袋垂度與退路暗角游走，先算生路再算買賣。" NOR;
        }
    }
    return "";
}

// ── 宣告式動作規則系統 (Declarative Room Action Rules) ──────
void add_action_rule(string verb, mapping rule_def) {
    if (!action_rules) action_rules = ([]);
    if (!verb || verb == "" || !mapp(rule_def)) return;
    action_rules[verb] = rule_def;
}

mapping query_action_rules() {
    if (!action_rules) return ([]);
    return action_rules;
}

int do_declarative_action(string arg) {
    string verb = query_verb();
    object me = this_player();
    if (!me || !action_rules || !action_rules[verb]) return 0;

    mapping rule = action_rules[verb];

    // 1. 目標比對
    if (rule["targets"] && arrayp(rule["targets"]) && sizeof(rule["targets"]) > 0) {
        string t = arg ? lower_case(arg) : "";
        int matched = 0;
        foreach (string cand in rule["targets"]) {
            if (t == lower_case(cand)) { matched = 1; break; }
        }
        if (!matched) {
            write((rule["usage_msg"] ? rule["usage_msg"] : ("請指定目標（" + implode(rule["targets"], " / ") + "）。")) + "\n");
            return 1;
        }
    }

    // 2. 身世條件
    if (rule["require_background"] && me->query("background") != rule["require_background"]) {
        write((rule["fail_msg"] ? rule["fail_msg"] : "你的身世歷練與此處機巧並不相契。") + "\n");
        return 1;
    }

    // 3. 物品條件
    if (rule["require_item"] && !present(rule["require_item"], me)) {
        write((rule["missing_item_msg"] ? rule["missing_item_msg"] : ("缺少必需物品：" + rule["require_item"])) + "\n");
        return 1;
    }

    // 4. 資格檢定 (會做 vs 有資格做)
    if (rule["require_qualification"]) {
        object cd = load_object("/daemon/city_d.c");
        if (cd) {
            mapping qres = cd->check_qualification_vs_skill(me, rule["require_qualification"], rule["action_label"] ? rule["action_label"] : verb);
            if (mapp(qres) && !qres["allowed"]) {
                write(qres["msg"] + "\n");
                return 1;
            }
        }
    }

    // 5. 精力／氣血／神識消耗
    int sp_cost = rule["sp_cost"];
    if (sp_cost > 0) {
        if (me->query("sp") < sp_cost) {
            write(HIR "你精力不濟，手腳發軟，暫時無法進行這項操作。\n" NOR);
            return 1;
        }
        me->add("sp", -sp_cost);
    }

    // 6. 感官與物質描述先行
    string matched_target = arg ? lower_case(arg) : "";
    if (mapp(rule["sensory_msgs"]) && rule["sensory_msgs"][matched_target]) {
        write(rule["sensory_msgs"][matched_target] + "\n");
    } else if (rule["sensory_msg"]) {
        write(rule["sensory_msg"] + "\n");
    }

    // 7. 數值與經驗回饋（後置）
    if (rule["train_stat"] && mapp(rule["train_stat"])) {
        foreach (string sk, int pts in rule["train_stat"]) {
            me->train_stat(sk, pts);
        }
    }
    if (rule["exp_gain"] > 0) {
        me->gain_exp(rule["exp_gain"]);
    }

    // 8. 任務引擎觸發
    if (rule["quest_verb"] || rule["quest_target"] || rule["quest_target_from_arg"]) {
        object qe = load_object("/daemon/quest_engine_d.c");
        if (qe) {
            string qtarget = rule["quest_target_from_arg"] ? matched_target : (rule["quest_target"] ? rule["quest_target"] : "");
            qe->trigger_event(me, "action", ([
                "verb": rule["quest_verb"] ? rule["quest_verb"] : verb,
                "target": qtarget
            ]));
        }
    }
    return 1;
}

// ── 動態環境與時辰呼吸片段 (PHASE_D & WORLD_STATE 整合) ──────
string query_phase_ambient_line() {
    string rpath = object_name(this_object());
    object pd = find_object("/daemon/phase_d.c");
    if (!pd) pd = load_object("/daemon/phase_d.c");
    if (!pd) return "";

    string *lines = ({});

    // 1. 區域時辰 × 季節節律描寫
    string rhythm = pd->query_room_rhythm_line(this_object());
    if (rhythm && rhythm != "") {
        lines += ({ rhythm });
    }

    // 2. NPC-to-NPC 樞紐日常劇本切片
    string hub_line = pd->query_current_hub_scene(base_name(this_object()));
    if (hub_line && hub_line != "") {
        lines += ({ HIC "【市井日常】" NOR + hub_line });
    }

    // 3. 註冊於此房間之時辰作息 NPC 動靜
    string period = pd->query_current_period();
    mapping scheds = pd->query_all_schedules();
    if (mapp(scheds)) {
        string *notes = ({});
        foreach (string nk, mapping ndef in scheds) {
            if (!mapp(ndef) || !ndef["schedules"]) continue;
            string target_r = pd->query_npc_target_room(nk, period);
            if (target_r && strsrch(rpath, replace_string(target_r, ".c", "")) == 0) {
                string amb = pd->query_npc_ambient_desc(nk, period);
                if (amb && amb != "") notes += ({ amb });
            }
        }
        if (sizeof(notes) > 0) {
            lines += ({ HIG "【時辰動靜】" NOR + implode(notes, " ") });
        }
    }

    if (sizeof(lines) > 0) {
        return implode(lines, "\n");
    }
    return "";
}

// ── NPC 產生與重生 ─────────────────────────────────────
object spawn_npc(string file) {
    string path = resolve_path(file, object_name(this_object()));
    
    // 🚀 安全檢查：避免重複產生相同的 NPC
    object *inv = all_inventory(this_object());
    if (inv) {
        for (int i = 0; i < sizeof(inv); i++) {
            if (base_name(inv[i]) == path) return inv[i];
        }
    }

    object ob = clone_object(path);
    if (ob) {
        move_object(ob, this_object());
    }
    return ob;
}

object spawn_item(string file) {
    string path = resolve_path(file, object_name(this_object()));
    object *inv = all_inventory(this_object());
    if (inv) {
        for (int i = 0; i < sizeof(inv); i++) {
            if (base_name(inv[i]) == path) return inv[i];
        }
    }
    object ob = clone_object(path);
    if (ob) {
        move_object(ob, this_object());
    }
    return ob;
}

// ── 查詢函式 ────────────────────────────────────────────
string query_short() { return select_lang(short_desc); }
string query_long()  { return select_lang(long_desc); }
mapping query_exits(){ return exits; }
int query_no_combat(){ return no_combat; }
int query_has_forge(){ return has_forge; }
int query_has_lab()  { return has_lab; }
int query_has_bank() { return has_bank; }
int query_has_tavern(){ return has_tavern; }
int query_has_guild(){ return has_guild; }
int query_has_shop() { return has_shop; }
int query_is_outdoor(){ return is_outdoor; }

// ── 顯示房間 ────────────────────────────────────────────
void look_room(object who) {
    if (!who) who = this_player();

    // 顯示天氣與時間 (僅限室外)
    if (is_outdoor) {
        write("$HIG$" + load_object("/secure/nature_d.c")->query_weather_string() + "$NOR$" + "\n");
    }

    write("【" + query_short() + "】\n");
    write(query_long() + "\n");

    string phase_line = query_phase_ambient_line();
    if (phase_line && phase_line != "") {
        write(phase_line + "\n");
    }

    string bg_line = query_bg_sensory_line(who);
    if (bg_line && bg_line != "" && (!who || !who->query("brief_sensory"))) {
        write(bg_line + "\n");
    }

    mixed exit_dirs = keys(exits);
    if (exit_dirs) {
        // 將出口用 [ ] 包起來，讓前端可以轉化為可點擊的連結
        string *formatted_exits = ({});
        for (int i = 0; i < sizeof(exit_dirs); i++) {
            formatted_exits += ({ "[" + exit_dirs[i] + "]" });
        }
        write(_t("exits") + "：" + implode(formatted_exits, "  ") + "\n");
    } else {
        write(_t("exits") + "：（無）\n");
    }

    mixed here_inv = all_inventory(this_object());
    mixed items_in_room = ({});
    mixed livings_in_room = ({});

    int i;
    for (i = 0; i < sizeof(here_inv); i++) {
        object ob = here_inv[i];
        if (living(ob)) {
            livings_in_room = livings_in_room + ({ ob });
        } else {
            items_in_room = items_in_room + ({ ob });
        }
    }

    if (sizeof(items_in_room) > 0) {
        write(_t("inventory") + "：\n");
        int j;
        for (j = 0; j < sizeof(items_in_room); j++) {
            object item = items_in_room[j];
            string item_id = item->query_key_id();
            write("  [" + item->query_short() + "(" + item_id + ")|look " + item_id + "]\n");
        }
    }

    if (sizeof(livings_in_room) > 0) {
        write(_t("livings") + "：\n");
        int k;
        for (k = 0; k < sizeof(livings_in_room); k++) {
            object liv = livings_in_room[k];
            if (!liv || liv == who) continue; // 不看自己
            
            string liv_id = "living";
            string display_name = liv->query_name();
            
            if (!display_name || display_name == "0") display_name = "某個生物";
            
            if (userp(liv)) {
                liv_id = liv->get_id();
                // 🚀 關鍵修正：不要在 [ ] 內嵌套 [ ]，會導致前端 regex 誤判
                display_name = "(玩家) " + display_name;
            } else {
                // 從 ID 列表抓取第一個可用 ID
                mixed ids = liv->query_id();
                if (arrayp(ids) && sizeof(ids) > 0) liv_id = ids[0];
                else if (stringp(ids)) liv_id = ids;
            }
            
            if (!liv_id || liv_id == "0") liv_id = "living";
            
            // 統一輸出格式：[顯示名稱(id)|指令]
            write("  [" + display_name + "(" + liv_id + ")|look " + liv_id + "]\n");
        }
    }

    // 🚀 新增：發送小地圖的 JSON 資料給前端
    object map_d = load_object("/secure/map_d.c");
    mapping map_data = ([]);
    if (map_d) {
        map_data = map_d->get_map_json(who, 2); // 取得 5x5 的網格資料
    }
    map_data["exits"] = keys(exits); // 同時保留可用出口資訊給前端使用
    write(sprintf("{\"ui\": \"minimap\", \"data\": %s}", json_encode(map_data)));

    // 🚀 新增：發送天氣資訊給前端
    object nature_d = load_object("/secure/nature_d.c");
    mapping nature_data = ([
        "weather": nature_d->query_weather(),
        "is_day": nature_d->is_day(),
        "hour": nature_d->query_hour(),
        "season": nature_d->query_season()
    ]);
    write(sprintf("{\"ui\": \"nature\", \"data\": %s}", json_encode(nature_data)));
}

// ── 移動指令 ────────────────────────────────────────────
void init() {
    ::init();
    mixed dirs = keys(exits);
    int i;
    for (i = 0; i < sizeof(dirs); i++) {
        add_action("do_go", dirs[i]);
    }
    add_action("do_go", "go");

    add_action("do_search", "search");
    add_action("do_search", "搜尋");
    add_action("do_touch", "touch");
    add_action("do_touch", "觸摸");
    add_action("do_smell", "smell");
    add_action("do_smell", "嗅聞");
    add_action("do_listen_room", "listen");
    add_action("do_listen_room", "傾聽");
    add_action("do_observe_scene", "observe");
    add_action("do_observe_scene", "旁觀");

    if (action_rules && sizeof(action_rules) > 0) {
        foreach (string rverb in keys(action_rules)) {
            add_action("do_declarative_action", rverb);
        }
    }

    // 🚀 新增：地圖探索紀錄
    object tp = this_player();
    if (tp && userp(tp)) {
        tp->record_exploration(object_name(this_object()));
    }

    // 🚩 性能優化：當玩家進入房間時，喚醒房間內所有 NPC 的心跳
    if (userp(this_player())) {
        object *inv = all_inventory(this_object());
        for (i = 0; i < sizeof(inv); i++) {
            if (living(inv[i])) inv[i]->set_heart_beat(1);
        }
    }
}

// ── 移動 ───────────────────────────────────────────────
int do_go(string dir) {
    mixed cmd = dir;
    if (!cmd || cmd == "") {
        cmd = query_verb();
    }

    if (!exits[cmd]) {
        write(_t("no_exit_err") + "\n");
        return 1;
    }

    string dest_path = exits[cmd];
    object dest;
    
    // dest_path 若為緩存路徑（/data/fs_cache/...），load_object 直接載入遠端緩存 room
    // 若尚未緩存，load_object 會失敗，再透過 fs_d 懶加載
    dest = load_object(dest_path);
    if (!dest) {
        // 嘗試判斷是否為遠端路徑（/area/... 但緩存不存在）
        // 這種情況代表玩家在未完整緩存的遠端區域移動，不做額外處理
        // 正常情況下不應發生（緩存 room 的 exits 應已指向 FS_CACHE_DIR）
    }
    
    if (!dest) {
        write(_t("dest_missing_err") + "\n");
        return 1;
    }

    object me = this_player();
    object lang_d = load_object("/secure/language_d.c");

    // 🚀 核心優化：移動前紀錄當前位置，方便目標房間查詢來源
    me->set_temp("last_location", base_name(this_object()));

    // 廣播離開訊息 (給原本房間的人)
    lang_d->broadcast_event(this_object(), "say_leave", ([ "$name": me, "$dir": cmd ]));

    if (me->move(dest, cmd)) {
        // 廣播抵達訊息 (給新房間的人)
        // 🚀 關鍵修正：抵達訊息應該顯示「反向」
        string from_dir = query_reverse_dir(cmd);
        lang_d->broadcast_event(dest, "say_arrive", ([ "$name": me, "$dir": from_dir ]));
        dest->look_room(me);
    } else {
        string fail_msg = _t("move_fail_err");
        fail_msg = replace_string(fail_msg, "$dir", cmd);
        write(fail_msg + "
");
    }
    return 1;
}

// ── 互動：搜尋 ──────────────────────────────────────────
int do_search(string arg) {
    write("你開始在房間裡四處搜尋...\n");
    say(this_player()->query_name() + " 開始在房間裡四處搜尋。\n");

    if (!hidden_elements || sizeof(hidden_elements) == 0) {
        write("你搜了半天，什麼都沒有發現。\n");
        return 1;
    }

    mixed ks = keys(hidden_elements);
    int found = 0;
    
    foreach (string key in ks) {
        mapping data = hidden_elements[key];
        
        // 這裡可以加入機率或屬性判定
        if (random(100) < 50) { // 50% 機率搜到
            write(data["msg"] + "\n");
            
            if (data["type"] == "exit") {
                add_exit(key, data["value"]);
            } else if (data["type"] == "item") {
                object ob = clone_object(data["value"]);
                if (ob) {
                    write("你找到了一件物品：" + ob->query_short() + "\n");
                    move_object(ob, this_object());
                }
            }
            
            // 搜到後移除隱藏標記
            m_delete(hidden_elements, key);
            found = 1;
        }
    }

    if (!found) {
        write("你搜了半天，什麼都沒有發現。\n");
    }

    return 1;
}

// ── 看裝飾物 ────────────────────────────────────────────
string look_at_item(string id) {
    if (item_ids && item_ids[id]) { return item_ids[id]; }
    return 0;
}

// ── 互動：觸摸、嗅聞、傾聽 (感官與物質細節反饋) ───────────
int do_touch(string arg) {
    string key = (arg && arg != "") ? lower_case(arg) : "default";
    string desc = query_touch(key);
    if (!desc && arg && item_ids && item_ids[key]) {
        desc = "你伸手觸摸【" + arg + "】，指腹傳來粗糙而真實的質感：\n" + item_ids[key];
    }
    if (!desc) {
        if (is_outdoor) {
            desc = "你蹲下身，掌心貼著微涼粗糙的泥石地面，能清晰感受到大地深處細微的脈動與濕度。";
        } else {
            desc = "你伸手撫過冰涼的牆垣與木石器物，指腹老繭摩擦出沙沙的細響。";
        }
    }
    write(desc + "\n");
    return 1;
}

int do_smell(string arg) {
    string key = (arg && arg != "") ? lower_case(arg) : "default";
    string desc = query_smell(key);
    if (!desc) {
        if (is_outdoor) {
            desc = "你微翕鼻翼深吸一口氣，空氣裡混雜著泥土、草木微腥與山風的冷冽氣息。";
        } else {
            desc = "你輕嗅四周，鼻端縈繞著陳年木料、灰塵與人間煙火留下的氣味。";
        }
    }
    write(desc + "\n");
    return 1;
}

int do_listen_room(string arg) {
    string key = (arg && arg != "") ? lower_case(arg) : "default";
    string desc = query_listen(key);
    if (!desc) {
        if (is_outdoor) {
            desc = "你屏息凝神傾聽，風掠過山石林梢的低鳴與遠處隱約的人聲犬吠交織在一起。";
        } else {
            desc = "你側耳細聽，屋樑微不可察的應力輕響與四周細碎的呼吸步履聲清晰可辨。";
        }
    }
    write(desc + "\n");
    return 1;
}

int do_observe_scene(string arg) {
    object pd = find_object("/daemon/phase_d.c");
    if (!pd) pd = load_object("/daemon/phase_d.c");
    if (!pd) return 0;

    string beat = pd->advance_hub_scene(this_object());
    if (beat && beat != "") {
        write("\n" HIC "【市井旁觀】" NOR + beat + "\n");
        return 1;
    }
    string rhythm = pd->query_room_rhythm_line(this_object());
    if (rhythm && rhythm != "") {
        write("\n" + rhythm + "\n");
        return 1;
    }
    write("你靜立片刻，留心周遭來往行人的神色與動靜，暫無特別異狀。\n");
    return 1;
}

void catch_tell(string msg) {}

// ── 房間專用垃圾回收 ──────────────────────────────────
int clean_up(int inherited_count) {
    if (inherited_count > 0) return 1;

    // 1. 如果房間內有玩家，絕對不清理
    object *inv = all_inventory(this_object());
    foreach (object ob in inv) {
        if (userp(ob)) return 1;
    }

    // 2. 如果是本機的藍圖房間，不清理 (保持世界連貫性)
    string oname = object_name(this_object());
    if (strsrch(oname, "#") == -1 && strsrch(oname, FS_CACHE_DIR) != 0) return 1;

    // 3. 閒置超過 20 分鐘 (1200秒) 則回收 (包含異世界緩存房間)
    if (query_idle(this_object()) > 1200) {
        destruct(this_object());
        return 0;
    }

    return 1;
}

// ── 相容與代理介面 ──────────────────────────────────────────
string short() { return query_short(); }
string long() { return query_long(); }
int is_proxy_room() { return 0; }
string query_remote_mud() { return 0; }
string query_shadow_uuid() { return 0; }
void set_shadow_uuid(string id) {}
void update_state(mixed payload) {}
void update_inventory(mixed payload) {}
int query_is_loading_room() { return 0; }
string query_target_mudlib() { return 0; }
string query_target_room() { return 0; }
int query_is_lm_world() { return 0; }
void set_world_name(string n) {}
void broadcast_map_all() {}
int do_meditate(string arg) { return 0; }
