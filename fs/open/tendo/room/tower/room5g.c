#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
          set("short","七星陣");
        set("outdoors", 1);
       set("long", @LONG
你已經走入八卦七星陣，只見四周都是岩石，以及一些困死在此
的人的骸骨，在此你已無法辨明方向。四處陰森森的，空氣中瀰漫著
一股不尋常的氣息，就連你帶進來的火把也顯得十分的暗淡。這樣的
場面使你怯步，心中一股寒意不禁油然升起，有種聲音一直在叫你回
頭，不要繼續往前走了....
LONG);
        set("exits", ([
		"north":__DIR__"room5h",
		"south":__DIR__"room5b",
		"west":__DIR__"room5h",
		"east":__DIR__"room5c",
       ]));
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


