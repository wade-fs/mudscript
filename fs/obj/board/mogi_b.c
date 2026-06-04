
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
set_name(HIB + "魔界留言板" + NOR, ({"board"}));
set("location","/open/mogi/village/room/room-04");
  set("board_id", "mogi_b");
  set("long", "對魔界有什麼意見可以post在這");
  setup();
set("capacity",300);
  set("master", ({"roger","eva","poloer"}));
  }
