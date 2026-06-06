#include "/open/open.h"
inherit NPC;
void create()
{
        set_name("段遠風",({"duan"}));
        set("long","段遠風是段雲的三弟子, 他才剛辦完師父所交代的事, 因此在這稍微的休息。\n");
        set("gender","男性");
        set("class","scholar");
        set("combat_exp", 240000);
        set("attitude","heroism");
        set("inquiry", ([
        "thief" : "嗯..這件事我在路經京城時也有耳聞, 可惜有要事在身, 無法擒拿此賊。",
        "scar" : "右耳後有傷痕的人﹖這我倒是不清楚耶。",
        "sad_story" : "師父的傷心往事..嗯, 由於我是帶藝拜師, 師父的事我也不太清楚, 你可以去問問大師兄看看。",
        ]));
        set("age",33);
        set("force",800);
        set("max_force",800);
        set_skill("force",50);
        set_skill("unarmed",30);
        set_skill("sunforce",60);
        set_skill("linpo-steps",70);
        set_skill("six-fingers",70);
        map_skill("force","sunforce");
        map_skill("dodge","linpo-steps");
        map_skill("move","linpo-steps");
        map_skill("parry","six-fingers");
        map_skill("stabber","six-fingers");
        map_skill("unarmed","six-fingers");
        set("force_factor", 9);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action("stabber.handwriting") :),
        }));
        setup();
        carry_object(PING_OBJ"neck2")->wear();
        carry_object(PING_OBJ"gloves1")->wear();
        carry_object(PING_OBJ"boots1")->wear();
        carry_object(PING_OBJ"pen1")->wield();
        add_money("gold",3);
        create_family("段家",11,"弟子");
}
