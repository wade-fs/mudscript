// by poloer
#include "/open/open.h"
#include <ansi.h>

inherit NPC;
void use_poison(object me, object viction);


void create()
{
    set_name(HIR"鄭雨橋"NOR, ({"jen wu-cho", "jen","wu-cho"}));
    set("gender", "男性");
    set("title", "炎龍谷主");
    set("nickname", HIB"暴王"NOR);
    set("age",20);
    set("long","\n看起來非常兇惡的人，臉上充滿殺氣。\n\n");
    set("quest/dragon",1);
set_skill("parry",100);
        set("s_kee",4000);
        set("str",30);
        set("cps",30);
        set("kar",30);
        set("spe",30);
        set("int",30);
        set("cor",30);
        set("attitude","herosim");
        set("combat_exp",3000000);
        set_skill("skystrike",200);
        set("kee",4000);
        set("max_kee",4000);
        set("gin",4000);
        set("max_gin",4000);
        set("sen",4000);
        set("max_sen",4000);
        set("atman",1700);
        set("max_atman",1000);
        set("mana",1000);
        set("max_mana",1000);
        set("force",6000);
        set("force_factor", 15);
        set("max_force",6000);
        set_skill("dodge",100);
        set_skill("unarmed",200);
        set_skill("nine-steps",100);
        set("functions/evil-blade/level",100);
        set("chat_chance_combat",15);
        set("limbs",({"頭部","胸部","背部","腰部"}));
        map_skill("dodge","nine-steps");
        map_skill("unarmed","skystrike");
        setup();
        set("default_actions", (: call_other, __FILE__,"query_action" :));
        reset_action();
        carry_object(__DIR__"obj/ghostar")->wear();
        add_money("gold",50);
}


void greeting(object me)
{
 write(HIC"鄭雨橋狂傲的說：
「柳家掌門都敗在我的手裡了，你還會比他強嗎?」
「不過如果想找我較量，當然可以，閻羅王正招生呢！」
"NOR); 
}

void heart_beat()
{
        if( random(5) < 2 ){
        if(!is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
            if( query("eff_kee") < query("max_kee") )
                        command("exert heal");
                           }
        }
        :: heart_beat();
}       
 void die()
{
    object winner = query_temp("last_damage_from");
    tell_object(users(),HIM"
       
      "HIW"炎龍谷主說:"HIM" 柳家的人終於來報仇了，冤冤相報何時了啊！
         
      不過今竟然敗在"+winner->query("name")+HIM"之手真是不甘ㄚ");

           new(__DIR__"obj/key")->move(winner);
      

   winner->set("quest/dragon",1);


 tell_object(winner,HIW"鄭雨橋說:冤冤相報何時了呀~
      罷了！我就把柳家的鑰匙交給你吧！\n"NOR,this_player());

         ::die();
      }                                         
