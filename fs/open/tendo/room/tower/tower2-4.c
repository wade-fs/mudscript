
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "鎖妖塔二樓--");
  set ("long", @LONG
走到了這兒，發現地上的血漬不像方才那麼多，但四周的殺氣比方才更加的
濃烈，你發現遍地骷髏，白骨成堆，燐光閃爍，好似鬼一般，武林中人丟棄的刀
槍劍爪，處處皆世，陰風吹過，寒意透心。
LONG);

	set("exits", ([ /* sizeof() == 2 */
	"south" : __DIR__"tower2-1",
	]));

	set("no_transmit",1);
	setup();
}

void init()
{
        if( !previous_object()
        ||      !userp(previous_object()) )
                return;
      call_out( "fire_wound", 6,previous_object());
}

void fire_wound(object ob)
{
        if( !ob || !present(ob) ) return;
       tell_object(ob,HIR"～鬼影幢幢～你覺得胸中一陣翻滾，忽然一道血箭從你的嘴裡噴了出來。\n"NOR);
       ob->add("kee",-100);
       call_out("fire_wound", 6,ob);
}
