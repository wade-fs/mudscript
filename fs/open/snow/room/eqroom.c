// Room: /open/start/room/eqroom
inherit ROOM;

void create()
{
	set("short","雪倉庫");
	set("exits",([ /*sizeof()==1 */
	"down" : __DIR__"room2",
 ]));
	set("no_clean_up", 1);
  set ("long", @LONG
讓雪蒼弟子堆垃圾的地方，裡面說不定藏著有你需要的寶藏。
LONG);

  set("light_up", 1);
	set("no_fight",1);
  setup();
}
