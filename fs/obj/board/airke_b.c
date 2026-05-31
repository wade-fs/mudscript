//roger's board
inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name("電腦留言機",({"board"}));
	set("location","/u/a/airke/workroom");
	set("board_id","airke_b1");
   set("long","高科技的橢圓形乳白銀幕,顯示魔界一切的狀態。\n");
   setup();
   set("capacity", 100);
	set("master",({"airke"}));
}
