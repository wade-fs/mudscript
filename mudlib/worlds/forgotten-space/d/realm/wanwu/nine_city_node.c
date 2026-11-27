// /d/realm/wanwu/nine_city_node.c
// 主機底層・九城萬物商盟離線總節點 (Ch.142-143 啟封曾祖手諭與逐戶補登火種配額)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("主機底層・九城離線總節點");
    set_long("藏在私商廢鹽倉底層的古老鋼鐵庫房，正中玄鐵厚門上刻著一圓一方雙重嵌槽，\n"
             "專認【萬物行商・天門引】與【九城古商盟總契銅版】之諧振。架上排滿蠟封《平民避難配額總帳》，\n"
             "可持雙鑰啟封並押抵實物工時，替石堡遺民逐戶補登在籍名冊（register ledger）。\n"
             "向上（up）返回【九號艙登錄廳】。\n");

    set_exits(([
        "up" : "/d/realm/wanwu/ark_registry_hall.c",
    ]));
    set("is_outdoor", 0);

    set_touch("default", HIY "玄鐵雙槽門在天門引靠近時傳來沉實微溫，蠟封帳冊紙頁厚韌如老牛皮。" NOR);
    set_smell("default", YEL "千年不散的蜂蠟松脂香、陳年乾燥舊紙氣與古銅氧化的沉厚氣息。" NOR);
    set_listen("default", WHT "與外頭嘈雜主機城隔絕的寂靜空間裡，僅聞鋼印壓落帳冊時的沉厚迴音。" NOR);
}

void init() {
    ::init();
    add_action("do_register_ledger", "register");
}

int do_register_ledger(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "ledger" && arg != "清冊" && arg != "配額") {
        notify_fail("你要補登什麼？試試：register ledger\n");
        return 0;
    }

    tell_object(me, HIY "你以天門引與總契銅版啟封塵封千年的【九城商盟離線補給總庫】，展開曾祖手諭！\n" NOR);
    tell_object(me, HIG
        "【逐戶補登・石堡在籍火種清冊（Q1 因果鍵）】\n"
        "你查明『雲記』當年因拒絕放棄平民避難配額而遭放逐；隨即受限於舊約名額上限，\n"
        "預押三十斤高純鹽晶與十套活榫零件折抵維護工時，逐戶補登石堡五十三戶老弱名諱！\n" NOR);
    say(me->query_name() + " 依曾祖手諭逐戶核驗並押上實物工時，完成《石堡在籍火種補登清冊》鋼印登記！\n");

    object t3 = load_object(TIER3_D);
    if (t3) {
        if (!t3->has_k(me, "commerce")) {
            t3->grant_k_from_experiment(me, "commerce", "audit_salt_market_deficit", ([
                "levy_pct"        : 30,
                "buyback_drop_pct": 70
            ]));
        }
        t3->unlock_u_via_path(me, "commerce", "nine_city_quota_ledger", ([
            "registered_households": 53,
            "labor_salt_offset"    : 30
        ]));
    }

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "register", "target": "ledger" ]));
    }
    return 1;
}
