
inherit ROOM;
#include <ansi.h>
void create()
{
  set ("short", "鎖妖塔二樓--");
  set ("long", @LONG
來到這兒，由於有小氣窗的關係，兀自吱吱作響，偶爾還會落下一兩片破磚
碎瓦，一切顯得是那麼蕭瑟，慘淡。這裡有個通往鎖妖塔三樓的的樓梯。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tower3-1",
  "east" : __DIR__"tower2-2",
]));
        set("no_transmit",1);
  setup();
}
int valid_leave(object me, string dir)
{
        if( dir=="up" )
        message("system",
 HIW"\n\t武林之中傳來一道消息 : "HIY""+this_player()->name()+""HIW"勇闖"HIR"鎖妖塔"HIW"第三層了 !!\n"NOR,users());
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
       tell_object(ob,HIR"～鬼影幢幢～你覺得胸中一陣翻滾，忽然一道血箭從你的嘴裡噴了出來。\n"NOR);
       ob->add("kee",-100);
       call_out("fire_wound", 3,ob);
}


void reset()
{
        ::reset();
        delete("go_north");
}


