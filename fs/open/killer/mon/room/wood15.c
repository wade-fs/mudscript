//written by acelan...../u/a/acelan/room/wood15.c

inherit ROOM;

void create()
{
        set("short", "小徑的盡頭");
        set("long", @LONG
咦! 小徑到此來到了盡頭, 在一片空地中有一棵參天古木(tree),
四周橫生了許多的枝枒與周圍的樹葉連成一片, 密不透風, 彷彿太陽在
一瞬之間下山了。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "south" : "/open/killer/mon/room/wood11.c",
   ]));

   set("item_desc", ([
       "tree" : "你仔細的看過這棵古木之後, 發現它是空心的, 而且在隱密處\n還有個門(door)\n",
   ]));

        set("no_clean_up", 0);

        setup();
}

void init()
{
   add_action("do_search", "search");
}

int do_search( string str)
{
   object me;
   me= this_player();
   if( str== "door")
   {
      tell_object( me, "果然, 在打開門後你發現了古木之中有一條向上的樓梯。\n");
      set("exits/up", "/open/killer/mon/room/wood22.c");
      return 1;
   }
   return notify_fail("什麼..你在找小度的小褲褲...\n");
}

int valid_leave(object me, string dir)
{
  if (dir != "up")
  {
     this_object()->delete("exits/up");
     return 1;
  }
  return 1;
}
