//written by acelan...../u/a/acelan/ghost/room/ghost12.c
//2001.12.11 Modify by Wataru for 幻之忍殺
//載此處增加，八卦迷陣

inherit ROOM;
void create()
{
 object me=this_player();

        set("short", me->query("name")+"之墓");
        set("long", "什麼....這裡竟是我的墳墓, 再仔細看看墓碑(gravestone), \n"+
"上面果然是寫著「"+me->query("name")+"之墓」, 看得你嚇出了一身冷汗,\n"+
" 只聽見墳墓內傳來陣陣的哭聲。哇....媽呀....還不快走。\n\n");
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
 set("objects", ([ /* sizeof() == 1 */
  "/open/killer/mon/ghost/npc/empty.c" : 1,
]));
   setup();
}

void init()
{
        object me=this_player();
//避免光create會使後到的人，看不到是自己的墓
        set("short", me->query("name")+"之墓");
        set("long", "什麼....這裡竟是我的墳墓, 再仔細看看墓碑(gravestone), \n"+
"上面果然是寫著「"+me->query("name")+"之墓」, 看得你嚇出了一身冷汗,\n"+
" 只聽見墳墓內傳來陣陣的哭聲。哇....媽呀....還不快走。\n\n");
   set("item_desc", ([ /* sizeof() == 1 */
       "gravestone" : "上面寫著幾個大字「"+me->query("name")+"之墓」\n",
   ]));
   set("search_desc", ([ /* sizeof() == 1 */
       "gravestone" : "你仔細看過自己的墓碑後發現, 它的底部有摩擦過的痕跡, 看來似乎是可以推(pull)的。\n",
   ]));

   add_action("do_pull", "pull");
   add_action("do_intone", "intone");
}

int do_pull( string arg)
{
   object me=this_player();
   if( arg != "gravestone")
   {
      message_vision("你要推什麼.........\n", me);
      return 0;
   }
   message_vision("你使勁的將你的墓碑推開後, 赫然發現在墓碑之後竟然還有個通道。\n", me);
   set("exits/west", __DIR__"ghost11.c");
   return 1;
}

int do_intone( string arg)
{
   object me=this_player();
   
   if (me->query_temp("firstpart") !=9)
   	return 0;
   if( arg != "耶西西凹安骯")
   {
      message_vision("你到底在吟唱什麼呀？很吵耶........\n", me);
      return 0;
   }
   message_vision("當$N將老祖所教的咒文吟唱了一下後，墓碑上出現了一個羅盤\n", me);
   message_vision("$N將羅盤取下，瞬時一道光芒攏罩$N......\n", me);
   new("/open/killer/ninja/find/gmap.c")->move(me);
   me->set_temp("firstpart",10);
   me->move("/open/killer/ninja/find/9block.c");
   return 1;
}


int valid_leave(object me, string dir)
{
   if (dir != "west")
   {
      this_object()->delete("exits/west");
      return 1;
   }
   return 1;
}

