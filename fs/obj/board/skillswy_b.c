inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
set_name(HIY"上訴申請板"NOR,({"skills board","board"}));
set("location","/open/wiz/skroom");
set("board_id","skillswy_b");
set("long","若對skills and funcs有意見，可以來這post");
setup();
set("capacity",300);
  }
