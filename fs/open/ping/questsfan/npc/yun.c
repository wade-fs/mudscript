inherit NPC;     //寒芸 2000.4.2 by dhk
#include <ansi.h>
#include "/open/open.h"
inherit F_MASTER;

void create()
{
  set_name("寒芸",({"yun hain","yun","hain"}));
  set("long","寒芸是段氏嫡系族人女性中才華最為出眾，也是最為年輕\n"
            +"、貌美的絕色佳人。她會在此擔任四位關卡守衛之一，完\n"
            +"全是因為從小被父親的英雄形象所感染所致。\n");
  set("gender","女性"); 
  set("class","dancer");
  set("title","段家第十代才女");
  set("nickname",""HIM"心云流水"NOR"");
  set("attitude","heroism");
  set("age",20);
  set("max_kee",5000);
  set("kee",5000);
  set("str",30);
  set("per",50);
  set("cps",50);
  set("cor",30);
  set("int",40);
  set("kar",50);
  set("max_force",14000);
  set("force",14000);
  set("force_factor",10);
  set("combat_exp",9000000);
  set_skill("dagger",100);
  set_skill("fly-circle",120);
  map_skill("dagger","fly-circle");
  set_skill("dodge",120);
  set_skill("move",120);
  set_skill("force",100);
  set_skill("parry",100);
  set_skill("literate",110);
  set_skill("unarmed",90);
  set_skill("linpo-steps",100);
  set_skill("sunforce",160);
  set_temp("apply/armor",100);
  map_skill("move","linpo-steps");
  map_skill("dodge","linpo-steps");
  map_skill("force","sunforce");
  set("chat_chance_combat",100);
  //set("chat_msg_combat",({
  //   (:do_special_fight:),
  //   }));
  set("chat_chance",10);
  set("chat_msg", ({
            ""+HIY+"寒芸自言自語的道: 父親唯一遺留給我的～珍瓏棋局～我已經研究整整十年了。"+NOR+"\n",
            ""+HIY+"寒芸對著棋局道: 我雖是族人公認的才女，但是對父親的殘局竟一點頭緒也沒有。"+NOR+"\n"+
                            ""+HIY+"我寒芸對天發誓：『若解不開此局，便常伴青燈從此一生。』"+NOR+"\n",
            ""+HIM+"寒芸嘆道: 如果有傳說中"+HIR+"紅帥先生"+HIM+"的"+HIC+"無敵棋意"+HIM+"或許\我就解的出來了。"+NOR+"\n",
      
               }));
setup();
  add_money("gold",100);
//carry_object("/open/dancer/obj/yuaboots.c")->wear();
  carry_object("/open/ping/questsfan/obj/diamond_hairpin")->wear();
  carry_object("/open/ping/questsfan/obj/diamond_skirt")->wear();
   carry_object("/open/ping/questsfan/obj/dagger1")->wield();
//carry_object("/open/dancer/obj/ribbon.c")->wield();
  create_family("段家",10,"才女");
}
int accept_fight(object ob)
{
        command("say 小女子怎是您的對手呢??\n");
        message_vision( this_object()->name()+"一付弱不禁風的樣子。\n",ob);
        command("say 既然你忍心欺負弱小女子，那我就不客氣了!!!\n");
        fight_ob(ob);
        return 1;
}
int accept_kill(object who)
{
        command("say 沒想到你忍心欺負弱小女子，那我就不客氣了!!!\n");
        kill_ob(who);
        return 1;
}

void init()
{
        add_action("do_answer","answer");
        set_heart_beat(1);
}
void heart_beat()
{
        if( random(4) < 1 ){
        if( is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
        }
        else{
                if( query("eff_kee") < query("max_kee") )
                        command("exert heal");
        }
        }
        :: heart_beat();
}

int accept_object(object me, object obj)
{
    if( obj->query("id") == "board chess manual" )
      {
        command("bow "+getuid(me));
        command("say 太好了, 您是如何得到的？真是太感謝。");
         if( me->query("family/family_name") == "段家" && me->query("questsfan/quest_step") == 4 )
          {
            command("say 寒芸神情和悅的對你說道:閣下竟送我如此貴重之物，讓小女子了一樁心事，您請過吧!!!\n");
            me->set("questsfan/quest_step", 5);
          }
        destruct(obj);
      }
    else
      command("? "+getuid(me));
    return 1;
}
