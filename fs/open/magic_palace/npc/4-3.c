#include <ansi.h>
#include <combat.h>
#include "/open/open.h" 
inherit NPC;
inherit SSERVER;
object me = this_player();
object book;
void create()
{
        set_name("劍光芒",({"Sword Shining","shining"}));
        set("long","
英雄新經創始人，在四絕當中，若論拳腳武學，應是修為最高者，
正道群雄奉其為武聖聯盟盟主，然其為人絕非如其稱號般正氣凜然
，英雄正宗之所以慾權嗜名，泰半由劍光芒所致。
\n" + NOR);
        set("attitude", "friendly");
        set("gender","男性");
        set("combat_exp",10000000);
        set("score",100000);
        set("sec_kee","god");
        set("max_s_kee",100);
        set("s_kee",1000);
        set("age",64);
        set("class","dancer");
        set("family/family_name","夜夢小築");
        set("title",HIY + "初代" + HIW + "『" + HIC + "英雄新經" + HIW + "』" + HIY + "傳人" + NOR);
        set("nickname",HIR + "武聖" + NOR);
        set("chat_chance", 10);
        set("max_gin",20000);
        set("max_kee",40000);
        set("max_sen",20000);
        set("bellicosity",50000);
        set("max_force",20000);
        set("force",50000);
        set("max_atman",10000);
        set("max_mana",10000);
        set("atman",10000);
        set("mana",10000);
        set("force_factor",35);
        set("str",35);
        set("cor",35);
        set("cps",35);
        set("int",35);
        set("con",35);
        set("per",35);
        set("spi",35);
        set("kar",35);
        set_skill("hero",99);
        set_skill("badforce",250);
        set_skill("dreamdance",120);
        set_skill("unarmed",120);
        set_skill("literate",120);
        set_skill("ghost-steps",120);
        set_skill("dodge",120);
        set_skill("parry",120);
        set_skill("force",450);
        map_skill("unarmed","hero");
        map_skill("parry","dreamdance");
        map_skill("force", "badforce");
        map_skill("dodge", "ghost-steps");
        setup();
        carry_object("/open/capital/obj/icer")->wield();
}

void init()
{
       add_action("do_nod","nod");
       ::init();
}



void greeting(object me)
{

if(me->query_temp("ko_baby"))
{
message_vision(HIY + "劍光芒說道:「$N殺了英雄正宗!?很好，那就來領死吧!!」\n" + NOR,me);
kill_ob(me);
}
set_heart_beat(1);
}
void heart_beat()
{
object me;
int kee,mkee,sen,msen,gin,mgin,chance,ekee,egin,esen;
me=this_object();
kee=me->query("kee");
mkee=me->query("max_kee");
sen=me->query("max_sen");
msen=me->query("max_sen");
gin=me->query("max_gin");
mgin=me->query("max_gin");

if(!me->query_temp("unconcious"))
{
  if((kee < mkee || sen < msen || gin < mgin ) && random(4)==1 ) //回精氣神
  {
message_vision(HIB + "
$N運起少林寺內功\心法" + HIW + "<<" + HIM + "菩提拂拭神功\" + HIW + ">>

                 " + HIW + "『" + HIY + "心如明鏡，身如菩提，時常勤拂拭，一切魔障給我破！" + HIW + "』

                               " + HIC + "$N身上的傷勢立即復原了些許\。
\n" + NOR,me);
          me->delete_busy();
          ekee=me->query("eff_kee");
          egin=me->query("eff_gin");
          esen=me->query("eff_sen");
          me->receive_curing("kee",400+(mkee-kee)/5);
          me->receive_heal("kee",400+(mkee-ekee)/5);
          me->receive_curing("gin",400+(mgin-gin)/5);
          me->receive_heal("gin",400+(mgin-egin)/5);
          me->receive_curing("sen",400+(msen-sen)/5);
          me->receive_heal("sen",400+(msen-esen)/5);
          COMBAT_D->report_status(me);
  }
  if(me->query_busy()&& random(100) < 40 )
  {
message_vision(HIR + "$N潛運" + HIW + "<<" + HIM + "菩提拂拭神功\" + HIW + ">>" + HIR + "衝破一時的滯塞，接著以" + HIY + "閃電步" + HIR + "迅速解除束縛。\n" + NOR,me);
          me->delete_busy();
  }
}
if(me->query("kee")<0) me->die();
set_heart_beat(1);

::heart_beat();
}
