//written by acelan...../u/a/acelan/room/wood12.c

inherit ROOM;

void create()
{
        set("short", "小徑的盡頭");
        set("long", @LONG
你來到了小徑的盡頭, 你訝異竟然沒有路了, 但正當你要往回走
的時候, 你發現地上若隱若現的隱約有個奇怪的符號(sign), 不知道
到底是寫著什麼。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "south" : "/open/killer/mon/room/wood5.c",
   ]));
   set("item_desc", ([
       "sign" : "你仔細的看過這個符號之後, 發現它是指向一個拉桿(level),\n你可以試著拉拉看(pull)。\n",
   ]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/killer/mon/npc/grnnpc1.c" : 2,
]));
        setup();
}

void init()
{
   add_action("do_pull", "pull");
}

int do_pull( string str)
{
   object me;
   me= this_player();
   if( str== "level")
   {
      tell_object( me, "你發現了一個往下的密道\n");
      set("exits/down", "/open/killer/mon/room/wood16.c");
      return 1;
   }
   return notify_fail("拉什麼?，不要亂拉好不好?\n");
}

int valid_leave(object me, string dir)
{
  if (dir != "down")
  {
     this_object()->delete("exits/down");
     return 1;
  }
  return 1;
}
