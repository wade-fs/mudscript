#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
set_name(HIR + "聖火" + HIW + "風雲錄" + NOR,({"fire board","board"}));
set("location","/open/clan/fire.c");
set("board_id","fire_b");
set("long","記載聖火教歷代大事的記實冊。\n");
setup();
set("capacity",100);
}

