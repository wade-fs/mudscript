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
int county_ecosystem_init;

void create() {
    ::create();
    county_id = "";
    branch_org_id = "";
    qual_path = "";
    stage_descs = ([]);
    county_ecosystem_init = 0;
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

// ── 依六縣地理風土與當前局勢生成動態五感體驗 ──────────────────────────
string query_touch(string target) {
    string custom = ::query_touch(target);
    if (custom) return custom;
    if (county_id == "liefan") {
        return HIR "指腹撫過帶赤紅鐵鏽紋的礦岩牆面，能感到石縫裡傳來一絲隱約的地火餘溫與微澀礦粉。" NOR;
    }
    if (county_id == "qinghe") {
        return CYN "石欄與木柱摸起來潮潤微涼，沾著河霧與草藥曬篩留下的細碎植物絨毛。" NOR;
    }
    if (county_id == "panmu") {
        return YEL "粗大紅杉木料表皮微黏，指尖能捻到新鮮滲出的琥珀色松脂與林間涼露。" NOR;
    }
    if (county_id == "zhenfeng") {
        return HIW "迎風石面被夾沙朔風打磨得生冷粗糙，指甲刮過還能摸見細小的石英晶粒。" NOR;
    }
    if (county_id == "zhongshi") {
        return WHT "厚重條石切面冰冷堅實如生鐵，地面還鋪著一層細密的灰白石粉與磨損鐵屑。" NOR;
    }
    if (county_id == "zhuoshui") {
        return MAG "空氣潮濕得連門板都發脹，手掌一按便覺得木面黏膩發涼，透出沼澤陰氣。" NOR;
    }
    return 0;
}

string query_smell(string target) {
    string custom = ::query_smell(target);
    if (custom) return custom;
    if (county_id == "liefan") {
        return YEL "鼻端滿是赤銅熔渣、明礬酸氣與刺鼻的微弱硫磺火煙。" NOR;
    }
    if (county_id == "qinghe") {
        return HIG "清冽江風裡飄著洗靈草、紫蘇與濕潤河泥的草木清苦香味。" NOR;
    }
    if (county_id == "panmu") {
        return GRN "濃郁的紅杉木屑香、雨後腐葉與野菌潮味順著山風撲面而來。" NOR;
    }
    if (county_id == "zhenfeng") {
        return CYN "乾燥刺骨的北塞沙塵味中，混著羊湯辣氣、熟牛皮與邊軍兵甲油味。" NOR;
    }
    if (county_id == "zhongshi") {
        return WHT "乾燥的石粉塵灰、鐵匠磨具油腥與車夫汗味交織在長街上。" NOR;
    }
    if (county_id == "zhuoshui") {
        return MAG "水澤泥沼特有的微腥瘴霧氣裡，夾著老薑熱湯與潮濕生銅的鐵鏽氣。" NOR;
    }
    return 0;
}

string query_listen(string target) {
    string custom = ::query_listen(target);
    if (custom) return custom;
    mapping st = query_county_state();
    int stage = mapp(st) ? st["stage"] : 1;
    if (stage >= 3) {
        return HIR "四下傳來市井百姓焦慮的議論聲、店鋪關板木閂聲與急促腳步聲，人心惶惶。" NOR;
    }
    if (county_id == "liefan") return YEL "遠近礦窯地火鼓風聲、赤銅叮噹與礦車鐵輪滾動聲終日不斷。" NOR;
    if (county_id == "qinghe") return CYN "河水拍岸聲中夾雜著船伕號子與藥坊木槌搗藥的清脆節拍。" NOR;
    if (county_id == "panmu") return GRN "遠山林海風濤聲裡，隱約傳來大鋸拉木與木排入水的沉悶回響。" NOR;
    if (county_id == "zhenfeng") return WHT "朔風掠過烽燧與崖壁發出尖銳呼嘯，偶爾傳來城防軍靴踏石聲。" NOR;
    if (county_id == "zhongshi") return HIY "石場絞盤咯吱作響，鐵鑿叮噹敲擊條石的聲響在山谷間迴盪。" NOR;
    if (county_id == "zhuoshui") return MAG "浮橋木板在濁浪上吱呀搖晃，不時傳來小船暗語對號的竹篙輕點聲。" NOR;
    return 0;
}

// ── 自動注入符合該縣建築功能的在地庶民 NPC，消滅空城布景 ────────────
void ensure_county_residents() {
    if (county_ecosystem_init || query("no_auto_npc")) return;
    county_ecosystem_init = 1;

    string oname = base_name(this_object());
    string npc_path = "/clone/npc/folk/county_worker.c";

    if (strsrch(oname, "post_inn") != -1 || strsrch(oname, "waterhouse") != -1) {
        npc_path = "/clone/npc/folk/county_innkeeper.c";
    } else if (strsrch(oname, "pawnshop") != -1 || strsrch(oname, "market") != -1 || strsrch(oname, "vault") != -1) {
        npc_path = "/clone/npc/folk/county_broker.c";
    } else if (strsrch(oname, "yamen") != -1 || strsrch(oname, "gate") != -1 ||
               strsrch(oname, "fort") != -1 || strsrch(oname, "garrison") != -1 ||
               strsrch(oname, "beacon") != -1 || strsrch(oname, "guard") != -1) {
        npc_path = "/clone/npc/folk/county_bailiff.c";
    }

    object *inv = all_inventory(this_object());
    int has_living = 0;
    if (arrayp(inv)) {
        foreach (object ob in inv) {
            if (living(ob) && !userp(ob) && !ob->query_temp("phase_migrated")) { has_living = 1; break; }
        }
    }
    if (!has_living) {
        spawn_npc(npc_path);
    }
}

void look_room(object who) {
    ensure_county_residents();
    ::look_room(who);
}

void init() {
    ::init();
    ensure_county_residents();
    string oname = base_name(this_object());
    if (strsrch(oname, "post_inn") != -1 || strsrch(oname, "waterhouse") != -1) {
        add_action("do_county_rest", "rest");
        add_action("do_county_rest", "drink");
        add_action("do_county_rest", "歇腳");
    }
    if (strsrch(oname, "market") != -1 || strsrch(oname, "pawnshop") != -1) {
        add_action("do_county_browse", "browse");
        add_action("do_county_browse", "appraise");
        add_action("do_county_browse", "行情");
    }
    if (qual_path && qual_path != "") {
        add_action("do_county_exam", "exam");
        add_action("do_county_exam", "initiate");
        add_action("do_county_exam", "考取");
        add_action("do_county_exam", "考核");
    }
}

int do_county_rest(string arg) {
    object me = this_player();
    if (!me) return 0;
    string drink_desc = "你叫來一碗滾燙的粗葉熱茶慢慢喝下，驅散了滿身風塵疲憊。";
    if (county_id == "liefan") drink_desc = "你端起大碗甘甜山泉熬的綠豆解毒湯一口喝盡，瞬間壓下了喉間那股硫磺礦酸氣。";
    else if (county_id == "zhenfeng") drink_desc = "你喝下一大碗浮著黑胡椒與羊油的滾燙羊雜湯，凍僵的四肢頓時回暖！";
    else if (county_id == "zhuoshui") drink_desc = "你灌下一碗辛辣驅瘴的老薑濃湯，胸口那股濕冷沼澤寒氣頓時散去大半。";

    write(HIG + drink_desc + "\n" NOR);
    me->add(VITAL_KEE, 20);
    me->add(VITAL_SEN, 15);
    me->add(VITAL_SP, 25);
    if (!me->query("brief_numeric")) {
        write(CYN "【客舍歇腳：氣血 +20、神識 +15、精力 +25】\n" NOR);
    }
    return 1;
}

int do_county_browse(string arg) {
    mapping st = query_county_state();
    if (!mapp(st)) {
        write("當地市集今日交易零星，暫無大宗掛牌行情。\n");
        return 1;
    }
    write(sprintf(HIY "\n【%s・即時市集與通寶估價】\n" NOR
                  "  主產專材：%s\n"
                  "  當前行情：%d%%（第 %d 階段 — %s）\n"
                  "  市井現況：現銅現銀照常結算，跨縣飛錢需視金石總號與官道安全放行。\n\n",
                  st["name"], st["commodity"], st["price_pct"], st["stage"], st["stage_desc"]));
    return 1;
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
