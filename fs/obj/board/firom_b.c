inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
set_name(HIW + "武者巫師討論板" + NOR,({"board"}));
set("location","/u/c/chan/fi_room");
set("board_id","firoom");
set("long","這是讓武者系列的巫師群來討論問題的及研究系統的討論佈告欄\n");
setup();
set("capacity",200);
replace_program(BULLETIN_BOARD);
}
