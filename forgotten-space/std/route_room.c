// /std/route_room.c
// 跨縣標準交通路段節點房間基底類別 (Standard Route Segment Node Room)
// 自動對接 CITY_D 之 ROUTE_SEGMENTS 12 條標準路段資訊與 TRAVEL_D 通行規則

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

string route_segment_id;
int node_index;

void create() {
    ::create();
    route_segment_id = "";
    node_index = 1;
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
