// d/village/village_school.c
// 黑石鋪・村尾蒙館（非修仙線的平民識字、算帳與基礎啟蒙）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("黑石鋪・村尾蒙館");
    set_long("一間土坯壘砌、窗紙糊著舊油紙的簡陋村塾，門楣上掛著宋秀才親筆寫的\n"
             "木匾『耕讀傳家』。屋裡擺著五張高低不平的長條木凳與沙土盤 (sandbox)，幾名\n"
             "半大孩子正低頭用細木棍在淺沙盤裡臨摹《千字文》與算籌口訣。\n"
             "向南走出低矮竹籬即回【村尾土地廟】。\n");

    set_exits(([
        "south": "/d/village/earth_shrine.c",
    ]));

    set("is_outdoor", 0);
    set("no_combat", 1);

    set_touch("default", YEL "沙盤裡細沙微涼乾燥，長條木凳被孩童磨得光滑圓潤，硯台邊沾著一點乾涸松煙墨漬。" NOR);
    set_smell("default", CYN "舊宣紙、廉價松煙墨的苦香與土牆乾泥味安靜地浮在屋裡。" NOR);
    set_listen("default", HIG "幾個村童齊聲背誦『天地玄黃、宇宙洪荒』的清亮童音夾著先生輕敲桌面的木尺聲。" NOR);

    mapping copy_rule = ([
        "targets": ({ "sandbox", "characters", "字帖", "沙盤", "" }),
        "sp_cost": 4,
        "sensory_msg": CYN "你拾起細木棍在沙盤裡一筆一劃臨摹『人、山、水、糧、契』諸字，浮躁心緒漸漸沉靜下來。" NOR,
        "train_stat": ([ "int": 8, "per": 6 ]),
        "exp_gain": 6
    ]);
    add_action_rule("copy", copy_rule);
    add_action_rule("臨摹", copy_rule);

    spawn_npc("/clone/npc/folk/song_xiucai.c");
}
