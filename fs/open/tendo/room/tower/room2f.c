#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
          set("short","四象陣");
        
                    set("long",@LONG

你已經走入五行八卦陣的四象陣中，只見四周都是岩石，以及一
些困死在此的人的骸骨，在此你已無法辨明方向。腐爛的惡臭更是令
你無法忍受。再加上地面上都是爛泥，更是難走，腳上七高八低，望
出來黑漆一團，令人覺得一陰森恐怖。
LONG);
        set("exits", ([
		"north":__DIR__"room2g",
		"south":__DIR__"room2c",
		"west":__DIR__"room2d",
	        "east":__DIR__"room2g",
        ]) );
	set("objects",([
]));
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
       tell_object(ob,HIR + "～鬼影幢幢～你覺得胸中一陣翻滾，忽然一道血箭從你的嘴裡噴了出來。\n" + NOR);
       ob->add("kee",-100);
       call_out("fire_wound", 3,ob);
}


void reset()
{
        ::reset();
        delete("go_north");
}




