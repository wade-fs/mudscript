#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
          set("short","八卦陣");
          set("long",@LONG
這裡就是五行八卦陣的八卦陣了，在此處你看到了滿地的武器，
四周漆黑如夜，伸手不見五指，遠遠望去，一道光線迎面而來，令你
想立刻飛奔過去，只見一陣陣的陰風撲面而來，此時才發覺有許多鬼
影向你這奔來。

LONG);
        set("exits", ([
		"south":__DIR__"room6",
		"north":__DIR__"room6b",
		"east":__DIR__"room6b",
		"west":__DIR__"room6c",
        ]) );
set("objects", ([ /* sizeof() == 2 */
"/open/tendo/room/tower/npc/genies.c" : 2,
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


void reset()
{
        ::reset();
        delete("go_north");
}




