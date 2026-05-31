#include <ansi.h>
inherit NPC;
void create()
{
        set_name("火龜", ({ "fire turtle","fire","turtle" }) );
        set("long",
                "這是一隻棲息在火龍窟的火龜﹐身體外面有一層極為堅固的外殼所保護。\n");
        set("race", "野獸");
        set("age", 990);
        set("attitude", "friendly");
        set("max_gin", 20000);
        set("max_kee", 33000);
        set("max_sen", 20000);
        set("str", 90);
        set("cor", 50);
        set("spi", 50);
        set("int", 50);
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("bellicosity",10000);
        set("max_force",35000);
        set("force",50000);
        set_temp("apply/armor", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/damage", 100);
        set_temp("apply/attack", 100);
        set("force_factor",40);
        set("combat_exp", 9500000);
        set_skill("move",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("force",500);
        set_temp("kang-power",1);
        set_temp("hardshell",1);
        setup();

}

void heart_beat()
{
        object ob=this_object();
        if( ob->query("kee") <= 0 )
        {
        ob->die();
        }
}

void die()
{
        object winner = query_temp("last_damage_from");
        if(!winner)
        {
        ::die();
        return ;
        }
        if( !present( "fire-turtle shield", winner ) )
        {
          {
          new("/autoload/open-area/turtle-shield.c")->move(winner);
          message_vision(HIR"火龜臨死的一個掙扎，甩出了一塊盾甲砸向了$N!!\n"NOR,winner);
          }
        }
        :: die();
}
