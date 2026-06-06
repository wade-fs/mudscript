//written by acelan...../u/a/acelan/ghost/room/ghost12.c

inherit ROOM;

void create()
{
        object me;
        me= this_player();
        set("short", me->query("name")+"之墓");
        set("long", @LONG
什麼....這裡竟是我的墳墓, 再仔細看看墓碑(gravestone), 上
面果然是寫著「"+me->query("name")+"之墓」, 看得你嚇出了一身冷汗, 只聽見墳墓
內傳來陣陣的哭聲。哇....媽呀....還不快走。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : __DIR__"ghost19.c",
       "south" : __DIR__"ghost6.c",
       "east"  : __DIR__"ghost13.c",
   ]));
   set("item_desc", ([ /* sizeof() == 1 */
       "gravestone" : "上面寫著幾個大字「"+me->query("name")+"之墓」\n",
   ]));
   set("search_desc", ([ /* sizeof() == 1 */
       "gravestone" : "你仔細看過自己的墓碑後發現, 它的底部有摩擦過的痕跡, 看來似乎是可以推(pull)的。\n",
   ]));
   set("no_clean_up", 0);

   setup();
}

void init()
{
   add_action("do_pull", "pull");
}

int do_pull( string arg)
{
   object me;
   me= this_player();
   if( arg != "gravestone")
   {
      mission_vision("你要推什麼.........\n", me);
      return 0;
   }
   mission_vision("你使勁的將你的墓碑推開後, 赫然發現在墓碑之後竟然還有個通道。\n", me);
   set("exits/west", __DIR__"ghost11.c");
}

int valid_leave(object me, string dir)
{
   if (dir != "west")
   {
      this_object()->delete("exits/down");
      return 1;
   }
   return 0;
}
