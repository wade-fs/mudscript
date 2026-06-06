inherit NPC;
#include <ansi.h>

mapping *action = ({
([     "action"     :   "$N雙手一揚"HIY"『求生有道』"NOR"，剎那間天地雲氣狂湧，$n已被重重的雲氣所包圍，命在旦夕！",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    250,
                "force"      :    250,
                "damage_type":   "暗傷",
           ]),
([     "action"     :   "$N隨風輕揚一式"HIY"『逃生無門』"NOR"，環伺於$n令$n捉摸不定！",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    350,
                "force"      :    350,
                "damage_type":   "內傷",
           ]),
([     "action"     :   "$N喑喑嘆道："HIY"『生命有時盡』"NOR"，何苦呀！何苦呀！$n就乖乖的束手就範吧！！",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    300,
                "force"      :    450,
                "damage_type":   "重傷",
           ]),
([     "action"     :   "$N嘆道："HIY"『生不逢時』"NOR"可嘆！可悲呀！招式似有似無的向$n！",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    250,
                "force"      :    350,
                "damage_type":   "暗傷",
           ]),
([     "action"     :   "$N殺的性起，使出一式"HIY"『殺生無悔』"NOR"，瞬間已經到達無我之境，殺的$n傷痕累累！",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    350,
                "force"      :    250,
                "damage_type":   "內傷",
           ]),
([     "action"     :   "$N輕笑道：遇到我算$n"HIY"『三生有幸』"NOR"，但仍不留情地向$n攻去！",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    500,
                "force"      :    500,
                "damage_type":   "重傷",
           ]),
([     "action"     :   "$N姿勢立穩，一式"HIY"『生生不息』"NOR"，一招一式已向$n重重的襲去！",
                "dodge"      :   -35,
                "parry"      :   -35,
                "damage"     :    450,
                "force"      :    350,
                "damage_type":   "暗傷",
           ]),
([    "action"     :    "$N喝道：使出至極一式"HIY"『普渡眾生』"NOR"，通通給我下地獄去吧！！！",
                "dodge"      :    40,
                "parry"      :   -50,
                "damage"     :    600,
                "force"      :    600,
                "damage_type":   "無名之傷",
            ]),
   });

void create()
{
        set("nickname",HIM"殘生夢醒"NOR);
        set("title",HIY"生冥王"NOR);
        set_name("夢風兒", ({"ghost life","ghost","life"}));
        set("age",30);
        set("long","死靈骨魔的兩大護法之一，負責掌管【生】，生的柔媚多姿，甚是得死靈骨魔的寵愛。\n");
        set("gender","女性");
        set("str",35);
        set("con",35);
        set("cor",30);
        set("cps",30);
        set("attitude","aggressive");
        set("bellicosity",2000);
        set("max_gin",14000);
        set("gin",14000);
        set("max_sen",14000);
        set("sen",14000);
        set("max_kee",15000);
        set("kee",15000);
        set("combat_exp",10000000);
        set("max_force",90000);
        set("force",1000000);
        set("force_factor",40);
        set("clan_kill",1);
        set_skill("dodge",300);
        set_skill("force",200);
        set_skill("fireforce",150);
        set_skill("mogi-strike1",220);
        set_skill("mogi-steps",220);
        set_skill("unarmed",200);
        set_skill("parry",300);
        set_skill("literate",180);
        set_skill("move",200);
        map_skill("parry","mogi-strike1");
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
        map_skill("force","fireforce");
  
        set_temp("apply/armor",600);
        set_temp("apply/damage",200);
        setup();
        add_money("cash",50);
        carry_object("/open/ghost-hole/obj/life-ghost-head.c");

        set("default_actions", (: call_other, __FILE__,"query_action" :));
        reset_action();

}

mapping query_action()
{
        return action[random(sizeof(action))];
}
        

void init()
{
 ::init();
 add_action("do_cmd","cmd");
}

int do_cmd(string str){
 object who=this_player();
 object ob,ghost;
 ob=this_object();
 ghost=present( "ghost",environment(ob) );
 if(str=="askgod ghost" || str=="askgod white-ghost"){
 write(HIY"生冥王冷笑：「別在我面前佔卜了，省省吧！」\n"NOR);
 ghost->kill_ob(who);
 who->start_busy(1);
 return 1;                                                 
                  }
}

int accept_fight(object who)
{
return notify_fail("生冥王說道 : 別煩我，快走開！。\n");
}

int accept_kill(object who)
{
 who = this_player();
 kill_ob(who);
 return 1;
}

void heart_beat()
{
 object env,mob,*enemy,target;
 int i,j,force,count;
 mapping exit;
 string *exit_name;
 mob = this_object();
 env = environment(mob);
 count = random(100);
  
 if(count < 5)
 {
    enemy=mob->query_enemy();
        if( i = sizeof(enemy) ) {
    target=enemy[random(i)];
    if( env == environment(target) )
    {
      message_vision(HIW"
一聲輕笑，千柔萬媚的$N施展"HIM"「回眸一笑百媚生」"HIW"，以
"HIM"「沉魚落雁」"HIW"之姿迷惑了$n，$n禁不住迷惑產生混亂，
當場被$N無情的攻擊著，全無招架之力！！
\n"NOR,mob,(enemy[j]));
      for(j=0;j < i;j++){
      message_vision(HIR"$N禁不住這樣的迷惑，漸漸喪失心志，瘋狂的向周圍的人狂撲！！\n"NOR,(enemy[j]));
      enemy[j]->start_busy(2);
      enemy[j]->add("kee",-800);
      enemy->apply_condition("mess",random(2)+1);
      COMBAT_D->report_status(enemy[j], 1);
                        }
    }
        }
 }  

 if(count > 85)
 {
    enemy=mob->query_enemy();
        if( i = sizeof(enemy) ) {
    target=enemy[random(i)];
    if( env == environment(target) )
    {
      message_vision(HIW"
$N冷冷的注視著$n，"HIM"「"HIC"森然凜烈"HIM"」"HIW"一道森寒的氣息漸漸的
襲向$n，剎時間，在$n四周的空氣為之凝結！
\n"NOR,mob,(enemy[j]));
      for(j=0;j < i;j++){
      message_vision(HIR"$N為之一愕，以被凜烈的氣息所傷！！\n"NOR,(enemy[j]));
      enemy[j]->start_busy(2);
      enemy[j]->add("kee",-800);
      enemy->apply_condition("cold",random(5)+10);
      COMBAT_D->report_status(enemy[j], 1);
                        }
    }
        }
 }  

   set_heart_beat(1);
   ::heart_beat();
   
}

void die()
{
        object winner,spirit;
        winner = query_temp("last_damage_from");
        if( random(144) == 77 && userp(winner))
        {
        spirit = new("/open/ghost-hole/obj/dark-spirit");
        spirit->move(winner);
        log_file("/sky/spirit/dark-spirit",sprintf("%s(%s)讓夢風兒掉下了%s於 %s\n",winner->name(1),winner->query("id"),spirit->query("name"),ctime(time())));
        message_vision(HIW"薀含在"+this_object()->query("name")+HIW"身體中的"+spirit->query("name")+HIW"飛射而出，落在$N"HIW"手中。\n"NOR,winner);
        }
        ::die();
}
