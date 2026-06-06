//room:/open/dancer/room/roomsw3s.c :cgy

inherit ROOM;

void create ()
{
  set ("short","廚房" );
  set ("long", @LONG
這裡是夜夢小築的廚房，在這裡你聞到了陣陣的飯菜香，這裡是
由鏡月島的弟子掌廚，別看她正當妙齡之際，一手廚藝還真是令人讚
不絕口，走到此處的你不禁食指大動想大吃一頓。

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "north"     :"/open/dancer/room/roomsw3.c",
  
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/dancer/npc/leing.c" : 1,
]));

  setup();

}
