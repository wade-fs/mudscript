#include <ansi.h>
inherit NPC;
string magic1();
string magic2();
string magic3();
string magic4();
string adv_taoist();

void create()
{
        set_name("殭屍王",({"zombie king","zombie","king","zk"}));
        set("long", 
"全身充滿著金光，面目非常恐怖，並且好像所有的傷害都傷害不了他。"
);
       
        set("gender","男性");
        set("class","taoist");
        set("combat_exp",10000000);
        set("attitude","friendly");
        set("age",88);
        set("str",20);
        set("cps",30);
        set("cor",25);
        set("per",25);
        set("int",35);
        set("con",25);
        set("spi",25);
        set("kar",40);

        setup();
        set("max_s_kee",100);
        set("s_kee",100);
        set("sec_kee","tiger");
        set("max_kee",20000);
        set("kee",20000);
        set("max_sen",20000);
        set("sen",20000);
        set("max_gin",20000);
        set("gin",20000);
        set("eff_kee",20000);
        set("eff_gin",20000);
        set("eff_sen",20000);

        set("force",50000);
        set("chat_chance",3);
        set("max_force",50000);
        set("max_mana",300000);
        set("mana",300000);
        set("atman",300000);
        set("max_atman",300000);
        set("mana_factor",60);
        set_skill("literate",240);
        set_skill("cure",290);
        set_skill("taoism",290);
        map_skill("cure","taoism");
        set_skill("force",260);
        set_skill("gforce",200);
        map_skill("force","gforce");
        set_skill("dodge",20);
        set_skill("g-steps",200);
        map_skill("dodge","g-steps");
        set_skill("magic",200);
        set_skill("gmagic", 200);
        map_skill("magic", "gmagic");
        set_skill("whip",205);
        set_skill("gwhip",200);
        map_skill("whip","gwhip");  
        set_skill("parry",270);
        map_skill("parry","gwhip");
        set_skill("spells",220);
        set_skill("necromancy",200);
        map_skill("spells","necromancy");
        set_skill("move",280);
        map_skill("move","g-steps");
        set("spells/feeblebolt/level",290);
        set("spells/missible/level",200);
        set("spells/hardshell/level",290);
        set("spells/invocation/level",200);
        set("spells/godfight/level",270);
		set("spells/stopmove/level",1);
        set("spells/lightfire/level",1);
        set("spells/flee/level",260);
        set("spells/manabody/level",1);
        set("force_factor",10);
        set("guild_master",1);
		set("marks/god-kee",1);
        set("chat_chance_combat",200);
        set("no_die_soon",1);
        set("chat_msg_combat",({
         (: magic1 :),
         (: magic2 :),
         (: magic3 :),
         (: magic4 :),
        }));
        set("family/family_name","天道派");
        delete("family/privs");
        carry_object("/open/tendo/obj/red_dragon_chain")->wield();
        carry_object("/open/tendo/obj/lucloth")->wear();
        carry_object("/open/tendo/obj/luboot")->wear();
        add_money("gold",20);
}
void init()
{
        ::init();
}

void greeting()
{
        }

int accept_object(object me, object obj)
{
}
int accept_fight (object who)
{
command("conj hardshell");
return 1;
}
int accept_kill(object who)
{
who=this_player();
kill_ob(who);
command("conj hardshell");
return 1;
}

string magic1()
{
	command("cast king invocation");
        return "\n";
}
string magic2()
{
	if(random(2)<=1) 
	command("cast missible");
	else command("cast feeblebolt");
	return "\n";
}
string magic3()
{
	if(random(3)<=2)
	command("cast stopmove");
	return "\n";
}
string magic4()
{
	command("cast godfight");
	return "\n";
}
varargs int receive_damage(string type, int damage, object who)
{
  if(!this_object()->query_temp("break"))
    return ;
  if(!who) return ;
  if(who->query("class") != "taoist") return ;

  ::receive_damage(type, damage, who);
}
varargs int receive_wound(string type, int damage, object who)
{
  if(!this_object()->query_temp("break"))
    return ;
  if(!who) return ;
  if(who->query("class") != "taoist") return ;
  ::receive_wound( type,  damage,  who);
}
void heart_beat()
{
  object me;
  if(!environment()) return ;
  me = this_object();
  command("conj hardshell");
  if(me->query_temp("control_z"))
  {
    foreach(object en in me->query_temp("control_z"))
    {
      if(!en) continue;
      if(!en->is_fighting()) destruct(en);
    }
  }

  if(me->is_fighting()) {
    int i  = 3;
    while(i-- != 0) {
      if(!me->query_temp("control_z") || sizeof(me->query_temp("control_z") - ({ 0 })) < 5)
      {
        string *npcs; 
        object base_mob,target,mob;
        npcs = ({
            "/open/poison/npc/masterl.c",
            "/daemon/class/scholar/master_duan.c",
            "/open/dancer/npc/master_yua.c",
            "/daemon/class/swordsman/master.c",
            "/daemon/class/blademan/master_mou.c",
            });
        seteuid(getuid());
        base_mob = target = new (npcs[random(sizeof(npcs))]);
        mob  = "/daemon/class/taoist/necromancy/control.c"->control(this_object(), base_mob,target);
        foreach(object en in me->query_enemy() )
        {
          mob->kill_ob(en);
          en->kill_ob(mob);
          mob->fight_ob(en);
          en->fight_ob(mob);

        }
      }
    }
    if(random(10) == 0 )
    {
      message_vision(HIY"$N由體內散出一道金光，$N又回復無敵的刀槍不入的金身了！\n",me);
      me->set("force",50000);
      me->delete_temp("break");
      me->clear_condition();
    }
  }
  ::heart_beat();
}

void die()
{
        object cloth;
        int j;
        object winner = query_temp("last_damage_from");
        string name ;
        string class1 ;
        if(!winner)
        {
        ::die();
        return ;
        }
        name = winner->query("name");
        class1 = winner->query("family/family_name");
        if(winner->query_temp("control") == 4)
        {
          tell_object(winner,"你順手割下殭屍王的頭。\n");
          new("/open/zombie_hole/obj/head.c")->move(winner);
          winner->set_temp("control",5);
        }
        tell_object(users(),HIW"          
          "+this_object()->name()+""HIG"叫道：現在"HIC+name+HIG"或許\打敗了我，但是我還是會生生世世的復活的!!!!!!\n"NOR);
::die();
}


