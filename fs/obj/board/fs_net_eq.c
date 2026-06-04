
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
set_name(HIG + "網聚獎品板" + NOR,({"restore board","board"}));
set("location","/open/wiz/fs_net_room");
set("board_id","fs_net_eq");
set("long","所有網聚獎品的贈與跟想法，可以來這post請wiz 轉贈跟修改");
  setup();
set("capacity",300);
  }
