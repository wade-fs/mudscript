// room7.c by roger
inherit ROOM;
#include <ansi.h>
void create () {
    set ("short", HIR"焚天魔域"NOR);
    set( "build", 113 );
    set ("long","這個房間一片通紅，牆上有團紅色的火焰，烈焰奔騰，火焰隨著你的情緒起伏有秩。
看起來蠻嚇人的，不妨(search)一番看看有啥收穫。
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ 
        "north" :  __DIR__"room64",  
            
            
      ]));

        setup();
}
void init()
{
        add_action("do_search", "search");
        add_action("do_jump","jump");
}

int do_jump(string str){

   object me;
   me = this_player();

        if(!str || str != "fire"){
                return notify_fail("你想跳到那裡？\n");
                           return 1;
                                 }
            me->add("sen",-100);
            tell_object(me,"你縱身跳進這紅色的火焰，頓時神智昏迷，迷迷糊糊中被傳到某一地方.....。\n");
            me->move(__DIR__"entrance");
            return 1;

            
}
int do_search()
{
object me;
 me = this_player();
 tell_object(me,"你找啊找，終於在牆上發現一團紅色的火焰(fire)，怪詭異的，跳(jump)進去不知會到那裡？\n");
 return 1;
}
