#include <ansi.h>

inherit NPC;

string ask_me(object who);
int accept_kill(object who);

void create()
{
        set_name("鐘妃", ({ "King girl", "girl" }) );
        set("title", "當今皇后");
        set("gender", "女性" );
        set("age", 22);
        set("str", 22);
        set("cor", 30);
        set("cps", 21);
        set("int", 25);
        set("per", 29);
        set("long",
                "鐘妃就是當今聖上的正室, 乃為鳳儀天下之皇后\n" );
        set("combat_exp", 30000);
        set("attitude", "heroism");
        set("chat_chance", 15);
        set("chat_msg_combat", ({
                "鐘妃說道﹕大膽狂徒, 竟敢來皇城撒野﹖\n",
                "鐘妃說道﹕來人啊..有刺客!!\n",
           }) );
        set("force_factor",80);
        set_skill("force",120);
        set_skill("dodge",120);
        set_skill("parry",120);
        set_skill("dagger",120);
        set_skill("fireforce",120);
        set_skill("bss-steps",120);
        set_skill("fly-circle",120);
        set_skill("bss-parry",120);
        map_skill("dodge","bss-steps");
        map_skill("dagger","fly-circle");
        map_skill("force","fireforce");
        map_skill("parry","bss-parry");
        set("force",50000);
        set("max_force",50000);
        set("force_factor",80);
        set("max_gin",3000);
        set("gin",3000);
        set("max_kee",10000);
        set("kee",10000);
        set("max_sen",3000);
        set("sen",3000);

        setup();

        carry_object("/open/capital/room/king/obj/dagger1")->wield();
}

int accept_kill(object who)
{
        int i;
        object ob, guard;
        ob = this_object();

        if( !present("king guard", environment(ob)) ) {
        tell_room(environment(ob),HIW + "\n突然！衝出五位御前護衛！\n\n" + NOR);
     for(i=0;i<5;i++)
     {
        guard = new(__DIR__"fuguard");
        guard->move(environment(ob));
        guard->command("defend girl");
        guard->command("follow girl");
        guard->kill_ob(who);
        }
        }
     tell_object(users(),HIR + "御前護衛大叫：有刺客！快保護殿下！！\n" + NOR);
        return 1;
}
