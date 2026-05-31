#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
  set_name("蛋蛋佈告欄", ({"board"}));
  set("location","/u/a/acelan/workroom.c");
  set("board_id","acelan_b");
  set("long", "這是蛋蛋的塗鴉牆\n");
    setup();
   set("capacity", 100);
  set("master",({"acelan"}));
}


