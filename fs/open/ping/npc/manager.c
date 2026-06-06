#include "/open/open.h"
inherit NPC;
void create()
{
        set_name("郭嘯風",({"manager kou","kou"}));
        set("title","段王府總管");
        set("long","他當年是橫行西南的一名大盜, 後來為段雲所敗, 而甘心跟隨段雲 。\n");
        set("gender","男性");
        set("combat_exp", 300000);
        set("attitude","heroism");
        set("inquiry", ([
        "thief" : "哼!不管有多少惡賊, 我一律都殺光!",
        "scar" : "右耳後有傷痕的人﹖這我不清楚耶。",
        "sad_story" : "王爺的傷心往事..嗯, 你去找毅風或許\能知道。",
        ]));
        set("age",43);
        set("force",3000);
        set("max_force",3000);
        set_skill("force",50);
        set_skill("blade",70);
        set_skill("sixforce",60);
        set_skill("linpo-steps",70);
        set_skill("gold-blade",70);
        map_skill("force","sixforce");
        map_skill("dodge","linpo-steps");
        map_skill("move","linpo-steps");
        map_skill("parry","gold-blade");
        map_skill("blade","gold-blade");
        set("force_factor",10);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action("blade.gold-dest") :),
        }));
        setup();
        carry_object(PING_OBJ"gblade")->wield();
        add_money("gold",5);
}
