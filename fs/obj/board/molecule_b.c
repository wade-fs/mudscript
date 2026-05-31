inherit BULLETIN_BOARD;
#include <ansi.h>
void create()

{
set_name(HIC"傷心咖啡店"NOR,({"coffee shop","shop","coffee","board"}));
set("location","/u/m/molecule/workroom.c");
set("board_id","molecule_c");
set("long",HIW"來杯香醇的咖啡吧。"NOR);
setup();
set("capacity",200);
set("master",({"molecule"}));
}
