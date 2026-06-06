
inherit ROOM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
void create () {
set ("short","七色迴路");
        set ("long","一步踏入此地, 立覺陰冷刺骨, 此處乃是妖魔古堡中最陰最寒之地. 儘管
兩邊的牆壁上掛著兩列燭臺, 卻不透一絲絲暖意, 冷光落壁, 邪氳雰雰, 
魔氣呼嘯, 掠影幢幢, 你頓時發現聽覺與視覺已經不能作出正確的判斷. 
突來陣陣殺氣掀起了紫黑色的火線, 血腥的戰鬥將隨時發生. 

");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "south" : __DIR__"room82",
            "east" : __DIR__"room88",
            "north" : __DIR__"room84",          
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
   if( random(500) > obj->query_skill("parry")+obj->query_skill("dodge") ) {
   message_vision(HIR + "嗤嗤聲響處，幾枚毒蒺菱快速射出，$N閃躲不及被毒蒺菱給射中！\n" + NOR,obj);
   obj->add("eff_kee",-kee1/30);
   obj->apply_condition("dark_poison",random(20));
                                                  }                                              
  else  message_vision(HIW + "嗤嗤聲響處，幾枚毒蒺菱快速射出，$N連忙竄高伏低，並揮手擊落射來的暗器\n" + NOR,obj);   
       }
}

