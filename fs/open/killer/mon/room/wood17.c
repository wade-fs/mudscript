//written by acelan...../u/a/acelan/room/wood17.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "神祕的地道");
        set("long", @LONG
在你面前有一個閃爍著耀眼光芒的水晶轉盤 (wheel), 藉著火把
的反射, 正散發著詭異光芒。除此之外, 地道內除了自己的身影外,
已無他物了。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : "/open/killer/mon/room/wood25.c",
   ]));
   set("no_clean_up", 0);
   set("light_up", 1);
   set("item_desc", ([ /* sizeof() == 1 */
       "wheel" : "這是個使用水晶所打造的轉盤, 正閃爍著詭異的光芒, 它看起來\n似乎是可以旋轉(turn)的\n",
   ]));
   set("search_desc", ([ /* sizeof() == 1 */
       "wheel" : "你仔細看過轉盤之後發現它不但可以旋轉, 而且還發現了一個按\n鈕(button),你可以試著按下(press)它\n",
   ]));

   setup();
}

void init()
{
   add_action("do_turn_wheel", "turn");
   add_action("do_press_wheel", "press");
}

int do_turn_wheel( string arg)
{
   object user;
   user= this_player();
   if( arg == "wheel")
   {
      tell_object( this_player(), HIY"你將轉盤轉了兩圈之後, 地板開始慢慢的上升, 把你送出了地道...\n"NOR);
      user->move("/open/killer/mon/room/wood13.c");
      return 1;
   }
   else
      tell_object( this_player(), "你想要旋轉什麼....\n");
   return 0;
}

int do_press_wheel( string arg)
{
   if( arg == "button")
   {
      tell_object( this_player(), HIY"一按下按鈕, 東側的牆壁無聲無息的打開了, 你讚嘆這機關的巧妙..\n"NOR);
      set("exits/east", "/open/killer/mon/room/wood18.c");
      return 1;
   }
   tell_object( this_player(), "你想要按下什麼....\n");
   return 1;
}

int valid_leave(object me, string dir)
{
  if (dir != "east")
  {
     this_object()->delete("exits/east");
     return 1;
  }
  return 1;
}
