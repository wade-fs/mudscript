// /std/county_room.c
// 六縣城鎮與黑石鋪房間基底類別 (County Room Base Class)
// 自動掛接 WORLD_STATE_D 六縣 30 天無主角介入自主演進時間線、四階段動態描述與物價指數

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

string county_id;
string branch_org_id;
string qual_path;
mapping stage_descs;

void create() {
    ::create();
    county_id = "";
    branch_org_id = "";
    qual_path = "";
    stage_descs = ([]);
}

void set_county(string cid) {
    county_id = cid;
    ::set("county_id", cid);
}

string query_county() {
    return county_id;
}

void set_branch_org(string org_id) {
    branch_org_id = org_id;
    ::set("branch_org_id", org_id);
}

string query_branch_org() {
    return branch_org_id;
}

void set_qual_path(string p) {
    qual_path = p;
    ::set("qual_path", p);
}

string query_qual_path() {
    return qual_path;
}

void set_stage_desc(int stage, string desc) {
    if (!mapp(stage_descs)) stage_descs = ([]);
    stage_descs[sprintf("%d", stage)] = desc;
}

string query_stage_desc(int stage) {
    if (!mapp(stage_descs)) return "";
    string key = sprintf("%d", stage);
    if (!stage_descs[key]) return "";
    return stage_descs[key];
}

mapping query_county_state() {
    if (!county_id || county_id == "") return 0;
    object ws_d = load_object(WORLD_STATE_D);
    if (!ws_d) return 0;
    return ws_d->query_county_status(county_id);
}

int query_local_price_pct() {
    mapping st = query_county_state();
    if (!mapp(st) || !st["price_pct"]) return 100;
    return st["price_pct"];
}

string query_long() {
    string base = ::query_long();
    if (!county_id || county_id == "") return base;

    mapping st = query_county_state();
    if (!mapp(st)) return base;

    int stage = st["stage"];
    string custom_stage = query_stage_desc(stage);
    string dynamic_line = "";
    if (custom_stage && custom_stage != "") {
        dynamic_line = sprintf("\n" YEL "【地方局勢・第 %d 日（第 %d 階段）】%s（專材行情：%d%%）" NOR,
            st["day"], stage, custom_stage, st["price_pct"]);
    } else if (st["stage_desc"]) {
        dynamic_line = sprintf("\n" YEL "【%s局勢・第 %d 日】%s（%s行情：%d%%）" NOR,
            st["name"], st["day"], st["stage_desc"], st["commodity"], st["price_pct"]);
    }

    if (qual_path && qual_path != "") {
        object sk_d = load_object(SKILL_D);
        if (sk_d) {
            mapping eq = sk_d->check_county_qualification_equivalence(county_id, qual_path);
            if (mapp(eq) && eq["equivalent"]) {
                dynamic_line += sprintf("\n" CYN "【地方傳承入口】此處為「%s」，可核發與金石府城等效之初階資格（主考：%s）。" NOR,
                    eq["local_institution"], eq["examiner"]);
            }
        }
    }

    return base + dynamic_line;
}

void init() {
    ::init();
    if (qual_path && qual_path != "") {
        add_action("do_county_exam", "exam");
        add_action("do_county_exam", "initiate");
        add_action("do_county_exam", "考取");
        add_action("do_county_exam", "考核");
    }
}

int do_county_exam(string arg) {
    object me = this_player();
    if (!me || !county_id || county_id == "" || !qual_path || qual_path == "") return 0;

    object sk_d = load_object(SKILL_D);
    if (!sk_d) return 0;

    mapping eq = sk_d->check_county_qualification_equivalence(county_id, qual_path);
    if (!mapp(eq) || !eq["equivalent"]) return 0;

    write(CYN "\n你向「" + eq["local_institution"] + "」主考官 " + eq["examiner"] + " 遞交地方初階資格考核申請...\n" NOR);
    sk_d->grant_county_initiation(me, county_id, qual_path);
    return 1;
}
