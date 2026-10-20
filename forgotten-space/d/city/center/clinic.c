// d/city/center/clinic.c
// 杏林醫館 (濁氣清心散、試藥童緩衝路徑 C)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石都城・杏林醫館");
    set_long("府城最大的草藥診所與濟世堂口，空氣中瀰漫著清冽的煎藥苦甘之氣。\n"
             "整面牆壁嵌滿了數百個百眼藥斗，分類存放著來自青河縣與大荒各地的靈草散劑。\n"
             "館主白先生正坐在診案前為病患切脈行針。此處常年供應【清心散】(buy pill)\n"
             "供修士百姓淨化紅塵濁氣，亦可申請充任試藥童 (ask bai about 試藥) 領取合法腰牌。\n"
             "東面穿過穿廊可通往金石學塾。\n");

    set_exits(([
        "east": "/d/city/center/academy.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/center_doctor_bai.c");
}
