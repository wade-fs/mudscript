#include "/open/open.h"
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("段雲",({"lord duan","lord","duan"}));
        set("long","段雲便是當今皇上冊封的平南王, 同時也是段家武學的第十代傳人, "+
"雖然貴為王爺, 自有一肚子的墨水, 但其一身祖傳的武學卻也沒忘, 可說是文武雙全, "+
"也因為如此, 段雲自是非常重視文學素養, 若想拜入段家武學的門下, 則非是一位書生不可。\n");
        set("gender","男性");
        set("class","scholar");
        set("nickname","平南王");
        set("combat_exp",8000000);
        set("attitude","heroism");
set("title",HIW + "～幻影～" + NOR);
        set("age",50);
        set("max_kee",10000);
        set("str", 44);
        set("cor", 24);
        set("cps", 45);
        set("per", 30);
        set("int", 42);

        set("force",100000);
        set("max_force",100000);
  set("six_spsp",1);
        set("force_factor", 20);
        set_skill("cure", 60);
set("no_lyssa",1);
        set_skill("dodge", 70);
        set_skill("force",80);
        set_skill("move", 70);
        set_skill("parry", 70);
        set_skill("stabber",120);
        set_skill("unarmed",20);
        set_skill("literate",120);
        set_skill("sunforce",80);
        set_skill("linpo-steps",100);
        set_skill("six-fingers",100);
        map_skill("force","sunforce");
        map_skill("dodge","linpo-steps");
        map_skill("move","linpo-steps");
        map_skill("parry","six-fingers");
        map_skill("stabber","six-fingers");
        map_skill("unarmed","six-fingers");
        set("functions/handwriting/level",100);
        set("marks/sun-finger",1);
        set("marks/six_sp",3);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action("stabber.handwriting") :),
        }));
        setup();
        carry_object(PING_OBJ"neck0")->wear();
  carry_object(PING_OBJ"cloud_fan");
        add_money("gold",10);
        create_family("段家",10,"掌門人");
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



int accept_kill(object who)
{

        who=this_player();
        command("unwield all");
        command("wield fan");
        command("kill "+who->query("id"));
        command("exert sun-finger");
        command("perform unarmed.handwriting");
        command("wield finger");
        return 1;
}
int accept_fight(object who)
{
        who=this_player();
        command("unwield all");
        command("wield fan");
        command("exert sun-finger");
        fight_ob(who);
        command("perform unarmed.handwriting");
        command("wield finger");
        return 1;
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
if(me->query("quest/start_game")< 22)
       {
        message_vision(HIY + "
恭喜" + HIW+me->query("name")+HIY + "挑戰" + HIG + "『" + HIR + "第二十一層試煉ソ塔" + HIG + "』" + HIY + "通過！！

" + HIW + "希望"+me->query("name")+"能不負眾望，勇闖" + HIG + "『" + HIY + "第二十二層試煉ソ塔" + HIG + "』" + HIW + "。
	" + NOR,me);
	me->set("quest/start_game",22);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW + "系統：你已經通過測試，系統不做任何更改。\n" + NOR);
	destruct(this_object());
}
}


