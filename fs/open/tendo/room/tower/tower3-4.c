
inherit ROOM;
#include <ansi.h>
void create()
{
  set ("short","鎖妖塔三樓--");
  set ("long", @LONG
剛踏上這一層樓，你的視線就被一股深藍色所佔滿。這一層的四周牆壁，已經
不再是剛剛的那種暗紅，而是漆上了一種令人不寒而慄的深藍；加上斑駁的血印，
使剛剛那股肅殺的氣氛又籠罩在你身上。
LONG);

	set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"tower3-1",
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
       tell_object(ob,HIR + "～鬼影幢幢～你覺得胸中一陣翻滾，忽然一道血箭從你的嘴裡噴了出來。\n" + NOR);
       ob->add("kee",-100);
       call_out("fire_wound", 6,ob);
}

