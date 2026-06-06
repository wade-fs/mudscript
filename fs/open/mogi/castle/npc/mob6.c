// mob4.c by roger

#include <ansi.h>
#include "castle.h"
inherit NPC;
void create() {
        
        set_name("藍蠍哭道",({"ghost"}));
        set("long",
            "\n他是鎮守神秘地帶的厲害妖魔。\n");

        set("age",3121);
        set("str",35);
        set("cor",35);
        set("race","野獸");
        set("gender","雄性");
        set("attitude","peaceful");
        set("class","fighter");
        set("bellicosity",800);
        set("max_gin",2800);
        set("max_kee",9000);
        set("max_sen",3300);
        set("max_force",9500);
        set("force",9500);
        set("force_factor",15);
        set("combat_exp",2750000);
        set_skill("unarmed",120);
        set_skill("dodge",100);
        set_skill("nine-steps",100);
        set_skill("move",40);
        set_skill("parry",100);
        set_skill("badstrike", 100);
        set_skill("force",120);
        set_skill("badforce",120);
        map_skill("unarmed", "badstrike");
        map_skill("dodge","nine-steps");
        map_skill("parry","badstrike");
        map_skill("move","nine-steps");
        map_skill("force","badforce");
        set("limbs",({"頭部","胸部","背部","腰部"}));
        set("verbs",({"bite","claw"}));
        setup();
        carry_object(C_OBJ"/ninepill");
        add_money("gold",20);
 }
int accept_fight(object who)
{
return notify_fail("奪魂魔說道 : 我沒空陪你玩。\n");
}
int accept_kill(object who)
{
 who=this_player();
 command("hehe "+who->query("id"));
 command("exert roar");
 command("kill "+who->query("id"));
 return 1;
}
