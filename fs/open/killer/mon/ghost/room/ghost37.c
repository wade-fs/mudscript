//written by acelan...../u/a/acelan/ghost/room/ghost37.c

inherit ROOM;

void create()
{
        set("short", "黑風組總部");
        set("long", @LONG
這裡是黑風組總部的大廳, 只見黑風組長威風凜凜的坐在大廳之
上, 廳前有一個圓桌, 看來應該是議事用的, 大廳的後方就是黑風組
長的臥室, 平時是不準入內的。
LONG);
   set("exits", ([ /* sizeof() == 1 */
       "north" : __DIR__"ghost39.c",
       "south" : __DIR__"ghost34.c",
       "east"  : __DIR__"ghost38.c",
       "west"  : __DIR__"ghost36.c",
   ]));
 set("objects", ([ /* sizeof() == 1 */
  "/open/killer/mon/ghost/npc/hu_fa6.c" : 1,
  "/open/killer/mon/ghost/npc/black2.c" : 2,
]));

   setup();
}

int valid_leave(object me, string dir)
{
   if (dir == "north")
   {
      if( me->query_temp("ghost") == 2)
      {
         message_vision("黑風組長衛博戰說道:「沒想到陳星輝是這種人, 快去將他除掉吧!」\n", me);
         return 1;
      }
      else
      {
         message_vision("黑風組長衛博戰大喝道:「我的閨房豈是$N所能亂闖的嗎?」\n", me);
         return 0;
      }
   }
   return 1;
}
