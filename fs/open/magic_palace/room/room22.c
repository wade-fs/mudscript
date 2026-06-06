inherit ROOM;
#include <ansi.h>
void create ()
{
set ("short","魔宮-萬仙道");
set("long",@LONG
四周的毒物緩緩蠕動，不時發出悉悉嗦嗦的聲響，毒蛇吐者引信蜷曲著，
蜘蛛弔著絲網在空中晃動，蠍子舉著鋒銳的大鉗子到處亂爬，蜈蚣則滿佈整片
牆壁，這到底是什麼世界啊...
LONG);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 2 */
        "up"   : __DIR__"room23",
        "down"   : __DIR__"room21",
      ]));
        setup();
}
void init()
{
      call_out("do_check",1,this_player()); 

}

void do_check(object me)
{  
	        me = this_player();
	        if(present(me))
	        {
                if (!present("snake amulet",me)) 
                {
                  message_vision(HIM"一群毒蛇、蜈蚣和蜘蛛衝上來在$N的腿上咬了一大口。\n"NOR,me);
                  me->apply_condition("mogi",3);
                  me->apply_condition("ff_poison",5);
                  me->apply_condition("flower_poison",5);
                  me->apply_condition("snake_poison",5);
                  me->apply_condition("super_snake_poison",5);
                  me->apply_condition("dark_poison",5);
                  me->apply_condition("hart",5);
                  me->apply_condition("enforce_poison",5);
                  me->apply_condition("rose_poison",5);
                  me->apply_condition("scorpion_poison",5);
                  COMBAT_D->report_status(me);
                }else{
                  message_vision(HIG"蛇郎君的庇護使得眾毒物奉$N為王，絲毫不敢侵犯。\n"NOR,me);
                     }
                call_out("do_check",1,this_player());
                }
}
