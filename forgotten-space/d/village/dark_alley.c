// d/village/dark_alley.c
// 黑石鋪・客棧後街・青石暗巷 (小說第9、10章場景)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("客棧後街・青石暗巷");
    set_long("這是一條終年不見天日的幽暗死巷。兩側高聳的黃土危牆將外頭的喧囂徹底\n"
             "隔絕，巷道深處凌亂堆放著廢棄的破瓦罐、長滿綠斑的發霉爛木板 (boards)\n"
             "以及幾具殘破的石碾。地面坑窪黏滑，積滿了黑臭的雨水與雜草。\n"
             "巷道南邊直通廢柴房的後門，往東穿過窄縫可折返青石街市。\n"
             "（可在此翻查木板 search boards，或比對星圖殘卷 compare_map）\n");

    set_exits(([
        "south": "/d/village/shed.c",
        "east":  "/d/village/square.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/black_guard.c");
}

void init() {
    ::init();
    add_action("do_compare_map", "compare_map");
    add_action("do_compare_map", "比對星圖");
    add_action("do_compare_map", "拼圖");
    add_action("do_search_boards", "search");
    add_action("do_search_boards", "搜查");
}

int do_compare_map(string arg) {
    object me = this_player();

    // 檢查是否有拓片或殘片
    int has_piece = 0;
    if (me->query_temp("has_stele_rubbing") || present("stele_rubbing", me) || present("rubbing", me) ||
        present("dao crystal", me) || present("crystal", me) ||
        present("ancient black iron", me) || present("black iron", me) ||
        present("tianmen token", me) || present("token", me) ||
        me->query("personal_event/stream_stele")) {
        has_piece = 1;
    }

    if (!has_piece) {
        write("你手頭並無古碑拓片或太古傳承殘件，無法在此暗巷深處推演星軌脈絡。\n");
        return 1;
    }

    object qe = find_object(QUEST_ENGINE_D);
    if (!qe) qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        int res = qe->evaluate_encounter(me, "enc_map_fusion", ([]));
        if (res > 0) {
            write(CYN "你在發霉木板的陰影下避開外界耳目，將手頭的太古星圖殘卷輕輕攤開……\n" NOR);
            write(HIY "【太古周天逆星殘卷・雙脈合契】：青銅古絲與粗紙墨痕嚴絲合縫，太古神魔手撕蒼穹的浩瀚星空半壁在暗巷中綻放出萬道青金微芒！\n" NOR);
            write("墨痕與青銅暗紋交融，你勘破了九天星宿偽網與大地厚土之間的萬古真相，道心在震撼中徹底破立！\n");
            qe->trigger_event(me, "action", ([
                "verb": "compare_map",
                "target": "star_map"
            ]));
            return 1;
        } else {
            return 1;
        }
    }

    write("暗巷深處陰風瑟瑟，殘卷暫時未能引起天地道韻共鳴。\n");
    return 1;
}

int do_search_boards(string arg) {
    object me = this_player();

    if (!arg || (arg != "boards" && arg != "wood" && arg != "木板" && arg != "爛木")) {
        write("你想在暗巷裡搜查什麼？提示：search boards（搜查堆積的爛木堆）\n");
        return 1;
    }

    write(YEL "你撥開潮濕發霉的爛木板，在泥濘石縫深處發現了一枚沾滿暗紅血跡的精鋼三棱破甲錐！\n" NOR);
    object arrow = new("/clone/weapon/armor_piercing_arrow.c");
    if (arrow) {
        arrow->move(me);
        write(HIG "你拾取了一枚【精鋼三棱破甲錐】！\n" NOR);
    }

    object qe = find_object(QUEST_ENGINE_D);
    if (!qe) qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([
            "verb": "search",
            "target": "boards"
        ]));
    }
    return 1;
}
