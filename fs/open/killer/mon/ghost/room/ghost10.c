//written by acelan...../u/a/acelan/ghost/room/ghost10.c
#include <ansi.h>
inherit ROOM;

void create()
{
        object me;
        me= this_player();
        set("short", "墳墓");
        set("long", @LONG
這是一個很大很華麗的墳墓, 四周有圍牆圍住, 墓穴是由石材所
做成的, 圍起來的面積很大, 最少可容納十多人, 看來這個墓穴內住
的人必定是大有來頭的人物, 可是墓碑(gravestone)上卻是一個字都
沒寫, 看起來挺古怪的。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "west"  : __DIR__"ghost9.c",
   ]));
   set("item_desc", ([ /* sizeof() == 1 */
       "gravestone" : "一塊什麼字都沒寫的墓碑\n",
   ]));
   set("search_desc", ([ /* sizeof() == 1 */
       "gravestone" : "你仔細觀察這塊墓碑後, 發現它的上面有寫著幾個字, 好像是「芝麻開門」。\n",
   ]));
   set("no_clean_up", 0);

   setup();
}

void init()
{
   add_action("do_say", "say");
}

int do_say( string arg)
{
   object me;
   me= this_player();
   if( arg != "芝麻開門")
   {
      message_vision("你在念什麼ㄚ, 沒看過阿里巴巴與四十大盜嗎...\n", me);
      return 0;
   }
   message_vision(HIY"突然間轟的一聲, 只見墓碑緩緩升起, 在你前方出現了一條路。\n"NOR, me);
   set("exits/north", __DIR__"ghost16.c");
   return 1;
}

int valid_leave(object me, string dir)
{
   if (dir != "north" && this_object()->query("exits/north"))
   {
      message_vision(HIY"突然間轟的一聲, 只見墓碑掉了下來, 又將洞口堵住了。\n"NOR, me);
      this_object()->delete("exits/north");
   }
   return 1;
}
