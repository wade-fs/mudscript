//open/prayer/room/kicthen2

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "廚房");
  set ("long", @LONG

	    這裡是處理所剩餘的菜渣的地方，因此顯
	得有些凌亂不墈，並有陣陣的惡臭傳出，看來
	還是快些離開好了．

LONG);
  set("exits", ([ /* sizeof() ==  2*/
	"north" : "/open/prayer/room/kicthen5",		//`廚房
	"east" : "/open/prayer/room/kicthen3",		//`廚房
]));
   set("light_up", 1);

  setup();
}
 
