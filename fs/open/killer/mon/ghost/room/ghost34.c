//written by acelan...../u/a/acelan/ghost/room/ghost34.c

inherit ROOM;

void create()
{
        set("short", "黑風組總部");
        set("long", @LONG
這裡是黑風組的總部, 黑風組員一個個神色木然, 看起來頗不易
與, 四周空盪盪的, 除了牆上釘了幾把千古恨外, 便再無其他東西了
, 看來黑風組並不富裕。南邊有片很特別的土牆壁(wall)。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : __DIR__"ghost37.c",
       "east"  : __DIR__"ghost35.c",
       "west"  : __DIR__"ghost33.c",
   ]));
 set("objects", ([ /* sizeof() == 1 */
  "/open/killer/mon/ghost/npc/black2.c" : 2,
]));
   setup();
}

void init()
{
   add_action("do_search", "search");
}

int do_search( string str)
{
   object me= this_player();
   if( str != "wall")
   {
      message_vision("你要找什麼...\n", me);
      return 0;
   }
   message_vision("你赫然發現這土牆其實是一扇旋轉門, 你一拍牆壁, 隨著牆壁旋轉進去了。\n", me);
   me->move( __DIR__"ghost31");
   return 1;
}
