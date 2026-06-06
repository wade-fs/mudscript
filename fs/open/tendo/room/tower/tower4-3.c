inherit ROOM;
#include <ansi.h>
void create()
{
  set ("short", "鎖妖塔四樓--");
  set ("long", @LONG
來到這裡，你發覺打鬥的痕跡比方才少了許多，這裡的牆壁也是漆著深藍色，不
同的是這裡的空間比前幾層都小了些，不過這一層的挑高比前幾層都高，你想可能是
為了讓闖塔者不易施展輕功的因素。
LONG);

	set("exits", ([ /* sizeof() == 2 */
	"south" : __DIR__"tower4-1",
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



