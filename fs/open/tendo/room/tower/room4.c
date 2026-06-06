#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
          set("short","六儀陣");
          set("long",@LONG
這裡就是五行八卦陣中的六儀陣了，在此處你看到了一團團鬼火
，四周陰森森的，伸手不見五指，遠遠的望去，只看到幾處出口，令
你想立刻飛奔過去，只見一陣陣的陰風撲面而來，此時才發覺有許多
妖魔向你這奔來。

LONG);
        set("exits", ([
		"east":__DIR__"room4",
		"south":__DIR__"room4b",
		"west":__DIR__"room4c",
		"north":__DIR__"room4b",
        ]) );
	
        set("no_transmit",1);
setup();
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


