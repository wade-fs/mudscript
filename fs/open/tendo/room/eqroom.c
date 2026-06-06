// Room: /open/start/room/eqroom
inherit ROOM;

void create()
{
	set("short","EQ儲藏室");
	set("exits",([ /*sizeof()==1 */
	"south" : __DIR__"start",
 ]));
	set("no_clean_up", 1);
  set ("long", @LONG
這裡是天道派為了造福新進弟子所開闢的EQ室，看到房間內滿滿的EQ
你不禁感到一股暖流直透心頭.
LONG);

  set("light_up", 1);
	set("no_fight",1);
  setup();
call_other("/obj/board/ten_b.c","???");
}
