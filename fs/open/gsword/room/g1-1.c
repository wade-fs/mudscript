// Room: /open/su/room/suroad9_1.c

inherit ROOM;

void create ()
{
  set ("short", "紫皇大殿");
	set( "build", 36 );
  set ("long", @LONG
這是仙劍派的大殿，殿中數位劍士恭謹的站在兩側，看看這的陳設，
全以紫檀木造成，少了一種壯麗，確多一分莫名的英氣。唯一令你不解是
大殿掌門人的位置上，卻不見掌門人 ─ 鄭士欣，坐在其上。看來想拜師
的話只好問問左右的劍士們了。
　
LONG);

  set("light_up",1);
  set("exits", ([ /* sizeof() == 3 */
  "north" : "/open/gsword/room/g1-3.c",
  "out" : "/open/gsword/room/test.c",
  "south": "/open/gsword/room/roomf",
  "east" : "/open/gsword/room/g1-2.c",
]));

  set("objects", ([ /* sizeof() == 2 */
  "/open/gsword/npc/swordsman" : 2,
  "/daemon/class/swordsman/chenfon" :1 ,
]));

   set("valid_startroom", 1);
    set("light_up", 1 );

  setup();
}
