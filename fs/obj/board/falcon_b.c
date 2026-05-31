inherit BULLETIN_BOARD;
#include <ansi.h>
void create()

{
set_name(HIR"我就是那把刀"NOR,({"falcon board","board"}));
set("location","/u/f/falcon/workroom.c");
set("board_id","falcon_b");
set("long","有事請留言, 我會幫你轉答給 Falcon 的");
setup();
set("capacity",100);
set("master",({"falcon"}));
}

