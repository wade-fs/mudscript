#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
          set("short","五行陣");
          set("long",@LONG

你已邁入了五行八卦陣中的五行陣，在此處你看到了滿地的枯骨，
四周毫無光線，伸手不見五指, 遠遠的望去，只看到一點亮光，令你想
立刻飛奔過去，只見一陣陣的陰風撲面而來，此時才發覺有許多的妖魅
向你這飛奔過來。
LONG);
        set("exits", ([
		"north":__DIR__"room3c",
		"south":__DIR__"room3f",
		"west":__DIR__"room3f",
		"east":__DIR__"room3e",
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



