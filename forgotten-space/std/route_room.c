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
    if (strsrch(oname, "post") != -1 || strsrch(oname, "pass") != -1 ||
        strsrch(oname, "pavilion") != -1 || strsrch(oname, "dock") != -1 ||
        strsrch(oname, "toll") != -1 || strsrch(oname, "entry") != -1) {
        object *inv = all_inventory(this_object());
        int has_liv = 0;
        if (arrayp(inv)) {
            foreach (object ob in inv) {
                if (living(ob) && !userp(ob)) { has_liv = 1; break; }
            }
        }
        if (!has_liv) spawn_npc("/clone/npc/folk/route_traveler.c");
    }
}

void look_room(object who) {
    ensure_route_travelers();
    ::look_room(who);
}

void init() {
    ::init();
    ensure_route_travelers();
}
