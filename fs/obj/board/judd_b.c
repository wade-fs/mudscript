#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
	set_name("電子佈告欄", ({"board"}));
  set("location","/u/j/judd/workroom.c");
  set("board_id","judd_b");
  set("long", "這是小張宇的電子留言版\n");
    setup();
   set("capacity", 100);
  set("master",({"judd"}));
}

