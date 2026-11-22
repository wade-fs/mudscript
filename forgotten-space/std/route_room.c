// /std/route_room.c
// 跨縣標準交通路段節點房間基底類別 (Standard Route Segment Node Room)
// 自動對接 CITY_D 之 ROUTE_SEGMENTS 12 條標準路段資訊與 TRAVEL_D 通行規則

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

string route_segment_id;
int node_index;
int route_npc_init;

void create() {
    ::create();
    route_segment_id = "";
    node_index = 1;
    route_npc_init = 0;
    is_outdoor = 1;
}

void set_route_segment(string seg_id) {
    route_segment_id = seg_id;
    ::set("route_segment_id", seg_id);
}

string query_route_segment() {
    return route_segment_id;
}

void set_node_index(int idx) {
    node_index = idx;
    ::set("node_index", idx);
}

int query_node_index() {
    return node_index;
}

mapping query_segment_info() {
    if (!route_segment_id || route_segment_id == "") return 0;
    object city_d = load_object(CITY_D);
    if (!city_d) return 0;
    return city_d->query_route_segment(route_segment_id);
}

string query_long() {
    string base = ::query_long();
    mapping seg = query_segment_info();
    if (!mapp(seg)) return base;

    string info = sprintf(
        "\n" CYN "【官道輿圖・%s】全長 %d 里｜通行：%s（%s）\n"
        "【水文氣候】%s｜潛在風險：%s" NOR,
        seg["name"], seg["distance_li"], seg["travel_mode"], seg["normal_duration"],
        seg["seasonal_block"], seg["risk"]
    );
    return base + info;
}

string query_touch(string target) {
    string custom = ::query_touch(target);
    if (custom) return custom;
    mapping seg = query_segment_info();
    string terr = mapp(seg) ? seg["terrain"] : "";
    if (terr == "waterway") return CYN "碼頭青石板長期被河水打濕，滑溜冰涼，繩樁上纏著磨毛的濕粗麻纜。" NOR;
    if (terr == "cliff_plank_road") return YEL "懸崖棧道的杉木板在腳下微微顫動，扶手鐵索冷得刺手。" NOR;
    if (terr == "underground_canal") return HIB "溶洞石壁濕冷滲水，手掌按上去能摸見滑膩的地下石灰垢與陰寒水氣。" NOR;
    return WHT "車轍碾壓出的深溝裡石砂粗糲，經歷風雨日曬，留著無數重載大車與草鞋踩出的痕跡。" NOR;
}

string query_smell(string target) {
    string custom = ::query_smell(target);
    if (custom) return custom;
    mapping seg = query_segment_info();
    string terr = mapp(seg) ? seg["terrain"] : "";
    if (terr == "smuggler_ravine") return YEL "山風裡夾著生銅鐵鏽、私硝硫磺與汗馬腥氣。" NOR;
    if (terr == "swamp_pontoon") return MAG "腐泥水草與潮濕淤泥的瘴氣撲面而來，讓人呼吸發悶。" NOR;
    return CYN "山野泥土、馱獸草料與風霜吹拂下的草木清氣撲面而來。" NOR;
}

string query_listen(string target) {
    string custom = ::query_listen(target);
    if (custom) return custom;
    mapping seg = query_segment_info();
    string terr = mapp(seg) ? seg["terrain"] : "";
    if (terr == "gorge_highway") return WHT "峽谷罡風呼嘯穿過崖壁發出嗚咽，夾雜遠處馬鈴與駝鈴叮噹聲。" NOR;
    if (terr == "waterway") return CYN "船槳撥水聲與岸邊蘆葦在風裡沙沙擺動的聲音此起彼落。" NOR;
    return YEL "風聲、車輪嘎吱聲與不遠處挑夫換肩喘息的吆喝聲沿官道傳開。" NOR;
}

void ensure_route_travelers() {
    if (route_npc_init || query("no_auto_npc")) return;
    route_npc_init = 1;
    string oname = base_name(this_object());
    int is_checkpoint = (strsrch(oname, "pass") != -1 || strsrch(oname, "toll") != -1 ||
                         strsrch(oname, "entry") != -1);
    int is_waystation = (strsrch(oname, "post") != -1 || strsrch(oname, "pavilion") != -1 ||
                         strsrch(oname, "dock") != -1 || strsrch(oname, "approach") != -1 ||
                         strsrch(oname, "bend") != -1 || strsrch(oname, "highway") != -1);

    if (is_checkpoint || is_waystation) {
        object *inv = all_inventory(this_object());
        int has_liv = 0;
        if (arrayp(inv)) {
            foreach (object ob in inv) {
                if (living(ob) && !userp(ob)) { has_liv = 1; break; }
            }
        }
        if (!has_liv) {
            if (is_checkpoint) spawn_npc("/clone/npc/folk/route_guard.c");
            else spawn_npc("/clone/npc/folk/route_traveler.c");
        }
    }
}

void look_room(object who) {
    ensure_route_travelers();
    ::look_room(who);
}

void init() {
    ::init();
    ensure_route_travelers();
    string oname = base_name(this_object());
    add_action("do_route_survey", "survey");
    add_action("do_route_survey", "路況");
    if (strsrch(oname, "post") != -1 || strsrch(oname, "pavilion") != -1 ||
        strsrch(oname, "dock") != -1 || strsrch(oname, "approach") != -1) {
        add_action("do_route_rest", "rest");
        add_action("do_route_rest", "drink");
        add_action("do_route_rest", "歇腳");
    }
    if (strsrch(oname, "pass") != -1 || strsrch(oname, "toll") != -1 ||
        strsrch(oname, "entry") != -1) {
        add_action("do_route_check_pass", "check_pass");
        add_action("do_route_check_pass", "盤查");
    }
}

int do_route_survey(string arg) {
    mapping seg = query_segment_info();
    object ws = load_object(WORLD_STATE_D);
    string garr = ws ? ws->query_garrison_narrative(0) : "各路段暫無戰時封鎖令。";
    if (!mapp(seg)) {
        write("你放眼檢視前後山道與天色雲勢，路面尚可通行。\n" + CYN "【商道風聲】" + garr + "\n" NOR);
        return 1;
    }
    write(sprintf(HIY "\n【官道實測・%s】\n" NOR
                  "  路段長度：%d 里｜通行方式：%s（正常耗時：%s）\n"
                  "  地形風險：%s｜季節阻斷：%s\n"
                  "  關卡現況：%s\n\n",
                  seg["name"], seg["distance_li"], seg["travel_mode"], seg["normal_duration"],
                  seg["risk"], seg["seasonal_block"], garr));
    return 1;
}

int do_route_rest(string arg) {
    object me = this_player();
    if (!me) return 0;
    write(HIG "你在路邊石凳或茶寮簷下卸下肩擔喘口氣，喝了兩口涼水潤潤乾裂的喉嚨。\n" NOR);
    me->add(VITAL_KEE, 10);
    me->add(VITAL_SP, 20);
    if (!me->query("brief_numeric")) {
        write(CYN "【官道歇腳：氣血 +10、精力 +20】\n" NOR);
    }
    return 1;
}

int do_route_check_pass(string arg) {
    object me = this_player();
    if (!me) return 0;
    object pass_ob = present("road pass", me);
    if (!pass_ob) {
        foreach (object item in all_inventory(me)) {
            if (item->query("is_road_pass")) { pass_ob = item; break; }
        }
    }
    object ws = load_object(WORLD_STATE_D);
    int blocked = (ws && ws->is_caravan_blocked());
    if (pass_ob) {
        write(HIG "你亮出蓋有官方火漆的【" + pass_ob->query_name() + "】，關卡巡檢卒驗看無誤後揮手放行。\n" NOR);
    } else if (blocked) {
        write(HIR "關卡巡檢卒橫槍攔道：「眼下官道戒嚴封鎖，無路引或商會保單一概不得帶貨強過！」\n" NOR);
    } else {
        write(YEL "關卡巡檢卒上下打量你兩眼道：「沒帶正式路引只許空身趕路，若夾帶大宗礦藥貨物可得補繳過山錢！」\n" NOR);
    }
    return 1;
}
