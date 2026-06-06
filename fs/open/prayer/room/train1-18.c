//open/prayer/room/train1-18

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "練武場");
	set( "build", 31 );
  set ("long", @LONG

	    聖火教總壇的練武場上，你看到許多聖火
	弟子拼命的勤練武功．而眼前這個聖火弟子看
	來武功底子不弱． 

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee4" : 3,
]));
  set("outdoors", "/open/prayer/room");
  set("exits", ([ /* sizeof() == 2 */
	"north" : "/open/prayer/room/train1-13",		//`練武場
	"east" : "/open/prayer/room/train1-17",		//`練武場
]));

  setup();
}
 
