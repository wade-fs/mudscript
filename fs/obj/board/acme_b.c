#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
  set_name("電子記事本", ({"board"}));
  set("location","/u/a/acme/workroom.c");
  set("board_id","acme_b");
  set("long", "這是acme的高科技設備\n");
    setup();
   set("capacity", 100);
  set("master",({"acme"}));
}

