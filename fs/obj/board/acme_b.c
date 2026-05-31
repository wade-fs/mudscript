#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
  set_name("[0;1;5;33m¹[1;5mq[1;5m¤[1;5ml[1;5m°[1;5mO[1;5m¨[1;5mÆ[1;5m¥[1;5m»[0m", ({"board"}));
  set("location","/u/a/acme/workroom.c");
  set("board_id","acme_b");
  set("long", "³o¬Oacmeªº°ª¬ì§Þ³]³Æ\n");
    setup();
   set("capacity", 100);
  set("master",({"acme"}));
}

