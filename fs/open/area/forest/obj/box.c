inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("箱子",({"box"}));
        set("long","一個四處可見的盒子。\n");
        set("no_get",1);
        setup();
}

void init()
{
        add_action("do_open","open");
}

int do_open(string arg)
{
object me,ob,obj;
int i,j,k;

        me = this_player();
        ob = this_object();

        if(!arg)
                return 0;
        if(arg != "box")
                return 0;

        (int)me->add_temp("box",1);
        j = (int)me->query_temp("box");

        if( j < 10 )
                i = random(10)+1;
        else
                i = random(11)+1;

        if( i < 1 )
        {
                obj = new("/open/poison/obj/pearl");
                tell_object(me,"你打開盒子，發現了一顆夜明珠。\n");
                obj->move(me);
        }
        else if ( i < 3 )
        {
                tell_object(me,"你打開盒子，發現了一張銀票。\n");
                obj=new("/obj/money/cash");
                obj->set_amount(1);
                obj->move(me);
        }
        else if ( i < 4 )
        {
                k = random(5)+1;
                obj = new("/open/common/obj/mass");
                obj->set_amount(k);
                tell_object(me,"你打開盒子，發現了"+k+"粒小拉大龍棕。\n");
                obj->move(me);
        }
        else if ( i < 5 )
        {
                tell_object(me,"你打開盒子，發現了10兩黃金。\n");
                obj=new("/obj/money/gold");
                obj->set_amount(10);
                obj->move(me);
        }
        else if ( i < 6 )
        {
                tell_object(me,HIR + "你打開盒子，盒內突然冒出一團黑霧，你不慎吸入了幾口，全身痛苦不堪!\n" + NOR);
                me->receive_damage("gin", (int)me->query("gin")/7 );
                me->receive_damage("kee", (int)me->query("kee")/5 );
                me->receive_damage("sen", (int)me->query("sen")/7 );
        }
        else if ( i < 7 )
        {
                k = random(5)+1;
                obj = new("/obj/example/besttea");
                obj->set_amount(k);
                tell_object(me,"你打開盒子，發現了"+k+"壺純喫茶。\n");
                obj->move(me);
        }
        else if ( i < 9 )
        {
                me->start_busy(10);
                tell_object(me,HIR + "你打開盒子，盒內突然冒出一團白霧，你不慎吸入了幾口，全身動彈不得!\n" + NOR);
        }
        else if ( i < 10 )
        {
                k = random(10)+1;
                obj = new("/open/doctor/pill/ff_pill");
                obj->set_amount(k);
                tell_object(me,"你打開盒子，發現了"+k+"粒雪蓮丹。\n");
                obj->move(me);
        }
        else if ( i <= 11 )
        {
                tell_object(me,"你打開盒子，發現了一顆玻璃水晶。\n");
obj=new(__DIR__"crystal");
obj->move(me);
me->set_temp("/open/forest/crystal");
        }
destruct(ob);           
return 1;
}
