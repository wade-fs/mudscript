
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "鎖妖塔三樓--");
  set ("long", @LONG
這裡的陳設和方才的那間相似：空盪盪的，沒有窗戶，只有個往四樓的長梯，
以及一地的血印、破磚、和那股惱人的深藍色，你只覺得自己不斷地在喘氣，彷彿
驚魂未定。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"room3",
  "west" : __DIR__"tower3-2",
]));

        set("no_transmit",1);

  setup();
}
int valid_leave(object me, string dir)
{
        if( dir=="up" )
        message("system",
 HIW + "\n\t武林之中傳來一道消息 : " + HIY + ""+this_player()->name()+"" + HIW + "勇闖" + HIR + "鎖妖塔" + HIW + "第四層了 !!\n" + NOR,users());
        return ::valid_leave(me, dir);
}
void init()
{
        if( !previous_object()
        ||      !userp(previous_object()) )
                return;
      call_out( "fire_wound", 3,previous_object());
}

void fire_wound(object ob)
{
        if( !ob || !present(ob) ) return;
       tell_object(ob,HIR + "～鬼影幢幢～你覺得胸中一陣翻滾，忽然一道血箭從你的嘴裡噴了出來。\n" + NOR);
       ob->add("kee",-100);
       call_out("fire_wound", 3,ob);
}


void reset()
{
        ::reset();
        delete("go_north");
}




