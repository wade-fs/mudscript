//written by acelan...../u/a/acelan/ghost/room/ghost31.c

inherit ROOM;

void create()
{
        set("short", "墓園小徑");
        set("long", @LONG
這是一條在墓園中的小徑, 不過這條卻出奇的隱密, 再往東去,
是一望無際的墓園, 而北面則是一面土牆壁(wall), 看來小徑到了這
裡, 確實是已經到了盡頭了。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "west"  : __DIR__"ghost30.c",
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
   object me= this_player();
   if( str != "wall")
   {
      message_vision("你要找什麼...\n", me);
      return 0;
   }
   message_vision("你赫然發現這土牆其實是一扇旋轉門, 你一拍牆壁, 隨著牆壁旋轉進去了。\n", me);
   me->move( __DIR__"ghost34");
   return 1;
}
