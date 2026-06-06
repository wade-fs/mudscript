// medicine.c
// 重新修正 by chan
// 靈力、法力、解毒、氣血失調、狀態(刀傷....等)都加上藥性
// 補kee > force = atman = mana > dark_poison = five_poison =
// flower_poison = rose_poison = snake_poison > burn = blade = u-stial =
// cold = star-stial = hart
// con (根骨)的部份也跟藥性有關
#include <ansi.h>
#include <dbase.h>
#include <name.h>
inherit F_GUILDCMDS;
inherit COMBINED_ITEM;
inherit F_CONDITION;
void init()
{
        add_action("do_eat", "eat");
        add_action("do_apply","apply");
}
int do_eat(string arg)
{
        object ob,me=this_player();
        int medicine_power,tmp,player_con=me->query_con(),power,value;//跟体質有關

        string TYPE;
        if( !arg )                              return 0;
        arg=lower_case(arg);
        if( !ob = present(arg,me) )             return 0;
        if( ob != this_object() )               return 0;
        if( me->query_temp("unconcious") )      return 0;
        medicine_power = ob->query("medicine_power");
        TYPE = ob->query("cure_"+ob->query("cure_type")+"_type");
        if( ob->query("cure_type")=="outheal")
                return notify_fail("這種藥是外敷的(apply)﹐不能吃。\n");
        if( me->is_busy() )
                return notify_fail("你上一個動作還沒有完成。\n");
        // 新增醫生和魔教吃藥是不會有藥性的，因為本身是用毒(醫)人，還有什麼藥性 by whatup
        if(me->query("class") == "doctor" || me->query("class") == "poisoner")
        me->set("status",0);
        switch( ob->query("cure_type") )
        {
        case "poison" :        //解毒 //一隻只能解一種狀態的......
                player_con=player_con*3;
                power= ob->query("medicine_sick"); //藥性的值
                power= power-player_con;
                 if(power > 40)
                    power = 40;
                me->add( "status",power);
                tmp=me->query("status");
                if( tmp >= 1000 )
                {
                        write("你吃藥過多, 身體承受不住而暈倒了。\n");
                        me->unconcious();
                }
                else
                {
                        if( tmp < 400 )
                         tmp = 0;
                        else
                         tmp-=400;
                  if(me->query_condition(TYPE))
                   {
                        me->apply_condition(TYPE,me->query_condition(TYPE)-medicine_power);
                        if( me->query_condition(TYPE) < 0 )
                                me->clear_condition(TYPE);
                   }
                  else
                  return notify_fail("你沒中毒﹐幹嘛吃藥 ?\n");
                }
                break;
        case "heal" :      //kee(1)大還丹及小還丹的
                player_con=player_con*3;
                power= ob->query("medicine_sick"); //藥性的值
                power= power-player_con;
                 if(power > 40)
                    power = 40;
                me->add( "status",power);
                tmp=me->query("status");
                if( tmp >= 1000 )
                {
                        write("你吃藥過多, 身體承受不住而暈倒了。\n");
                        me->unconcious();
                }
                else
                {
                        if( tmp < 400 )         tmp = 0;
                        else                    tmp-=400;
                        me->receive_heal(TYPE,
                        medicine_power*( 1000-tmp )/1000+random(10)-5);
                }
                me->add_temp("fight",1);
                break;
        case "heal_kee" :      //kee(2)人靈丹
                player_con=player_con*2;
                power= ob->query("medicine_sick"); //藥性的值
                power= power-player_con;
                 if(power > 70)
                    power = 70;
                me->add( "status",power);
                tmp=me->query("status");
                if( tmp >= 1000 )
                {
                        write("你吃藥過多, 身體承受不住而暈倒了。\n");
                        me->unconcious();
                }
                else
                {
                        if( tmp < 400 )         tmp = 0;
                        else                    tmp-=400;
                        value=me->query("max_kee");
                        me->set("kee",value);
                }
                me->add_temp("fight",1);
                break;
        case "force" :      //force 雪蓮丹
                player_con=player_con*3;
                power= ob->query("medicine_sick"); //藥性的值
                power= power-player_con;
                 if(power > 40)
                    power = 40;
                me->add( "status",power);
                tmp=me->query("status");
                if( tmp >= 1000 )
                {
                        write("你吃藥過多, 身體承受不住而暈倒了。\n");
                        me->unconcious();
                }
                else
                {
                        if( tmp < 400 )         tmp = 0;
                        else                    tmp-=400;
                        me->add("force",500);
                        value=me->query("max_force");
                        if(me->query("force") > value)
                          me->set("force",value);
                }
                me->add_temp("fight",1);
                break;
        case "atman" :      //atman 太乙靈神丹
                player_con=player_con*3;
                power= ob->query("medicine_sick"); //藥性的值
                power= power-player_con;
                 if(power > 40)
                    power = 40;
                me->add( "status",power);
                tmp=me->query("status");
                if( tmp >= 1000 )
                {
                        write("你吃藥過多, 身體承受不住而暈倒了。\n");
                        me->unconcious();
                }
                else
                {
                        if( tmp < 400 )         tmp = 0;
                        else                    tmp-=400;
                        me->add("atman",300);
                        value=me->query("max_atman");
                        if(me->query("atman") > value)
                          me->set("atman",value);
                }
                me->add_temp("fight",1);
                break;
        case "mana" :      //mana 九節法神丸
                player_con=player_con*3;
                power= ob->query("medicine_sick"); //藥性的值
                power= power-player_con;
                 if(power > 40)
                    power = 40;
                me->add( "status",power);
                tmp=me->query("status");
                if( tmp >= 1000 )
                {
                        write("你吃藥過多, 身體承受不住而暈倒了。\n");
                        me->unconcious();
                }
                else
                {
                        if( tmp < 400 )         tmp = 0;
                        else                    tmp-=400;
                        me->add("mana",300);
                        value=me->query("max_mana");
                        if(me->query("mana") > value)
                          me->set("mana",value);
                }
                me->add_temp("fight",1);
                break;
        case "all_atats" :      //all_stats 天靈丹 解除所有狀態
                player_con=player_con*1;
                power= ob->query("medicine_sick"); //藥性的值
                power= power-player_con;
                 if(power > 80)
                    power = 80;
                me->add( "status",power);
                tmp=me->query("status");
                if( tmp >= 1000 )
                {
                        write("你吃藥過多, 身體承受不住而暈倒了。\n");
                        me->unconcious();
                }
                else
                {
                        if( tmp < 400 )         tmp = 0;
                        else                    tmp-=400;
                        TYPE="burn";
                        me->clear_condition(TYPE);     //灼傷
                        TYPE="blade";
                        me->clear_condition(TYPE);     //刀傷
                        TYPE="u-stial";
                        me->clear_condition(TYPE);     //毒傷
                        TYPE="cold";
                        me->clear_condition(TYPE);     //凍傷
                        TYPE="hart";
                        me->clear_condition(TYPE);     //內傷
                        TYPE="star-stial";
                        me->clear_condition(TYPE);     //內傷
                        TYPE="blockade";
                        me->clear_condition(TYPE);     //穴道被封
                }
                me->add_temp("fight",1);
                break;
        case "all_poison" :      //all_poison 地靈丹
                player_con=player_con*2;
                power= ob->query("medicine_sick"); //藥性的值
                power= power-player_con;
                 if(power > 70)
                    power = 70;
                me->add( "status",power);
                tmp=me->query("status");
                if( tmp >= 1000 )
                {
                        write("你吃藥過多, 身體承受不住而暈倒了。\n");
                        me->unconcious();
                }
                else
                {
                        if( tmp < 400 )         tmp = 0;
                        else                    tmp-=400;
                        TYPE="five_poison";
                        me->clear_condition(TYPE);
                        TYPE="rose_poison";
                        me->clear_condition(TYPE);
                        TYPE="dark_poison";
                        me->clear_condition(TYPE);
                        TYPE="fire_poison";
                        me->clear_condition(TYPE);
                        TYPE="snake_poison";
                        me->clear_condition(TYPE);
                        TYPE="flower_poison";
                        me->clear_condition(TYPE);
                }
                me->add_temp("fight",1);
                break;
        case "sick" :
                me->add("status",-medicine_power);
                if( me->query("status") < 0 )
                        me->set("status",0);
                break;
        default :
                error("F_MEDICINE:沒有這種 cure_type。\n");
        }
        message_vision((query("eat_msg")?query("eat_msg"):
        "$N服下了$n之後﹐過了一會﹐臉上看起來好多了。\n"),me,ob);
        add_amount(-1);
        return 1;
}

int do_apply(string arg)
{
        string ob_name,target_name,TYPE;
        object me=this_player();
        object ob,target;
        if( !arg )                      return 0;
        if( me->query_temp("unconcious") )      return 0;
        arg=lower_case(arg);
        if( sscanf(arg, "%s at %s", ob_name, target_name)==2 )
        {
          if( !target = present(target_name,environment(me)) )
            return notify_fail("這裡沒有 " + target_name + "。\n");
        }
        else
        {
          ob_name=arg;
          target=me;
        }
        if( !ob = present(ob_name,me) ) return 0;
        if( ob != this_object() )       return 0;
        if( target->query_temp("medicine/bandaged") )
          return notify_fail("需先將繃帶拆掉才能塗藥。\n");
        if( ob->query("cure_type")!="outheal")
          return notify_fail("這種藥不能用來外敷。\n");
        TYPE=ob->query("cure_heal_type");
        if( !target->is_character() || target->is_corpse() )
          return notify_fail("看清楚一點﹐那並不是活物。\n");
        if( target->query(TYPE) >= target->query("max_"+TYPE) )
          return notify_fail((target=me?"你":target->name())+"並沒有明顯的傷口。\n");
        if( me->is_fighting() || target->is_fighting() )
          return notify_fail("戰鬥中無法敷藥。\n");
        message_vision(
        "$N細心的把$n敷在"+ (target==me?"自己":target->name()) +"的身上。\n" ,me,ob);
        target->set_temp("medicine/plaster_power",ob->query("medicine_power"));
        target->set_temp("medicine/plaster_times",ob->query("medicine_times"));
        target->set_temp("medicine/type",TYPE);
        add_amount(-1);
        return 1;
}
