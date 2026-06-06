//written by acelan...../u/a/acelan/room/wood21.c

inherit ROOM;

void create()
{
        set("short", "密道的盡頭");
        set("long", @LONG
這裡是密道的盡頭, 有一棵樹幹看起來表面特別平滑, 你繞到另
外一邊去看, 發現樹幹上面刻滿了字(word), 左邊和右邊各有一條垂
到地上的樹藤。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : "/open/killer/mon/room/wood27.c",
   ]));

   set("item_desc", ([
       "word" : "(pull left)通往你想到的地方。\n(pull right)通往你想不到的地方。\n",
   ]));

   set("objects", ([ /* sizeof() == 1 */
       "/open/beggar/npc/young.c":1,
   ]));

        set("no_clean_up", 0);

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
   if( str== "left")
   {
      tell_object( me, "你難以置信的發現西邊開了一個洞, 可以繼續前進。\n");
      set("exits/west", "/open/killer/mon/room/wood20.c");
      return 1;
   }
   if( str== "right")
   {
      tell_object( me, "你一拉下樹藤, 腳下出現一個大洞, 你連叫也來不及就掉下去了。\n");
      me->move("/open/killer/mon/room/wood14.c");
      return 1;
   }
   return notify_fail("拉什麼?，不要亂拉好不好?\n");
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
