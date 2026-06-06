#include <ansi.h>
inherit NPC;
void create()
  {
        set("class", "doctor");
        set_name("華陀", ({ "master tor", "master", "tor" }) );
        set("title",HIW"～幻影～"NOR"銀針門第三代掌門人");
        set("nickname",HIC "妙手回春"NOR);
        set("gender", "男性");
        set("max_gin",4000);
        set("max_sen",4000);
        set("max_kee",5000);
        set("age", 55);
        set("attitude", "heroism");
        set("long",
"華陀為一代名醫,相傳曾為關公刮骨療傷過,可見其醫術的高明.\n"+
"身為銀針門掌門的他，以發揚醫術為己任,對於患者絕對全力以赴..\n");
        set("str",18);
        set("cps",30);
        set("per",10);
        set("int",40);
        set("kar",16);
        set("combat_exp",3000000);
        set("force",8000);
        set("max_force", 8000);
        set("force_factor", 10);
        set("score",200000);
        set("functions/gold-needle/level",100);
        set("functions/break-kee/level",100);
        set_skill("godcure",100);
       set_skill("spells",20);
          set_skill("magic",20);
        set_skill("cure",120);
        set_skill("force",60);
        set_skill("move",60);
        set_skill("stabber",120);
        set_skill("parry", 50);
        set_skill("dodge",70);
        set_skill("poison",70);
        set_skill("literate", 80);
        set_skill("seven-steps",100);
        set_skill("yu-needle",100);
        set_skill("shinnoforce",60);
        map_skill("force", "shinnoforce");
        map_skill("dodge", "yu-steps");
        map_skill("stabber","yu-needle");
        map_skill("cure","godcure");
        map_skill("move","seven-steps");
        map_skill("parry", "yu-needle");
        set("chat_chance_combat",65);
        set("chat_msg_combat",({
        (: perform_action("yu-needle.gold-needle") :),
        (: perform_action("yu-needle.break-kee") :),
        }));

        create_family("銀針門", 3, "掌門人");
        setup();
carry_object("/open/doctor/obj/cloth.c")->wear();
carry_object("/open/doctor/obj/needle9.c")->wield();
        add_money("gold",10);
}

void heart_beat()
{
 object me,boy;
 int value;
 me=this_object();
  if(me->query_condition("lyssa"))
  {
    me->clear_condition("lyssa");
    message_vision(HIY"只見$N雙眼忽然湛放金光,大喝一聲,逼出了身上的狂犬病毒!!!\n",me);
  }
 boy=present("medicine boy",me);
 if(boy)
  if(boy->query_condition("lyssa"))
  {
    boy->clear_condition("lyssa");
    message_vision(HIG"只見$N一掌拍在$n的背後,$n開始渾身冒汗,而$n身上的狂犬病毒似乎也跟著汗水排去!!\n",me,boy);
   }
 value=random(10);
 if( is_fighting() )
 if( value < 4){
 if( query("kee") < query("eff_kee") ) {
   message_vision(HIW"\n華陀見情勢不妙,趕緊服下人靈丹,臉色頓時好多了\n"NOR,me);
    me->receive_heal("kee",500);
    me->receive_heal("gin",200);
    me->receive_heal("sen",200);
    me->delete_busy();
    me->clear_condition();
  }
 } else if( value > 7)
   command("perform yu-needle.gold-needle");
   else if( value = 6)
   command("perform yu-needle.break-kee");
    ::heart_beat();
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
if(me->query("quest/start_game")< 14)
       {
        message_vision(HIY"
恭喜"HIW+me->query("name")+HIY"挑戰"HIG"『"HIR"第十三層試煉ソ塔"HIG"』"HIY"通過！！

"HIW"希望"+me->query("name")+"能不負眾望，勇闖"HIG"『"HIY"第十四層試煉ソ塔"HIG"』"HIW"。
	"NOR,me);
	me->set("quest/start_game",14);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW"系統：你已經通過測試，系統不做任何更改。\n"NOR);
	destruct(this_object());
}
}


