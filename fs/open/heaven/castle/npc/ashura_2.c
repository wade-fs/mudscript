#include <ansi.h>
inherit NPC;

int kill_him(object);

void create() {
set_name("碎羽",({"ashura"}));
        set("long",
            "\n一個面目猙獰的修羅，看得你頭皮發麻。\n");
        set("str",40);
set("cor",35);
        set("gender","男性");
        set("attitude","aggressive");
set("max_gin",4500);
set("max_kee",5000);
set("max_sen",4200);
set("max_force",5000);
set("force",5000);
set("force_factor",10);
set("combat_exp",3000000);
        set_skill("unarmed",80);
        set_skill("dodge",70);
        set_skill("move",60);
        set_skill("parry",70);
set_skill("ashura-strike", 90);
map_skill("unarmed", "ashura-strike");
map_skill("parry","ashura-strike");
        set("chat_chance",50);
        set("chat_msg",({
        }));
//        set("limbs",({"頭部","胸部","背部","腰間","手腕"}));
//        set("verbs",({"bite","claw"}));
        setup();
 }

void init() {
        object obj;

        ::init();
        if(interactive(obj=this_player()) && !is_fighting()) {
           remove_call_out("kill_him");
           call_out("kill_him",0,obj);
        }
 }

