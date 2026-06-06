inherit NPC;     //段川嶽
#include <ansi.h>
#include "/open/open.h"
inherit F_MASTER;
int exert_sunforce();

void create()
{
  set_name("段川嶽",({"muan duan","muan","duan"}));
  set("long","段川嶽即是段氏嫡系族人中最年輕有為的族長。他率領世\n"
              +"代手守護虹晶礦的族人，渡過許\多年的歲月、盡心盡力，\n"
            +"而且親自鎮守晶谷最後的關卡。\n");
  set("gender","男性"); 
  set("class","scholar");
  set("nickname",""+HIC+"幻宇策士"+NOR+"");
  set("attitude","heroism");
  set("age",30);
  set("max_kee",9500);
  set("kee",9500);
  set("str",40);
  set("con",40);
  set("cps",40);
  set("cor",24);
  set("int",22);
  set("kar",40);
  set("bellicosity",5000);
  set("max_force",10000);
  set("force",10000);
  set("force_factor",10);
  set("combat_exp",10000000);
  set_skill("dodge",100);
  set_skill("move",100);
  set_skill("force",150);
  set_skill("parry",90);
  set_skill("unarmed",90);
  set_skill("stabber",120);
  set_skill("literate",120);
  set_skill("linpo-steps",100);
  set_skill("six-fingers",100);
  set_skill("sunforce",150);
  map_skill("unarmed","six-fingers");
  map_skill("parry","six-fingers");
  map_skill("stabber","six-fingers");
  map_skill("move","linpo-steps");
  map_skill("dodge","linpo-steps");
  map_skill("force","sunforce");
  set("env/六絕劍","YES");
  set("marks/sun-finger",1);
  set("marks/six_sp",3);
  set("functions/handwriting/level",100);
  set("chat_chance_combat",100);
  set("chat_msg_combat",({
     (:perform_action,"unarmed.handwriting":),
     (:this_object(),"exert_sunforce":),
     }));
  set("chat_chance",10);
  set("chat_msg", ({
            ""+HIC+"段川嶽自言自語的道: 想到我出任族長時曾為本族財源煩惱，因而一頭栽入研究、收集天下間的寶物。"+NOR+"\n"+
""+HIC+"但是我萬萬想不到所謂的〝"HIR"寶物"HIC"〞也深深的吸引我，害我自今還無法自拔。"NOR"\n",
            ""+HIC+"段川嶽說: 最近我在藏經閣找到一本〝"HIB"況古奇物大全"HIC"〞，它真是一本奇書呀！"+NOR+"\n",
            ""+HIY+"段川嶽嘆道: 真想見識一下那本書中記載，於盛唐時期出自名家之手的那座〝"HIR"雙麒麟火琉璃"HIY"〞呀！"+NOR+"\n",
               }));
setup();
  add_money("gold",50);
  carry_object("/open/ping/obj/cloud_fan");
    carry_object(PING_OBJ"neck0")->wear();
  carry_object("/open/ping/questsfan/obj/diamond_armor")->wear();
  carry_object("/open/ping/questsfan/obj/diamond_cloak")->wear();
  create_family("段家",10,"族長");
}
int accept_kill(object who)
{
  command("perform unarmed.handwriting");
  command("wield fan");
  command("exert sun-finger");
  command("wield finger");
  kill_ob(who);
  return 1;
}
int accept_fight(object who)
{
  command("perform unarmed.handwriting");
  command("wield fan");
  command("exert sun-finger");
  command("wield finger");
  fight_ob(who);
  return 1;
}
void die()
{
        object winner = query_temp("last_damage_from");
//        if(!wizardp(winner)){;:
        tell_object(users(),"\n\t『大鵬一日同風起  扶搖直上九千里\n\t\t今遇風歇遂下來  猶能撥卻滄冥水』\n"+
        "\n\t想我段川嶽一生盡忠職守, 今日敗於"+HIR+""+winner->query("name")+"之手\n\t真是～有負先祖所寄望～\n");
        tell_object(users(),"\n\n南方天空畫過一道流星。\n\n\t「天權星」\n\n");
//       }
        :: die();
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
        if( obj->query("id") == "fire colored glaze" )
        {
          command("pat "+getuid(me));
          command("say 太好了, 這是送我的嗎﹖謝了。");
         if( me->query("family/family_name") == "段家" && me->query("questsfan/quest_step") == 5 )
          {
           command("say 段川嶽神情和悅的對你說道:閣下竟送我如此貴重之物，既然閣下是要來取虹晶
                          石的，那便是已經通過重重考驗，它就在山洞中您請便吧!!!\n");
            me->set("questsfan/quest_step", 6);
          }
          destruct(obj);
        }
        else
        command("? "+getuid(me));
        return 1;
}

