// clone/npc/granary_liubingzhong.c
// 劉秉忠・常平倉大使 (granary_liubingzhong) - 官平糧倉

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("劉秉忠");
    set_short(CYN "常平倉大使" NOR " 劉秉忠");
    set_long("一位身穿深青官袍、手持算籌與糧冊的清廉老官吏。\n"
             "他終日守在府城戰略常平倉前，監看米糧出入，隨時準備在災荒糧價暴漲時開倉平糶。\n");
    set_id(({ "granary_liubingzhong", "liubingzhong", "liu bingzhong", "granary commissioner", "劉秉忠", "常平倉大使", "倉大使" }));

    setup_archetype("A", 25);
    set("class", "mortal");
    set("faction", "yamen");
    set("roles", ({ "service", "info" }));
    set("rules", ([ "price_cap_trigger": 250, "stabilize_mult_min": 70, "stabilize_mult_max": 90 ]));
    set("schedule", "day");

    add_response(({ "常平倉", "平糶", "糧價", "開倉", "災荒" }),
        (: call_other, this_object(), "respond_granary_status" :));

    add_response(({ "分級", "配給", "保命", "優先序" }),
        "劉秉忠雙手抱拳嘆道：「顧小哥這套『重傷礦工、修閘苦力、孕婦幼童優先』的分級保命條陳，真是救了全城百萬生靈！府尹大人已硃批依此平糶！」");
}

string respond_granary_status() {
    object city_d = find_object(CITY_D);
    if (!city_d) city_d = load_object(CITY_D);
    if (city_d && city_d->query_granary_open()) {
        return "劉秉忠抹著汗水笑道：「府尹手諭已下！常平倉現正開倉平糶，平價供應【平糶荒糧袋】(buy grain, 10文)，每人皆可平價購買充飢，平抑物價！」";
    }
    return "劉秉忠撫摸著糧冊肅然道：「民以食為天！常平倉儲備全府三年戰略荒糧，一旦市井物價衝破兩成半（250%）上限，本官即刻奏請開倉平糶，將米價壓回七至九折！」";
}

void init() {
    ::init();
    add_action("do_buy", "buy");
    add_action("do_buy", "買");
}

int do_buy(string arg, object who) {
    object me = who ? who : this_player();
    if (!me) me = this_player();
    if (!arg || (arg != "grain" && arg != "relief grain" && arg != "糧" && arg != "荒糧")) {
        write("你想購買什麼物資？若逢平糶可購買平價糧袋 (buy grain)。\n");
        return 1;
    }

    object city_d = find_object(CITY_D);
    if (!city_d) city_d = load_object(CITY_D);
    if (!city_d || !city_d->query_granary_open()) {
        write("劉秉忠搖頭道：「常平倉戰略荒糧受法統封存，非遇物價突破 250% 災異平糶，概不對外單獨零售！」\n");
        return 1;
    }

    if (me->query("money") < 10) {
        write("你的銅錢不足（需要 10 文錢）。\n");
        return 1;
    }

    me->add_money(-10);
    object grain = clone_object("/clone/item/relief_grain.c");
    if (grain) {
        grain->move(me);
        tell_object(me, HIY "【劉秉忠在糧冊上記下一筆，從倉頭提了一袋《平糶荒糧袋》交到你手中！】\n" NOR);
    }
    return 1;
}
