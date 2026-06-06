
inherit ROOM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
void create () {
set ("short","魔之右翼");
        set ("long","魔氣蕩繞晦明變化, 非比山間之朝暮霏霏, 髏\頭燭眼, 魅影參間, 滴聲間
斷, 不知是水是血. 突來陰風陣陣如魚龍吐息, 卻是混沌灼熱, 強烈的溫
差使你的身體如剮如裂, 若非內力深厚可能早已被盡碎五腑而亡. 魔界黑
石腥光粼粼, 炎炎邪氣急竄奔走, 魔歸而巖穴暝. 
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "north"  : __DIR__"room79",
            "west" : __DIR__"room53",
            "south" : __DIR__"room77",          
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
   message_vision(HIR"嗤嗤聲響處，幾枚毒蒺菱快速射出，$N閃躲不及被毒蒺菱給射中！\n"NOR,obj);
   obj->add("eff_kee",-kee1/30);
   obj->apply_condition("dark_poison",random(20));
                                                  }                                              
  else  message_vision(HIW"嗤嗤聲響處，幾枚毒蒺菱快速射出，$N連忙竄高伏低，並揮手擊落射來的暗器\n"NOR,obj);   
       }
}

