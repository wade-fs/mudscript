#include <ansi.h>
inherit NPC;
void do_special();

mapping *action = ({
([     "action"     :   "$N輕聲說道：『我正在snoop $n喔』，剎那間$N的身影已在$n的身後了",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    150,
                "force"      :    150,
                "damage_type":   "內傷",
           ]),
([    "action"     :   "$N輕聲說道：『給我3秒鐘，我給你smash』，一道落雷擊向$n。",
                "dodge"      :    40,
                "parry"      :   -50,
                "damage"     :    250,
                "force"      :    200,
                "damage_type":   "燒傷",
            ]),
   });

void create()
{
        set_name("懶人舞", ({"lazy dancer","dancer","lazy"}));
        set("age",16);
        set("long","他是所有的巫師當中最懶的一位，整天無所事事，
最近才去找到一份『可以偷懶』的工作。\n");
        set("title",HIR"懶惰成性"NOR+ HIG"巫師"NOR);
        set("gender","男性");
        set("class","巫師");
        set("str",30);
        set("cps",30);
        set("kar",30);
        set("spi",30);
        set("int",30);
        set("cor",30);
        set("attitude","herosim");
        set("potential",49999);
        set("max_gin",1000);
        set("max_kee",3000);
        set("max_sen",1000);
        set("gin",1000);
        set("kee",2000);
        set("sen",1000);
        set("combat_exp",100000);
        set("max_force",10000);
        set("force",10000);
        set("max_atman",5000);
        set("max_mana",5000);
        set("atman",5000);
        set("mana",5000);
        set("force_factor",35);
        set_skill("dodge",200);
        set_skill("unarmed",200);
        set("chat_chance_combat",40);
        set("chat_msg_combat",({
        (: do_special :)
        }));
        set_temp("apply/armor",430);
        set_temp("apply/damage",110);
        setup();
        set("default_actions", (: call_other, __FILE__,"query_action" :));
        reset_action();
}

mapping query_action()
{
        return action[random(sizeof(action))];
}
void do_special()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];

                message_vision(
HIR "\n懶人舞懶懶的叫了一聲："+target->query("name")+"再不回應～～～，我要purge "+target->query("id")+"囉。\n",target);
                message_vision(
HIW "\n懶人舞躺了下來，手指揮揮，出現了purge "+target->query("id")+" 的訊息...\n"NOR,target);
                target->receive_wound("kee",random(210+270));
        COMBAT_D->report_status(target, 1);

  }
int heal_up()
{
        if (!is_fighting() ) {
             message_vision (HIW"系統：戰鬥停止，$N回收中，。\n"NOR, this_object ());
             destruct(this_object());
             return 1;
        }
        return ::heal_up() + 1;
}

void unconcious ()
{
 object me=query_temp("last_damage_from");
if(!present("fight_card",me))
{
tell_object(me,"\n\n系統：由於你沒攜帶晶片，所以無法記錄戰績。\n");
destruct (this_object ());
}
else
if(!me->query("quest/start_game"))
{
tell_object(me,"\n\n系統：由於你沒有正式登記，資料無法傳輸。\n");
destruct (this_object ());
}
else
if(me->query("quest/start_game")< 12)
       {
        message_vision(HIY"
恭喜"HIW+me->query("name")+HIY"挑戰"HIG"『"HIR"第十一層試煉ソ塔"HIG"』"HIY"通過！！

"HIW"希望"+me->query("name")+"能不負眾望，勇闖"HIG"『"HIY"第十二層試煉ソ塔"HIG"』"HIW"。
	"NOR,me);
	me->set("quest/start_game",12);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW"系統：你已經通過測試，系統不做任何更改。\n"NOR);
	destruct(this_object());
}
}


