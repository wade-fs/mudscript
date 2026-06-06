// Room: /open/prayer/room/tangi/tangi1-15.c

#include <room.h>
#include "/open/open.h"    
inherit ROOM;

void create()
{
	set("short", "議事廳");
	set("long", @LONG
此處是天機門成員討論問題的所在，往南則是天機門的玄關(open door)．出去大廳後
便是天機門的練武場．往北則是到門主的寶座．兩旁站著許多高階的幹部，個個面
無表情!
LONG
	);
	set("item_desc", ([
	  "south" : (: look_door,     "south" :),  
]));
	set("outdoors", "/open/prayer/room"); 
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"tangi1-14",
  "south" : __DIR__"tangi1-17",
  "north" : __DIR__"tangi1-12.c",
  "east" : __DIR__"tangi1-16",
]));
	set("light_up", 1);
	set("no_clean_up", 0);

	create_door("south","聖火刻紋木雕門", "north",DOOR_CLOSED);
	setup();
	}
