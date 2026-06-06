//copy from cage,re-edit from ccat

#include <ansi.h>
inherit NPC;

mapping *action = ({
([ "action" : "$N手成爪狀,對準$n"+HIW+"腦門"NOR+"直插而下,正是九陰白骨爪第一招"+
               HIW+" 破首式" + NOR,
                "dodge"      :    -25,
                "parry"      :    -25,
                "damage"     :    200,
                "damage_type":   "抓傷",
           ]),
([ "action" : "$N雙爪交錯而過,對準$n"+HIW+"胸口"NOR+"抓去,正是九陰白骨抓之第二招"+
               HIW+" 開膛式" + NOR,
                "dodge"      :      -5,
                "parry"      :     -15,
                "damage"     :     180,
                "damage_type":   "抓傷",
           ]),
([ "action" : "$N雙爪穿過$n的防禦圈,由下而上往$n之"+HIW+"喉嚨"NOR+"抓去,正是九陰白骨爪之"+
              "第三招"+HIW" 斷喉式" + NOR,
                "dodge"      :     30,
                "parry"      :     30,
                "damage"     :    100,
                "damage_type":   "抓傷",
            ]),
([ "action" : "$N一爪在前,一爪在後,迅急無比的往$n"+HIW+"心臟"NOR+"挖去,正是九陰白骨爪之"
             +"第四招"+HIW" 腕心式" + NOR,
                "dodge"      :     5,
                "parry"      :     5,
                "damage"     :   200,
                "damage_type":   "抓傷",
            ]),                
   });

void create()
{
        set("title","黑風雙剎");
        set_name("梅超風", ({"mechoufen"}));
        set("age",35);
        set("long","曾經名動江湖一時,手中殺人無數,黑風雙剎之銅屍,梅超風.\n");
        set("gender","女姓");
        set("str",30);
        set("con",30);
        set("max_kee",20000);
        set("kee",20000);
        set("combat_exp",350000);
        set("max_force",10500);
        set("force",10500);
        set("force_factor",25);
        set_skill("dodge",80);
        set_skill("force",80);
        set_skill("linpo-steps",80);
        set_skill("unarmed",80);
        map_skill("dodge","linpo-steps");
        set("chat_chance_combat",25);
        set("chat_msg_combat",({
        "梅超風說: 你是哪來的高手,竟趕來打擾我修練!!\n",
        "梅超風說: 不教訓你,你不知道我黑風雙剎的可怕!!\n",
        "梅超風說: 殺殺殺殺!!!\n",
        }));
        set_temp("apply/armor",100);
        set_temp("apply/damage",80);
        setup();
       carry_object("/open/gsword/obj/sick_item");
        carry_object("open/center/obj/mechoufen-head");
        add_money("gold",25);
        set("default_actions", (: call_other, __FILE__,"query_action" :));
        
        reset_action();
}

mapping query_action()
{
        return action[random(sizeof(action))];
}
void greeting(object ob)
{
    int exp,lv_1;
    string skill;
    object weapon;
    exp =ob->query("combat_exp",1);
    if( exp < 100000 )
    {
      say("梅超風說: 喂!!"+ob->name(1)+"!! 這裡不是肉腳該來的地方,快滾吧!!\n");
      return;
    }else{
      weapon = ob->query_temp("weapon");     
      if( weapon ) skill = weapon->query("skill_type");
      else skill = "unarmed";
      lv_1 =(int) 1.8 * ob->query_skill(skill, 1);
      if( lv_1 > 50)
      {
        set_skill("unarmed", lv_1);
        set_skill("force", lv_1);
      }
      exp = exp * 1.5;
      set("combat_exp",exp);
      kill_ob(ob);
      ob->kill_ob(this_object());
    }
    return;
}
void heart_beat()
{
 object env,mob,*enemy,target;
 int i,kee;
 mapping exit;
 string *exit_name;

 mob = this_object();
 env = environment(mob);
 
 if( random(100) < 30)
 {
    enemy=mob->query_enemy();
    i=sizeof(enemy);
    target=enemy[random(i)];
    kee = target->query("max_kee") * 0.4;
    if( env == environment(target) )
    {
      message_vision(HIR+"$N一個不留意,被九陰白骨爪正面擊中!!!\n"+NOR,target);
      target->receive_damage("kee",(int)kee,mob);
      COMBAT_D->report_status(target,0);
    }
 }
 
 if((mob->query("kee")<mob->query("max_kee")*0.5) && (random(100) < 20) )
 {
    tell_room(environment(), HIY+name()+"運起九陰真經之氣療法,為自己"
               +"療傷.\n"+NOR);
    mob->receive_curing("kee",700);
    mob->receive_heal("kee",700);
 }

 if((mob->query("kee")<mob->query("max_kee")*0.3) && (random(100) < 20) )
 {
   exit = env->query("exits");
   exit_name = keys(exit);
   i = random(sizeof(exit_name));
   command(exit_name[i]);
   i = random(sizeof(exit_name));
   command(exit_name[i]);
 }
   
   set_heart_beat(1);
   ::heart_beat();
   
}
