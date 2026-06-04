inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
set_name(HIC + "皓月" + HIY + "明鏡" + NOR,({"mirror","board"}));
 set("long",HIW + "伸手觸摸這光滑的明鏡，腦中一幕一幕浮出舊時的記憶。\n" + NOR);
 set("location","/u/m/marsden/workroom.c");
 set("board_id","marsden_b");
setup();
 set("capacity",300);
 set("master",({"marsden"}));
}

