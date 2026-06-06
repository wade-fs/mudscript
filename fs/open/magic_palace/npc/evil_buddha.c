#include <ansi.h>
#include <combat.h>
#include "/open/open.h" 
inherit NPC;
inherit SSERVER;
string magic1();
string magic2();
string magic3();
string magic4();
string magic5();
void create()
{
        set_name("魔也佛",({"Evil Buddha","buddha"}));
        set("long","
魔界金典第一代擁有者，一言以蔽之，『天下無敵』!!
\n" + NOR);
        set("attitude", "aggressive");
        set("gender","男性");
        set("combat_exp",24000000);
        set("score",9000000);
        set("sec_kee","god");
        set("max_s_kee",1000);
        set("s_kee",5000);
        set("age",410);
        set("class","bandit");
        set("title",HIR + "初代" + HIW + "『" + HIY + "魔界金典" + HIW + "』" + HIW + "傳人" + NOR);
        set("nickname",HIM + "無敵傳說" + NOR);
        set("max_gin",90000);
        set("max_kee",150000);
        set("max_sen",90000);
        set("bellicosity",99999);
        set("max_force",90000);
        set("force",999999);
        set("max_atman",50000);
        set("max_mana",50000);
        set("atman",60000);
        set("mana",60000);
        set("force_factor",70);
        set("str",35);
        set("cor",35);
        set("cps",50);
        set("int",35);
        set("con",35);
        set("per",35);
        set("spi",35);
        set("kar",35);
        set_skill("badstrike",140);
        set_skill("unarmed",150);
        set_skill("gold-magic",150);
        set_skill("ghost-steps",120);
        set_skill("badforce",240);
        set_skill("dodge",120);
        set_skill("parry",120);
        set_skill("force",500);
        map_skill("unarmed","badstrike");
        map_skill("magic", "gold-magic");
        map_skill("parry","badstrike");
        map_skill("force", "badforce");
        map_skill("dodge", "ghost-steps");
        set("chat_chance_combat",99);
        set("chat_msg_combat",({
        (: magic1 :),
        (: magic2 :),
        (: magic3 :),
        (: magic4 :),
        (: magic5 :),
        }) );
        setup();
        carry_object("/open/magic-manor/obj/evil-kill-claw")->wield();
        add_money("diamond", 1);
}

void heart_beat()
{
object me,*target;
int i,b,killair;
me=this_object();

if(me->is_fighting() || me->is_killing())
{
if(living(me))
{
target=me->query_enemy();
i=sizeof(target);

        if(random(7)==3)
        {
message_vision(HIM + "$N身形暴起，連環使出魔界金典上的滅世武學。
\n" + NOR,me);

message_vision(HIW + "
              ζ" + HIC + "天地神通" + HIW + "ζ" + CYN + "《" + HIG + "風變化" + CYN + "》
              \n" + NOR,me);
           for(b=0;b<i;b++)
           {
message_vision(HIW + "狂風驟起，$N感覺到自己的身軀完全失去控制。\n" + NOR,target[b]);
           	 target[b]->start_busy(1);
                 COMBAT_D->report_status(target[b]);
           }
message_vision(HIW + "
              ζ" + HIC + "天地神通" + HIW + "ζ" + CYN + "《" + HIY + "雷變化" + CYN + "》
              \n" + NOR,me);
           for(b=0;b<i;b++)
           {
message_vision(HIW + "巨雷劈下，$N被狂風捲住無法閃避，完全命中。\n" + NOR,target[b]);
           	 target[b]->set("force",(target[b]->query("force"))*1/3);
                 COMBAT_D->report_status(target[b]);
           }
message_vision(HIW + "
              ζ" + HIC + "天地神通" + HIW + "ζ" + CYN + "《" + HIB + "雨變化" + CYN + "》
              \n" + NOR,me);
           for(b=0;b<i;b++)
           {
message_vision(HIW + "天地變異，$N目瞪口呆，任由隕石雨點般砸下。\n" + NOR,target[b]);
           	 target[b]->receive_damage("kee",3000);
                 COMBAT_D->report_status(target[b]);
           }
message_vision(HIM + "

            $N吼道：『無名小輩!!死吧!!』


" + HIW + "               ζ" + HIY+BRED + "魔典奧義" + NOR + "" + HIW + "ζ" + CYN + "《" + HIR + "血穴神通" + CYN + "》
\n\n" + NOR,me);
           for(b=0;b<i;b++)
           {   
           	 if(random(3) == 1)
           	 {
message_vision(HIM + "$N閃避不及，整個人撞進血穴之中，完全蒸發消失了。\n" + NOR,target[b]);
           	 target[b]-> move ("/open/magic_palace/room/room34");
                 }else{
                 target[b]->receive_damage("gin",100);
                 target[b]->receive_damage("sen",100);
message_vision(YEL + "$N及時由血穴謎陣中抽身，但身心已遭受重創。\n" + NOR,target[b]);
                      }
           }
        }
        
        
}
}
me->clean_up_enemy();
set_heart_beat(1);

::heart_beat();
}

void die()
{
object *enemy;
int i,j;
object winner = query_temp("last_damage_from");
object me;
string name = winner->query("name");
me=this_object();
enemy=me->query_enemy();
i=sizeof(enemy);

	if( userp(winner) )
	CLAN_D->add_clanset( winner->query("clan/id"), "develop" ,  7 );
tell_object(users(),HIW + "\n\n      西方傳來一聲巨響，" + HIR + "魔也佛" + HIW + "被" + HIG + ""+winner->name()+"" + HIW + "重重一掌印在胸前，

      血脈爆裂，血劍散射遠及數百里...
              
              
                                " + HIY + "無敵傳說  " + HIR + "魔也佛" + HIW + "  終於敗了!!!
                                    
                                    
                                                " + HIC + "魔宮上空的三個太陽搖搖欲墜......
              \n\n" + NOR);

 
   if(present("New_Hero Book",winner))
   {
     message_vision(HIY + "一本金色的書掉落於$N身上。\n\n" + NOR,winner);
     new("/open/magic_palace/obj/magic_book.c")->move(winner);
   }

	:: die();
}

string magic1()
{
        command("conjure magic-crazy");
        return "\n";
}

string magic2()
{
        command("conjure magic-wind");
        return "\n";
}

string magic3()
{
        command("conjure magic-thunder");
        return "\n";
}

string magic4()
{
        command("conjure magic-rain");
        return "\n";
}

string magic5()
{
        command("conjure magic-blood");
        return "\n";
}
