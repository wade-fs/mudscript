// daemon/city_d.c
// 《遺忘的世界》金石府城環境守護進程 (CITY_D)
// 維護紅塵濁氣梯度、絕靈法網防衛、城防四關稅則與三日通牒身分緩衝

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/object.c";

void create() {
    ::create();
}

// ── 1. 紅塵濁氣梯度指數 ──────────────────────────────────────
// center / south: 100% (打坐效率 20%，滯留易積濁氣)
// west / north:   45%  (道統淨化陣法與純陽爐火)
// outer:          15%  (近郊自然清新)
// under:          5%   (紅塵濁氣低，但陰煞地煞極重)
int query_turbidity_index(string room_path) {
    if (!room_path) return 0;
    if (strsrch(room_path, "/d/city/center/") != -1 || strsrch(room_path, "/d/city/south/") != -1) {
        return 100;
    }
    if (strsrch(room_path, "/d/city/west/") != -1 || strsrch(room_path, "/d/city/north/") != -1) {
        return 45;
    }
    if (strsrch(room_path, "/d/city/outer/") != -1) {
        return 15;
    }
    if (strsrch(room_path, "/d/city/under/") != -1) {
        return 5;
    }
    if (strsrch(room_path, "/d/city/gate/") != -1 || strsrch(room_path, "/d/city/wall/") != -1) {
        return 50;
    }
    return 0;
}

// ── 2. 城防絕靈法網防衛機制 ──────────────────────────────────
// 覆蓋: center/, gate/, west/, north/
int is_spirit_sealed_grid(string room_path) {
    if (!room_path) return 0;
    if (strsrch(room_path, "/d/city/center/") != -1 ||
        strsrch(room_path, "/d/city/gate/") != -1 ||
        strsrch(room_path, "/d/city/west/") != -1 ||
        strsrch(room_path, "/d/city/north/") != -1) {
        return 1;
    }
    return 0;
}

// ── 3. 濁氣淨化與累積 ───────────────────────────────────────
int cleanse_turbidity(object who, int amount) {
    if (!who || amount <= 0) return 0;
    int cur = who->query("turbidity");
    if (cur <= 0) return 0;
    cur -= amount;
    if (cur < 0) cur = 0;
    who->set("turbidity", cur);
    return cur;
}

void apply_turbidity_tick(object who) {
    if (!who || !userp(who)) return;
    object env = environment(who);
    if (!env) return;
    string path = base_name(env);
    int idx = query_turbidity_index(path);
    if (idx >= 80) {
        int cur = who->query("turbidity");
        if (cur < 100) {
            cur += 1;
            who->set("turbidity", cur);
            if (cur == 20) {
                tell_object(who, YEL "【心神浮躁】紅塵喧囂紛擾，你感到心神濁氣隱隱上湧 (20/100)。\n" NOR);
            } else if (cur == 50) {
                tell_object(who, HIR "【濁障迷心】市井濁氣沉積靈台，若不儘快淨化，將難以凝神觀象 (50/100)！\n" NOR);
            } else if (cur >= 80 && cur < 100) {
                tell_object(who, HIR "【走火邊緣】心神濁氣已達 " + sprintf("%d", cur) + "/100，氣血翻騰逆行！\n" NOR);
                int hp_drain = who->query("max_kee") * 5 / 100;
                if (hp_drain > 0) who->receive_damage(hp_drain);
            }
        }
    }
}

// ── 4. 四關入城與稅則檢查 ───────────────────────────────────
mapping check_gate_access(object who, string gate_type) {
    if (!who) return ([ "allow": 0, "msg": "無效目標" ]);

    // 檢查是否擁有合法身分憑證
    int has_pass = (present("road pass", who) || present("baoshu", who) || present("保書路引", who)) ? 1 : 0;
    int has_buffer = (present("academy token", who) || present("caravan token", who) || present("clinic token", who)) ? 1 : 0;
    string my_class = who->query("class");
    int has_class = (my_class && my_class != "") ? 1 : 0;

    if (gate_type == "south") {
        // 南關：盤木大木、重石石料大車、流民入口
        // 黑石鋪鄉民憑舊戶籍或路引可免稅，無憑證者需 10 文工本費
        if (has_pass || has_buffer || has_class || who->query("level") >= 10) {
            return ([ "allow": 1, "fee": 0, "msg": "城防武卒審核憑證無誤，放行入城！" ]);
        }
        int money = who->query("money");
        if (money >= 10) {
            who->add_money(-10);
            return ([ "allow": 1, "fee": 10, "msg": "南關稅吏收取了十文流民查驗費，揮手放行入關。" ]);
        }
        return ([ "allow": 0, "fee": 10, "msg": "南關稅吏喝道：「無路引又無盤纏的流民，休想擅闖金石南關！」" ]);
    }

    if (gate_type == "north") {
        // 北關：官道客商、邊防物證
        if (has_pass || has_buffer || has_class || who->query("level") >= 10) {
            return ([ "allow": 1, "fee": 0, "msg": "北關典吏韓清點頭查驗完畢，放行入城！" ]);
        }
        int money = who->query("money");
        if (money >= 10) {
            who->add_money(-10);
            return ([ "allow": 1, "fee": 10, "msg": "北關城防兵收取十文客商登記費，放行入城。" ]);
        }
        return ([ "allow": 0, "fee": 10, "msg": "城門典吏按刀喝道：「北關重地，未經登記流民不得擅入！」" ]);
    }

    // 東關與西水門
    return ([ "allow": 1, "fee": 0, "msg": "盤查通過，放行入關。" ]);
}
