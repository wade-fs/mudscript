//by roger
#include <ansi.h>
inherit NPC;

int kill_him(object);

void create() {
        set_name("千年雪妖",({"old snow ghost","ghost"}));
        set("long",
            "\n它是天邪峰中常常出現的妖怪，聽說會把人的皮剝下披在身上。\n");
        set("age",1937);
        set("str",25);
        set("cor",25);
        set("race","野獸");
        set("gender","雄性");
        set("attitude","aggressive");
        set("max_gin",500);
        set("max_kee",1500);
        set("max_sen",200);
        set("max_force",2000);
        set("force",2000);
        set("force_factor",4);
        set("combat_exp",1200000);
        set_skill("unarmed",90);
        set_skill("dodge",95);
        set_skill("nine-steps",80);
        set_skill("move",60);
        set_skill("parry",900);
        set_skill("hell-evil", 100);
        map_skill("unarmed", "hell-evil");
        map_skill("dodge","nine-steps");
        map_skill("parry","hell-evil");
        map_skill("move","nine-steps");
        set("chat_chance",50);
        set("chat_msg",({
	"咭咭...好久沒剝人皮了～～\n",
	}));
        set("limbs",({"頭部","胸部","大黑手","大黑腳","背部","腰部"}));
        set("verbs",({"bite","claw"}));
        setup();
 }

void init()
{
        object obj;
        ::init();
	set_leader(this_player());
}

int heal_up()
{
        if (!is_fighting() ) {
             message_vision (HIB"魔石雕像發出一陣強光，把$N再度吸回雕像中了！\n"NOR, this_object ());
             destruct(this_object());
             return 1;
        }
        return ::heal_up() + 1;
}
