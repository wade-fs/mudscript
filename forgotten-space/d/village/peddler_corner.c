// d/village/peddler_corner.c
// 黑石鋪・老貨郎雜貨棚（日用雜貨、便宜文墨與平價乾糧補給）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("黑石鋪・老貨郎雜貨棚");
    set_long("挨著陳記雜糧鋪南山牆搭出來的一座油布木棚，簷下掛滿了一串串黃麻草鞋、\n"
             "竹編斗笠、粗陶油燈與鐵皮火摺子。胡二貨郎的雙輪木推車停在棚角，木格裡\n"
             "擺著針線、粗鹽包、廉價松煙墨錠與耐放的死麵乾麥餅 (ration)。\n"
             "向北繞回【陳記雜糧鋪】。\n");

    set_exits(([
        "north": "/d/village/chen_grain_shop.c",
    ]));

    set("is_outdoor", 0);
    set("no_combat", 1);

    set_touch("default", YEL "新編的黃麻草鞋粗礪紮手，貨擔銅鎖被胡二長年摩挲得鋥亮溫熱。" NOR);
    set_smell("default", YEL "乾麥餅的烤焦麵香、生桐油布味道與廉價松煙墨氣味混在一起。" NOR);
    set_listen("default", HIY "簷下那串貨郎銅鈴被山風吹得「叮鈴、叮鈴」輕響，伴隨著胡二撥算盤報價聲。" NOR);

    spawn_npc("/clone/npc/folk/peddler_hu.c");
}

void init() {
    ::init();
    add_action("do_browse_goods", "browse");
    add_action("do_browse_goods", "貨單");
    add_action("do_buy_ration", "buy_ration");
    add_action("do_buy_ration", "買乾糧");
    add_action("do_village_cargo", "cargo");
    add_action("do_village_cargo", "跑商");
}

int do_village_cargo(string arg) {
    object me = this_player();
    if (!me) return 0;
    object ws = load_object(WORLD_STATE_D);
    if (!ws) return 0;

    if (!arg || arg == "" || arg == "list" || arg == "行情") {
        write(ws->format_trade_board("blackstone"));
        return 1;
    }
    string sub = "";
    string cid = "";
    if (sscanf(arg, "%s %s", sub, cid) == 2 && (sub == "buy" || sub == "買")) {
        mapping bres = ws->buy_trade_cargo(me, cid, "blackstone");
        write(bres["msg"] + "\n");
        return 1;
    }
    if (arg == "sell" || arg == "賣") {
        mapping sres = ws->sell_trade_cargo(me, "blackstone");
        write(sres["msg"] + "\n");
        return 1;
    }
    write("用法：cargo list | cargo buy <貨號> | cargo sell\n");
    return 1;
}

int do_browse_goods(string arg) {
    write(HIY "\n【胡二貨郎・日常雜貨價目】\n" NOR
          "  ・耐放死麵乾麥餅：2 文銅錢 (指令: buy_ration / 買乾糧)\n"
          "  ・黃麻編草鞋：5 文銅錢（走官道磨腳必備）\n"
          "  ・防水松脂火摺：3 文銅錢\n"
          "  ・松煙墨與舊字帖：10 文銅錢（村塾宋秀才常賒購）\n\n");
    return 1;
}

int do_buy_ration(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (me->query("money") < 2 && me->query_money() < 2) {
        write("你摸遍衣袋湊不出 2 文銅錢，胡二擺手笑道：「下回賺了工錢再來賒個熱餅吧！」\n");
        return 1;
    }
    if (me->query_money() >= 2) {
        me->add_money(-2);
    } else {
        me->add("money", -2);
    }
    me->add(VITAL_KEE, 10);
    me->add(VITAL_SP, 20);
    write(HIG "你付了 2 文銅錢從胡二貨擔裡買下一塊厚實的死麵乾麥餅啃下，胃裡頓時踏實不少（氣血 +10、精力 +20）。\n" NOR);
    return 1;
}
