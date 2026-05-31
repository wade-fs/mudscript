inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
set_name(HIC"意見發表處"NOR,({"means board","board"}));
set("location","/open/wiz/fsroom");
set("board_id","fsstr_b");
set("long","若對狂想空間有任何的建議,可以來這裏post");
setup();
set("capacity",300);
  }
