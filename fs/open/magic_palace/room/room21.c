inherit ROOM;
#include <ansi.h>
void create ()
{
set ("short","魔宮-萬仙道");
set("long",@LONG
地面上竟散佈著各式各樣、五顏六色的蟲蛇，不，當你抬頭往四週一望，
不禁獃住了，何只地上，牆上、天花板都爬滿了毒物，稍不留神就會被狠狠
咬上一口，在這鳥不生蛋的魔宮裡，到哪裡去找大夫來給你解毒!?還是小心
點走路吧...

LONG);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 1 */
        "up"   : __DIR__"room22",
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
                  message_vision(HIM + "一群毒蛇、蜈蚣和蜘蛛衝上來在$N的腿上咬了一大口。\n" + NOR,me);
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
                  message_vision(HIG + "蛇郎君的庇護使得眾毒物奉$N為王，絲毫不敢侵犯。\n" + NOR,me);
                     }
                call_out("do_check",1,this_player());
                }
}
