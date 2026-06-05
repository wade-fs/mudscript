#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
set_name(HIY + "沙加的秘密花園" + NOR,({"xman board","board"}));
set("location","/u/x/xman/workroom");
set("board_id","xboy_b");
set("long","歡迎灌水澆花,,:)\n");
setup();
set("capacity",555);
set("master",({"xman"}));
}
