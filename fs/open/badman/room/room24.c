// room7.c by konn
inherit ROOM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
void create () {
set ("short","孤身不過廊");
        set ("long","
這條長廊就是古堡裡有名的「孤身不過」長廊，顧名思義，意指若你
想孤身闖過這道長廊簡直難如登天。沿途不但有越來越多的妖魔鎮守
更不知道那裡會有暗器射出。雖然長廊不見的很長，但是恐怖的程度
會讓你有永遠走不完的驚慄。
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "down"  : __DIR__"room11",
            "north" : __DIR__"room25",        
      ]));
        setup();
}

void init()
{
      call_out("do_damage",1,this_player()); 
}
void do_damage(object ob){
 mixed all;
 object obj,who,room;
 int kee1,i,j;
    
    
        room = environment(ob);
        all = all_inventory(room);
        for( i = 0 ; i < sizeof(all) ; i++)
        {
   obj = all[i];
   kee1=obj->query("eff_kee");  
   if( random(300) > obj->query_skill("parry") ) {
   message_vision(HIR + "忽然破空之聲尖銳響起，數支破甲錐快速奔向$N且射穿了$N，血流不止！\n" + NOR,obj);
   obj->add("eff_kee",-kee1/10);
   obj->apply_condition("bleeding",random(30));
                                                  }                                              
  else  message_vision(HIW + "忽然破空之聲尖銳響起，數支破甲錐快速奔向$N，但被$N一一打落在地！\n" + NOR,obj);   
       }
   write(HIC + "四周響起「嘿 嘿......」的冷笑聲\n" + NOR);
}

