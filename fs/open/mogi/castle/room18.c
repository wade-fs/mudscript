// room7.c by konn
inherit ROOM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
void create () {
set ("short","古堡一樓");
        set ("long","四周似乎還潛伏著什麼妖魔鬼怪,令人心裡惶惶不安。地板是由已腐舊的的木板
釘成,走在上面不停的發出嘎吱嘎吱的聲音。令人不禁想起是否有陷阱呢。

                      ～嘎吱～嘎吱～

");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "east" :  __DIR__"room16",
            "south"  : __DIR__"room17",
            "northeast" :  __DIR__"room20",
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
   if( random(300) > obj->query_skill("dodge") ) {
   message_vision(HIR + "突然間四周無數隻箭射了過來,$N閃躲不及,只聽一聲哀嚎$N已被箭射中！\n" + NOR,obj);
   obj->add("kee",-kee1/10);
                                                  }                                              
  else  message_vision(HIW + "突然間四周無數隻箭射了過來,但$N的輕功\了得,危急中避了開去\n" + NOR,obj);   
       }
}

