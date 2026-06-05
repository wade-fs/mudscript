#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
  set_name(HIC + "女人真心話" + NOR, ({"board"}));
  set("location","/u/p/pana/workroom");
  set("board_id","pana_b");
  set("long","只准留讚美的話!!");
  setup();
  set("capacity",100);
  set("master",({"pana"}));
}

