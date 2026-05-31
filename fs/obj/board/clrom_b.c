inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
set_name(HIW"幫派系統討論板"NOR,({"board"}));
set("location","/u/c/chan/cl_room");
set("board_id","clan_b");
set("long","這是讓幫派系列的巫師來討論問題的及研究系統的討論佈告欄\n");
setup();
set("capacity",200);
replace_program(BULLETIN_BOARD);
}
