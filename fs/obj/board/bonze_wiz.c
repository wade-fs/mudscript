#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
  set_name("少林發展留言板",({"bonze board","board"}));
  set("location","/open/bonze/room/bonze_room");
  set("board_id","bonze_wiz");
  set("long","為了紀錄曾有的想法或是預計要實現的構想所留下的紀錄。\n");
  setup();
  set("capacity",555);
}
