// Room: /open/capital/room/farm
inherit ROOM;

void create()
{
  set ("short", "小廣場");
  set ("long", @LONG
這兒是供給軍糧的地方，中間有個廣場。有幾間茅草屋在廣場兩側
，有間很大的木製房子立在正前方，房子前面有士兵在巡邏，大概就是
儲糧的地方了。廣場上有幾個士兵忙碌的搬運糧草。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/soldier1" : 2,
  ]));

  set("light_up", 1);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/capital/room/foodh",
  "east" : "/open/capital/room/r46",
]));

  setup();
}
int valid_leave(object me,string dir)
{

   if( (dir=="north") && (present("soldier",environment(me))) )
   return notify_fail("禁衛軍對你大吼:快滾!這裡不是你該來的地方!!\n");


   return ::valid_leave(me,dir);
}
