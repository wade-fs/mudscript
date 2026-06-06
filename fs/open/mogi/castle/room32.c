// room7.c by konn
inherit ROOM;
#include <ansi.h>
void create () {
set ("short", HIG"神秘地帶"NOR);
        set ("long","這裡似乎就是傲嘯天所說的神秘地帶，傳說由此可以逃到古堡外頭，
只見這裡泛著淡淡的慘綠，詭異萬分，你不禁考慮是否藉機逃到外
頭，畢竟這裡的妖魔實在太可怕了...念頭一轉，還是先搜尋(search)
一番再說吧...
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ 
        "east" :  __DIR__"room31",  
            
            
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

        if(!str || str != "hole"){
                return notify_fail("你想跳到那裡？\n");
                           return 1;
                                 }
            me->add("sen",-100);
            tell_object(me,"你縱身跳進這綠色的漩渦，頓時神智昏迷，迷迷糊糊中被傳到某一地方.....。\n");
            me->move(__DIR__"entrance");
            return 1;

            
}
int do_search()
{
object me;
 me = this_player();
 tell_object(me,"你找啊找，終於在牆上發現一個綠色的漩渦(hole)，怪詭異的，跳(jump)進去不知會到那裡？\n");
 return 1;
}
