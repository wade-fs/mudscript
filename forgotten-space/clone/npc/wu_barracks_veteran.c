// clone/npc/wu_barracks_veteran.c
// 石老兵・輪休老兵 (wu_barracks_veteran) - 鎮武兵營

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("石老兵");
    set_short(YEL "鎮武營輪休老兵" NOR " 石老兵");
    set_long("一位滿身刀疤、正坐在兵營石階上用烈酒擦拭舊鐵槍的退伍老卒。\n");
    set_id(({ "wu_barracks_veteran", "wu_barracks_deputy", "shi laobing", "veteran", "石老兵", "輪休老兵", "老兵" }));

    setup_archetype("B", 15);
    set("class", "wu_initiate");
    set("faction", "wu");
    set("roles", ({ "info" }));
    set("schedule", "24h");

    add_response(({ "邊關", "鎮風", "黑石關", "陳鎮山", "胡百戶" }),
        "石老兵灌了一口燒刀子，罵道：「黑石關那個胡百戶也是個利慾熏心的蠢貨，竟敢私吞兵備道的軍火雷管跟商會敗類勾結！要不是陳鎮山將軍當機立斷封關拿人，咱鎮武軍的名聲都被他敗光了！」");
}
